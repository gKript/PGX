//
#ifndef _PGIMX_DELAY_H_
	#define _PGIMX_DELAY_H_
	//------------------------------------------------------------------------
    #include <pic18.h>
	#include "pgx_custom_type.h"
	
	void pgx_delay_usec     ( _pgx_Uint16 pgx_delay );
	void pgx_delay_msec     ( _pgx_Uint16 pgx_delay );
    void pgx_delay_sec      ( _pgx_Uint16 sec );
    void pgx_delay          ( _pgx_Uint16 req_delay , _pgx_Uint8 unit );
#endif /* _PGIMX_DELAY_H_ */


