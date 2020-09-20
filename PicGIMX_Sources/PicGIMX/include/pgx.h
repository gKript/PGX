//
#ifndef _PGIMX_INCLUDES_H_
	#define _PGIMX_INCLUDES_H_
    /*!
		\brief		To correct initialize PGX environment
	*/
	void pgx_initialize( void );
    
	//-------------------------------------------------------------------------------
	//    I N C L U S I O N S :     E N V I R O N M E N T
	//-------------------------------------------------------------------------------
	#include <xc.h>
	//-------------------------------------------------------------------------------
	//    I N C L U S I O N S :     S T A N D A R D
	//-------------------------------------------------------------------------------
    #include <stdio.h>
	#include <stdbool.h>
	//-------------------------------------------------------------------------------
	//    I N C L U S I O N S :     P I C G I M X
	//-------------------------------------------------------------------------------
	#include "pgx_custom_type.h"
	#include "pgx_version.h"
	#include "pgx_define.h"
	#include "pgx_project_setup_public.h"
	#include "pgx_ezfuse.h"
	#include "pgx_hardware_setup.h"
	#include "pgx_module_setup.h"
	#include "pgx_hardware_setup_public.h"
	#include "pgx_selective_compiling_setup.h"
	#include "pgx_selective_compiling.h"
    #include "pgx_pin_mapping.h"
	//-------------------------------------------------------------------------------
	//    I N C L U S I O N S :     M O D U L E S
	//-------------------------------------------------------------------------------
	// //---[ Board A ]---
	// #if ( PGX_BOARD != PGX_BOARD_USER_DEFINED )
		// #if ( PGX_BOARD == PGX_BOARD_A )
			// #include "pgim_board_setup_a.h"
			// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
				// #warning	PGX >>> Board A >>> Defined
			// #endif
		// #endif
		// #if ( PGX_BOARD == PGX_BOARD_EXPERIENCE )
			// #include "pgim_board_setup_experience.h"
			// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
				// #warning	PGX >>> Experience Board >>> Defined
			// #endif
		// #endif
	// #endif
	// //---[ END Board A ]---

	
	// //---[ Error ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_ERROR
		// #define		PGX_ERROR		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_ERROR
		// #define		PGX_ERROR		PGX_DISABLE
	// #endif
	// #if ( PGIMX_ERROR == PGX_ENABLE )
// /*
		// enum _pgmodules_code_enum {
			// PGX_ADC,
			// PGX_BUZZER,
			// PGX_DELAY,
			// PGX_EE,
			// PGX_ENCODER,
			// PGX_EXT_MEM,
			// PGX_EZFUSE,
			// PGX_FONT,
			// PGX_INTERRUTPS,
			// PGX_LCD_HD44780,
			// PGX_LCD_PCD8544,
			// PGX_PWM,
			// PGX_SERIAL,
			// PGX_SPI,
			// PGX_TIMER,
			// PGX_FTOA,
			// PGX_SENSOR,
			// PGX_RTC_DS1302,
			// PGX_3WIRE,
			// PGX_GCP,
			// PGX_SSP,
			// PGX_GKH32,
			// PGX_PRS,
			// PGX_AD9851
		// };
