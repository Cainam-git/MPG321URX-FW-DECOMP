/* CONV2HDMITX_UpdateInterface_3 (leon2s 0xa00b20dc-0xa00b2194, 184 bytes), flags -mcpu=v8 -Os -g.
 * When the byte DAT_a80793a4 is non-zero and the descriptor d and its function pointer are non-null: finds the
 * first of the 16 24-byte task records DAT_a80793b8 whose word at +0x10 is 0 and fills it from d (period,
 * periodic, fn, count = period, word +0x10 = d, active = 1, in this store order; three separate early-return
 * tests); when none is free, tail-calls FUN_a0073044 with
 * s_a006c628 ("\nNo S/W timer available"). Record layout as in FUN_a00618d8; counterpart of
 * CONV2HDMITX_UpdateInterface_4.
 */
struct Task {
    unsigned int periodic;
    unsigned char active;
    unsigned char pending;
    unsigned char _6[2];
    unsigned int period;
    unsigned int count;
    unsigned int enabled;
    void (*fn)(void);
};
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct Task DAT_a80793b8[16];
extern char s_a006c628[];
extern unsigned char DAT_a80793a4;
extern int FUN_a0073044(const char *, ...);

void CONV2HDMITX_UpdateInterface_3(struct TimerDesc *d)
{
    int i;
    struct Task *t;

    if (DAT_a80793a4 == 0)
        return;
    if (d == 0)
        return;
    if (d->fn == 0)
        return;
    for (i = 0; i < 16; i++) {
        t = &DAT_a80793b8[i];
        if (t->enabled == 0)
            break;
    }
    if (i == 16) {
        FUN_a0073044(s_a006c628);
        return;
    }
    t->period = d->period;
    t->periodic = d->periodic;
    t->fn = d->fn;
    t->count = d->period;
    t->enabled = (unsigned int)d;
    t->active = 1;
}
