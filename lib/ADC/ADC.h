#ifndef ADC_H_
#define ADC_H_

#include "avr/io.h"
#include <stdint.h>

/**
 * @brief Holds all possible prescaler values for ADC
 * Holds the actual value of the prescaler, which enables the usage in e. g. further calculations.
 */
typedef enum
{
    PRSC_2 = 0x1,
    PRSC_4 = 0x2,
    PRSC_8 = 0x3,
    PRSC_16 = 0x4,
    PRSC_32 = 0x5,
    PRSC_64 = 0x6,
    PRSC_128 = 0x7,
} ADC_PRESCALER;

typedef enum
{
    AREF = 0x0,
    AVCC = 0x1,
    INTERNAL = 0x3,
} REF_VOLTAGE;

typedef enum
{
    MUX_ADC0 = 0x0,
    MUX_ADC1 = 0x1,
    MUX_ADC2 = 0x2,
    MUX_ADC3 = 0x3,
    MUX_ADC4 = 0x4,
    MUX_ADC5 = 0x5,
    MUX_ADC6 = 0x6,
    MUX_ADC7 = 0x7,
    MUX_TSENSE = 0x8,
    MUX_1_1 = 0xE,
    MUX_0 = 0xF
} MUX_SELECT;

typedef struct
{
    ADC_PRESCALER prescaler;

} ADC_Config;

ADC_Config ADC_Init(ADC_PRESCALER Prescale_Value, REF_VOLTAGE reference, MUX_SELECT source_channel);

#endif