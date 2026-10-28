/* FUN_a00d8b90 (leon2s 0xa00d8b90-0xa00d8d20, 400 bytes), flags -mcpu=v8 -Os -g.
 * int (void). Clears the 0x10c-byte stack record big with func_0xa0fc15ac(&big, 0, 0x10c) and fills it with
 * FUN_a00d73b4(&big, 0, 1, 0x18). Stack record m: bits 24..30 of its first word = 0x21, bits 16..19 = bits
 * 20..23 of big's first word. When those bits are 1: the big.n bytes from big + 9 are passed in pieces of at most
 * 16 bytes to func_0xa0f963d4(0, 0x80, word +4 of big, piece length, address); a zero result passes
 * "Write DPCD --> FALSE!\r" to func_0xa0f834c4 and returns 0. Otherwise, with R = DAT_a80760a4[DAT_a8078832]:
 * word +4 == 0x160: FUN_a00d7bf8(), R[DAT_a00b383c[0x41]] = big + 9 (byte), FUN_a00d7ca4(); then
 * word +4 == 0x107: R[DAT_a00b383c[0x34]] = big + 9 (byte). Finally FUN_a00d791c(&m, 2, 1, 8, 2), return 1.
 * Source form: n = big.n and off = 0 are set before the bits 16..19 test; DAT_a8078832 is read through the
 * pointer cur, and the table addresses through the locals tab and ix.
 */
struct Big {
    unsigned int a : 8, f20 : 4, rest : 20;
    unsigned int type;
    unsigned char n;
    unsigned char data[0x10c - 9];
};
struct Msg { unsigned int b31 : 1, f24 : 7, h : 4, f16 : 4, low : 16; unsigned int w1; };
extern unsigned char DAT_a8078832;
extern volatile unsigned int *DAT_a80760a4[];
extern const unsigned short DAT_a00b383c[];
extern void *func_0xa0fc15ac(void *, int, unsigned int);
extern void FUN_a00d73b4(void *, unsigned char, unsigned char, unsigned char);
extern unsigned char func_0xa0f963d4(unsigned int, unsigned int, unsigned int, char, unsigned char *);
extern void func_0xa0f834c4(const char *);
extern const char s_9f1cc9f0[];
extern void FUN_a00d7bf8(void);
extern void FUN_a00d7ca4(void);
extern void FUN_a00d791c(void *, int, int, int, int);

int FUN_a00d8b90(void)
{
    struct Big big;
    struct Msg m;
    unsigned short n, off;
    unsigned char c;
    volatile unsigned int *regs;
    unsigned int k;
    volatile unsigned int **tab;
    const unsigned short *ix;
    unsigned char *cur;

    func_0xa0fc15ac(&big, 0, 0x10c);
    tab = DAT_a80760a4;
    ix = DAT_a00b383c;
    FUN_a00d73b4(&big, 0, 1, 0x18);
    m.f24 = 0x21;
    m.f16 = big.f20;
    cur = &DAT_a8078832;
    n = big.n;
    off = 0;
    if (m.f16 == 1) {
        while (n != 0) {
            if (n > 0x10) {
                c = 0x10;
                n -= 0x10;
            } else {
                c = n;
                n = 0;
            }
            if (func_0xa0f963d4(0, 0x80, big.type, c, &big.data[off]) == 0) {
                func_0xa0f834c4(s_9f1cc9f0);
                return 0;
            }
            off += c;
        }
        goto out;
    }
    if (big.type == 0x160) {
        regs = tab[*cur];
        k = ix[0x82 / 2];
        FUN_a00d7bf8();
        regs[k] = big.data[0];
        FUN_a00d7ca4();
    }
    if (big.type == 0x107)
        tab[*cur][ix[0x68 / 2]] = big.data[0];
out:
    FUN_a00d791c(&m, 2, 1, 8, 2);
    return 1;
}
