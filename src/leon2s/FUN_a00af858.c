/* leon2s FUN_a00af858 @ 0xa00af858 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Sets or clears one bit of control register
 * 0xcf012448 for port param_1: the bit number comes from FUN_a00add48(port, value), where the
 * value is read through 0x9f1c6624 (same lookup as FUN_a00af94c). param_2 == 1 sets the bit,
 * anything else clears it. The second call takes the first call's
 * result as its argument.
 */
extern int func_0x9f1c6624(int);
extern int FUN_a00add48(int, int);
#define _DAT_cf012448 (*(volatile unsigned int *)0xcf012448)

void FUN_a00af858(unsigned char param_1, unsigned char param_2) {
    unsigned int shift;
    param_1 &= 0xff;
    shift = FUN_a00add48(param_1, func_0x9f1c6624(param_1) & 0xff) & 0xff;
    param_2 &= 0xff;
    if (param_2 == 1) {
        _DAT_cf012448 |= (param_2 << shift);
    } else {
        _DAT_cf012448 &= ~(1 << shift);
    }
}
