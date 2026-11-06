/* leon2s FUN_a007a79c @ 0xa007a79c (-mcpu=v8 -Os -g)
 * p = p1 & 0xff. FUN_a007a708(p); for i = 0..3: FUN_a00a7424(0, 7, p, DAT_a00b3b18[i]) and
 * FUN_a00a7488(p, DAT_a00b3b10[i], 0xffffff, 0x18000000). Then for each i whose bit is set in p2 & 0xff, the same
 * two calls followed by FUN_a00a7488(p, reg, mask, value) on the registers of entry i from the halfword tables
 * DAT_a00b3b40 / b50 / b38 / b48 (value 0x88000000 / 0x88), DAT_a00b3b30 / b28 (bytes 1 and 2 cleared), and again
 * b40 / b50 / b38 / b48 with 0x8000000 / 8.
 * Source form: every table write has its own 'i < 4' bound check (macro WR, as in FUN_a0079e00 and
 * FUN_a007a0a0), and so has the FUN_a00a7424 call of the second loop; the counter of the first loop is set
 * before the FUN_a007a708 call (0xa007a7a4).
 */

extern void FUN_a007a708(unsigned char param_1);
extern void FUN_a00a7424(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned short param_4);
extern void FUN_a00a7488(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern unsigned short DAT_a00b3b10[4];
extern unsigned short DAT_a00b3b18[4];
extern const unsigned short DAT_a00b3b28[4];
extern const unsigned short DAT_a00b3b30[4];
extern const unsigned short DAT_a00b3b38[4];
extern const unsigned short DAT_a00b3b40[4];
extern const unsigned short DAT_a00b3b48[4];
extern const unsigned short DAT_a00b3b50[4];

#define WR(tab, mask, val) if (i < 4) FUN_a00a7488(port, tab[i], mask, val)

void FUN_a007a79c(unsigned int param_1, int param_2)
{
  unsigned char port = param_1;
  int i;

  i = 0;
  FUN_a007a708(port);
  while (i < 4) {
    FUN_a00a7424(0, 7, port, DAT_a00b3b18[i]);
    WR(DAT_a00b3b10, 0xffffff, 0x18000000);
    i++;
  }
  for (i = 0; i < 4; i++) {
    if (((param_2 & 0xff) >> i) & 1) {
      if (i < 4)
        FUN_a00a7424(0, 7, port, DAT_a00b3b18[i]);
      WR(DAT_a00b3b10, 0xffffff, 0x18000000);
      WR(DAT_a00b3b40, 0xffffff, 0x88000000);
      WR(DAT_a00b3b50, 0xffffff00, 0x88);
      WR(DAT_a00b3b38, 0xffffff, 0x88000000);
      WR(DAT_a00b3b48, 0xffffff00, 0x88);
      WR(DAT_a00b3b30, 0xffff00ff, 0);
      WR(DAT_a00b3b28, 0xffff00ff, 0);
      WR(DAT_a00b3b30, 0xff00ffff, 0);
      WR(DAT_a00b3b28, 0xff00ffff, 0);
      WR(DAT_a00b3b40, 0xffffff, 0x8000000);
      WR(DAT_a00b3b50, 0xffffff00, 8);
      WR(DAT_a00b3b38, 0xffffff, 0x8000000);
      WR(DAT_a00b3b48, 0xffffff00, 8);
    }
  }
}
