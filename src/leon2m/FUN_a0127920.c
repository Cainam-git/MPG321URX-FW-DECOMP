/* FUN_a0127920 (leon2m 0xa0127920-0xa012792c, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns the byte DAT_a802d8a5. Called by FUN_a008454c. It lies between FUN_a0127914 and FUN_a012792c. Source
 * form: a direct read of the extern symbol (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802d8a5;

unsigned char FUN_a0127920(void)
{
    return DAT_a802d8a5;
}
