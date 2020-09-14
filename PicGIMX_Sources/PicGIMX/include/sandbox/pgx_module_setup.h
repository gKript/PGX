//
#ifndef _PGIMX_MODULE_SETUP_H_
	#define	_PGIMX_MODULE_SETUP_H_
	//========================================================================
	//	D E B U G   O N L Y
	//========================================================================
	#define PGX_ALL_MODULES_DISABLED				PGX_DISABLE
//	//========================================================================
//	//	D E F A U L T   M O D U L E   I N C L U S I O N
//	//========================================================================
//	//------------------------------------------------------------------------
//	//	Software General	
//	//------------------------------------------------------------------------
//	#define PGX_ERROR								PGX_DISABLE
//	#define PGX_CAL_DELAY							PGX_DISABLE
//	#define PGX_FTOA								PGX_DISABLE
//	#define	PGX_GCP								PGX_DISABLE
//	#define	PGX_SSP								PGX_DISABLE
//	#define	PGX_GKH32								PGX_DISABLE
//	#define	PGX_PRS								PGX_DISABLE
//	#define	PGX_FONT								PGX_DISABLE
//	//------------------------------------------------------------------------
//	//	Software Device	
//	//------------------------------------------------------------------------
//	#define PGX_3WIRE								PGX_DISABLE
//	//------------------------------------------------------------------------
//	//	Hardware Internal
//	//------------------------------------------------------------------------
//	#define PGX_EVENTS								PGX_DISABLE
//	#define PGX_AD_CONVERTER						PGX_DISABLE
//	#define PGX_SPI								PGX_DISABLE
//	#define PGX_I2C								PGX_DISABLE
//	#define PGX_EE									PGX_DISABLE
//	#define PGX_TIMER								PGX_DISABLE
//	#define PGX_PWM								PGX_DISABLE
//	#define PGX_SERIAL								PGX_DISABLE
//	//------------------------------------------------------------------------
//	//	Hardware External
//	//------------------------------------------------------------------------
//	#define PGX_LCD_HD44780						PGX_DISABLE
//	#define PGX_LCD_PCD8544						PGX_DISABLE
//	#define PGX_BUZZER								PGX_DISABLE
//	#define PGX_SENSOR								PGX_DISABLE
//	#define	PGX_RTC_DS1302							PGX_DISABLE
//	#define	PGX_EXTERNAL_MEMORY					PGX_DISABLE
//	#define	PGX_AMG88XX							PGX_DISABLE
//	#define	PGX_DDS_AD9851							PGX_DISABLE
//	//------------------------------------------------------------------------
//	//	Hardware gKript
//	//------------------------------------------------------------------------
//	#define PGX_ENCODER							PGX_DISABLE
	//========================================================================
	//	P U B L I C   F I L E S   I N C L U S I O N
	//========================================================================
	#include "pgx_project_setup_public.h"
	#include "pgx_ezfuse.h"
	#include "pgx_module_setup_public.h"
//     #include "pgim_font_setup_public.h"
//	 #include "pgim_event_setup_public.h"
	 #include "pgx_timer_setup_public.h"
//	 #include "pgim_pwm_setup_public.h"
//	 #include "pgim_serial_setup_public.h"
//	 #include "pgim_external_memory_setup_public.h"
//	 #include "pgim_amg88xx_setup_public.h"
//	 #include "pgim_sensor_setup_public.h"
//	 #include "pgim_gcp_setup_public.h"
//	 #include "pgim_ssp_setup_public.h"
//	 #include "pgim_prs_setup_public.h"
//	 #include "pgim_dds_ad9851_setup_public.h"
     #include "pgx_hardware_setup.h"
	//========================================================================
	//	M O D U L E   I N C L U S I O N
	//========================================================================
