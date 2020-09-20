//
#ifndef _PGIMX_CUSTOM_TYPE_H_
	#define _PGIMX_CUSTOM_TYPE_H_
	//------------------------------------------------------------------------
	#define	_pgx_Font						const _pgx_Uint8
	//------------------------------------------------------------------------
	typedef enum _BOOL { FALSE = 0 , TRUE } BOOL;
	typedef BOOL							_pgx_bool;
	//------------------------------------------------------------------------
	typedef char							_pgx_int8;
	typedef unsigned char					_pgx_Uint8;
	typedef int								_pgx_int16;
	typedef unsigned int					_pgx_Uint16;
    typedef __int24							_pgx_int24;     //not standard
    typedef __uint24						_pgx_Uint24;	//not standard
	typedef long							_pgx_int32;
	typedef unsigned long					_pgx_Uint32;
	typedef float							_pgx_float;
	//------------------------------------------------------------------------
	typedef	char *							_pgx_buffer;
	typedef	unsigned char *					_pgx_Ubuffer;
	//------------------------------------------------------------------------
	//	8   B I T   U N I O N
	//------------------------------------------------------------------------
	typedef union _pgx_Uint8_UNION {
		unsigned char val;
		struct {
			unsigned char b0:1;
			unsigned char b1:1;
			unsigned char b2:1;
			unsigned char b3:1;
			unsigned char b4:1;
			unsigned char b5:1;
			unsigned char b6:1;
			unsigned char b7:1;
			} bit;
	} BYTE_VAL;
	typedef BYTE_VAL						_pgx_Uint8_VAL;
	typedef BYTE_VAL						_pgx_Uint8_BIT;
	//------------------------------------------------------------------------
	//	16   B I T   U N I O N
	//------------------------------------------------------------------------
	typedef union _pgx_Uint16_UNION {
		unsigned int val;
		unsigned char v[ 2 ];
		struct {
			unsigned char LB;
			unsigned char HB;
		} byte;
		struct {
			unsigned char b0:1;
			unsigned char b1:1;
			unsigned char b2:1;
			unsigned char b3:1;
			unsigned char b4:1;
			unsigned char b5:1;
			unsigned char b6:1;
			unsigned char b7:1;
			unsigned char b8:1;
			unsigned char b9:1;
			unsigned char b10:1;
			unsigned char b11:1;
			unsigned char b12:1;
			unsigned char b13:1;
			unsigned char b14:1;
			unsigned char b15:1;
		} bit;
	} WORD_VAL;
	typedef WORD_VAL						_pgx_Uint16_VAL;
	typedef WORD_VAL						_pgx_Uint16_BYTE;
	typedef WORD_VAL						_pgx_Uint16_BIT;
	//------------------------------------------------------------------------
	//	24   B I T   U N I O N
	//------------------------------------------------------------------------
	typedef union _pgx_Uint24_UNION{
		unsigned char val[ 3 ];
		struct {
			unsigned char LB;
			unsigned char MB;
			unsigned char HB;
		} byte;
		struct {
			unsigned char b0:1;
			unsigned char b1:1;
			unsigned char b2:1;
			unsigned char b3:1;
			unsigned char b4:1;
			unsigned char b5:1;
			unsigned char b6:1;
			unsigned char b7:1;
			unsigned char b8:1;
			unsigned char b9:1;
			unsigned char b10:1;
			unsigned char b11:1;
			unsigned char b12:1;
			unsigned char b13:1;
			unsigned char b14:1;
			unsigned char b15:1;
			unsigned char b16:1;
			unsigned char b17:1;
			unsigned char b18:1;
			unsigned char b19:1;
			unsigned char b20:1;
			unsigned char b21:1;
			unsigned char b22:1;
			unsigned char b23:1;
		}bit;
	} SHORTLONG_VAL;
	typedef SHORTLONG_VAL					_pgx_Uint24_VAL;
	typedef SHORTLONG_VAL					_pgx_Uint24_BYTE;
	typedef SHORTLONG_VAL					_pgx_Uint24_BIT;
	//------------------------------------------------------------------------
	//	32   B I T   U N I O N
	//------------------------------------------------------------------------
	typedef union _pgx_Uint32_UNION {
		unsigned long int val;
		unsigned int  w[ 2 ];
		unsigned char v[ 4 ];
		struct {
			unsigned int LW;
			unsigned int HW;
		} word;
		struct {
			unsigned char LB;
			unsigned char HB;
			unsigned char UB;
			unsigned char MB;
		} byte;
		struct {
			WORD_VAL low;
			WORD_VAL high;
		} wordUnion;
		struct {
			unsigned char b0:1;
			unsigned char b1:1;
			unsigned char b2:1;
			unsigned char b3:1;
			unsigned char b4:1;
			unsigned char b5:1;
			unsigned char b6:1;
			unsigned char b7:1;
			unsigned char b8:1;
			unsigned char b9:1;
			unsigned char b10:1;
			unsigned char b11:1;
			unsigned char b12:1;
			unsigned char b13:1;
			unsigned char b14:1;
			unsigned char b15:1;
			unsigned char b16:1;
			unsigned char b17:1;
			unsigned char b18:1;
			unsigned char b19:1;
			unsigned char b20:1;
			unsigned char b21:1;
			unsigned char b22:1;
			unsigned char b23:1;
			unsigned char b24:1;
			unsigned char b25:1;
			unsigned char b26:1;
			unsigned char b27:1;
			unsigned char b28:1;
			unsigned char b29:1;
			unsigned char b30:1;
			unsigned char b31:1;
		}bit;
	} DWORD_VAL;
	typedef DWORD_VAL						_pgx_Uint32_VAL;
	typedef DWORD_VAL						_pgx_Uint32_BITS;
	//------------------------------------------------------------------------
#endif /* _PGIMX_CUSTOM_TYPE_H_ */


