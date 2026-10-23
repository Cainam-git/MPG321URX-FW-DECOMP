/* FUN_a0072b7c (leon2s 0xa0072b7c-0xa0072c6c, 240 bytes), flags -mcpu=v8 -Os -g.
 * Clears bytes +0x81 and +0x80 of DAT_a80788e8, sets bit 6 of hardware register 0xc0000000, calls
 * FUN_a00b1794(1) and clears bit 6 again. Then writes the registers at 0xc00c0000: +0xc = 0x80, +0 = 0x34
 * when the word DAT_a80787dc is 96000000 (else 0xd), +4 = 0, +0xc = 0, +0xc = 3, +8 = 6, +8 = 0, +4 = 1;
 * sets bit 4 of 0x9f100090, clears bit 4 of 0x9f120028 and bit 6 of 0x9f120044, writes 0x40 to 0x9f12007c
 * and 0x10 to 0x9f120034. volatile only on the hardware registers.
 * Source form: the two byte clears are written before the first register update, +0x81 first.
 */
extern unsigned char DAT_a80788e8[];
extern unsigned int DAT_a80787dc;
extern void FUN_a00b1794(unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0072b7c(void)
{
    DAT_a80788e8[0x81] = 0;
    DAT_a80788e8[0x80] = 0;
    R(0xc0000000) |= 0x40;
    FUN_a00b1794(1);
    R(0xc0000000) &= ~0x40;
    R(0xc00c000c) = 0x80;
    R(0xc00c0000) = DAT_a80787dc == 96000000 ? 0x34 : 0xd;
    R(0xc00c0004) = 0;
    R(0xc00c000c) = 0;
    R(0xc00c000c) = 3;
    R(0xc00c0008) = 6;
    R(0xc00c0008) = 0;
    R(0xc00c0004) = 1;
    R(0x9f100090) |= 0x10;
    R(0x9f120028) &= ~0x10;
    R(0x9f120044) &= ~0x40;
    R(0x9f12007c) = 0x40;
    R(0x9f120034) = 0x10;
}
