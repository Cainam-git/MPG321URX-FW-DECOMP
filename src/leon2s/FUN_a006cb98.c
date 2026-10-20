/* FUN_a006cb98 (leon2s, 0xa006cb98-0xa006cc24, 35 words, leaf with a tail call). Flags -mcpu=v8 -Os -g.
 * 7 params (p3/p5/p6 u16, p4 u8, p7 on the stack at [%sp+0x5c]). v = 0x1e0 if p4 == 0 or p6 < p3, else
 * p5 (u16). If v <= 0x1e0: tail call FUN_a006c9c0(p1, (p7 >> 5) + (p2 >> 3) + p6 * 60, v >> 3);
 * p6 * 60 uses the full u16 p6.
 * Source form: the || written as an if/else (firmware subx/addx + orcc, 0x1e0 in the delay slot).
 */
extern void FUN_a006c9c0(unsigned int, unsigned int, unsigned int);

void FUN_a006cb98(unsigned int param_1, unsigned int param_2, unsigned short param_3, 
                  unsigned char param_4, unsigned short param_5, unsigned short param_6,
                  unsigned int param_7)
{
    unsigned short uVar1;
    
    if (param_4 == '\0' || param_6 < param_3)
        uVar1 = 0x1e0;
    else
        uVar1 = param_5;
    if (uVar1 < 0x1e1) {
        FUN_a006c9c0(param_1, (param_7 >> 5) + (param_2 >> 3) + param_6 * 0x3c, uVar1 >> 3);
    }
}
