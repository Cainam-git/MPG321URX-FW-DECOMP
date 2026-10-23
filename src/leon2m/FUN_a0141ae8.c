/* FUN_a0141ae8 (leon2m 0xa0141ae8-0xa0141af4, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte DAT_a802e110. Called by FUN_a013dc6c (2 calls). It lies between FUN_a0141ad0 and
 * switchdataD_a0141af4. Source form: a direct read of the extern symbol (sethi %hi + load with the %lo offset in
 * the retl delay slot).
 */
extern unsigned char DAT_a802e110;

unsigned char FUN_a0141ae8(void)
{
    return DAT_a802e110;
}
