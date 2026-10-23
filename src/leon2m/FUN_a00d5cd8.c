/* leon2m FUN_a00d5cd8 @ 0xa00d5cd8-0xa00d5d8c (45 words).
 * Sets byte DAT_a802d290+0x3e: 0 when bit 17 of word +0xac is clear, else FUN_a014468c(FUN_a01445fc(
 * FUN_a014448c(x))) with x = 1 when byte +0x1f is non-zero and bit 14 of word +0xa8 is set, x = 0 otherwise.
 * Then FUN_a01478b0(byte +0x3e, 7) (tail call). Called from FUN_a00d93c8 and many others.
 * Source form: separate arms for byte +0x1f zero / non-zero, each with its own bit 17 test and calls.
 */
struct R290 {
    unsigned char pad0[0x1f];
    unsigned char b1f;
    unsigned char pad20[0x3e - 0x20];
    unsigned char b3e;
    unsigned char pad3f[0xa8 - 0x3f];
    unsigned int wa8;
    unsigned int wac;
};
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a014448c(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014468c(unsigned char);
extern void FUN_a01478b0(unsigned char, unsigned char);

void FUN_a00d5cd8(void)
{
    if (DAT_a802d290.b1f == 0) {
        if (DAT_a802d290.wac & 0x20000)
            DAT_a802d290.b3e = FUN_a014468c(FUN_a01445fc(FUN_a014448c(0)));
        else
            DAT_a802d290.b3e = 0;
    } else if (DAT_a802d290.wac & 0x20000) {
        if (DAT_a802d290.wa8 & 0x4000)
            DAT_a802d290.b3e = FUN_a014468c(FUN_a01445fc(FUN_a014448c(1)));
        else
            DAT_a802d290.b3e = FUN_a014468c(FUN_a01445fc(FUN_a014448c(0)));
    } else
        DAT_a802d290.b3e = 0;
    FUN_a01478b0(DAT_a802d290.b3e, 7);
}
