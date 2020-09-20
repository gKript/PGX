/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_event_setup_public.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

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
		\file		pgim_event_setup_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		EVENTS module configuration public file.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIMX_EVENT_SETUP_PUBLIC_H_
	#define	_PGIMX_EVENT_SETUP_PUBLIC_H_
	//------------------------------------------------------------------------
	#if ( PGIMX_EVENT == PG_ENABLE )
		//------------------------------------------------------------------------
		//		A U T O   I N T E R R U P T S   H A N D L E R
		//------------------------------------------------------------------------
		#define PG_EVENT_AUTO_HANDLER		PG_ENABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		//------------------------------------------------------------------------
		//		E X T E R N A L   I N T E R R U P T S
		//------------------------------------------------------------------------
		#define PG_EVENT_SET_INT0			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_INT1			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_INT2			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_RB0			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		//------------------------------------------------------------------------
		//		I N T E R N A L   I N T E R R U P T S
		//------------------------------------------------------------------------
		#define PG_EVENT_SET_TMR0			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_TMR1			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_TMR2			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_AD				PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_USARTRC        PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_USARTTX        PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_SSP			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_CCP1			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_CCP2			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_OSCF			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_CM				PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_EE				PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define PG_EVENT_SET_BCL			PG_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		//------------------------------------------------------------------------
	#endif
#endif /* _PGIMX_EVENT_SETUP_PUBLIC_H_ */


