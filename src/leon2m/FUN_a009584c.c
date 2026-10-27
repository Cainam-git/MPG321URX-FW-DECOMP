/* FUN_a009584c (leon2m 0xa009584c-0xa00958c4, 120 bytes), flags -mcpu=v8 -O3 -g.
 * When the word DAT_a802afec is 0x42, stores 0x750 and 0x402 to the halfwords at DAT_a802d290 + 0x1ac and + 0x1ae
 * and calls FUN_a00a93bc(3); then calls FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1), stores 0xc to DAT_a802afec,
 * calls FUN_a00a900c(1, 1) and sets bit 1 of the byte DAT_a802b08e.
 */
struct G290 { unsigned char p0[0x1ac]; unsigned short h1ac, h1ae; };
extern struct G290 DAT_a802d290;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9468(unsigned char sel, unsigned char mode);
extern void FUN_a00b34d4(unsigned char hi, unsigned char lo);
extern void FUN_a00a900c(unsigned char, int);

void FUN_a009584c(void)
{
    if (DAT_a802afec == 0x42) {
        DAT_a802d290.h1ac = 0x750;
        DAT_a802d290.h1ae = 0x402;
        FUN_a00a93bc(3);
    }
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
    DAT_a802afec = 0xc;
    FUN_a00a900c(1, 1);
    DAT_a802b08e |= 2;
}
