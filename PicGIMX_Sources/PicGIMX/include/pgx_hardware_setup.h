//
#ifndef _PGIMX_HARDWARE_SETUP_H_
	#define	_PGIMX_HARDWARE_SETUP_H_
	//------------------------------------------------------------------------
	//	P R O J E C T   P O W E R   S U P P L Y   V O L T A G E   C H E C K   
	//------------------------------------------------------------------------
	#if ( PGX_USER_SUPPLY_MILLIVOLT == 0 )
		#warning PicGIMX: This is the first time you have compiled your project with PicGIMX. First of all you have to set the correct power supply value in "pgx_hardware_setup_public.h".
		#ifndef PGX_EXIT_ON_ERROR
			#define PGX_EXIT_ON_ERROR
		#endif
	#endif
	//------------------------------------------------------------------------
	#if ( PGX_USER_SUPPLY_MILLIVOLT > PGX_MCU_SUPPLY_VOLT_MAX )
		#warning PicGIMX: MCU power supply is greater than its maximum specification.
		#ifndef PGX_EXIT_ON_ERROR
			#define PGX_EXIT_ON_ERROR
		#endif
	#elseif( PGX_USER_SUPPLY_MILLIVOLT < PGX_MCU_SUPPLY_VOLT_MIN )
		#warning PicGIMX: MCU power supply is lower than the correct specification.
		#ifndef PGX_EXIT_ON_ERROR
			#define PGX_EXIT_ON_ERROR
		#endif
	#endif
	//------------------------------------------------------------------------
	//	P R O J E C T   C L O C K   C H E C K
	//------------------------------------------------------------------------
	#if ( PGX_CLOCK_HZ == 0 )
		#warning PicGIMX: This is the first time you have compiled your project with PicGIMX. First of all you have to set the correct frequency oscillator value in "pgx_hardware_setup_public.h".
		#ifndef PGX_EXIT_ON_ERROR
			#define PGX_EXIT_ON_ERROR
		#endif
	#endif
	//------------------------------------------------------------------------
	#if ( PGX_CLOCK_HZ > PGX_MAX_OSC_FREQ )
		#error PicGIMX: Frequency clock too high!
		#ifndef PGX_EXIT_ON_ERROR
			#define PGX_EXIT_ON_ERROR
		#endif
	#endif
	//------------------------------------------------------------------------
	//	S Y S T E M   C L O C K   S E T
	//------------------------------------------------------------------------
	#undef	_XTAL_FREQ	//XC8 user defined
	#define	_XTAL_FREQ	( PGX_CLOCK_HZ )
	#define PGX_CLOCK	( PGX_CLOCK_HZ / 1000000.0 )
	//------------------------------------------------------------------------
	//#define PGX_DELAY_CONST_1US	( _XTAL_FREQ / 4000000.0 )
	//#define PGX_DELAY_BALLAST	2
	//------------------------------------------------------------------------
#endif /* _PGIMX_HARDWARE_SETUP_H_ */


