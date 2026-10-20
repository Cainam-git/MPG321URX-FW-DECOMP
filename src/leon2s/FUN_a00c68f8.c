/* leon2s FUN_a00c68f8 @ 0xa00c68f8-0xa00c6968 (28 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: arg byte != 0 -> reg 0xcf018d00 &= ~0x40, log func_0xa0f83044(0x9f1b7608, reg & 0xff),
 * byte 0xa8078c5a = 0; arg == 0 -> reg |= 0x40, log func_0xa0f83044(0x9f1b7630, reg & 0xff),
 * byte = 1. The log argument is a fresh volatile re-read of the register after the store.
 * Fixes vs the autoc draft (96.43): BEHAVIOUR, the arm test was inverted (draft cleared the bit for
 * arg == 0); the flag byte is the symbol 0xa8078c5a itself (%lo = 0x5a on the sethi of 0xa8078c00),
 * not base 0xa8078c00 + 0x5a; draft junk locals removed. Aids: none.
 */
extern unsigned char DAT_a8078c5a;
#define _DAT_cf018d00 (*(volatile unsigned int *)0xcf018d00)
extern int func_0xa0f83044(unsigned int, ...);

void FUN_a00c68f8(unsigned char param_1)
{
    if (param_1 != 0) {
        _DAT_cf018d00 &= 0xffffffbf;
        func_0xa0f83044(0x9f1b7608, (unsigned char)_DAT_cf018d00);
        DAT_a8078c5a = 0;
    } else {
        _DAT_cf018d00 |= 0x40;
        func_0xa0f83044(0x9f1b7630, (unsigned char)_DAT_cf018d00);
        DAT_a8078c5a = 1;
    }
}
