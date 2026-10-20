/* leon2m FUN_a00869b0 @ 0xa00869b0, flags -mcpu=v8 -O3 -g
 * APP timer start: ages all 23 u16 down-counters DAT_a802af6a[] by the ms elapsed since the last
 * tick snapshot DAT_a802af68 (FUN_a0147724 = ms tick), counters below the elapsed time become 0;
 * then sets counter 'id' to 'ms'.
 */
extern unsigned short FUN_a0147724();
extern unsigned short DAT_a802af68;
extern unsigned short DAT_a802af6a[];

void FUN_a00869b0(int id, int ms)
{
    unsigned short now = FUN_a0147724();
    unsigned short d = now - DAT_a802af68;
    unsigned char i;

    DAT_a802af68 = now;
    for (i = 0; i < 23; i++) {
        if (DAT_a802af6a[i] < d)
            DAT_a802af6a[i] = 0;
        else
            DAT_a802af6a[i] -= d;
    }
    DAT_a802af6a[id] = ms;
}
