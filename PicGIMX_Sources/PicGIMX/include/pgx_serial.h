/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_serial.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_serial.c

	START LICENSE	GPL	V3.0

		PicGIM is a "modular library from scratch".
		PicGIM is developed to work with PIC18F (R) MCU family only.

		Copyright (C) 2015  gKript.org - We.PIC project - <http://www.gkript.org>

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
 */

 /*!
		\file		pgim_serial.h
		\version	0.5-0
		\date		2002 - 2015
		\brief			Automatically configures the USART.
		\details		Calculates the parameters needed to obtain the baud rate defined by the user, or automatically searches for the highest.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIMX_SERIAL_H_
	#define _PGIMX_SERIAL_H_

	#if ( PGIMX_SERIAL == PGX_ENABLE )

		//---[ Baudrate ]---
		#define PGX_SERIAL_BAUDRATE_300						300				//!< Baudrate value. The relative index is: 8
		#define PGX_SERIAL_BAUDRATE_1200					1200			//!< Baudrate value. The relative index is: 7
		#define PGX_SERIAL_BAUDRATE_2400					2400			//!< Baudrate value. The relative index is: 6
		#define PGX_SERIAL_BAUDRATE_4800					4800			//!< Baudrate value. The relative index is: 5
		#define PGX_SERIAL_BAUDRATE_9600					9600			//!< Baudrate value. The relative index is: 4
		#define PGX_SERIAL_BAUDRATE_19200					19200			//!< Baudrate value. The relative index is: 3
		#define PGX_SERIAL_BAUDRATE_38400					38400			//!< Baudrate value. The relative index is: 2
		#define PGX_SERIAL_BAUDRATE_57600					57600			//!< Baudrate value. The relative index is: 1
		#define PGX_SERIAL_BAUDRATE_115200					115200			//!< Baudrate value. The relative index is: 0
		
		#define PGX_SERIAL_BAUDRATE_VALUE_QUANTITY			9				//!< How many baudrate value are available

		//---[ Errors ]---	
		#define PGX_SERIAL_ERROR_BAUDRATE_NOT_FOUND			-1				//!< System clock too slow, or accuracy too close.

		//---[ Prototypes ]--
		_pgx_int8	pgx_serial_init							( void );
		void		pgx_serial_open							( void );
		void		pgx_serial_close						( void );
		void		pgx_serial_write_byte					( _pgx_Uint8 pg_data );
		void		pgx_serial_write_string					( _pgx_Uint8 * pg_data );
		_pgx_Uint8	pgx_serial_read_byte					( void );
		void		pgx_serial_read_string					( _pgx_Uint8 * pg_data );
		
	#endif
#endif
  

