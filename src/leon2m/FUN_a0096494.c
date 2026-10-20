/* leon2m FUN_a0096494 @ 0xa0096494 (-mcpu=v8 -O2 -g)
 * Reads byte 0x11 of the mode record at 0xA802D290 into DAT_a8025c56 and calls FUN_a00a813c(1, byte, 0), then
 * FUN_a00a900c((_DAT_a802afec - 24) & 0xff, 2). It reads byte 0x11 again, stores byte + 0x6c to _DAT_a802afec,
 * calls FUN_a00a9650(byte, 1) and writes 0x0D to DAT_a802b08f.
 *
 * The record is accessed through a volatile byte pointer, so byte 0x11 is loaded twice as in the target.
 */
extern unsigned char DAT_a8025c56;   // 0xa8025c56
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned char DAT_a802b08f;   // 0xa802b08f
extern unsigned char DAT_a802d2a1;   // 0xa802d2a1

extern void FUN_a00a813c(int, unsigned char, int); // 0xa00a813c
extern void FUN_a00a900c(int, int); // 0xa00a900c
extern void FUN_a00a9650(int, int); // 0xa00a9650

void FUN_a0096494(void)
{
    volatile unsigned char *pb = (volatile unsigned char *)0xA802D290;
    unsigned char v;

    v = pb[0x11];
    DAT_a8025c56 = v;
    FUN_a00a813c(1, v, 0);
    FUN_a00a900c((_DAT_a802afec - 24) & 0xff, 2);
    v = pb[0x11];
    _DAT_a802afec = v + 0x6c;
    FUN_a00a9650((int)v, 1);
    DAT_a802b08f = 0xd;
}
