/* leon2s FUN_a00a6260 @ 0xa00a6260-0xa00a63a8 (82 words).
 * flags -mcpu=v8 -Os -g.
 * Code facts: (u8 p, u16 *rec), void. i = 0 for p == 0x51, 1 for p == 0x61, else return. The callees get i
 * (0/1), not p. Byte offsets: rec[0x48] = a2750(i), [0x14] = a2788(i), [0x10] = a27f8(i), [0x16] = a27f8(i),
 * [0x18] = a27c0(i) <= 7 ? 2 : a27c0(i) (called again), [0x20] = a27a4(i), [0x24] = a2814(i),
 * [0x38] = (a2788(i) - a27dc(i) - a27a4(i)) / 8 (signed), x = rec[0x20] re-read (u16):
 * [0x1a] = 5 for x < 480, 10 for 480 <= x < 960 (gcc folds this range test to (u16)(x - 480) < 480),
 * 0x14 for x >= 960, else 10. Then [0x4a] = a276c(i), [0x4c] = a284c(i).
 * Fix: the [0x1a] chain is an if/else-if chain with its OWN STORE in each arm and an explicit
 * 'x >= 0x1e0 &&' range test, x unsigned short. With one shared 'v' (the earlier form) post-reload if-conversion
 * (ce3, IF-CASE-1) hoists 'mov 5' above the branch and reorg fills both delay slots differently; that form
 * also fixes the 'mov 2' slot of the cmp-7 test. No aids.
 */
extern unsigned short FUN_a00a2750(unsigned int);
extern unsigned short FUN_a00a276c(unsigned int);
extern unsigned short FUN_a00a2788(unsigned int);
extern unsigned short FUN_a00a27a4(unsigned int);
extern unsigned short FUN_a00a27c0(unsigned int);
extern unsigned short FUN_a00a27dc(unsigned int);
extern unsigned short FUN_a00a27f8(unsigned int);
extern unsigned short FUN_a00a2814(unsigned int);
extern unsigned short FUN_a00a284c(unsigned int);

void FUN_a00a6260(unsigned char param_1, unsigned short *param_2)
{
    unsigned char i;
    int d;
    unsigned short x;

    if (param_1 == 0x51)
        i = 0;
    else if (param_1 == 0x61)
        i = 1;
    else
        return;
    param_2[0x48 / 2] = FUN_a00a2750(i);
    param_2[0x14 / 2] = FUN_a00a2788(i);
    param_2[0x10 / 2] = FUN_a00a27f8(i);
    param_2[0x16 / 2] = FUN_a00a27f8(i);
    if (FUN_a00a27c0(i) <= 7)
        param_2[0x18 / 2] = 2;
    else
        param_2[0x18 / 2] = FUN_a00a27c0(i);
    param_2[0x20 / 2] = FUN_a00a27a4(i);
    param_2[0x24 / 2] = FUN_a00a2814(i);
    d = FUN_a00a2788(i);
    d -= FUN_a00a27dc(i);
    d -= FUN_a00a27a4(i);
    param_2[0x38 / 2] = d / 8;
    x = param_2[0x20 / 2];
    if (x < 0x1e0)
        param_2[0x1a / 2] = 5;
    else if (x >= 0x1e0 && x < 0x3c0)
        param_2[0x1a / 2] = 10;
    else if (x >= 0x3c0)
        param_2[0x1a / 2] = 0x14;
    else
        param_2[0x1a / 2] = 10;
    param_2[0x4a / 2] = FUN_a00a276c(i);
    param_2[0x4c / 2] = FUN_a00a284c(i);
}