// */
		// #include "pgim_error.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> ERROR module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------

	//---[ Calibrated Delay ]---
	#if defined( PGX_DOXYGEN )
		#undef		PGX_CAL_DELAY
		#define		PGX_CAL_DELAY		PGX_ENABLE
	#elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		#undef		PGX_CAL_DELAY
		#define		PGX_CAL_DELAY		PGX_DISABLE
	#endif
	#if ( PGIMX_CAL_DELAY == PGX_ENABLE )
		//#define	_XTAL_FREQ              PGX_CLOCK
		#include "pgx_delay.h"
		#if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			#warning	PGX >>> DELAY module >>> Loaded
		#endif
	#else
		#if defined( __18CXX )
			#include <delays.h>
		#endif
	#endif
	//-------------------------------------------------------------------------------
	
	// //---[ Buzzer ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_BUZZER
		// #define		PGX_BUZZER		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_BUZZER
		// #define		PGX_BUZZER		PGX_DISABLE
	// #endif
	// #if ( PGIMX_BUZZER == PGX_ENABLE )
	
		// #include "pgim_buzzer.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> BUZZER module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	//---[ Interrupts ]---
	#if defined( PGX_DOXYGEN )
		//-------------------------------------------------------------------------------
		#undef		PGX_EVENT
		#undef		PGX_EVENT_SET_INT0	
		#undef		PGX_EVENT_SET_INT1	
		#undef		PGX_EVENT_SET_INT2	
		#undef		PGX_EVENT_SET_TMR0	
		#undef		PGX_EVENT_SET_TMR1	
		#undef		PGX_EVENT_SET_TMR2	
		#undef		PGX_EVENT_SET_RB0	
		#undef		PGX_EVENT_SET_AD		
		#undef		PGX_EVENT_SET_USARTRC      
		#undef		PGX_EVENT_SET_USARTTX      
		#undef		PGX_EVENT_SET_SSP	
		#undef		PGX_EVENT_SET_CCP1	
		#undef		PGX_EVENT_SET_CCP2	
		#undef		PGX_EVENT_SET_OSCF	
		#undef		PGX_EVENT_SET_CM		
		#undef		PGX_EVENT_SET_EE		
		#undef		PGX_EVENT_SET_BCL	
		//---
		#define		PGX_EVENT				PGX_ENABLE
		#define		PGX_EVENT_SET_INT0		PGX_ENABLE
		#define		PGX_EVENT_SET_INT1		PGX_ENABLE
		#define		PGX_EVENT_SET_INT2		PGX_ENABLE
		#define		PGX_EVENT_SET_TMR0		PGX_ENABLE
		#define		PGX_EVENT_SET_TMR1		PGX_ENABLE
		#define		PGX_EVENT_SET_TMR2		PGX_ENABLE
		#define		PGX_EVENT_SET_RB0		PGX_ENABLE
		#define		PGX_EVENT_SET_AD		PGX_ENABLE
		#define		PGX_EVENT_SET_USARTRC	PGX_ENABLE
		#define		PGX_EVENT_SET_USARTTX	PGX_ENABLE
		#define		PGX_EVENT_SET_SSP		PGX_ENABLE
		#define		PGX_EVENT_SET_CCP1		PGX_ENABLE
		#define		PGX_EVENT_SET_CCP2		PGX_ENABLE
		#define		PGX_EVENT_SET_OSCF		PGX_ENABLE
		#define		PGX_EVENT_SET_CM		PGX_ENABLE
		#define		PGX_EVENT_SET_EE		PGX_ENABLE
		#define		PGX_EVENT_SET_BCL		PGX_ENABLE
	#elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		#undef		PGX_EVENT
		#define		PGX_EVENT				PGX_DISABLE
	#endif
	//-------------------------------------------------------------------------------
	#if ( PGIMX_EVENT == PGX_ENABLE )
		//-------------------------------------------------------------------------------
		#include "pgim_event.h"
		//#include "pgim_interrupt_callbacks.h"
		#if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			#warning	PGX >>> IRQ module >>> INTERRUPTS handle module loaded
			#if ( PGX_SUGGESTION == PGX_ENABLE )
				#warning PGX >>> Note >>> Hint >>> See the documentation to know how initialize interrupts you want to manage.
			#endif
		#endif
	#else
		#if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE ) && ( PGX_SUGGESTION == PGX_ENABLE )
			#warning	PGX >>> Note >>> INTERRUPTS disabled
			#warning    PGX >>> Note >>> Hint >>> Keep in mind that PicGim offers a very simple way to use them. See the documentation.
		#endif
	#endif
	//-------------------------------------------------------------------------------
	
	
	// //---[ AD-Converter ]---
	// #if defined( PGX_DOXYGEN )
	
		// #undef		PGX_AD_CONVERTER
		// #define		PGX_AD_CONVERTER		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_AD_CONVERTER
		// #define		PGX_AD_CONVERTER		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_AD_CONVERTER == PGX_ENABLE )
		// #include "pgim_adc.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> ADC module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	
	// //---[ Spi ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_SPI
		// #define		PGX_SPI		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_SPI
		// #define		PGX_SPI		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_SPI == PGX_ENABLE )
		// #include <spi.h>
		// #include "pgim_spi.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> SPI module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	
	// //---[ I2C ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_I2C
		// #define		PGX_I2C		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_I2C
		// #define		PGX_I2C		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_I2C == PGX_ENABLE )
		// #include <i2c.h>
		// #include "pgim_i2c.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> I2C module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	
	// //---[ EE ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_EE
		// #define		PGX_EE		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_EE
		// #define		PGX_EE		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_EE == PGX_ENABLE )
		// #include "pgim_ee.h"
		// #if defined( __18F97J60 )
			// #warning	PGX >>> ERROR !!! >>> Core >>> You have requested the EE module but this MCU [ 18F97J60 ] have not the EEPROM on board. Please disable the module EE in "pgim_module_setup_public.h"
			// #ifndef		PGX_EXIT_ON_ERROR
				// #define		PGX_EXIT_ON_ERROR
			// #endif
		// #else
			// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
				// #warning	PGX >>> EE module >>> Loaded
			// #endif
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	
	 //---[ Timer ]---
	 #if defined( PGX_DOXYGEN )
		 #undef		PGX_TIMER
		 #define		PGX_TIMER		PGX_ENABLE
	 #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		 #undef		PGX_TIMER
		 #define		PGX_TIMER		PGX_DISABLE
	 #endif
	//-------------------------------------------------------------------------------
	 #if ( PGIMX_TIMER == PGX_ENABLE )
    	//#include <plib/timers.h>
		 #include "pgx_timer.h"
		 #if ( PGX_TIMER_0 != PGX_DISABLE )
			 #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
				 #warning	PGX >>> TIMER 0 module >>> Loaded
			 #endif
		 #endif
		 #if ( PGX_TIMER_1 != PGX_DISABLE )
			 #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
				 #warning	PGX >>> TIMER 1 module >>> Loaded
			 #endif
		 #endif
		 #if ( PGIMX_EVENT == PGX_DISABLE )
			 #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE ) && ( PGX_SUGGESTION == PGX_ENABLE )
				 #warning	PGX >>> TIMER module >>> Hint >>> Enabled without interrupt. Keep in mind PicGIM is able to handle interrupts very easily.
			 #endif
		 #endif
	 #endif
	//-------------------------------------------------------------------------------
	
	
	// //---[ Pwm ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_PWM
		// #define		PGX_PWM		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_PWM
		// #define		PGX_PWM		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_PWM == PGX_ENABLE )
