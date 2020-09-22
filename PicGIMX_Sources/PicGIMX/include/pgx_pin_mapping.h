//
#ifndef PGX_PIN_MAPPING_H
    #define	PGX_PIN_MAPPING_H


void pin_mode( _pgx_Uint8 p , _pgx_Uint8 status );
void pin_write( _pgx_Uint8 p , _pgx_Uint8 status );
_pgx_int8 pin_read( _pgx_Uint8 p );


	//------------------------------------------------------------------------
    #define _PIN_OUT(pin)        ( PIN##pin##_TRIS )
    #define _PIN_IN(pin)         ( PIN##pin##_PORT )
    #define _PIN_MODE(pin)       ( PIN##pin##_TRIS )
	//------------------------------------------------------------------------
	//		N U M E R I C   P I N   P O R T   M A P P I N G
	//------------------------------------------------------------------------
    #define PIN10_PORT          PORTAbits.RA0
    #define PIN11_PORT          PORTAbits.RA1
    #define PIN12_PORT          PORTAbits.RA2
    #define PIN13_PORT          PORTAbits.RA3
    #define PIN14_PORT          PORTAbits.RA4
    #define PIN15_PORT          PORTAbits.RA5
    #define PIN16_PORT          PORTAbits.RA6
    #define PIN17_PORT          PORTAbits.RA7
    //------------------------------------------------------------------------
    #define PIN20_PORT          PORTBbits.RB0
    #define PIN21_PORT          PORTBbits.RB1
    #define PIN22_PORT          PORTBbits.RB2
    #define PIN23_PORT          PORTBbits.RB3
    #define PIN24_PORT          PORTBbits.RB4
    #define PIN25_PORT          PORTBbits.RB5
    #define PIN26_PORT          PORTBbits.RB6
    #define PIN27_PORT          PORTBbits.RB7
    //------------------------------------------------------------------------
    #define PIN30_PORT          PORTCbits.RC0
    #define PIN31_PORT          PORTCbits.RC1
    #define PIN32_PORT          PORTCbits.RC2
    #define PIN33_PORT          PORTCbits.RC3
    #define PIN34_PORT          PORTCbits.RC4
    #define PIN35_PORT          PORTCbits.RC5
    #define PIN36_PORT          PORTCbits.RC6
    #define PIN37_PORT          PORTCbits.RC7
   //------------------------------------------------------------------------
    #define PIN40_PORT          PORTDbits.RD0
    #define PIN41_PORT          PORTDbits.RD1
    #define PIN42_PORT          PORTDbits.RD2
    #define PIN43_PORT          PORTDbits.RD3
    #define PIN44_PORT          PORTDbits.RD4
    #define PIN45_PORT          PORTDbits.RD5
    #define PIN46_PORT          PORTDbits.RD6
    #define PIN47_PORT          PORTDbits.RD7
    //------------------------------------------------------------------------
    #define PIN50_PORT          PORTEbits.RE0
    #define PIN51_PORT          PORTEbits.RE1
    #define PIN52_PORT          PORTEbits.RE2
    #define PIN53_PORT          PORTEbits.RE3
    #define PIN54_PORT          PORTEbits.RE4
    #define PIN55_PORT          PORTEbits.RE5
    #define PIN56_PORT          PORTEbits.RE6
    #define PIN57_PORT          PORTEbits.RE7
    //------------------------------------------------------------------------
    #define PIN60_PORT          PORTFbits.RF0
    #define PIN61_PORT          PORTFbits.RF1
    #define PIN62_PORT          PORTFbits.RF2
    #define PIN63_PORT          PORTFbits.RF3
    #define PIN64_PORT          PORTFbits.RF4
    #define PIN65_PORT          PORTFbits.RF5
    #define PIN66_PORT          PORTFbits.RF6
    #define PIN67_PORT          PORTFbits.RF7
