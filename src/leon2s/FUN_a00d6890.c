/* leon2s FUN_a00d6890 @ 0xa00d6890 (-mcpu=v8 -Os -g)
 * v = FUN_a00d66bc(p2 & 0xff, p3 & 0xff). When v == 0 returns p1; otherwise sets bit 5 (0x20) of the byte at p1 +
 * 0x12 and returns FUN_a00d6724(p1, v, p3, p4, p5, p6).
 * Source form: Ghidra's type and symbol names are kept.
 */
extern int FUN_a00d66bc(); /* 0xa00d66bc */
extern int FUN_a00d6724(); /* 0xa00d6724 */

int FUN_a00d6890(unsigned int param_1, unsigned int param_2, unsigned int param_3,
                 unsigned int param_4, unsigned int param_5, unsigned int param_6)
{
    param_2 = FUN_a00d66bc(param_2 & 0xff, param_3 & 0xff);
    if (param_2 == 0) {
        return param_1;
    }
    *(volatile unsigned char *)(param_1 + 0x12) |= 0x20;
    return FUN_a00d6724(param_1, param_2, param_3, param_4, param_5, param_6);
}
