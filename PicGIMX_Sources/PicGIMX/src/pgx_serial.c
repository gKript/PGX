//
#include "pgx.h"

#if ( PGIMX_SERIAL == PGX_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	_pgx_Uint8	pgx_serial_bitconf_cycle_index;             			//cycle index 
	_pgx_Uint8	pgx_serial_baudrate_cycle_index;						//baudrate index
	_pgx_Uint32	pgx_serial_baudrate_value_wanted;          				//i.e.:9600
	_pgx_Uint32	pgx_serial_baudrate_value_calculated;      				//i.e.:9615
	_pgx_float	pgx_serial_baudrate_error;                  			//i.e.:0.16 [%]
	_pgx_Uint16	pgx_serial_baudrate_reg;								//[SPBRGH:SPBRG]
	_pgx_Uint16	pgx_serial_baudrate_reg_size;               			//8bit => 0xFF; 16 bit => 0xFFFF;
	_pgx_float	pgx_serial_baudrate_reg_calculated;         			//
	_pgx_Uint8	pgx_serial_baudrate_divisor;							//4, 16 o 64; vedi tabella pag.205 4620
	
	_pgx_int8 pgx_serial_init( void ) {
		//--------------------------------------------------
		//	Configure TX and RX USART tris pins 
        PGX_SERIAL_TX_TRIS = 0;
        PGX_SERIAL_RX_TRIS = 1;
        //--------------------------------------------------
        //	Looking for the configuration with percentage error (%) lower then user's specification
        for ( pgx_serial_baudrate_cycle_index = 0; pgx_serial_baudrate_cycle_index < PGX_SERIAL_BAUDRATE_VALUE_QUANTITY; pgx_serial_baudrate_cycle_index++ ) {
            for ( pgx_serial_bitconf_cycle_index = 0; pgx_serial_bitconf_cycle_index < 4; pgx_serial_bitconf_cycle_index++ ) {
                switch ( pgx_serial_bitconf_cycle_index ) {
                    case 0: {
                        BAUDCONbits.BRG16 = 0;							//8bit; /64; Fosc/[64(reg+1)];
                        TXSTAbits.BRGH = 0;
                        pgx_serial_baudrate_reg_size = 0xFF;
                        pgx_serial_baudrate_divisor = 64;
                        break;
                    }
                    case 1: {
                        BAUDCONbits.BRG16 = 0;							//8bit; /16; Fosc/[16(reg+1)];
                        TXSTAbits.BRGH = 1;
                        pgx_serial_baudrate_reg_size = 0xFF;
                        pgx_serial_baudrate_divisor = 16;
                        break;
                    }
                    case 2: {
                        BAUDCONbits.BRG16 = 1;							//16bit; /16; Fosc/[16(reg+1)];
                        TXSTAbits.BRGH = 0;
                        pgx_serial_baudrate_reg_size = 0xFFFF;
                        pgx_serial_baudrate_divisor = 16;
                        break;
                    }
                    case 3: {
                        BAUDCONbits.BRG16 = 1;							//16bit; /4; Fosc/[4(reg+1)];
                        TXSTAbits.BRGH = 1;
                        pgx_serial_baudrate_reg_size = 0xFFFF;
                        pgx_serial_baudrate_divisor = 4;
                        break;
                    }
                }
                //	Calculation SPBRG registers 
                pgx_serial_baudrate_value_wanted = PGIMX_SERIAL_BAUDRATE;
                pgx_serial_baudrate_reg_calculated = ( ( ( PGX_CLOCK_HZ / (_pgx_float)pgx_serial_baudrate_value_wanted ) / pgx_serial_baudrate_divisor ) - 1 );
                if ( ( pgx_serial_baudrate_reg_calculated > 1 ) && ( pgx_serial_baudrate_reg_calculated <= pgx_serial_baudrate_reg_size ) ) {
                    pgx_serial_baudrate_value_calculated = (_pgx_Uint32)( PGX_CLOCK_HZ / ( pgx_serial_baudrate_divisor * ( (_pgx_Uint32)( pgx_serial_baudrate_reg_calculated ) + 1 )  ) );
                    pgx_serial_baudrate_error = ( ( ( (_pgx_float)pgx_serial_baudrate_value_calculated - (_pgx_float)pgx_serial_baudrate_value_wanted ) / (_pgx_float)pgx_serial_baudrate_value_wanted ) * 100 );	
                    if ( pgx_serial_baudrate_error < PGIMX_SERIAL_BAUDRATE_ACCURACY ) {
                        pgx_serial_baudrate_reg = (_pgx_Uint16)pgx_serial_baudrate_reg_calculated;
                        return PGX_OK;
                    }
                }
            }
            pgx_serial_bitconf_cycle_index = 0;
            return ( -1 );	
        }
        return ( -1 );
	}

	void pgx_serial_open( void ) {
	//--------------------------------------------------
        SPBRG  = (_pgx_Uint8)( pgx_serial_baudrate_reg ); 				//Writing SPBRG Register
        SPBRGH = (_pgx_Uint8)( pgx_serial_baudrate_reg >> 8 );
        TXSTAbits.SYNC = 0;     										//Setting Asynchronous Mode, ie UART
        RCSTAbits.CREN = 1;     										//Enable Continuous RX
        TXSTAbits.TXEN = 1;     										//Enable TX
        RCSTAbits.SPEN = 1;     										//Enable Serial Port
	}

	void pgx_serial_close( void ) {
        //--------------------------------------------------
		RCSTAbits.SPEN = 0;
	}

    void pgx_serial_write_byte( _pgx_Uint8 pg_data ) {
        //--------------------------------------------------
        while( !TXSTAbits.TRMT );                 						//1==empty
        TXREG = pg_data;
    }

    _pgx_Uint8 pgx_serial_read_byte( void ) {
        //--------------------------------------------------
        while( !PIR1bits.RCIF );                    					//1==full
        return( RCREG );
    }
    
