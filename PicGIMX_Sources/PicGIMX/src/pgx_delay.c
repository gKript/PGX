//
#include "pgx.h"

#if ( PGIMX_CAL_DELAY == PGX_ENABLE )

    #if ( PGX_DELAY_SEC == PGX_INCLUDE )
        void pgx_delay_msec( _pgx_Uint16 pgx_delay ) {
            //--------------------------------------------------------------------
            _pgx_Uint16 d;
            for( d = 0; d < pgx_delay; d++ ) {
                __delay_ms( 1 );
            }
            return;
        }
    #endif

    #if ( PGX_DELAY_SEC == PGX_INCLUDE )
        void pgx_delay_usec( _pgx_Uint16 pgx_delay ) {
            //--------------------------------------------------------------------
            _pgx_Uint16 d;
            for( d = 0; d < pgx_delay; d++ ) {
                __delay_us( 1 );
            }
            return;
        }
    #endif
    
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

    #if ( PGX_DELAY == PGX_INCLUDE )
        void	pgx_delay( _pgx_Uint16 pgx_delay , _pgx_Uint8 pgx_unit ) {
            #if ( PGX_DELAY_SEC == PGX_INCLUDE )
                if( pgx_unit == PGX_SEC )
                    pgx_delay_sec( pgx_delay );
            #endif
            #if ( PGX_DELAY_MSEC == PGX_INCLUDE )
                if( pgx_unit == PGX_MSEC )
                    pgx_delay_msec( pgx_delay );
            #endif
            #if ( PGX_DELAY_USEC == PGX_INCLUDE )
                if( pgx_unit == PGX_USEC )
                    pgx_delay_usec( pgx_delay );
            #endif
        }
    #endif
		
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
    //#endif
#endif


