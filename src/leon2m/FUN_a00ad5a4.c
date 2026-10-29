/* leon2m FUN_a00ad5a4 @ 0xa00ad5a4-0xa00ad86c (178 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u8 t, u8 x, u8 y, u8 f). w = 10 for t == 3, else 16. f == 0: c0 = 0x5b9a, c1 = 0x7c2, c2 = 0xb92 and
 * a = 0x3a (byte DAT_a802d033 == 0) or 0x3e. f != 0: c0 = 0x589a, c1 = 0x742, c2 = 0x392, a = 0x38 or 0x3c, then
 * FUN_a00b3ed0(1, x, y, (u8)(w - 2)); FUN_a00b32e4(0, 1, 0x589a, x, y, 2, 0x29) and FUN_a00b32e4(0, 0, 0xa59a, x,
 * y + 2, 1, 0x2f) when y == 10 and t == 2, else FUN_a00b32e4(0, 1, 0x589a, x, y, 3, 0x29); FUN_a00b32e4(0, 1, 0x589a,
 * x + w - 1, y, 3, 0x2c); FUN_a0146c40(1, 1, 0) and FUN_a0146c40(2, 1, 0). Then for t == 3 only: (f == 0) the two
 * FUN_a00b32e4 calls with c0 at x and x + w - 1; FUN_a0146a80(x + 1, y + 1, w - 2, c1 & 0x7c2, 0) and
 * FUN_a00b32e4(1, 0, c2 & 0xb92, x + 1, y (and y + 2), w - 2, a (and a + 1)).
 * Source form: c0 is set before a in both arms; the f == 0 arm selects a with if/else, the f != 0 arm with ?:.
 * Compiler aid: '{ struct Aid s_ = { t }; }' in the else arm of the f == 0 selection emits no instructions. Its
 * initialisation puts a CLOBBER of the unused structure into that arm, so the first if-conversion pass (before
 * combine, single-set blocks only) leaves it; the CLOBBER is deleted by flow and the later pass if-converts the
 * select after combine, which keeps the firmware's 'xor x,0; addx; neg; and 4; add 0x3a' sequence.
 */
extern unsigned char DAT_a802d033;
struct Aid { unsigned int v; };
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);
extern void FUN_a00b32e4(unsigned char dir, unsigned char inc, unsigned short c, unsigned short x, unsigned char y,
                         unsigned char n, unsigned char ch);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146c40(int, int, int);

void FUN_a00ad5a4(unsigned char t, unsigned char x, unsigned char y, unsigned char f)
{
    unsigned char w = (t == 3) ? 0xa : 0x10;
    unsigned char a;
    unsigned short c0, c1, c2;

    if (f == 0) {
        c0 = 0x5b9a;
        if (DAT_a802d033 == 0)
            a = 0x3a;
        else {
            a = 0x3e;
            { struct Aid s_ = { t }; }
        }
        c1 = 0x7c2;
        c2 = 0xb92;
    } else {
        c0 = 0x589a;
        a = DAT_a802d033 == 0 ? 0x38 : 0x3c;
        c1 = 0x742;
        c2 = 0x392;
        FUN_a00b3ed0(1, x, y, (unsigned char)(w - 2));
        if (y == 0xa && t == 2) {
            FUN_a00b32e4(0, 1, 0x589a, x, y, 2, 0x29);
            FUN_a00b32e4(0, 0, 0xa59a, x, y + 2, 1, 0x2f);
        } else
            FUN_a00b32e4(0, 1, 0x589a, x, y, 3, 0x29);
        FUN_a00b32e4(0, 1, 0x589a, x + w - 1, y, 3, 0x2c);
        FUN_a0146c40(1, 1, 0);
        FUN_a0146c40(2, 1, 0);
    }
    if (t == 3) {
        if (f == 0) {
            FUN_a00b32e4(0, 1, c0, x, y, 3, 0x29);
            FUN_a00b32e4(0, 1, c0, x + w - 1, y, 3, 0x2c);
        }
        FUN_a0146a80(x + 1, y + 1, w - 2, c1 & 0x7c2, 0);
        FUN_a00b32e4(1, 0, c2 & 0xb92, x + 1, y, w - 2, a);
        FUN_a00b32e4(1, 0, c2 & 0xb92, x + 1, y + 2, w - 2, a + 1);
    }
}
