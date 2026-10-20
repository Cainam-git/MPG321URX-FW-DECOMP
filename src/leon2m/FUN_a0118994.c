/* leon2m FUN_a0118994 @ 0xa0118994-0xa0118a28 (37 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/37 mismatches.
 * Code facts: only if bit 0 of hw reg 0xcf012e00 is set, bit 0 of hw reg 0xcf0115c0 is clear and
 * bit 0 of FUN_a00f2254(p & 0xff, 0x50) is set: n = byte DAT_a802c99c + 1 (u8); if n > 0x32:
 * DAT_a802c99c = 0, then hw reg 0xcf012f00 = 0x40 when hw reg 0xcf012f24 != 0, else 0;
 * otherwise DAT_a802c99c = n. void. The volatile casts are the real 0xcf... hw registers only.
 * Fixes vs the autoc draft (82.86 -> 100): the 0xcf012f24 test is written '!= 0' with the 0x40 arm
 * first (fw falls through into the 0x40 store); FUN_a00f2254 is u8 (u8, u8) (it returns the low
 * byte of a 0xcf... register read: and %o0,0xff before retl). Aids: none.
 */
extern unsigned char DAT_a802c99c;
extern unsigned char FUN_a00f2254(unsigned char port, unsigned char reg);

#define REG_cf012e00 (*(volatile unsigned int *)0xcf012e00)
#define REG_cf0115c0 (*(volatile unsigned int *)0xcf0115c0)
#define REG_cf012f00 (*(volatile unsigned int *)0xcf012f00)
#define REG_cf012f24 (*(volatile unsigned int *)0xcf012f24)

void FUN_a0118994(unsigned int param_1)
{
    if (((REG_cf012e00 & 1) != 0) &&
        ((REG_cf0115c0 & 1) == 0) &&
        (FUN_a00f2254(param_1 & 0xff, 0x50) & 1)) {
        if ((unsigned char)(DAT_a802c99c + 1) > 0x32) {
            DAT_a802c99c = 0;
            if (REG_cf012f24 != 0) {
                REG_cf012f00 = 0x40;
            } else {
                REG_cf012f00 = 0;
            }
        } else {
            DAT_a802c99c = DAT_a802c99c + 1;
        }
    }
}
