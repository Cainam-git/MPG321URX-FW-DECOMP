/* leon2m FUN_a014c794 @ 0xa014c794-0xa014c7bc (10 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 10 words.
 * Code facts: byte 0xa802e3d0+0x18 = u8 param; FUN_a012eeb0(param & 0xff); tail FUN_a014c118(byte rec+0xb)
 * (1 arg, restore in the delay slot). void.
 * Fix vs the autoc draft (70.00): real base DAT_a802e3d0 as a struct (draft: DAT_a802e3e8 / DAT_a802e3db
 * mid-record names), u8 param only, both callees void with 1 u8 arg. Aids: none.
 */
struct E3D0 { unsigned char pad[0xb]; unsigned char b0b; unsigned char pad2[0xc]; unsigned char b18; };
extern struct E3D0 DAT_a802e3d0;
extern void FUN_a012eeb0(unsigned char);
extern void FUN_a014c118(unsigned char);

void FUN_a014c794(unsigned char param_1)
{
  struct E3D0 *p = &DAT_a802e3d0;

  p->b18 = param_1;
  FUN_a012eeb0(param_1);
  FUN_a014c118(p->b0b);
}
