/* leon2s FUN_a006d46c @ 0xa006d46c-0xa006d4e0 (29 words), flags -mcpu=v8 -Os -g.
 * u8 i = 0..8 (nine passes: 'cmp 8; bleu' on i + 1): record DAT_a807a824[i] (20-byte records, sll 2 / add /
 * sll 2), byte +0: when bit i of the u8 mask is set (sra / btst 1) and the byte == 1 it becomes 2; when the
 * bit is clear it becomes 1. For i = 8 the bit is always clear, so record 8 is always set to 1. void.
 * The records are a 20-byte struct array at DAT_a807a824.
 */
struct Rec20 { unsigned char state; unsigned char rest[19]; };
extern struct Rec20 DAT_a807a824[];

void FUN_a006d46c(unsigned char mask)
{
  unsigned char i;

  for (i = 0; i < 9; i++) {
    if ((mask >> i) & 1) {
      if (DAT_a807a824[i].state == 1)
        DAT_a807a824[i].state = 2;
    } else
      DAT_a807a824[i].state = 1;
  }
}
