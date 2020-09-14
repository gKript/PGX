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

#ifndef _PGIMX_SELECTIVE_COMPILING_SETUP_H_
	#define _PGIMX_SELECTIVE_COMPILING_SETUP_H_
	
	//========================================================================
	//		LCD_HD44780  -  S e l e c t i v e   c o m p i l i n g
	//========================================================================
	#if ( PGIMX_LCD_HD44780 == PGX_ENABLE )

		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( manual )
		//------------------------------------------------------------------------------------------------------------
		//pg_lcd_hd44780_char_generator()
		#define	PGX_LCD_HD44780_CHAR_GENERATOR					PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_put_p_char()
		#define	PGX_LCD_HD44780_PUT_P_CHAR						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_put_byte()
		#define	PGX_LCD_HD44780_PUT_BYTE						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_put_p_byte()
		#define	PGX_LCD_HD44780_PUT_P_BYTE						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_write_string_rom()
		#define	PGX_LCD_HD44780_WRITE_STRING_ROM				PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_write_p_string()
		#define	PGX_LCD_HD44780_WRITE_P_STRING					PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_write_p_string_flash()
		#define	PGX_LCD_HD44780_WRITE_P_STRING_FLASH			PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_write_p_string_rom()
		#define	PGX_LCD_HD44780_WRITE_P_STRING_ROM				PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_write_p_string_flash_rom()
		#define	PGX_LCD_HD44780_WRITE_P_STRING_FLASH_ROM		PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_write_p_int()
		#define	PGX_LCD_HD44780_WRITE_P_INT						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_lcd_hd44780_write()
		#define	PGX_LCD_HD44780_WRITE							PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( semi-automatic )
		//------------------------------------------------------------------------------------------------------------
		//pg_lcd_hd44780_write_p_char()
		#define	PGX_LCD_HD44780_WRITE_P_CHAR					PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS ARE AUTOMATICALLY DISABLED IF NOT REQUIRED:
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	pg_lcd_hd44780_splash_full()
		//	pg_lcd_hd44780_splash_slide()
		//	pg_lcd_hd44780_read_byte()
		//	pg_lcd_hd44780_char_generator_from_EE()
		//	pg_lcd_hd44780_write_p_float()
		
		//------------------------------------------------------------------------------------------------------------
		//		COMPULSORY FUNCTIONS ( must be compiled ):
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	pg_lcd_hd44780_init()
		//	pg_lcd_hd44780_init_routine()
		//	pg_lcd_hd44780_wait_busy()
		//	pg_ldc_hd44780_write_nibble()
		//	pg_lcd_hd44780_write_byte()
		//	pg_lcd_hd44780_en_select()
		//	pg_lcd_hd44780_clear()
		//	pg_lcd_hd44780_goto()
		//	pg_lcd_hd44780_put_char()
		//	pg_lcd_hd44780_write_string()
	#endif

	//========================================================================
	//		RTC_DS1302  -  S e l e c t i v e   c o m p i l i n g
	//========================================================================
	#if ( PGIMX_RTC_DS1302 == PGX_ENABLE )
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( manual )
		//------------------------------------------------------------------------------------------------------------
		//pg_rtc_ds1302_use_min()
		#define	PGX_RTC_DS1302_USE_MIN							PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_rtc_ds1302_use_hour()
		#define	PGX_RTC_DS1302_USE_HOUR							PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_rtc_ds1302_use_day()
		#define	PGX_RTC_DS1302_USE_DAY							PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_rtc_ds1302_use_month()
		#define	PGX_RTC_DS1302_USE_MONTH						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_rtc_ds1302_use_year()
		#define	PGX_RTC_DS1302_USE_YEAR							PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_rtc_ds1302_use_weekday()
		#define	PGX_RTC_DS1302_USE_WEEKDAY						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE

		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( semi-automatic )
		//------------------------------------------------------------------------------------------------------------
		//pg_rtc_ds1302_wr_time_all()
		#define	PGX_RTC_DS1302_WR_TIME_ALL						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_rtc_ds1302_rd_time_all()
		#define	PGX_RTC_DS1302_RD_TIME_ALL						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_rtc_ds1302_wr_date_all()
		#define	PGX_RTC_DS1302_WR_DATE_ALL						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_rtc_ds1302_rd_date_all()
		#define	PGX_RTC_DS1302_RD_DATE_ALL						PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS ARE AUTOMATICALLY DISABLED IF NOT REQUIRED:
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	None.

		//------------------------------------------------------------------------------------------------------------
		//		COMPULSORY FUNCTIONS ( must be compiled ):
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	pg_rtc_ds1302_init()
		//	pg_rtc_ds1302_wr_access()
		//	pg_rtc_ds1302_start()
		//	pg_rtc_ds1302_stop()
		//	pg_rtc_ds1302_wr_time_sec()
		//	pg_rtc_ds1302_rd_time_sec()
	#endif

	//========================================================================
	//		AD_CONVERTER  -  S e l e c t i v e   c o m p i l i n g
	//========================================================================
	#if ( PGIMX_AD_CONVERTER == PGX_ENABLE )
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( manual )
		//------------------------------------------------------------------------------------------------------------
		//pg_adc_get_user_scale()
		#define	PGX_ADC_GET_USER_SCALE							PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_adc_start_avg()
		#define	PGX_ADC_START_AVG								PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_adc_get_perc()
		#define	PGX_ADC_GET_PERC								PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_adc_get_perc_f()
		#define	PGX_ADC_GET_PERC_F								PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( semi-automatic )
		//------------------------------------------------------------------------------------------------------------
		//	None.
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS ARE AUTOMATICALLY DISABLED IF NOT REQUIRED:
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	None.
		
		//------------------------------------------------------------------------------------------------------------
		//		COMPULSORY FUNCTIONS ( must be compiled ):
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	pg_adc_init()
		//	pg_adc_set()
		//	pg_adc_start()
		//	pg_adc_get()
	#endif
	
	//========================================================================
	//		CALDELAY  -  S e l e c t i v e   c o m p i l i n g
	//========================================================================
	#if ( PGIMX_CAL_DELAY == PGX_ENABLE )
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( manual )
		//------------------------------------------------------------------------------------------------------------
		//pg_delay_sec()
		#define	PGX_DELAY_SEC									PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_delay_msec()
		#define	PGX_DELAY_MSEC									PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_delay_usec()
		#define	PGX_DELAY_USEC									PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_delay()
		#define	PGX_DELAY										PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( semi-automatic )
		//------------------------------------------------------------------------------------------------------------
		//pg_delay_high_priority()
		#define	PGX_DELAY_HIGH_PRIORITY							PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS ARE AUTOMATICALLY DISABLED IF NOT REQUIRED:
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	None.
		
		//------------------------------------------------------------------------------------------------------------
		//		COMPULSORY FUNCTIONS ( must be compiled ):
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	pg_delay_NinstusCalc()
	#endif
	
	//========================================================================
	//		EE  -  S e l e c t i v e   c o m p i l i n g
	//========================================================================
	#if ( PGIMX_EE == PGX_ENABLE )
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( manual )
		//------------------------------------------------------------------------------------------------------------
		//pg_ee_write()
		#define	PGX_EE_WRITE									PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_ee_read()
		#define	PGX_EE_READ										PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_ee_write_buffer()
		#define	PGX_EE_WRITE_BUFFER								PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_ee_read_buffer()
		#define	PGX_EE_READ_BUFFER								PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( semi-automatic )
		//------------------------------------------------------------------------------------------------------------
		//	None.
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS ARE AUTOMATICALLY DISABLED IF NOT REQUIRED:
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	None.
		
		//------------------------------------------------------------------------------------------------------------
		//		COMPULSORY FUNCTIONS ( must be compiled ):
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	pg_ee_init()
	#endif

	//========================================================================
	//		PWM  -  S e l e c t i v e   c o m p i l i n g
	//========================================================================
	#if ( PGIMX_PWM == PGX_ENABLE )
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( manual )
		//------------------------------------------------------------------------------------------------------------
		//pg_pwm_stop()
		#define	PGX_PWM_STOP									PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_pwm_restart()
		#define	PGX_PWM_RESTART									PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_pwm_shutdown()
		#define	PGX_PWM_SHUTDOWN								PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//pg_pwm_dc_res_max()
		#define	PGX_PWM_DC_RES_MAX								PGX_INCLUDE	//!< Must be: PGX_INCLUDE || PGX_EXCLUDE
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS CAN BE DISABLED IF NOT USED ( semi-automatic )
		//------------------------------------------------------------------------------------------------------------
		//	None.
		
		//------------------------------------------------------------------------------------------------------------
		//		THESE FUNCTIONS ARE AUTOMATICALLY DISABLED IF NOT REQUIRED:
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	None.
		
		//------------------------------------------------------------------------------------------------------------
		//		COMPULSORY FUNCTIONS ( must be compiled ):
		//		Nothing can be configured here.
		//------------------------------------------------------------------------------------------------------------
		//	pg_pwm_init()
		//	pg_pwm_set()
		//	pg_pwm_dutycycle()
		//	pg_pwm_start()
	#endif

    //========================================================================

#endif /* _PGIMX_SELECTIVE_COMPILING_SETUP_H_ */


