/*gk
===============================================================================
  <°)   PicGIMX	- Generic Information Manager for Pic18 uControllers 
 /( )\  -----------------------------------------------------------------------
  ^ ^   AUTHORS: Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)
===============================================================================
START LICENSE - GPLv3

	PicGIMX is a "modular library from scratch".

	Copyright (C) 2021  gKript.org - We.PIC project - <http://www.gkript.org>

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
END LICENSE
===============================================================================
	\file			main.c
	\version		0.100
	\date			2002 - 2021
	\author			Danilo Zannoni (AsYntote)
	\author			Corrado Tumiati (SkyMatrix)
	\copyright		Released under the terms of the GNU GPLv3<BR>
===============================================================================
REMARKS:
-------------------------------------------------------------------------------
Editor set:	Fixed width fonts - Expandtab OFF - Tabstop 4
-------------------------------------------------------------------------------
EEPROM data memory can be erased by programmer during each programming cycle
by default. Open Project Properties window, then check the box next to
Preserve EEPROM Memory.
=============================================================================*/

#include "pgx.h"

//------------------------------"123456789012345"-----------------------------
#define DEV_ID                  "GKRIPT__18F4620"   //Device ID must be exactly #15 char
#define DELAY_SERIAL_PROBE      100
#define DELAY_RESET             2
#define DEBUG                   0

_pgx_Uint8      dev_id[ ] = { DEV_ID };
_pgx_Uint8      fw_ver[ 16 ];                       //Fw version string must be exactly #15 char
    
_pgx_Uint8      pgx_eeprom_read                     ( _pgx_Uint16 address );
void            pgx_eeprom_write                    ( _pgx_Uint16 address, _pgx_Uint8 byte );
void            pgx_store_fw_ver_to_eeprom          ( void );
void            pgx_retrieve_fw_ver_from_eeprom     ( void );
    
