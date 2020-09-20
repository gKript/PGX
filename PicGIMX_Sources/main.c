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

void digitalWrite( _pgx_int8 p , _pgx_int8 status ) {
    if ( status == PGX_HIGH ) {
        _PIN_MODE( p ) = PGX_OUT;     //  Il mode è dentro all'if perchè così tocco il tris solo se devo fare qualcosa, se no non tocco nulla
        _PIN_OUT( p ) = PGX_HIGH;
    }
    else if ( status == PGX_LOW ) {
        _PIN_MODE( p ) = PGX_OUT;
        _PIN_OUT( p ) = PGX_LOW;
    }
}

_pgx_int8 digitalRead( _pgx_int8 p ) {
    _PIN_MODE( p ) = PGX_IN;
    if ( _PIN_IN( p ) ) 
         return PGX_HIGH;
    else
        return _PIN_IN( p );
}


void main( void ) {
	pgx_initialize( );
    
    pgx_loop {
        if ( digitalRead( 22 ) ) {
            digitalWrite( 20 , PGX_HIGH );
            pgx_delay_msec( 500 );
            digitalWrite( 20 , PGX_LOW );
        }
        pgx_delay_msec( 500 );
    }
    
    PGX_HALT;
}