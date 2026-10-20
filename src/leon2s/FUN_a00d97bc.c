/* leon2s FUN_a00d97bc @ 0xa00d97bc-0xa00d985c (40 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0 mismatches / 40 words.
 * Code facts: stack message m at %fp-32 (address kept in %l0): ROM copy func_0xa0fc15d8(&m, src, 0x13);
 * t = src[0] & 0xf; bits 24..27 of m's first word (4-bit bit-field) = t - 1; n = (signed char)(t - 1); for u8
 * i while i < n (signed): m.b[i + 1] = src[i + 2]; then m.b[i + 1] = 0; FUN_a00d6a54(&m, 3, 1). The fw ends
 * with a real 'nop' after that call's delay slot. void.
 * Fix vs the autoc draft: one union for the header bit-field and the byte view; n is a signed char (an int n
 * lets CSE share the two 't - 1', 57.50). Aids: one asm nop at the end (fw real nop, not a delay slot).
 */
union Msg { struct { unsigned int hi : 4, cnt : 4, rest : 24; } h; unsigned char b[0x18]; };
extern void func_0xa0fc15d8(void *, const void *, int);
extern void FUN_a00d6a54(union Msg *, int, int);

void FUN_a00d97bc(unsigned char *src)
{
  union Msg m;
  signed char n;
  unsigned char t;
  unsigned char i;

  func_0xa0fc15d8(&m, src, 0x13);
  t = src[0] & 0xf;
  m.h.cnt = t - 1;
  n = t - 1;
  for (i = 0; i < n; i++)
    m.b[i + 1] = src[i + 2];
  m.b[i + 1] = 0;
  FUN_a00d6a54(&m, 3, 1);
  __asm__ volatile ("nop");
}
