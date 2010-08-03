// alpha-numeric-serial-display.h

// Bit position relating display pin to driver output pin
//		SEG	OUT#	LED		STP16CP05
#define A1	0	//	2		5
#define A2	13 	//	22		18
#define B	12	//	21		17
#define C	10	//	16		15
#define D1	5	//	10		10
#define D2	8	//	14		13
#define E	4	//	9		9
#define F	2	//	4		7
#define G1	3	//	7		8
#define G2	11	//	19		16
#define H	1	//	3		6
#define J	15	//	24		20
#define K	14	//	23		19
#define L	9	//	15		14
#define M	7	//	12		12
#define N	6	//	11		11

#define A_CHAR (1<<G1)+(1<<G2)+(1<<E)+(1<<F)+(1<<A1)+(1<<A2)+(1<<B)+(1<<C)
#define B_CHAR (1<<A1)+(1<<A2)+(1<<B)+(1<<C)+(1<<D2)+(1<<D1)+(1<<M)+(1<<J)+(1<<G1)+(1<<G2)
#define C_CHAR (1<<A1)+(1<<A2)+(1<<D2)+(1<<D1)+(1<<E)+(1<<F)
#define D_CHAR (1<<A1)+(1<<A2)+(1<<B)+(1<<C)+(1<<D2)+(1<<D1)+(1<<M)+(1<<J)
#define E_CHAR (1<<A1)+(1<<A2)+(1<<D2)+(1<<D1)+(1<<E)+(1<<F)+(1<<G1)+(1<<G2)
#define F_CHAR (1<<A1)+(1<<A2)+(1<<F)+(1<<G1)+(1<<E)
#define G_CHAR (1<<A1)+(1<<A2)+(1<<F)+(1<<E)+(1<<D1)+(1<<D2)+(1<<C)+(1<<G2)
#define H_CHAR (1<<F)+(1<<E)+(1<<G1)+(1<<G2)+(1<<B)+(1<<C)
#define I_CHAR (1<<A1)+(1<<A2)+(1<<J)+(1<<M)+(1<<D1)+(1<<D2)
#define J_CHAR (1<<B)+(1<<C)+(1<<D1)+(1<<D2)
#define K_CHAR (1<<F)+(1<<E)+(1<<G1)+(1<<K)+(1<<L)
#define L_CHAR (1<<F)+(1<<E)+(1<<D1)+(1<<D2)
#define M_CHAR (1<<E)+(1<<F)+(1<<H)+(1<<K)+(1<<B)+(1<<C)
#define N_CHAR (1<<E)+(1<<F)+(1<<H)+(1<<L)+(1<<C)+(1<<B)
#define O_CHAR (1<<F)+(1<<E)+(1<<D1)+(1<<D2)+(1<<C)+(1<<B)+(1<<A2)+(1<<A1)
#define P_CHAR (1<<E)+(1<<F)+(1<<A1)+(1<<A2)+(1<<B)+(1<<G2)+(1<<G1)
#define Q_CHAR (1<<F)+(1<<E)+(1<<D1)+(1<<D2)+(1<<C)+(1<<B)+(1<<A2)+(1<<A1)+(1<<L)
#define R_CHAR (1<<E)+(1<<F)+(1<<A1)+(1<<A2)+(1<<B)+(1<<G1)+(1<<G2)+(1<<L)
#define S_CHAR (1<<A2)+(1<<A1)+(1<<F)+(1<<G1)+(1<<G2)+(1<<C)+(1<<D2)+(1<<D1)
#define T_CHAR (1<<A1)+(1<<A2)+(1<<J)+(1<<M)
#define U_CHAR (1<<F)+(1<<E)+(1<<D1)+(1<<D2)+(1<<C)+(1<<B)
#define V_CHAR (1<<F)+(1<<E)+(1<<N)+(1<<K)
#define W_CHAR (1<<F)+(1<<E)+(1<<N)+(1<<L)+(1<<C)+(1<<B)
#define X_CHAR (1<<H)+(1<<N)+(1<<L)+(1<<K)
#define Y_CHAR (1<<H)+(1<<K)+(1<<M)
#define Z_CHAR (1<<A1)+(1<<A2)+(1<<K)+(1<<N)+(1<<D1)+(1<<D2)

