/* FUN_a00618d8 (leon2s 0xa00618d8-0xa0061a6c, 404 bytes), flags -mcpu=v8 -Os -g.
 * Tick routine. Sets DAT_a807de92, counts the down counter DAT_a80793a0 towards 0, advances three dividers (de8c:
 * every 5 ticks sets de9c; dea0: every 50 ticks sets de90; de94: every 500 ticks sets de91), increments the tick
 * words DAT_a80793a4.tick and DAT_a807de98, then steps the 16 task records (24 bytes each, also used by
 * FUN_a00b229c): an enabled, active task with a non-zero period counts down; at 0 it is marked pending and either
 * reloaded with its period (periodic) or deactivated. Then calls the two optional callbacks cb[0], cb[1] with 0 and
 * increments DAT_a807939c. Data: DAT_a80793a4 holds a word, the tick word, a word, the two callbacks and the task
 * array (0xa80793b8). Source forms: the down counter is declared volatile; the firmware reads it again for the
 * decrement, which GCC only does for a volatile access. The non-periodic arm comes first.
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
struct Timers {
    unsigned int w0;
    unsigned int tick;
    unsigned int w8;
    void (*cb[2])(int);
    struct Task task[16];
};
extern struct Timers DAT_a80793a4;
extern volatile unsigned int DAT_a80793a0;
extern unsigned int DAT_a807939c;
extern unsigned char DAT_a807de92;
extern unsigned char DAT_a807de9c;
extern unsigned char DAT_a807de90;
extern unsigned char DAT_a807de91;
extern unsigned int DAT_a807de8c;
extern unsigned int DAT_a807dea0;
extern unsigned int DAT_a807de94;
extern unsigned int DAT_a807de98;

void FUN_a00618d8(void)
{
    int i;
    unsigned char j;
    struct Task *t;

    DAT_a807de92 = 1;
    if (DAT_a80793a0 != 0)
        DAT_a80793a0--;
    if (++DAT_a807de8c > 4) {
        DAT_a807de9c = 1;
        DAT_a807de8c = 0;
    }
    if (++DAT_a807dea0 > 0x31) {
        DAT_a807de90 = 1;
        DAT_a807dea0 = 0;
    }
    if (++DAT_a807de94 > 499) {
        DAT_a807de91 = 1;
        DAT_a807de94 = 0;
    }
    DAT_a80793a4.tick++;
    DAT_a807de98++;
    for (i = 0; i < 16; i++) {
        t = &DAT_a80793a4.task[i];
        if (t->enabled != 0 && t->active != 0 && t->period != 0) {
            if (--t->count == 0) {
                t->pending = 1;
                if (t->periodic == 0)
                    t->active = 0;
                else
                    t->count = t->period;
            }
        }
    }
    for (j = 0; j < 2; j++)
        if (DAT_a80793a4.cb[j] != 0)
            DAT_a80793a4.cb[j](0);
    DAT_a807939c++;
}
