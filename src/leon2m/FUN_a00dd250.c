/* leon2m FUN_a00dd250 @ 0xa00dd250-0xa00dd3d4 (97 words).
 * Prints n words (32 when n is 0) from the address addr (rounded down to a word) through FUN_a00def40,
 * FUN_a00deffc, FUN_a00df0f4 and FUN_a00deef0: after a "\n", one line per 16 bytes from addr rounded down to 16 up
 * to the end rounded up to 16, each with the line address, " : ", four columns (the four bytes of a word via
 * FUN_a00df0f4, each followed by " ", inside the requested range; twelve spaces outside it), "| ", the 16 bytes as
 * characters (FUN_a00deef0 for 0x20..0x7e, "." otherwise; words outside the range count as 0) and "\n"; a final
 * "\n" ends the output. addr 0 prints nothing. The line's words are kept in a local 4-word array.
 * The strings are named by their firmware addresses (s_...): " " (0x198bb0) and "\n" (0xfef90) are tails of other
 * strings merged by the linker, and the order of the other strings is set by other functions of this file.
 * Flags -mcpu=v8 -O3 -g -msoft-float (the reserved floating-point registers change the loop scheduling).
 */
extern void FUN_a00def40(const char *);
extern void FUN_a00deffc(unsigned int val);
extern void FUN_a00df0f4(unsigned char);
extern void FUN_a00deef0(signed char);
extern const char s_000fef90[];
extern const char s_00198b60[];
extern const char s_00198b68[];
extern const char s_00198b70[];
extern const char s_00198b80[];
extern const char s_00198bb0[];

void FUN_a00dd250(unsigned int addr, unsigned int n)
{
    unsigned int *start, *end, *p, *row, *last;
    unsigned int buf[4];
    int i, j;

    if (addr == 0)
        return;
    start = (unsigned int *)(addr & ~3);
    if (n == 0)
        n = 32;
    end = start + n;
    last = (unsigned int *)(((unsigned int)end + 15) & ~15);
    p = (unsigned int *)(addr & ~15);
    FUN_a00def40(s_000fef90);
    for (row = p; row < last; row += 4) {
        FUN_a00deffc((unsigned int)row);
        FUN_a00def40(s_00198b60);
        for (i = 0; i < 4; i++) {
            if (p < start || p >= end) {
                buf[i] = 0;
                FUN_a00def40(s_00198b70);
            } else {
                unsigned int w = *p;
                buf[i] = w;
                for (j = 0; j < 4; j++) {
                    FUN_a00df0f4(w >> (j * 8));
                    FUN_a00def40(s_00198bb0);
                }
            }
            p++;
        }
        FUN_a00def40(s_00198b68);
        for (i = 0; i < 4; i++) {
            unsigned int w = buf[i];
            for (j = 0; j < 4; j++) {
                unsigned char c = w >> (j * 8);
                if (c >= 0x20 && c <= 0x7e)
                    FUN_a00deef0(c);
                else
                    FUN_a00def40(s_00198b80);
            }
        }
        FUN_a00def40(s_000fef90);
    }
    FUN_a00def40(s_000fef90);
}
