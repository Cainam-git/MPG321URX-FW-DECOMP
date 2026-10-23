/* FUN_a006e2c4 (leon2s 0xa006e2c4-0xa006e430, 364 bytes), flags -mcpu=v8 -Os -g.
 * Fills the output record out for port from the 400-byte port record ARR_a807d7e0[port]: byte +0x12 =
 * rec byte +0x19, then FUN_a006e0e4(out, port, rec). When rec byte +0x2d is 1, or FUN_a00a2080(port) returns 0
 * in its low byte, the halfwords +2, +6 and +0xa get rec +0x1a, +0x1e and +0x32 / 10; otherwise twice those
 * values. +4 and +8 get rec +0x1c and +0x20. Prints the eight fields with the firmware's "usLINKHtotal(%d)" ...
 * "ucPHYStatus(%d)" strings and sets byte +0xf to 1.
 * Source form: the record pointer is taken from a pointer to the array (base before the multiply); three
 * arms (== 1, call result, else) with the plain copy written twice.
 */
struct Rec400 {
    unsigned char b0[0x19];
    unsigned char b19;
    unsigned short h1a, h1c, h1e, h20;
    unsigned char b22[0x2d - 0x22];
    unsigned char b2d;
    unsigned char b2e[4];
    unsigned short h32;
    unsigned char rest[400 - 0x34];
};
struct LinkInfo {
    unsigned char b0, b1;
    unsigned short htotal, vtotal, hde, vde, clk;
    unsigned char clrspace, phystatus, be, bf;
    unsigned char b10, b11, colordepth;
};
extern struct Rec400 ARR_a807d7e0[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a006e0e4(struct LinkInfo *, unsigned char, struct Rec400 *);
extern int FUN_a00a2080(unsigned int);

void FUN_a006e2c4(struct LinkInfo *out, unsigned char port)
{
    struct Rec400 *t = ARR_a807d7e0;
    struct Rec400 *rec = t + port;

    out->colordepth = rec->b19;
    FUN_a006e0e4(out, port, rec);
    if (rec->b2d == 1) {
        out->htotal = rec->h1a;
        out->hde = rec->h1e;
        out->clk = rec->h32 / 10;
    } else if ((unsigned char)FUN_a00a2080(port)) {
        out->htotal = rec->h1a * 2;
        out->hde = rec->h1e * 2;
        out->clk = rec->h32 / 10 * 2;
    } else {
        out->htotal = rec->h1a;
        out->hde = rec->h1e;
        out->clk = rec->h32 / 10;
    }
    out->vtotal = ARR_a807d7e0[port].h1c;
    out->vde = ARR_a807d7e0[port].h20;
    FUN_a0073044("usLINKHtotal(%d)\r\n", out->htotal);
    FUN_a0073044("usLINKVtotal(%d)\r\n", out->vtotal);
    FUN_a0073044("usLINKHrtlDE(%d)\r\n", out->hde);
    FUN_a0073044("usLINKVrtlDE(%d)\r\n", out->vde);
    FUN_a0073044("usLINKClk(%d)\r\n", out->clk);
    FUN_a0073044("ucClrSpace(%d)\r\n", out->clrspace);
    FUN_a0073044("ucColordepth(%d)\r\n", out->colordepth);
    FUN_a0073044("ucPHYStatus(%d)\r\n\r\n", out->phystatus);
    out->bf = 1;
}
