/* leon2m FUN_a00f6d80 @ 0xa00f6d80-0xa00f6dd8 (22 words), flags -mcpu=v8 -O3 -g. Called by FUN_a01471a0.
 * v = the u8 parameter with bit 7 toggled (p & 0x7f if bit 7 is set, else p | 0x80). If the hook word
 * _DAT_a802b7b8 is non-zero it is called as hook(0, v); otherwise v is written to the word register
 * 0xcf00ef04. void. Same form as FUN_a00f6e30 (selector 2, register 0xcf00ef0c).
 */
extern void (*_DAT_a802b7b8)(int, unsigned int);

void FUN_a00f6d80(unsigned char param_1)
{
  unsigned char v;

  v = param_1 | 0x80;
  if (param_1 & 0x80)
    v = param_1 & 0x7f;
  if (_DAT_a802b7b8 != 0)
    _DAT_a802b7b8(0, v);
  else
    *(volatile unsigned int *)0xcf00ef04 = v;
}
