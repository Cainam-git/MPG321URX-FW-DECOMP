/* leon2m FUN_a00dd43c @ 0xa00dd43c-0xa00dd540 (65 words).
 * Prints n words (32 when n is 0) from the address addr (rounded down to a word) through FUN_a00def40 /
 * FUN_a00deffc: after a "\n", one line per 16 bytes from addr rounded down to 32 up to the end rounded up to 32,
 * each with the line address, " : " and four columns, a word value and " " inside the requested range and
 * nine spaces outside it, then "\n"; a final "\n" ends the output. addr 0 prints nothing.
 * The strings are named by their firmware addresses: " " (0x198bb0) and "\n" (0xfef90) are tails of other strings
 * merged by the linker, and " : " (0x198b60) and the nine spaces (0x198ba8) sit between strings of other
 * functions of this file.
 */
extern void FUN_a00def40(const char *);
extern void FUN_a00deffc(unsigned int val);
extern const char s_000fef90[];
extern const char s_00198b60[];
extern const char s_00198ba8[];
extern const char s_00198bb0[];

void FUN_a00dd43c(unsigned int addr, unsigned int n)
{
    unsigned int *start, *end, *p, *row, *last;
    int i;

    if (addr == 0)
        return;
    start = (unsigned int *)(addr & ~3);
    if (n == 0)
        n = 32;
    end = start + n;
    last = (unsigned int *)(((unsigned int)end + 31) & ~31);
    p = (unsigned int *)(addr & ~31);
    FUN_a00def40(s_000fef90);
    for (row = p; row < last; row += 4) {
        FUN_a00deffc((unsigned int)row);
        FUN_a00def40(s_00198b60);
        for (i = 0; i < 4; i++) {
            if (p < start || p >= end)
                FUN_a00def40(s_00198ba8);
            else {
                FUN_a00deffc(*p);
                FUN_a00def40(s_00198bb0);
            }
            p++;
        }
        FUN_a00def40(s_000fef90);
    }
    FUN_a00def40(s_000fef90);
}
