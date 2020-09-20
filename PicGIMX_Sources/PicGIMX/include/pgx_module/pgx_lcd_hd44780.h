//
#ifndef _PGIMX_LCD_HD44780_H_
	#define _PGIMX_LCD_HD44780_H_
	//------------------------------------------------------------------------
	#include "pgx_custom_type.h"
	#include "pgx_delay.h"
	//------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   L C D - H D 4 4 7 8 0
	//------------------------------------------------------------------------
	#if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
		// LAT
		#define PGX_LCD_HD44780_RS					L_D4				//!< Must be: <pin-lat-name>
		#define PGX_LCD_HD44780_RW_PRESENT			PGX_YES				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_RW					L_D5				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_0_PRESENT		PGX_YES				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_EN_0				L_D6				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_1_PRESENT		PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_EN_1				PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_2_PRESENT		PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_EN_2				PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_EN_3_PRESENT		PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_EN_3				PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_DATA_0				L_D0				//!< Must be: <pin-lat-name> (lcd DB4)
		#define PGX_LCD_HD44780_DATA_1				L_D1				//!< Must be: <pin-lat-name> (lcd DB5)
		#define PGX_LCD_HD44780_DATA_2				L_D2				//!< Must be: <pin-lat-name> (lcd DB6)
		#define PGX_LCD_HD44780_DATA_3				L_D3				//!< Must be: <pin-lat-name> (lcd DB7)
		#define PGX_LCD_HD44780_BL_0_PRESENT		PGX_YES				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_BL_0				L_D7				//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_1_PRESENT		PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_BL_1				PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_2_PRESENT		PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_BL_2				PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
		#define PGX_LCD_HD44780_BL_3_PRESENT		PGX_NO				//!< Must be: PGX_YES || PGX_NO
		#define PGX_LCD_HD44780_BL_3				PGX_MISSING			//!< Must be: <pin-lat-name> || PGX_MISSING if not used.
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
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   L C D - H D 4 4 7 8 0
	//----------------------------------------------------------------------------------------------------------------
	#if ( PGIMX_LCD_HD44780 == PGX_ENABLE )
		#define	PGX_LCD_HD44780_COLUMNS				16					//!< Number of columns of the display
		#define	PGX_LCD_HD44780_LINES				2					//!< Number of lines of the display
		#define	PGX_LCD_HD44780_BUSY_FLAG			PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define	PGX_LCD_HD44780_BUSY_DELAY			1					//!< Waiting time for display processing in micro-seconds [us]
		#define PGX_LCD_HD44780_TIMEOUT_MAX			1000				//!< The delay time required, when the BUSY-FLAG is NOT used
		#define	PGX_LCD_HD44780_LINE_0_ADDRESS		0x00				//!< Address (default 0x00) for the line number 1. Must be : PGX_MISSING if there is not.
		#define	PGX_LCD_HD44780_LINE_1_ADDRESS		0X40				//!< Address (default 0x40) for the line number 2. Must be : PGX_MISSING if there is not.
		#define	PGX_LCD_HD44780_LINE_2_ADDRESS		PGX_MISSING			//!< Address (default 0x00) for the line number 3. Must be : PGX_MISSING if there is not.
		#define	PGX_LCD_HD44780_LINE_3_ADDRESS		PGX_MISSING			//!< Address (default 0x40) for the line number 4. Must be : PGX_MISSING if there is not.
		#define	PGX_LCD_HD44780_BL_0_ENABLE			PGX_ENABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define	PGX_LCD_HD44780_BL_1_ENABLE			PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define	PGX_LCD_HD44780_BL_2_ENABLE			PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define	PGX_LCD_HD44780_BL_3_ENABLE			PGX_DISABLE			//!< Must be: PGX_ENABLE || PGX_DISABLE
		#define	PGX_LCD_HD44780_BL_0_ENABLE_LOGIC	PGX_POSITIVE			//!< Must be: PGX_POSITIVE || PGX_NEGATIVE
		#define	PGX_LCD_HD44780_BL_1_ENABLE_LOGIC	PGX_POSITIVE			//!< Must be: PGX_POSITIVE || PGX_NEGATIVE
		#define	PGX_LCD_HD44780_BL_2_ENABLE_LOGIC	PGX_POSITIVE			//!< Must be: PGX_POSITIVE || PGX_NEGATIVE
		#define	PGX_LCD_HD44780_BL_3_ENABLE_LOGIC	PGX_POSITIVE			//!< Must be: PGX_POSITIVE || PGX_NEGATIVE
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
	#if ( PGX_LCD_HD44780_BUSY_FLAG == PGX_ENABLE )
		/*!
			\brief			Wait for the display is ready to receive next comand or data.
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
		*/	
		void pgx_lcd_hd44780_wait_busy                  ( _pgx_int8 Controller );
	#endif
	//------------------------------------------------------------------------
	extern _pgx_Uint16 pgx_lcd_hd780_print_delay_ms;
	//---[ Prototypes ]-------------------------------------------------------
	/*!
		\brief			Slows down the speed of printing characters on the display. If set to zero the speed is maximum..
		\attention		Internal use only !
		\return			Nothing.
		\param			Delay time in [ms].
	*/	
	void pgx_lcd_hd44780_print_speed( _pgx_Uint16 PrintSpeed );
	//------------------------------------------------------------------------
	/*!
		\brief			Checks for the controllers to be initialized.
		\attention		Internal use only !
		\return			Nothing.
		\param			Nothing.
		\deprecated		Do not call directly. \n
						Already called in pgx_initialize().
	*/
	void	pgx_lcd_hd44780_init                        ( void );
	//------------------------------------------------------------------------
	/*!
		\brief			Properly initializes all present controllers. 
		\attention		Internal use only !
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\deprecated		Do not call directly. \n
						Already called in pgx_initialize().
	*/		
	void	pgx_lcd_hd44780_init_routine                ( _pgx_int8 Controller );
	//------------------------------------------------------------------------
	/*!
		\brief			Turn on all the pixels of the display. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
	*/			
	void	pgx_lcd_hd44780_splash_full                 ( _pgx_int8 Controller );
	//------------------------------------------------------------------------
	/*!
		\brief			Show full cursor moving.
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
	*/			
	void	pgx_lcd_hd44780_splash_slide                ( _pgx_int8 Controller );
	//------------------------------------------------------------------------
	/*!
		\brief			Delete all character on the display. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
	*/	
	void	pgx_lcd_hd44780_clear                       ( _pgx_int8 Controller );
	//------------------------------------------------------------------------
	/*!
		\brief			Places the cursor, in a specific position.
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
	*/	
	void	pgx_lcd_hd44780_goto                        ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a character, at the current position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Data					The character to print.
	*/	
	void	pgx_lcd_hd44780_put_char                    ( _pgx_int8 Controller , _pgx_Uint8 Data );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a character, in a specific position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
		\param			Data					The character to print.
	*/	
	void 	pgx_lcd_hd44780_put_p_char                  ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_Uint8 Data );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a byte, at the current position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Data					The byte to print.
	*/	
	void	pgx_lcd_hd44780_put_byte                    ( _pgx_int8 Controller , _pgx_Uint8 Val );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a byte, in a specific position.
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
		\param			Data					The byte to print.
	*/	
	void 	pgx_lcd_hd44780_put_p_byte                  ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_Uint8 Val );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a character from display CGRAM at the current position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			location				The storage location in the CGRAM.
		\param			new_char				The new char.
	*/	
	void	pgx_lcd_hd44780_char_generator              ( _pgx_int8 Controller , char location , char * new_char );
	//------------------------------------------------------------------------
	#if ( PGIMX_EE == PGX_ENABLE )
		/*!
			\brief			Print a character from micro-controller internal EEPROM at the current position.
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			location				The storage location in the EEPROM.
			\param			ee_addy					The char address in the microcontroller eeprom.
		*/	
		void	pgx_lcd_hd44780_char_generator_from_EE      ( _pgx_int8 Controller ,char location , _pgx_Uint16 ee_addy );
	#endif
	//------------------------------------------------------------------------
	/*!
		\brief			Write a nibble on the display data bus. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			DataType				The type of the data: a command or a data.
		\param			Dat						The command or the data to send.
	*/	
	void	pgx_ldc_hd44780_write_nibble                ( _pgx_int8 Controller , _pgx_Uint8 DataType , _pgx_Uint8 Dat );
	//------------------------------------------------------------------------
	/*!
		\brief			Write a byte on the display data bus.
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			DataType				The type of the data: a command or a data.
		\param			Dat						The command or the data to send.
	*/	
	void	pgx_lcd_hd44780_write_byte                  ( _pgx_int8 Controller , _pgx_Uint8 DataType , _pgx_Uint8 Dat );
	//------------------------------------------------------------------------
	/*!
		\brief			Enables selected controller. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			EnState					The state in which, the enable must be set.
							Use \b PGX_ENABLE to activate the controller \n
							Use \b PGX_DISABLE to deactivate the controller
	*/	
	void	pgx_lcd_hd44780_en_select                   ( _pgx_int8 Controller , _pgx_Uint8 EnState );
	//------------------------------------------------------------------------
	/*!
		\brief			Print with the \a PRINTF \a FORMAT, at the current position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
		\param			Format					The Format to use.
	*/	
	//void	pgx_lcd_hd44780_write                       ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8 * Format , ... );
	void	pgx_lcd_hd44780_write                       ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8 * Format , ... );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a string by a pointer, at the current position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Str						The pointer to the string in \a RAM.
	*/	
	void	pgx_lcd_hd44780_write_string                ( _pgx_int8 Controller , _pgx_int8 * Str );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a constant string by a pointer, at the current position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Str						The pointer to the string in \a ROM.
	*/	
	//void	pgx_lcd_hd44780_write_string_rom            ( _pgx_int8 Controller , const rom _pgx_int8 * Str );
	void	pgx_lcd_hd44780_write_string_rom            ( _pgx_int8 Controller , const _pgx_int8 * Str );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a string by a pointer, in a specific position.
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
		\param			Str						The pointer to the string in \a RAM.
	*/	
	void	pgx_lcd_hd44780_write_p_string              ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_int8 * Str );
	//------------------------------------------------------------------------
	/*!
	*/	
	void	pgx_lcd_hd44780_write_p_string_flash        ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_int8  *Str , _pgx_Uint8 time , _pgx_Uint8 unit );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a constant string by a pointer, in a specific position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
		\param			Str						The pointer to the string in \a ROM.
	*/	
	//void	pgx_lcd_hd44780_write_p_string_rom          ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8 * Str );
	void	pgx_lcd_hd44780_write_p_string_rom          ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8 * Str );
	//------------------------------------------------------------------------
	/*!
	 */
	//void	pgx_lcd_hd44780_write_p_string_flash_rom	( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8 * Str , _pgx_Uint8 time , _pgx_Uint8 unit );
	void	pgx_lcd_hd44780_write_p_string_flash_rom	( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8 * Str , _pgx_Uint8 time , _pgx_Uint8 unit );
	//------------------------------------------------------------------------
	/*!
		\brief			Print an integer, specifying the Format, in a specific position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
		\param			Format					The Format to use.
	*/	
	//void	pgx_lcd_hd44780_write_p_int                 ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8 * Format , _pgx_int16 Val );
	void	pgx_lcd_hd44780_write_p_int                 ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8 * Format , _pgx_int16 Val );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a float, specifying the Format, in a specific position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
		\param			Format					The Format to use.
	*/	
	void	pgx_lcd_hd44780_write_p_float               ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , _pgx_Uint24 Decimal_Digits , float Flt );
	//------------------------------------------------------------------------
	/*!
		\brief			Print a char, specifying the Format, in a specific position. 
		\return			Nothing.
		\param			ControllerNumber		The number of the controller.
		\param			Ln						It specifies the line.
		\param			Pos						It specifies the column.
		\param			Decimal_Digits			Number of digits of truncation, after the decimal point of the float value.
		\param			Flt						Float value to be printed.
	*/	
	//void	pgx_lcd_hd44780_write_p_char                ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8 * Format , _pgx_int8 chr );
	//void	pgx_lcd_hd44780_write_pchar_rom             ( _pgx_Uint8 Ln , _pgx_Uint8 Pos , const rom far _pgx_int8  *Format , const rom far _pgx_int8 chr );
	void	pgx_lcd_hd44780_write_p_char                ( _pgx_int8 Controller , _pgx_Uint8 Ln , _pgx_Uint8 Pos , const _pgx_int8 * Format , _pgx_int8 chr );
	//---[ END Prototypes ]-----------------------------------------------
