/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgx_hardware_setup_public.h
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
		\file		pgx_hardware_setup_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		Hardware details configuration public file.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIMX_HARDWARE_SETUP_PUBLIC_H_
	#define	_PGIMX_HARDWARE_SETUP_PUBLIC_H_

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   L E D - E R R O R
	//------------------------------------------------------------------------------
	#if ( ( PGX_ERROR == PGX_ENABLE ) && ( PGX_ERROR_LED_PRESENT == PGX_YES ) )
		// LAT
		#define	PGX_ERROR_LED						L_B0				//!< Must be: <pin-lat-name>
		// TRIS
		#define	PGX_ERROR_LED_TRIS					T_B0				//!< Must be: <pin-tris-name>
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   L C D - H D 4 4 7 8 0
	//------------------------------------------------------------------------------
	#if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
		// LAT
		#define PGX_LCD_HD44780_RS					L_D4				//!< Must be: <pin-lat-name>
		#define PGX_LCD_HD44780_RW_PRESENT			PGX_YES				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_RW					L_D5				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_0_PRESENT			PGX_YES				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_EN_0					L_D6				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_1_PRESENT			PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_EN_1					PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_2_PRESENT			PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_EN_2					PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_3_PRESENT			PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_EN_3					PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_DATA_0				L_D0				//!< Must be: <pin-lat-name> (lcd DB4)
		#define PGX_LCD_HD44780_DATA_1				L_D1				//!< Must be: <pin-lat-name> (lcd DB5)
		#define PGX_LCD_HD44780_DATA_2				L_D2				//!< Must be: <pin-lat-name> (lcd DB6)
		#define PGX_LCD_HD44780_DATA_3				L_D3				//!< Must be: <pin-lat-name> (lcd DB7)
		#define PGX_LCD_HD44780_BL_0_PRESENT			PGX_YES				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_BL_0					L_D7				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_1_PRESENT			PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_BL_1					PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_2_PRESENT			PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_BL_2					PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_3_PRESENT			PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_BL_3					PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		// TRIS		
		#define PGX_LCD_HD44780_RS_TRIS				T_D4				//!< Must be: <pin-tris-name>
		#define PGX_LCD_HD44780_RW_TRIS				T_D5				//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_0_TRIS			T_D6				//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_1_TRIS			PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_2_TRIS			PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_3_TRIS			PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_DATA_0_TRIS			T_D0				//!< Must be: <pin-tris-name> (lcd DB4)
		#define PGX_LCD_HD44780_DATA_1_TRIS			T_D1				//!< Must be: <pin-tris-name> (lcd DB4)
		#define PGX_LCD_HD44780_DATA_2_TRIS			T_D2				//!< Must be: <pin-tris-name> (lcd DB4)
		#define PGX_LCD_HD44780_DATA_3_TRIS			T_D3				//!< Must be: <pin-tris-name> (lcd DB4)
		#define PGX_LCD_HD44780_BL_0_TRIS			T_D7				//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_1_TRIS			PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_2_TRIS			PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_3_TRIS			PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		// PORT
		#define PGX_LCD_HD44780_DATA_0_PORT			P_D0				//!< Must be: <pin-port-name> || PGX_MISSING if not used. (lcd DB4)
		#define PGX_LCD_HD44780_DATA_1_PORT			P_D1				//!< Must be: <pin-port-name> || PGX_MISSING if not used. (lcd DB4)
		#define PGX_LCD_HD44780_DATA_2_PORT			P_D2				//!< Must be: <pin-port-name> || PGX_MISSING if not used. (lcd DB4)
		#define PGX_LCD_HD44780_DATA_3_PORT			P_D3				//!< Must be: <pin-port-name> || PGX_MISSING if not used. (lcd DB4)
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |	L C D - P C D 8 5 4 4
	//------------------------------------------------------------------------------
	#if ( PGIMX_LCD_PCD8544 == PGX_ENABLE )
		#define	PGX_LCD_PCD8544_VIDEO_MEMORY			PGX_NO
		// LAT
		#define	PGX_LCD_PCD8544_BACKLIGHT			L_B2
		#define PGX_LCD_PCD8544_VDD					PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used
		#define PGX_LCD_PCD8544_DC					L_C0
		#define PGX_LCD_PCD8544_RST					L_C1
		#define PGX_LCD_PCD8544_CE 					L_C2
		// TRIS
		#define	PGX_LCD_PCD8544_BACKLIGHT_TRIS		T_B2
		#define PGX_LCD_PCD8544_VDD_TRIS				PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used
		#define PGX_LCD_PCD8544_DC_TRIS				T_C0
		#define PGX_LCD_PCD8544_RST_TRIS				T_C1
		#define PGX_LCD_PCD8544_CE_TRIS				T_C2
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   B U Z Z E R
	//------------------------------------------------------------------------------
	#if ( PGIMX_BUZZER == PGX_ENABLE )
		// LAT
		#define	PGX_BUZZER_PIN						L_C2				//!< Must be: <pin-lat-name>
		//TRIS
		#define	PGX_BUZZER_PIN_TRIS					T_C2				//!< Must be: <pin-tris-name>
	#endif
	
	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   E N C O D E R
	//------------------------------------------------------------------------------
	#if ( PGIMX_ENCODER == PGX_ENABLE )
		// PORT
		#define	PGX_ENCODER_STEP						P_B0				//!< Must be: <pin-port-name>
		#define	PGX_ENCODER_DIR						P_B5				//!< Must be: <pin-port-name>
		#define	PGX_ENCODER_SW						P_B6				//!< Must be: <pin-port-name>
		// TRIS
		#define	PGX_ENCODER_STEP_TRIS				T_B0				//!< Must be: <pin-tris-name>
		#define	PGX_ENCODER_DIR_TRIS					T_B5				//!< Must be: <pin-tris-name>
		#define	PGX_ENCODER_SW_TRIS					T_B6				//!< Must be: <pin-tris-name>
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   E X T E R N A L   M E M O R Y
	//------------------------------------------------------------------------------
	#if ( PGIMX_EXTERNAL_MEMORY == PGX_ENABLE )
		// LAT
		#define	PGX_EXTERNAL_MEMORY_CS				L_B3				//!< Must be: <pin-lat-name>
		// TRIS
		#define	PGX_EXTERNAL_MEMORY_CS_TRIS			T_B3				//!< Must be: <pin-tris-name>
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   R T C   D S 1 3 0 2
	//------------------------------------------------------------------------------
	#if ( PGIMX_RTC_DS1302 == PGX_ENABLE )
		// LAT
		#define	PGX_RTC_DS1302_CS 					L_B0				//!< Must be: <pin-lat-name>
		// TRIS
		#define PGX_RTC_DS1302_CS_TRIS				T_B0				//!< Must be: <pin-tris-name>
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   3 W I R E
	//------------------------------------------------------------------------------
	#if ( PGIMX_3WIRE == PGX_ENABLE )
		// LAT
		#define PGX_3WIRE_IO							L_B1				//!< Must be: <pin-lat-name>
		#define PGX_3WIRE_CK 						L_B2				//!< Must be: <pin-lat-name>
		// TRIS		
		#define PGX_3WIRE_IO_TRIS					T_B1				//!< Must be: <pin-tris-name>
		#define PGX_3WIRE_CK_TRIS					T_B2				//!< Must be: <pin-tris-name>
		// PORT
		#define PGX_3WIRE_IO_PORT					P_B1				//!< Must be: <pin-port-name>
	#endif
	
	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   A M G 8 8 X X
	//------------------------------------------------------------------------------
	#if ( PGIMX_AMG88XX == PGX_ENABLE )
		// TRIS
		#define PGX_AMG88XX_IRQ_DEVICE1_TRIS			PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_AMG88XX_IRQ_DEVICE2_TRIS			PGX_MISSING			//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		// PORT
		#define PGX_AMG88XX_IRQ_DEVICE1				PGX_MISSING			//!< Must be: <pin-port-name> || PGX_MISSING if not used.
		#define PGX_AMG88XX_IRQ_DEVICE2				PGX_MISSING			//!< Must be: <pin-port-name> || PGX_MISSING if not used.
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   A D 9 8 5 1
	//------------------------------------------------------------------------------
	#if ( PGIMX_DDS_AD9851 == PGX_ENABLE )
		// TRIS
		#define PGX_DDS_AD9851_SERIAL_DATA_TRIS		T_D7				//!< Must be: <pin-tris-name> || PGX_MISSING if not used.	//Used in serial data mode to control AD9851 pin#25 "D7"
		#define PGX_DDS_AD9851_WORD_CLOCK_TRIS		T_B1				//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_DDS_AD9851_FREQ_UPDATE_TRIS		T_B2				//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_DDS_AD9851_RESET_TRIS			T_B3				//!< Must be: <pin-tris-name> || PGX_MISSING if not used.
		#define PGX_DDS_AD9851_DATABUS_TRIS			PGX_MISSING			//!< Must be: <port-tris-name> || PGX_MISSING if not used.	//Used in parallel data mode.
		// LAT
		#define PGX_DDS_AD9851_SERIAL_DATA			L_D7				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.		//Used in serial data mode to control AD9851 pin#25 "D7"
		#define PGX_DDS_AD9851_WORD_CLOCK			L_B1				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_DDS_AD9851_FREQ_UPDATE			L_B2				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_DDS_AD9851_RESET					L_B3				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_DDS_AD9851_DATABUS				PGX_MISSING			//!< Must be: <port-lat-name> || PGX_MISSING if not used.	//Used in parallel data mode.
	#endif
	
#endif /* _PGIMX_HARDWARE_SETUP_PUBLIC_H_ */


