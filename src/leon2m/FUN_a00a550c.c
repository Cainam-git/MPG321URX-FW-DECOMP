/* leon2m FUN_a00a550c @ 0xa00a550c  MATCH (-mcpu=v8 -O2 -g)
 * Code facts: FUN_a0146a80(3, 1, 6, 0xf9a, 0); a loop i = 0..5 of FUN_a0146b20(0, i + 3, 1, 1, i + 0x15, 0); seven
 * FUN_a0146a80 calls with the constant 0x12aa (first arguments 0x14, 0x1d, 0x25, 0x32, 0x35, 0x35, 0xd); two loops
 * of two rounds, FUN_a0146b20(0, j + 0x14, 0, 1, j + 0x1b, 0) and FUN_a0146b20(0, k + 0x1d, 0, 1, k + 0x1d, 0); then
 * four FUN_a0146b20 calls with fixed arguments. void, no parameters.
 * Matching form: each loop is a do-while with the increment after the call (the fw puts 'inc %l0' in the call's
 * delay slot or right after it, then 'and 0xff' / 'cmp' / 'bleu'); the counters are unsigned char (masked with 0xff in
 * the asm); the second FUN_a0146b20 argument is '(unsigned short)(i + offset)' (sll 16 / srl 16). Ghidra's separate
 * uVar1 / bVar2 counters are one loop counter, and its third loop increments before the call (the fw does not).
 */
extern void FUN_a0146a80(unsigned short param_1, unsigned short param_2, unsigned char param_3, unsigned short param_4, unsigned char param_5);
extern void FUN_a0146b20(unsigned char param_1, unsigned short param_2, unsigned short param_3, unsigned char param_4, unsigned char param_5, unsigned char param_6);

void FUN_a00a550c(void)
{
    unsigned char i;
    unsigned char j;
    unsigned char k;

    FUN_a0146a80(3, 1, 6, 0xf9a, 0);

    i = 0;
    do {
        FUN_a0146b20(0, (unsigned short)(i + 3), 1, 1, i + 0x15, 0);
        i++;
    } while (i <= 5);

    FUN_a0146a80(0x14, 0, 2, 0x12aa, 0);
    FUN_a0146a80(0x1d, 0, 2, 0x12aa, 0);
    FUN_a0146a80(0x25, 0, 1, 0x12aa, 0);
    FUN_a0146a80(0x32, 0, 1, 0x12aa, 0);
    FUN_a0146a80(0x35, 0, 1, 0x12aa, 0);
    FUN_a0146a80(0x35, 0, 1, 0x12aa, 0);
    FUN_a0146a80(0xd, 2, 1, 0x12aa, 0);

    j = 0;
    do {
        FUN_a0146b20(0, (unsigned short)(j + 0x14), 0, 1, j + 0x1b, 0);
        j++;
    } while (j <= 1);

    k = 0;
    do {
        FUN_a0146b20(0, (unsigned short)(k + 0x1d), 0, 1, k + 0x1d, 0);
        k++;
    } while (k <= 1);

    FUN_a0146b20(0, 0x25, 0, 1, 0x1f, 0);
    FUN_a0146b20(0, 0x32, 0, 1, 0x20, 0);
    FUN_a0146b20(0, 0x35, 0, 1, 0x21, 0);
    FUN_a0146b20(0, 0xd, 2, 1, 0x22, 0);
}
