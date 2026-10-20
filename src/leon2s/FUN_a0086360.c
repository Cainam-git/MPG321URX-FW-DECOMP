/*
 * FUN_a0086360 (leon2s, 0xa0086360-0xa008639c, 60 bytes), flags -mcpu=v8 -Os -g.
 * r = (u8)FUN_a00862e4(p1, p2, p3, 0, &param_4): the 5th argument is the address of the u8 4th parameter
 * (firmware 'stb %i3, [%fp + 0x50]' = its home slot, then 'add %fp, 0x50, %o4'). Returns the u8 0 when
 * r == 1, else 0xff (firmware xor/cmp/subx, then 'and 0xff').
 */
extern unsigned char FUN_a00862e4(unsigned char, unsigned char, unsigned int, unsigned int, unsigned char *);

unsigned char FUN_a0086360(unsigned char param_1, unsigned char param_2, unsigned int param_3, unsigned char param_4)
{
    unsigned char r = FUN_a00862e4(param_1, param_2, param_3, 0, &param_4);

    return (r == 1) ? 0 : 0xff;
}