#endif /* _PGIMX_LCD_HD44780_H_ */


/*!	\page	HWE_lcd_HD44780		LCD Character [Hitachi HD44780]

		\tableofcontents

		\image	html	lcd_char.png

		<p>
			This module manages the <b>Characters LCD Display</b> with <b>HD44780</b> controller.<br>
			It is able to support up to a maximum of four controllers.<br>
			For each controller, four lines are available.<br>
			For example it is possible use two 4x40 (which have 2 controllers each), or four 4x20 (which have only a controller each).<br>
			The management of the data bus, at present, is implemented only in four bit mode.<br>
			The configuration also allows to choose whether to use the <b>Busy-Flag</b>, or a software delay.<br>
		</p>
		\n \n \n 
		
		\section	CLCDconf	Module configuration
			\htmlonly <hr> \endhtmlonly
			In order to use the module, it must enabled and software configured in: \n
			\arg \b pgx_module_setup_public.h : the main management file for the modules that must be included in the project.
				
			and must be assigned to it the related control pins in: \n
			\arg \b pgx_hardware_setup_public.h : where there are all hardware configuration of all modules.
			\n \n \n	
		
		\subsection	CLCDdim		Display dimensions
			\htmlonly <hr> \endhtmlonly
			\code
				#define	PGX_LCD_HD44780_COLUMN				16
				#define	PGX_LCD_HD44780_LINE					2
			\endcode
			\htmlonly
				These defines set the dimensions of the display in the number of columns and rows.<br>
			\endhtmlonly

				\subsubsection	CLCDdimref	Reference
					\li \e File : pgx_module_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_COLUMN \n
					\li \e Reference : \ref PGX_LCD_HD44780_LINE \n

		\subsection	CLCDbusy	Busy Time mode
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_BUSY_FLAG			PGX_ENABLE
			\endcode
			\htmlonly
				With this define you change the way you manage the <i>busy time</i> of the display.<br>
				It must be:<br>
			\endhtmlonly
				\arg \b PGX_ENABLE : busy flag enabled.
				\arg \b PGX_DISABLE : busy flag disabled.
				\endcode
				
			\htmlonly
				With <b>PGX_LCD_HD44780_BUSY_FLAG</b> <i>enabled</i> PicGIM uses the <b>busy flag</b> of the LCD.<br>
				If <i>disabled</i> PicGIM calls a delay; this is an easier method but with a light loss of performance.<br>
			\endhtmlonly

				\subsubsection	CLCDbusyref	Reference
					\li \e File : pgx_module_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_COLUMN \n
					\li \e Reference : \ref PGX_LCD_HD44780_LINE \n
			
		\subsection	CLCDlina	Line addresses
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_LINE_0_ADDRESS		0x00
				#define PGX_LCD_HD44780_LINE_1_ADDRESS		0x40
				#define PGX_LCD_HD44780_LINE_2_ADDRESS		0x00
				#define PGX_LCD_HD44780_LINE_3_ADDRESS		0x40
			\endcode	
			\htmlonly
				These defines set the addresses of the <i>first</i> character of each line.<br>
				Max four lines are available.<br>
				Missing lines <b>MUST</b> be set to <b>PGX_MISSING</b> .
			\endhtmlonly

				\subsubsection	CLCDlinaref	Reference
					\li \e File : pgx_module_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_LINE_0_ADDRESS \n
					\li \e Reference : \ref PGX_LCD_HD44780_LINE_1_ADDRESS \n
					\li \e Reference : \ref PGX_LCD_HD44780_LINE_2_ADDRESS \n
					\li \e Reference : \ref PGX_LCD_HD44780_LINE_3_ADDRESS \n

		\subsection	CLCDspl		Splash screen
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_SPLASH_ENABLE		PGX_ENABLE
			\endcode	
			\htmlonly
				A print of a splash screen is possible enabling this define.<br>
				It must be:<br>
			\endhtmlonly
				\arg \b PGX_ENABLE : splash screen enabled.
				\arg \b PGX_DISABLE : splash screen disabled.
				\endcode

			\code
				#define PGX_LCD_HD44780_SPLASH_TIME			1
			\endcode	
			\htmlonly
				This one is to choose how long view it.<br>
				Time is expressed in seconds [s].<br>
				It is a quick way to verify the correct initialization of the display.<br>
			\endhtmlonly

				\subsubsection	CLCDsplref	Reference
					\li \e File : pgx_module_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_SPLASH_ENABLE \n
					\li \e Reference : \ref PGX_LCD_HD44780_SPLASH_TIME \n
			
		\subsection	CLCDpinrw	Pin: RW
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_RW_PRESENT			PGX_YES
				#define PGX_LCD_HD44780_RW					L_B3
			\endcode
			\htmlonly
				This pin controls the reading or writing.<br>
			\endhtmlonly

				\subsubsection	CLCDpinrwref	Reference
					\li \e File : pgx_hardware_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_RW_PRESENT \n
					\li \e Reference : \ref PGX_LCD_HD44780_RW \n
			
		\subsection	CLCDpinrs	Pin: RS
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_RS					L_B4
			\endcode
			\htmlonly
				This pin controls whether the display must receive a command or a data.<br>
			\endhtmlonly

				\subsubsection	CLCDpinrsref	Reference
					\li \e File : pgx_hardware_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_RS \n

		\subsection	CLCDpinen	Pin: EN
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_EN_0_PRESENT			PGX_YES
				#define PGX_LCD_HD44780_EN_1_PRESENT			PGX_NO
				#define PGX_LCD_HD44780_EN_2_PRESENT			PGX_NO
				#define PGX_LCD_HD44780_EN_3_PRESENT			PGX_NO
			\endcode
			\htmlonly
				These defines declares the availability of enables.<br>
				It must be:<br>
			\endhtmlonly
				\arg \b PGX_YES : lcd enable pin present.
				\arg \b PGX_NO  : lcd enable pin not present.
				\endcode
				
			\code
				#define PGX_LCD_HD44780_EN_0					L_B2
				#define PGX_LCD_HD44780_EN_1					PGX_MISSING
				#define PGX_LCD_HD44780_EN_2					PGX_MISSING
				#define PGX_LCD_HD44780_EN_3					PGX_MISSING
			\endcode
			\htmlonly
				These defines assign the pin to enable that was declared present.<br>
				If an enable not exist, you must set this field to PGX_MISSING.<br>
			\endhtmlonly

				\subsubsection	CLCDpinenref	Reference
					\li \e File : pgx_hardware_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_0_PRESENT \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_1_PRESENT \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_2_PRESENT \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_3_PRESENT \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_0 \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_1 \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_2 \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_3 \n

		\subsection	CLCDpindat	Pin: DATA<0-3>
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_DATA_0				L_D7
				#define PGX_LCD_HD44780_DATA_1				L_D6
				#define PGX_LCD_HD44780_DATA_2				L_D5
				#define PGX_LCD_HD44780_DATA_3				L_D4
			\endcode			
			\htmlonly
				Here are defined the four pins for data.<br>
				Refer to the datasheet of the display to know what are the pin relative to which to connect in four-bit mode.<br>
			\endhtmlonly
			
				\subsubsection	CLCDpindatref	Reference
					\li \e File : pgx_hardware_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_0 \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_1 \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_2 \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_3 \n

		\subsection	CLCDpinbl	Pin: BL
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_BL_PRESENT			PGX_YES
			\endcode	
			\htmlonly
				This define declares the availability of the BACKLIGHT pin control.<br>
				It must be:<br>
			\endhtmlonly
				\arg \b PGX_YES : backlight pin is present.
				\arg \b PGX_NO : backlight pin is not present.
				\endcode
			\code
				#define PGX_LCD_HD44780_BL					L_D3
			\endcode	
			\htmlonly
				This define assign the pin to control the backlight that was declared present.<br>
				If a backlight pin do not exist, you must set this field to PGX_MISSING.<br>
			\endhtmlonly

				\subsubsection	CLCDpinblref	Reference
					\li \e File : pgx_hardware_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_BL_PRESENT \n
					\li \e Reference : \ref PGX_LCD_HD44780_BL \n

		\subsection	CLCDpintr	Tris
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_RW_TRIS				T_B3
				#define PGX_LCD_HD44780_RS_TRIS				T_B4
				#define PGX_LCD_HD44780_EN_0_TRIS			T_B2
				#define PGX_LCD_HD44780_EN_1_TRIS			PGX_MISSING
				#define PGX_LCD_HD44780_EN_2_TRIS			PGX_MISSING
				#define PGX_LCD_HD44780_EN_3_TRIS			PGX_MISSING
				#define PGX_LCD_HD44780_DATA_0_TRIS			T_D7
				#define PGX_LCD_HD44780_DATA_1_TRIS			T_D6
				#define PGX_LCD_HD44780_DATA_2_TRIS			T_D5
				#define PGX_LCD_HD44780_DATA_3_TRIS			T_D4
				#define PGX_LCD_HD44780_BL_TRIS				T_D3
			\endcode	
			\htmlonly
				These define concern all tris pins that were configured previously.<br>
				The name matching ensures easy association.<br>
				If a Tris pin is not used, you must set this field to PGX_MISSING.<br>
			\endhtmlonly

				\subsubsection	CLCDpintrref	Reference
					\li \e File : pgx_hardware_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_RW_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_RS_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_0_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_1_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_2_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_EN_3_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_0_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_1_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_2_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_3_TRIS \n
					\li \e Reference : \ref PGX_LCD_HD44780_BL_TRIS \n

		\subsection	CLCDpinpo	Port
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGX_LCD_HD44780_DATA_0_PORT			P_D7
				#define PGX_LCD_HD44780_DATA_1_PORT			P_D6
				#define PGX_LCD_HD44780_DATA_2_PORT			P_D5
				#define PGX_LCD_HD44780_DATA_3_PORT			P_D4
			\endcode
			\htmlonly
				When using the BUSY-FLAG, it is necessary to be able to read from the display.<br>
				So, it is important to specify its corresponding port pin previously declared.<br>
				The name matching ensures easy association.<br>
			\endhtmlonly

				\subsubsection	CLCDpinporef	Reference
					\li \e File : pgx_hardware_setup_public.h \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_0_PORT \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_1_PORT \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_2_PORT \n
					\li \e Reference : \ref PGX_LCD_HD44780_DATA_3_PORT

			\n \n \n 


 		\section	CLCDfun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

			\attention	This module can use the \b Error \b Handling \b Module : \ref SWG_error \n
						In the \e TEST section of each function is specified which values ​​are set and in which cases. \n
						Please refer to the specific documentation of the file header: \ref pgx_adc.h

			\htmlonly <br> \endhtmlonly

			\subsection	CLCDfunprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pgx_lcd_hd44780_init() : Properly initializes all present controllers.
				\arg \b pgx_lcd_hd44780_init_routine() : Initializes the present controller.
				\arg \b pgx_lcd_hd44780_wait_busy() : Wait for the display is ready to receive next comand or data.
				\arg \b pgx_lcd_hd44780_goto() : Places the cursor, in a specific position.
				\arg \b pgx_lcd_hd44780_en_select() : Enables selected controller.
				\arg \b pgx_ldc_hd44780_write_nibble() : Write a nibble on the display data bus.
				\arg \b pgx_lcd_hd44780_write_byte() : Write a byte on the display data bus.

				\htmlonly <br><br> \endhtmlonly

			\subsection	CLCDfunpubfunc	Public functions
				\endcode

				\arg \b pgx_lcd_hd44780_clear() : Delete all characters from the display.
				\arg \b pgx_lcd_hd44780_put_char() : Print a character, at the current position.
				\arg \b pgx_lcd_hd44780_put_p_char() : Print a character, in a specific position.
				\arg \b pgx_lcd_hd44780_put_byte() : Print a byte, at the current position.
				\arg \b pgx_lcd_hd44780_put_p_byte() : Print a byte, in a specific position.
				\arg \b pgx_lcd_hd44780_char_generator() : Print a character from display CGRAM at the current position.
				\arg \b pgx_lcd_hd44780_char_generator_from_EE() : Print a character from micro-controller internal EEPROM at the current position.
				\arg \b pgx_lcd_hd44780_write() : Print with the <i>PRINTF FORMAT</i>, at the current position.
				\arg \b pgx_lcd_hd44780_write_string() : Print a string by a pointer, at the current position.
				\arg \b pgx_lcd_hd44780_write_string_rom() : Print a constant string by a pointer, at the current position.
				\arg \b pgx_lcd_hd44780_write_p_string() : Print a string by a pointer, in a specific position.
				\arg \b pgx_lcd_hd44780_write_p_string_rom() : Print a constant string by a pointer, in a specific position.
				\arg \b pgx_lcd_hd44780_write_p_int() : Print an integer, specifying the Format, in a specific position.
				\arg \b pgx_lcd_hd44780_write_p_float() : Print a float, specifying the Format, in a specific position.
				\arg \b pgx_lcd_hd44780_write_p_char() : Print a char, specifying the Format, in a specific position.

			\endcode

			\htmlonly <br><br> \endhtmlonly




 	\attention	Here a link to the file : \ref pgx_lcd_hd44780.h \n
				This is not a file defined as public and therefore would not be edited. \n
				We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/
	

