/*
	Created on: July 20, 2010
	by: Jim Lindblom
	AlphaNumeric Display Driver
	
	Send a serial character to the ATmega328 and it'll display it on the 16-segment display.
	
	Hardware: Arduino Pro connected to a STP16CP05 connected to a 16-segment display.
	Connections:
	Arduino Pro -------------	STP16CP05
		D10	---------------------	LE
		D11	---------------------	SDI	
		D12 ---------------------	SDO
		D13	---------------------	CLK
		D9	---------------------	OE
	
	 AlphaNumeric Display-------STP16CP05 (Pin-to-pin)
			2	------------------	5
			2	------------------	18
			21	------------------	17
			16	------------------	15
			10	------------------	10
			14	------------------	13
			9	------------------	9
			4	------------------	7
			7	------------------	8
			19	------------------	16
			3	------------------	6
			24	------------------	20
			23	------------------	19
			15	------------------	14
			12	------------------	12
			11	------------------	11
	
	AlphaNumeric Display Anodes connected to +7-9V (depends on color/forward voltage).
	Arduino Pro powered with 5V at raw. 3.3V regulated on Arduino is sent to STP16CP05.
*/

//======================//
// 		Includes		//
//======================//
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "alpha-numeric-serial-display.h"
//======================//
//		 Macros 		//
//======================//

#define sbi(var, mask)   ((var) |= (uint8_t)(1 << mask))
#define cbi(var, mask)   ((var) &= (uint8_t)~(1 << mask))

//======================//
// Arduino Pro  Defines	//
//======================//
#define SDI	3	// PB3 (D11)
#define CLK	5	// PB5 (D13)
#define SDO	4	// PB4 (D12)
#define LE	2	// PB2 (D10)
#define OE	1	// PB1 (D9)

//======================//
// Function Prototypes	//
//======================//
void ioinit(void);
void delay_ms(uint16_t x);
void delay_us(uint16_t x);
void shiftOut(uint16_t data);
uint16_t createShiftData(char character);
static int uart_putchar(char c, FILE *stream);
uint8_t uart_getchar(void);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

//======================//
//   Global Variables	//
//======================//
char displayBuffer;

//======================//
//  	   ISRs			//
//======================//
ISR(TIMER1_COMPA_vect)
{
	shiftOut(createShiftData(displayBuffer));
}

int main(void)
{
	ioinit();
	
	while(1)
	{
		displayBuffer = uart_getchar();
		if((displayBuffer == 0x10)&&(OCR1A>TIMER_MINIMUM))
		{
			OCR1A--;
			printf("0x%x\n", OCR1A);
			TCNT1 = 0x00;
		}
		else if ((displayBuffer == 0x11)&&(OCR1A<TIMER_MAXIMUM))
		{
			OCR1A++;
			printf("0x%x\n", OCR1A);
			TCNT1 = 0x00;
		}
		printf("%c", displayBuffer);
	}
	/*
	
		displayBuffer = uart_getchar();
		if (inKey == -1)
		{
			if((inKey == '!')&&(OCR1A>0))
				OCR1A -= 256;
			else if ((inKey == '@')&&(OCR1A<0x1FFF))
				OCR1A += 256;
		}
		else
			displayBuffer = inKey;
	*/
}

void shiftOut(uint16_t data)
{
	sbi(PORTB, OE);
	delay_ms(1);
	cbi(PORTB, CLK);
	sbi(PORTB, LE);
	
	// Clock in data
	
	for (unsigned int i = 0; i<16; i++)
	{		
		if ((data<<i)&0x8000)
		{
			sbi(PORTB, SDI);
		}
		else
		{
			cbi(PORTB, SDI);
		}
		
		sbi(PORTB, CLK);	// rising
		cbi(PORTB, CLK);	// falling
	}
	
	// Output enable
	cbi(PORTB, OE);
}

