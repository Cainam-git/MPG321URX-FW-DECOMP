/* leon2m FUN_a0126dcc @ 0xa0126dcc-0xa0126f4c (96 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * DAT_a802d890[1] = val, DAT_a802d890[0] = 0; returns when FUN_a01248c8() & 0xff is 0. Calls FUN_a00df170 with
 * s_001a4710 and DAT_a802d890[0..1], FUN_a0147aa0(0x60, 2, 0xa0, 5, 0, &DAT_a802d890, 2, 1), func_0x4008d1a0(0x32),
 * FUN_a0147ae8(0x60, 2, 0xa0, 5, 0, &DAT_a802d888, 2), FUN_a00df170 with s_001a4730 and DAT_a802d888[0..1], and
 * func_0x4008d1a0(0x32). Then, at most 10 times, while DAT_a802d888[0..1] differ from DAT_a802d890[0..1] and
 * FUN_a01248c8() & 0xff is not 0: FUN_a00df170 with s_001a4750 and both byte pairs, then the FUN_a0147aa0,
 * func_0x4008d1a0(0x32) and FUN_a0147ae8 calls as above.
 * Caller: FUN_a0126c58.
 * Source form: the second loop is a while loop with the byte compares, 'n <= 9' and the FUN_a01248c8 test in its
 * condition (fw block order: loop body before the condition blocks).
 */
extern unsigned char DAT_a802d888[2];
extern unsigned char DAT_a802d890[2];
extern int FUN_a01248c8(void);
extern unsigned short FUN_a0147aa0(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short FUN_a0147ae8(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int func_0x4008d1a0(int);
extern int FUN_a00df170(const char *, ...);
extern const char s_001a4710[];
extern const char s_001a4730[];
extern const char s_001a4750[];

void FUN_a0126dcc(unsigned char val)
{
    unsigned char n = 0;

    DAT_a802d890[1] = val;
    DAT_a802d890[0] = 0;
    if (!(FUN_a01248c8() & 0xff)) return;
    FUN_a00df170(s_001a4710, DAT_a802d890[0], DAT_a802d890[1]);
    FUN_a0147aa0(0x60, 2, 0xa0, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
    func_0x4008d1a0(0x32);
    FUN_a0147ae8(0x60, 2, 0xa0, 5, 0, (unsigned int)&DAT_a802d888, 2);
    FUN_a00df170(s_001a4730, DAT_a802d888[0], DAT_a802d888[1]);
    func_0x4008d1a0(0x32);
    while ((DAT_a802d890[1] != DAT_a802d888[1] || DAT_a802d890[0] != DAT_a802d888[0]) && n <= 9 && (FUN_a01248c8() & 0xff)) {
        FUN_a00df170(s_001a4750, DAT_a802d890[0], DAT_a802d890[1], DAT_a802d888[0], DAT_a802d888[1]);
        FUN_a0147aa0(0x60, 2, 0xa0, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
        func_0x4008d1a0(0x32);
        FUN_a0147ae8(0x60, 2, 0xa0, 5, 0, (unsigned int)&DAT_a802d888, 2);
        n++;
    }
}
