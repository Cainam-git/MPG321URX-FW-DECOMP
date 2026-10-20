/* leon2m FUN_a0082b00 @ 0xa0082b00, flags -mcpu=v8 -O3 -g
 * Burn-in colour cycler (called by APPTimerRoutine FUN_a0085984 in the no-signal chains while the factory
 * "Burn In" byte is set). Copies the 9-entry RGB table (27 bytes, ROM 0xFECF0: FF FF FF, 00 00 00, 00 00 00,
 * FF 00 00, 00 FF 00, 00 00 FF, 80 80 00, 80 00 80, 00 80 80) to the stack (FUN_a013c910 = memcpy);
 * FUN_a014d474(1, 0) when DAT_a802d2af != 0; func_0x4008e3c4(0, 0); unless FUN_a01279f4() toggles bit 8 of
 * DAT_a802cff4.h004 and the GPIO pairs FUN_a0124af8/ab0 (bit was clear) or FUN_a0124a68/b40 (bit was set);
 * (the bit-8 copy h is an unsigned int; the mod-9 step is unsigned) then fills port 0 with colour DAT_a802af54 (FUN_a0145fe8(0, R, G, B, 0)) and steps it, mod 9.
 */
struct Scff4 { unsigned short h000, h002, h004; };
extern struct Scff4 DAT_a802cff4;
extern unsigned char DAT_a802d2af;
extern unsigned char DAT_a802af54;
extern const unsigned char s_000fecf0[];        /* 27-byte RGB table, ROM 0xFECF0 */
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern void FUN_a014d474(unsigned char, unsigned char);
extern void func_0x4008e3c4(unsigned int, unsigned int);
extern unsigned char FUN_a01279f4(void);
extern void FUN_a0124af8(void);
extern void FUN_a0124ab0(void);
extern void FUN_a0124a68(void);
extern void FUN_a0124b40(void);
extern void FUN_a0145fe8();

void FUN_a0082b00(void)
{
    unsigned char rgb[9][3];
    unsigned int h;

    FUN_a013c910(rgb, s_000fecf0, 0x1b);
    if (DAT_a802d2af != 0)
        FUN_a014d474(1, 0);
    func_0x4008e3c4(0, 0);
    if (!FUN_a01279f4()) {
        h = DAT_a802cff4.h004;
        if (!(h & 0x100)) {
            DAT_a802cff4.h004 = h | 0x100;
            FUN_a0124af8();
            FUN_a0124ab0();
        } else {
            DAT_a802cff4.h004 = h & ~0x100;
            FUN_a0124a68();
            FUN_a0124b40();
        }
    }
    FUN_a0145fe8(0, rgb[DAT_a802af54][0], rgb[DAT_a802af54][1], rgb[DAT_a802af54][2], 0);
    DAT_a802af54 = (DAT_a802af54 + 1u) % 9;
}
