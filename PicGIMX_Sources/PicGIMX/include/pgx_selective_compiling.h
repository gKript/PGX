/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_selective_compiling.h
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

/*!		\file		pgx_selective_compiling.h
		\version	0.6-0
		\date		2002 - 2016
		\brief		
		\details	
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
*/

#ifndef _PGIMX_SELECTIVE_COMPILING_H_
	#define _PGIMX_SELECTIVE_COMPILING_H_
	//------------------------------------------------------------------------
	#if defined( PGX_DOXYGEN )
		//========================================================================
		//		LCD_HD44780  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
			#undef	PGX_LCD_HD44780_CHAR_GENERATOR
			#define	PGX_LCD_HD44780_CHAR_GENERATOR					PGX_INCLUDE
			#undef	PGX_LCD_HD44780_PUT_P_CHAR
			#define	PGX_LCD_HD44780_PUT_P_CHAR						PGX_INCLUDE
			#undef	PGX_LCD_HD44780_PUT_BYTE
			#define	PGX_LCD_HD44780_PUT_BYTE						PGX_INCLUDE
			#undef	PGX_LCD_HD44780_PUT_P_BYTE
			#define	PGX_LCD_HD44780_PUT_P_BYTE						PGX_INCLUDE
			#undef	PGX_LCD_HD44780_WRITE_STRING_ROM
			#define	PGX_LCD_HD44780_WRITE_STRING_ROM				PGX_INCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_STRING
			#define	PGX_LCD_HD44780_WRITE_P_STRING					PGX_INCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_STRING_FLASH
			#define	PGX_LCD_HD44780_WRITE_P_STRING_FLASH			PGX_INCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_STRING_ROM
			#define	PGX_LCD_HD44780_WRITE_P_STRING_ROM				PGX_INCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_STRING_FLASH_ROM
			#define	PGX_LCD_HD44780_WRITE_P_STRING_FLASH_ROM		PGX_INCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_INT
			#define	PGX_LCD_HD44780_WRITE_P_INT						PGX_INCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_CHAR
			#define	PGX_LCD_HD44780_WRITE_P_CHAR					PGX_INCLUDE
			#undef	PGX_LCD_HD44780_WRITE
			#define	PGX_LCD_HD44780_WRITE							PGX_INCLUDE
		#endif
		//========================================================================
		//		RTC_DS1302  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_RTC_DS1302 == PGX_ENABLE )
			#undef	PGX_RTC_DS1302_USE_MIN
			#define	PGX_RTC_DS1302_USE_MIN							PGX_INCLUDE
			#undef	PGX_RTC_DS1302_USE_HOUR
			#define	PGX_RTC_DS1302_USE_HOUR							PGX_INCLUDE
			#undef	PGX_RTC_DS1302_USE_DAY
			#define	PGX_RTC_DS1302_USE_DAY							PGX_INCLUDE
			#undef	PGX_RTC_DS1302_USE_MONTH
			#define	PGX_RTC_DS1302_USE_MONTH						PGX_INCLUDE
			#undef	PGX_RTC_DS1302_USE_YEAR
			#define	PGX_RTC_DS1302_USE_YEAR							PGX_INCLUDE
			#undef	PGX_RTC_DS1302_USE_WEEKDAY
			#define	PGX_RTC_DS1302_USE_WEEKDAY						PGX_INCLUDE
			#undef	PGX_RTC_DS1302_WR_TIME_ALL
			#define	PGX_RTC_DS1302_WR_TIME_ALL						PGX_INCLUDE
			#undef	PGX_RTC_DS1302_RD_TIME_ALL
			#define	PGX_RTC_DS1302_RD_TIME_ALL						PGX_INCLUDE
			#undef	PGX_RTC_DS1302_WR_DATE_ALL
			#define	PGX_RTC_DS1302_WR_DATE_ALL						PGX_INCLUDE
			#undef	PGX_RTC_DS1302_RD_DATE_ALL
			#define	PGX_RTC_DS1302_RD_DATE_ALL						PGX_INCLUDE
		#endif
		//========================================================================
		//		AD_CONVERTER  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_AD_CONVERTER == PGX_ENABLE )
			#undef	PGX_ADC_GET_USER_SCALE
			#define	PGX_ADC_GET_USER_SCALE							PGX_INCLUDE
			#undef	PGX_ADC_START_AVG
			#define	PGX_ADC_START_AVG								PGX_INCLUDE
			#undef	PGX_ADC_GET_PERC
			#define	PGX_ADC_GET_PERC								PGX_INCLUDE
			#undef	PGX_ADC_GET_PERC_F
			#define	PGX_ADC_GET_PERC_F								PGX_INCLUDE
		#endif
		//========================================================================
		//		CALDELAY  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_CAL_DELAY == PGX_ENABLE )
			#undef	PGX_DELAY_SEC
			#define	PGX_DELAY_SEC									PGX_INCLUDE
			#undef	PGX_DELAY_MSEC
			#define	PGX_DELAY_MSEC									PGX_INCLUDE
			#undef	PGX_DELAY_USEC
			#define	PGX_DELAY_USEC									PGX_INCLUDE
			#undef	PGX_DELAY
			#define	PGX_DELAY										PGX_INCLUDE
			#undef	PGX_DELAY_HIGH_PRIORITY
			#define	PGX_DELAY_HIGH_PRIORITY							PGX_INCLUDE
		#endif
		//========================================================================
		//		EE  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_EE == PGX_ENABLE )
			#undef	PGX_EE_WRITE										
			#define	PGX_EE_WRITE									PGX_INCLUDE
			#undef	PGX_EE_READ										
			#define	PGX_EE_READ										PGX_INCLUDE
			#undef	PGX_EE_WRITE_BUFFER								
			#define	PGX_EE_WRITE_BUFFER								PGX_INCLUDE
			#undef	PGX_EE_READ_BUFFER								
			#define	PGX_EE_READ_BUFFER								PGX_INCLUDE
		#endif
		//========================================================================
		//		PWM  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_PWM == PGX_ENABLE )
			#undef	PGX_PWM_STOP										
			#define	PGX_PWM_STOP									PGX_INCLUDE
			#undef	PGX_PWM_RESTART										
			#define	PGX_PWM_RESTART									PGX_INCLUDE
			#undef	PGX_PWM_SHUTDOWN								
			#define	PGX_PWM_SHUTDOWN								PGX_INCLUDE
			#undef	PGX_PWM_DC_RES_MAX								
			#define	PGX_PWM_DC_RES_MAX								PGX_INCLUDE
		#endif
	#elif ( ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG ) )
		//========================================================================
		//		LCD_HD44780  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
			#undef	PGX_LCD_HD44780_CHAR_GENERATOR
			#define	PGX_LCD_HD44780_CHAR_GENERATOR					PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_PUT_P_CHAR
			#define	PGX_LCD_HD44780_PUT_P_CHAR						PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_PUT_BYTE
			#define	PGX_LCD_HD44780_PUT_BYTE						PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_PUT_P_BYTE
			#define	PGX_LCD_HD44780_PUT_P_BYTE						PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_WRITE_STRING_ROM
			#define	PGX_LCD_HD44780_WRITE_STRING_ROM				PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_STRING
			#define	PGX_LCD_HD44780_WRITE_P_STRING					PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_STRING_FLASH
			#define	PGX_LCD_HD44780_WRITE_P_STRING_FLASH			PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_STRING_ROM
			#define	PGX_LCD_HD44780_WRITE_P_STRING_ROM				PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_STRING_FLASH_ROM
			#define	PGX_LCD_HD44780_WRITE_P_STRING_FLASH_ROM		PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_INT
			#define	PGX_LCD_HD44780_WRITE_P_INT						PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_WRITE_P_CHAR
			#define	PGX_LCD_HD44780_WRITE_P_CHAR					PGX_EXCLUDE
			#undef	PGX_LCD_HD44780_WRITE
			#define	PGX_LCD_HD44780_WRITE							PGX_EXCLUDE
		#endif
		//========================================================================
		//		RTC_DS1302  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_RTC_DS1302 == PGX_ENABLE )
			#undef	PGX_RTC_DS1302_USE_MIN
			#define	PGX_RTC_DS1302_USE_MIN							PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_USE_HOUR
			#define	PGX_RTC_DS1302_USE_HOUR							PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_USE_DAY
			#define	PGX_RTC_DS1302_USE_DAY							PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_USE_MONTH
			#define	PGX_RTC_DS1302_USE_MONTH						PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_USE_YEAR
			#define	PGX_RTC_DS1302_USE_YEAR							PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_USE_WEEKDAY
			#define	PGX_RTC_DS1302_USE_WEEKDAY						PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_WR_TIME_ALL
			#define	PGX_RTC_DS1302_WR_TIME_ALL						PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_RD_TIME_ALL
			#define	PGX_RTC_DS1302_RD_TIME_ALL						PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_WR_DATE_ALL
			#define	PGX_RTC_DS1302_WR_DATE_ALL						PGX_EXCLUDE
			#undef	PGX_RTC_DS1302_RD_DATE_ALL
			#define	PGX_RTC_DS1302_RD_DATE_ALL						PGX_EXCLUDE
		#endif
		//========================================================================
		//		AD_CONVERTER  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_AD_CONVERTER == PGX_ENABLE )
			#undef	PGX_ADC_GET_USER_SCALE
			#define	PGX_ADC_GET_USER_SCALE							PGX_EXCLUDE
			#undef	PGX_ADC_START_AVG
			#define	PGX_ADC_START_AVG								PGX_EXCLUDE
			#undef	PGX_ADC_GET_PERC
			#define	PGX_ADC_GET_PERC								PGX_EXCLUDE
			#undef	PGX_ADC_GET_PERC_F
			#define	PGX_ADC_GET_PERC_F								PGX_EXCLUDE
		#endif
		//========================================================================
		//		CALDELAY  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_CAL_DELAY == PGX_ENABLE )
			#undef	PGX_DELAY_SEC
			#define	PGX_DELAY_SEC									PGX_EXCLUDE
			#undef	PGX_DELAY_MSEC
			#define	PGX_DELAY_MSEC									PGX_EXCLUDE
			#undef	PGX_DELAY_USEC
			#define	PGX_DELAY_USEC									PGX_EXCLUDE
			#undef	PGX_DELAY
			#define	PGX_DELAY										PGX_EXCLUDE
			#undef	PGX_DELAY_HIGH_PRIORITY
			#define	PGX_DELAY_HIGH_PRIORITY							PGX_EXCLUDE
		#endif
		//========================================================================
		//		EE  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_EE == PGX_ENABLE )
			#undef	PGX_EE_WRITE										
			#define	PGX_EE_WRITE									PGX_EXCLUDE
			#undef	PGX_EE_READ										
			#define	PGX_EE_READ										PGX_EXCLUDE
			#undef	PGX_EE_WRITE_BUFFER								
			#define	PGX_EE_WRITE_BUFFER								PGX_EXCLUDE
			#undef	PGX_EE_READ_BUFFER								
			#define	PGX_EE_READ_BUFFER								PGX_EXCLUDE
		#endif
		//========================================================================
		//		PWM  -  R e d e f i n i t i o n s
		//========================================================================
		#if ( PGIMX_PWM == PGX_ENABLE )
			#undef	PGX_PWM_STOP										
			#define	PGX_PWM_STOP									PGX_EXCLUDE
			#undef	PGX_PWM_RESTART										
			#define	PGX_PWM_RESTART									PGX_EXCLUDE
			#undef	PGX_PWM_SHUTDOWN								
			#define	PGX_PWM_SHUTDOWN								PGX_EXCLUDE
			#undef	PGX_PWM_DC_RES_MAX								
			#define	PGX_PWM_DC_RES_MAX								PGX_EXCLUDE
		#endif
	#endif
#endif /* _PGIMX_SELECTIVE_COMPILING_H_ */


