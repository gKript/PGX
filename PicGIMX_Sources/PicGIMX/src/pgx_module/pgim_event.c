/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_interrupt.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_interrupt.h

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
		\file		pgim_interrupt.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily use the interrupt.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "pgx.h"

#if	( PGIMX_EVENT == PGX_ENABLE )
	//------------------------------------------------------------------------
	#if ( PGX_PROJECT_STATE == PGX_DEBUG )
		#warning	PGX >>> Message >>> This file is compiling.
	#endif
	//------------------------------------------------------------------------
	volatile char pgx_event_name;
	//------------------------------------------------------------------------
	pgx_int0_cb_pointer		pgx_int0_callback;
	pgx_int1_cb_pointer		pgx_int1_callback;
	pgx_int2_cb_pointer		pgx_int2_callback;
	pgx_tmr0_cb_pointer		pgx_tmr0_callback;
	pgx_tmr1_cb_pointer		pgx_tmr1_callback;
	pgx_tmr2_cb_pointer		pgx_tmr2_callback;
	pgx_rb0_cb_pointer		pgx_rb0_callback;
	pgx_ad_cb_pointer		pgx_ad_callback;
	pgx_usartrc_cb_pointer	pgx_usartrc_callback;
	pgx_usarttx_cb_pointer	pgx_usarttx_callback;
	pgx_ssp_cb_pointer		pgx_ssp_callback;
	pgx_ccp1_cb_pointer		pgx_ccp1_callback;
	pgx_ccp2_cb_pointer		pgx_ccp2_callback;
	pgx_oscf_cb_pointer		pgx_oscf_callback;
	pgx_cm_cb_pointer		pgx_cm_callback;
	pgx_ee_cb_pointer		pgx_ee_callback;
	pgx_bcl_cb_pointer		pgx_bcl_callback;
	//---
	pgx_event_user_handler	pgx_user_handler_callback;
	//------------------------------------------------------------------------
	
	//---[ Event Init ]---
	void	pgx_event_init( void ) {
		//------------------------------------------------------------------------
		RCONbits.IPEN = 0;
		pgx_user_handler_callback = NULL;
		pgx_event_name = PGX_EVENT_CLEAR;
	}

	//---[ Event Clear Bit ]---
	void	pgx_event_clear_bit( char int_event ) {
		//------------------------------------------------------------------------
		switch( int_event ) {
		#if	( PGX_EVENT_SET_INT0 == PGX_ENABLE )
			case PGX_EVENT_INT0:
			{
				if ( PGX_INTERRUPT_INT0_FLAG )
					PGX_INTERRUPT_INT0_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_INT1 == PGX_ENABLE )
			case PGX_EVENT_INT1:
			{
				if ( PGX_INTERRUPT_INT1_FLAG )
					PGX_INTERRUPT_INT1_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_INT2 == PGX_ENABLE )
			case PGX_EVENT_INT2:
			{
				if ( PGX_INTERRUPT_INT2_FLAG )
					PGX_INTERRUPT_INT2_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_TMR0 == PGX_ENABLE )
			case PGX_EVENT_TMR0:
			{
				if ( PGX_INTERRUPT_TMR0_FLAG )
					PGX_INTERRUPT_TMR0_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_TMR1 == PGX_ENABLE )
			case PGX_EVENT_TMR1:
			{
				if ( PGX_INTERRUPT_TMR1_FLAG )
					PGX_INTERRUPT_TMR1_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_TMR2 == PGX_ENABLE )
			case PGX_EVENT_TMR2:
			{
				if ( PGX_INTERRUPT_TMR2_FLAG )
					PGX_INTERRUPT_TMR2_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_RB0 == PGX_ENABLE )
			case PGX_EVENT_RB0:
			{
				if ( PGX_INTERRUPT_RB0_FLAG )
					PGX_INTERRUPT_RB0_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_AD == PGX_ENABLE )
			case PGX_EVENT_AD:
			{
				if ( PGX_INTERRUPT_AD_FLAG )
					PGX_INTERRUPT_AD_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_USARTRC == PGX_ENABLE )
			case PGX_EVENT_USARTRC:
			{
				if ( PGX_INTERRUPT_USARTRC_FLAG )
					PGX_INTERRUPT_USARTRC_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_USARTTX == PGX_ENABLE )
			case PGX_EVENT_USARTTX:
			{
				if ( PGX_INTERRUPT_USARTTX_FLAG )
					PGX_INTERRUPT_USARTTX_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_SSP == PGX_ENABLE )
			case PGX_EVENT_SSP:
			{
				if ( PGX_INTERRUPT_SSP_FLAG )
					PGX_INTERRUPT_SSP_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_CCP1 == PGX_ENABLE )
			case PGX_EVENT_CCP1:
			{
				if ( PGX_INTERRUPT_CCP1_FLAG )
					PGX_INTERRUPT_CCP1_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_CCP2 == PGX_ENABLE )
			case PGX_EVENT_CCP2:
			{
				if ( PGX_INTERRUPT_CCP2_FLAG )
					PGX_INTERRUPT_CCP2_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_OSCF == PGX_ENABLE )
			case PGX_EVENT_OSCF:
			{
				if ( PGX_INTERRUPT_OSCF_FLAG )
					PGX_INTERRUPT_OSCF_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_CM == PGX_ENABLE )
			case PGX_EVENT_CM:
			{
				if ( PGX_INTERRUPT_CM_FLAG )
					PGX_INTERRUPT_CM_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		#if ! defined( PGIMX_P18F97J60 )
			#if ( PGX_EVENT_SET_EE == PGX_ENABLE )
					case PGX_EVENT_EE:
				{
					if ( PGX_INTERRUPT_EE_FLAG )
						PGX_INTERRUPT_EE_FLAG = PGX_CLEAR;
					break;
				}
			#endif
		#endif
		#if ( PGX_EVENT_SET_BCL == PGX_ENABLE )
				case PGX_EVENT_BCL:
			{
				if ( PGX_INTERRUPT_BCL_FLAG )
					PGX_INTERRUPT_BCL_FLAG = PGX_CLEAR;
				break;
			}
		#endif
		}
		pgx_event_name = PGX_EVENT_CLEAR;
	}

	//---[ Event Set ]---
	void	pgx_event_set( char int_event , char int_state ) {
		//------------------------------------------------------------------------
		pgx_event_clear_bit( int_event );
		switch( int_event ) {
			case PGX_EVENT_ANY: {
				INTCONbits.GIE = int_state;
				INTCONbits.GIEH = int_state;
				INTCONbits.GIEL = int_state;
				INTCONbits.PEIE = int_state;
				break;
			}
			case PGX_EVENT_GLOBAL: {
				INTCONbits.GIE = int_state;
				INTCONbits.GIEH = int_state;
				INTCONbits.GIEL = int_state;
				break;
			}
			case PGX_EVENT_PERIPHERAL: {
				INTCONbits.PEIE = int_state;
				break;
			}
		#if ( PGX_EVENT_SET_INT0 == PGX_ENABLE )
			case PGX_EVENT_INT0: {
				PGX_INTERRUPT_INT0_ENABLE = int_state;
//				INTCON2bits.RBPU = 0;				// Pull ups on Portb are enable
//				INTCON2bits.INTEDG0 = 0;			// Activates on raising edge
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_INT1 == PGX_ENABLE )
			case PGX_EVENT_INT1: {
//				EnablePullups();
				DisablePullups();
//				INTCON2bits.RBPU = 1;				// Pull ups on Portb are enable
//		INTCON2bits.INTEDG0 = 0;			// Activates on raising edge
				PGX_INTERRUPT_INT1_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_INT2 == PGX_ENABLE )
			case PGX_EVENT_INT2:	{
				PGX_INTERRUPT_INT2_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_TMR0 == PGX_ENABLE )
			case PGX_EVENT_TMR0:	{
				PGX_INTERRUPT_TMR0_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_TMR1 == PGX_ENABLE )
			case PGX_EVENT_TMR1:	{
				PGX_INTERRUPT_TMR1_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_TMR2 == PGX_ENABLE )
			case PGX_EVENT_TMR2:	{
				PGX_INTERRUPT_TMR2_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_RB0 == PGX_ENABLE )
			case PGX_EVENT_RB0:	{
				PGX_INTERRUPT_RB0_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_AD == PGX_ENABLE )
			case PGX_EVENT_AD: {
				PGX_INTERRUPT_AD_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_USARTRC == PGX_ENABLE )
			case PGX_EVENT_USARTRC: {
				PGX_INTERRUPT_USARTRC_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_USARTTX == PGX_ENABLE )
			case PGX_EVENT_USARTTX: {
				PGX_INTERRUPT_USARTTX_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_SSP == PGX_ENABLE )
			case PGX_EVENT_SSP: {
				PGX_INTERRUPT_SSP_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_CCP1 == PGX_ENABLE )
			case PGX_EVENT_CCP1: {
				PGX_INTERRUPT_CCP1_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_CCP2 == PGX_ENABLE )
			case PGX_EVENT_CCP2: {
				PGX_INTERRUPT_CCP2_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_OSCF == PGX_ENABLE )
			case PGX_EVENT_OSCF: {
				PGX_INTERRUPT_OSCF_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PGX_EVENT_SET_CM == PGX_ENABLE )
			case PGX_EVENT_CM: {
				PGX_INTERRUPT_CM_ENABLE = int_state;
				break;
			}
		#endif
		#if ! defined( PGIMX_P18F97J60 )
			#if ( PGX_EVENT_SET_EE == PGX_ENABLE )
				case PGX_EVENT_EE: {
					PGX_INTERRUPT_EE_ENABLE = int_state;
					break;
				}
			#endif
		#endif
		#if ( PGX_EVENT_SET_BCL == PGX_ENABLE )
			case PGX_EVENT_BCL: {
				PGX_INTERRUPT_BCL_ENABLE = int_state;
				break;
			}
		#endif
		}
	}

	//---[ Event Interrupt Get ]---
	char	pgx_interrupt_get( void ) {
		//------------------------------------------------------------------------
		#if ( PGX_EVENT_SET_INT0 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_INT0 == PGX_ENABLE ) && ( PGX_INTERRUPT_INT0_FLAG ) )
				return PGX_EVENT_INT0;
		#endif
		#if ( PGX_EVENT_SET_INT1 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_INT1 == PGX_ENABLE ) && ( PGX_INTERRUPT_INT1_FLAG ) )
				return PGX_EVENT_INT1;
		#endif
		#if ( PGX_EVENT_SET_INT2 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_INT2 == PGX_ENABLE ) && ( PGX_INTERRUPT_INT2_FLAG ) )
				return PGX_EVENT_INT2;
		#endif
		#if ( PGX_EVENT_SET_TMR0 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_TMR0 == PGX_ENABLE ) && ( PGX_INTERRUPT_TMR0_FLAG ) )
				return PGX_EVENT_TMR0;
		#endif
		#if ( PGX_EVENT_SET_TMR1 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_TMR1 == PGX_ENABLE ) && ( PGX_INTERRUPT_TMR1_FLAG ) )
				return PGX_EVENT_TMR1;
		#endif
		#if ( PGX_EVENT_SET_TMR2 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_TMR2 == PGX_ENABLE ) && ( PGX_INTERRUPT_TMR2_FLAG ) )
				return PGX_EVENT_TMR2;
		#endif
		#if ( PGX_EVENT_SET_RB0 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_RB0 == PGX_ENABLE ) && ( PGX_INTERRUPT_RB0_FLAG ) )
				return PGX_EVENT_RB0;
		#endif
		#if ( PGX_EVENT_SET_AD == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_AD == PGX_ENABLE ) && ( PGX_INTERRUPT_AD_FLAG ) )
				return PGX_EVENT_AD;
		#endif
		#if ( PGX_EVENT_SET_USARTRC == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_USARTRC == PGX_ENABLE ) && ( PGX_INTERRUPT_AD_FLAG ) )
				return PGX_EVENT_USARTRC;
		#endif
		#if ( PGX_EVENT_SET_USARTTX == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_USARTTX == PGX_ENABLE ) && ( PGX_INTERRUPT_USARTTX_FLAG ) )
				return PGX_EVENT_USARTTX;
		#endif
		#if ( PGX_EVENT_SET_SSP == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_SSP == PGX_ENABLE ) && ( PGX_INTERRUPT_SSP_FLAG ) )
				return PGX_EVENT_SSP;
		#endif
		#if ( PGX_EVENT_SET_CCP1 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_CCP1 == PGX_ENABLE ) && ( PGX_INTERRUPT_CCP1_FLAG ) )
				return PGX_EVENT_CCP1;
		#endif
		#if ( PGX_EVENT_SET_CCP2 == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_CCP2 == PGX_ENABLE ) && ( PGX_INTERRUPT_CCP2_FLAG ) )
				return PGX_EVENT_CCP2;
		#endif
		#if ( PGX_EVENT_SET_OSCF == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_OSCF == PGX_ENABLE ) && ( PGX_INTERRUPT_OSCF_FLAG ) )
				return PGX_EVENT_OSCF;
		#endif
		#if ( PGX_EVENT_SET_CM == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_CM == PGX_ENABLE ) && ( PGX_INTERRUPT_CM_FLAG ) )
				return PGX_EVENT_CM;
		#endif
		#if !defined( PGIMX_P18F97J60 )
			#if ( PGX_EVENT_SET_EE == PGX_ENABLE )
				if ( ( PGX_EVENT_SET_EE == PGX_ENABLE ) && ( PGX_INTERRUPT_EE_FLAG ) )
					return PGX_EVENT_EE;
			#endif
		#endif
		#if ( PGX_EVENT_SET_BCL == PGX_ENABLE )
			if ( ( PGX_EVENT_SET_BCL == PGX_ENABLE ) && ( PGX_INTERRUPT_BCL_FLAG ) )
				return PGX_EVENT_BCL;
		#endif
		return PGX_EVENT_CLEAR;
	}

	#if ( PGX_EVENT_AUTO_HANDLER == PGX_ENABLE )
	
		//---[ Event Auto Handler ]---
		char	pgx_event_auto_handler( void ) {
			//------------------------------------------------------------------------
			pgx_event_name = pgx_interrupt_get( );
			if ( pgx_event_name != PGX_EVENT_CLEAR ) {
				switch( pgx_event_name ) {
					#if	( PGX_EVENT_SET_INT0 == PGX_ENABLE )
						case PGX_EVENT_INT0: {
							pgx_int0_callback();
							PGX_INTERRUPT_INT0_FLAG = PGX_CLEAR;
							break;
						}
					#endif
					#if	( PGX_EVENT_SET_INT1 == PGX_ENABLE )
						case PGX_EVENT_INT1: {
							pgx_int1_callback();
							PGX_INTERRUPT_INT1_FLAG = PGX_CLEAR;
							break;
						}
					#endif
					#if	( PGX_EVENT_SET_INT2 == PGX_ENABLE )
						case PGX_EVENT_INT2: {
							pgx_int2_callback();
							PGX_INTERRUPT_INT2_FLAG = PGX_CLEAR;
							break;
						}
					#endif
					#if	( PGX_EVENT_SET_TMR0 == PGX_ENABLE ) && ( PGIMX_TIMER_0 != PGX_DISABLE ) && ( PGIMX_TIMER == PGX_ENABLE )
						case PGX_EVENT_TMR0: {
							if ( PGIMX_TIMER_0 == PGX_ENABLE_1_SHOT )
								T0CONbits.TMR0ON = 0;
							TMR0L = pgx_timer_0_tmr_reg_set_save.byte.LB;		//!< Restore Timer Set value
							TMR0H = pgx_timer_0_tmr_reg_set_save.byte.HB;		//!< Restore Timer Set value
							pgx_tmr0_callback();
							break;
						}
					#endif
					#if	( PGX_EVENT_SET_TMR1 == PGX_ENABLE ) && ( PGIMX_TIMER_1 != PGX_DISABLE ) && ( PGIMX_TIMER == PGX_ENABLE )
						case PGX_EVENT_TMR1: {
							if ( PGIMX_TIMER_1 == PGX_ENABLE_1_SHOT )
								T1CONbits.TMR1ON = 0;
							TMR1L = pgx_timer_1_tmr_reg_set_save.byte.LB;
							TMR1H = pgx_timer_1_tmr_reg_set_save.byte.HB;
							pgx_tmr1_callback();
							break;
						}
					#endif
					#if	( PGX_EVENT_SET_TMR2 == PGX_ENABLE ) && ( PGIMX_TIMER_2 != PGX_DISABLE ) && ( PGIMX_TIMER == PGX_ENABLE )
						case PGX_EVENT_TMR2: {
							if ( PGIMX_TIMER_2 == PGX_ENABLE_1_SHOT )
								T1CONbits.TMR2ON = 0;
							TMR2L = pgx_timer_2_tmr_reg_set_save.byte.LB;
							TMR2H = pgx_timer_2_tmr_reg_set_save.byte.HB;
							pgx_tmr2_callback();
							break;
						}
					#endif
					#if	( PGX_EVENT_SET_RB0 == PGX_ENABLE )
						case PGX_EVENT_RB0: {
							INTCON2bits.RBPU = 0;
							INTCON2bits.RBIP = 1;
							pgx_rb0_callback();
							break;
						}
					#endif
					#if	( PGX_EVENT_SET_AD == PGX_ENABLE )
						case PGX_EVENT_AD: {
							pgx_ad_callback( );
							break;
						}
					#endif
					#if ( PGX_EVENT_SET_USARTRC == PGX_ENABLE )
						case PGX_EVENT_USARTRC: {
							pgx_usartrc_callback( );
							break;
						}
					#endif
					#if ( PGX_EVENT_SET_USARTTX == PGX_ENABLE )
						case PGX_EVENT_USARTTX: {
							pgx_usarttx_callback( );
							break;
						}
					#endif
					#if ( PGX_EVENT_SET_SSP == PGX_ENABLE )
						case PGX_EVENT_SSP: {
							pgx_ssp_callback();
							break;
						}
					#endif
					#if ( PGX_EVENT_SET_CCP1 == PGX_ENABLE )
						case PGX_EVENT_CCP1: {
							pgx_ccp1_callback();
							break;
						}
					#endif
					#if ( PGX_EVENT_SET_CCP2 == PGX_ENABLE )
						case PGX_EVENT_CCP2: {
							pgx_ccp2_callback();
							break;
						}
					#endif
					#if ( PGX_EVENT_SET_OSCF == PGX_ENABLE )
						case PGX_EVENT_OSCF: {
							pgx_oscf_callback();
							break;
						}
					#endif
					#if ( PGX_EVENT_SET_CM == PGX_ENABLE )
						case PGX_EVENT_CM: {
							pgx_cm_callback();
							break;
						}
					#endif
					#if ! defined( PGIMX_P18F97J60 )
						#if ( PGX_EVENT_SET_EE == PGX_ENABLE )
								case PGX_EVENT_EE: {
								pgx_ee_callback();
								break;
							}
						#endif
					#endif
					#if ( PGX_EVENT_SET_BCL == PGX_ENABLE )
							case PGX_EVENT_BCL: {
							pgx_bcl_callback();
							break;
						}
					#endif
				}
			}
			return pgx_event_name;
		}

		//---[ Event Attach ]---
		void	pgx_event_attach( int event , void (*pgx_event_callback)(void) ) {
			//------------------------------------------------------------------------
			switch( event ) {
			#if	( PGX_EVENT_SET_INT0 == PGX_ENABLE )
				case PGX_EVENT_INT0 : {
					pgx_int0_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_INT1 == PGX_ENABLE )
				case PGX_EVENT_INT1 : {
					pgx_int1_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_INT2 == PGX_ENABLE )
				case PGX_EVENT_INT2 : {
					pgx_int2_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_TMR0 == PGX_ENABLE )
				case PGX_EVENT_TMR0 : {
					pgx_tmr0_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_TMR1 == PGX_ENABLE )
				case PGX_EVENT_TMR1 : {
					pgx_tmr1_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_TMR2 == PGX_ENABLE )
				case PGX_EVENT_TMR2 : {
					pgx_tmr2_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_RB0 == PGX_ENABLE )
				case PGX_EVENT_RB0 : {
					pgx_rb0_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_AD == PGX_ENABLE )
				case PGX_EVENT_AD : {
					pgx_ad_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_USARTRC == PGX_ENABLE )
				case PGX_EVENT_USARTRC : {
					pgx_usartrc_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_USARTTX == PGX_ENABLE )
				case PGX_EVENT_USARTTX : {
					pgx_usarttx_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_SSP == PGX_ENABLE )
				case PGX_EVENT_SSP : {
					pgx_ssp_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_CCP1 == PGX_ENABLE )
				case PGX_EVENT_CCP1 : {
					pgx_ccp1_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_CCP2 == PGX_ENABLE )
				case PGX_EVENT_CCP2 : {
					pgx_ccp2_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_OSCF == PGX_ENABLE )
				case PGX_EVENT_OSCF : {
					pgx_oscf_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_CM == PGX_ENABLE )
				case PGX_EVENT_CM : {
					pgx_cm_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_EE == PGX_ENABLE )
				case PGX_EVENT_EE : {
					pgx_ee_callback = pgx_event_callback;
					break;
				}
			#endif
			#if ( PGX_EVENT_SET_BCL == PGX_ENABLE )
				case PGX_EVENT_BCL : {
					pgx_bcl_callback = pgx_event_callback;
					break;
				}
			#endif
			}
		}
		//---[ Event Use Handler Attach ]---
		void	pgx_event_user_handler_attach( void (*pgx_uh_callback)(void) ) {
			//------------------------------------------------------------------------
			pgx_user_handler_callback = pgx_uh_callback;
		}
	#endif
#endif


