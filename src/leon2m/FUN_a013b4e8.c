/* leon2m FUN_a013b4e8 @ 0xa013b4e8-0xa013b544 (23 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 23 words.
 * Code facts: three u8 params (all three are re-extended with 'and 0xff'); record 0xa802a468 bytes
 * +0/+1/+2 = p1/p2/p3; a 12-entry u16 stack buffer (frame -128) gets [3]=p1, [7]=p2, [11]=p3; then
 * FUN_a00f6fe4(byte 0xa802cbbc & 1, (byte >> 1) & 1, buf, 0x70). void.
 * Fix vs the autoc draft (73.91): record 0xa802a468 as one 3-byte struct (draft: three symbols), param_3 is u8,
 * the record stores in ascending offset order a,b,c (a,c,b gives 91.30). Aids: none.
 */
struct R468 { unsigned char a, b, c; };
extern struct R468 DAT_a802a468;
extern unsigned char DAT_a802cbbc;
extern void FUN_a00f6fe4(unsigned char, unsigned char, unsigned short *, int);

void FUN_a013b4e8(unsigned char param_1, unsigned char param_2, unsigned char param_3)
{
  unsigned short buf[12];

  DAT_a802a468.a = param_1;
  DAT_a802a468.b = param_2;
  DAT_a802a468.c = param_3;
  buf[3] = param_1;
  buf[7] = param_2;
  buf[11] = param_3;
  FUN_a00f6fe4(DAT_a802cbbc & 1, (DAT_a802cbbc >> 1) & 1, buf, 0x70);
}
