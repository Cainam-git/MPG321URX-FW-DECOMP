/* leon2m FUN_a0093694 @ 0xa0093694 (-mcpu=v8 -O2 -g)
 * v = byte 0xA802D290 + 0x1a0: FUN_a00a813c(1, (v + 1) & 0xff, 0); byte 0xA8025C56 = that byte (read again);
 * FUN_a00a900c((word 0xA802AFEC - 14) & 0xff, 2); word 0xA802AFEC = byte (read again) + 0x57;
 * FUN_a00a9650((byte + 1) & 0xff, 1). The byte is read three times through a volatile pointer.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d430;
extern void FUN_a00a813c();
extern void FUN_a00a900c();
extern int FUN_a00a9650();

void FUN_a0093694(void)
{
    volatile unsigned char *pb = (volatile unsigned char *)0xA802D290;
    unsigned char v;
    unsigned char t;

    v = pb[0x1a0];
    FUN_a00a813c(1, (v + 1) & 0xff, 0);
    t = pb[0x1a0];
    DAT_a8025c56 = t;
    FUN_a00a900c((_DAT_a802afec - 14) & 0xff, 2);
    t = pb[0x1a0];
    _DAT_a802afec = t + 0x57;
    FUN_a00a9650((t + 1) & 0xff, 1);
}
