/* leon2m FUN_a014837c @ 0xa014837c-0xa01483b8 (15 words), flags -mcpu=v8 -O3 -g.
 * Leaf (retl).
 * Code facts: u16 getter on a u8 selector: 0 -> halfword 0xa802e380, 1 -> halfword 0xa802e382, else 0;
 * the result is zero-extended with sll/srl 16 on the shared exit.
 * Source form: a switch with case 0 first and a preset r = 0 (if/else chains in either order, or a switch
 * with case 1 first, give other code). Aids: none.
 */
extern unsigned short DAT_a802e380;
extern unsigned short DAT_a802e382;

unsigned short FUN_a014837c(unsigned char p)
{
  unsigned short r = 0;

  switch (p) {
  case 0:
    r = DAT_a802e380;
    break;
  case 1:
    r = DAT_a802e382;
    break;
  }
  return r;
}
