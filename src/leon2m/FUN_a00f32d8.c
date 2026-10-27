/* leon2m FUN_a00f32d8 @ 0xa00f32d8-0xa00f3528 (148 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * on != 0: a fixed write sequence to the 0xcf0200xx / 0xcf0201xx registers (0x24..0x38 = 0, 0x3c = 0xe0, 0x74 = 0,
 * 0x80 = 0x20, 0x84 = 0, 0x40 = 0x80, 0x44 = 0x40, 0x114 = 0xe0, 0x11c = 3, 0x120 = 0xa, 0x124 = 0x48, 0x4c = 0x40,
 * 0x58 = 0xe0, 0x5c = 0x80, 0x64 = 0x80, 0x8c = 0, 0xd4 = 0xe0, 0x114 |= 0xe0), FUN_a00f1ad4(8, 1, 0x81),
 * FUN_a00f1ad4(8, 2, 0x81), FUN_a00f308c(0xcf012820, 0x800), 0xcf012800 = 0x33, 0xcf012808 = 0x81,
 * 0xcf012804 = 2, bit 1 set in 0xcf0116b8, 0xcf01141c = 0xcf011420 = 0x53, bits 0x90 cleared in 0xcf020080 and
 * bits 0xe0 set in 0xcf02006c and 0xcf02003c. on == 0: 0xcf0200d4 = 0, bits 0xe0 cleared in 0xcf020114, bits 0x41
 * cleared in 0xcf0200cc, 0xcf020134 = 0x50, 0xcf020138 = 0x22, 0xcf012800 = 0, 0xcf0200cc = 0,
 * 0xcf01141c = 0xcf011420 = 0x88. In both cases the 0x24-byte record *h is copied to 0xa802b770 (the record
 * described in FUN_a00f3528).
 */
struct hooks {
    unsigned char on;
    void *f4;
    unsigned int (*f8)(void);
    void (*fc)(unsigned char);
    unsigned int (*f10)(void);
    void *f14, *f18, *f1c, *f20;
};
extern struct hooks DAT_a802b770;
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f308c(volatile unsigned int *r, unsigned int v);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00f32d8(unsigned char on, struct hooks *h)
{
    if (on) {
        R(0xcf020024) = 0;
        R(0xcf020028) = 0;
        R(0xcf02002c) = 0;
        R(0xcf020030) = 0;
        R(0xcf020034) = 0;
        R(0xcf020038) = 0;
        R(0xcf02003c) = 0xe0;
        R(0xcf020074) = 0;
        R(0xcf020080) = 0x20;
        R(0xcf020084) = 0;
        R(0xcf020040) = 0x80;
        R(0xcf020044) = 0x40;
        R(0xcf020114) = 0xe0;
        R(0xcf02011c) = 3;
        R(0xcf020120) = 0xa;
        R(0xcf020124) = 0x48;
        R(0xcf02004c) = 0x40;
        R(0xcf020058) = 0xe0;
        R(0xcf02005c) = 0x80;
        R(0xcf020064) = 0x80;
        R(0xcf02008c) = 0;
        R(0xcf0200d4) = 0xe0;
        R(0xcf020114) |= 0xe0;
        FUN_a00f1ad4(8, 1, 0x81);
        FUN_a00f1ad4(8, 2, 0x81);
        FUN_a00f308c(&R(0xcf012820), 0x800);
        R(0xcf012800) = 0x33;
        R(0xcf012808) = 0x81;
        R(0xcf012804) = 2;
        R(0xcf0116b8) |= 2;
        R(0xcf01141c) = 0x53;
        R(0xcf011420) = 0x53;
        R(0xcf020080) &= ~0x90;
        R(0xcf02006c) |= 0xe0;
        R(0xcf02003c) |= 0xe0;
    } else {
        R(0xcf0200d4) = 0;
        R(0xcf020114) &= ~0xe0;
        R(0xcf0200cc) &= ~0x41;
        R(0xcf020134) = 0x50;
        R(0xcf020138) = 0x22;
        R(0xcf012800) = 0;
        R(0xcf0200cc) = 0;
        R(0xcf01141c) = 0x88;
        R(0xcf011420) = 0x88;
    }
    DAT_a802b770 = *h;
}