// //		#include <pwm.h>        //kmod
		// #include "pgim_pwm.h"
		// #if defined( __24FJ256GB110 )
			// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
				// #warning	PGX >>> ERROR !!! >>> Core >>> You have requested the PWM module but it is NOT YET SUPPORTED with this MCU. \
								// Please disable this module in "pgim_module_setup_public.h"
				// #ifndef		PGX_EXIT_ON_ERROR
					// #define		PGX_EXIT_ON_ERROR
				// #endif
			// #endif
		// #endif
		// //--------------------------------------------------
		// #if defined( PGX_DOXYGEN )
			// #undef		PGX_PWM_1
			// #define		PGX_PWM_1		PGX_ENABLE
		// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
			// #undef		PGX_PWM_1
			// #define		PGX_PWM_1		PGX_DISABLE
		// #endif
		// //--------------------------------------------------
		// #if ( PGX_PWM_1 == PGX_ENABLE )
		
			// #if defined( _GIM_H_ ) && ( PGX_PWM_1_MODE == PGX_NONE )
				// #warning	PGX >>> ERROR !!! >>> Core >>> Sorry, module NOT PRESENT in this MCU. Please disable it in "pgim_pwm_setup_public.h"
				// #ifndef		PGX_EXIT_ON_ERROR
					// #define		PGX_EXIT_ON_ERROR
				// #endif
			// #else
				// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
					// #warning	PGX >>> PWM 1 module >>> Loaded
				// #endif
				// #if defined( _GIM_H_ ) && ( PGX_PWM_1_MODE != PGX_ENHANCED ) && ( PGX_PWM_1_ENHANCED == PGX_ENABLE )
					// #warning	PGX >>> ERROR !!! >>> Core >>> Sorry, ENHANCED mode NOT SUPPORTED.	Please disable it in "pgim_pwm_setup_public.h"
					// #ifndef		PGX_EXIT_ON_ERROR
						// #define		PGX_EXIT_ON_ERROR
					// #endif
				// #endif
				// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE ) && ( PGX_PWM_1_MODE == PGX_ENHANCED ) && ( PGX_PWM_1_ENHANCED == PGX_ENABLE )
					// #if ( PGX_PWM_1_OUT_CONF != SINGLE_OUT )
						// #warning	PGX >>> PWM 1 module >>> ENHANCED mode enabled
						// #if ( PGX_PWM_AUTO_SHUTDOWN == PGX_ENABLE )
							// #warning	PGX >>> PWM 1 module >>> AUTO-SHUTDOWN feature enabled
						// #endif
					// #else
						// #warning	PGX >>> PWM 1 module >>> ENHANCED mode is disabled in SINGLE mode
						// #if ( PGX_PWM_AUTO_SHUTDOWN == PGX_ENABLE )
							// #warning	PGX >>> PWM 1 module >>> AUTO-SHUTDOWN feature is disabled in SINGLE mode
						// #endif
					// #endif
				// #endif
				// #if defined( _GIM_H_ )&& ( PGX_VERBOSE == PGX_ENABLE ) && ( PGX_SUGGESTION == PGX_ENABLE ) && \
					// ( PGX_PWM_1_MODE == PGX_ENHANCED ) && ( PGX_PWM_1_ENHANCED == PGX_DISABLE )
					
					// #warning	PGX >>> PWM 1 module >>> Hint >>> Keep in mind that this module supports the ENHANCED mode
				// #endif
			// #endif
		// #endif
		// //--------------------------------------------------
		// #if defined( PGX_DOXYGEN )
			// #undef		PGX_PWM_2
			// #define		PGX_PWM_2		PGX_ENABLE
		// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
			// #undef		PGX_PWM_2
			// #define		PGX_PWM_2		PGX_DISABLE
		// #endif
		// //--------------------------------------------------
		// #if ( PGX_PWM_2 == PGX_ENABLE )
		
			// #if defined( _GIM_H_ ) && ( PGX_PWM_2_MODE == PGX_NONE )
				// #warning	PGX >>> ERROR !!! >>> Core >>> Sorry, module NOT PRESENT in this MCU. Please disable it in "pgim_pwm_setup_public.h"
				// #ifndef		PGX_EXIT_ON_ERROR
					// #define		PGX_EXIT_ON_ERROR
				// #endif
			// #else
				// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
					// #warning	PGX >>> PWM 2 module >>> Loaded
				// #endif
				// #if defined( _GIM_H_ ) && ( PGX_PWM_2_MODE != PGX_ENHANCED ) && ( PGX_PWM_2_ENHANCED == PGX_ENABLE )
					// #warning	PGX >>> ERROR !!! >>> Core >>> Sorry, ENHANCED mode NOT SUPPORTED. Please disable it in "pgim_pwm_setup_public.h"
					// #ifndef		PGX_EXIT_ON_ERROR
						// #define		PGX_EXIT_ON_ERROR
					// #endif
				// #endif
				// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE ) && ( PGX_PWM_2_MODE == PGX_ENHANCED ) && ( PGX_PWM_2_ENHANCED == PGX_ENABLE )
					// #if ( PGX_PWM_2_OUT_CONF != SINGLE_OUT )
						// #warning	PGX >>> PWM 2 module >>> ENHANCED mode enabled
						// #if ( PGX_PWM_AUTO_SHUTDOWN == PGX_ENABLE )
							// #warning	PGX >>> PWM 2 module >>> SHUTDOWN feature enabled
						// #endif
					// #else
						// #warning	PGX >>> PWM 2 module >>> ENHANCED mode is disabled in SINGLE mode
						// #if ( PGX_PWM_AUTO_SHUTDOWN == PGX_ENABLE )
							// #warning	PGX >>> PWM 2 module >>> SHUTDOWN feature is disabled in SINGLE mode
						// #endif
					// #endif
				// #endif
				// #if defined( _GIM_H_ )&& ( PGX_VERBOSE == PGX_ENABLE ) && ( PGX_SUGGESTION == PGX_ENABLE ) && \
					// ( PGX_PWM_2_MODE == PGX_ENHANCED ) && ( PGX_PWM_2_ENHANCED == PGX_DISABLE )
					// #warning	PGX >>> PWM 2 module >>> Hint >>> Keep in mind that this module supports the ENHANCED mode
				// #endif
			// #endif
		// #endif
