/* FUN_a00dccd8 (leon2s 0xa00dccd8-0xa00dcdb8, 224 bytes), flags -mcpu=v8 -Os -g.
 * void (void); called by FUN_a00de8ac after it fills the halfword record DAT_a8079538 (fields +8..+0x16).
 * Writes the register block at 0xc0120800: 0x14 = 0x12000218, 0x18 = 0xffff0000, 0x1c = (h8 >> 3) << 16 | 0xffff,
 * 0x20 = (hc >> 3) << 16 | h14, 0x24 = (he + hc) >> 3 | (h16 + h14) << 16, 0x28 = ha >> 3 in both halves,
 * 0x2c = h12, 0x48 = h10 >> 3 | 0x80000000.
 * Source form: hc, h14, h12, ha >> 3 and h10 >> 3 are read into unsigned short locals and (he + hc) >> 3 into an
 * unsigned int local before the stores that precede their use; the 0x24 high half is the unsigned short sum h16 + h14,
 * with h16 read last of all record fields, and the 0x24 value is built before the 0x20 store.
 */
struct win {
    unsigned short _0[4];
    unsigned short h8, ha, hc, he, h10, h12, h14, h16;
};
extern struct win DAT_a8079538;
#define REG(o) (*(volatile unsigned int *)(0xc0120800 + (o)))

void FUN_a00dccd8(void)
{
    unsigned short h12;
    unsigned short e;
    unsigned short c;
    unsigned short t;
    unsigned short ha3;
    unsigned int lo;
    unsigned int v24;

    c = DAT_a8079538.hc;
    ha3 = DAT_a8079538.ha >> 3;
    REG(0x14) = 0x12000218;
    t = DAT_a8079538.h10 >> 3;
    lo = (DAT_a8079538.he + (unsigned int)c) >> 3;
    e = DAT_a8079538.h14;
    REG(0x18) = 0xffff0000;
    h12 = DAT_a8079538.h12;
    REG(0x1c) = ((DAT_a8079538.h8 >> 3) << 16) | 0xffff;
    v24 = lo | ((unsigned int)(unsigned short)(DAT_a8079538.h16 + e) << 16);
    REG(0x20) = ((c >> 3) << 16) | e;
    REG(0x24) = v24;
    REG(0x28) = ha3 | (ha3 << 16);
    REG(0x2c) = h12;
    REG(0x48) = t | 0x80000000;
}
