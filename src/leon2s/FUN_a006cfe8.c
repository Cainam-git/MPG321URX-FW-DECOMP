/* FUN_a006cfe8 (leon2s 0xa006cfe8-0xa006d050, 104 bytes), flags -mcpu=v8 -Os -g.
 * Runs the request stored by FUN_a006cfac: when the byte flag DAT_a80787f4 is 1, prints s_a0065bc8
 * (debug string "unzip osd GO!! %d" per Ghidra) with the mode byte DAT_a80787e0, calls FUN_a006cc24 with the four words of
 * DAT_a80787e4, clears the flag, calls FUN_a006fedc() and prints s_a0065be0 ("unzip osd finish!! %d") with the
 * mode byte (tail call).
 */
struct Req { unsigned int a, b, c, d; };
extern struct Req DAT_a80787e4;
extern unsigned char DAT_a80787e0;
extern unsigned char DAT_a80787f4;
extern char s_a0065bc8[], s_a0065be0[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a006cc24(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a006fedc(void);

void FUN_a006cfe8(void)
{
    if (DAT_a80787f4 == 1) {
        FUN_a0073044(s_a0065bc8, DAT_a80787e0);
        FUN_a006cc24(DAT_a80787e4.a, DAT_a80787e4.b, DAT_a80787e4.c, DAT_a80787e4.d);
        DAT_a80787f4 = 0;
        FUN_a006fedc();
        FUN_a0073044(s_a0065be0, DAT_a80787e0);
    }
}
