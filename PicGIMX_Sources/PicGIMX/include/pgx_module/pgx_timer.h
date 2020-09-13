/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgx_timer.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgx_timer.c

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
		\file		pgx_timer.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily use the Timer device.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIMX_TIMER_H_
	#define _PGIMX_TIMER_H_

	#if ( PGIMX_TIMER == PGX_ENABLE )

		#define	PGX_ENABLE_LOOP						100
		#define	PGX_ENABLE_1_SHOT					101

		//---[ Status ]---
		#define	PGX_TIMER_ALREADY_STARTED			10				//!< Timer is already started.
		#define	PGX_TIMER_ALREADY_STOPPED			11				//!< Timer is already stopped.
		#define	PGX_TIMER_IS_RUNNING					12				//!< Timer is running.
		//---[ END Status ]---
		
		//---[ Error ]---
		#define	PGX_TIMER_ERROR						201				//!< Timer unknown error.
		#define PGX_TIMER_ERROR_ID					202				//!< Timer identifier not enabled or wrong.
		#define PGX_TIMER_ERROR_TIME_TOO_LONG		203				//!< Required time is too high!
		#define PGX_TIMER_ERROR_TIME_TOO_SHORT		204				//!< Required time is too short!
		//---[ END Error ]---
		
		//---[ Variables ]---
		#define	PGX_TIMER_FOSC_DIVIDER				4.000			//!< Internal clock divider to drive timer.
		//---[ END Variables ]---
		
		//---[ Prototypes ]---	
		/*!
			\brief			This function properly initializes the TIMER module.
			\attention		Internal use only !
			\return			Nothing.
			\param			Nothing.
			\deprecated		Do not call directly. \n
							Already called in pgx_initialize().
		*/
		void	pgx_timer_init						( void );

		/*!
			\brief			Allows to configure the timer selected by \a timer_id parameter and calculates the limit values.
			\return			\b PGX_OK : if the configuration was successful. \n
							\b PGX_NOK : if the configuration was not successful. \n For details about the error, it is possible to check the environment variables of this module : \ref SWG_error
			\param			timer_id				The identification number of the timer. \n
								Use \b PGX_TIMER_0 to select \a Timer 0 \n
								Use \b PGX_TIMER_1 to select \a Timer 1
			\param			timer_time				The required timer value.
			\param			unit_measure			The unit of measure of the timer value. \n
								Use \b PGX_SEC if timer_time is expressed in seconds [s]. \n
								Use \b PGX_MSEC if timer_time is expressed in milli-seconds[ms].

		 	\test	 		\b PGX_OK : if the configuration was successful. \n
							\b PGX_TIMER_ERROR_ID : if the timer_id parameter is wrong. \n
							\b PGX_TIMER_IS_RUNNING : if it was not possible to configure the timer because active. \n
							\b PGX_TIMER_ERROR_TIME_TOO_SHORT : if it was not possible to configure the timer because the time required is too short. \n
							\b PGX_TIMER_ERROR_TIME_TOO_LONG : if it was not possible to configure the timer because the time required is too long.

			\attention		\b PGX_TIMER_ERROR_TIME_TOO_SHORT and \b PGX_TIMER_ERROR_TIME_TOO_LONG generate \b FATAL errors. Refer to the error module : \ref SWG_error

		 	\warning		This function must be called when the timer is stopped.
		*/			
		_pgx_Uint8	pgx_timer_set_period				( _pgx_Uint8 timer_id , _pgx_float timer_time , _pgx_Uint8 unit_measure );
		
		/*!
			\brief			Converts the specified frequency in period and performs a call to \ref pgx_timer_set_period function.
			\return			\b PGX_OK : if the configuration was successful. \n
							\b PGX_NOK : if the configuration was not successful. \n For details about the error, it is possible to check the environment variables of this module : \ref SWG_error
			\param			timer_id				The identification number of the timer. \n
								Use \b PGX_TIMER_0 to select \a Timer 0 \n
								Use \b PGX_TIMER_1 to select \a Timer 1
			\param			timer_freq				The required frequency value.
			\param			unit_measure			The unit of measure of the timer value. \n
								Use \b PGX_HZ if timer_time is expressed in Hertz [Hz]. \n
								Use \b PGX_KHZ if timer_time is expressed in kilo-Hertz [KHz].

		 	\test	 		\b PGX_OK : if the configuration was successful. \n
							\b PGX_TIMER_ERROR_ID : if the timer_id parameter is wrong. \n
							\b PGX_TIMER_IS_RUNNING : if it was not possible to configure the timer because active. \n
							\b PGX_TIMER_ERROR_TIME_TOO_SHORT : if it was not possible to configure the timer because the frequency required is too high. \n
							\b PGX_TIMER_ERROR_TIME_TOO_LONG : if it was not possible to configure the timer because the frequency required is too low.

			\attention		\b PGX_TIMER_ERROR_TIME_TOO_SHORT and \b PGX_TIMER_ERROR_TIME_TOO_LONG generate \b FATAL errors. Refer to the error module : \ref SWG_error

		 	\warning		This function must be called when the timer is stopped.
		*/		
		_pgx_Uint8	pgx_timer_set_freq				( _pgx_Uint8 timer_id , _pgx_float timer_freq , _pgx_Uint8 unit_measure );	// PGX_HZ || PGX_KHZ
		
		/*!
			\brief			Allows to start the timer selected by \a timer_id parameter.
			\return			\b PGX_OK : if the timer has been started successfully. \n
							\b PGX_TIMER_ERROR_ID : if the timer_id parameter is wrong. \n
							\b PGX_TIMER_ALREADY_STARTED : if it has not been possible to start the timer because it is already running.
			\param			timer_id				The identification number of the required timer. \n
								Use \b PGX_TIMER_0 to select Timer 0 \n
								Use \b PGX_TIMER_1 to select Timer 1
		*/
		_pgx_Uint8	pgx_timer_start					( _pgx_Uint8 timer_id );
		
		/*!
			\brief			Allows to stop the timer selected by \a timer_id parameter.
			\return			\b PGX_OK : if the timer has been stopped successfully. \n
							\b PGX_TIMER_ERROR_ID : if the timer_id parameter is wrong. \n
							\b PGX_TIMER_ALREADY_STOPPED : if it has not been possible to stop the timer because it was already in stopped.
			\param			timer_id				The identification number of the timer. \n
								Use \b PGX_TIMER_0 to select Timer 0 \n
								Use \b PGX_TIMER_1 to select Timer 1
		*/
		_pgx_Uint8	pgx_timer_stop					( _pgx_Uint8 timer_id );
		
		/*!
			\brief			Converts the value of the timer contained in the two 8-bit registers (TMRxH and TMRxL) in a 16-bit value.
			\return			The current value of the timer registers in 16-bit Format.
			\param			timer_id				The identification number of the timer. \n
								Use \b PGX_TIMER_0 to select Timer 0 \n
								Use \b PGX_TIMER_1 to select Timer 1
		*/
		_pgx_Uint16	pgx_timer_reg_current_value		( _pgx_Uint8 timer_id );	
		//---[ Prototypes ]---
		
		//---[ Timer_0 ]---    
		#if ( PGIMX_TIMER_0 != PGX_DISABLE )

			#define PGX_TIMER_0						0				//!< Timer 0 identifier.
			
			#define PGX_TIMER_0_PRESCALER_MIN		1				//!< Min prescaler value (8bit). Set to 1 to disable prescaler, not to 0, it is used in a division with the clock value.
			#define PGX_TIMER_0_PRESCALER_MAX		256				//!< Max prescaler value (8bit). Not 255, it is used in a division with the clock value.
			
			#define	PGX_TIMER_0_TMR_REG_MIN			1.000			//!< Timer register min value. Not 0.
			#define PGX_TIMER_0_TMR_REG_MAX			65535.000		//!< Timer register max value (16bit).

			#define PGX_TIMER_0_OFFSET_GUARD			500.000			//!< Guard offset in determination of the minimum possible time.

			extern	_pgx_Uint16_VAL	pgx_timer_0_tmr_reg_set_save;	//!< Backup the 16-bit value of the timer 0 register.

			#if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
				#if ( PGIMX_TIMER_0 == PGX_ENABLE_1_SHOT )
					#warning	PicGIM >>> TIMER 0 module >>> Set 1-SHOT mode
				#elif ( PGX_TIMER_0 == PGX_ENABLE_LOOP )
					#warning	PicGIM >>> TIMER 0 module >>> Set LOOP mode
				#endif
				#if ( PGIMX_TIMER_0 != PGX_DISABLE ) && ( PGX_SUGGESTION == PGX_ENABLE )
					#warning	PicGIM >>> TIMER 0 module >>> Hint >>> Max time available is PGX_TIMER_FOSC_DIVIDER * PGX_TIMER_0_TMR_REG_MAX * PGX_TIMER_0_PRESCALER_MAX / PGX_CLOCK [us]
				#endif
			#endif
			
			#if defined( _GIM_H_ ) && defined( __18CXX ) //&& ( PGX_VERBOSE == PGX_ENABLE )
				#if ( PGX_CLOCK < 4 )
					#warning	PicGIM >>> TIMER 0 module >>> Sorry, DOES NOT WORK correctly with a clock frequency below 4.000 [MHz]
				#endif
			#endif
		#endif
		//---[ END Timer_0 ]---				#define PGX_TIMER_1_TMR_REG_8BIT_MAX     256.000         //!< Timer register max value (8bit)

		//---[ Timer_1 ]---
		#if ( PGIMX_TIMER_1 != PGX_DISABLE )

			#define PGX_TIMER_1						1				//!< Timer 1 identifier.
			
			#define PGX_TIMER_1_PRESCALER_MIN		1               //!< Min prescaler value (2bit). Set to 1 to disable prescaler, not to 0, it is used in a division with the clock value.
			#define PGX_TIMER_1_PRESCALER_MAX		8				//!< Max prescaler value (2bit). Not 7, it is used in a division with the clock value.
			
			#define	PGX_TIMER_1_TMR_REG_MIN			1.000			//!< Timer register min value.
			#define PGX_TIMER_1_TMR_REG_MAX			65535.000       //!< Timer register max value (16bit).

			#define PGX_TIMER_1_OFFSET_GUARD         500.000         //!< Guard offset in determination of the minimum possible time value.

			extern	_pgx_Uint16_VAL	pgx_timer_1_tmr_reg_set_save;	//!< Backup the 16-bit value of the timer 1 register.

			#if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
				#if ( PGIMX_TIMER_1 == PGX_ENABLE_1_SHOT )
					#warning	PicGIM >>> TIMER 1 module >>> Set 1-SHOT mode
				#elif ( PGX_TIMER_1 == PGX_ENABLE_LOOP )
					#warning PicGIM >>> TIMER 1 module >>> Set LOOP mode
				#endif
				#if ( PGIMX_TIMER_1 != PGX_DISABLE ) && ( PGX_SUGGESTION == PGX_ENABLE )
					#warning	PicGIM >>> TIMER 1 module >>> Hint >>> Max time available is PGX_TIMER_FOSC_DIVIDER * PGX_TIMER_1_TMR_REG_MAX * PGX_TIMER_1_PRESCALER_MAX / PGX_CLOCK [us]
				#endif
			#endif
			
			#if defined( _GIM_H_ ) && defined( __18CXX ) //&& ( PGX_VERBOSE == PGX_ENABLE )
				#if ( PGX_CLOCK < 4 )
					#warning	PicGIM >>> TIMER 1 module >>> Sorry, DOES NOT WORK correctly with a clock frequency below 4.000 [MHz]
				#endif
			#endif
		#endif
		//---[ END Timer_1 ]---

	#endif