// //		#if	defined( _GIM_H_ ) && \
// //			( ( ( PGX_PWM_1 == PGX_ENABLE ) && ( PGX_PWM_1_ENHANCED == PGX_ENABLE ) && ( PGX_PWM_1_MODE == PGX_ENHANCED ) \
// //			&& ( PGX_PWM_1_OUT_CONF == HALF_OUT ) ) || ( ( PGX_PWM_2 == PGX_ENABLE ) && ( PGX_PWM_2_ENHANCED == PGX_ENABLE ) \
// //			&& ( PGX_PWM_2_MODE == PGX_ENHANCED ) && ( PGX_PWM_2_OUT_CONF == HALF_OUT ) ) )

		// #if	defined( _GIM_H_ )
			// #if ( ( PGX_PWM_1 == PGX_ENABLE ) && ( PGX_PWM_1_ENHANCED == PGX_ENABLE ) && ( PGX_PWM_1_MODE == PGX_ENHANCED ) && ( PGX_PWM_1_OUT_CONF == HALF_OUT ) ) || \
				// ( ( PGX_PWM_2 == PGX_ENABLE ) && ( PGX_PWM_2_ENHANCED == PGX_ENABLE ) && ( PGX_PWM_2_MODE == PGX_ENHANCED ) && ( PGX_PWM_2_OUT_CONF == HALF_OUT ) )			

				// #if ( PGX_PWM_DEAD_TIME > ( ( 1 / PGX_CLOCK ) * PGX_TCYCLEPERI * 0x7F ) )
