//
#ifndef _PGIMX_DELAY_H_
	#define _PGIMX_DELAY_H_
	//------------------------------------------------------------------------
    #include <pic18.h>
	#include "pgx_custom_type.h"
	//------------------------------------------------------------------------
    extern _pgx_Uint8	pgx_ninstus;		//!< The number of instruction in a usec
	//------------------------------------------------------------------------
    void pg_delay_ninstus_calc  ( void );
	void pgx_delay_usec         ( _pgx_Uint16 pgx_delay );
	void pgx_delay_msec         ( _pgx_Uint16 pgx_delay );
    void pgx_delay_sec          ( _pgx_Uint16 sec );
    void pgx_delay              ( _pgx_Uint16 req_delay , _pgx_Uint8 unit );
    //------------------------------------------------------------------------
#endif /* _PGIMX_DELAY_H_ */


