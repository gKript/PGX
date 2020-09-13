//
//#include "pgx_delay.h"
#include "pgx.h"

#if ( PGIMX_CAL_DELAY == PGX_ENABLE )

		void pgx_delay_msec( _pgx_Uint16 pgx_delay ) {
			//--------------------------------------------------------------------
			_pgx_Uint16 d;
			for( d = 0; d < pgx_delay; d++ ) {
				__delay_ms( 1 );
			}
			return;
		}

	// void pgx_delay_msec( _pgx_Uint16 pgx_delay ) {
		// //--------------------------------------------------------------------
		// _pgx_Uint16 d;
		// for( d = 0; d < ( pgx_delay * PGX_DELAY_CONST_1US * 1000 ); d++ ) {
			// asm("nop");
		// }
        // return;
	// }	
	
	void pgx_delay_usec( _pgx_Uint16 pgx_delay ) {
		//--------------------------------------------------------------------
		_pgx_Uint16 d;
		for( d = 0; d < pgx_delay; d++ ) {
			__delay_us( 1 );
		}
        return;
	}

	// void pgx_delay_usec( _pgx_Uint16 pgx_delay ) {
		// //--------------------------------------------------------------------
		// _pgx_Uint16 d;
		// for( d = 0; d < ( ( pgx_delay * PGX_DELAY_CONST_1US ) - PGX_DELAY_BALLAST ); d++ ) {
			// asm("nop");
		// }
        // return;
	// }
	
	//	__delay_ms( pgx_delay );
		//_delay( (unsigned long)( ( pgx_delay ) * ( _XTAL_FREQ / 4000.0) ) );
	
	// #if ( PGX_PROJECT_STATE == PGX_DEBUG )
		// #warning PicGIMX: This file is compiling...
	// #endif
	
	//(see xc8 pic18.h include)
	// #define pgx_delay_usec( x )	_delay( (unsigned long)( ( x ) * ( _XTAL_FREQ / 4000000.0) ) )
	// #define pgx_delay_msec( x )	_delay( (unsigned long)( ( x ) * ( _XTAL_FREQ / 4000.0) ) )
	// #define pgx_delay_sec( x )	_delay( (unsigned long)( ( x ) * ( _XTAL_FREQ / 4.0) ) )
	
	
	
		// void pgx_delay_NinstusCalc( ) {
			// pgx_ninstus = ( 0.000001 / ( 1.0 / ( ( PGX_CLOCK * 1000000 ) / PGX_TCYCLEPERI ) ) );
			// pgx_uninstus = ( 0.000001 / ( 1.0 / ( ( PGX_CLOCK * 1000000 ) / PGX_TCYCLEPERI ) ) ) / 2;
// //			pgx_ninstus = (_pgx_Uint8)( 0.000001 / ( 1.0 / ( ( PGX_CLOCK ) / PGX_TCYCLEPERI ) ) );     	//kmod
// //			pgx_uninstus = (_pgx_Uint8)( 0.000001 / ( 1.0 / ( ( PGX_CLOCK ) / PGX_TCYCLEPERI ) ) ) / 2;	//kmod
		// }

		// #if ( PGX_DELAY_SEC == PGX_INCLUDE )
			// void pgx_delay_sec( _pgx_Uint8 sec ) {
				// while( sec-- ) {
// //					__delay_sec( sec );			//kmod added... non accetta variabili, vuole solo const, quindi modificare
					// //	As for the delay function the correct for XC8 is to use __delay_ms(), or __delay_us().						//kmod added

					// Delay10KTCYx( ( ( pgx_ninstus * 20 ) + PGX_NINSTUS_OFFSET ) );							//ori
					// Delay10KTCYx( ( ( pgx_ninstus * 20 ) + PGX_NINSTUS_OFFSET ) );							//ori
					// Delay10KTCYx( ( ( pgx_ninstus * 20 ) + PGX_NINSTUS_OFFSET ) );							//ori
					// Delay10KTCYx( ( ( pgx_ninstus * 20 ) + PGX_NINSTUS_OFFSET ) );							//ori
					// Delay10KTCYx( ( pgx_ninstus * 20 ) );													//ori
				
// //					Delay10KTCYx( (unsigned char)( ( pgx_ninstus * 20 ) + ( PGX_NINSTUS_OFFSET / 10 ) ) );		//kmod added
// //					Delay10KTCYx( ( pgx_ninstus * 20 ) + ( PGX_NINSTUS_OFFSET / 10 ) );							//kmod added
// //					Delay10KTCYx( ( pgx_ninstus * 20 ) + ( PGX_NINSTUS_OFFSET / 10 ) );							//kmod added
// //					Delay10KTCYx( ( pgx_ninstus * 20 ) + ( PGX_NINSTUS_OFFSET / 10 ) );							//kmod added
// //					Delay10KTCYx( pgx_ninstus * 20 );
				// }
			// }
		// #endif
		
		 #if ( PGX_DELAY_SEC == PGX_INCLUDE )
			 void pgx_delay_sec( _pgx_Uint16 sec ) {
				 _pgx_Uint16 t;
                 
                 while( sec-- ) {
                     for( t = 0 ; t < 1000 ; t++) {
                         __delay_ms( 1 );
                     }
				 }
			 }
		 #endif

             
		// #if ( PGX_DELAY_MSEC == PGX_INCLUDE )
			// void pgx_delay_msec( _pgx_Uint16 msec ) {
				// while( msec-- ) {
// //					__delay_ms( msec );																			//kmod added
					// Delay10TCYx( pgx_ninstus * 20 );																//ori
					// Delay10TCYx( pgx_ninstus * 20 );																//ori
					// Delay10TCYx( pgx_ninstus * 20 );																//ori
					// Delay10TCYx( pgx_ninstus * 20 );																//ori
					// Delay10TCYx( pgx_ninstus * 20 );																//ori
				// }
			// }
		// #endif

		// #if ( PGX_DELAY_USEC == PGX_INCLUDE )
			// void pgx_delay_usec( _pgx_Uint16 tusec )  {
				// tusec /= 10;
				// while( tusec-- ) {
// //					__delay_us( tusec );																		//kmod added
					// Delay10TCYx( pgx_ninstus );																	//ori
				// }
			// }
		// #endif

		 #if ( PGX_DELAY == PGX_INCLUDE )
			 void	pgx_delay( _pgx_Uint16 req_delay , _pgx_Uint8 unit ) {
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
	// #endif
#endif


