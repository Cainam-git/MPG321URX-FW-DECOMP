/* leon2m FUN_a00a9dac @ 0xa00a9dac  (-mcpu=v8 -O3 -g)
 * id = 3 when flag != 0, else 4; row = sel * 2 + 5. Calls FUN_a0146c40(id, 0, 0), then
 * FUN_a0146870(id, 0x3A8, row * 36 + a, 0x4F7, row * 36 + b, 0) with (a, b) = (0x1A, 0x51) when flag != 0, else
 * (0x16, 0x55), and FUN_a0146c40(id, 1, 0). When flag != 0 it then calls FUN_a00b3ed0(1, 0x27, row, 0xE),
 * FUN_a00b32e4(0, 1, 0x589A, 0x27, row, 3, 0xA6), FUN_a00b32e4(0, 1, 0x589A, 0x34, row, 3, 0xA9),
 * FUN_a0146c40(1, 1, 0) and FUN_a0146c40(2, 1, 0).
 * Callers: FUN_a0095778, FUN_a009b864, FUN_a009b8e0.
 * Source form: a 5-byte local struct is filled ({0, w, 0, 0, 0} with w = 4 when flag != 0, else 0xC) and never
 * read; the firmware keeps these stack stores (the same values are passed to FUN_a014667c in FUN_a00ad86c).
 */
struct Box { unsigned char a, w, c, d, e; };
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00a9dac(unsigned char sel, unsigned char flag)
{
    unsigned char id = flag ? 3 : 4;
    unsigned char row = sel * 2 + 5;
    struct Box s;

    FUN_a0146c40(id, 0, 0);
    s.a = 0;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    if (flag) {
        s.w = 4;
        FUN_a0146870(id, 0x3a8, row * 36 + 0x1a, 0x4f7, row * 36 + 0x51, 0);
    } else {
        s.w = 0xc;
        FUN_a0146870(id, 0x3a8, row * 36 + 0x16, 0x4f7, row * 36 + 0x55, 0);
    }
    FUN_a0146c40(id, 1, 0);
    if (flag) {
        FUN_a00b3ed0(1, 0x27, row, 0xe);
        FUN_a00b32e4(0, 1, 0x589a, 0x27, row, 3, 0xa6);
        FUN_a00b32e4(0, 1, 0x589a, 0x34, row, 3, 0xa9);
        FUN_a0146c40(1, 1, 0);
        FUN_a0146c40(2, 1, 0);
    }
}
