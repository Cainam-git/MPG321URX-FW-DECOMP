/* leon2s FUN_a00a2010 @ 0xa00a2010 (-mcpu=v8 -Os -g)
 * Sets (param_2 != 0) or clears (param_2 == 0) one bit of the register 0xCF0147F0: bit 2 for param_1 == 0, bit 6
 * otherwise. Both parameters are bytes ('and %o0, 0xff', 'btst 0xff, %o1'); the 'mov %o4, %o5' in the delay slots
 * carries the shared register address.
 */
#define REG_cf0147f0 (*(volatile unsigned int *)0xcf0147f0)

void FUN_a00a2010(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0) {
        if (param_1 == 0) {
            REG_cf0147f0 = REG_cf0147f0 | 4;
        } else {
            REG_cf0147f0 = REG_cf0147f0 | 0x40;
        }
    } else {
        if (param_1 == 0) {
            REG_cf0147f0 = REG_cf0147f0 & 0xfffffffb;
        } else {
            REG_cf0147f0 = REG_cf0147f0 & 0xffffffbf;
        }
    }
}
