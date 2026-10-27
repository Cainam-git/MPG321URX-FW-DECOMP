/* FUN_a0096e9c (leon2m 0xa0096e9c-0xa0096f40, 164 bytes), flags -mcpu=v8 -O3 -g.
 * When FUN_a01445fc(byte 0x1e of DAT_a802d290) is 0: calls FUN_a00a8ee8(DAT_a802afec - 30),
 * FUN_a00aa01c(DAT_a802afec - 30, 0), FUN_a00a900c(FUN_a01445fc(byte 0x1e), 0), stores 6 to DAT_a802afec and calls
 * FUN_a00b4144(4, 1), FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1); otherwise stores FUN_a014459c(0) to byte 0x1e and
 * calls FUN_a00b8804().
 */
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_a802afec;
extern unsigned char FUN_a01445fc(unsigned char x);
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00aa01c(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00b4144(unsigned char, int);
extern void FUN_a00a9468(unsigned char sel, unsigned char mode);
extern void FUN_a00b34d4(unsigned char hi, unsigned char lo);
extern void FUN_a00b8804(void);

void FUN_a0096e9c(void)
{
    if (FUN_a01445fc(DAT_a802d290[0x1e]) == 0) {
        FUN_a00a8ee8(DAT_a802afec - 30);
        FUN_a00aa01c(DAT_a802afec - 30, 0);
        FUN_a00a900c(FUN_a01445fc(DAT_a802d290[0x1e]), 0);
        DAT_a802afec = 6;
        FUN_a00b4144(4, 1);
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    } else {
        DAT_a802d290[0x1e] = FUN_a014459c(0);
        FUN_a00b8804();
    }
}
