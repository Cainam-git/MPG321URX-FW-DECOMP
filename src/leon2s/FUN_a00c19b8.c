/*
 * FUN_a00c19b8 (leon2s, 0xa00c19b8-0xa00c1ac0, 264 bytes), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/66.
 * Code facts: k = (u8)(p2 - 2). p2 <= 1: sibcall func_0xa0fb65c4(p2, 0x301, mode == 1 ? 4 : 0) - 3 args
 * like its other callers (the draft passed a 4th '1': BEHAVIOUR). Else regs 0xa6/0xa5/0xa4 of k = 0 and
 * 0xa7 = 4 (mode 1) or 0 through func_0xa0fb69fc, then sibcall func_0xa0fb6aa0(k, 0xa4, 0x20, 1).
 * Form: the full call sequence in EACH arm of the p2 test, long arm first ('p2 > 1'), (u8)(p2 - 2)
 * written at each use (the FUN_a00af464 lever): -Os pre-sets the 6aa0 args i1/i2/i3 above the test.
 * A k local gives 80.30. Aids: none.
 */
extern int func_0xa0fb65c4(unsigned int, unsigned int, unsigned int);
extern void func_0xa0fb69fc(unsigned int, unsigned int, unsigned int);
extern int func_0xa0fb6aa0(unsigned int, unsigned int, unsigned int, unsigned int);

int FUN_a00c19b8(unsigned char param_1, unsigned char param_2)
{
    if (param_1 == 1) {
        if (param_2 > 1) {
            func_0xa0fb69fc((unsigned char)(param_2 - 2), 0xa6, 0);
            func_0xa0fb69fc((unsigned char)(param_2 - 2), 0xa5, 0);
            func_0xa0fb69fc((unsigned char)(param_2 - 2), 0xa4, 0);
            func_0xa0fb69fc((unsigned char)(param_2 - 2), 0xa7, 4);
            return func_0xa0fb6aa0((unsigned char)(param_2 - 2), 0xa4, 0x20, 1);
        } else {
            return func_0xa0fb65c4(param_2, 0x301, 4);
        }
    } else {
        if (param_2 > 1) {
            func_0xa0fb69fc((unsigned char)(param_2 - 2), 0xa6, 0);
            func_0xa0fb69fc((unsigned char)(param_2 - 2), 0xa5, 0);
            func_0xa0fb69fc((unsigned char)(param_2 - 2), 0xa4, 0);
            func_0xa0fb69fc((unsigned char)(param_2 - 2), 0xa7, 0);
            return func_0xa0fb6aa0((unsigned char)(param_2 - 2), 0xa4, 0x20, 1);
        } else {
            return func_0xa0fb65c4(param_2, 0x301, 0);
        }
    }
}
