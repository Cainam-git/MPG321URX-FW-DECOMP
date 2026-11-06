/* FUN_a012b458 (leon2m 0xa012b458-0xa012b7b8), flags -mcpu=v8 -O3 -g.
 * Source form: the tail is the matched neighbour FUN_a012b418 inlined with FUN_a012ad80 / FUN_a012adac as
 * static copies; bit[] stores before pos[].
 * Compiler aid: __builtin_expect(n <= 2, 1) on the b00 test (block order of the b31 arm after the i == 1 block).
 */
struct __attribute__((packed, aligned(4))) Settings {
    union { unsigned int w; unsigned char b[4]; } u00;
    unsigned char p04[0x2c - 4];
    unsigned char b2c;
    unsigned short h2d:16;
    unsigned short h2f:16;
    unsigned char b31, b32, b33;
    unsigned char rest[0x50 - 0x34];
};
struct Row {
    unsigned char b00, b01, b02, b03, b04, b05, b06, b07, b08, b09, b0a, b0b, b0c, b0d, b0e, b0f, b10, b11;
    unsigned short h12;
    unsigned char b14, b15;
};
extern struct Settings DAT_a802e1a0;
extern struct Row DAT_a802d8ae[];
extern unsigned char DAT_a802e14a, DAT_a802e15c;
extern char s_001a4eb8[];
extern int FUN_a00df170();
extern void FUN_a013797c(unsigned char id, unsigned char *p);
extern unsigned char FUN_a01250a8(unsigned int);
extern void FUN_a0124b88(unsigned char, unsigned int *);
extern unsigned char FUN_a01250c4(void);
extern void FUN_a0137d08(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
static inline unsigned int pack2(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    return ((a & 3) << 6) | ((b & 3) << 4) | ((c & 3) << 2) | (d & 3);
}
static inline unsigned char pack1(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    return (a << 3) | (b << 2) | (c << 1) | d;
}
static inline void set_row(unsigned char i, unsigned char order, unsigned char mask, unsigned char b11, unsigned char en)
{
    DAT_a802d8ae[i].b08 = order;
    DAT_a802d8ae[i].b0a = mask;
    DAT_a802d8ae[i].b0b = b11;
    FUN_a0137d08(i, order, mask, b11, en);
}


void FUN_a012b458(unsigned char i)
{
    unsigned int buf[2];
    unsigned char bit[4] = {0};
    unsigned char pos[4] = {0};
    struct Row r;
    unsigned int w;
    unsigned char n, k, order, b11, en, v0, v1, v6, v7, e25;
    unsigned int p0, p1, p2, p3;
    unsigned char mask;
    unsigned char t0, t1, t2, t3;

    n = (DAT_a802e1a0.b2c >> (i * 4)) & 0xf;
    DAT_a802d8ae[i].b02 = n;
    DAT_a802d8ae[i].b00 = __builtin_expect(n <= 2, 1) ? ((unsigned char)(DAT_a802e1a0.h2f >> (i * 8)) >> (n * 2)) & 3 : (DAT_a802e1a0.b31 >> (i * 4)) & 0xf;
    DAT_a802d8ae[i].b01 = ((unsigned char)(DAT_a802e1a0.h2d >> (i * 8)) >> (n * 2)) & 3;
    DAT_a802d8ae[i].b07 = ((DAT_a802e1a0.b32 >> (i * 4)) & 0xf) >> n & 1;
    DAT_a802d8ae[i].b06 = ((DAT_a802e1a0.b33 >> (i * 4)) & 0xf) >> n & 1;
    DAT_a802d8ae[i].b03 = i == 0 ? DAT_a802e1a0.u00.b[0] & 1 : 0;
    DAT_a802d8ae[i].b08 = 0x1b;
    DAT_a802d8ae[i].b04 = 0;
    DAT_a802d8ae[i].b05 = 0;
    e25 = (DAT_a802e1a0.u00.w >> 25) & 1;
    if (e25 == 1)
        DAT_a802d8ae[i].b09 = 1;
    else
        DAT_a802d8ae[i].b09 = 0;
    DAT_a802d8ae[i].b0e = 1;
    DAT_a802d8ae[i].b0f = (DAT_a802e1a0.u00.w >> 27) & 1;
    DAT_a802d8ae[i].b0b = 0;
    DAT_a802d8ae[i].b0c = 0;
    DAT_a802d8ae[i].b0d = 0;
    DAT_a802d8ae[i].b10 = 1;
    DAT_a802d8ae[i].h12 = 600;
    DAT_a802d8ae[i].b14 = 1;
    r = DAT_a802d8ae[i];
    FUN_a013797c(i, (unsigned char *)&r);

    k = 0;
    if (i == 0)
        k = DAT_a802e14a;
    else if (i == 1)
        k = DAT_a802e15c;
    if (FUN_a01250a8(k) != 2) {
        FUN_a00df170(s_001a4eb8);
        for (;;) {
            __asm__ volatile ("nop");
            __asm__ volatile ("nop");
        }
    }
    FUN_a0124b88(k, buf);
    w = buf[0];
    p0 = (w >> 22) & 3;
    p1 = (w >> 20) & 3;
    p2 = (w >> 18) & 3;
    p3 = (w >> 16) & 3;
    t0 = (w >> 15) & 1;
    t1 = (w >> 14) & 1;
    t2 = (w >> 13) & 1;
    t3 = (w >> 12) & 1;
    bit[0] = t0;
    bit[1] = t1;
    bit[2] = t2;
    bit[3] = t3;
    pos[p0] = t0;
    pos[p1] = t1;
    pos[p2] = t2;
    pos[p3] = t3;
    order = pack2(p0, p1, p2, p3);
    b11 = (w >> 11) & 1;
    mask = pack1(pos[0], pos[1], pos[2], pos[3]);
    en = (FUN_a01250c4() >> k) & 1;
    set_row(i, order, mask, b11, en ^ 1);
}
