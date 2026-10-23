/* leon2m FUN_a00ae8e0 @ 0xa00ae8e0-0xa00aea3c (87 words).
 * q = FUN_a01445fc(byte 0xa802d433) * 2 + 4 (8 bits). FUN_a00b3ed0(0, 0, 0, 0). When q is 10:
 * FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0) and FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11); otherwise
 * FUN_a00b32e4(0, 0, 0x792, 3, q, 3, 0). Then FUN_a00b32e4(0, 0, 0x792, 0x12, q, 3, 0). Byte 0xa802d433 (offset 0x1a3
 * of the block at 0xa802d290) becomes FUN_a014459c((FUN_a01445fc(byte) + 1) & 3), and FUN_a00ad86c(FUN_a01445fc(new
 * byte), 1) is called. When FUN_a0143c14(0) is not 10 and bit 9 of the word 0xa802d290 is clear,
 * FUN_a00869b0(0xb, 10000) is called. Finally bit 1 of byte 0xa802b08e is set and FUN_a0090f94(10) is tail-called
 * (FUN_a0090f94 stores its halfword argument; the 10 is set in %i0 in a branch delay slot).
 * Source form: the word at +0 and the byte at +0x1a3 are members of one record, so both share the %hi register.
 */
struct R290 { unsigned int w0; unsigned char pad4[0x1a3 - 4]; unsigned char b1a3; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a00869b0(int, int);
extern void FUN_a0090f94(unsigned short);

void FUN_a00ae8e0(void)
{
    unsigned char q = FUN_a01445fc(DAT_a802d290.b1a3) * 2 + 4;

    FUN_a00b3ed0(0, 0, 0, 0);
    if (q == 10) {
        FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0);
        FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11);
    } else
        FUN_a00b32e4(0, 0, 0x792, 3, q, 3, 0);
    FUN_a00b32e4(0, 0, 0x792, 0x12, q, 3, 0);
    DAT_a802d290.b1a3 = FUN_a014459c((FUN_a01445fc(DAT_a802d290.b1a3) + 1) & 3);
    FUN_a00ad86c(FUN_a01445fc(DAT_a802d290.b1a3), 1);
    if (FUN_a0143c14(0) != 10 && !(DAT_a802d290.w0 & 0x200))
        FUN_a00869b0(0xb, 10000);
    DAT_a802b08e |= 2;
    FUN_a0090f94(10);
}