//	#if defined( _PGIMX_DELAY_H_ )
//		#undef  PGIMX_CAL_DELAY
//        #define PGIMX_CAL_DELAY PGX_ENABLE
//	#endif
//	#if defined( _PGIMX_LCD_HD44780_H_ )
//		#undef  PGIMX_LCD_HD44780
//        #define PGIMX_LCD_HD44780 PGX_ENABLE
//	#endif
		
	
	//------------------------------------------------------------------------
	//	D E L A Y   M A C R O
	//------------------------------------------------------------------------
	//(dependancy from: xc8 pic18.h && pgx_hardware_setup.h)
	//#define pgx_delay_usec( x )	_delay( (unsigned long)( ( x ) * ( _XTAL_FREQ / 4000000.0) ) )
	//#define pgx_delay_msec( x )	_delay( (unsigned long)( ( x ) * ( _XTAL_FREQ / 4000.0) ) )
	//#define pgx_delay_sec( x )	_delay( (unsigned long)( ( x ) * ( _XTAL_FREQ / 4.0) ) )
	// //------------------------------------------------------------------------------	
	// //		D E P E N D E N C Y    M A N A G E M E N T
	// //------------------------------------------------------------------------------	

	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   D E B U G
	// //------------------------------------------------------------------------------
	// #if ( PGIMX_ERROR == PGX_ENABLE )
		// #if ( PGX_PROJECT_STATE != PGX_DEBUG )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must set the PROJECT STATE to DEBUG in pgim_project_setup_public.h as required by other modules or DISABLE the module that need DEBUG STATE
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif
	
	 //------------------------------------------------------------------------------
	 //	D e p e n d e n c y   o n   D E L A Y
	 //------------------------------------------------------------------------------
	 #if ( PGIMX_LCD_HD44780 == PGX_ENABLE ) || \
		 ( PGIMX_LCD_PCD8544 == PGX_ENABLE ) || \
		 ( PGIMX_LCD_9340 == PGX_ENABLE ) || \
		 ( PGIMX_BUZZER == PGX_ENABLE ) || \
		 ( ( PGIMX_SERIAL == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL ) && ( ( PGX_SERIAL_DEBUG_TO_PIN == PGX_ENABLE ) || ( PGX_SERIAL_DEBUG_TO_LCD_PCD8544 == PGX_ENABLE ) || ( PGX_SERIAL_DEBUG_TO_LCD_HD44780 == PGX_ENABLE ) ) ) || \
		 ( PGIMX_EXTERNAL_MEMORY == PGX_ENABLE ) || \
		 ( ( PGIMX_ERROR == PGX_ENABLE ) && ( PGX_ERROR_LED_PRESENT == PGX_YES ) ) || \
		 ( PGIMX_TIMER == PGX_ENABLE ) || \
		 ( PGIMX_ENCODER == PGX_ENABLE ) || \
		 ( PGIMX_DDS_AD9851 == PGX_ENABLE )
	
		 #if ( PGIMX_CAL_DELAY == PGX_DISABLE )
			 #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the DELAY module required by other modules
			 #ifndef		PGX_EXIT_ON_ERROR
				 #define		PGX_EXIT_ON_ERROR
			 #endif
		 #endif
	 #endif

	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   A D   C O N V E R T E R
	// //------------------------------------------------------------------------------
	// #if ( PGIMX_SENSOR == PGX_ENABLE )

		// #if ( PGIMX_AD_CONVERTER == PGX_DISABLE )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the AD CONVERTER module required by other modules
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif

	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   S P I
	// //------------------------------------------------------------------------------
	// #if ( ( PGX_LCD_PCD8544 == PGX_ENABLE ) || ( PGX_SERIAL_DEBUG_TO_LCD_PCD8544 == PGX_ENABLE ) || ( PGX_EXTERNAL_MEMORY == PGX_ENABLE ) )
		// #if ( PGIMX_SPI == PGX_DISABLE )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the SPI module required by other modules
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif

	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   I 2 C
	// //------------------------------------------------------------------------------
	// #if ( PGIMX_AMG88XX == PGX_ENABLE )
		// #if ( PGIMX_I2C == PGX_DISABLE )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the I2C module required by other modules
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif

	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   L C D - P C D 8 5 4 4
	// //------------------------------------------------------------------------------
	// #if ( ( PGX_SERIAL == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL ) && ( PGX_SERIAL_DEBUG_TO_LCD_PCD8544 == PGX_ENABLE ) )

		// #if ( PGIMX_LCD_PCD8544 == PGX_DISABLE ) && defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the LCD-PCD8544 module required by other modules
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif
	
	 //------------------------------------------------------------------------------
	 //	D e p e n d e n c y   o n   L C D - H D 4 4 7 8 0
	 //------------------------------------------------------------------------------
	 #if ( ( PGIMX_SERIAL == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL ) && ( PGX_SERIAL_DEBUG_TO_LCD_HD44780 == PGX_ENABLE ) ) \
		 && defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
		
		 #if ( PGIMX_LCD_HD44780 == PGX_DISABLE )
			 #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the LCD-HD44780 module required by other modules
			 #ifndef		PGX_EXIT_ON_ERROR
				 #define		PGX_EXIT_ON_ERROR
			 #endif
		 #endif
	 #endif

	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   B U Z Z E R
	// //------------------------------------------------------------------------------
	// #if ( ( PGX_SERIAL == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL ) && ( PGX_SERIAL_DEBUG_TO_BUZZER == PGX_ENABLE ) )
		 
		// #if ( PGIMX_BUZZER == PGX_DISABLE )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the BUZZER module required by other modules
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif
	
	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   3 W I R E
	// //------------------------------------------------------------------------------
	// #if ( PGIMX_RTC_DS1302 == PGX_ENABLE )
		 
		// #if ( PGIMX_3WIRE == PGX_DISABLE )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the 3WIRE module required by other modules
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif
	
	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   R T C - D S 1 3 0 2
	// //------------------------------------------------------------------------------
	// #if ( PGIMX_RTC_DS1302 == PGX_ENABLE )
		 
		// #if ( PGIMX_3WIRE == PGX_DISABLE )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the 3WIRE module required by other modules
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif
	
	// //------------------------------------------------------------------------------
	// //	D e p e n d e n c y   o n   F O N T S
	// //------------------------------------------------------------------------------
	// #if ( ( PGX_SERIAL == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL ) && ( PGX_SERIAL_DEBUG_TO_LCD_PCD8544 == PGX_ENABLE ) )

		// #if ( PGIMX_SERIAL == PGX_ENABLE ) && defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #if ( PGIMX_FONT == PGX_DISABLE )
				// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable FONT module as required by SERIAL debug
				// #ifndef		PGX_EXIT_ON_ERROR
					// #define		PGX_EXIT_ON_ERROR
				// #endif
			// #endif
			// #if ( PGX_FONT_5X8 == PGX_NOT_INCLUDE )
				// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must include 5X8 font as required by SERIAL debug
				// #ifndef		PGX_EXIT_ON_ERROR
					// #define		PGX_EXIT_ON_ERROR
				// #endif
			// #endif
		// #endif
	// #endif
	
	// //------------------------------------------------------------------------------
	// //		C O N F L I C T   M A N A G E M E N T
	// //------------------------------------------------------------------------------
	// #if ( PGX_BOARD == PGX_BOARD_A )
		// #if ( PGX_PIN_NUMBER != 28 )
			// #warning	PicGIM >>> ERROR !!! >>> Board A  >>> You are using an MCU NOT COMPATIBLE with Board A.
			// #warning	PicGIM >>> ERROR !!! >>> Continue >>> Board A can only support MCU DIL with 28 Pin.
			// #ifndef	PGX_EXIT_ON_ERROR
				// #define	PGX_EXIT_ON_ERROR
			// #endif
         // #endif
    // #endif

	// #if ( ( PGX_SPI == PGX_ENABLE ) && ( PGX_I2C == PGX_ENABLE ) )
		// #error	PicGIM >>> ERROR !!! >>> MSSP HW module >>> Hardware conflict.
		// #error	PicGIM >>> ERROR !!! >>> Continue       >>> Currently it is not possible to use both modules at the same time.
		// #ifndef	PGX_EXIT_ON_ERROR
			// #define	PGX_EXIT_ON_ERROR
		// #endif
    // #endif
	
#endif /* _PGIMX_MODULE_SETUP_H_ */
 
 
 
