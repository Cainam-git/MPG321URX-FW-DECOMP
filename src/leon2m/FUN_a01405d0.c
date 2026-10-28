/* leon2m FUN_a01405d0 @ 0xa01405d0-0xa0140a0c (271 words), -mcpu=v8 -O3 -g.
 * For the device record DAT_001a69fe[dev] (38 bytes) whose byte b0 = b has bit 7 set (otherwise it returns at
 * once): when the ROM area record DAT_001a6a24[b].b2 is 1, calls FUN_a0124ed0(), FUN_a0134428(DAT_a802a47a, 8) and
 * FUN_a0124eb4(). Otherwise it advances the index byte DAT_a802cbdc[b].b8 (12-byte RAM rows): cur = b8; when
 * cur != 0xff, b8 = nxt = (cur + 3) % DAT_a802cbdc[b].b9 and, with per = 16 / DAT_001a69fe[dev].b4, the local
 * 4-byte record st gets f0 = 1, cur, blk = (nxt % per == 0) and f1 = 0 when blk and nxt < cur < nxt + per, else 1;
 * when cur == 0xff, b8 = 0 and st = {1, 0, 0, 0xff}. row_addr(dev, i) gives the 16-bit address
 * i * (b4 << 8) + DAT_a802cbdc[b].h0 (i = b8 when i is 0xff; 0xffff when that is 0xff too) when DAT_001a6a24[b].b2
 * is 0, else (h0 + (DAT_001a69fe[dev].b1 << 11)) & 0xf800; old = row_addr(dev, cur), new = row_addr(dev, 0xff).
 * Then, with n = b4: FUN_a0124ed0(); blk set: FUN_a0134464(area_base(dev)) (area_base = (b8 * (b4 << 8) + h0) &
 * 0xf000 when DAT_001a6a24[b].b3 is 0, else (h0 + (b1 << 11)) & 0xf000); f0 set: FUN_a013588c(n * 256 - 1, 1,
 * DAT_a802a478); FUN_a0134428(new, n); f1 set: FUN_a013588c(n * 256 - 1, 1, DAT_a802cbd8), FUN_a0134428(old, n),
 * FUN_a0134394(new, n); finally FUN_a0124eb4(). Record layouts as in FUN_a0140360.
 * Called by FUN_a012cfac, FUN_a012e928, FUN_a0140a0c, FUN_a0140ab4, FUN_a0140b78 and FUN_a0140e74.
 * Source form: st is written through a pointer p = &st and read directly (the firmware rebuilds the frame address
 * at the shared f1 = 1 store; st.cur is stored but never read); the cur != 0xff arm comes first and the 0xff arm
 * assigns cur = 0xff again (the firmware sets the register to -1 there); the f1 test is grouped as
 * 'blk && (nxt < cur && cur < nxt + per)' (the ungrouped '&&' is folded into flag arithmetic). row_addr and
 * area_base are inlined static helpers with one exit and an unsigned short result variable, so the masks are
 * 16-bit immediates and the conversion follows the join; row_addr selects the index with '?:' into a new
 * variable; the sums are written h0 + (b1 << 11).
 */
struct B38 { unsigned char b0, b1; unsigned short h2; unsigned char b4; char name[33]; };
struct A36 { unsigned short h0; unsigned char b2, b3; char name[32]; };
struct D12 { unsigned short h0; unsigned short h2; int w4; unsigned char b8, b9; unsigned char pad[2]; };
struct St { unsigned char f0, f1, blk, cur; };
extern const struct B38 DAT_001a69fe[];
extern const struct A36 DAT_001a6a24[];
extern struct D12 DAT_a802cbdc[];
extern unsigned short DAT_a802a47a;
extern unsigned char DAT_a802a478[], DAT_a802cbd8[];
extern void FUN_a0124ed0(void);
extern void FUN_a0124eb4(void);
extern void FUN_a0134464(unsigned short);
extern void FUN_a0134428(unsigned short, unsigned char);
extern void FUN_a0134394(unsigned short, unsigned char);
extern void FUN_a013588c(unsigned short, unsigned short, unsigned char *);

static unsigned short area_base(unsigned char dev)
{
    unsigned char b = DAT_001a69fe[dev].b0;
    unsigned short a;

    if (DAT_001a6a24[b].b3 == 0)
        a = (DAT_a802cbdc[b].b8 * (DAT_001a69fe[dev].b4 << 8) + DAT_a802cbdc[b].h0) & 0xf000;
    else
        a = (DAT_a802cbdc[b].h0 + (DAT_001a69fe[dev].b1 << 11)) & 0xf000;
    return a;
}

static unsigned short row_addr(unsigned char dev, unsigned char s)
{
    unsigned char b = DAT_001a69fe[dev].b0;
    unsigned short a;
    unsigned char t;

    if (DAT_001a6a24[b].b2 == 0) {
        t = s == 0xff ? DAT_a802cbdc[b].b8 : s;
        if (t == 0xff)
            a = -1;
        else
            a = t * (DAT_001a69fe[dev].b4 << 8) + DAT_a802cbdc[b].h0;
    } else
        a = (DAT_a802cbdc[b].h0 + (DAT_001a69fe[dev].b1 << 11)) & 0xf800;
    return a;
}

void FUN_a01405d0(unsigned char dev)
{
    unsigned char b = DAT_001a69fe[dev].b0;
    unsigned char cur;
    unsigned char nxt, n;
    int per;
    unsigned short old, new;
    struct St st;
    struct St *p = &st;

    if ((signed char)DAT_001a69fe[dev].b0 >= 0)
        return;
    if (DAT_001a6a24[b].b2 == 1) {
        FUN_a0124ed0();
        FUN_a0134428(DAT_a802a47a, 8);
        FUN_a0124eb4();
        return;
    }
    cur = DAT_a802cbdc[b].b8;
    if (cur != 0xff) {
        nxt = (cur + 3) % DAT_a802cbdc[b].b9;
        per = 16 / DAT_001a69fe[dev].b4;
        DAT_a802cbdc[b].b8 = nxt;
        p->f0 = 1;
        p->cur = cur;
        p->blk = nxt % per == 0;
        if (p->blk && (nxt < cur && cur < nxt + per))
            p->f1 = 0;
        else
            p->f1 = 1;
    } else {
        DAT_a802cbdc[b].b8 = 0;
        cur = 0xff;
        p->f0 = 1;
        p->cur = cur;
        p->blk = 0;
        p->f1 = 0;
    }
    old = row_addr(dev, cur);
    new = row_addr(dev, 0xff);
    n = DAT_001a69fe[dev].b4;
    FUN_a0124ed0();
    if (st.blk)
        FUN_a0134464(area_base(dev));
    if (st.f0)
        FUN_a013588c(n * 256 - 1, 1, DAT_a802a478);
    FUN_a0134428(new, n);
    if (st.f1) {
        FUN_a013588c(n * 256 - 1, 1, DAT_a802cbd8);
        FUN_a0134428(old, n);
        FUN_a0134394(new, n);
    }
    FUN_a0124eb4();
}
