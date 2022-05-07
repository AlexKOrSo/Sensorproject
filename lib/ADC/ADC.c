#include "ADC.h"

void inline ADC_doConvserion()
{
    ADCSRA |= (0x1 << ADSC);
}

void inline ADC_waitForConversion()
{
    while (ADCSRA && (~(0x1 << ADSC)))
        ;
}

ADC_Config ADC_Init(ADC_PRESCALER Prescale_Value, REF_VOLTAGE reference, MUX_SELECT source_channel)
{
    ADC_Config temp;
    temp.prescaler = Prescale_Value;

    ADCSRA = (temp.prescaler << ADPS0) | (0x1 << ADIE);
    ADMUX = (reference << REFS0) | (source_channel << MUX0);

    if (source_channel <= MUX_ADC5)
    {
        DIDR0 |= (0x1 << source_channel);
    }

    ADC_doConvserion();

    return temp;
}