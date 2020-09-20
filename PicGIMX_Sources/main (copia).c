#include "pgx.h"

void pin_mode( _pgx_Uint8 p , _pgx_Uint8 status ) {
    switch ( p ) {
        case 20:
            T_B0 = status;
            break;
        case 22:
            T_B2 = status;
            break;
    }
}

void pin_write( _pgx_Uint8 p , _pgx_Uint8 status ) {
    switch ( p ) {
        case 20:
            L_B0 = status;
            break;
        case 22:
            L_B2 = status;
            break;
    }
}

_pgx_Uint8 pin_read( _pgx_Uint8 p ) {
    _pgx_Uint8 status;
    
    switch ( p ) {
        case 20:
            status = P_B0;
            break;
        case 22:
            status = P_B2;
            break;
    }
    return( status );
}

void digitalWrite( _pgx_int8 p , _pgx_int8 status ) {
    if ( status == PGX_HIGH ) {
        pin_mode( p , PGX_OUT );    //  Il mode è dentro all'if perchè così tocco il tris solo se devo fare qualcosa, se no non tocco nulla
        pin_write( p , PGX_HIGH );
    }
    else if ( status == PGX_LOW ) {
        pin_mode( p , PGX_OUT );
        pin_write( p , PGX_LOW );
    }
}

_pgx_int8 digitalRead( _pgx_int8 p ) {
    return( pin_read( p ) );
}

void main( void ) {
	pgx_initialize( );
    
    pgx_loop {
        if ( digitalRead( 22 ) ) {
            digitalWrite( 20 , PGX_HIGH );
            pgx_delay_msec( 200 );
            digitalWrite( 20 , PGX_LOW );
            pgx_delay_msec( 200 );
        }
    }
    
    PGX_HALT;
}



