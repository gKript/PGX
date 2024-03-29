//
#ifndef _PGIMX_FLASH_LVP_H_
	#define _PGIMX_FLASH_LVP_H_
	
	#if ( PGIMX_FLASH_LVP == PGX_ENABLE )
		
		//--------------------------------------------------------------------------
		// DS39643B - Flash Microcontroller Programming Specification
		// For 18F8722 (Enhanced)
		// P1 && P17 timing with acceptable MAX value!!!
		//--------------------------------------------------------------------------
		// !!! NOT all parameters are under define, check them if mcu is changed !!!
		//--------------------------------------------------------------------------
	
		void		pgx_flash_lvp_init							( void );
		void		pgx_flash_lvp_mode_enter					( void );
		void		pgx_flash_lvp_mode_exit						( void );
		void		pgx_flash_lvp_send_command					( _pgx_Uint8 pgx_command , _pgx_Uint16 pgx_payload );
		_pgx_Uint8	pgx_flash_lvp_shift_out_data				( void );
		void		pgx_flash_lvp_bulk_erase					( _pgx_Uint8 pgx_memory_area );
		void		pgx_flash_lvp_erase_program_memory_block	( _pgx_Uint32 pgx_table_ptr_address , _pgx_Uint16 pgx_block_quantity );
		void		pgx_flash_lvp_write_program_memory_block	( _pgx_Uint32 pgx_table_ptr_address , _pgx_Uint16 * pgx_code_word );
		void		pgx_flash_lvp_write_ee_memory_byte			( _pgx_Uint16 pgx_ee_address , _pgx_Uint8 pgx_ee_data );
		void		pgx_flash_lvp_write_id_location				( _pgx_Uint8  * pgx_id_data );
		
		//---[ Writing Block Size ]---
		#define	PGX_FLASH_LVP_CODEBLOCK_SIZE_BYTE			64
		#define	PGX_FLASH_LVP_CODEBLOCK_SIZE_WORD			32
		#define	PGX_FLASH_LVP_ID_LOCATION_SIZE_BYTE			8
		#define	PGX_FLASH_LVP_ID_LOCATION_SIZE_WORD			4
		#define	PGX_FLASH_LVP_EEPROM_SIZE_BYTE				1024
		
		//---[ Address Memory Area ]---
		#define	PGX_FLASH_LVP_ADDRESS_FUSES					0x300000	//<!   14 byte area size (0x300000-0x30000D)
		#define	PGX_FLASH_LVP_ADDRESS_EEPROM				0xF00000	//<! 1024 bytes (00h to 3FFh)
		#define	PGX_FLASH_LVP_ADDRESS_ID_LOCATION			0x200000	//<!    8 byte area size (0x200000-0x200007)
		#define	PGX_FLASH_LVP_ADDRESS_DEVICE_ID				0x3FFFFE	//<!    2 byte area size (0x3FFFFE-0x3FFFFF)
		
		//---[ 4bit Command ]---
		#define	PGX_FLASH_LVP_COMMAND_CORE					0b00000000
		#define	PGX_FLASH_LVP_COMMAND_SHIFT_OUT				0b00000010
		#define	PGX_FLASH_LVP_COMMAND_TBLRD					0b00001000
		#define	PGX_FLASH_LVP_COMMAND_TBLRD_POSTINC			0b00001001
		#define	PGX_FLASH_LVP_COMMAND_TBLRD_POSTDEC			0b00001010
		#define	PGX_FLASH_LVP_COMMAND_TBLRD_PREINC			0b00001011
		#define	PGX_FLASH_LVP_COMMAND_TBLWR					0b00001100
		#define	PGX_FLASH_LVP_COMMAND_TBLWR_POSTINC_2B		0b00001101
		#define	PGX_FLASH_LVP_COMMAND_TBLWR_START_POSTINC2	0b00001110
		#define	PGX_FLASH_LVP_COMMAND_TBLWR_START			0b00001111

		//---[ Tblptr Addresses ]---
		#define PGX_FLASH_LVP_TBLPTR_ADDRESS_U				0x6EF8		//<! Upper byte tblptr
		#define PGX_FLASH_LVP_TBLPTR_ADDRESS_H				0x6EF7		//<! High byte tblptr
		#define PGX_FLASH_LVP_TBLPTR_ADDRESS_L				0x6EF6		//<! Low byte tblptr

		//---[ Bulk Erase Area Memory IDentifier ]---
		#define PGX_FLASH_LVP_BULK_ERASE_CHIP				0xFF87		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_EEPROM				0x0084		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_BOOT				0x0081		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_FUSES				0x0082		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_CODE_0				0x0180		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_CODE_1				0x0280		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_CODE_2				0x0480		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_CODE_3				0x0880		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_CODE_4				0x1080		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_CODE_5				0x2080		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_CODE_6				0x4008		//<! High byte bulk erase identifier data
		#define PGX_FLASH_LVP_BULK_ERASE_CODE_7				0x8080		//<! High byte bulk erase identifier data
		
		//---[ Timing ]---									//not yet implemented (waiting accurate deley function)
		#define PGX_FLASH_LVP_TIMING_P3						1 , PGX_USEC	//<!  15[ns] min.
		#define PGX_FLASH_LVP_TIMING_P4						1 , PGX_USEC	//<!  15[ns] min.
		#define PGX_FLASH_LVP_TIMING_P5						1 , PGX_USEC	//<!  40[ns] min.
		#define PGX_FLASH_LVP_TIMING_P5A					1 , PGX_USEC	//<!  40[ns] min.
		#define PGX_FLASH_LVP_TIMING_P6						1 , PGX_USEC	//<!  20[ns] min.
		#define PGX_FLASH_LVP_TIMING_P9						2 , PGX_MSEC	//<!   1[ms] min.
		#define PGX_FLASH_LVP_TIMING_P10				  200 , PGX_USEC	//<! 100[us] min.
		#define PGX_FLASH_LVP_TIMING_P12					4 , PGX_USEC	//<!   2[us] min.
		#define PGX_FLASH_LVP_TIMING_P14					1 , PGX_USEC	//<!  10[ns] min.
		#define PGX_FLASH_LVP_TIMING_P15					4 , PGX_USEC	//<!   2[us] min.
		#define PGX_FLASH_LVP_TIMING_P16				  100 , PGX_USEC	//<!   0[s] min.
		#define PGX_FLASH_LVP_TIMING_P18				  100 , PGX_USEC	//<!   0[s] min.
		
	#endif
