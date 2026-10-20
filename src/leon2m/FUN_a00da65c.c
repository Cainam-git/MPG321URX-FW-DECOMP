/* leon2m FUN_a00da65c @ 0xa00da65c-0xa00da714 (46 words).
 * Computes from the byte x = FUN_a0125c54(): v = x * 3.3 / 255 (as float), r = (33 - 10 v) / v,
 * t = 3400.65 / log(r / 0.000112) - 273.15, returned as an unsigned char. The arithmetic runs through the
 * soft-float routines (__floatsidf, __muldf3, __divdf3, __truncdfsf2, __mulsf3, __subsf3, __divsf3,
 * __extendsfdf2, log, __subdf3, __fixunssfsi); flags -mcpu=v8 -O3 -g -msoft-float.
 */
extern unsigned char FUN_a0125c54(void);
extern double log(double);

unsigned char FUN_a00da65c(void)
{
    float v = FUN_a0125c54() * 3.3 / 255.0;
    float r = (33.0f - v * 10.0f) / v;
    float t = 3400.65 / log(r / 0.000112) - 273.15;

    return t;
}
