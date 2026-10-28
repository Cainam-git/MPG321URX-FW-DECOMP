/* leon2s FUN_a0079e00 @ 0xa0079e00-0xa0079f80 (-mcpu=v8 -Os -g)
 * void (u8 port). Tail-called by DRV_HDMI21_LMS_To_EQ and FUN_a007ac7c. For each entry i = 0..3 of the
 * halfword register tables DAT_a00b3b28 .. DAT_a00b3b50 it makes twelve FUN_a00a7488(port, reg, mask, value)
 * writes: b40 / b38 with mask 0xffffff and value 0x88000000, b50 / b48 with mask 0xffffff00 and value 0x88,
 * b30 / b28 with mask 0xffff00ff and value 0, b30 / b28 with mask 0xff00ffff and value 0xf00000, then b40 / b38
 * with 0x8000000 and b50 / b48 with 8.
 * Source form: every write has its own 'i < 4' bound check (macro WR); GCC keeps the first test of each
 * iteration and removes the others, but the separate blocks keep the port conversion ('and %i0,0xff') at each
 * call. The tables are const (read-only data), so each entry is loaded once and reused after the calls.
 */
extern const unsigned short DAT_a00b3b28[4];
extern const unsigned short DAT_a00b3b30[4];
extern const unsigned short DAT_a00b3b38[4];
extern const unsigned short DAT_a00b3b40[4];
extern const unsigned short DAT_a00b3b48[4];
extern const unsigned short DAT_a00b3b50[4];
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);

#define WR(tab, mask, val) if (i < 4) FUN_a00a7488(port, tab[i], mask, val)

void FUN_a0079e00(unsigned char port)
{
    unsigned short i;

    for (i = 0; i < 4; i++) {
        WR(DAT_a00b3b40, 0xffffff, 0x88000000);
        WR(DAT_a00b3b50, 0xffffff00, 0x88);
        WR(DAT_a00b3b38, 0xffffff, 0x88000000);
        WR(DAT_a00b3b48, 0xffffff00, 0x88);
        WR(DAT_a00b3b30, 0xffff00ff, 0);
        WR(DAT_a00b3b28, 0xffff00ff, 0);
        WR(DAT_a00b3b30, 0xff00ffff, 0xf00000);
        WR(DAT_a00b3b28, 0xff00ffff, 0xf00000);
        WR(DAT_a00b3b40, 0xffffff, 0x8000000);
        WR(DAT_a00b3b50, 0xffffff00, 8);
        WR(DAT_a00b3b38, 0xffffff, 0x8000000);
        WR(DAT_a00b3b48, 0xffffff00, 8);
    }
}
