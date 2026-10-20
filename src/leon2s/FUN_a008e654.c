/* leon2s FUN_a008e654 @ 0xa008e654-0xa008e6b8 (25 words), flags -mcpu=v8 -Os -g.
 * (u8 port, u8 mode, 4 words passed through). FUN_a008e054(port, mode == 1 ? 0 : 1), then
 * FUN_a008da88(port, 1), FUN_a008df40(port, 1), FUN_a00b1794(1), FUN_a008df7c(port, 1), and the sibcall
 * FUN_a008e004(port, mode, p3, p4, p5, p6) (%i2..%i5 untouched). void.
 * Source form: the first step is an if/else with two FUN_a008e054 calls (gcc crossjumps them into one call
 * with %o1 = 0/1; this keeps the firmware's separate 'and %i0,0xff,%g1' copy and the second
 * 'and %i0,0xff,%i0'). A computed 0/1 argument gives an extra 'and %o1,1'.
 */
extern void FUN_a008da88(unsigned char, unsigned char);
extern void FUN_a008df40(unsigned char, unsigned char);
extern void FUN_a008df7c(unsigned char, unsigned char);
extern void FUN_a008e004(unsigned char, unsigned char, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a008e054(unsigned char, unsigned char);
extern void FUN_a00b1794(unsigned char);

void FUN_a008e654(unsigned char param_1, unsigned char param_2, unsigned int param_3, unsigned int param_4,
                  unsigned int param_5, unsigned int param_6)
{
    if (param_2 == 1)
        FUN_a008e054(param_1, 0);
    else
        FUN_a008e054(param_1, 1);
    FUN_a008da88(param_1, 1);
    FUN_a008df40(param_1, 1);
    FUN_a00b1794(1);
    FUN_a008df7c(param_1, 1);
    FUN_a008e004(param_1, param_2, param_3, param_4, param_5, param_6);
}
