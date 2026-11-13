/* hdr_reset_tone_curve  (FUN_a00d264c)
 *
 * Fill the 257-entry tone curve with the neutral value 0x400.
 * Name basis: proven - 16-bit table at 0xA8077A08
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d264c @ 0xa00d264c (-mcpu=v8 -Os -g)
 * Source form: a plain array loop (a byte-offset pointer form changes the address operand order).
 */
extern unsigned short hdr_tone_curve[];

#define TONE_CURVE_LAST    0x100        /* the curve has entries 0..0x100 (257) */
#define TONE_CURVE_NEUTRAL 0x400        /* neutral entry value: output = input */

/*
 * Set every entry of the tone curve table hdr_tone_curve to the neutral value 0x400. Called by hdr_init.
 */
void hdr_reset_tone_curve(void)
{
    int i;
    for (i = 0; i <= TONE_CURVE_LAST; i++)
        hdr_tone_curve[i] = TONE_CURVE_NEUTRAL;
}
