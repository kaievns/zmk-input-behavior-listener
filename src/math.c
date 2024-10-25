/**
 * A super simple sin/cos substitute based on taylor sequences
 * to avoid importing the math.h
 *
 * sin x = x - x^3/3! + x^5/5! -x^7/7! ...
 * cos x = 1 -x^2/2!+x^4/4!-x^6/6! ...
 */
#include "math.h"
#include <zephyr/kernel.h>

#define PI (3.14159265359f)
#define TERMS 7

float simple_sin(float rad)
{
    float sign = 1.0;
    if (rad < 0)
    {
        sign = -1.0;
        rad = -rad;
    }
    float res = 0;
    float term = rad;
    int8_t k = 1;
    while (k < TERMS * 2)
    {
        res += term;
        k += 2;
        term *= -rad * rad / k / (k - 1);
    }

    return sign * res;
}

float simple_cos(float rad)
{
    if (rad < 0)
    {
        rad = -rad;
    }
    float res = 0;
    float term = 1;
    int8_t k = 0;
    while (k < TERMS * 2)
    {
        res += term;
        k += 2;
        term *= -rad * rad / k / (k - 1);
    }
    return res;
}

// conver clockwise degrees into counter-clockwise radians
float deg_to_cc_rad(int16_t deg)
{
    deg %= 360; // make it less than 360
    return -(deg * PI) / 180.0f;
}

// clockwise
float sin_from_deg(int16_t deg)
{
    return simple_sin(deg_to_cc_rad(deg));
}
float cos_from_deg(int16_t deg)
{
    return simple_cos(deg_to_cc_rad(deg % 360));
}
