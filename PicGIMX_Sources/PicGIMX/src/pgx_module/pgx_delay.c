//
#include "pgx.h"

#if ( PGX_PROJECT_STATE == PGX_DEBUG )
    #warning PGX >>> Message >>> This file is compiling...
#endif

#if ( PGIMX_CAL_DELAY == PGX_ENABLE )   //#if defined( __18CXX )

    _pgx_Uint8	pgx_ninstus = 0;

    //---[ Ninstus ]---
    void pg_delay_ninstus_calc( void ) {
        pgx_ninstus = (_pgx_Uint8)( 0.000001 / ( 1.0 / ( ( PGX_CLOCK * 1000000 ) / PGX_TCYCLEPERI ) ) );
    }
    //---[ END Ninstus ]---
    
    //---[ Delay ms ]---
    void pgx_delay_msec( _pgx_Uint16 pgx_delay ) {
        //--------------------------------------------------------------------
        _pgx_Uint16 d;
        for( d = 0; d < pgx_delay; d++ ) {
            __delay_ms( 1 );
        }
        return;
    }
    //---[ END Delay ms ]---
    
	//---[ Delay us ]---
	void pgx_delay_usec( _pgx_Uint16 pgx_delay ) {
		//--------------------------------------------------------------------
		_pgx_Uint16 d;
		for( d = 0; d < pgx_delay; d++ ) {
			__delay_us( 1 );
		}
        return;
	}
    //---[ END Delay us ]---
    
    //---[ Delay s ]---
	#if ( PGX_DELAY_SEC == PGX_INCLUDE )
		void pgx_delay_sec( _pgx_Uint16 sec ) {
            //--------------------------------------------------------------------
			_pgx_Uint16 t;
			 
			while( sec-- ) {
				for( t = 0 ; t < 1000 ; t++) {
					__delay_ms( 1 );
				}
			}
		}
	#endif
    //---[ END Delay s ]---

    //---[ Delay ]---
	#if ( PGX_DELAY == PGX_INCLUDE )
		void	pgx_delay( _pgx_Uint16 req_delay , _pgx_Uint8 unit ) {
            //--------------------------------------------------------------------
            #if ( PGX_DELAY_SEC == PGX_INCLUDE )
				if( unit == PGX_SEC )
					pgx_delay_sec( req_delay );
			#endif
			#if ( PGX_DELAY_MSEC == PGX_INCLUDE )
				if( unit == PGX_MSEC )
					pgx_delay_msec( req_delay );
			#endif
			#if ( PGX_DELAY_USEC == PGX_INCLUDE )
				if( unit == PGX_USEC )
					pgx_delay_usec( req_delay );
			#endif
		}
	#endif
    //---[ END Delay ]---
	
	// #if ( ( PGX_EVENTS == PGX_ENABLE ) && ( PGX_DELAY_HIGH_PRIORITY == PGX_INCLUDE ) )
		// void pgx_delay_high_priority( _pgx_Uint16 req_delay , _pgx_Uint8 unit ) {
			// _pgx_Uint8 GIE_state , PIE_state;
			// GIE_state = PGX_INTERRUPT_GLOBAL_ENABLE;
			// PIE_state = PGX_INTERRUPT_PERIPHERAL_ENABLE;
			// if( GIE_state )
				// pgx_event_set( PGX_EVENT_GLOBAL , PGX_DISABLE );
			// if( PIE_state )
				// pgx_event_set( PGX_EVENT_PERIPHERAL , PGX_DISABLE );
			// #if ( PGX_DELAY_SEC == PGX_INCLUDE )
				// if( unit == PGX_SEC )
					// pgx_delay_sec( req_delay );
			// #endif
			// #if ( PGX_DELAY_MSEC == PGX_INCLUDE )
				// if( unit == PGX_MSEC )
					// pgx_delay_msec( req_delay );
			// #endif
			// #if ( PGX_DELAY_USEC == PGX_INCLUDE )
				// if( unit == PGX_USEC )
					// pgx_delay_usec( req_delay );
			// #endif
			// if( GIE_state )
				// pgx_event_set( PGX_EVENT_GLOBAL , PGX_ENABLE );
			// if( PIE_state )
				// pgx_event_set( PGX_EVENT_PERIPHERAL , PGX_ENABLE );
		// }
	// #endif
#endif


