/* FUN_a00dccd8 (leon2s 0xa00dccd8-0xa00dcdb8, 224 bytes), flags -mcpu=v8 -Os -g.
 * void (void). Programs the register block at 0xc0120800 from the halfwords +8..+0x16 of DAT_a8079538:
 * 0xc0120814 = 0x12000218, 0xc0120818 = 0xffff0000, 0xc012081c = (h8 >> 3) << 16 | 0xffff,
 * 0xc0120820 = (hc >> 3) << 16 | h14, 0xc0120824 = (he + hc) >> 3 | (unsigned short)(h16 + h14) << 16,
 * 0xc0120828 = ha >> 3 in both halves, 0xc012082c = h12, 0xc0120848 = h10 >> 3 | 0x80000000.
 * Source form: values read into locals ahead of earlier register writes: ha >> 3 (unsigned short) before the
 * 0x14 write; the (he + hc) >> 3 sum and h10 >> 3 (unsigned int) before the 0x18 write; h12 before the 0x1c
 * write; h14 and the unsigned short h16 + h14 sum before the 0x20 write; the 0x24 value composed at its write.
 */
struct win {
    unsigned short _0[4];
    unsigned short h8, ha, hc, he, h10, h12, h14, h16;
};
extern struct win DAT_a8079538;

#define REG(o) (*(volatile unsigned int *)(0xc0120800 + (o)))

void FUN_a00dccd8(void)
{
    unsigned short ha3, h12, h14, hi;
    unsigned int lo, x10;

    ha3 = DAT_a8079538.ha >> 3;
    REG(0x14) = 0x12000218;
    lo = ((unsigned int)DAT_a8079538.he + DAT_a8079538.hc) >> 3;
    x10 = DAT_a8079538.h10 >> 3;
    REG(0x18) = 0xffff0000;
    h12 = DAT_a8079538.h12;
    REG(0x1c) = 0xffff | ((DAT_a8079538.h8 >> 3) << 16);
    h14 = DAT_a8079538.h14;
    hi = DAT_a8079538.h16 + h14;
    REG(0x20) = ((DAT_a8079538.hc >> 3) << 16) | h14;
    REG(0x24) = lo | ((unsigned int)hi << 16);
    REG(0x28) = ha3 | (ha3 << 16);
    REG(0x2c) = h12;
    REG(0x48) = x10 | 0x80000000;
}
