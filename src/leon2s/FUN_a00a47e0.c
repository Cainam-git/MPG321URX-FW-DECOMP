/* leon2s FUN_a00a47e0 @ 0xa00a47e0-0xa00a486c (35 words), flags -mcpu=v8 -Os -g.
 * Code facts: r = 1; unless byte +5 of the 8-byte record ARR_a807dc10[ch] is 1: if
 * FUN_a00a6190(port) or FUN_a00a61d4(port) is nonzero (port = byte DAT_a8079228, re-read for each
 * call): r = 0, and if FUN_a00a621c(port) == 1: r = 1, log FUN_a0073044(string 0xa006c030
 * "dsc interface mode change %d\r\n", 1). Returns r (int).
 * Fixes vs the autoc draft (80.00): the port argument byte DAT_a8079228 is passed to all three
 * calls (the draft dropped it for two); real base ARR_a807dc10 (8-byte records; draft used the
 * mid-record dc15); int r (a u8 r adds 'and 1' twice). Aids: none.
 */
struct Rec8 { unsigned char b[8]; };
extern struct Rec8 ARR_a807dc10[];
extern unsigned char DAT_a8079228;
extern const char s_a006c030[];
extern void FUN_a0073044(const char *fmt, ...);
extern unsigned char FUN_a00a6190(unsigned char);
extern unsigned char FUN_a00a61d4(unsigned char);
extern unsigned char FUN_a00a621c(unsigned char);

int FUN_a00a47e0(unsigned char ch)
{
    int r = 1;

    if (ARR_a807dc10[ch].b[5] != 1) {
        if (FUN_a00a6190(DAT_a8079228) != 0 || FUN_a00a61d4(DAT_a8079228) != 0) {
            r = 0;
            if (FUN_a00a621c(DAT_a8079228) == 1) {
                r = 1;
                FUN_a0073044(s_a006c030, 1);
            }
        }
    }
    return r;
}
