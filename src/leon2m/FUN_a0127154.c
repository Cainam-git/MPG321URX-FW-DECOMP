/* leon2m FUN_a0127154 @ 0xa0127154-0xa01272c8 (93 words), flags -mcpu=v8 -O3 -g -msoft-float
 * (NOTE: best flags differ; with plain '-mcpu=v8 -O3 -g' jf gives 74.19, register choice differs).
 * with -msoft-float.
 * Code facts: twin of FUN_a0126ae4 with register 0x1b4 instead of 0x70: buf 0xa802d890 = {0, val};
 * FUN_a01248c8() & 0xff == 0 -> return; log FUN_a00df170(0x1a47f0, val); write FUN_a0147aa0(0x60, 2,
 * 0x1b4, 5, 0, &d890, 2, 1); func_0x4008d1a0(0x32); read back FUN_a0147ae8(0x60, 2, 0x1b4, 5, 0, &d888, 2);
 * log FUN_a00df170(0x1a4818, d888[0], d888[1]); func_0x4008d1a0(0x32); retry loop while the buffers
 * differ and the retry byte 0xa802c9fd <= 9: log FUN_a00df170(0x1a4840, ...), write,
 * func_0x4008d1a0(5), read back, retry byte++.
 * Fixes vs the autoc draft (95.70 with -msoft-float): BEHAVIOUR, the delay inside the retry loop is
 * func_0x4008d1a0(5) (fw 'mov 5, %o0'), the draft had 0x32; prototypes as in FUN_a0126ae4. Aids: none.
 */
extern unsigned char DAT_a802d888[2];
extern unsigned char DAT_a802d890[2];
extern unsigned char DAT_a802c9fd;
extern int FUN_a01248c8(void);
extern unsigned short FUN_a0147aa0(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short FUN_a0147ae8(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int func_0x4008d1a0(int);
extern int FUN_a00df170(const char *, ...);
extern const char s_001a47f0[];
extern const char s_001a4818[];
extern const char s_001a4840[];

void FUN_a0127154(unsigned char val)
{
    DAT_a802d890[1] = val;
    DAT_a802d890[0] = 0;
    if (!(FUN_a01248c8() & 0xff)) return;
    FUN_a00df170(s_001a47f0, val);
    FUN_a0147aa0(0x60, 2, 0x1b4, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
    func_0x4008d1a0(0x32);
    FUN_a0147ae8(0x60, 2, 0x1b4, 5, 0, (unsigned int)&DAT_a802d888, 2);
    FUN_a00df170(s_001a4818, DAT_a802d888[0], DAT_a802d888[1]);
    func_0x4008d1a0(0x32);
    while ((DAT_a802d890[1] != DAT_a802d888[1] || DAT_a802d890[0] != DAT_a802d888[0]) && DAT_a802c9fd <= 9) {
        FUN_a00df170(s_001a4840, DAT_a802d890[0], DAT_a802d890[1], DAT_a802d888[0], DAT_a802d888[1]);
        FUN_a0147aa0(0x60, 2, 0x1b4, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
        func_0x4008d1a0(5);
        FUN_a0147ae8(0x60, 2, 0x1b4, 5, 0, (unsigned int)&DAT_a802d888, 2);
        DAT_a802c9fd++;
    }
}