void main( void ) {
    //------------------------------------------------------------------------
    _pgx_Uint8		int_data_length;
	_pgx_Uint8		int_addy[ 2 ];
	_pgx_Uint8		int_type;
	_pgx_Uint8		int_data[ 16 ];
	_pgx_Uint8		int_checksum;
    
    _pgx_Uint8      idx = 0;
    _pgx_Uint8      idu = 0;
    _pgx_Uint8      dat = 0;
    _pgx_Uint8      cs  = 0x00;
    
	pgx_initialize( );
    pgx_serial_open( );
	
    T_B0 = PGX_OUT;
    L_B0 = PGX_ON;
    
    //retrieve fw version from eeprom
    pgx_retrieve_fw_ver_from_eeprom( );
    //----------------------------------------------"----------------"
    pgx_lcd_hd44780_write_p_string_rom( 0 , 0 , 0 , "                " );
    for( idx = 0 ; idx < 15 ; idx++ ) {
        pgx_lcd_hd44780_put_p_char( 0 , 0 , idx , fw_ver[ idx ] );
    }
    //----------------------------------------------"----------------"
    pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Waiting..." );
    
    //wait handshake from downloader
    while( pgx_serial_read_byte( ) != 'p' );
    //----------------------------------------------"----------------"
    pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Connecting...   " );
    pgx_serial_write_byte( 'p' );
    
    //send dev id
    for( idx = 0 ; idx < 15 ; idx++ ) {
        pgx_delay_msec( DELAY_SERIAL_PROBE );
        pgx_serial_write_byte( dev_id[ idx ] );                                 if( DEBUG ) { pgx_lcd_hd44780_put_p_char( 0 , 1 , idx , dev_id[ idx ] ); }
    }
    
    //send fw version
    for( idx = 0 ; idx < 15 ; idx++ ) {
        pgx_delay_msec( DELAY_SERIAL_PROBE );
        pgx_serial_write_byte( fw_ver[ idx ] );                                 if( DEBUG ) { pgx_lcd_hd44780_put_p_char( 0 , 1 , idx , dev_id[ idx ] ); }
    }
    //----------------------------------------------"----------------"
    pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Connected       " );
    
    //wait reply
    dat = pgx_serial_read_byte( );                                              if( DEBUG ) { pgx_lcd_hd44780_put_p_char( 0 , 1 , 0 , dat ); }
    switch( dat ) {
        case 'w':
            //----------------------------------------------"----------------"
            pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Wrong device    " );
            pgx_serial_close( );
            PGX_HALT;
            break;
        case 'a':
            //----------------------------------------------"----------------"
            pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Aborted by user " );
            //wait reset confirmation
            if( pgx_serial_read_byte( ) == 'r' ) {
                //----------------------------------------------"----------------"
                pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Resetting...   " );
                pgx_delay_sec( DELAY_RESET );
                RESET( );
            }
            else {
                PGX_HALT;
            }
            break;
        case 'd':
            //----------------------------------------------"----------------"
            pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Downloading...  " );
            break;
        default:
            //----------------------------------------------"----------------"
            pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Protocol error  " );
            pgx_serial_close( );
            PGX_HALT;
            break;
    }

    //call downloader
    pgx_loop {   
        if( pgx_serial_read_byte( ) != 's' ) {
            //----------------------------------------------"----------------"
            pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Line sync error  " );
            pgx_serial_close( );
            PGX_HALT;
        }
        
        //start rx data
        pgx_serial_write_byte( 's' );                                           if( DEBUG ) { pgx_lcd_hd44780_put_char( 0 , 's' ); }

		//retrieve fw version from downloader
        for( idu = 0; idu < 15; idu++ ) {
			fw_ver[ idu ] = pgx_serial_read_byte( );
		}
        
        //retrieve data + checksum from downloader
        cs = 0x00;
    	int_data_length = pgx_serial_read_byte( );      cs = cs + int_data_length;
		int_addy[ 1 ]   = pgx_serial_read_byte( );      cs = cs + int_addy[ 1 ];
		int_addy[ 0 ]   = pgx_serial_read_byte( );      cs = cs + int_addy[ 0 ];
		int_type        = pgx_serial_read_byte( );      cs = cs + int_type;
		for( idu = 0; idu < int_data_length; idu++ ) {
			int_data[ idu ] = pgx_serial_read_byte( );
            cs = cs + int_data[ idu ];
		}
		int_checksum    = pgx_serial_read_byte( );                              if( DEBUG ) { pgx_lcd_hd44780_write_p_char( 0 , 1 , 0 , "0x%.2X " , cs ); }
        
        //debug cs by wrong value...
        //if ( int_checksum == 0x6E ) cs++;
        
        //Two's complement
        cs = ( ~cs ) + 1;                                                       if( DEBUG ) { pgx_lcd_hd44780_write_p_char( 0 , 1 , 5 , "0x%.2X " , cs ); pgx_lcd_hd44780_write_p_char( 0 , 1 , 10 , "0x%.2X " , int_checksum ); }
        
        //wrong checksum: send fail reply
        if( cs != int_checksum ) {
            pgx_serial_write_byte( 'c' );                                       if( DEBUG ) { pgx_lcd_hd44780_put_char( 0 , 'c' ); }
            break;
        }
        
        //reached ":00000001FF"?
        if( !int_data_length ) {
            
            //save fw version to eeprom
            pgx_store_fw_ver_to_eeprom( );
            
            //all done: send 'end' reply
            pgx_serial_write_byte( 'e' );                                       if( DEBUG ) { pgx_lcd_hd44780_put_char( 0 , 'e' ); }
            //----------------------------------------------"----------------"   
            pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Successful!    " );
            
            //wait reset confirmation
            if( pgx_serial_read_byte( ) == 'r' ) {
                //----------------------------------------------"----------------"
                pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Resetting...   " );
                pgx_delay_sec( DELAY_RESET );
                RESET( );
            }
            pgx_serial_close( );
            PGX_HALT;
        }
        
        //correct checksum: send continue reply
        pgx_serial_write_byte( 'k' );                                           if( DEBUG ) { pgx_lcd_hd44780_put_char( 0 , 'k' ); }
    }
    
    //something goes wrong
    //----------------------------------------------"----------------"    
    pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , "Checksum failed " );
    pgx_serial_close( );
	PGX_HALT;
}

void pgx_eeprom_write( _pgx_Uint16 address , _pgx_Uint8 byte ) {
    //--------------------------------------------------------------
    _pgx_Uint8   save_gie_status;

    EEADRH = address >> 8;
    EEADR = address;
    EEDATA = byte;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
    save_gie_status = INTCONbits.GIE;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0x0AA;
    EECON1bits.WR = 1;
    while( EECON1bits.WR );
    EECON1bits.WREN = 0;
    INTCONbits.GIE = save_gie_status;
}

_pgx_Uint8 pgx_eeprom_read( _pgx_Uint16 address ) {
    //--------------------------------------------------------------
    EEADRH = address >> 8;
    EEADR = address;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.RD = 1;
    NOP();
    NOP();
    NOP();
    NOP();
    return( EEDATA );
}

void pgx_store_fw_ver_to_eeprom( ) {
    //--------------------------------------------------------------
    _pgx_Uint16 idw;
    for( idw = 0 ; idw < 15 ; idw++ ) {
        pgx_eeprom_write( idw , fw_ver[ idw ] );                                if( DEBUG ) { pgx_lcd_hd44780_put_p_char( 0 , 1 , idw , fw_ver[ idw ] ); }
    }
}

void pgx_retrieve_fw_ver_from_eeprom( ) {
    //--------------------------------------------------------------
    _pgx_Uint16 idr;
    for( idr = 0 ; idr < 15 ; idr++ ) {
        fw_ver[ idr ] = pgx_eeprom_read( idr );                                 if( DEBUG ) { pgx_lcd_hd44780_put_p_char( 0 , 1 , idr , fw_ver[ idr ] ); }
    }
}