uint16_t createShiftData(char character)
{
	switch (character)
	{
		case '0':
		case 0:
			return ZERO;
			break;
		case '1':
		case 1:
			return ONE;
			break;
		case '2':
		case 2:
			return TWO;
			break;
		case '3':
		case 3:
			return THREE;
			break;
		case '4':
		case 4:
			return FOUR;
			break;
		case '5':
		case 5:
			return FIVE;
			break;
		case '6':
		case 6:
			return SIX;
			break;
		case '7':
		case 7:
			return SEVEN;
			break;
		case '8':
		case 8:
			return EIGHT;
			break;
		case '9':
		case 9:
			return NINE;
			break;
		case 'A':
		case 'a':
		case 10:
			return A_CHAR;
			break;
		case 'B':
		case 'b':
		case 11:
			return B_CHAR;
			break;
		case 'C':
		case 'c':
		case 12:
			return C_CHAR;
			break;
		case 'D':
		case 'd':
		case 13:
			return D_CHAR;
			break;
		case 'E':
		case 'e':
		case 14:
			return E_CHAR;
			break;
		case 'F':
		case 'f':
		case 15:
			return F_CHAR;
			break;
		case 'G':
		case 'g':
			return G_CHAR;
			break;
		case 'H':
		case 'h':
			return H_CHAR;
			break;
		case 'I':
		case 'i':
			return I_CHAR;
			break;
		case 'J':
		case 'j':
			return J_CHAR;
			break;
		case 'K':
		case 'k':
			return K_CHAR;
			break;
		case 'L':
		case 'l':
			return L_CHAR;
			break;
		case 'M':
		case 'm':
			return M_CHAR;
			break;
		case 'N':
		case 'n':
			return N_CHAR;
			break;
		case 'O':
		case 'o':
			return O_CHAR;
			break;
		case 'P':
		case 'p':
			return P_CHAR;
			break;
		case 'Q':
		case 'q':
			return Q_CHAR;
			break;
		case 'R':
		case 'r':
			return R_CHAR;
			break;
		case 'S':
		case 's':
			return S_CHAR;
			break;
		case 'T':
		case 't':
			return T_CHAR;
			break;
		case 'U':
		case 'u':
			return U_CHAR;
			break;
		case 'V':
		case 'v':
			return V_CHAR;
			break;
		case 'W':
		case 'w':
			return W_CHAR;
			break;
		case 'X':
		case 'x':
			return X_CHAR;
			break;
		case 'Y':
		case 'y':
			return Y_CHAR;
			break;
		case 'Z':
		case 'z':
			return Z_CHAR;
			break;
		case ' ':
			return 0;
			break;
		case '!':
			return EXCLAMATION;
			break;
		case '$':
			return DOLLAR;
			break;
		case '%':
			return PERCENT;
			break;
		case '^':
			return CARROT;
			break;
		case '&':
			return AMPERSAND;
			break;
		case '*':
			return ASTERISK;
			break;
		case '(':
			return LPAREN;
			break;
		case ')':
			return RPAREN;
			break;
		case '-':
			return MINUS;
			break;
		case '_':
			return UNDERSCORE;
			break;
		case '+':
			return PLUSYSIGN;
			break;
		case '=':
			return EQUALS;
			break;
		case '>':
			return RARROW;
			break;
		case '<':
			return LARROW;
			break;
		case ',':
			return COMMA;
			break;
		case '/':
			return FSLASH;
			break;
		case '\\':
			return BSLASH;
			break;
		case '\'':
			return SINGLEQUOTE;
			break;
		case '"':
			return DOUBLEQUOTE;
			break;
		case 0X5B:
			return LBRACKET;
			break;
		case 0X5D:
			return RIBRACKET;
			break;
		case 0X7D:
			return LECURLY;
			break;
		case 0X7B:
			return RICURLY;
			break;
		case '|':
			return PIPE;
			break;
		case '~':
			return TILDE;
			break;
		case '`':
			return APOSTROPHE;
			break;
		case '@':
			return ATSIGN;
			break;
		case '?':
			return QUESTIONMARK;
			break;
		case ':':
			return COLON;
			break;
		case ';':
			return SEMICOLON;
			break;
		case '.':
			return PERIOD;
			break;
	}
	
	return -1;	// Return error, maybe check for special character if error returned
}

static int uart_putchar(char c, FILE *stream)
{
    if (c == '\n') uart_putchar('\r', stream);

    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;

    return 0;
}

uint8_t uart_getchar(void)
{
    while( !(UCSR0A & (1<<RXC0)) );
    return(UDR0);
}


void ioinit (void)
{
	int MYUBRR = 103;	// Results in 9600bps@8MHz or 19200bps@16MHz
	
    //1 = output, 0 = input
	DDRB = 0b00101111;
    DDRD = 0b11111110; //PORTD (RX on PD0)
	stdout = &mystdout; //Required for printf init

	UBRR0H = (MYUBRR) >> 8;
	UBRR0L = MYUBRR;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
	UCSR0A = (1<<U2X0);

	TCCR2B = (1<<CS21);
	
	// Set 16-bit Timer 1 for clicking
	TCCR1A = 0x00;
	TCCR1B = (1<<WGM12) | (1<<CS12);
	OCR1A = TIMER_MAXIMUM;
	TIMSK1 = (1<<OCIE1A);
	sei();

	// Shift in data to blank display
	cbi(PORTB, CLK);
	cbi(PORTB, SDI);
	cbi(PORTB, LE);
	sbi(PORTB, OE);
	delay_ms(1);
	
	for (unsigned int i = 0; i<16; i++)
	{
		sbi(PORTB, CLK);
		delay_ms(1);
		cbi(PORTB, CLK);
		delay_ms(1);
	}
	
	sbi(PORTB, LE);
	delay_ms(1);
	sbi(PORTB, CLK);
	delay_ms(1);
	cbi(PORTB, LE);
	delay_ms(1);
	cbi(PORTB, CLK);
	delay_ms(1);

}

//General short delays
void delay_ms(uint16_t x)
{
    for (; x > 0 ; x--)
        delay_us(1000);
}

//General short delays
void delay_us(uint16_t x)
{
    while(x > 256)
    {
        TIFR2 = (1<<TOV2); //Clear any interrupt flags on Timer2
        TCNT2 = 0; //256 - 125 = 131 : Preload timer 2 for x clicks. Should be 1us per click
        while( (TIFR2 & (1<<TOV2)) == 0);

        x -= 256;
    }

    TIFR2 = (1<<TOV2); //Clear any interrupt flags on Timer2
    TCNT2= 256 - x; //256 - 125 = 131 : Preload timer 2 for x clicks. Should be 1us per click
    while( (TIFR2 & (1<<TOV2)) == 0);
}

