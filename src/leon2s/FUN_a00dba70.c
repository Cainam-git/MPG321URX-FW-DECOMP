/* leon2s FUN_a00dba70 @ 0xa00dba70-0xa00dbc8c, -mcpu=v8 -Os -g.
 * (u8 on), returns 0 or 1. Stack message m (24-byte union Msg as in FUN_a00d9524; here word 0 seen as a 7-bit
 * field at bits 24..30 = 2 and a 4-bit field at bits 20..23 = 1). m bytes 2..17 = the low bytes of words
 * 0x340..0x34f of the register block DAT_a80760a4[DAT_a8078832]; returns 0 when all 16 are 0. on == 1:
 * DAT_a8078846 and DAT_a8078843 = bytes read with func_0xa0f96400(0, 0x90, 0 / 0x21, 0, &t) (ROM call); in
 * word 4 of m bit 14 = 0, bit 13 = 1, bit 12 = 1 only when DAT_a8078846 > 0x11 and bit 0 of the second byte
 * is set, and the nibble at bits 8..11 = 3 when DAT_a8078846 <= 0x11, else 2; bit 0 of block word 0x814/4 is
 * set. Other on: bits 8..14 of word 4 cleared and bit 0 of word 0x814/4 cleared. Then FUN_a00d791c(&m, 2, 1,
 * 0x11, 0x13) and 1. The register-block pointers are volatile (as in FUN_a00da6ac).
 */
union Msg {
    struct {
        unsigned int b31 : 1, f24 : 7, f20 : 4, rest : 20;
        unsigned int w1, w2, w3;
        unsigned int a : 8, b23 : 1, b22 : 1, f16 : 6, b15 : 1, b14 : 1, b13 : 1, b12 : 1, n8 : 4, low : 8;
    } h;
    unsigned char b[0x18];
};
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078846;
extern unsigned char DAT_a8078843;
extern volatile unsigned int *DAT_a80760a4[];
extern unsigned char func_0xa0f96400(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern void FUN_a00d791c(void *, int, int, int, int);

int FUN_a00dba70(unsigned char on)
{
    union Msg m;
    unsigned char t;
    volatile unsigned int *regs;
    unsigned char i;

    m.h.f24 = 2;
    m.h.f20 = 1;
    regs = DAT_a80760a4[DAT_a8078832];
    for (i = 0; i <= 0xf; i++)
        m.b[2 + i] = regs[0x340 + i];
    for (i = 0; i <= 0xf; i++)
        if (m.b[2 + i] != 0)
            break;
    if (i > 0xf)
        return 0;
    if (on == 1) {
        func_0xa0f96400(0, 0x90, 0, 0, &t);
        DAT_a8078846 = t;
        func_0xa0f96400(0, 0x90, 0x21, 0, &t);
        DAT_a8078843 = t;
        if (DAT_a8078846 <= 0x11) {
            m.h.b14 = 0;
            m.h.b13 = 1;
            m.h.b12 = 0;
            m.h.n8 = 3;
        } else if (t & 1) {
            m.h.b14 = 0;
            m.h.b13 = 1;
            m.h.b12 = 1;
            m.h.n8 = 2;
        } else {
            m.h.b14 = 0;
            m.h.b13 = 1;
            m.h.b12 = 0;
            m.h.n8 = 2;
        }
        DAT_a80760a4[DAT_a8078832][0x814 / 4] |= 1;
    } else {
        m.h.b14 = 0;
        m.h.b13 = 0;
        m.h.b12 = 0;
        m.h.n8 = 0;
        DAT_a80760a4[DAT_a8078832][0x814 / 4] &= ~1;
    }
    FUN_a00d791c(&m, 2, 1, 0x11, 0x13);
    return 1;
}
