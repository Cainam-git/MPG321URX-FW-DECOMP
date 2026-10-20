/* leon2m FUN_a0099864 @ 0xa0099864-0xa0099970 (67 words).
 * Calls FUN_a0099658. When the word at 0xa802afec is above 0x45, calls FUN_a0146a80(9, 0x13, 0xc, c, 0) with
 * c = 0x292 when FUN_a00d7d48 returns non-zero and c = 0x792 otherwise. Then FUN_a00a93bc(byte 0xa8025c56 + 2),
 * FUN_a00a813c(1, byte 0xa8025c56 + 2, 0), FUN_a00a9650(word 0xa802afec - 0x44, 0), FUN_a00a813c(1, b + 2, 0)
 * and FUN_a00a813c(1, b + 2, 1) with b = byte 0xa802d290+0x4a, stores 0xd to the word at 0xa802afec,
 * calls FUN_a00a900c(2, 1) and sets bit 1 of the byte at 0xa802b08e.
 */
struct R290 { unsigned char pad[0x4a]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern void FUN_a0099658(void);
extern int FUN_a00d7d48(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);

void FUN_a0099864(void)
{
    FUN_a0099658();
    if (_DAT_a802afec > 0x45) {
        if (FUN_a00d7d48() != 0)
            FUN_a0146a80(9, 0x13, 0xc, 0x292, 0);
        else
            FUN_a0146a80(9, 0x13, 0xc, 0x792, 0);
    }
    FUN_a00a93bc(DAT_a8025c56 + 2);
    FUN_a00a813c(1, DAT_a8025c56 + 2, 0);
    FUN_a00a9650(_DAT_a802afec - 0x44, 0);
    FUN_a00a813c(1, DAT_a802d290.b + 2, 0);
    FUN_a00a813c(1, DAT_a802d290.b + 2, 1);
    _DAT_a802afec = 0xd;
    FUN_a00a900c(2, 1);
    DAT_a802b08e |= 2;
}
