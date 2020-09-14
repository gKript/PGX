//
#ifndef _PGIMX_PROJECT_SETUP_PUBLIC_H_
	#define	_PGIMX_PROJECT_SETUP_PUBLIC_H_
	//------------------------------------------------------------------------
	//	P R O J E C T   D E T A I L S
	//------------------------------------------------------------------------
	#define PGX_PROJECT_NAME                    None						//!< Name of your Project
	#define PGX_PROJECT_ORGANIZATION			None						//!< Name of your Organization
	#define PGX_PROJECT_AUTHOR					None						//!< Your name || nickname
	#define PGX_PROJECT_VERSION_MAJOR			0							//!< Major version of your project
	#define PGX_PROJECT_VERSION_MINOR			0							//!< Minor version of your project
	#define PGX_PROJECT_STATE					PGX_RELEASE					//!< Must be: PGX_DEBUG  ||  PGX_RELEASE
	#define PGX_PROJECT_DATE					01/01/2019					//!< Date of the project
	//------------------------------------------------------------------------
	//	H A R D W A R E   C O N F I G   M A I N   S Y S T E M
	//------------------------------------------------------------------------
	#define PGX_CLOCK_HZ						40000000					//!< CORE FREQUENCY of the CPU in your project. Unit of measure is given in [Hz].  \note The working frequency is the \b CORE \b FREQUENCY of the \b MCU in your project. To set it correctly, consider the value of the \b oscillator/crystal and eventually of the \b PLL. Using a lower frequency than 4MHz, delay functions will be definitely inaccurate.
	#define PGX_USER_SUPPLY_MILLIVOLT			5000						//!< Power supply VOLTAGE of the MCU in your project. Unit of measure is given in [mV].
	#define PGX_USER_SUPPLY_BATTERY				PGX_NO						//!< Must be: PGX_YES  ||  PGX_NO
	#define PGX_USE_INTERNAL_OSC				PGX_DISABLE					//!< Must be: PGX_ENABLE  ||  PGX_DISABLE
	//------------------------------------------------------------------------
	//	S O F T W A R E   C O N F I G   M A I N   S Y S T E M
	//------------------------------------------------------------------------
	#define PGX_POWER_GOOD_DELAY				500							//!< Time delay [ms](16bit), waiting power supply is good, before initialize() PicGIM; Default is '500'.
	//------------------------------------------------------------------------	
	//	P I C G I M   B E H A V I O U R
	//------------------------------------------------------------------------
	#define PGX_VERBOSE							PGX_DISABLE					//!< Must be: PGX_ENABLE  ||  PGX_DISABLE
	#define PGX_SUGGESTION						PGX_DISABLE					//!< Must be: PGX_ENABLE  ||  PGX_DISABLE
	#define PGX_PROJECT_INFO_SHOW				PGX_DISABLE					//!< Must be: PGX_ENABLE  ||  PGX_DISABLE
	//------------------------------------------------------------------------
#endif /* _PGIMX_PROJECT_SETUP_PUBLIC_H_ */


