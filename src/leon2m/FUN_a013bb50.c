/* leon2m FUN_a013bb50 @ 0xa013bb50-0xa013bbb8 (26 words), flags -mcpu=v8 -O3 -g.
 * Code facts: u8 FUN_a013bb50(u8 id): p = FUN_a013cd4c(id) (the DAT_a802df30 0x78-byte port record whose
 * word-0 bits 12..15 == id). If id == 0 and FUN_a0140098((p->w00 >> 12) & 0xf) != 0 (u8 return, btst 0xff) and
 * the u16 at p+8 > 3000 (cmp 0xbb8; bleu): return 1. Otherwise return (u16 at p+8) >= 0x993 (fw cmp 0x993;
 * subx %g0,-1 = branch-free GEU store-flag). Fix vs the autoc draft: record struct with h08 at +8, the &&
 * chain, u8 prototypes (callers test the result with btst 0xff). AID (code-free local constant, same kind
 * as FUN_a00aaf48 'n = 7' / FUN_a00ad7c8 'm = 8'): 'unsigned int lim = 0x993; return
 * p->h08 >= lim;'. A literal is folded at tree level to '> 0x992' (GTU), which has no SPARC store-flag
 * pattern, so expand emits branches (17 words off); the local reaches the compare only at RTL level as GEU,
 * giving the fw subx. Same final code, no volatile.
 */
struct Port { unsigned int w00; unsigned int w04; unsigned short h08; };
extern struct Port *FUN_a013cd4c(unsigned char);
extern unsigned char FUN_a0140098(unsigned char);

unsigned char FUN_a013bb50(unsigned char id)
{
  struct Port *p = FUN_a013cd4c(id);

  if (id == 0 && FUN_a0140098((p->w00 >> 12) & 0xf) && p->h08 > 3000)
    return 1;
  {
    unsigned int lim = 0x993;
    return p->h08 >= lim;
  }
}
