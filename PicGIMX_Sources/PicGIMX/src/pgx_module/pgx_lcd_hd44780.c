//
#include "pgx.h"

#if ( PGX_PROJECT_STATE == PGX_DEBUG )
    #warning PGX >>> Message >>> This file is compiling...
#endif

#if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
	
    //#if ( )
        //global variable
        _pgx_Uint16 pgx_lcd_hd780_print_speed_ms;
    //#endif
    
    //---[ HD44780 Print Delay ]---
    //#if ( )
	void pgx_lcd_hd44780_print_speed( _pgx_Uint16 PrintSpeed) {
        //--------------------------------------------------------------------
        //Implemented only in put char function...
        pgx_lcd_hd780_print_speed_ms = PrintSpeed;
    }
    //#endif
    //---[ END HD44780 Print Delay ]---
        
    //---[ HD44780 Init ]---
	void pgx_lcd_hd44780_init( void ) {
        //--------------------------------------------------------------------
		//Backlight turn-off and tris
		#if ( PGX_LCD_HD44780_BL_0_PRESENT == PGX_YES )
			#if ( PGX_LCD_HD44780_BL_0_ENABLE_LOGIC == PGX_POSITIVE )
				PGX_LCD_HD44780_BL_0 = PGX_LOW;	//Active High
			#endif
			#if ( PGX_LCD_HD44780_BL_0_ENABLE_LOGIC == PGX_NEGATIVE )
				PGX_LCD_HD44780_BL_0 = PGX_HIGH;	//Active Low
			#endif
			PGX_LCD_HD44780_BL_0_TRIS = PGX_OUT;
		#endif
		#if ( PGX_LCD_HD44780_BL_1_PRESENT == PGX_YES )
			#if ( PGX_LCD_HD44780_BL_1_ENABLE_LOGIC == PGX_POSITIVE )
				PGX_LCD_HD44780_BL_1 = PGX_LOW;	//Active High
			#endif
			#if ( PGX_LCD_HD44780_BL_1_ENABLE_LOGIC == PGX_NEGATIVE )
				PGX_LCD_HD44780_BL_1 = PGX_HIGH;	//Active Low
			#endif
			PGX_LCD_HD44780_BL_1_TRIS = PGX_OUT;
		#endif
		#if ( PGX_LCD_HD44780_BL_2_PRESENT == PGX_YES )
			#if ( PGX_LCD_HD44780_BL_2_ENABLE_LOGIC == PGX_POSITIVE )
				PGX_LCD_HD44780_BL_2 = PGX_LOW;	//Active High
			#endif
			#if ( PGX_LCD_HD44780_BL_2_ENABLE_LOGIC == PGX_NEGATIVE )
				PGX_LCD_HD44780_BL_2 = PGX_HIGH;	//Active Low
			#endif
			PGX_LCD_HD44780_BL_2_TRIS = PGX_OUT;
		#endif
		#if ( PGX_LCD_HD44780_BL_3_PRESENT == PGX_YES )
			#if ( PGX_LCD_HD44780_BL_3_ENABLE_LOGIC == PGX_POSITIVE )
				PGX_LCD_HD44780_BL_3 = PGX_LOW;	//Active High
			#endif
			#if ( PGX_LCD_HD44780_BL_3_ENABLE_LOGIC == PGX_NEGATIVE )
				PGX_LCD_HD44780_BL_3 = PGX_HIGH;	//Active Low
			#endif
			PGX_LCD_HD44780_BL_3_TRIS = PGX_OUT;
		#endif

		//Lcd control tris
		#if ( PGX_LCD_HD44780_EN_0_PRESENT == PGX_YES )
			PGX_LCD_HD44780_EN_0 = PGX_DISABLE;
			PGX_LCD_HD44780_EN_0_TRIS = PGX_OUT;
		#endif
		#if ( PGX_LCD_HD44780_EN_1_PRESENT == PGX_YES )
			PGX_LCD_HD44780_EN_1 = PGX_DISABLE;
			PGX_LCD_HD44780_EN_1_TRIS = PGX_OUT;
		#endif
		#if ( PGX_LCD_HD44780_EN_2_PRESENT == PGX_YES )
			PGX_LCD_HD44780_EN_2 = PGX_DISABLE;
			PGX_LCD_HD44780_EN_2_TRIS = PGX_OUT;
		#endif
		#if ( PGX_LCD_HD44780_EN_3_PRESENT == PGX_YES )
			PGX_LCD_HD44780_EN_3 = PGX_DISABLE;
			PGX_LCD_HD44780_EN_3_TRIS = PGX_OUT;
		#endif
		#if ( PGX_LCD_HD44780_RW_PRESENT == PGX_YES )
			PGX_LCD_HD44780_RW = PGX_LOW;
			PGX_LCD_HD44780_RW_TRIS = PGX_OUT;
		#endif
		PGX_LCD_HD44780_RS_TRIS  = PGX_OUT;
		PGX_LCD_HD44780_DATA_0_TRIS  = PGX_OUT;
		PGX_LCD_HD44780_DATA_1_TRIS  = PGX_OUT;
		PGX_LCD_HD44780_DATA_2_TRIS  = PGX_OUT;
		PGX_LCD_HD44780_DATA_3_TRIS  = PGX_OUT;
		
		//Initialize controllers
		#if ( PGX_LCD_HD44780_EN_0_PRESENT == PGX_YES )
			pgx_lcd_hd44780_init_routine( PGX_CONTROLLER_0 );
		#endif
		#if ( PGX_LCD_HD44780_EN_1_PRESENT == PGX_YES )
			pgx_lcd_hd44780_init_routine( PGX_CONTROLLER_1 );
		#endif
		#if ( PGX_LCD_HD44780_EN_2_PRESENT == PGX_YES )
			pgx_lcd_hd44780_init_routine( PGX_CONTROLLER_2 );
		#endif
		#if ( PGX_LCD_HD44780_EN_3_PRESENT == PGX_YES )
			pgx_lcd_hd44780_init_routine( PGX_CONTROLLER_3 );
		#endif
		
		//Backlight turn-on
		#if ( ( PGX_LCD_HD44780_BL_0_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_BL_0_ENABLE == PGX_ENABLE ) )
			#if ( PGX_LCD_HD44780_BL_0_ENABLE_LOGIC == PGX_POSITIVE )
				PGX_LCD_HD44780_BL_0 = PGX_HIGH;	//Active High
			#endif
			#if ( PGX_LCD_HD44780_BL_0_ENABLE_LOGIC == PGX_NEGATIVE )
				PGX_LCD_HD44780_BL_0 = PGX_LOW;	//Active Low
			#endif
		#endif
		#if ( ( PGX_LCD_HD44780_BL_1_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_BL_1_ENABLE == PGX_ENABLE ) )
			#if ( PGX_LCD_HD44780_BL_1_ENABLE_LOGIC == PGX_POSITIVE )
				PGX_LCD_HD44780_BL_1 = PGX_HIGH;	//Active High
			#endif
			#if ( PGX_LCD_HD44780_BL_1_ENABLE_LOGIC == PGX_NEGATIVE )
				PGX_LCD_HD44780_BL_1 = PGX_LOW;	//Active Low
			#endif
		#endif
		#if ( ( PGX_LCD_HD44780_BL_2_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_BL_2_ENABLE == PGX_ENABLE ) )
			#if ( PGX_LCD_HD44780_BL_2_ENABLE_LOGIC == PGX_POSITIVE )
				PGX_LCD_HD44780_BL_2 = PGX_HIGH;	//Active High
			#endif
			#if ( PGX_LCD_HD44780_BL_2_ENABLE_LOGIC == PGX_NEGATIVE )
				PGX_LCD_HD44780_BL_2 = PGX_LOW;	//Active Low
			#endif
		#endif
		#if ( ( PGX_LCD_HD44780_BL_3_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_BL_3_ENABLE == PGX_ENABLE ) )
			#if ( PGX_LCD_HD44780_BL_3_ENABLE_LOGIC == PGX_POSITIVE )
				PGX_LCD_HD44780_BL_3 = PGX_HIGH;	//Active High
			#endif
			#if ( PGX_LCD_HD44780_BL_3_ENABLE_LOGIC == PGX_NEGATIVE )
				PGX_LCD_HD44780_BL_3 = PGX_LOW;	//Active Low
			#endif
		#endif
		
		 //Splash screen FULL
		 #if ( ( PGX_LCD_HD44780_EN_0_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_SPLASH_FULL_0_EN ) )
			 pgx_lcd_hd44780_splash_full( PGX_CONTROLLER_0 );
		 #endif
		 #if ( ( PGX_LCD_HD44780_EN_1_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_SPLASH_FULL_1_EN ) )
			 pgx_lcd_hd44780_splash_full( PGX_CONTROLLER_1 );
		 #endif
		 #if ( ( PGX_LCD_HD44780_EN_2_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_SPLASH_FULL_2_EN ) )
			 pgx_lcd_hd44780_splash_full( PGX_CONTROLLER_2 );
		 #endif
		 #if ( ( PGX_LCD_HD44780_EN_3_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_SPLASH_FULL_3_EN ) )
			 pgx_lcd_hd44780_splash_full( PGX_CONTROLLER_3 );
		 #endif
		
		 //Splash screen SLIDE
		 #if ( ( PGX_LCD_HD44780_EN_0_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_SPLASH_SLIDE_0_EN ) )
			 pgx_lcd_hd44780_splash_slide( PGX_CONTROLLER_0 );
		 #endif
		 #if ( ( PGX_LCD_HD44780_EN_1_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_SPLASH_SLIDE_1_EN ) )
			 pgx_lcd_hd44780_splash_slide( PGX_CONTROLLER_1 );
		 #endif
		 #if ( ( PGX_LCD_HD44780_EN_2_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_SPLASH_SLIDE_2_EN ) )
			 pgx_lcd_hd44780_splash_slide( PGX_CONTROLLER_2 );
		 #endif
		 #if ( ( PGX_LCD_HD44780_EN_3_PRESENT == PGX_YES ) && ( PGX_LCD_HD44780_SPLASH_SLIDE_3_EN ) )
			 pgx_lcd_hd44780_splash_slide( PGX_CONTROLLER_3 );
		 #endif
	}
    //---[ END HD44780 Init ]---

	//---[ HD44780 Init Routine ]---
    void pgx_lcd_hd44780_init_routine( _pgx_int8 Controller ) {
        //--------------------------------------------------------------------
        pgx_delay_msec( 200 );
		PGX_LCD_HD44780_RS = PGX_COMMAND;
		if( PGX_LCD_HD44780_RW_PRESENT )
			PGX_LCD_HD44780_RW = PGX_WRITE;
		pgx_lcd_hd44780_en_select( Controller , PGX_DISABLE );
//		pgx_lcd_hd44780_en_select( Controller , PGX_ENABLE );
		pgx_delay_msec( 1 );
		
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000011 );
		pgx_delay_msec( 50 );
		
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000011 );
		pgx_delay_msec( 1 );
		
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000011 );
		pgx_delay_msec( 1 );
		
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000010 );
		pgx_delay_msec( 1 );
		
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000010 );
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00001000 );
		pgx_delay_msec( 1 );
		
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000000 );
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00001000 );
		pgx_delay_msec( 1 );
		
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000000 );
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000001 );
		pgx_delay_msec( 20 );
		
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000000 );
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000110 );
		pgx_delay_msec( 1 );

		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00000000 );
		pgx_ldc_hd44780_write_nibble( Controller , PGX_COMMAND , 0b00001100 );	//pgx_ldc_hd44780_write_nibble( PGX_TRUE , 0b00001101 );cursor blink
		pgx_delay_msec( 1 );
		
		pgx_lcd_hd44780_clear( Controller );
		pgx_delay_msec( 10 );
		//pgx_lcd_hd44780_goto( Controller , 0 , 0 );
		pgx_delay_msec( 10 );
	}
	//---[ END HD44780 Init Routine ]---
	
    //---[ HD44780 Splash Full ]---
	 #if ( ( PGX_LCD_HD44780_SPLASH_FULL_0_EN == PGX_ENABLE ) || \
		 ( PGX_LCD_HD44780_SPLASH_FULL_1_EN == PGX_ENABLE ) || \
		 ( PGX_LCD_HD44780_SPLASH_FULL_2_EN == PGX_ENABLE ) || \
		 ( PGX_LCD_HD44780_SPLASH_FULL_3_EN == PGX_ENABLE ) )
		 void	pgx_lcd_hd44780_splash_full( _pgx_int8 Controller ) {
            //--------------------------------------------------------------------
			_pgx_Uint8 c, r;
			for( r = 0  ; r < PGX_LCD_HD44780_LINES ; r++ ) {
				for( c = 0  ; c < PGX_LCD_HD44780_COLUMNS ; c++ ) {
					pgx_lcd_hd44780_write_p_char( Controller , r , c , "%c" , 0xff );
				}
			}
			#if ( PGX_LCD_HD44780_SPLASH_FULL_DELAY != 0 )
				pgx_delay_sec( PGX_LCD_HD44780_SPLASH_FULL_DELAY );
				pgx_lcd_hd44780_clear( Controller );
				pgx_lcd_hd44780_goto( Controller , 0 , 0 );
			#endif
			pgx_delay_msec( 500 );
		}		
	#endif
    //---[ END HD44780 Splash Full ]---
	
    //---[ HD44780 Splash Slide ]---
	#if ( ( PGX_LCD_HD44780_SPLASH_SLIDE_0_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_SLIDE_1_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_SLIDE_2_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_SLIDE_3_EN == PGX_ENABLE ) )
		void	pgx_lcd_hd44780_splash_slide( _pgx_int8 Controller ) {
            //--------------------------------------------------------------------
			_pgx_Uint8 c, r;
			for( r = 0 ; r < PGX_LCD_HD44780_LINES ; r++ ) {
				for( c = 0 ; c < PGX_LCD_HD44780_COLUMNS ; c++ ) {
					pgx_lcd_hd44780_write_p_char( Controller , r , c , "%c" , 0xff );
					pgx_delay_msec( PGX_LCD_HD44780_SPLASH_SLIDE_SPEED );	//100
					if( c >= 1 )
						pgx_lcd_hd44780_write_p_char( Controller , r , c - 1 , "%c" , 0x20 );
				}
				pgx_lcd_hd44780_write_p_char( Controller , r , c , "%c" , 0x20 );
			}
			pgx_lcd_hd44780_clear( Controller );
			pgx_lcd_hd44780_goto( Controller , 0 , 0 );
			pgx_delay_msec( 500 );
		}
	#endif
    //---[ END HD44780 Splash Slide ]---
	
    //---[ HD44780 Busy Flag ]---
	#if ( PGX_LCD_HD44780_BUSY_FLAG == PGX_ENABLE )
		_pgx_Uint8 pgx_lcd_hd44780_read_byte( _pgx_int8 Controller ) {
            //--------------------------------------------------------------------
			_pgx_Uint8 	Dat;
			
			PGX_LCD_HD44780_DATA_0_TRIS  = PGX_IN;
			PGX_LCD_HD44780_DATA_1_TRIS  = PGX_IN;
			PGX_LCD_HD44780_DATA_2_TRIS  = PGX_IN;
			PGX_LCD_HD44780_DATA_3_TRIS  = PGX_IN;
			
			pgx_lcd_hd44780_en_select( Controller , PGX_ENABLE );
			pgx_delay_usec( 5 );
			
			Dat = 0x00;
			if( PGX_LCD_HD44780_DATA_3_PORT )	Dat |= 0x80;
			if( PGX_LCD_HD44780_DATA_2_PORT )	Dat |= 0x40;
			if( PGX_LCD_HD44780_DATA_1_PORT )	Dat |= 0x20;
			if( PGX_LCD_HD44780_DATA_0_PORT )	Dat |= 0x10;
			
			pgx_lcd_hd44780_en_select( Controller , PGX_DISABLE );
			pgx_delay_usec( 5 );
			
			pgx_lcd_hd44780_en_select( Controller , PGX_ENABLE );
			pgx_delay_usec( 5 );
			
			if( PGX_LCD_HD44780_DATA_3_PORT )	Dat |= 0x08;
			if( PGX_LCD_HD44780_DATA_2_PORT )	Dat |= 0x04;
			if( PGX_LCD_HD44780_DATA_1_PORT )	Dat |= 0x02;
			if( PGX_LCD_HD44780_DATA_0_PORT )	Dat |= 0x01;
			
			pgx_lcd_hd44780_en_select( Controller , PGX_DISABLE );
			pgx_delay_usec( 5  );

			PGX_LCD_HD44780_DATA_0_TRIS  = PGX_OUT;
			PGX_LCD_HD44780_DATA_1_TRIS  = PGX_OUT;
			PGX_LCD_HD44780_DATA_2_TRIS  = PGX_OUT;
			PGX_LCD_HD44780_DATA_3_TRIS  = PGX_OUT;
			
			return Dat;
		}
	#endif 
    //---[ END HD44780 Busy Flag ]---

    //---[ HD44780 Wait Busy ]---
	void pgx_lcd_hd44780_wait_busy( _pgx_int8 Controller ) {
        //--------------------------------------------------------------------
		#if ( PGX_LCD_HD44780_BUSY_FLAG == PGX_ENABLE )
			_pgx_Uint8 Status;
			PGX_LCD_HD44780_RS = PGX_COMMAND;
			if( PGX_LCD_HD44780_RW_PRESENT )
				PGX_LCD_HD44780_RW = PGX_READ;
			do {
				Status = pgx_lcd_hd44780_read_byte( Controller );
			} while( Status & 0x80 );
			if( PGX_LCD_HD44780_RW_PRESENT )
				PGX_LCD_HD44780_RW = PGX_WRITE;
		#else
			pgx_delay_usec( PGX_LCD_HD44780_BUSY_DELAY );
		#endif
	}
    //---[ END HD44780 Wait Busy ]---

    //---[ HD44780 Write Nibble ]---
	void pgx_ldc_hd44780_write_nibble( _pgx_int8 Controller , _pgx_Uint8 DataType , _pgx_Uint8 Dat ) {
        //--------------------------------------------------------------------
        // es.: pgx_ldc_hd44780_write_nibble( PGX_CONTROLLER_0 , PGX_COMMAND , 0x01 );

        //	if( ( Controller < 0 ) || ( Controller > 4 ) || ( Controller == PGX_MISSING ) )
        //		return;	//gestire errore
			
		PGX_LCD_HD44780_RS = DataType;
		if( PGX_LCD_HD44780_RW_PRESENT )
			PGX_LCD_HD44780_RW = PGX_WRITE;
		pgx_lcd_hd44780_en_select( Controller , PGX_ENABLE );
		pgx_delay_msec( 1 );
		
		PGX_LCD_HD44780_DATA_0 = PGX_LCD_HD44780_DATA_1 = PGX_LCD_HD44780_DATA_2 = PGX_LCD_HD44780_DATA_3 = PGX_CLEAR;
		
		Dat &= 0x0F;	//superfluo?
		if( Dat & 0x08 )	PGX_LCD_HD44780_DATA_3 = 1;
		if( Dat & 0x04 )	PGX_LCD_HD44780_DATA_2 = 1;
		if( Dat & 0x02 )	PGX_LCD_HD44780_DATA_1 = 1;
		if( Dat & 0x01 )	PGX_LCD_HD44780_DATA_0 = 1;
		
		pgx_lcd_hd44780_en_select( Controller , PGX_DISABLE );
		pgx_delay_msec( 1 );
	}
    //---[ END HD44780 Write Nibble ]---

    //---[ HD44780 Write byte ]---
	void pgx_lcd_hd44780_write_byte( _pgx_int8 Controller , _pgx_Uint8 DataType , _pgx_Uint8 Dat ) {
        //--------------------------------------------------------------------
		pgx_ldc_hd44780_write_nibble( Controller , DataType , Dat >> 4 );
		pgx_ldc_hd44780_write_nibble( Controller , DataType , Dat );
	}
    //---[ END HD44780 Write Byte ]---

    //---[ HD44780 Enable Select ]---
	void pgx_lcd_hd44780_en_select( _pgx_int8 Controller , _pgx_Uint8 EnState ) {
        //--------------------------------------------------------------------
		//	es.: pgx_lcd_hd44780_en_select( PGX_CONTROLLER_0 , PGX_ENABLE );
		#if ( PGX_LCD_HD44780_EN_0_PRESENT == PGX_YES )
			if( Controller == PGX_CONTROLLER_0 )
				PGX_LCD_HD44780_EN_0 = EnState;
		#endif
		#if ( PGX_LCD_HD44780_EN_1_PRESENT == PGX_YES )
			if( Controller == PGX_CONTROLLER_1 )
				PGX_LCD_HD44780_EN_1 = EnState;
		#endif
		#if ( PGX_LCD_HD44780_EN_2_PRESENT == PGX_YES )
			if( Controller == PGX_CONTROLLER_2 )
				PGX_LCD_HD44780_EN_2 = EnState;
		#endif
		#if ( PGX_LCD_HD44780_EN_3_PRESENT == PGX_YES )
			if( Controller == PGX_CONTROLLER_3 )
				PGX_LCD_HD44780_EN_3 = EnState;
		#endif
	}
    //---[ END HD44780 Enable Select ]---
    
    //---[ HD44780 Clear ]---
	void pgx_lcd_hd44780_clear( _pgx_int8 Controller ) {
        //--------------------------------------------------------------------
		pgx_lcd_hd44780_write_byte( Controller , PGX_COMMAND , 0x01 );
		pgx_delay_msec( 100 );
		pgx_lcd_hd44780_wait_busy( Controller );
	}
    //---[ END HD44780 Clear ]---

    //---[ HD44780 Goto ]---
	void pgx_lcd_hd44780_goto( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos ) {
        //--------------------------------------------------------------------
		//	es.: pgx_lcd_hd44780_goto( PGX_CONTROLLER_0 , PGX_LINE_0 , 0 )
		
		if( ( Ln > ( PGX_LCD_HD44780_LINES - 1 ) ) || ( Pos > ( PGX_LCD_HD44780_COLUMNS - 1 ) ) )
			return;	//gestire errore 
			
		//pgx_lcd_hd44780_write_byte( GtController , PGX_COMMAND , ( Ln == 1 ) ? ( 0xC0 | Pos ) : ( 0x80 | Pos ) );
		
		if( ( ( Ln == PGX_LINE_0 ) && ( PGX_LCD_HD44780_LINE_0_ADDRESS == PGX_MISSING ) ) ||
			( ( Ln == PGX_LINE_1 ) && ( PGX_LCD_HD44780_LINE_1_ADDRESS == PGX_MISSING ) ) ||
			( ( Ln == PGX_LINE_2 ) && ( PGX_LCD_HD44780_LINE_2_ADDRESS == PGX_MISSING ) ) ||
			( ( Ln == PGX_LINE_3 ) && ( PGX_LCD_HD44780_LINE_3_ADDRESS == PGX_MISSING ) ) )
			return;	//gestire errore
		
		if( Ln == PGX_LINE_0 )
			pgx_lcd_hd44780_write_byte( Controller , PGX_COMMAND , ( 0x80 | ( (_pgx_Uint8)PGX_LCD_HD44780_LINE_0_ADDRESS + Pos ) ) );
		if( Ln == PGX_LINE_1 )
			pgx_lcd_hd44780_write_byte( Controller , PGX_COMMAND , ( 0x80 | ( (_pgx_Uint8)PGX_LCD_HD44780_LINE_1_ADDRESS + Pos ) ) );
		if( Ln == PGX_LINE_2 )
			pgx_lcd_hd44780_write_byte( Controller , PGX_COMMAND , ( 0x80 | ( (_pgx_Uint8)PGX_LCD_HD44780_LINE_2_ADDRESS + Pos ) ) );
		if( Ln == PGX_LINE_3 )
			pgx_lcd_hd44780_write_byte( Controller , PGX_COMMAND , ( 0x80 | ( (_pgx_Uint8)PGX_LCD_HD44780_LINE_3_ADDRESS + Pos ) ) );
			
		pgx_lcd_hd44780_wait_busy( Controller );

		//		LCD 4x16 ( Model: WH1604A )
		//		
		//			 0  1  2 ... 15
		//	-----------------------
		//	0		00 01 02 ... 0F
		//	1		40 41 42 ... 4F
		//	2		10 11 12 ... 1F
		//	3		50 51 52 ... 5F
	}
    //---[ END HD44780 Goto ]---
    
    //---[ HD44780 Goto ]---
		#if ( PGX_LCD_HD44780_CHAR_GENERATOR == PGX_INCLUDE )
		void pgx_lcd_hd44780_char_generator( _pgx_int8 Controller ,char location , char * new_char ) {
            //--------------------------------------------------------------------
			//	Location 0,1,2,...7
			//	pattern[8]={0x06,0x09,0x09,0x06,0x00,0x00,0x00,0x00};
			//	pgx_lcd_hd44780_char_generator( 0 , pattern );
			char i;
			pgx_lcd_hd44780_write_byte( Controller , PGX_COMMAND , 0x40 + ( location * 8 ) );
			for( i = 0 ; i < 8 ; i++ )
				pgx_lcd_hd44780_write_byte( Controller , PGX_DATA , new_char[i] );
		}
	#endif
    //---[ END HD44780 Goto ]---
	
	//---[ HD44780 Eeprom ]---
	#if ( PGX_EE == PGX_ENABLE )
		void pgx_lcd_hd44780_char_generator_from_EE( _pgx_int8 Controller ,char location , _pgx_Uint16 ee_addy ) {
            //--------------------------------------------------------------------
			char i;
			pgx_lcd_hd44780_write_byte( Controller , PGX_COMMAND , 0x40 + ( location * 8 ) );
			for( i = 0 ; i < 8 ; i++ )
				pgx_lcd_hd44780_write_byte( Controller , PGX_DATA , pgx_ee_read( ee_addy + i ) );
		}
	#endif
	//---[ END HD44780 Eeprom ]---

	//---[ HD44780 Put Char ]---
	void pgx_lcd_hd44780_put_char( _pgx_int8 Controller , _pgx_Uint8 Data ) {
        //--------------------------------------------------------------------
		pgx_lcd_hd44780_write_byte( Controller , PGX_DATA , Data );
		if( pgx_lcd_hd780_print_speed_ms ) {
            pgx_delay_msec( pgx_lcd_hd780_print_speed_ms );
        }
        pgx_lcd_hd44780_wait_busy( Controller );
	}
    //---[ END HD44780 Put Char ]---
	
    //---[ HD44780 Put Position Char ]---
	#if ( PGX_LCD_HD44780_PUT_P_CHAR == PGX_INCLUDE )
		void pgx_lcd_hd44780_put_p_char( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_Uint8 Data ) {
            //--------------------------------------------------------------------
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
			pgx_lcd_hd44780_write_byte( Controller , PGX_DATA , Data );
			pgx_lcd_hd44780_wait_busy( Controller );
		}
	#endif
    //---[ ENDHD44780 Put Position Char ]---
	
    //---[ HD44780 Put Byte ]---
	#if ( PGX_LCD_HD44780_PUT_BYTE == PGX_INCLUDE )
		void pgx_lcd_hd44780_put_byte( _pgx_int8 Controller , _pgx_Uint8 Val ) {
            //--------------------------------------------------------------------
			pgx_lcd_hd44780_put_char( Controller , Val / 10 + '0' );
			pgx_lcd_hd44780_put_char( Controller , Val % 10 + '0' );
		}
	#endif
    //---[ END HD44780 Put Byte ]---
	
	//---[ HD44780 Put Position Byte ]---
	#if ( PGX_LCD_HD44780_PUT_P_BYTE == PGX_INCLUDE )
		void pgx_lcd_hd44780_put_p_byte( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_Uint8 Val ) {
            //--------------------------------------------------------------------
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
			pgx_lcd_hd44780_put_char( Controller , Val / 10 + '0' );
			pgx_lcd_hd44780_put_char( Controller , Val % 10 + '0' );
		}
	#endif
	//---[ HD44780 Put Position Byte ]---

	//---[ HD44780 Write String ]---
	void pgx_lcd_hd44780_write_string( _pgx_int8 Controller , _pgx_int8  *Str ) {
        //--------------------------------------------------------------------
		_pgx_Uint8 i = 0;
		while( Str[i] )
			pgx_lcd_hd44780_put_char( Controller , Str[i++] );
	}
	//---[ END HD44780 Write String ]---

	//---[ HD44780 Write String Rom ]---
	#if ( PGX_LCD_HD44780_WRITE_STRING_ROM == PGX_INCLUDE )
		//void pgx_lcd_hd44780_write_string_rom( _pgx_int8 Controller , const rom _pgx_int8  *Str ) {
		void pgx_lcd_hd44780_write_string_rom( _pgx_int8 Controller , const _pgx_int8  *Str ) {
            //--------------------------------------------------------------------
			_pgx_Uint8 i = 0;
			while( Str[ i ] )
				pgx_lcd_hd44780_put_char( Controller , Str[ i++ ] );
		}
	#endif
	//---[ END HD44780 Write String Rom ]---
	
	//---[ HD44780 Write Position String ]---
	 #if ( PGX_LCD_HD44780_WRITE_P_STRING == PGX_INCLUDE 	)
		void pgx_lcd_hd44780_write_p_string( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_int8  *Str ) {
            //--------------------------------------------------------------------
			_pgx_Uint8 i = 0;
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
				while( Str[i] )
				pgx_lcd_hd44780_put_char( Controller , Str[i++] );
		}
	#endif
	//---[ END HD44780 Write Position String ]---
	
	//---[ HD44780 Write Position String Flash ]---
	#if ( PGX_LCD_HD44780_WRITE_P_STRING_FLASH == PGX_INCLUDE )
		void pgx_lcd_hd44780_write_p_string_flash( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_int8  *Str , _pgx_Uint8 time , _pgx_Uint8 unit ) {
            //--------------------------------------------------------------------
			_pgx_Uint8 i = 0;
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
			while( Str[i] )
				pgx_lcd_hd44780_put_char( Controller , Str[i++] );
			pgx_delay( time , unit );
			i = 0;
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
			while( Str[i++] )
				pgx_lcd_hd44780_put_char( Controller , ' ' );
		}
	#endif
	//---[ END HD44780 Write Position String Flash ]---

	//---[ HD44780 Write Position String Rom ]---
	#if ( PGX_LCD_HD44780_WRITE_P_STRING_ROM == PGX_INCLUDE )
		//void pgx_lcd_hd44780_write_p_string_rom( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8  *Str ) {
		void pgx_lcd_hd44780_write_p_string_rom( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8  *Str ) {
            //--------------------------------------------------------------------
			_pgx_Uint8 i = 0;
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
			while( Str[ i ] ) {
				pgx_lcd_hd44780_put_char( Controller , Str[ i++ ] );
            }
		}
	#endif
	//---[ END HD44780 Write Position String Rom ]---
	
	//---[ HD44780 Write Position Flash Rom ]---
	#if ( PGX_LCD_HD44780_WRITE_P_STRING_FLASH_ROM == PGX_INCLUDE )
		//void pgx_lcd_hd44780_write_p_string_flash_rom( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8  *Str , _pgx_Uint8 time , _pgx_Uint8 unit ) {
		void pgx_lcd_hd44780_write_p_string_flash_rom( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8  *Str , _pgx_Uint8 time , _pgx_Uint8 unit ) {
            //--------------------------------------------------------------------
			_pgx_Uint8 i = 0;
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
			while( Str[ i ] )
                pgx_lcd_hd44780_put_char( Controller , Str[ i++ ] );
			
			pgx_delay( time , unit );
			i = 0;
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
			while( Str[ i++ ] )
				pgx_lcd_hd44780_put_char( Controller , ' ' );
		}
	#endif
	//---[ END HD44780 Write Position Flash Rom ]---
	
	//---[ HD44780 Write Position Integer ]---
	#if ( PGX_LCD_HD44780_WRITE_P_INT == PGX_INCLUDE )
		//void	pgx_lcd_hd44780_write_p_int( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8  *Format , _pgx_int16 Val ) {
		void	pgx_lcd_hd44780_write_p_int( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8  *Format , _pgx_int16 Val ) {
            //--------------------------------------------------------------------
			_pgx_int8 Str[ PGX_LCD_HD44780_COLUMNS ];
			pgx_lcd_hd44780_goto( Controller ,Ln , Pos );
			sprintf( Str , Format , Val );
			pgx_lcd_hd44780_write_string( Controller , Str );
		}	
	#endif
	//---[ END HD44780 Write Position Integer ]---
	
	//---[ HD44780 Write Position Float ]---
	#if ( PGX_FTOA	== PGX_ENABLE )
		void	pgx_lcd_hd44780_write_p_float( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_Uint24 Decimal_Digits , float Flt ) {
            //--------------------------------------------------------------------
            //_pgx_int8 Str[ PGX_LCD_HD44780_COLUMNS ];
			pgx_lcd_hd44780_goto( Controller ,Ln , Pos );
			pgx_lcd_hd44780_write_string( Controller , pgx_ftoa( Flt, Decimal_Digits ) );
		}
	#endif
	//---[ END HD44780 Write Position Float ]---

	//---[ HD44780 Write Position Char ]---
	#if ( ( PGX_LCD_HD44780_SPLASH_FULL_0_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_FULL_1_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_FULL_2_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_FULL_3_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_SLIDE_0_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_SLIDE_1_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_SLIDE_2_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_SPLASH_SLIDE_3_EN == PGX_ENABLE ) || \
		( PGX_LCD_HD44780_WRITE_P_CHAR == PGX_ENABLE ) )
		//void	pgx_lcd_hd44780_write_p_char( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8  *Format , _pgx_int8 Chr ) {
		void	pgx_lcd_hd44780_write_p_char( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8  *Format , _pgx_int8 Chr ) {
            //--------------------------------------------------------------------
			 _pgx_int8 Str[ PGX_LCD_HD44780_COLUMNS ];
			pgx_lcd_hd44780_goto( Controller , Ln , Pos );
			sprintf( Str , Format , Chr );
			pgx_lcd_hd44780_write_string( Controller , Str );
		}
	#endif
	//---[ END HD44780 Write Position Char ]---

	//---[ HD44780 Write ]---
//	 #if ( PGX_LCD_HD44780_WRITE == PGX_INCLUDE )
//		 //void	pgx_lcd_hd44780_write( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8 * Format , ... ) {
//		 void	pgx_lcd_hd44780_write( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8 * Format , ... ) {
         //--------------------------------------------------------------------
//			 char    Message[ 2 * PGX_LCD_HD44780_COLUMNS ];
//			 va_list	VAList;
//			 va_start( VAList , Format );
//			 vsprintf( Message , Format , VAList );
//			 va_end( VAList );
//			 pgx_lcd_hd44780_goto( Controller , Ln , Pos );
//			 //pgx_lcd_hd44780_write_string( Controller , Ln , Pos , Message );
//			 pgx_lcd_hd44780_write_string( Controller , Message );
//		 }
//	 #endif
	//---[ END HD44780 Write ]---
#endif