//   _pgx_Uint8 pgx_serial_write_string( _pgx_Uint8 * pg_data ) {
        //--------------------------------------------------
//      _pgx_Uint16 idx = 0;
//      while ( 1 ) {
//			while ( !TXSTAbits.TRMT );               					//1==empty
//          if ( *( pg_data + idx ) != '\0') {
//				TXREG  = *( pg_data + idx );
//              idx++;
//          }
//          else {
//				while ( !TXSTAbits.TRMT );           					//1==empty
//          	TXREG  = '\0';
//          	return( idx );
//          }
//      }
//  }

//   _pgx_Uint8 pgx_serial_read_string( _pgx_Uint8 * pg_data ) {
//		//--------------------------------------------------
//      _pgx_Uint16 idx = 0;
//      while ( 1 ) {
//          while ( PIR1bits.RCIF );                    				//==full
//          if ( *( pg_data + idx ) != '\0') {
//              *( pg_data + idx ) = RCREG;
//              idx++;
//          }
//          else {
//              return( idx );
//          }
//      }
//  }
#endif

	//--------------------------------------------------------------
	//PG_SERIAL_BAUDRATE_SPEED_LOW  64	---> Set BRGH = 0
	//PG_SERIAL_BAUDRATE_SPEED_HIGH 16	---> Set BRGH = 1
	//pgx_serial_baudrate_calc = ( PG_CLOCK / ( pgx_serial_baudrate_divisor * ( pgx_serial_baudrate_reg + 1 ) ) );
	//pgx_serial_baudrate_max_high_speed = ( PG_CLOCK / ( PG_SERIAL_BAUDRATE_SPEED_HIGH ) ); 	//pgx_serial_baudrate_reg = [SPBRGH:SPBRG] = 0
	//pgx_serial_baudrate_max_low_speed = ( PG_CLOCK / ( PG_SERIAL_BAUDRATE_SPEED_LOW ) ); 	//pgx_serial_baudrate_reg = [SPBRGH:SPBRG] = 0
	//--------------------------------------------------------------
	//PG_SERIAL_BAUDRATE_SPEED_LOW  64	---> Set BRGH = 0
	//PG_SERIAL_BAUDRATE_SPEED_HIGH 16	---> Set BRGH = 1
	//pgx_serial_baudrate_calc = ( PG_CLOCK / ( pgx_serial_baudrate_divisor * ( pgx_serial_baudrate_reg + 1 ) ) );
	//pgx_serial_baudrate_min_high_speed = ( PG_CLOCK / PG_SERIAL_BAUDRATE_SPEED_HIGH / 65536 ); //pgx_serial_baudrate_reg = [SPBRGH:SPBRG] = 65535 ( +1 = 65536 )
	//pgx_serial_baudrate_min_low_speed = ( PG_CLOCK / PG_SERIAL_BAUDRATE_SPEED_LOW / 65536 ); //pgx_serial_baudrate_reg = [SPBRGH:SPBRG] = 65535 ( +1 = 65536 )
	//--------------------------------------------------------------
	//Those are for 24F, but can help
	//MAX baud rate (BRGH=0) possible is FCY/64 (for [SPBRGH:SPBRG]=0)
	//MIN baud rate (BRGH=0) possible is FCY/(64 * 65536)
	//--------------------------------------------------------------
	//MAX baud rate (BRGH=1) possible is FCY/16 (for [SPBRGH:SPBRG]=0)
	//MIN baud rate (BRGH=1) possible is FCY/(16 * 65536)		
	//--------------------------------------------------------------

	//--------------------------------------------------------------
	//Asynchronous mode
	//--------------------------------------------------------------
	//BRG16:
	//	1 = 16-bit Baud Rate Generator : SPBRGH and SPBRG			pgx_serial_baudrate_reg -> _pgx_Uint16
	//	0 = 8-bit  Baud Rate Generator : SPBRG only					pgx_serial_baudrate_reg -> _pgx_Uint8
	//--------------------------------------------------------------
	//BRGH:
	//	1 = High speed		Fosc / ( 16 * (spbrg + 1 ) )			pgx_serial_baudrate_divisor = 16;
	//	0 = Low speed		Fosc / ( 64 * (spbrg + 1 ) )			pgx_serial_baudrate_divisor = 64;
	//--------------------------------------------------------------
	//Desired Baud Rate = FOSC / ( 64 * ( [SPBRGH:SPBRG] + 1 ) )
	//
	//SPBRGH:SPBRG = ( ( FOSC / Desired Baud Rate ) / 64 ) - 1
	//			 = ( ( 16000000 / 9600 ) / 64 ) - 1
	//			 = [ 25.042 ] = 25
	//			 
	//Calculated Baud Rate = 16000000 / ( 64 ( 25 + 1 ) ) = 9615
	//
	//Error	= ( Calculated Baud Rate - Desired Baud Rate ) / Desired Baud Rate
	//		= ( 9615 - 9600 ) / 9600 = 0.16%
	//--------------------------------------------------------------
	//Look for max baudrate with lower % error
	//There are 4 cases
	//BRGH = 0; BRG16 = 0;
	//BRGH = 0; BRG16 = 1;
	//BRGH = 1; BRG16 = 0;
	//BRGH = 1; BRG16 = 1;
	//--------------------------------------------------------------

	
