/* leon2m FUN_a0096610 @ 0xa0096610-0xa009665c (19 words), flags -mcpu=v8 -O3 -g.
 * Sibling of src FUN_a009665c.
 * void(void). On the mode record DAT_a802d290: [0x11] = 3, then the copies [0x8c] = [0x12], [0x8d] = [0x13],
 * [0x8e] = [0x14]; then DAT_a802afec = 0xca; calls FUN_a00b7474() (no arguments; it sets its own %o0 at entry) and
 * tail-calls FUN_a00a9650(0, 1).
 * Required source form: the record is addressed from its base DAT_a802d290 (byte array), no extra parameters are
 * forwarded, and the stores are written in ascending record-offset order with the afec store last (sched2 then
 * emits 8e, afec, 11, 8c, 8d as in the target).
 */
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_a802afec;
extern void FUN_a00b7474(void);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0096610(void)
{
    DAT_a802d290[0x11] = 3;
    DAT_a802d290[0x8c] = DAT_a802d290[0x12];
    DAT_a802d290[0x8d] = DAT_a802d290[0x13];
    DAT_a802d290[0x8e] = DAT_a802d290[0x14];
    DAT_a802afec = 0xca;
    FUN_a00b7474();
    FUN_a00a9650(0, 1);
}
