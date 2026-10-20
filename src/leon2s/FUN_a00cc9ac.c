/*
 * FUN_a00cc9ac (leon2s, 0xa00cc9ac-0xa00cc9f8, 76 bytes), flags -mcpu=v8 -Os -g.
 * Code facts: a 2-byte stack table (fw 'clrh [%fp-16]' = the {0, 0} initializer) gets
 * buf[port] = bit 2 of func_0xa0fb7fd8(port, 0, 9) (stb 1 / clrb), and buf[port] is returned (u8).
 * Aids: none.
 */
extern unsigned int func_0xa0fb7fd8(unsigned int, unsigned int, unsigned int);

unsigned char FUN_a00cc9ac(unsigned char param_1)
{
    unsigned char buf[2] = {0, 0};

    if (func_0xa0fb7fd8(param_1, 0, 9) & 4)
        buf[param_1] = 1;
    else
        buf[param_1] = 0;
    return buf[param_1];
}
