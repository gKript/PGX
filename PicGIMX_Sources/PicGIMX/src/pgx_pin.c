//
#include "pgx.h"

#include "pgx_custom_type.h"
#include "pgx_define.h"
#include "pgx_pin_mapping.h"

#if ( PGX_PROJECT_STATE == PGX_DEBUG )
	#warning	PGX >>> Message >>> This file is always compiled.
#endif

//---[ PGX Pin ]---
void digitalWrite( _pgx_int8 p , _pgx_int8 status ) {
    if ( status == PGX_HIGH ) {
        pin_mode( p , PGX_OUT );     //  Il mode è dentro all'if perchè così tocco il tris solo se devo fare qualcosa, se no non tocco nulla
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


void pin_mode( _pgx_Uint8 p , _pgx_Uint8 status ) {
    switch ( p ) {
//TRIS A
        case 10: {
            T_A0 = status;
            break;
		}
        case 11: {
            T_A1 = status;
            break;
		}
        case 12: {
            T_A2 = status;
            break;
		}
        case 13: {
            T_A3 = status;
            break;
		}
        case 14: {
            T_A4 = status;
            break;
		}
        case 15: {
            T_A5 = status;
            break;
		}
        case 16: {
            T_A6 = status;
            break;
		}
        case 17: {
            T_A7 = status;
            break;
		}

//TRIS B
        case 20: {
            T_B0 = status;
            break;
		}
        case 21: {
            T_B1 = status;
            break;
		}
        case 22: {
            T_B2 = status;
            break;
		}
        case 23: {
            T_B3 = status;
            break;
		}
        case 24: {
            T_B4 = status;
            break;
		}
        case 25: {
            T_B5 = status;
            break;
		}
        case 26: {
            T_B6 = status;
            break;
		}
        case 27: {
            T_B7 = status;
            break;
		}

//TRIS C
        case 30: {
            T_C0 = status;
            break;
		}
        case 31: {
            T_C1 = status;
            break;
		}
        case 32: {
            T_C2 = status;
            break;
		}
        case 33: {
            T_C3 = status;
            break;
		}
        case 34: {
            T_C4 = status;
            break;
		}
        case 35: {
            T_C5 = status;
            break;
		}
        case 36: {
            T_C6 = status;
            break;
		}
        case 37: {
            T_C7 = status;
            break;
		}

//TRIS D
        case 40: {
            T_D0 = status;
            break;
		}
        case 41: {
            T_D1 = status;
            break;
		}
        case 42: {
            T_D2 = status;
            break;
		}
        case 43: {
            T_D3 = status;
            break;
		}
        case 44: {
            T_D4 = status;
            break;
		}
        case 45: {
            T_D5 = status;
            break;
		}
        case 46: {
            T_D6 = status;
            break;
		}
        case 47: {
            T_D7 = status;
            break;
		}

//TRIS E
        case 50: {
            T_E0 = status;
            break;
		}
        case 51: {
            T_E1 = status;
            break;
		}
        case 52: {
            T_E2 = status;
            break;
		}
#ifndef __18F4620
        case 53: {
            T_E3 = status;
            break;
		}
        case 54: {
            T_E4 = status;
            break;
		}
        case 55: {
            T_E5 = status;
            break;
		}
        case 56: {
            T_E6 = status;
            break;
		}
        case 57: {
            T_E7 = status;
            break;
		}

//TRIS F
        case 60: {
            T_F0 = status;
            break;
		}
        case 61: {
            T_F1 = status;
            break;
		}
        case 62: {
            T_F2 = status;
            break;
		}
        case 63: {
            T_F3 = status;
            break;
		}
        case 64: {
            T_F4 = status;
            break;
		}
        case 65: {
            T_F5 = status;
            break;
		}
        case 66: {
            T_F6 = status;
            break;
		}
        case 67: {
            T_F7 = status;
            break;
		}

//TRIS G
        case 70: {
            T_G0 = status;
            break;
		}
        case 71: {
            T_G1 = status;
            break;
		}
        case 72: {
            T_G2 = status;
            break;
		}
        case 73: {
            T_G3 = status;
            break;
		}
        case 74: {
            T_G4 = status;
            break;
		}
        case 75: {
            T_G5 = status;
            break;
		}
        case 76: {
            T_G6 = status;
            break;
		}
        case 77: {
            T_G7 = status;
            break;
		}


//TRIS H
        case 80: {
            T_H0 = status;
            break;
		}
        case 81: {
            T_H1 = status;
            break;
		}
        case 82: {
            T_H2 = status;
            break;
		}
        case 83: {
            T_H3 = status;
            break;
		}
        case 84: {
            T_H4 = status;
            break;
		}
        case 85: {
            T_H5 = status;
            break;
		}
        case 86: {
            T_H6 = status;
            break;
		}
        case 87: {
            T_H7 = status;
            break;
		}
#endif
    }
}


void pin_write( _pgx_Uint8 p , _pgx_Uint8 status ) {
    pin_mode( p , PGX_OUT );

    switch ( p ) {
//LAT A
        case 10: {
            L_A0 = status;
            break;
		}
        case 11: {
            L_A1 = status;
            break;
		}
        case 12: {
            L_A2 = status;
            break;
		}
        case 13: {
            L_A3 = status;
            break;
		}
        case 14: {
            L_A4 = status;
            break;
		}
        case 15: {
            L_A5 = status;
            break;
		}
        case 16: {
            L_A6 = status;
            break;
		}
        case 17: {
            L_A7 = status;
            break;
		}

//LAT B
        case 20: {
            L_B0 = status;
            break;
		}
        case 21: {
            L_B1 = status;
            break;
		}
        case 22: {
            L_B2 = status;
            break;
		}
        case 23: {
            L_B3 = status;
            break;
		}
        case 24: {
            L_B4 = status;
            break;
		}
        case 25: {
            L_B5 = status;
            break;
		}
        case 26: {
            L_B6 = status;
            break;
		}
        case 27: {
            L_B7 = status;
            break;
		}

//LAT C
        case 30: {
            L_C0 = status;
            break;
		}
        case 31: {
            L_C1 = status;
            break;
		}
        case 32: {
            L_C2 = status;
            break;
		}
        case 33: {
            L_C3 = status;
            break;
		}
        case 34: {
            L_C4 = status;
            break;
		}
        case 35: {
            L_C5 = status;
            break;
		}
        case 36: {
            L_C6 = status;
            break;
		}
        case 37: {
            L_C7 = status;
            break;
		}

//LAT D
        case 40: {
            L_D0 = status;
            break;
		}
        case 41: {
            L_D1 = status;
            break;
		}
        case 42: {
            L_D2 = status;
            break;
		}
        case 43: {
            L_D3 = status;
            break;
		}
        case 44: {
            L_D4 = status;
            break;
		}
        case 45: {
            L_D5 = status;
            break;
		}
        case 46: {
            L_D6 = status;
            break;
		}
        case 47: {
            L_D7 = status;
            break;
		}

//LAT E
        case 50: {
            L_E0 = status;
            break;
		}
        case 51: {
            L_E1 = status;
            break;
		}
        case 52: {
            L_E2 = status;
            break;
		}
#ifndef __18F4620
        case 53: {
            L_E3 = status;
            break;
		}
        case 54: {
            L_E4 = status;
            break;
		}
        case 55: {
            L_E5 = status;
            break;
		}
        case 56: {
            L_E6 = status;
            break;
		}
        case 57: {
            L_E7 = status;
            break;
		}

//LAT F
        case 60: {
            L_F0 = status;
            break;
		}
        case 61: {
            L_F1 = status;
            break;
		}
        case 62: {
            L_F2 = status;
            break;
		}
        case 63: {
            L_F3 = status;
            break;
		}
        case 64: {
            L_F4 = status;
            break;
		}
        case 65: {
            L_F5 = status;
            break;
		}
        case 66: {
            L_F6 = status;
            break;
		}
        case 67: {
            L_F7 = status;
            break;
		}

//LAT G
        case 70: {
            L_G0 = status;
            break;
		}
        case 71: {
            L_G1 = status;
            break;
		}
        case 72: {
            L_G2 = status;
            break;
		}
        case 73: {
            L_G3 = status;
            break;
		}
        case 74: {
            L_G4 = status;
            break;
		}
        case 75: {
            L_G5 = status;
            break;
		}
        case 76: {
            L_G6 = status;
            break;
		}
        case 77: {
            L_G7 = status;
            break;
		}


//LAT H
        case 80: {
            L_G0 = status;
            break;
		}
        case 81: {
            L_G1 = status;
            break;
		}
        case 82: {
            L_G2 = status;
            break;
		}
        case 83: {
            L_G3 = status;
            break;
		}
        case 84: {
            L_G4 = status;
            break;
		}
        case 85: {
            L_G5 = status;
            break;
		}
        case 86: {
            L_G6 = status;
            break;
		}
        case 87: {
            L_G7 = status;
            break;
		}
#endif
    }
}


_pgx_int8 pin_read( _pgx_Uint8 p ) {
    
    pin_mode( p , PGX_IN );
    
    switch ( p ) {
//PORT A
        case 10: {
            return P_A0;
		}
        case 11: {
            return P_A1;
		}
        case 12: {
            return P_A2;
		}
        case 13: {
            return P_A3;
		}
        case 14: {
            return P_A4;
		}
        case 15: {
            return P_A5;
		}
        case 16: {
            return P_A6;
		}
        case 17: {
            return P_A7;
		}

//PORT B
        case 20: {
            return P_B0;
		}
        case 21: {
            return P_B1;
		}
        case 22: {
            return P_B2;
		}
        case 23: {
            return P_B3;
		}
        case 24: {
            return P_B4;
		}
        case 25: {
            return P_B5;
		}
        case 26: {
            return P_B6;
		}
        case 27: {
            return P_B7;
		}

//PORT C
        case 30: {
            return P_C0;
		}
        case 31: {
            return P_C1;
		}
        case 32: {
            return P_C2;
		}
        case 33: {
            return P_C3;
		}
        case 34: {
            return P_C4;
		}
        case 35: {
            return P_C5;
		}
        case 36: {
            return P_C6;
		}
        case 37: {
            return P_C7;
		}

//PORT D
        case 40: {
            return P_D0;
		}
        case 41: {
            return P_D1;
		}
        case 42: {
            return P_D2;
		}
        case 43: {
            return P_D3;
		}
        case 44: {
            return P_D4;
		}
        case 45: {
            return P_D5;
		}
        case 46: {
            return P_D6;
		}
        case 47: {
            return P_D7;
		}

//PORT E
        case 50: {
            return P_E0;
		}
        case 51: {
            return P_E1;
		}
        case 52: {
            return P_E2;
		}
#ifndef __18F4620
        case 53: {
            return P_E3;
		}
        case 54: {
            return P_E4;
		}
        case 55: {
            return P_E5;
		}
        case 56: {
            return P_E6;
		}
        case 57: {
            return P_E7;
		}

//PORT F
        case 60: {
            return P_F0;
		}
        case 61: {
            return P_F1;
		}
        case 62: {
            return P_F2;
		}
        case 63: {
            return P_F3;
		}
        case 64: {
            return P_F4;
		}
        case 65: {
            return P_F5;
		}
        case 66: {
            return P_F6;
		}
        case 67: {
            return P_F7;
		}

//PORT G
        case 70: {
            return P_G0;
		}
        case 71: {
            return P_G1;
		}
        case 72: {
            return P_G2;
		}
        case 73: {
            return P_G3;
		}
        case 74: {
            return P_G4;
		}
        case 75: {
            return P_G5;
		}
        case 76: {
            return P_G6;
		}
        case 77: {
            return P_G7;
		}

//PORT H
        case 80: {
            return P_G0;
		}
        case 81: {
            return P_G1;
		}
        case 82: {
            return P_G2;
		}
        case 83: {
            return P_G3;
		}
        case 84: {
            return P_G4;
		}
        case 85: {
            return P_G5;
		}
        case 86: {
            return P_G6;
		}
        case 87: {
            return P_G7;
		}
#endif
    }
}

/*
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


*/

