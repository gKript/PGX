//
#include "pgx.h"

#if ( PGIMX_FLASH_LVP == PGX_ENABLE )

	#if	( PGX_PROJECT_STATE == PGX_DEBUG )
		#warning	PicGIMX >>> Message >>> This file is compiling.
	#endif
	
	//--------------------------------------------------------------------------
	// DS39643B - Flash Microcontroller Programming Specification
	// For 18F8722 (Enhanced)
	// P1 && P17 timing with acceptable MAX value!!!
	//--------------------------------------------------------------------------
	// !!! NOT all parameters are under define, check them if mcu is changed !!!
	//--------------------------------------------------------------------------
	
	//---[ Init ]---
	void pgx_flash_lvp_init( void ) {
		//--------------------------------------------------------------------------
		PGX_FLASH_LVP_PGD_TRIS	= PGX_IN;
		PGX_FLASH_LVP_PGC_TRIS	= PGX_IN;
		PGX_FLASH_LVP_PGM_TRIS	= PGX_IN;
		PGX_FLASH_LVP_RST_TRIS	= PGX_IN;
	}

	//---[ Enter LVP Mode ]---
	void pgx_flash_lvp_mode_enter( void ) {
		//--------------------------------------------------------------------------
		PGX_FLASH_LVP_PGD_LAT	= PGX_LOW;
		PGX_FLASH_LVP_PGC_LAT	= PGX_LOW;
		PGX_FLASH_LVP_PGM_LAT	= PGX_LOW;
		PGX_FLASH_LVP_RST_LAT	= PGX_LOW;
		
		PGX_FLASH_LVP_PGD_TRIS	= PGX_OUT;
		PGX_FLASH_LVP_PGC_TRIS	= PGX_OUT;
		PGX_FLASH_LVP_PGM_TRIS	= PGX_OUT;
		PGX_FLASH_LVP_RST_TRIS	= PGX_OUT;
		
		PGX_FLASH_LVP_PGM_LAT	= PGX_HIGH;
		pgx_delay_usec( 5 );					//Delay P15=[2us] min.
		PGX_FLASH_LVP_RST_LAT	= PGX_HIGH;
		pgx_delay_usec( 5 );					//Delay P12=[2us] min.
		//exiting clean: low on clk && data & pgm && rst
	}
	
	//---[ Exit LVP Mode ]---
	void pgx_flash_lvp_mode_exit( void ) {
		//--------------------------------------------------------------------------
		PGX_FLASH_LVP_PGD_LAT	= PGX_LOW;
		PGX_FLASH_LVP_PGC_LAT	= PGX_LOW;
		pgx_delay_usec( 1 );					//Delay P16=[0s] min.
		PGX_FLASH_LVP_RST_LAT	= PGX_LOW;
		pgx_delay_usec( 1 );					//Delay P18=[0s] min.
		PGX_FLASH_LVP_PGM_LAT	= PGX_LOW;
		pgx_delay_msec( 1 );					//added out delay
		PGX_FLASH_LVP_PGD_TRIS	= PGX_IN;	//release programming pin
		PGX_FLASH_LVP_PGC_TRIS	= PGX_IN;	//release programming pin
		//PGX_FLASH_LVP_RST_TRIS	left low and exits keeping target in reset
	}
	
	//---[ Send Command-Payload ]---
	void pgx_flash_lvp_send_command( _pgx_Uint8 pgx_command , _pgx_Uint16 pgx_payload ) {
		//--------------------------------------------------------------------------
		_pgx_Uint8	n;
		
		for( n = 0 ; n < 4 ; n++ ) {
			PGX_FLASH_LVP_PGD_LAT = ( ( pgx_command >> n ) & 0b00000001 );		//Least Significant bit (LSb) first
			PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
			pgx_delay_usec( 1 );				//wait P3=15[ns] min.
			PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
			pgx_delay_usec( 1 );				//wait P4=15[ns] min.
			
		}
		pgx_delay_usec( 1 );					//wait P5=40[ns] min.
		//PGX_FLASH_LVP_PGD_LAT = PGX_LOW;	//clean data
		for( n = 0 ; n < 16 ; n++ ) {
			PGX_FLASH_LVP_PGD_LAT = ( ( pgx_payload >> n ) & 0x0001);
			PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
			pgx_delay_usec( 1 );				//wait P3=15[ns] min.
			PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
			pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		}
		PGX_FLASH_LVP_PGD_LAT = PGX_LOW;		//exit low as clk, clean to default!
		pgx_delay_usec( 1 );					//wait P5A=40[ns] min.
		//exiting clean: low on clk && data
	}
	
	//---[ Read - Shift Out Data ]---
	_pgx_Uint8 pgx_flash_lvp_shift_out_data( void ) {
		//--------------------------------------------------------------------------
		_pgx_Uint8	n;
		_pgx_Uint8	data_out;
		
		data_out = 0x00;
		for( n = 0 ; n < 4 ; n++ ) {
			PGX_FLASH_LVP_PGD_LAT = ( ( PGX_FLASH_LVP_COMMAND_SHIFT_OUT >> n ) & 0b00000001 );
			PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
			pgx_delay_usec( 1 );				//wait P3=15[ns] min.
			PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
			pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		}
		pgx_delay_usec( 1 );					//wait P5=40[ns] min.
		PGX_FLASH_LVP_PGD_LAT = PGX_LOW;		//clean data
		for( n = 0 ; n < 8 ; n++ ) {		//skip MSB
			PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
			pgx_delay_usec( 1 );				//wait P3=15[ns] min.
			PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
			pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		}
		pgx_delay_usec( 1 );					//wait P6=20[ns] min.
		PGX_FLASH_LVP_PGD_TRIS = PGX_IN;		//ready to read data from target
		for( n = 0 ; n < 8 ; n++ ) {		//read LSB (LSb first)
			PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;	
			pgx_delay_usec( 1 );				//wait P14=10[ns] min.
			if( PGX_FLASH_LVP_PGD_PORT ) {
				data_out |= 0b10000000;
			}
			data_out >>= 1;
			PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
			pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		}
		pgx_delay_usec( 1 );					//wait P5A=40[ns] min.
		PGX_FLASH_LVP_PGD_TRIS = PGX_OUT;		
		return( data_out );
		//exiting clean: low on clk && data
	}
	
	//---[ Bulk Erase ]---
	void pgx_flash_lvp_bulk_erase( _pgx_Uint8 pgx_memory_area_id ) {
		//--------------------------------------------------------------------------
		_pgx_Uint32_VAL	address;
		
		address.val =	pgx_memory_area_id;
		//--------------------------------------------------------------------------
		// Step 1: Write control register high byte
		//--------------------------------------------------------------------------
		// 0000	0E 3C				MOVLW 3Ch
		// 0000	6E F8				MOVWF TBLPTRU
		// 0000	0E 00				MOVLW 00h
		// 0000	6E F7				MOVWF TBLPTRH
		// 0000	0E 05				MOVLW 05h
		// 0000	6E F6				MOVWF TBLPTRL
		// 1100	FF FF				Write FFh to 3C0005h to erase entire device (PGX_FLASH_LVP_BULK_ERASE_CHIP)
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E3C );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF8 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E00 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF7 );		
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E05 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF6 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_TBLWR , ( ( (_pgx_Uint16)address.byte.HB << 8 ) & address.byte.HB ) );
		//--------------------------------------------------------------------------
		// Step 2: Write control register low byte
		//--------------------------------------------------------------------------
		// 0000	0E 3C				MOVLW 3Ch
		// 0000	6E F8				MOVWF TBLPTRU
		// 0000	0E 00				MOVLW 00h
		// 0000	6E F7				MOVWF TBLPTRH
		// 0000	0E 04				MOVLW 04h
		// 0000	6E F6				MOVWF TBLPTRL
		// 1100	87 87				Write 87h TO 3C0004h to erase entire device (PGX_FLASH_LVP_BULK_ERASE_CHIP)
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E3C );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF8 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E00 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF7 );		
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E04 );	
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF6 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_TBLWR , ( ( (_pgx_Uint16)address.byte.LB << 8 ) & address.byte.LB ) );
		//--------------------------------------------------------------------------
		// Step 3: Start erasing
		//--------------------------------------------------------------------------
		// 0000	00 00				NOP
		// 0000	00 00				Hold PGD low until erase completes(P10+P11)
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0000 );		
		//here PGD must be held low to the end
		pgx_delay_msec( 10 );				//wait P11=5[ms] min. + P10=100[us] min.
	}

	//---[ Write Program Memory ]---
	void pgx_flash_lvp_write_program_memory_block( _pgx_Uint32 pgx_table_ptr_address , _pgx_Uint16 * pgx_code_word ) {
		//--------------------------------------------------------------------------
		_pgx_Uint16	n;
		_pgx_Uint32_VAL	address;
		
		address.val = pgx_table_ptr_address;
		//--------------------------------------------------------------------------
		// Step 1: Direct access to configuration memory.
		//--------------------------------------------------------------------------
		// 0000	8E A6				BSF   EECON1, EEPGD
		// 0000	8C A6				BSF   EECON1, CFGS
		// 0000	84 A6				BSF   EECON1, WREN
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x8EA6 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x8CA6 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x84A6 );
		//--------------------------------------------------------------------------
		// Step 2: Direct access to code memory and enable writes.
		//--------------------------------------------------------------------------
		// 0000	8E A6				BSF   EECON1, EEPGD
		// 0000	9C A6				BCF   EECON1, CFGS
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x8EA6 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x9CA6 );
		//--------------------------------------------------------------------------
		// Step 3: Load write buffer for panel.
		//--------------------------------------------------------------------------
		// 0000	0E <Addr[21:16]>	MOVLW <Addr[21:16]>
		// 0000	6E F8				MOVWF TBLPTRU
		// 0000	0E <Addr[15:8]>		MOVLW <Addr[15:8]>
		// 0000	6E F7				MOVWF TBLPTRH
		// 0000	0E <Addr[7:0]>		MOVLW <Addr[7:0]>
		// 0000	6E F6				MOVWF TBLPTRL
		// 1101	<MSB><LSB>			Write 2 bytes and post-increment address by 2.. 
		// ....	...					Repeat 28 times.									//??? #31(con incremento) + 1(senza incremento)!
		// 1111	<MSB><LSB>			Write 2 bytes and start programming
		// 0000	00 00				NOP - hold SCLK high for time P9, low for time P10
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , address.byte.UB );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF8 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , address.byte.HB );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF7 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , address.byte.LB );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF6 );
		for( n = 0 ; n < ( PGX_FLASH_LVP_CODEBLOCK_SIZE_WORD - 1 ) ; n++ ) {
			pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_TBLWR_POSTINC_2B , *( pgx_code_word + n ) );
		}
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_TBLWR_START , *( pgx_code_word + n ) );	//last word without increment
		PGX_FLASH_LVP_PGD_LAT = PGX_LOW;	//ensure data is low
		PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
		pgx_delay_usec( 1 );				//wait P3=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
		pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
		pgx_delay_usec( 1 );				//wait P3=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
		pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
		pgx_delay_usec( 1 );				//wait P3=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
		pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
		pgx_delay_msec( 10 );			//wait P9=1[ms] min.		(programming time!)
		PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
		pgx_delay_msec( 1 );				//wait P10=100[us] min. 	(discharge time!)
		//exiting clean: low on clk && data
	}	

	//---[ Write EE Memory ]---
	void pgx_flash_lvp_write_ee_memory_byte( _pgx_Uint16 pgx_ee_address , _pgx_Uint8 pgx_ee_data ) {
		//--------------------------------------------------------------------------
		_pgx_Uint16_VAL	address;
		
		address.val = pgx_ee_address;
		//--------------------------------------------------------------------------
		// Step 1: Direct access to data EEPROM.
		//--------------------------------------------------------------------------
		// 0000	9E A6				BCF    EECON1,    EEPGD
		// 0000	9C A6				BCF    EECON1,    CFGS
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x9EA6 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x9CA6 );
		//--------------------------------------------------------------------------
		// Step 2: Set the data EEPROM address pointer.
		//--------------------------------------------------------------------------
		// 0000	0E <Addr>			MOVLW  <Addr>
		// 0000	6E A9				MOVWF  EEADR
		// 0000	0E <AddrH>			MOVLW  <AddrH>
		// 0000	6E AA				MOVWF  EEADRH
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , ( 0x0E00 & address.byte.LB ) );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EA9 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , ( 0x0E00 & address.byte.HB ) );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EAA );
		//--------------------------------------------------------------------------
		// Step 3: Load the data to be written.
		//--------------------------------------------------------------------------
		// 0000	0E <Data>			MOVLW  <Data>
		// 0000	6E A8				MOVWF  EEDATA
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , ( 0x0E00 & pgx_ee_data ) );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EA8 );
		//--------------------------------------------------------------------------
		// Step 4: Enable memory writes.
		//--------------------------------------------------------------------------
		// 0000	84 A6				BSF    EECON1, WREN
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x84A6 );
		//--------------------------------------------------------------------------
		// Step 5: Initiate write.
		//--------------------------------------------------------------------------
		// 0000	82 A6				BSF    EECON1, WR
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x82A6 );
		//--------------------------------------------------------------------------
		// Step 6: Poll WR bit, repeat until the bit is clear.
		// [EECON1] = <7-EEPGD ><6-CFGS ><5-— ><4-FREE ><3-WRERR ><2-WREN ><1-WR ><0-RD>
		//--------------------------------------------------------------------------
		// 0000	50 A6				MOVF   EECON1, W, 0
		// 0000	6E F5				MOVWF  TABLAT
		// 0000	00 00				NOP
		// 0010	<MSB><LSB>			Shift out data(1)
		//--------------------------------------------------------------------------
		do{ pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x50A6 );
			pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF5 );
			pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0000 );
		} while( ! ( pgx_flash_lvp_shift_out_data( ) & 0b00000010 ) );
		//--------------------------------------------------------------------------
		// Step 7: Hold PGC low for time P10.
		//--------------------------------------------------------------------------
		// clk is already low...
		pgx_delay_msec( 1 );				//wait P10=100[us] min.
		//--------------------------------------------------------------------------
		// Step 8: Disable writes.
		//--------------------------------------------------------------------------
		// 0000	94 A6				BCF    EECON1, WREN
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x94A6 );
	}
	
	//---[ Write ID Location ]---
	void pgx_flash_lvp_write_id_location( _pgx_Uint8  * pgx_id_data ) {
		//--------------------------------------------------------------------------
		_pgx_Uint8	n;
		_pgx_Uint16_VAL	data;
		
		//--------------------------------------------------------------------------
		// Step 1: Direct access to code memory and enable writes.
		//--------------------------------------------------------------------------
		// 0000	8E A6			BSF   EECON1, EEPGD
		// 0000	9C A6			BCF   EECON1, CFGS
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x8EA6 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x9CA6 );
		//--------------------------------------------------------------------------
		// Step 2: Load write buffer with 8 bytes and write.
		//--------------------------------------------------------------------------
		// 0000	0E 20			MOVLW 20h
		// 0000	6E F8			MOVWF TBLPTRU
		// 0000	0E 00			MOVLW 00h
		// 0000	6E F7			MOVWF TBLPTRH
		// 0000	0E 00			MOVLW 00h
		// 0000	6E F6			MOVWF TBLPTRL
		// 1101	<MSB><LSB>		Write 2 bytes and post-increment address by 2.
		// 1101	<MSB><LSB>		Write 2 bytes and post-increment address by 2.
		// 1101	<MSB><LSB>		Write 2 bytes and post-increment address by 2.
		// 1111	<MSB><LSB>		Write 2 bytes and start programming.
		// 0000	00 00			NOP - hold PGC high for time P9 and low for time P10.
		//--------------------------------------------------------------------------
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E20 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF8 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E00 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF7 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0E00 );
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x6EF6 );
		for( n = 0 ; n < 6 ; n + 2 ) {
			data.byte.HB = *( pgx_id_data + n );
			data.byte.LB = *( pgx_id_data + n + 1);
			pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_TBLWR_POSTINC_2B , data.val );
		}
		data.byte.HB = *( pgx_id_data + n );
		data.byte.LB = *( pgx_id_data + n + 1);
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_TBLWR_START , data.val );	//last word without increment
		pgx_flash_lvp_send_command( PGX_FLASH_LVP_COMMAND_CORE , 0x0000 );	
		PGX_FLASH_LVP_PGD_LAT = PGX_LOW;	//ensure data is low
		PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
		pgx_delay_usec( 1 );				//wait P3=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
		pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
		pgx_delay_usec( 1 );				//wait P3=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
		pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
		pgx_delay_usec( 1 );				//wait P3=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
		pgx_delay_usec( 1 );				//wait P4=15[ns] min.
		PGX_FLASH_LVP_PGC_LAT = PGX_HIGH;
		pgx_delay_msec( 10 );			//wait P9=1[ms] min.		(programming time!)
		PGX_FLASH_LVP_PGC_LAT = PGX_LOW;
		pgx_delay_msec( 1 );				//wait P10=100[us] min. 	(discharge time!)
		//exiting clean: low on clk && data
	}
	
#endif

	
	
	// bit 7	EEPGD: Flash Program or Data EEPROM Memory
	// Select bit
	// 1 =  Access Flash program memory
	// 0 =  Access data EEPROM memory
	// bit 6	CFGS: Flash Program/Data EEPROM or Configuration
	// Select bit
	// 1 =  Access Configuration registers
	// 0 =  Access Flash program or data EEPROM memory
	
