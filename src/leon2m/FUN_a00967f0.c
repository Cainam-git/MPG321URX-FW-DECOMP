/* leon2m FUN_a00967f0 @ 0xa00967f0 (-mcpu=v8 -O3 -g)
 * v = byte 0xA802D434 (0xA802D290 + 0x1A4); stores v in byte 0xA8025C56, calls FUN_a00a813c(1, v, 0) and
 * FUN_a00a900c((word 0xA802AFEC - 24) & 0xff, 2); reads v again, stores v + 0x70 in word 0xA802AFEC, calls
 * FUN_a00a9650(v, 1) and stores 0xE in byte 0xA802B08F. Same code as FUN_a0096494 with other constants.
 * See FUN_a0096494 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a8025c56;   // 0xa8025c56
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned char DAT_a802b08f;   // 0xa802b08f
extern unsigned char DAT_a802d2a1;   // 0xa802d2a1

extern void FUN_a00a813c(int, unsigned char, int); // 0xa00a813c
extern void FUN_a00a900c(int, int); // 0xa00a900c
extern void FUN_a00a9650(int, int); // 0xa00a9650

void FUN_a00967f0(void)
{
    volatile unsigned char *pb = (volatile unsigned char *)0xA802D290;
    unsigned char v;

    v = pb[0x1a4];
    DAT_a8025c56 = v;
    FUN_a00a813c(1, v, 0);
    FUN_a00a900c((_DAT_a802afec - 24) & 0xff, 2);
    v = pb[0x1a4];
    _DAT_a802afec = v + 0x70;
    FUN_a00a9650((int)v, 1);
    DAT_a802b08f = 0xe;
}
