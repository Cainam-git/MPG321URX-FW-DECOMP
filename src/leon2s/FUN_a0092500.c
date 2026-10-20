/* leon2s FUN_a0092500 @ 0xa0092500 (-mcpu=v8 -Os -g)
 * The target does `sll %o2, 0x10, %o2; srl %o2, 0x10, %o2` which is a 16-bit mask on the offset - this matches `(unsigned short)(i + 0x144)`. The loop index `i` is used both for the offset and as pointer index, which matches the `add %i1, %l0, %l0` (pointer + index) and `ldub [%l0 + 4]` pattern.
 */
extern void FUN_a00a8054(unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a0092500(unsigned int param_1, unsigned char *param_2)
{
    unsigned char i;
    unsigned char sum;

    FUN_a00a8054(param_1 & 0xff, 0, 0x140, param_2[0]);
    FUN_a00a8054(param_1 & 0xff, 0, 0x141, param_2[1]);
    FUN_a00a8054(param_1 & 0xff, 0, 0x142, param_2[2]);

    sum = 0;
    for (i = 0; i < param_2[2]; i++) {
        FUN_a00a8054(param_1 & 0xff, 0, ((unsigned short)(i + 0x144)), param_2[i + 4]);
        sum += param_2[i + 4];
    }

    FUN_a00a8054(param_1 & 0xff, 0, 0x143, (unsigned char)(-sum));
}
