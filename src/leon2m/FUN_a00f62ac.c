/* leon2m FUN_a00f62ac @ 0xa00f62ac-0xa00f6340, flags -mcpu=v8 -O3 -g -msoft-float.
 * Reads block register 0x36 of block blk (FUN_a00f1a90); when bit 1 (0x02) is set it returns 0 without writing.
 * Otherwise it reads register 0x9d (r = value != 0) and register 0x04, then writes register 0x36 through
 * FUN_a00f1ad4: 0x6e when the low nibble of register 0x04 is 0 or 1 and r is 0, else 0x2e. Returns 1.
 * Source form: nested ifs, the outer one on the low nibble, the inner one on r, with the 0x2e write in both the
 *   inner then-arm and the outer else-arm (cross-jumping merges the calls); the outer else-arm call then has no
 *   jump after it at the first scheduling pass, so its argument moves stay below the nibble compare.
 *   The other matched functions of this file use -msoft-float; this one gives the same bytes without it.
 */
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);

int FUN_a00f62ac(unsigned char blk)
{
    unsigned char r;

    if (FUN_a00f1a90(blk, 0x36) & 2)
        return 0;
    r = FUN_a00f1a90(blk, 0x9d) != 0;
    if ((FUN_a00f1a90(blk, 4) & 0xf) <= 1) {
        if (r)
            FUN_a00f1ad4(blk, 0x36, 0x2e);
        else
            FUN_a00f1ad4(blk, 0x36, 0x6e);
    } else
        FUN_a00f1ad4(blk, 0x36, 0x2e);
    return 1;
}
