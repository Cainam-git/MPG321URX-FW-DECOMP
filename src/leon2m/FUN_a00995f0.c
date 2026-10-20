/* leon2m FUN_a00995f0 @ 0xa00995f0-0xa0099658 (26 words).
 * Same code as FUN_a0093694, whose comment describes it, with other constants (template -> this function):
 * 0x1 -> 0x2 (v + 1, t + 1), 14 -> 11 (word 0xa802afec - 14), 0x57 -> 0x46, 0x1a0 -> 0x4a
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d430;
extern void FUN_a00a813c();
extern void FUN_a00a900c();
extern int FUN_a00a9650();

void FUN_a00995f0(void)
{
    volatile unsigned char *pb = (volatile unsigned char *)0xA802D290;
    unsigned char v;
    unsigned char t;

    v = pb[0x4a];
    FUN_a00a813c(1, (v + 2) & 0xff, 0);
    t = pb[0x4a];
    DAT_a8025c56 = t;
    FUN_a00a900c((_DAT_a802afec - 11) & 0xff, 2);
    t = pb[0x4a];
    _DAT_a802afec = t + 0x46;
    FUN_a00a9650((t + 2) & 0xff, 1);
}
