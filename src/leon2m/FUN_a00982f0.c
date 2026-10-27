/* FUN_a00982f0 (leon2m 0xa00982f0-0xa0098364, 116 bytes), flags -mcpu=v8 -O3 -g.
 * Stores 5 to the byte DAT_a802b08f and 1 to byte 0x1a3 of DAT_a802d290, calls FUN_a00b621c(); copies byte 0x20 of
 * DAT_a802d290 (b) to DAT_a8025c55; stores FUN_a01445fc(b) + 0xd4 to the word DAT_a802afec; then calls
 * FUN_a00a9650(FUN_a01445fc(b), 0) and, as a tail call, FUN_a00a9650(FUN_a01445fc(b), 1). Source form: the form of
 * FUN_a0097b7c.
 */
extern unsigned char DAT_a802b08f, DAT_a8025c55;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern unsigned char FUN_a01445fc(unsigned char x);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00b621c(void);

void FUN_a00982f0(void)
{
    DAT_a802b08f = 5;
    DAT_a802d290[0x1a3] = 1;
    FUN_a00b621c();
    DAT_a8025c55 = DAT_a802d290[0x20];
    DAT_a802afec = FUN_a01445fc(DAT_a802d290[0x20]) + 0xd4;
    FUN_a00a9650(FUN_a01445fc(DAT_a802d290[0x20]), 0);
    FUN_a00a9650(FUN_a01445fc(DAT_a802d290[0x20]), 1);
}
