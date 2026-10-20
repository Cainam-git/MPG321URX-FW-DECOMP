/* leon2m FUN_a00d93c8 @ 0xa00d93c8-0xa00d94fc (77 words).
 * Sets bit 17 of the word at 0xa802d290+0xac and toggles bit 14 of the word at +0xa8. Before the toggle, the
 * byte at +0x3e is set to FUN_a014468c(FUN_a01445fc(b) + 1), with b = byte +0x1e when bit 14 was set and byte
 * +0x20 when it was clear. Then FUN_a01479ec(1) and FUN_a00d5cd8(). FUN_a01479ec(0) follows when
 * FUN_a0143c14(1) (bit 14 set) or FUN_a0143c14(0) (bit 14 clear) returns 10. Ends with the tail call
 * FUN_a0147a14(byte +0x10 limited to 100).
 * Each arm of the toggle makes its own FUN_a01479ec(1) / FUN_a00d5cd8() calls; the 10-test is two else-if
 * arms that each re-test bit 14. The limited value is held in an unsigned short (an unsigned char local drops the
 * final and 0xff).
 */
struct R290 {
    unsigned char pad0[0x10];
    unsigned char b10;
    unsigned char pad11[0x1e - 0x11];
    unsigned char b1e;
    unsigned char pad1f;
    unsigned char b20;
    unsigned char pad21[0x3e - 0x21];
    unsigned char b3e;
    unsigned char pad3f[0xa8 - 0x3f];
    unsigned int wa8;
    unsigned int wac;
};
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014468c(unsigned char);
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a01479ec(unsigned char);
extern void FUN_a00d5cd8(void);
extern void FUN_a0147a14(unsigned char);

void FUN_a00d93c8(void)
{
    unsigned short m;

    DAT_a802d290.wac |= 0x20000;
    if (DAT_a802d290.wa8 & 0x4000) {
        DAT_a802d290.b3e = FUN_a014468c(FUN_a01445fc(DAT_a802d290.b1e) + 1);
        DAT_a802d290.wa8 &= ~0x4000;
        FUN_a01479ec(1);
        FUN_a00d5cd8();
    } else {
        DAT_a802d290.b3e = FUN_a014468c(FUN_a01445fc(DAT_a802d290.b20) + 1);
        DAT_a802d290.wa8 |= 0x4000;
        FUN_a01479ec(1);
        FUN_a00d5cd8();
    }
    if (!(DAT_a802d290.wa8 & 0x4000) && FUN_a0143c14(0) == 10)
        FUN_a01479ec(0);
    else if ((DAT_a802d290.wa8 & 0x4000) && FUN_a0143c14(1) == 10)
        FUN_a01479ec(0);
    m = DAT_a802d290.b10;
    if (m > 100)
        m = 100;
    FUN_a0147a14(m);
}