#endif



		
		// //---[ Bulk Erase Area Memory Identifier Data ]---
		// #define PGX_FLASH_LVP_BULK_ERASE_CHIP_HB				0xFF		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CHIP_LB				0x87		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_EEPROM_HB			0x00		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_EEPROM_LB			0x84		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_BOOT_HB				0x00		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_BOOT_LB				0x81		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_FUSES_HB			0x00		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_FUSES_LB			0x82		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_0_HB			0x01		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_0_LB			0x80		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_1_HB			0x02		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_1_LB			0x80		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_2_HB			0x04		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_2_LB			0x80		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_3_HB			0x08		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_3_LB			0x80		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_4_HB			0x10		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_4_LB			0x80		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_5_HB			0x20		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_5_LB			0x80		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_6_HB			0x40		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_6_LB			0x80		//<! Low  byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_7_HB			0x80		//<! High byte bulk erase identifier data
		// #define PGX_FLASH_LVP_BULK_ERASE_CODE_7_LB			0x80		//<! Low  byte bulk erase identifier data
		
		// //---[ Bulk Erase Area Memory Address ]---			//0x3C0004-0x3C0005
		// #define PGX_FLASH_LVP_BULK_ERASE_ADDRESS_HIGH_HB		0x3C		//<! High byte bulk erase high address
		// #define PGX_FLASH_LVP_BULK_ERASE_ADDRESS_HIGH_MB		0x00		//<! Mid  byte bulk erase high address
		// #define PGX_FLASH_LVP_BULK_ERASE_ADDRESS_HIGH_LB		0x05		//<! Low  byte bulk erase high address
		// #define PGX_FLASH_LVP_BULK_ERASE_ADDRESS_LOW_HB		0x3C		//<! High byte bulk erase low  address
		// #define PGX_FLASH_LVP_BULK_ERASE_ADDRESS_LOW_MB		0x00		//<! Mid  byte bulk erase low  address
		// #define PGX_FLASH_LVP_BULK_ERASE_ADDRESS_LOW_LB		0x04		//<! Low  byte bulk erase low  address
		
		// //---[ 16bit asm instruction ]---
		// #define PGX_FLASH_LVP_ASM_MOVLW						0x0E		//<! MOVLW hex code
		// #define PGX_FLASH_LVP_ASM_MOVLW_16					0x0E00		//<! MOVLW hex code
		// #define PGX_FLASH_LVP_ASM_MOVWF						0x6E		//<! MOVWF hex code ( 0x6F too || or ? )
		// #define PGX_FLASH_LVP_ASM_MOVWF_16					0x6E00		//<! MOVWF hex code ( 0x6F too || or ? )



