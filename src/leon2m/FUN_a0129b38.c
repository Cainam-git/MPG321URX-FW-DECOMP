/* FUN_a0129b38 (leon2m 0xa0129b38-0xa0129b44, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns the halfword DAT_a802c9fe. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a0129af0 and FUN_a0129b44. Source form: a direct read of the extern symbol
 * (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned short DAT_a802c9fe;

unsigned short FUN_a0129b38(void)
{
    return DAT_a802c9fe;
}
