/* leon2m FUN_a00f6e30 @ 0xa00f6e30-0xa00f6e88 (22 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 22 words.
 * Code facts: v = u8 param with bit 7 toggled (p & 0x7f if bit 7 set, else p | 0x80); if the hook word
 * 0xa802b7b8 is non-zero it is called as hook(2, v), else v is written to the MMIO register 0xCF00EF0C
 * (volatile: real hardware register). void; %i0 is never set.
 * Fix vs the autoc draft (68.18): BEHAVIOUR: the hook takes 2 args (2, v), like its siblings in src/
 * (hook(3/4/5, param_1)); the fw 'mov %o1,%o5' in the bne delay slot is v moving out of the %o1 arg register.
 * 'v = p | 0x80; if (p & 0x80) v = p & 0x7f' order (if/else arms give an extra and). Aids: none.
 */
extern void (*_DAT_a802b7b8)(int, unsigned int);

void FUN_a00f6e30(unsigned char param_1)
{
  unsigned char v;

  v = param_1 | 0x80;
  if (param_1 & 0x80)
    v = param_1 & 0x7f;
  if (_DAT_a802b7b8 != 0)
    _DAT_a802b7b8(2, v);
  else
    *(volatile unsigned int *)0xcf00ef0c = v;
}
