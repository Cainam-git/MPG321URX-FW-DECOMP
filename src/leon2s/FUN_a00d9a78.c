/* leon2s FUN_a00d9a78 @ 0xa00d9a78-0xa00d9be4, -mcpu=v8 -Os -g.
 * void. Builds a stack message m (union Msg of FUN_a00d9524): clears 0x13 bytes with func_0xa0fc15ac (ROM
 * call), sets the 4-bit fields hi = 1 and cnt = 0 of word 0 and, in word 4, bits 23 and 22, f16 = 2, bits 15
 * and 14; FUN_a00d6a54(&m, 3, 1). With k = m.hi - 1 and off = k / 2 rounded up, n = m.f16: t[0] = 0x14,
 * t[1] = FUN_a00d9988(t, 1, 0, 0x30) (t = 8-byte stack buffer), and n bytes of t are copied to the 0x30-byte
 * row (DAT_a80787ff & 0xf) of ARR_a807a520 at offset off + 3. Then DAT_a8079c88[j] = off + n + 3 with
 * j = DAT_a80787ff, DAT_a80787ff = (j + 1) & 0xf, DAT_a8078854 = 1.
 * Source form: the row index is computed as (DAT_a80787ff & 0xf) * 3 into 16-byte rows (the firmware forms the
 * * 3 early and the * 16 at the loop), before h = k / 2; off = h then 'if (k & 1) off = h + 1'.
 */
union Msg {
    struct {
        unsigned int hi : 4, cnt : 4, rest : 24;
        unsigned int w1, w2, w3;
        unsigned int a : 8, b23 : 1, b22 : 1, f16 : 6, b15 : 1, b14 : 1, b13 : 1, b12 : 1, n8 : 4, low : 8;
    } h;
    unsigned char b[0x18];
};
extern unsigned char DAT_a80787ff;
extern unsigned char DAT_a8078854;
extern unsigned char DAT_a8079c88[];
extern unsigned char ARR_a807a520[][16];
extern void *func_0xa0fc15ac(void *, int, unsigned int);
extern void FUN_a00d6a54(union Msg *, int, int);
extern unsigned char FUN_a00d9988(unsigned char *, int, int, int);

void FUN_a00d9a78(void)
{
    union Msg m;
    unsigned char t[8];
    unsigned char i, n, off;
    unsigned int d, j;
    int k, h;

    func_0xa0fc15ac(&m, 0, 0x13);
    m.h.hi = 1;
    m.h.cnt = 0;
    m.h.b23 = 1;
    m.h.b22 = 1;
    m.h.f16 = 2;
    m.h.b15 = 1;
    m.h.b14 = 1;
    FUN_a00d6a54(&m, 3, 1);
    k = m.h.hi - 1;
    d = (DAT_a80787ff & 0xf) * 3;
    h = k / 2;
    off = h;
    if (k & 1)
        off = h + 1;
    n = m.h.f16;
    t[0] = 0x14;
    t[1] = FUN_a00d9988(t, 1, 0, 0x30);
    for (i = 0; i < n; i++)
        ARR_a807a520[d][i + off + 3] = t[i];
    j = DAT_a80787ff;
    DAT_a8079c88[j] = off + n + 3;
    DAT_a80787ff = (j + 1) & 0xf;
    DAT_a8078854 = 1;
}
