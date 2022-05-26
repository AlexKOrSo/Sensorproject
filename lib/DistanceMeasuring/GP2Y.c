#include "GP2Y.h"
const float a_const = 2.50509564e-04;
const float b_const = -3.24320788e-01;
const float c_const = 1.20210417e+02;


void ConvertValue(uint16_t cts, float *value)
{
    if (cts < 160)
    {
        *value = -1.0;
    }
    else
    {
        *value =  a_const * (cts * cts ) + b_const * (cts ) + c_const;
    }
}

int8_t readDistance(ADC_Config *interface, float *value)
{
    if (interface->state != READY)
    {
        return -1;
    }

    uint16_t temp = 0;
    ADC_ReadInput(interface, &temp);
    ConvertValue(temp, value);
}