/* FUN_a0105c78 (leon2m 0xa0105c78-0xa0105c84, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the halfword DAT_a8027a80. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a0105c0c and FUN_a0105c84. Source form: a direct read of the extern symbol
 * (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned short DAT_a8027a80;

unsigned short FUN_a0105c78(void)
{
    return DAT_a8027a80;
}
