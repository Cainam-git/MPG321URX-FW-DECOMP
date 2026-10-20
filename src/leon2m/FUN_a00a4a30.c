/* FUN_a00a4a30 (leon2m, 0xa00a4a30-0xa00a4b4c, 284 bytes, 71 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146a80(5, 8, 4, 0x792, 0); for i = 0..3 (u8): FUN_a0146b20(0, (u16)(i + 9), 8, 1, (u8)(i +
 * 0x22) when param_1 == 0 else (u8)(i + 0x1e), 0); then param_1 == 0: FUN_a0146a80(3, 8, 5, 0x792, 0) + tail
 * FUN_a0146a80(0xe, 8, 5, 0x992, 0); param_1 != 0: the same with 0x992 / 0x792 swapped.
 * Source form: the param_1 test is inside one loop (if/else around the call). -O3 loop unswitching makes the two
 * loop copies, and both copies jump back to a common exit that re-tests param_1 ('b; cmp %i0,0' in the fw); two
 * hand-written loops let jump threading skip that re-test. The '== 0' arms come first in both ifs.
 * Compiler aids: none.
 */
extern void FUN_a0146a80(unsigned short param_1, unsigned short param_2, unsigned char param_3, unsigned short param_4, unsigned char param_5);
extern void FUN_a0146b20(unsigned char param_1, unsigned short param_2, unsigned short param_3, unsigned char param_4, unsigned char param_5, unsigned char param_6);

void FUN_a00a4a30(unsigned char param_1)
{
    unsigned char i;

    FUN_a0146a80(5, 8, 4, 0x792, 0);

    i = 0;
    do {
        if (param_1 == 0)
            FUN_a0146b20(0, (unsigned short)(i + 9), 8, 1, i + 0x22, 0);
        else
            FUN_a0146b20(0, (unsigned short)(i + 9), 8, 1, i + 0x1e, 0);
        i++;
    } while (i <= 3);

    if (param_1 == 0) {
        FUN_a0146a80(3, 8, 5, 0x792, 0);
        FUN_a0146a80(0xe, 8, 5, 0x992, 0);
    } else {
        FUN_a0146a80(3, 8, 5, 0x992, 0);
        FUN_a0146a80(0xe, 8, 5, 0x792, 0);
    }
}
