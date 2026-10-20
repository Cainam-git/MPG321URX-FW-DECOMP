/* leon2m FUN_a0097138 @ 0xa0097138-0xa0097190 (22 words), flags -mcpu=v8 -O3 -g.
 * Code facts: toggles bit 9 (0x200) of the word at 0xa802d290 (one ld, btst, or/andn values both computed,
 * one st per arm); FUN_a0148d98((word >> 9) & 1) after a re-load; FUN_a00b3b5c(1); byte 0xa802b08e |= 2.
 * void(void). FUN_a00b3b5c takes 1 u8 argument (and %i0,0xff); FUN_a0148d98 takes 1 argument.
 * Source form: an if/else of the mask forms with the CLEAR test first ('(w & 0x200) == 0' -> |=, else &=~; the
 * opposite arm order swaps the or/andn values and be/bne). Twin pattern of FUN_a0099440. Aids: none.
 */
struct R290 { unsigned int w0; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a0148d98(unsigned int);
extern void FUN_a00b3b5c(unsigned char);

void FUN_a0097138(void)
{
  if ((DAT_a802d290.w0 & 0x200) == 0)
    DAT_a802d290.w0 |= 0x200;
  else
    DAT_a802d290.w0 &= ~0x200;
  FUN_a0148d98(DAT_a802d290.w0 >> 9 & 1);
  FUN_a00b3b5c(1);
  DAT_a802b08e |= 2;
}
