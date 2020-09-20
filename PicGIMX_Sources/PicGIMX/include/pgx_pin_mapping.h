
#ifndef PGX_PIN_MAPPING_H
    #define	PGX_PIN_MAPPING_H

    #define PIN_BIT(pin)            ( PIN##pin##_BIT )
    #define PIN_PORT(pin)           ( PIN##pin##_PORT )
    #define PIN_LAT(pin)            ( PIN##pin##_LAT )
    #define PIN_TRIS(pin)           ( PIN##pin##_TRIS )
    
    #define GET_PIN_OUT(pin)        ( PIN_LAT(pin)##PIN_BIT(pin) )
    #define GET_PIN_IN(pin)         ( PIN_PORT(pin)##PIN_BIT(pin) )
    #define GET_PIN_MODE(pin)       ( PIN_TRIS(pin)##PIN_BIT(pin) )

	//------------------------------------------------------------------------
	#define	PN_D0				25
	#define	PN_D1				26
	#define	PN_D2				27
	#define	PN_D3				28
	#define	PN_D4				29
	#define	PN_D5				30
	#define	PN_D6				31
	#define	PN_D7				32

    #define PIN40_BIT           0
    #define PIN41_BIT           1
    #define PIN42_BIT           2
    #define PIN43_BIT           3
    #define PIN44_BIT           4
    #define PIN45_BIT           5
    #define PIN46_BIT           6
    #define PIN47_BIT           7

    #define PIN40_PORT          PORTDbits.RD
    #define PIN41_PORT          PORTDbits.RD
    #define PIN42_PORT          PORTDbits.RD
    #define PIN43_PORT          PORTDbits.RD
    #define PIN44_PORT          PORTDbits.RD
    #define PIN45_PORT          PORTDbits.RD
    #define PIN46_PORT          PORTDbits.RD
    #define PIN47_PORT          PORTDbits.RD
    
    #define PIN40_LAT           LATDbits.LATD
    #define PIN41_LAT           LATDbits.LATD
    #define PIN42_LAT           LATDbits.LATD
    #define PIN43_LAT           LATDbits.LATD
    #define PIN44_LAT           LATDbits.LATD
    #define PIN45_LAT           LATDbits.LATD
    #define PIN46_LAT           LATDbits.LATD
    #define PIN47_LAT           LATDbits.LATD
    
    #define PIN40_TRIS          TRISDbits.TRISD
    #define PIN41_TRIS          TRISDbits.TRISD
    #define PIN42_TRIS          TRISDbits.TRISD
    #define PIN43_TRIS          TRISDbits.TRISD
    #define PIN44_TRIS          TRISDbits.TRISD
    #define PIN45_TRIS          TRISDbits.TRISD
    #define PIN46_TRIS          TRISDbits.TRISD
    #define PIN47_TRIS          TRISDbits.TRISD
    

#endif	/* PGX_PIN_MAPPING_H */