#endif /*_PGIMX_TIMER_H_ */

//			\arg \b PGX_DISABLE : Timer is disabled. Only set the necessary parameters.
//			\arg \b PGX_ENABLE_1_SHOT : When the timer starts, runs a loop and then stops.
//			\arg \b PGX_ENABLE_LOOP : When the timer starts, it continues to run until it is stopped.


/*!	
	\page 		HWI_timer			Timer

		\tableofcontents

		\image	html	timer.png
		
		The \b TIMER module provides a set of functions to easily configure and manage timers in different units of time (seconds or milliseconds). \n 
		The module can be configured in order to obtain a continuous timer or a timer that spins just once.
			
		In the public configuration file \ref pgx_timer_setup_public.h are specified clearly the possible values for the various parameters. \n
		For software reference please read the documentation in \ref pgx_timer.h
		
		\attention		The device managed by this module has interrupt signals. \n
							If you want to use please \b read \b carefully the chapter \ref HWI_interrupt . 
		
		\endcode
			\n \n \n
		
		\section	qsdtimerconf	Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg \b pgx_module_setup_public.h : the main management file for the modules that must be included in the project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref fewtimerconfenm  \n
					\n \n \n
				\arg \b pgx_timer_setup_public.h : where are collected all the features of the module. \n
						Here are specified the possible values for the various parameters and when they have to be set depending on the chosen mode of operation of the module. \n
						In this file there are these configurations  : \n \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref dwjp2cnbptimer \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref CLCDenmtimer \n
						\n \n \n &nbsp;&nbsp;&nbsp;&nbsp;

			\attention	For software reference, please read the documentation about \b pgx_timer.h . \n
						This is \b not a file defined as \b public and therefore it would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing.
			</p>

  			\n \n \n

			\subsection	fewtimerconfenm		Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGX_TIMER							PGX_ENABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PGX_ENABLE : Timer module enabled.
					\arg \b PGX_DISABLE : Timer module disabled.
					\endcode

				\subsubsection	timermodenref		References
					\li \e File : pgx_module_setup_public.h \n
					\li \e Reference : \ref PGX_TIMER \n

			\subsection	dwjp2cnbptimer	Channels enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGX_TIMER_0					PGX_ENABLE_LOOP
					#define PGX_TIMER_1					PGX_DISABLE
				\endcode
					These defines enable or disable independently pwm channels. \n
					They must be: \n
					\arg \b PGX_DISABLE			: Timer is disabled. Only set the necessary parameters.
					\arg \b PGX_ENABLE_1_SHOT	: When the timer starts, runs a loop and then stops.
					\arg \b PGX_ENABLE_LOOP		: When the timer starts, it continues to run until it is stopped.

				\subsubsection	timerchenref		References
					\li \e File : pgx_timer_setup_public.h \n
					\li \e Reference : \ref PGX_TIMER_0 \n
					\li \e Reference : \ref PGX_TIMER_1 \n

			\subsection	CLCDenmtimer	The delay Trim
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGX_TIMER_0_DELAY_TRIM			320
					#define PGX_TIMER_1_DELAY_TRIM			299
				\endcode
				\htmlonly
					These definitions are the result of an empirical test on the execution time of an interruption on its timer. <br>
					The time is expressed in uSec and refers to the delta between the first instruction in the function pgx_event_occurred() callback to the first instruction in the related Timer. <br>
				\endhtmlonly

				\subsubsection	timerenhenref		References
					\li \e File : pgx_timer_setup_public.h \n
					\li \e Reference : \ref PGX_TIMER_0_DELAY_TRIM \n
					\li \e Reference : \ref PGX_TIMER_1_DELAY_TRIM \n


  		\section	fdwtimercsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

			\attention	This module can use the \b Error \b Handling \b Module : \ref SWG_error \n
						In the \e TEST section of each function is specified which values ​​are set and in which cases. \n
						Please refer to the specific documentation of the file header: \ref pgx_timer.h

			\htmlonly <br> \endhtmlonly

			\subsection	timerprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pgx_timer_init() : This is the initialization function of the Timer handler module.

				\htmlonly <br><br> \endhtmlonly

			\subsection	timerpubfunc	Public functions
				\endcode

				\arg \b pgx_timer_set_period() : Allows to configure, through period, the timer selected by timer_id parameter and calculates the limit values.
				\arg \b pgx_timer_set_freq() : Allows to configure, through frequency, the timer selected by timer_id parameter and calculates the limit values.
				\arg \b pgx_timer_start() : Allows to start the timer selected by timer_id parameter.
				\arg \b pgx_timer_stop() : Allows to stop the timer selected by timer_id parameter.
				\arg \b pgx_timer_reg_current_value() : Converts the value of the timer contained in the two 8-bit registers (TMRxH and TMRxL) in a 16-bit value. 

				\endcode

			\htmlonly <br><br> \endhtmlonly

	\section	timerexampleuse	A code example
		\htmlonly <hr> \endhtmlonly
		\endcode
 
		Here is a simple example of how to use the module in the user code.
		\warning	In order to compile this example, the module must be enabled and properly configured.

		\code
			...

			pgx_timer_set_period( PGX_TIMER_0 , 1 , PGX_SEC );
			pgx_timer_set_period( PGX_TIMER_1 , 50 , PGX_MSEC );
			pgx_timer_start( PGX_TIMER_0 );
			pgx_timer_start( PGX_TIMER_1 );

			...
		\endcode

		\htmlonly <br><br> \endhtmlonly

	\section	timerinterrupthowto	Using this module with interrupts
		\endhtmlonly

		If the interrupt handling is enable is possible, through the interrupt signal \ref PGX_EVENT_SET_TMR0 or \ref PGX_EVENT_SET_TMR1, have an interrupt at every end of counting. \n
		If using the \b Automatic \b Interrupts \b Handler pgx_event_auto_handler() will call the associated callback: pgx_interrupts_event_tmr0() or pgx_interrupts_event_tmr1() \n
		So once entered the code inside the callback it will be executed at every end of counting. \n

		References :
			Interrups configuration :\ref iterruptconf \n
			Internal interrupts configuration : \ref interdefinesintern \n
			Callback configuration : \ref interruptcallbackhowto \n 

		\warning 	To use the \b User \b Interrupt \b Handler is necessary to read carefully the entire documentation related : pgx_event_user_handler() \n



		\htmlonly <br><br> \endhtmlonly



*/


