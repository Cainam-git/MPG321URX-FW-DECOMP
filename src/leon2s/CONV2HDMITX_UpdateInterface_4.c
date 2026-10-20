/* CONV2HDMITX_UpdateInterface_4 (leon2s 0xa00b2194-0xa00b222c, 152 bytes), flags -mcpu=v8 -Os -g.
 * For a non-null descriptor d: finds the first of the 16 24-byte task records DAT_a80793b8 whose word at +0x10
 * equals d (search as in FUN_a00b222c) and loads it from the descriptor: period, periodic, count = period, fn,
 * then active = 1 (this store order, with d as a struct pointer); when none matches, tail-calls FUN_a0073044 with s_a006c640 ("Can not find S/W timer!"
 * per Ghidra). Record layout as in FUN_a00618d8.
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
extern char s_a006c640[];
extern int FUN_a0073044(const char *, ...);

void CONV2HDMITX_UpdateInterface_4(struct TimerDesc *d)
{
    int i;
    struct Task *t;

    if (d == 0)
        return;
    for (i = 0; i < 16; i++) {
        t = &DAT_a80793b8[i];
        if (t->enabled == (unsigned int)d)
            break;
    }
    if (i == 16) {
        FUN_a0073044(s_a006c640);
        return;
    }
    t->period = d->period;
    t->periodic = d->periodic;
    t->count = d->period;
    t->fn = d->fn;
    t->active = 1;
}