// //				#if ( PGX_PWM_DEAD_TIME > ( PGX_TCYCLEPERI * 0x7F / ( PGX_CLOCK / 1000000 ) ) )
					// #warning	PGX >>> ERROR !!! >>> Core >>> Dead-time is too long. Please decrease the value in "pgim_pwm_setup_public.h"
					// #ifndef		PGX_EXIT_ON_ERROR
						// #define		PGX_EXIT_ON_ERROR
					// #endif
				// #else
					// #warning	PGX >>> PWM module >>> Set DEAD-TIME
				// #endif
			// #endif
		// #endif
		// #if	defined( _GIM_H_ ) && ( PGX_SUGGESTION == PGX_ENABLE ) && ( PGX_PWM_DC_RESOLUTION_MAX_CALC == PGX_ENABLE ) && \
			// ( ( PGX_PWM_1 == PGX_ENABLE ) || ( PGX_PWM_2 == PGX_ENABLE ) )
			// #warning	PGX >>> PWM module >>> Enabled duty-cycle resolution max calculation [bit]
		// #endif	
	// #endif
	//-------------------------------------------------------------------------------
	
	//---[ Lcd HD44780 ]---
	 #if defined( PGX_DOXYGEN )
		 #undef		PGX_LCD_HD44780
		 #define		PGX_LCD_HD44780		PGX_ENABLE
	 #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		 #undef		PGX_LCD_HD44780
		 #define		PGX_LCD_HD44780		PGX_DISABLE
	 #endif
	//--------------------------------------------------
	 #if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
		 #include "pgx_lcd_hd44780.h"
		  #if ( ( PGX_LCD_HD44780_BUSY_FLAG == PGX_ENABLE ) && ( PGX_LCD_HD44780_RW_PRESENT == PGX_NO ) )
			  #error	PicGIMX (LCD HD44780 module) Can not read busy flag, because writing pin is not used!
		  #endif
		  #if ( PGX_VERBOSE == PGX_ENABLE )
			  #warning PicGIMX: LCD HD44780 module >>> Loaded
		  #endif
	 #endif
	//-------------------------------------------------------------------------------

	// //---[ Lcd PCD8544 ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_LCD_PCD8544
		// #define		PGX_LCD_PCD8544		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_LCD_PCD8544
		// #define		PGX_LCD_PCD8544		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_LCD_PCD8544 == PGX_ENABLE )
		// #include "pgim_lcd_pcd8544.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> LCD PCD8544 module >>> Loaded
			// #if ( PGIMX_FONT == PGX_ENABLE )
				// #warning	PGX >>> LCD PCD8544 module >>> Fonts enabled and loaded
			// #endif
		// #endif
	// #endif
						// // //---[ Lcd 5110 ]---
						// // #if defined( PGX_DOXYGEN )
							// // #undef		PGX_LCD_5110
							// // #define		PGX_LCD_5110		PGX_ENABLE
						// // #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
							// // #undef		PGX_LCD_5110
							// // #define		PGX_LCD_5110		PGX_DISABLE
						// // #endif
						// // //--------------------------------------------------
						// // #if ( PGIMX_LCD_5110 == PGX_ENABLE )
							// // #include "pgim_lcd_5110.h"
							
							// // #if defined( PGX_5110_VMEM_AMOUNT ) 
								// // #undef	PGX_5110_VMEM_AMOUNT
							// // #endif
							
							// // #define PGX_5110_VMEM_AMOUNT		504
							// // #if PGX_MAX_RAM > ( 2.5 * PGX_5110_VMEM_AMOUNT )
								// // #if	PGX_LCD_5110_VIDEO_MEMORY == PGX_YES
									// // _pgx_Ubuffer vbuff_5110[ PGX_5110_VMEM_AMOUNT ];
									// // #if defined( _GIM_H )
										// // #if ( PGX_VERBOSE == PGX_ENABLE )
											// // #warning	PicGIM: This amount of allocated RAM ( 504 Bytes ) may cause errors during linking. Use the correct file LKR equipped by PicGIM relating to the selected MCU.
										// // #endif
									// // #endif
								// // #else
									// // #if defined( _GIM_H )
										// // #if PGX_VERBOSE == PGX_ENABLE && PGX_SUGGESTION == PGX_ENABLE
											// // #warning	PicGIM: This MCU can use the VIDEO BUFFER. Keep on mind.
										// // #endif
									// // #endif
								// // #endif
							// // #else
								// // #if defined( _GIM_H )
									// // #if ( PGX_VERBOSE == PGX_ENABLE )
										// // #warning	PicGIM: Not enough RAM ( PGX_MAX_RAM Bytes ) to use VIDEO BUFFER
									// // #endif
								// // #endif
							// // #endif
							
							// // #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
								// // #warning	PGX >>> LCD 5110 module >>> Loaded
							// // #endif
						// // #endif
						// // //---[ END Lcd 5110 ]---
	//-------------------------------------------------------------------------------
	
	// //---[ Lcd 9340 ]---
