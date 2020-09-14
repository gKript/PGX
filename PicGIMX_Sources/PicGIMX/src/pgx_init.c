//
#include "pgx.h"

#if ( PGX_PROJECT_STATE == PGX_DEBUG )
	#warning	PGX >>> Message >>> This file is always compiled.
#endif

//---[ PGX Init ]---
void pgx_initialize( void ) {
	//------------------------------------------------------------------------
	#if ( PGX_POWER_GOOD_DELAY > 0 )
        _pgx_Uint16 t_pg_power_good_delay;
		t_pg_power_good_delay = PGX_POWER_GOOD_DELAY;
                
        pgx_delay_msec( t_pg_power_good_delay );
	#endif
	//------------------------------------------------------------------------
	// #if ( PGX_BOARD == PGX_BOARD_A )
		// pgx_board_a_init();
	// #endif
	
	// #if ( PGX_USE_INTERNAL_OSC == PGX_ENABLE )
		// pgx_internal_osc_init( );
	// #endif

	//ADCON1 = 0x0f;

	 #if ( PGIMX_TIMER == PGX_ENABLE )
		 pgx_timer_init( );
	 #endif

	// #if ( PGX_EVENTS == PGX_ENABLE )
		// pgx_event_init( );
	// #endif

	// #if ( PGX_CAL_DELAY == PGX_ENABLE ) && defined( __18CXX )
		// pgx_delay_NinstusCalc( );
	// #endif

	// #if ( PGX_I2C == PGX_ENABLE )
		// pgx_i2c_init( );
	// #endif
	
	// #if ( PGX_PWM == PGX_ENABLE )
		// pgx_pwm_init( );
	// #endif

	// #if ( PGX_AD_CONVERTER == PGX_ENABLE )
		// pgx_adc_init( );
	// #endif

	// #if ( PGX_EE == PGX_ENABLE )
		// pgx_ee_init( );
	// #endif

	// #if ( PGX_ENCODER == PGX_ENABLE )
		// pgx_encoder_init( );
	// #endif

	#if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
		pgx_lcd_hd44780_init( );
        pgx_lcd_hd44780_print_speed( 0 );
	#endif

	// #if ( PGX_LCD_PCD8544 == PGX_ENABLE )
		// pgx_lcd_pcd8544_init( );
    // #endif

	// #if ( PGX_SERIAL == PGX_ENABLE )			//To init after lcd-pcd8544 and lcd-char
		// pgx_serial_init();
	// #endif
	
	// #if ( PGX_EXTERNAL_MEMORY == PGX_ENABLE )
		// pgx_delay( 10 , PGX_MSEC );				// Delay to wait memory becomes ready; no chip-select allowed
		// pgx_external_memory_init( );
	// #endif
	
	// #if ( PGX_3WIRE == PGX_ENABLE )
		// pgx_3wire_init( );
	// #endif

	// #if ( PGX_RTC_DS1302 == PGX_ENABLE )
		// pgx_rtc_ds1302_init( );
	// #endif
	
	// #if ( PGX_AMG88XX == PGX_ENABLE )
		// pgx_amg88xx_init( );
	// #endif
	
	// #if ( PGX_DDS_AD9851 == PGX_ENABLE )
		// pgx_dds_ad9851_init( );
	// #endif

	// #if ( PGX_SSP == PGX_ENABLE )
		// pgx_ssp_init( );
	// #endif
	//------------------------------------------------------------------------
}
//---[ END PGX Init ]---


