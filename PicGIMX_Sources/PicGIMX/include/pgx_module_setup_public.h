//
#ifndef _PGIMX_MODULE_SETUP_PUBLIC_H_
	#define	_PGIMX_MODULE_SETUP_PUBLIC_H_

	 //================================================================================================================
	 //		S O F T W A R E   G E N E R A L
	 //================================================================================================================
	 #define PGIMX_ERROR                                PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_CAL_DELAY                            PGX_ENABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_FTOA                                 PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_GCP                                  PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_SSP                                  PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_GKH32                                PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_PRS                                  PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_FONT                             	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	
	 //================================================================================================================
	 //		S O F T W A R E   D E V I C E
	 //================================================================================================================
	 #define PGIMX_3WIRE								PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	
	 //================================================================================================================
	 //		H A R D W A R E   I N T E R N A L
	 //================================================================================================================
	 #define PGIMX_EVENTS                               PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_AD_CONVERTER                         PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_SPI                                  PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_I2C                                  PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_EE                                   PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_TIMER                                PGX_ENABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_PWM                                  PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	 #define PGIMX_SERIAL                               PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	
	//================================================================================================================
	//		H A R D W A R E   E X T E R N A L
	//================================================================================================================
	#define PGIMX_LCD_HD44780                           PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	#define PGIMX_LCD_PCD8544                           PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	#define PGIMX_BUZZER                                PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	#define PGIMX_SENSOR                                PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	#define	PGIMX_RTC_DS1302                            PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	#define	PGIMX_EXTERNAL_MEMORY                       PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	#define	PGIMX_AMG88XX                               PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	#define	PGIMX_DDS_AD9851                            PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	
	 //================================================================================================================
	 //		H A R D W A R E   G K R I P T
	 //================================================================================================================
	 #define PGIMX_ENCODER                              PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
	
	
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   E R R O R   H A N D L E R
	 //----------------------------------------------------------------------------------------------------------------
	 #if ( PGIMX_ERROR == PGX_ENABLE )
		 #define	PGX_ERROR_LED_PRESENT               PGX_NO				//!< Must be: PGX_YES || PGX_NO
		 #define	PGX_ERROR_LCD_PRESENT               PGX_NO				//!< Must be: PGX_NO  || PGX_HD44780
	 #endif

	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   C A L - D E L A Y
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.

	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   F T O A
	 //----------------------------------------------------------------------------------------------------------------
	 #if ( PGIMX_FTOA == PGX_ENABLE )
		 #define	PGX_FTOA_PRINT_SIGN_PLUS            PGX_NO				//!< Must be: PGX_YES || PGX_NO
		 #define	PGX_FTOA_PRINT_SIGN_MINUS           PGX_YES				//!< Must be: PGX_YES || PGX_NO
	 #endif
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   G C P
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   S S P
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
		
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   G K H 3 2	
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   P R S
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   F O N T
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   3 W I R E
	 //----------------------------------------------------------------------------------------------------------------
	 #if ( PGIMX_3WIRE == PGX_ENABLE )
		 #define PGX_3WIRE_DIRECTION_INPUT              PGX_LSB_FIRST		//!< Must be: PGX_MSB_FIRST || PGX_LSB_FIRST
		 #define PGX_3WIRE_DIRECTION_OUTPUT             PGX_LSB_FIRST		//!< Must be: PGX_MSB_FIRST || PGX_LSB_FIRST
	 #endif

	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   E V E N T S
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   A D - C O N V E R T E R
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   S P I
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   E E
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   T I M E R
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   P W M 
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   S E R I A L
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   L C D - H D 4 4 7 8 0
	 //----------------------------------------------------------------------------------------------------------------
	 #if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
		 #define	PGX_LCD_HD44780_COLUMNS				16					//!< Number of columns of the display
		 #define	PGX_LCD_HD44780_LINES				2					//!< Number of lines of the display
		 #define	PGX_LCD_HD44780_BUSY_FLAG			PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_BUSY_DELAY			1					//!< Waiting time for display processing in micro-seconds [us]
		 #define	PGX_LCD_HD44780_LINE_0_ADDRESS		0x00				//!< Address (default 0x00) for the line number 1. Must be : PGX_MISSING if there is not.
		 #define	PGX_LCD_HD44780_LINE_1_ADDRESS		0X40				//!< Address (default 0x40) for the line number 2. Must be : PGX_MISSING if there is not.
		 #define	PGX_LCD_HD44780_LINE_2_ADDRESS		PGX_MISSING			//!< Address (default 0x00) for the line number 3. Must be : PGX_MISSING if there is not.
		 #define	PGX_LCD_HD44780_LINE_3_ADDRESS		PGX_MISSING			//!< Address (default 0x40) for the line number 4. Must be : PGX_MISSING if there is not.
		 #define	PGX_LCD_HD44780_BL_0_ENABLE			PGX_ENABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_BL_1_ENABLE			PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_BL_2_ENABLE			PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_BL_3_ENABLE			PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_BL_0_ENABLE_LOGIC	PGX_POSITIVE		//!< Must be: PGX_POSITIVE || PGX_NEGATIVE
		 #define	PGX_LCD_HD44780_BL_1_ENABLE_LOGIC	PGX_POSITIVE		//!< Must be: PGX_POSITIVE || PGX_NEGATIVE
		 #define	PGX_LCD_HD44780_BL_2_ENABLE_LOGIC	PGX_POSITIVE		//!< Must be: PGX_POSITIVE || PGX_NEGATIVE
		 #define	PGX_LCD_HD44780_BL_3_ENABLE_LOGIC	PGX_POSITIVE		//!< Must be: PGX_POSITIVE || PGX_NEGATIVE
		 #define	PGX_LCD_HD44780_SPLASH_FULL_0_EN	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_SPLASH_FULL_1_EN	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_SPLASH_FULL_2_EN	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_SPLASH_FULL_3_EN	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_SPLASH_FULL_DELAY	1					//!< Show time of splash in seconds [s] || 0 = do not clear
		 #define	PGX_LCD_HD44780_SPLASH_SLIDE_0_EN	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_SPLASH_SLIDE_1_EN	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_SPLASH_SLIDE_2_EN	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_SPLASH_SLIDE_3_EN	PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		 #define	PGX_LCD_HD44780_SPLASH_SLIDE_SPEED	1					//!< Slowdown time of slider in milli-seconds [ms]
	 #endif

	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |	L C D _ P C D 8 5 4 4 
	 //----------------------------------------------------------------------------------------------------------------
	 #if ( PGIMX_LCD_PCD8544 == PGX_ENABLE )
		 #define	PGX_PCD8544_DATA			    	1
		 #define	PGX_PCD8544_COMMAND			    	0
		
		 #define	PGX_PCD8544_CONFIGURATION			0x08
		 #define	PGX_PCD8544_FUNCTION				0x20
		 #define	PGX_PCD8544_ADDRESS_Y				0x40
		 #define	PGX_PCD8544_ADDRESS_X				0x80
		 #define	PGX_PCD8544_EXT_TEMP_CONTROL		0x04
		 #define	PGX_PCD8544_EXT_BIAS_CONTROL		0x10
		 #define	PGX_PCD8544_EXT_SET_VOP		    	0x80
	 #endif
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   B U Z Z E R
	 //----------------------------------------------------------------------------------------------------------------
	 #if ( PGIMX_BUZZER == PGX_ENABLE )
		 #define PGX_BEEP_LONG                          100					//!< Defines the long duration of the beep
		 #define	PGX_BEEP_SHORT						40					//!< Defines the short duration of the beep
		 #define	PGX_BEEP_HIGH						1					//!< Defines the high tone of the beep
		 #define	PGX_BEEP_MID						3					//!< Defines the mean tone of the beep
		 #define	PGX_BEEP_LOW						7					//!< Defines the low tone of the beep
	 #endif
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   S E N S O R
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   R T C _ D S 1 3 0 2
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.

	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   E X T E R N A L   M E M O R Y
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.
	
	 //----------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   E N C O D E R
	 //----------------------------------------------------------------------------------------------------------------
	 //Nothing to configure here.

	 //-------------------------------------------------------------------------------------------------------------
	 //		S O F T W A R E   C O N F I G   |   D D S _ A D 9 8 5 1 
	 //-------------------------------------------------------------------------------------------------------------
	 #if ( PGIMX_DDS_AD9851 == PGX_ENABLE )
		 #define	PGX_DDS_AD9851_DATA_MODE			PGX_SERIAL_MODE		//!< Must be: PGX_SERIAL_MODE || PGX_PARALLEL_MODE
		 #define PGX_DDS_AD9851_CLOCK_REF               29999989.0			//!< External oscillator value [Hz] (without multiplier)
		 #define PGX_DDS_AD9851_MULTIPLIER              PGX_ENABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE (Internal 6X PLL)
		 #define PGX_DDS_AD9851_INIT_FREQ           	0.0					//!< Init frequency [Hz] (default is '0.0')
		 //#define PGX_DDS_AD9851_INIT_PHASE            0					//!< Init phase (default is '0')
	 #endif
	//------------------------------------------------------------------------
#endif /* _PGIMX_MODULE_SETUP_PUBLIC_H_ */


