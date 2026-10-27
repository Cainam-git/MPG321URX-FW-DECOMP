/* leon2s FUN_a008cba8 @ 0xa008cba8-0xa008ced8 (204 words), flags -mcpu=v8 -Os -g.
 * void (const void *src). Copies 3 bytes from src to DAT_a8076688 (memcpy, FUN_a00b15d8), then calls
 * FUN_a008a238(4), FUN_a008a470(), FUN_a008a590(), FUN_a008a6f4(), FUN_a008c9a8(1, 0, 0, 1) and, for ports
 * 0..3, FUN_a00a7168(port, 4, 0x95), (port, 5, 0x18), (port, 6, 4). Byte 0 of DAT_a8076688: bit 7 writes the
 * registers 0xcf011148 = 7, 0xcf011140 = 3, 0xcf011144 = 8, 0xcf011154 = 0, 0xcf011158 = 0xff; bit 6 calls
 * FUN_a008a1f8(0), bit 5 FUN_a008a1f8(1); bits 3..4 clear bit 0 and set bit 5 of 0xcf0111d4, set bit 5 of
 * 0xcf0111d8, write 0xcf0111dc = 0x87, pulse bit 0 of 0xcf011118 and write 0xcf0111e8 = 0, 0xcf0111ec = 0xff,
 * 0xcf0111e4 = 3. Bit 0 of byte 2 selects FUN_a008a470() or FUN_a008a7a0(). Bits 6..7 of byte 1 (1, 2, other)
 * give FUN_a00b115c(2, 1 / 2 / 0), FUN_a00a2320(0 and 1, 1 / 1 / 0), FUN_a0090e4c(2, 1 / 1 / 0); bits 4..5 of
 * byte 1 (1, 2, other) give FUN_a00b1224(2, 2 / 1 / 0), FUN_a00a2374(0 and 1, same), FUN_a0090e6c(2, same).
 * Then FUN_a008a7bc() and register 0xcf014770 = (value & 0xf) | 0x40 in two writes.
 * Source form: byte 0 read once into an unsigned int local for the first two tests; case 2 written before
 * case 1 in the first switch; the second switch lists case 0 with its own copy of the default body (it changes
 * the compare tree; the copy is merged with the default later).
 */
extern unsigned char DAT_a8076688[];
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern void FUN_a008a238(unsigned char);
extern void FUN_a008a470(void);
extern void FUN_a008a590(void);
extern void FUN_a008a6f4(void);
extern void FUN_a008c9a8(unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a00a7168(unsigned char port, unsigned char reg, unsigned char val);
extern void FUN_a008a1f8(unsigned char);
extern void FUN_a008a7a0(void);
extern void FUN_a00b115c(unsigned char, unsigned char);
extern void FUN_a00a2320(unsigned char, unsigned char);
extern void FUN_a0090e4c(unsigned char, unsigned char);
extern void FUN_a00b1224(unsigned char, unsigned char);
extern void FUN_a00a2374(unsigned char, unsigned char);
extern void FUN_a0090e6c(unsigned char, unsigned char);
extern void FUN_a008a7bc(void);

#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a008cba8(const void *src)
{
    unsigned char i;
    unsigned int c;

    memcpy(DAT_a8076688, src, 3);
    FUN_a008a238(4);
    FUN_a008a470();
    FUN_a008a590();
    FUN_a008a6f4();
    FUN_a008c9a8(1, 0, 0, 1);
    for (i = 0; i <= 3; i++) {
        FUN_a00a7168(i, 4, 0x95);
        FUN_a00a7168(i, 5, 0x18);
        FUN_a00a7168(i, 6, 4);
    }
    c = DAT_a8076688[0];
    if (c & 0x80) {
        REG(0xcf011148) = 7;
        REG(0xcf011140) = 3;
        REG(0xcf011144) = 8;
        REG(0xcf011154) = 0;
        REG(0xcf011158) = 0xff;
    }
    if (c & 0x40)
        FUN_a008a1f8(0);
    if (DAT_a8076688[0] & 0x20)
        FUN_a008a1f8(1);
    if (DAT_a8076688[0] & 0x18) {
        REG(0xcf0111d4) &= ~1;
        REG(0xcf0111d4) |= 0x20;
        REG(0xcf0111d8) |= 0x20;
        REG(0xcf0111dc) = 0x87;
        REG(0xcf011118) |= 1;
        REG(0xcf011118) &= ~1;
        REG(0xcf0111e8) = 0;
        REG(0xcf0111ec) = 0xff;
        REG(0xcf0111e4) = 3;
    }
    if (DAT_a8076688[2] & 1)
        FUN_a008a470();
    else
        FUN_a008a7a0();
    switch (DAT_a8076688[1] >> 6) {
    case 2:
        FUN_a00b115c(2, 2);
        FUN_a00a2320(0, 1);
        FUN_a00a2320(1, 1);
        FUN_a0090e4c(2, 1);
        break;
    case 1:
        FUN_a00b115c(2, 1);
        FUN_a00a2320(0, 1);
        FUN_a00a2320(1, 1);
        FUN_a0090e4c(2, 1);
        break;
    default:
        FUN_a00b115c(2, 0);
        FUN_a00a2320(0, 0);
        FUN_a00a2320(1, 0);
        FUN_a0090e4c(2, 0);
        break;
    }
    switch ((DAT_a8076688[1] >> 4) & 3) {
    case 1:
        FUN_a00b1224(2, 2);
        FUN_a00a2374(0, 2);
        FUN_a00a2374(1, 2);
        FUN_a0090e6c(2, 2);
        break;
    case 2:
        FUN_a00b1224(2, 1);
        FUN_a00a2374(0, 1);
        FUN_a00a2374(1, 1);
        FUN_a0090e6c(2, 1);
        break;
    case 0:
        FUN_a00b1224(2, 0);
        FUN_a00a2374(0, 0);
        FUN_a00a2374(1, 0);
        FUN_a0090e6c(2, 0);
        break;
    default:
        FUN_a00b1224(2, 0);
        FUN_a00a2374(0, 0);
        FUN_a00a2374(1, 0);
        FUN_a0090e6c(2, 0);
        break;
    }
    FUN_a008a7bc();
    REG(0xcf014770) &= 0xf;
    REG(0xcf014770) |= 0x40;
}
