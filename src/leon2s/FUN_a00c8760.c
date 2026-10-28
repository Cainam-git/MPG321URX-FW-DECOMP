/*
 * FUN_a00c8760 (leon2s 0xa00c8760-0xa00c87c0, 96 bytes), flags -mcpu=v8 -Os -g. Called by FUN_a00c8b18.
 * u8 (u8 port, u8 *buf). r = FUN_a00c8048(port, 0x74, 8, 2); r != 0: func_0xa0f83044(s_9f1c1fe0, r) and returns
 * r. Otherwise calls FUN_a00c81f8(port, buf, 2) (result not used) and returns 0.
 * Same form as FUN_a00c9798 (which also checks the FUN_a00c81f8 result).
 */
extern const char s_9f1c1fe0[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned char FUN_a00c8048(unsigned char, unsigned char, unsigned char, unsigned short);
extern int FUN_a00c81f8(unsigned int, unsigned char *, unsigned short);

unsigned char FUN_a00c8760(unsigned char port, unsigned char *buf)
{
    unsigned char r;

    r = FUN_a00c8048(port, 0x74, 8, 2);
    if (r != 0) {
        func_0xa0f83044(s_9f1c1fe0, r);
        return r;
    }
    FUN_a00c81f8(port, buf, 2);
    return 0;
}
