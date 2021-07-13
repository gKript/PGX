//
#include "pgx.h"

#if ( PGIM_FLASH == PGX_ENABLE )

	#if	( PGX_PROJECT_STATE == PGX_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	//--------------------------------------------------------------------------
	// Read from program memory are performed one byte at a time.
	// Programming and erasing are performed by block, i.e. 32 word or 64 bytes.
	// See device manual for block size and define them in .h.
	// Istruction must be aligned (odd and even) to word, no matters for data.
	//--------------------------------------------------------------------------
	
	//---[ Set Table Pointer Flash ]---
	void pgx_flash_set_table_pointer( _pgx_Uint32 pgx_ptr_address ) {
		//--------------------------------------------------------------------------
		_pgx_Uint32_VAL	address;
		
		address.val = pgx_ptr_address;
		
		TBLPTRU	= address.byte.UB;			// Set Table Pointer Address, UPPER Byte
		TBLPTRH	= address.byte.HB;			// Set Table Pointer Address, HIGHER Byte
		TBLPTRL	= address.byte.LB;			// Set Table Pointer Address, LOWER Byte
	}
	
	//---[ Execute Flash ]---
	void pgx_flash_execute( void ) {
		//--------------------------------------------------------------------------
		_pgx_Uint8	flag_irq;
		
		flag_irq = 0;
		
		EECON1bits.EEPGD = 1;				// Point to flash program memory
		EECON1bits.CFGS = 0;       			// Access flash program memory
		EECON1bits.WREN = 1;				// Enable write to memory
		if( INTCONbits.GIE ) {				// Disable IRQ, if enabled
			INTCONbits.GIE = 0;
			flag_irq = 0x01;
		}
		EECON2 = 0x55;						// Required sequence
		EECON2 = 0xAA;						// Required sequence
		EECON1bits.WR = 1;					// Start erase (CPU stall) (Required sequence end)
		if( flag_irq ) {					// Restore IRQ, if enabled
			INTCONbits.GIE = 1;
			flag_irq = 0x00;
		}
	}
	
	//---[ Read Flash ]---
	void pgx_flash_read( _pgx_Uint32 pgx_address_start , _pgx_Uint32 pgx_byte_number , _pgx_Uint8 * pgx_buffer_read ) {
		//--------------------------------------------------------------------------
		_pgx_Uint32	n;
		
		pgx_flash_set_table_pointer( pgx_address_start );
		for( n = 0 ; n < pgx_byte_number ; n++ ) {
			_asm TBLRDPOSTINC _endasm
			*( pgx_buffer_read + n ) = TABLAT;
		}
	}

	//---[ Erase Flash ]---
	void pgx_flash_erase( _pgx_Uint32 pgx_address_start , _pgx_Uint16 pgx_erase_block_number ) {
		//--------------------------------------------------------------------------
		_pgx_Uint16	n;
		
		for( n = 0 ; n < pgx_erase_block_number ; n++ ) {
			pgx_flash_set_table_pointer( pgx_address_start + ( PGX_FLASH_SIZE_ERASE_BLOCK * n ) );
			EECON1bits.FREE = 1;			// Enable block Erase operation
			pgx_flash_execute( );
		}
	}

	//---[ Write Block Flash ]---
	void pgx_flash_write_block( _pgx_Uint32 pgx_address_start , _pgx_Uint16 pgx_write_block_number , _pgx_Uint8 * pgx_buffer_write ) {
		//--------------------------------------------------------------------------
		_pgx_Uint16	n;
		_pgx_Uint8	holding_reg;
		
		for( n = 0 ; n < pgx_write_block_number ; n++ ) {
			pgx_flash_set_table_pointer( pgx_address_start + ( PGX_FLASH_SIZE_WRITE_BLOCK * n ) );
			holding_reg = PGX_FLASH_SIZE_WRITE_BLOCK;
			while( holding_reg-- ) {		// Fill holding registers
				TABLAT = *( pgx_buffer_write++ );
				_asm TBLWTPOSTINC _endasm
			}
			_asm TBLRDPOSTDEC _endasm		// tblptr - 1 to return in the right block
			pgx_flash_execute( );
			//############################################################################################
			//############################################################################################
			//pgx_buffer_write -= PGX_FLASH_SIZE_WRITE_BLOCK;			//2rm only for debug!!!!!!!!!!!!!!!!!!
			//############################################################################################
			//############################################################################################
		}
	}

	//---[ Write Word Flash ]---
	void pgx_flash_write_word( _pgx_Uint32 pgx_address_word , _pgx_Uint16 pgx_data ) {
		//--------------------------------------------------------------------------
		_pgx_Uint16_VAL	data;
		
		data.val = pgx_data;
		
		pgx_flash_set_table_pointer( pgx_address_word );
		TABLAT = data.byte.LB;
		_asm TBLWTPOSTINC _endasm			// Store low byte
		TABLAT = data.byte.HB;
		_asm TBLWT _endasm					// Store high byte
		pgx_flash_execute( );
	}

	//todo:	write ID loc https://microchipdeveloper.com/faq:35

#endif
 
 
