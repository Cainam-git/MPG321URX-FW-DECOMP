/* leon2m FUN_a0126c58 @ 0xa0126c58-0xa0126dcc (93 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * NOTE: best flags differ: needs -mcpu=v8 -O3 -g -msoft-float (plain -O3 gives about 73-74, register choice),
 * like the twins FUN_a0126ae4 / FUN_a0127154. Code facts: buf 0xa802d890 = {0, val}; FUN_a01248c8() & 0xff
 * == 0 -> return. Log FUN_a00df170(0x1a4670, val); write FUN_a0147aa0(0x60, 2, 0x72, 5, 0, &d890, 2, 1)
 * (7th/8th args on the stack at %sp+0x5c/0x60); func_0x4008d1a0(0x32); read back FUN_a0147ae8(0x60, 2, 0x72,
 * 5, 0, &d888, 2); log FUN_a00df170(0x1a46a0, d888[0], d888[1]); func_0x4008d1a0(0x32). Retry loop while the
 * two 2-byte buffers differ and the retry byte 0xa802c9fd <= 9: log FUN_a00df170(0x1a46d0, d890[0], d890[1],
 * d888[0], d888[1]), write, func_0x4008d1a0(5), read back, retry byte++. Fixes vs the autoc draft: the
 * FUN_a0126ae4 form with this function's register 0x72 and format strings s_001a4670 / s_001a46a0 / s_001a46d0
 * (fw sethi|or); BEHAVIOUR: the in-loop delay is func_0x4008d1a0(5) (fw mov 5,%o0). Aids: none.
 */
extern unsigned char DAT_a802d888[2];
extern unsigned char DAT_a802d890[2];
extern unsigned char DAT_a802c9fd;
extern int FUN_a01248c8(void);
extern unsigned short FUN_a0147aa0(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short FUN_a0147ae8(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int func_0x4008d1a0(int);
extern int FUN_a00df170(const char *, ...);
extern const char s_001a4670[];
extern const char s_001a46a0[];
extern const char s_001a46d0[];

void FUN_a0126c58(unsigned char val)
{
    DAT_a802d890[1] = val;
    DAT_a802d890[0] = 0;
    if (!(FUN_a01248c8() & 0xff)) return;
    FUN_a00df170(s_001a4670, val);
    FUN_a0147aa0(0x60, 2, 0x72, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
    func_0x4008d1a0(0x32);
    FUN_a0147ae8(0x60, 2, 0x72, 5, 0, (unsigned int)&DAT_a802d888, 2);
    FUN_a00df170(s_001a46a0, DAT_a802d888[0], DAT_a802d888[1]);
    func_0x4008d1a0(0x32);
    while ((DAT_a802d890[1] != DAT_a802d888[1] || DAT_a802d890[0] != DAT_a802d888[0]) && DAT_a802c9fd <= 9) {
        FUN_a00df170(s_001a46d0, DAT_a802d890[0], DAT_a802d890[1], DAT_a802d888[0], DAT_a802d888[1]);
        FUN_a0147aa0(0x60, 2, 0x72, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
        func_0x4008d1a0(5);
        FUN_a0147ae8(0x60, 2, 0x72, 5, 0, (unsigned int)&DAT_a802d888, 2);
        DAT_a802c9fd++;
    }
}
