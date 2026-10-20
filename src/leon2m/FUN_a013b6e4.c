/* leon2m FUN_a013b6e4 @ 0xa013b6e4-0xa013b710 (11 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf. When the u32 arg is 0 or 1 (cmp 1; bgu): byte 0xa802cbbc = (byte & 0xfe) | (arg & 1), with
 * the or on its own branch and ONE stb at the join. Other values: no change. Returns nothing.
 * Source form: no volatile (RAM byte; one load and one store in the fw), a u32 temp for the masked byte (a u8
 * '&= 0xfe' gives 'and -2' and two stores). Aids: none.
 */
extern unsigned char DAT_a802cbbc;

void FUN_a013b6e4(unsigned int on)
{
  unsigned int v;

  if (on < 2) {
    v = DAT_a802cbbc & 0xfe;
    if (on & 1)
      v |= 1;
    DAT_a802cbbc = v;
  }
}
