/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_18f4620_public.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_18f4620.h

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
		\file		pgim_18f4620_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		The public configuration file for the 18F4620 uController.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIMX_18F4620_PUBLIC_H_
	#define _PGIMX_18F4620_PUBLIC_H_

	// #ifdef	_PGIMX_H_
		// #ifdef _PGIMX_18F4620_PRIVATE_H_

			// #if( PGX_USE_INTERNAL_OSC == PGX_DISABLE )
				// #pragma	config OSC			= ECIO6  		// Used only with external oscillator
			// #endif
				
			#pragma config FCMEN			= OFF
			#pragma config IESO				= OFF
			#pragma config PWRT				= OFF
			#pragma config BOREN			= ON
			#pragma config BORV				= 2
			#pragma config WDT				= OFF
			#pragma config WDTPS			= 32768
			#pragma config MCLRE			= ON
			#pragma config LPT1OSC			= OFF
			#pragma config PBADEN			= OFF
			#pragma config CCP2MX			= PORTC			//PORTC		//PORTBE
			#pragma config STVREN			= OFF
			#pragma config LVP				= OFF
			#pragma config DEBUG			= OFF
			#pragma config CP0				= OFF
			#pragma config CP1				= OFF
			#pragma config CP2				= OFF
			#pragma config CP3				= OFF
			#pragma config CPB				= OFF
			#pragma config WRT0				= OFF
			#pragma config WRT1				= OFF
			#pragma config WRT2				= OFF
			#pragma config WRT3				= OFF
			#pragma config WRTB				= OFF
			#pragma config WRTC				= OFF
			#pragma config WRTD				= OFF
			#pragma config EBTR0			= OFF
			#pragma config EBTR1			= OFF
			#pragma config EBTR2			= OFF
			#pragma config EBTR3			= OFF
			#pragma config EBTRB			= OFF
		// #endif
	// #endif
#endif /* _PGIMX_18F4620_PUBLIC_H_ */


