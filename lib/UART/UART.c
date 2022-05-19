#include "uart.h"


void Uart_Init(uint32_t baudrate)
{
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
    UBRR0L = BAUD_PRESCALE;
    UBRR0H = (BAUD_PRESCALE >> 8);
}

uint8_t uart_getc(void)
{
    while (!(UCSR0A & (1 << RXC0))) // warten bis Zeichen verfuegbar
        ;
    return UDR0; // Zeichen aus UDR an Aufrufer zurueckgeben
}

uint8_t Uart_RecieveString(char *buffer, uint8_t length)
{

    uint8_t NextChar;
    uint8_t StringLen = 0;

    NextChar = uart_getc(); // Warte auf und empfange das nächste Zeichen

    // Sammle solange Zeichen, bis:
    // * entweder das String Ende Zeichen kam
    // * oder das aufnehmende Array voll ist
    while (NextChar != UART_DELIM && StringLen < length - 1)
    {
        *buffer++ = NextChar;
        StringLen++;
        NextChar = uart_getc();
    }

    // Noch ein '\0' anhängen um einen Standard
    // C-String daraus zu machen
    *buffer = '\0';
    return StringLen;
}

int uart_putc(unsigned char c)
{
    while (!(UCSR0A & (1<<UDRE0)))  /* warten bis Senden moeglich */
    {
    }                             

    UDR0 = c;                      /* sende Zeichen */
    return 0;
}


/* puts ist unabhaengig vom Controllertyp */
void uart_puts (char *s)
{
    while (*s!='\0')
    {   /* so lange *s != '\0' also ungleich dem "String-Endezeichen(Terminator)" */
        uart_putc(*s);
        s++;
    }
    uart_putc('\n');
}

void uart_puts_length (char *s,uint8_t length)
{
    for (uint8_t i = 0; i < length; i++)
    {
        uart_putc(*(s+i));
    }
    uart_putc('\n');
    
}