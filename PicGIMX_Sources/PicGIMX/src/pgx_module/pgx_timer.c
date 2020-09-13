/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgx_timer.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgx_timer.h

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
		\file		pgx_timer.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily use the Timer device.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/



#include "pgx.h"

#if ( PGIMX_TIMER == PGX_ENABLE )

	#if ( PGX_PROJECT_STATE == PGX_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif

	#if ( PGIMX_TIMER_0 != PGX_DISABLE )
		_pgx_float		pgx_timer_0_period;
		_pgx_float		pgx_timer_0_count_min;
		_pgx_float		pgx_timer_0_count_max;
		_pgx_float		pgx_timer_0_nanosec;
		_pgx_float		pgx_timer_0_nanosec_min;
		_pgx_float		pgx_timer_0_nanosec_max;

		_pgx_Uint16		pgx_timer_0_prescaler;
		_pgx_Uint8		pgx_timer_0_prescaler_mask;
		_pgx_Uint16		pgx_timer_0_timer_counter;
		_pgx_Uint16_VAL	pgx_timer_0_tmr_reg_set_value;
		_pgx_Uint16_VAL	pgx_timer_0_tmr_reg_current_value;
		_pgx_float		pgx_timer_0_period_with_prescaler;

		_pgx_Uint16_VAL	pgx_timer_0_tmr_reg_set_save;
	#endif

	#if ( PGIMX_TIMER_1 != PGX_DISABLE )
		_pgx_float		pgx_timer_1_period;
		_pgx_float		pgx_timer_1_count_min;
		_pgx_float		pgx_timer_1_count_max;
		_pgx_float		pgx_timer_1_nanosec;
		_pgx_float		pgx_timer_1_nanosec_min;
		_pgx_float		pgx_timer_1_nanosec_max;

		_pgx_Uint16		pgx_timer_1_prescaler;
		_pgx_Uint8		pgx_timer_1_prescaler_mask;
		_pgx_Uint16		pgx_timer_1_timer_counter;
		_pgx_Uint16_VAL	pgx_timer_1_tmr_reg_set_value;
		_pgx_Uint16_VAL	pgx_timer_1_tmr_reg_current_value;
		_pgx_float		pgx_timer_1_period_with_prescaler;

		_pgx_Uint16_VAL	pgx_timer_1_tmr_reg_set_save;
	#endif


	//---[ Timer Set Period]---
	_pgx_Uint8	pgx_timer_set_period( _pgx_Uint8 timer_id , _pgx_float timer_time , _pgx_Uint8 unit_measure ) {	// PGX_SEC || PGX_MSEC
		//--------------------------------------------------
		if ( unit_measure == PGX_SEC )
			timer_time *= 1000;
		if ( ( unit_measure == PGX_MSEC ) || ( unit_measure == PGX_SEC ) )
			timer_time *= 1000;								// Then found micro-seconds.
		switch( timer_id ) {
			//--------------------------------------------------
			#if ( PGIMX_TIMER_0 != PGX_DISABLE )
			case PGX_TIMER_0:
			{
				if ( T0CONbits.TMR0ON == 0 ) {				// If timer is NOT running
					pgx_timer_0_nanosec = ( timer_time - ( PGX_TIMER_0_DELAY_TRIM / pgx_ninstus ) ) * 100;	    // Take back value always by micro-seconds
					// User input by micro-seconds [us], but all calculations are by tens of nano-seconds [ns].
					// Lower limit check
					if( pgx_timer_0_nanosec < pgx_timer_0_nanosec_min ) {
						#if PGX_ERROR_IS_ENABLE
							pgx_error_set( PGX_ERROR_TIMER , PGX_TIMER_ERROR_TIME_TOO_SHORT , PGX_ERROR_FATAL );
						#endif
						return PGX_NOK;
					}

					// Upper limit check
					if( pgx_timer_0_nanosec > pgx_timer_0_nanosec_max ) {
						#if PGX_ERROR_IS_ENABLE
							pgx_error_set( PGX_ERROR_TIMER , PGX_TIMER_ERROR_TIME_TOO_LONG , PGX_ERROR_FATAL );
						#endif
						return PGX_NOK;
					}

					// Search for right prescaler value
					if( pgx_timer_0_nanosec <= pgx_timer_0_count_max ) {
						pgx_timer_0_prescaler = 1;	        // No prescaler
						pgx_timer_0_prescaler_mask = T0_PS_1_1;
					} else {
						pgx_timer_0_prescaler = 2;
						pgx_timer_0_prescaler_mask = T0_PS_1_2;
					}
					if ( pgx_timer_0_nanosec < ( pgx_timer_0_count_max * 2.000 ) ) {
						pgx_timer_0_prescaler = 4;
						pgx_timer_0_prescaler_mask = T0_PS_1_4;
					} else if ( pgx_timer_0_nanosec < ( pgx_timer_0_count_max * 4.000 ) ) {
						pgx_timer_0_prescaler = 8;
						pgx_timer_0_prescaler_mask = T0_PS_1_8;
					} else if ( pgx_timer_0_nanosec < ( pgx_timer_0_count_max * 8.000 ) ) {
						pgx_timer_0_prescaler = 16;
						pgx_timer_0_prescaler_mask = T0_PS_1_16;
					} else if ( pgx_timer_0_nanosec < ( pgx_timer_0_count_max * 16.000 ) ) {
						pgx_timer_0_prescaler = 32;
						pgx_timer_0_prescaler_mask = T0_PS_1_32;
					} else if ( pgx_timer_0_nanosec < ( pgx_timer_0_count_max * 32.000 ) ) {
						pgx_timer_0_prescaler = 64;
						pgx_timer_0_prescaler_mask = T0_PS_1_64;
					} else if ( pgx_timer_0_nanosec < ( pgx_timer_0_count_max * 64.000 ) ) {
						pgx_timer_0_prescaler = 128;
						pgx_timer_0_prescaler_mask = T0_PS_1_128;
					} else {
						pgx_timer_0_prescaler = 256;
						pgx_timer_0_prescaler_mask = T0_PS_1_256;
					}

					// Computation for the right timer register value
					pgx_timer_0_period_with_prescaler = ( pgx_timer_0_period * pgx_timer_0_prescaler );
					pgx_timer_0_timer_counter = (_pgx_Uint16)( pgx_timer_0_nanosec  / pgx_timer_0_period_with_prescaler );
					pgx_timer_0_tmr_reg_set_value.Val = 65535 - pgx_timer_0_timer_counter;

					TMR0H = pgx_timer_0_tmr_reg_set_value.byte.HB;   // TMR0H MUST be loaded before TMR0L !!!
					TMR0L = pgx_timer_0_tmr_reg_set_value.byte.LB;

					// Setting the parameters of the timer
					T0CON = ( 0x7F & T0_16BIT & T0_SOURCE_INT & T0_EDGE_FALL & pgx_timer_0_prescaler_mask );  // Configure timer, but don't start it yet
					pgx_timer_0_tmr_reg_set_save.byte.LB  = TMR0L;
					pgx_timer_0_tmr_reg_set_save.byte.HB  = TMR0H;

					#if PGX_ERROR_IS_ENABLE
						pgx_error_set( PGX_ERROR_TIMER , PGX_OK , PGX_ERROR_OK );
					#endif
					return PGX_OK;
				} else {
					#if PGX_ERROR_IS_ENABLE
						pgx_error_set( PGX_ERROR_TIMER , PGX_TIMER_IS_RUNNING , PGX_ERROR_WARNING );
					#endif
					return PGX_NOK;
				}
			}
			#endif
			//--------------------------------------------------
			#if ( PGIMX_TIMER_1 != PGX_DISABLE )
			case PGX_TIMER_1:
			{
				if ( T1CONbits.TMR1ON == 0 ) {				// If timer is NOT running
					pgx_timer_1_nanosec = ( timer_time - ( PGX_TIMER_1_DELAY_TRIM / pgx_ninstus ) ) * 100;	    // Take back value always by micro-seconds
					// User input by micro-seconds [us], but all calculations are by tens of nano-seconds [ns].
					// Lower limit check
					if( pgx_timer_1_nanosec < pgx_timer_1_nanosec_min ) {
						#if PGX_ERROR_IS_ENABLE
							pgx_error_set( PGX_ERROR_TIMER , PGX_TIMER_ERROR_TIME_TOO_SHORT , PGX_ERROR_FATAL );
						#endif
						return PGX_NOK;
					}

					// Upper limit check
					if( pgx_timer_1_nanosec > pgx_timer_1_nanosec_max ) {
						#if PGX_ERROR_IS_ENABLE
							pgx_error_set( PGX_ERROR_TIMER , PGX_TIMER_ERROR_TIME_TOO_LONG , PGX_ERROR_FATAL );
						#endif
						return PGX_NOK;
					}

					// Search for right prescaler value
					if( pgx_timer_1_nanosec <= pgx_timer_1_count_max ) {
						pgx_timer_1_prescaler = 1;	        // No prescaler
						pgx_timer_1_prescaler_mask = T0_PS_1_1;
					} else {
						pgx_timer_1_prescaler = 2;
						pgx_timer_1_prescaler_mask = T0_PS_1_2;
					}
					if ( pgx_timer_1_nanosec < ( pgx_timer_1_count_max * 2.000 ) ) {
						pgx_timer_1_prescaler = 4;
						pgx_timer_1_prescaler_mask = T0_PS_1_4;
					} else if ( pgx_timer_1_nanosec < ( pgx_timer_1_count_max * 4.000 ) ) {
						pgx_timer_1_prescaler = 8;
						pgx_timer_1_prescaler_mask = T0_PS_1_8;
					}

					// Computation for the right timer register value
					pgx_timer_1_period_with_prescaler = ( pgx_timer_1_period * pgx_timer_1_prescaler );
					pgx_timer_1_timer_counter = (_pgx_Uint16)( pgx_timer_1_nanosec  / pgx_timer_1_period_with_prescaler );
					pgx_timer_1_tmr_reg_set_value.Val = 65535 - pgx_timer_1_timer_counter;

					TMR1H = pgx_timer_1_tmr_reg_set_value.byte.HB;   // TMR1H MUST be loaded before TMR1L !!!
					TMR1L = pgx_timer_1_tmr_reg_set_value.byte.LB;

					// Setting the parameters of the timer
					T1CON = ( 0x7F & T1_16BIT_RW & T1_SOURCE_INT & T1_OSC1EN_OFF & T1_SYNC_EXT_OFF & pgx_timer_1_prescaler_mask );  // Configure timer, but don't start it yet
					pgx_timer_1_tmr_reg_set_save.byte.LB  = TMR1L;
					pgx_timer_1_tmr_reg_set_save.byte.HB  = TMR1H;

					#if PGX_ERROR_IS_ENABLE
						pgx_error_set( PGX_ERROR_TIMER , PGX_OK , PGX_ERROR_OK );
					#endif
					return PGX_OK;
				} 
				else {
					#if PGX_ERROR_IS_ENABLE
						pgx_error_set( PGX_ERROR_TIMER , PGX_TIMER_IS_RUNNING , PGX_ERROR_WARNING );
					#endif
					return PGX_TIMER_IS_RUNNING;
				}
			}
			#endif
			default:
			{
				return PGX_TIMER_ERROR_ID;
			}
		}
	}
	//---[ END Timer Set Period]---

	//---[ Timer Set Frequency]---
	_pgx_Uint8	pgx_timer_set_freq( _pgx_Uint8 timer_id , _pgx_float timer_freq , _pgx_Uint8 unit_measure ) {	// PGX_HZ || PGX_KHZ
		//--------------------------------------------------
		_pgx_float	pgx_timer_freq_to_period;
		
		if ( unit_measure == PGX_HZ )
			timer_freq /= 1000;								// Then found kilo-hertz.
		pgx_timer_freq_to_period = (_pgx_float)1.0 / timer_freq;			// Then found milli-seconds.
		pgx_timer_set_period( timer_id , pgx_timer_freq_to_period , PGX_MSEC );
		
		// If timer_id = 0, force TIMER_0 in loop mode. Remember to restore!!!
		;
		// If timer_id = 1, force TIMER_1 in loop mode. Remember to restore!!!
		;
        return( 0 );
	}
	//---[ END Timer Set Frequency]---


	//---[ Timer Start  ]---
	_pgx_Uint8	pgx_timer_start( _pgx_Uint8 timer_id ) {
		//--------------------------------------------------
		switch( timer_id ) {
			//--------------------------------------------------
			#if ( PGIMX_TIMER_0 != PGX_DISABLE )
			case PGX_TIMER_0:
			{
				if ( T0CONbits.TMR0ON == 0 ) {				// If timer is NOT running
					T0CONbits.TMR0ON = 1;
					return PGX_OK;
				} else
					return PGX_TIMER_ALREADY_STARTED;
			}
			#endif
			//--------------------------------------------------
			#if ( PGIMX_TIMER_1 != PGX_DISABLE )
			case PGX_TIMER_1:
			{
				if ( T1CONbits.TMR1ON == 0 ) {				// If timer is NOT running
					T1CONbits.TMR1ON = 1;
					return PGX_OK;
				} else
					return PGX_TIMER_ALREADY_STARTED;
			}
			#endif
			default:
			{
				return PGX_TIMER_ERROR_ID;
			}
		}
	}
	//---[ END Timer Start ]---

	//---[ Timer Stop  ]---
	_pgx_Uint8	pgx_timer_stop( _pgx_Uint8 timer_id ) {
		//--------------------------------------------------
		switch( timer_id ) {
			//--------------------------------------------------
			#if ( PGIMX_TIMER_0 != PGX_DISABLE )
			case PGX_TIMER_0:
			{
				if ( T0CONbits.TMR0ON == 1 ) {
					T0CONbits.TMR0ON = 0;
					TMR0L = pgx_timer_0_tmr_reg_set_save.byte.LB;		// Restore Timer Set value
					TMR0H = pgx_timer_0_tmr_reg_set_save.byte.HB;		// Restore Timer Set value
					return PGX_OK;
				} else
					return PGX_TIMER_ALREADY_STOPPED;
			}
			#endif
			//--------------------------------------------------
			#if ( PGIMX_TIMER_1 != PGX_DISABLE )
			case PGX_TIMER_1:
			{
				if ( T1CONbits.TMR1ON == 1 ) {
					T1CONbits.TMR1ON = 0;
					TMR0L = pgx_timer_1_tmr_reg_set_save.byte.LB;		// Restore Timer Set value
					TMR0H = pgx_timer_1_tmr_reg_set_save.byte.HB;		// Restore Timer Set value
					return PGX_OK;
				} else
					return PGX_TIMER_ALREADY_STOPPED;
			}
			#endif
			default:
			{
				return PGX_TIMER_ERROR_ID;
			}
		}
	}
	//---[ END Timer Stop ]---

	//---[ Timer Value ]---
	_pgx_Uint16	pgx_timer_reg_current_value( _pgx_Uint8 timer_id ) {
		//--------------------------------------------------
		switch( timer_id ) {
			//--------------------------------------------------
			#if ( PGIMX_TIMER_0 != PGX_DISABLE )
			case PGX_TIMER_0:
			{
				pgx_timer_0_tmr_reg_current_value.byte.HB = TMR0H;
				pgx_timer_0_tmr_reg_current_value.byte.LB = TMR0L;
				return( pgx_timer_0_tmr_reg_current_value.Val );
			}
			#endif
			//--------------------------------------------------
			#if ( PGIMX_TIMER_1 != PGX_DISABLE )
			case PGX_TIMER_1:
			{
				pgx_timer_1_tmr_reg_current_value.byte.HB = TMR1H;
				pgx_timer_1_tmr_reg_current_value.byte.LB = TMR1L;
				return( pgx_timer_1_tmr_reg_current_value.Val );
			}
			#endif
			default:
			{
				return PGX_TIMER_ERROR_ID;
			}
		}
	}
	//---[ END Timer Value ]---

	//---[ Timer Init ]---
	void	pgx_timer_init( void ) {
		//--------------------------------------------------
		#if ( PGIMX_TIMER_0 != PGX_DISABLE )
			pgx_timer_0_period		= ( ( 100.000 * PGX_TIMER_FOSC_DIVIDER ) / PGX_CLOCK );		// One step timer, without prescaler, by tens of nano-second [10 ns];
			pgx_timer_0_count_max	= ( ( ( 100.000 * PGX_TIMER_FOSC_DIVIDER ) / PGX_CLOCK ) * PGX_TIMER_0_TMR_REG_MAX );	// Max time with full tmr register, without prescaler, by tens of nano-second [10 ns];
			pgx_timer_0_nanosec_min	= ( ( ( ( 100.000 * PGX_TIMER_FOSC_DIVIDER / PGX_CLOCK ) * PGX_TIMER_0_TMR_REG_MIN ) * PGX_TIMER_0_PRESCALER_MIN ) + PGX_TIMER_0_OFFSET_GUARD );
			pgx_timer_0_nanosec_max	= ( ( ( 100.000 * PGX_TIMER_FOSC_DIVIDER / PGX_CLOCK ) * PGX_TIMER_0_TMR_REG_MAX ) * PGX_TIMER_0_PRESCALER_MAX );	// Max time with full tmr register, with max prescaler, by tens of nano-second [10 ns];

			T0CON = 0b00001000;										// Stops Timer; 16-bit; Internal clock fron oscillator; No prescaler.
		#endif
		/*
				T0CON:
				-----------------------
				TIMER0 CONTROL REGISTER

				TMR0ON T08BIT T0CS T0SE PSA T0PS2 T0PS1 T0PS0
				bit 7 									bit 0
				---------------------------------------------
				bit 7 TMR0ON: Timer0 On/Off Control bit
								1 = Enables Timer0
								0 = Stops Timer0
				bit 6 T08BIT: Timer0 8-bit/16-bit Control bit
								1 = Timer0 is configured as an 8-bit timer/counter
								0 = Timer0 is configured as a 16-bit timer/counter
				bit 5 T0CS: Timer0 Clock Source Select bit
								1 = Transition on T0CKI pin
								0 = Internal instruction cycle clock (CLKO)
				bit 4 T0SE: Timer0 Source Edge Select bit
								1 = Increment on high-to-low transition on T0CKI pin
								0 = Increment on low-to-high transition on T0CKI pin
				bit 3 PSA: Timer0 Prescaler Assignment bit
								1 = TImer0 prescaler is NOT assigned. Timer0 clock input bypasses prescaler.
								0 = Timer0 prescaler is assigned. Timer0 clock input comes from prescaler output.
				bit 2-0 T0PS2:T0PS0: Timer0 Prescaler Select bits
								111 = 1:256 Prescale value
								110 = 1:128 Prescale value
								101 = 1:64 Prescale value
								100 = 1:32 Prescale value
								011 = 1:16 Prescale value
								010 = 1:8 Prescale value
								001 = 1:4 Prescale value
								000 = 1:2 Prescale value
		 */
		//--------------------------------------------------
		#if ( PGIMX_TIMER_1 != PGX_DISABLE )
			pgx_timer_1_period		= ( ( 100.000 * PGX_TIMER_FOSC_DIVIDER ) / PGX_CLOCK );		// One step timer, without prescaler, by tens of nano-second [10 ns];
			pgx_timer_1_count_max	= ( ( ( 100.000 * PGX_TIMER_FOSC_DIVIDER ) / PGX_CLOCK ) * PGX_TIMER_1_TMR_REG_MAX );	// Max time with full tmr register, without prescaler, by tens of nano-second [10 ns];
			pgx_timer_1_nanosec_min	= ( ( ( ( 100.000 * PGX_TIMER_FOSC_DIVIDER / PGX_CLOCK ) * PGX_TIMER_1_TMR_REG_MIN ) * PGX_TIMER_1_PRESCALER_MIN ) + PGX_TIMER_1_OFFSET_GUARD );
			pgx_timer_1_nanosec_max	= ( ( ( 100.000 * PGX_TIMER_FOSC_DIVIDER / PGX_CLOCK ) * PGX_TIMER_1_TMR_REG_MAX ) * PGX_TIMER_1_PRESCALER_MAX );	// Max time with full tmr register, with max prescaler, by tens of nano-second [10 ns];

			T1CON = 0b10000100;										// 16-bit; No prescaler; No sync; Internal clock fron oscillator; Stops Timer;
		#endif
		/*
				T1CON:
				-----------------------
				TIMER1 CONTROL REGISTER

				RD16 T1RUN T1CKPS1 T1CKPS0 T1OSCEN T1SYNC TMR1CS TMR1ON
				bit 7 											  bit 0
				-------------------------------------------------------
				bit 7 RD16: 16-bit Read/Write Mode Enable bit
								1 = Enables register read/write of TImer1 in one 16-bit operation
								0 = Enables register read/write of Timer1 in two 8-bit operations
				bit 6 T1RUN: Timer1 System Clock Status bit
								1 = Device clock is derived from Timer1 oscillator
								0 = Device clock is derived from another source
				bit 5-4 T1CKPS1:T1CKPS0: Timer1 Input Clock Prescale Select bits
								11 = 1:8 Prescale value
								10 = 1:4 Prescale value
								01 = 1:2 Prescale value
								00 = 1:1 Prescale value
				bit 3 T1OSCEN: Timer1 Oscillator Enable bit
								1 = Timer1 oscillator is enabled
								0 = Timer1 oscillator is shut off
								The oscillator inverter and feedback resistor are turned off to eliminate power drain.
				bit 2 T1SYNC: Timer1 External Clock Input Synchronization Select bit
								When TMR1CS = 1:
								1 = Do not synchronize external clock input
								0 = Synchronize external clock input
								When TMR1CS = 0:
								This bit is ignored. Timer1 uses the internal clock when TMR1CS = 0.
				bit 1 TMR1CS: Timer1 Clock Source Select bit
								1 = External clock from pin RC0/T1OSO/T13CKI (on the rising edge)
								0 = Internal clock (FOSC/4)
				bit 0 TMR1ON: Timer1 On bit
								1 = Enables Timer1
								0 = Stops Timer1				
		*/
	}
	//---[ END Timer Init ]---
#endif


