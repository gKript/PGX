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

void pin_mode( _pgx_Uint8 p , _pgx_Uint8 status ) {
    switch ( p ) {
        case 20:
            T_B0 = status;
            break;
        case 22:
            T_B2 = status;
            break;
    }
}

void pin_write( _pgx_Uint8 p , _pgx_Uint8 status ) {
    switch ( p ) {
        case 20:
            L_B0 = status;
            break;
        case 22:
            L_B2 = status;
            break;
    }
}

_pgx_Uint8 pin_read( _pgx_Uint8 p ) {
    _pgx_Uint8 status;
    
    switch ( p ) {
        case 20:
            status = P_B0;
            break;
        case 22:
            status = P_B2;
            break;
    }
    return( status );
}

void digitalWrite( _pgx_int8 p , _pgx_int8 status ) {
    if ( status == PGX_HIGH ) {
        pin_mode( p , PGX_OUT );     //  Il mode è dentro all'if perchè così tocco il tris solo se devo fare qualcosa, se no non tocco nulla
        pin_write( p , PGX_HIGH );
    }
    else if ( status == PGX_LOW ) {
        pin_mode( p , PGX_OUT );
        pin_write( p , PGX_LOW );
    }
}

_pgx_int8 digitalRead( _pgx_int8 p ) {
    return( pin_read( p ) );
}


void main( void ) {
	pgx_initialize( );
    
    pgx_loop {
        if ( !digitalRead( 22 ) ) {
            digitalWrite( 20 , PGX_HIGH );
            pgx_delay_msec( 200 );
            digitalWrite( 20 , PGX_LOW );
            pgx_delay_msec( 200 );
        }
        //pgx_delay_msec( 500 );
    }
    
    PGX_HALT;
}




/*
 void digitalWrite( _pgx_int8 p , _pgx_int8 status ) {
    if ( status == PGX_HIGH ) {
        GET_PIN_MODE( p ) = PGX_OUT;     //  Il mode è dentro all'if perchè così tocco il tris solo se devo fare qualcosa, se no non tocco nulla
        GET_PIN_OUT( p ) = PGX_HIGH;
    }
    else if ( status == PGX_LOW ) {
        GET_PIN_MODE( p ) = PGX_OUT;
        GET_PIN_OUT( p ) = PGX_LOW;
    }
}

_pgx_int8 digitalRead( _pgx_int8 p ) {
    GET_PIN_MODE( p ) = PGX_IN;
    if ( GET_PIN_IN( p ) ) 
         return PGX_HIGH;
    else
        return GET_PIN_IN( p );
        //??? return PGX_LOW;
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
 */