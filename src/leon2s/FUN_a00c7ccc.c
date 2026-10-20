/*
 * FUN_a00c7ccc (leon2s, 0xa00c7ccc-0xa00c7d5c, 144 bytes), flags -mcpu=v8 -Os -g.
 * Code facts: bit 2 of port register (0, 0xf) through the ROM read/write pair func_0xa0fb7fd8
 * (port, 0, 0xf) / func_0xa0fb8054(port, 0, 0xf, v). Mode 1: clear bit 2, func_0xa0fc1794(1)
 * (delay), re-read and write (u8)(v | 4). Any other mode: write v & 0xfb. Both arms end in their
 * OWN sibcall to func_0xa0fb8054 (crossjumped into one call + restore); with one call at the join
 * the fw's early %i0/%i1/%i2 arg sets of the mode-1 arm do not appear (69.44).
 * Aids: none.
 */
extern unsigned int func_0xa0fb7fd8(unsigned int, unsigned int, unsigned int);
extern void func_0xa0fb8054(unsigned int, unsigned int, unsigned int, unsigned int);
extern void func_0xa0fc1794(unsigned int);

void FUN_a00c7ccc(unsigned char param_1, unsigned char param_2)
{
    unsigned int v;

    if (param_2 == 1) {
        v = func_0xa0fb7fd8(param_1, 0, 0xf);
        func_0xa0fb8054(param_1, 0, 0xf, v & 0xfb);
        func_0xa0fc1794(1);
        v = func_0xa0fb7fd8(param_1, 0, 0xf);
        func_0xa0fb8054(param_1, 0, 0xf, (unsigned char)(v | 4));
    } else {
        v = func_0xa0fb7fd8(param_1, 0, 0xf);
        func_0xa0fb8054(param_1, 0, 0xf, v & 0xfb);
    }
}