//------------------------------------------------------------------------
    #define PIN70_PORT          PORTGbits.RG0
    #define PIN71_PORT          PORTGbits.RG1
    #define PIN72_PORT          PORTGbits.RG2
    #define PIN73_PORT          PORTGbits.RG3
    #define PIN74_PORT          PORTGbits.RG4
    #define PIN75_PORT          PORTGbits.RG5
    #define PIN76_PORT          PORTGbits.RG6
    #define PIN77_PORT          PORTGbits.RG7
   //------------------------------------------------------------------------
    #define PIN80_PORT          PORTHbits.RH0
    #define PIN81_PORT          PORTHbits.RH1
    #define PIN82_PORT          PORTHbits.RH2
    #define PIN83_PORT          PORTHbits.RH3
    #define PIN84_PORT          PORTHbits.RH4
    #define PIN85_PORT          PORTHbits.RH5
    #define PIN86_PORT          PORTHbits.RH6
    #define PIN87_PORT          PORTHbits.RH7
	//------------------------------------------------------------------------
	//		N U M E R I C   P I N   L A T   M A P P I N G
	//------------------------------------------------------------------------
    #define PIN10_LAT		   LATAbits.LATA0
    #define PIN11_LAT          LATAbits.LATA1
    #define PIN12_LAT          LATAbits.LATA2
    #define PIN13_LAT          LATAbits.LATA3
    #define PIN14_LAT          LATAbits.LATA4
    #define PIN15_LAT          LATAbits.LATA5
    #define PIN16_LAT          LATAbits.LATA6
    #define PIN17_LAT          LATAbits.LATA7
    //------------------------------------------------------------------------
    #define PIN20_LAT          LATBbits.LATB0
    #define PIN21_LAT          LATBbits.LATB1
    #define PIN22_LAT          LATBbits.LATB2
    #define PIN23_LAT          LATBbits.LATB3
    #define PIN24_LAT          LATBbits.LATB4
    #define PIN25_LAT          LATBbits.LATB5
    #define PIN26_LAT          LATBbits.LATB6
    #define PIN27_LAT          LATBbits.LATB7
    //------------------------------------------------------------------------
    #define PIN30_LAT          LATCbits.LATC0
    #define PIN31_LAT          LATCbits.LATC1
    #define PIN32_LAT          LATCbits.LATC2
    #define PIN33_LAT          LATCbits.LATC3
    #define PIN34_LAT          LATCbits.LATC4
    #define PIN35_LAT          LATCbits.LATC5
    #define PIN36_LAT          LATCbits.LATC6
    #define PIN37_LAT          LATCbits.LATC7
   //------------------------------------------------------------------------
    #define PIN40_LAT          LATDbits.LATD0
    #define PIN41_LAT          LATDbits.LATD1
    #define PIN42_LAT          LATDbits.LATD2
    #define PIN43_LAT          LATDbits.LATD3
    #define PIN44_LAT          LATDbits.LATD4
    #define PIN45_LAT          LATDbits.LATD5
    #define PIN46_LAT          LATDbits.LATD6
    #define PIN47_LAT          LATDbits.LATD7
    //------------------------------------------------------------------------
    #define PIN50_LAT          LATEbits.LATE0
    #define PIN51_LAT          LATEbits.LATE1
    #define PIN52_LAT          LATEbits.LATE2
    #define PIN53_LAT          LATEbits.LATE3
    #define PIN54_LAT          LATEbits.LATE4
    #define PIN55_LAT          LATEbits.LATE5
    #define PIN56_LAT          LATEbits.LATE6
    #define PIN57_LAT          LATEbits.LATE7
    //------------------------------------------------------------------------
    #define PIN60_LAT          LATFbits.LATF0
    #define PIN61_LAT          LATFbits.LATF1
    #define PIN62_LAT          LATFbits.LATF2
    #define PIN63_LAT          LATFbits.LATF3
    #define PIN64_LAT          LATFbits.LATF4
    #define PIN65_LAT          LATFbits.LATF5
    #define PIN66_LAT          LATFbits.LATF6
    #define PIN67_LAT          LATFbits.LATF7
	//------------------------------------------------------------------------
	#define PIN70_LAT          LATGbits.LATG0
    #define PIN71_LAT          LATGbits.LATG1
    #define PIN72_LAT          LATGbits.LATG2
    #define PIN73_LAT          LATGbits.LATG3
    #define PIN74_LAT          LATGbits.LATG4
    #define PIN75_LAT          LATGbits.LATG5
    #define PIN76_LAT          LATGbits.LATG6
    #define PIN77_LAT          LATGbits.LATG7
    //------------------------------------------------------------------------
	#define PIN80_LAT          LATHbits.LATH0
    #define PIN81_LAT          LATHbits.LATH1
    #define PIN82_LAT          LATHbits.LATH2
    #define PIN83_LAT          LATHbits.LATH3
    #define PIN84_LAT          LATHbits.LATH4
    #define PIN85_LAT          LATHbits.LATH5
    #define PIN86_LAT          LATHbits.LATH6
    #define PIN87_LAT          LATHbits.LATH7
	//------------------------------------------------------------------------
	//		N U M E R I C   P I N   T R I S   M A P P I N G
	//------------------------------------------------------------------------
    #define PIN10_TRIS		    TRISAbits.TRISA0
    #define PIN11_TRIS          TRISAbits.TRISA1
    #define PIN12_TRIS          TRISAbits.TRISA2
    #define PIN13_TRIS          TRISAbits.TRISA3
    #define PIN14_TRIS          TRISAbits.TRISA4
    #define PIN15_TRIS          TRISAbits.TRISA5
    #define PIN16_TRIS          TRISAbits.TRISA6
    #define PIN17_TRIS          TRISAbits.TRISA7
    //------------------------------------------------------------------------
    #define PIN20_TRIS          TRISBbits.TRISB0
    #define PIN21_TRIS          TRISBbits.TRISB1
    #define PIN22_TRIS          TRISBbits.TRISB2
    #define PIN23_TRIS          TRISBbits.TRISB3
    #define PIN24_TRIS          TRISBbits.TRISB4
    #define PIN25_TRIS          TRISBbits.TRISB5
    #define PIN26_TRIS          TRISBbits.TRISB6
    #define PIN27_TRIS          TRISBbits.TRISB7
    //------------------------------------------------------------------------
    #define PIN30_TRIS          TRISCbits.TRISC0
    #define PIN31_TRIS          TRISCbits.TRISC1
    #define PIN32_TRIS          TRISCbits.TRISC2
    #define PIN33_TRIS          TRISCbits.TRISC3
    #define PIN34_TRIS          TRISCbits.TRISC4
    #define PIN35_TRIS          TRISCbits.TRISC5
    #define PIN36_TRIS          TRISCbits.TRISC6
    #define PIN37_TRIS          TRISCbits.TRISC7
   //------------------------------------------------------------------------
    #define PIN40_TRIS          TRISDbits.TRISD0
    #define PIN41_TRIS          TRISDbits.TRISD1
    #define PIN42_TRIS          TRISDbits.TRISD2
    #define PIN43_TRIS          TRISDbits.TRISD3
    #define PIN44_TRIS          TRISDbits.TRISD4
    #define PIN45_TRIS          TRISDbits.TRISD5
    #define PIN46_TRIS          TRISDbits.TRISD6
    #define PIN47_TRIS          TRISDbits.TRISD7
    //------------------------------------------------------------------------
    #define PIN50_TRIS          TRISEbits.TRISE0
    #define PIN51_TRIS          TRISEbits.TRISE1
    #define PIN52_TRIS          TRISEbits.TRISE2
    #define PIN53_TRIS          TRISEbits.TRISE3
    #define PIN54_TRIS          TRISEbits.TRISE4
    #define PIN55_TRIS          TRISEbits.TRISE5
    #define PIN56_TRIS          TRISEbits.TRISE6
    #define PIN57_TRIS          TRISEbits.TRISE7
    //------------------------------------------------------------------------
    #define PIN60_TRIS          TRISFbits.TRISF0
    #define PIN61_TRIS          TRISFbits.TRISF1
    #define PIN62_TRIS          TRISFbits.TRISF2
    #define PIN63_TRIS          TRISFbits.TRISF3
    #define PIN64_TRIS          TRISFbits.TRISF4
    #define PIN65_TRIS          TRISFbits.TRISF5
    #define PIN66_TRIS          TRISFbits.TRISF6
    #define PIN67_TRIS          TRISFbits.TRISF7
	//------------------------------------------------------------------------
    #define PIN70_TRIS          TRISGbits.TRISG0
    #define PIN71_TRIS          TRISGbits.TRISG1
    #define PIN72_TRIS          TRISGbits.TRISG2
    #define PIN73_TRIS          TRISGbits.TRISG3
    #define PIN74_TRIS          TRISGbits.TRISG4
    #define PIN75_TRIS          TRISGbits.TRISG5
    #define PIN76_TRIS          TRISGbits.TRISG6
    #define PIN77_TRIS          TRISGbits.TRISG7
   //------------------------------------------------------------------------
    #define PIN80_TRIS          TRISHbits.TRISH0
    #define PIN81_TRIS          TRISHbits.TRISH1
    #define PIN82_TRIS          TRISHbits.TRISH2
    #define PIN83_TRIS          TRISHbits.TRISH3
    #define PIN84_TRIS          TRISHbits.TRISH4
    #define PIN85_TRIS          TRISHbits.TRISH5
    #define PIN86_TRIS          TRISHbits.TRISH6
    #define PIN87_TRIS          TRISHbits.TRISH7
	//------------------------------------------------------------------------
#endif	/* PGX_PIN_MAPPING_H */


