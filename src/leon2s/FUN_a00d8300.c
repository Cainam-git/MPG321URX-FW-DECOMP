/* leon2s FUN_a00d8300 @ 0xa00d8300-0xa00d84f4, -mcpu=v8 -Os -g.
 * void. in = 8-byte stack record (first halfword cleared) filled by FUN_a00d73b4(&in, 0, 1, 0x12); message m
 * (8 bytes): 7-bit field at bits 24..30 = 0x10, 4-bit field at bits 20..23 = the same field of in. When that
 * field is 1: a = t[0], b = t[1] from func_0xa0f96400(0, 0x90, 1, 1, t) (ROM call; t cleared when it returns
 * 0). Otherwise from the register block DAT_a80760a4[DAT_a8078832] at the word indices DAT_a00b383c[0x2d] (a)
 * and [0x2e] (b), and bit 16 of m = bit 0 of the word at index DAT_a00b383c[0x2c]. r = 0, 3, 6, 9, 12, 15 for
 * a = 6, 10, 0x14, 0x1e, 1, 4 (else 0), plus 1 or 2 for (b & 0xf) == 2 or 4. Halfwords 1 and 2 of m get
 * DAT_a80760c8[r] (halfword 2 = 0 when the field is 8 and DAT_a80787f8 != 0); FUN_a00d791c(&m, 2, 1, 2, 6).
 * Source form: m is a union of the bit-fields, halfwords and words (the first field test reads the word,
 * the second the halfword).
 */
struct In { unsigned int a : 8, f20 : 4, rest : 20; unsigned int w4; };
struct Bits { unsigned int b31 : 1, f24 : 7, f20 : 4, f17 : 3, b16 : 1, low : 16; unsigned int w4; };
union Msg { struct Bits b; unsigned short h[4]; unsigned int w[2]; };
extern unsigned char DAT_a8078832;
extern unsigned short DAT_a80787f8;
extern volatile unsigned int *DAT_a80760a4[];
extern const unsigned short DAT_a00b383c[];
extern unsigned short DAT_a80760c8[];
extern void FUN_a00d73b4(void *, unsigned char, unsigned char, unsigned char);
extern unsigned char func_0xa0f96400(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern void FUN_a00d791c(void *, int, int, int, int);

void FUN_a00d8300(void)
{
    unsigned char t[2];
    union { struct In s; unsigned short h0; } in;
    union Msg m;
    unsigned char r = 0;
    unsigned char a, b;
    volatile unsigned int *regs;

    in.h0 = 0;
    FUN_a00d73b4(&in, 0, 1, 0x12);
    m.b.f24 = 0x10;
    m.b.f20 = in.s.f20;
    if (((m.w[0] >> 16) & 0xf0) == 0x10) {
        if (func_0xa0f96400(0, 0x90, 1, 1, t) == 0) {
            t[0] = 0;
            t[1] = 0;
        }
        a = t[0];
        b = t[1];
    } else {
        regs = DAT_a80760a4[DAT_a8078832];
        a = regs[DAT_a00b383c[0x5a / 2]];
        b = regs[DAT_a00b383c[0x5c / 2]];
        if (regs[DAT_a00b383c[0x58 / 2]] & 1)
            m.b.b16 = 1;
        else
            m.b.b16 = 0;
    }
    if (a == 6)
        r = 0;
    else if (a == 10)
        r = 3;
    else if (a == 0x14)
        r = 6;
    else if (a == 0x1e)
        r = 9;
    else if (a == 1)
        r = 0xc;
    else if (a == 4)
        r = 0xf;
    if ((b & 0xf) == 2)
        r++;
    else if ((b & 0xf) == 4)
        r += 2;
    if ((m.h[0] & 0xf0) == 0x80 && DAT_a80787f8 != 0) {
        m.h[1] = DAT_a80760c8[r];
        m.h[2] = 0;
    } else {
        m.h[2] = m.h[1] = DAT_a80760c8[r];
    }
    FUN_a00d791c(&m, 2, 1, 2, 6);
}
