/* FUN_a00c85e4 (leon2s, 0xa00c85e4-0xa00c8688, 164 bytes, 41 words).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: port = (u8)param_1. When param_3 == 0, twice: v = func_0xa0fb7fd8(port, 0, 0xf) and
 * func_0xa0fb8054(port, 0, 0xf, (u8)(v | 8)) (read-modify-write, bit 3 set). Then for i = 0..7:
 * param_2[i] = func_0xa0fb7fd8(port, 0, (u16)(i + 0x15)). No return value (%i0 not set).
 * Draft behaviour bug fixed: the loop always starts at 0 (fw: 'clr %l0' after the second write);
 * the draft started it at the return value of the second func_0xa0fb8054 call. void. Aids: none.
 */
extern unsigned char func_0xa0fb7fd8();
extern void func_0xa0fb8054();

void FUN_a00c85e4(unsigned int param_1, unsigned char *param_2, unsigned char param_3)
{
  unsigned char i;
  unsigned char v;

  if (param_3 == 0) {
    v = func_0xa0fb7fd8(param_1 & 0xff, 0, 0xf);
    func_0xa0fb8054(param_1 & 0xff, 0, 0xf, (unsigned char)(v | 8));
    v = func_0xa0fb7fd8(param_1 & 0xff, 0, 0xf);
    func_0xa0fb8054(param_1 & 0xff, 0, 0xf, (unsigned char)(v | 8));
  }
  i = 0;
  do {
    param_2[i] = func_0xa0fb7fd8(param_1 & 0xff, 0, (unsigned short)(i + 0x15));
    i = i + 1;
  } while (i <= 7);
}
