
#ifndef PGX_PIN_MAPPING_H
    #define	PGX_PIN_MAPPING_H

    #define GET_PIN_OUT(pin)        ( PIN##pin##_LAT )
    #define GET_PIN_IN(pin)         ( PIN##pin##_PORT )
    #define GET_PIN_MODE(pin)       ( PIN##pin##_TRIS )

	//------------------------------------------------------------------------
	#define	PN_D0				25
	#define	PN_D1				26
	#define	PN_D2				27
	#define	PN_D3				28
	#define	PN_D4				29
	#define	PN_D5				30
	#define	PN_D6				31
	#define	PN_D7				32

    #define PIN40_PORT          PORTDbits.RD0
    #define PIN41_PORT          PORTDbits.RD1
    #define PIN42_PORT          PORTDbits.RD2
    #define PIN43_PORT          PORTDbits.RD3
    #define PIN44_PORT          PORTDbits.RD4
    #define PIN45_PORT          PORTDbits.RD5
    #define PIN46_PORT          PORTDbits.RD6
    #define PIN47_PORT          PORTDbits.RD7
    
    #define PIN40_LAT           LATDbits.LATD0
    #define PIN41_LAT           LATDbits.LATD1
    #define PIN42_LAT           LATDbits.LATD2
    #define PIN43_LAT           LATDbits.LATD3
    #define PIN44_LAT           LATDbits.LATD4
    #define PIN45_LAT           LATDbits.LATD5
    #define PIN46_LAT           LATDbits.LATD6
    #define PIN47_LAT           LATDbits.LATD7

    #define PIN40_TRIS          TRISDbits.TRISD0
    #define PIN41_TRIS          TRISDbits.TRISD1
    #define PIN42_TRIS          TRISDbits.TRISD2
    #define PIN43_TRIS          TRISDbits.TRISD3
    #define PIN44_TRIS          TRISDbits.TRISD4
    #define PIN45_TRIS          TRISDbits.TRISD5
    #define PIN46_TRIS          TRISDbits.TRISD6
    #define PIN47_TRIS          TRISDbits.TRISD7
    

#endif	/* PGX_PIN_MAPPING_H */