#define ONE (1<<B)+(1<<C)
#define TWO (1<<A1)+(1<<A2)+(1<<B)+(1<<G1)+(1<<G2)+(1<<E)+(1<<D1)+(1<<D2)
#define THREE (1<<A1)+(1<<A2)+(1<<B)+(1<<G2)+(1<<C)+(1<<D2)+(1<<D1)
#define FOUR (1<<F)+(1<<G1)+(1<<G2)+(1<<B)+(1<<C)
#define FIVE (1<<A1)+(1<<A2)+(1<<F)+(1<<G1)+(1<<G2)+(1<<C)+(1<<D2)+(1<<D1)
#define SIX (1<<A2)+(1<<A1)+(1<<F)+(1<<G2)+(1<<G1)+(1<<C)+(1<<D2)+(1<<D1)+(1<<E)
#define SEVEN (1<<A1)+(1<<A2)+(1<<B)+(1<<C)
#define EIGHT (1<<A1)+(1<<A2)+(1<<F)+(1<<G1)+(1<<G2)+(1<<B)+(1<<C)+(1<<D2)+(1<<D1)+(1<<E)
#define NINE (1<<A1)+(1<<A2)+(1<<F)+(1<<B)+(1<<G1)+(1<<G2)+(1<<C)
#define ZERO (1<<F)+(1<<E)+(1<<D1)+(1<<D2)+(1<<C)+(1<<B)+(1<<A2)+(1<<A1)

#define EXCLAMATION (1<<B)+(1<<C)
#define ATSIGN (1<<D2)+(1<<D1)+(1<<E)+(1<<F)+(1<<A1)+(1<<A2)+(1<<B)+(1<<G2)+(1<<J)
#define DOLLAR (1<<A2)+(1<<A1)+(1<<F)+(1<<G1)+(1<<G2)+(1<<C)+(1<<D2)+(1<<D1)+(1<<J)+(1<<M)
#define PERCENT (1<<A1)+(1<<F)+(1<<G1)+(1<<J)+(1<<G2)+(1<<M)+(1<<D2)+(1<<C)+(1<<N)+(1<<K)
#define CARROT (1<<K)+(1<<N)+(1<<A2)+(1<<B)
#define AMPERSAND (1<<A2)+(1<<J)+(1<<K)+(1<<N)+(1<<D1)+(1<<M)+(1<<D2)+(1<<C)
#define ASTERISK (1<<J)+(1<<H)+(1<<G1)+(1<<N)+(1<<M)+(1<<L)+(1<<G2)+(1<<K)
#define LPAREN (1<<K)+(1<<L)
#define RPAREN (1<<H)+(1<<N)
#define MINUS (1<<G1)+(1<<G2)
#define UNDERSCORE (1<<D1)+(1<<D2)
#define PLUSYSIGN (1<<J)+(1<<G1)+(1<<G2)+(1<<M)
#define EQUALS (1<<G1)+(1<<G2)+(1<<D1)+(1<<D2)

#define PERIOD (1<<G1)+(1<<M)+(1<<D1)+(1<<E)
#define COLON (1<<J)+(1<<M)
#define SEMICOLON (1<<J)+(1<<N)
#define LARROW (1<<K)+(1<<L)
#define RARROW (1<<H)+(1<<N)
#define COMMA (1<<N)
#define FSLASH (1<<N)+(1<<K)
#define BSLASH (1<<H)+(1<<L)
#define SINGLEQUOTE (1<<K)
#define DOUBLEQUOTE (1<<J)+(1<<F)
#define LBRACKET (1<<A2)+(1<<J)+(1<<M)+(1<<D2)
#define RIBRACKET (1<<A1)+(1<<J)+(1<<M)+(1<<D1)
#define LECURLY (1<<A1)+(1<<J)+(1<<M)+(1<<D1)+(1<<G2)
#define RICURLY (1<<G1)+(1<<A2)+(1<<J)+(1<<M)+(1<<D2)
#define PIPE (1<<J)+(1<<M)
#define TILDE (1<<E)+(1<<G1)+(1<<G2)+(1<<B)
#define APOSTROPHE (1<<H)
#define QUESTIONMARK (1<<M)+(1<<G2)+(1<<B)+(1<<A2)

#define TIMER_MAXIMUM 0x50
#define TIMER_MINIMUM 0x23
