/* leon2m FUN_a01445fc @ 0xa01445fc-0xa014464c (20 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf lookup in the ROM table DAT_001a6db2 of 4 {key, val} byte pairs: u8 i = 0..3 (bleu 3); when
 * key == the u8 arg, return val (ldub +1); no match returns 0xff. u8 return. Aids: none.
 */
struct kv { unsigned char key, val; };
extern struct kv DAT_001a6db2[];

unsigned char FUN_a01445fc(unsigned char x)
{
  unsigned char i;

  for (i = 0; i <= 3; i++)
    if (DAT_001a6db2[i].key == x)
      return DAT_001a6db2[i].val;
  return 0xff;
}
