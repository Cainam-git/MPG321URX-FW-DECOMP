/* ldc_user_set_dimming_mode  (FUN_a00d8064)
 *
 * Send the dimming mode 0..3.
 * Name basis: descriptive - ldc_api_set_dimming_mode; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8064 @ 0xa00d8064-0xa00d80b0, 76 bytes, leaf, flags -mcpu=v8 -O2 -g.
 * Source form: an if/else chain with a constant argument per call (GCC merges the four calls into one tail call).
 */
extern void ldc_api_set_dimming_mode(unsigned char);

/*
 * Pass a dimming mode of 0, 1, 2 or 3 on to ldc_api_set_dimming_mode; any other value does nothing.
 * Nothing in the image calls this routine or stores its address.
 */
void ldc_user_set_dimming_mode(unsigned char mode)
{
    if (mode == 0)
        ldc_api_set_dimming_mode(0);
    else if (mode == 1)
        ldc_api_set_dimming_mode(1);
    else if (mode == 2)
        ldc_api_set_dimming_mode(2);
    else if (mode == 3)
        ldc_api_set_dimming_mode(3);
}