// //	#if defined( PGX_DOXYGEN )
// //		#undef		PGX_LCD_9340
// //		#define		PGX_LCD_9340		PGX_ENABLE
// //	#elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
// //		#undef		PGX_LCD_9340
// //		#define		PGX_LCD_9340		PGX_DISABLE
// //	#endif
// //	//--------------------------------------------------
// //	#if ( PGIMX_LCD_9340 == PGX_ENABLE )
// //		#include "pgim_font.h"
// //		#include "pgim_lcd_9340.h"
// //		#if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
// //			#warning	PGX >>> LCD 9340 module >>> Loaded
// //			#if ( PGIMX_FONT == PGX_ENABLE )
// //				#warning	PGX >>> LCD 9340 module >>> Fonts enabled and loaded
// //			#endif
// //		#endif
// //	#endif
	//-------------------------------------------------------------------------------
	
	// //---[ Encoder ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_ENCODER
		// #define		PGX_ENCODER		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_ENCODER
		// #define		PGX_ENCODER		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_ENCODER == PGX_ENABLE )
		// #include "pgim_encoder.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> ENCODER module >>> Loaded
		// #endif
	//-------------------------------------------------------------------------------
	
	
	// //---[ Serial ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_SERIAL
		// #define		PGX_SERIAL		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_SERIAL
		// #define		PGX_SERIAL		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_SERIAL == PGX_ENABLE )
		// #include <usart.h>          //kmod
		// #include "pgim_serial.h"

		// //		B A U D R A T E   D E B U G   O U T P U T   T O   P I N
		// //( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		// #define PGX_SERIAL_DEBUG_TO_PIN				PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		// #define PGX_SERIAL_DEBUG_PIN					L_B3				//!< Output pin for debugging
		// #define PGX_SERIAL_DEBUG_PIN_TRIS				T_B3				//!< Debugging output pin tris

		// //		B A U D R A T E   D E B U G   O U T P U T   T O   B U Z Z E R
		// //( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		// #define PGX_SERIAL_DEBUG_TO_BUZZER				PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE

		// //		B A U D R A T E   D E B U G   O U T P U T   T O   L C D
		// //( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		// //#define PGX_SERIAL_DEBUG_TO_LCD_PCD8544		PGX_ENABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE. It is not yet supported.
		// #define PGX_SERIAL_DEBUG_TO_LCD_HD44780		PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE

		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> SERIAL module >>> Loaded
			// #if ( ( PGX_SUGGESTION == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE == PGX_AUTOMATIC ) )
				// #warning	PGX >>> SERIAL module >>> Activated AUTOMATIC mode configuration
			// #endif
			// #if ( ( PGX_SUGGESTION == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE == PGX_SEMI_AUTOMATIC ) )
				// #warning	PGX >>> SERIAL module >>> Activated SEMI-AUTOMATIC mode configuration
			// #endif
			// #if ( ( PGX_SUGGESTION == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE == PGX_MANUAL ) )
				// #warning	PGX >>> SERIAL module >>> Activated MANUAL mode configuration
			// #endif
			// #if ( ( PGX_SUGGESTION == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL ) )
				// #warning	PGX >>> SERIAL module >>> Trying to calculate parameter...
			// #endif			
			// #if ( PGX_SERIAL_DEBUG_TO_PIN == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL )
				// #warning	PGX >>> SERIAL module >>> Activated debug output to PIN
			// #endif
			// #if ( PGX_SERIAL_DEBUG_TO_LCD_PCD8544 == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL )
				// #warning	PGX >>> SERIAL module >>> Activated debug output to LCD-PCD8544
			// #endif
			// #if ( PGX_SERIAL_DEBUG_TO_LCD_HD44780 == PGX_ENABLE ) && ( PGX_SERIAL_BAUDRATE_MODE != PGX_MANUAL )
				// #warning	PGX >>> SERIAL module >>> Activated debug output to LCD-HD44780
			// #endif
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	// //---[ External Memory ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_EXTERNAL_MEMORY
		// #define		PGX_EXTERNAL_MEMORY		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_EXTERNAL_MEMORY
		// #define		PGX_EXTERNAL_MEMORY		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_EXTERNAL_MEMORY == PGX_ENABLE )
		// #include "pgim_external_memory.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> EXTERNAL MEMORY module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------

