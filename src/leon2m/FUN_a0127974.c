/* FUN_a0127974 (leon2m 0xa0127974-0xa0127980, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns the byte DAT_a802d8a4. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a0127968 and FUN_a0127980. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802d8a4;

unsigned char FUN_a0127974(void)
{
    return DAT_a802d8a4;
}
