/* FUN_a00b2070 (leon2s 0xa00b2070-0xa00b20dc, 108 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores the callback fn into the first empty one of the two callback words of group idx of DAT_a80793a4
 * (offset 0xc, the callbacks that FUN_a00618d8 calls); when both are taken, tail-calls
 * FUN_a0073044 with s_a006c608 ("\nNo H/W timer ISR available") instead.
 */
struct Timers {
    unsigned int w0;
    unsigned int tick;
    unsigned int w8;
    void (*cb[1][2])(int);
};
extern struct Timers DAT_a80793a4;
extern char s_a006c608[];
extern int FUN_a0073044(const char *, ...);

void FUN_a00b2070(unsigned int idx, void (*fn)(int))
{
    int j;

    for (j = 0; j < 2; j++)
        if (DAT_a80793a4.cb[idx][j] == 0)
            break;
    if (j == 2) {
        FUN_a0073044(s_a006c608);
        return;
    }
    DAT_a80793a4.cb[idx][j] = fn;
}
