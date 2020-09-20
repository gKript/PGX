//----------------------------------------------------------------------------
//	PicGIMX	- Generic Information Manager for Pic18 uControllers 
//----------------------------------------------------------------------------
// File name:	picgim_main.h
// Authors:		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)
//----------------------------------------------------------------------------
// Current Milestone:	0.1
// Current version:		0.1-0
// Since version:		0.1-0
// Deprecated version:	This file is not deprecated.
//----------------------------------------------------------------------------
/*	START LICENSE - GPL V3.0

		PicGIMX is a "modular library from scratch".

		Copyright (C) 2019  gKript.org - We.PIC project - <http://www.gkript.org>

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

	END LICENSE*/
//----------------------------------------------------------------------------
//	Editor set:	Fixed width fonts - Expandtab OFF - Tabstop 4
//----------------------------------------------------------------------------

/*!		\file			main.c
		\version		0.1-0
		\date			2002 - 2019
		\brief			<descrizione>
		\details		<spiegazione>
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v.2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "pgx.h"

void main( void ) {
	pgx_initialize( );
    
    GET_PIN_MODE(44) = 1;
    
    
/*
 * 	T_B0 = PGX_OUT;
	L_B0 = PGX_OFF;
    
    //pgx_loop {
        pgx_lcd_hd44780_clear( 0 );
        pgx_lcd_hd44780_print_speed( 0 );
        //----------------------------------------------"----------------" );
        pgx_lcd_hd44780_write_p_string_rom( 0 , 0 , 0 , "PGX Timer 0" );
        pgx_lcd_hd44780_write_p_string_rom( 0 , 1 , 0 , ">" );
        //pgx_delay_sec( 5 );
	//}
    pgx_timer_set_period( PGX_TIMER_0 , 3.0 , PGX_SEC );
    pgx_timer_start( PGX_TIMER_0 );
    while (TMR0L && TMR0H) {
        pgx_lcd_hd44780_put_char( 0 , 'T' );
        pgx_delay_sec( 2 );
        //pgx_pin_toggle
    }
 * 
 */
 
    
    
	PGX_HALT;
 
}