// //	//---[ Servo ]---
// //	#if defined( PGX_DOXYGEN )
// //		#undef		PGX_SERVO
// //		#define		PGX_SERVO			PGX_ENABLE
// //	#elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
// //		#undef		PGX_SERVO
// //		#define		PGX_SERVO			PGX_DISABLE
// //	#endif
// //	//--------------------------------------------------
// //	#if ( PGIMX_SERVO == PGX_ENABLE )
// //		#include "pgim_servo.h"
// //		#if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
// //			#warning	PGX >>> SERVO module >>> Loaded
// //		#endif
// //	#endif
	//-------------------------------------------------------------------------------

	// //---[ Ftoa Function]---
	// #if ( PGIMX_FTOA == PGX_ENABLE )
		// #include "pgim_ftoa.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> FTOA function >>> Included
		// #endif
	// #endif
	//-------------------------------------------------------------------------------

	// //---[ Sensor ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_SENSOR
		// #define		PGX_SENSOR		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_SENSOR
		// #define		PGX_SENSOR		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_SENSOR == PGX_ENABLE )
		// #include "pgim_sensor.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> SENSOR module >>> Loaded
			// #if ( ( PGX_SENSOR_ADC_REF == PGX_DISABLE ) && ( PGX_USER_SUPPLY_BATTERY	== PGX_YES ) )
				// #warning	PGX >>> SENSOR module >>> Hint >>> With the battery power supply (voltage non-constant) it is better to use the ADC-Ref module for the measurement of the true supply voltage.
			// #endif
			// // Parameter "PGX_SENSOR_ADC_REF_VOLT" value check
			// #if ( PGX_SENSOR_ADC_REF == PGX_ENABLE )
				// #if ( PGX_SENSOR_ADC_REF_VOLT > PGX_USER_SUPPLY_VOLT )
					// #warning	PGX >>> SENSOR module >>> Reference voltage value too big!
				// #endif
				// #if ( ( PGX_SENSOR_ADC_REF_VOLT < 0 ) || ( PGX_SENSOR_ADC_REF_VOLT == 0 ) )
					// #warning	PGX >>> SENSOR module >>> Reference voltage value negative or zero!
				// #endif
			// #endif
			// #if ( ( PGX_SENSOR_NTC_USE_ADCREF == PGX_YES ) && ( PGX_SENSOR_ADC_REF == PGX_DISABLE ) )
				// #warning	PGX >>> SENSOR module >>> ADC-Ref sensor must be enabled to be used with the NTC sensor!
			// #endif
			// #if ( ( PGX_SENSOR_NTC_USE_ADCREF == PGX_YES ) && ( PGX_SENSOR_ADC_REF == PGX_ENABLE ) )
				// #warning 	PGX >>> SENSOR module >>> Using ADC-Ref sensor to measure the power supply voltage for the NTC sensor.
			// #else
				// #warning 	PGX >>> SENSOR module >>> Using declared power supply voltage for the NTC sensor.
			// #endif
		// #endif
	// #endif
	// //---[ END Sensor ]---

	// //---[ RTC_DS1302 ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_RTC_DS1302
		// #define		PGX_RTC_DS1302		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_RTC_DS1302
		// #define		PGX_RTC_DS1302		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_RTC_DS1302 == PGX_ENABLE )
		// #include "pgim_rtc_ds1302.h"
		// // E R R O R   C H E C K   B E F O R E   L O A D   M O D U L E
		// #if ( ( PGX_RTC_DS1302_WR_TIME_ALL == PGX_INCLUDE ) || ( PGX_RTC_DS1302_RD_TIME_ALL == PGX_INCLUDE ) )
			// #if ( ( PGX_RTC_DS1302_USE_MIN == PGX_EXCLUDE ) || ( PGX_RTC_DS1302_USE_HOUR == PGX_EXCLUDE ) )
				// #error	PGX >>> RTC_DS1302 module >>> ERROR !!! >>> Incorrect pgim_selective_compiling_setup.h configuration file. Must be enabled minutes and hours, if you want to use *_ALL functions!
			// #endif
		// #endif
		// #if ( ( PGX_RTC_DS1302_WR_DATE_ALL == PGX_INCLUDE ) || ( PGX_RTC_DS1302_RD_DATE_ALL == PGX_INCLUDE ) )
			// #if ( ( PGX_RTC_DS1302_USE_DAY == PGX_EXCLUDE ) || ( PGX_RTC_DS1302_USE_MONTH == PGX_EXCLUDE ) || ( PGX_RTC_DS1302_USE_YEAR == PGX_EXCLUDE ) )
				// #error	PGX >>> RTC_DS1302 module >>> ERROR !!! >>> Incorrect pgim_selective_compiling_setup.h configuration file. Must be enabled day, month and year, if you want to use *_ALL functions!
			// #endif
		// #endif
		// //If all is OK...
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> RTC_DS1302 module >>> Loaded
		// #endif	
	// #endif
	//-------------------------------------------------------------------------------
	
	// //---[ 3Wire ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_3WIRE
		// #define		PGX_3WIRE		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_3WIRE
		// #define		PGX_3WIRE		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_3WIRE == PGX_ENABLE )
		// #include "pgim_3wire.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> 3WIRE module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	// //---[ GCP ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_GCP
		// #define		PGX_GCP		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_GCP
		// #define		PGX_GCP		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( ( ( ( PGX_GCP_BUFFER_RX_01_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_01_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_02_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_02_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_03_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_03_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_04_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_04_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_05_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_05_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_06_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_06_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_07_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_07_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_08_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_08_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_09_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_09_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_10_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_10_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_11_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_11_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_12_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_12_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_13_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_13_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_14_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_14_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_15_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_15_MODE	== PGX_GCP_STRING ) ) || \
			// ( ( PGX_GCP_BUFFER_RX_16_ENABLE == PGX_ENABLE	) && ( PGX_GCP_BUFFER_RX_16_MODE	== PGX_GCP_STRING ) ) ) && ( PGX_GCP_STATUS_MOD_ENABLE == PGX_DISABLE ) )
	  // #warning PGX >>> GCP module >>> Strings need STATUS_MOD enabled.
	// #endif
	// //If all is OK...
	// #if ( PGIMX_GCP == PGX_ENABLE ) 
		// #include "pgim_gcp.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> GCP module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	// //---[ SSP ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_SSP
		// #define		PGX_SSP		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_SSP
		// #define		PGX_SSP		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_SSP == PGX_ENABLE ) 
		// #include "pgim_ssp.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> SSP module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	// //---[ H32 ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_GKH32
		// #define		PGX_GKH32		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_GKH32
		// #define		PGX_GKH32		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_GKH32 == PGX_ENABLE ) 
		// #include "pgim_gkh32.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> GKH32 module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	// //---[ PRS ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_PRS
		// #define		PGX_PRS		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_PRS
		// #define		PGX_PRS		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_PRS == PGX_ENABLE ) 
		// #include "pgim_prs.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> PRS module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	// //---[ FONT ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_FONT
		// #define		PGX_FONT		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_FONT
		// #define		PGX_FONT		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_FONT == PGX_ENABLE )
		// #include "pgim_font.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> FONT module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------

	// //---[ AMG88XX ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_AMG88XX
		// #define		PGX_AMG88XX		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_AMG88XX
		// #define		PGX_AMG88XX		PGX_DISABLE
	// #endif
	// //--------------------------------------------------
	// #if ( PGIMX_AMG88XX == PGX_ENABLE )
		// #include "pgim_amg88xx.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> AMG88XX module >>> Loaded
		// #endif
	// #endif
	//-------------------------------------------------------------------------------
	
	// //---[ DDS AD9851 ]---
	// #if defined( PGX_DOXYGEN )
		// #undef		PGX_DDS_AD9851
		// #define		PGX_DDS_AD9851		PGX_ENABLE
	// #elif ( PGX_ALL_MODULES_DISABLED == PGX_ENABLE ) && ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #undef		PGX_DDS_AD9851
		// #define		PGX_DDS_AD9851		PGX_DISABLE
	// #endif
	// #if ( PGIMX_DDS_AD9851 == PGX_ENABLE )
		// #include "pgim_dds_ad9851.h"
		// #if defined( _GIM_H_ ) && ( PGX_VERBOSE == PGX_ENABLE )
			// #warning	PGX >>> DDS AD9851 module >>> Loaded
		// #endif
		// //PGX_MISSING cannot be compared by .bits
		// // #if ( PGX_DDS_AD9851_DATA_MODE	== PGX_PARALLEL )
			// // #if ( PGX_DDS_AD9851_DATABUS_TRIS == PGX_MISSING ) || ( PGX_DDS_AD9851_DATABUS == PGX_MISSING ) 
				// // #warning PGX >>> DDS AD9851 module >>> Wrong configuration in parallel mode.
			// // #endif
		// // #endif
		// // #if ( PGX_DDS_AD9851_DATA_MODE == PGX_SERIAL ) 
			// // #if ( PGX_DDS_AD9851_SERIAL_DATA_TRIS == PGX_MISSING )  ||  ( PGX_DDS_AD9851_SERIAL_DATA == PGX_MISSING )
				// // #warning PGX >>> DDS AD9851 module >>> Wrong configuration in serial mode.
			// // #endif
		// // #endif
	// #endif
	//-------------------------------------------------------------------------------

	// //------------------------------------------------------------------------------
	// //		E R R O R   M A N A G E M A N T
	// //------------------------------------------------------------------------------
	// #if defined( PGX_EXIT_ON_ERROR ) 
		// #error	PGX >>> ERROR !!! >>> Core >>> PicGIM has stopped compiling due to errors in configuration
	// #endif
	//-------------------------------------------------------------------------------
#endif /* _PGIMX_INCLUDES_H_ */


