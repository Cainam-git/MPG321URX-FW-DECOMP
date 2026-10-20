/* leon2m FUN_a00934dc @ 0xa00934dc-0xa0093534 (22 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 22 words. Family of FUN_a00957e8.
 * Code facts: FUN_a00a93bc(word 0xa802afec - 0x53, as u8); FUN_a00b3108(); v = byte 0xa802d290+0x13e;
 * byte 0xa8025c55 = v; word 0xa802afec = v + 0xdd; FUN_a00a9650(v, 0); tail FUN_a00a9650(rec+0x13e re-read, 1).
 * void(void). Fix vs the autoc draft: real base DAT_a802d290 (draft used mid-record DAT_a802d3ce);
 * real callee prototypes (u8 params, void); source order 5c55 store before the afec store (the other order
 * adds an 'and 0xff' before the + 0xdd). Aids: none.
 */
struct R290 { unsigned char pad[0x13e]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00b3108(void);

void FUN_a00934dc(void)
{
  struct R290 *p;
  unsigned char v;

  FUN_a00a93bc(_DAT_a802afec - 0x53);
  FUN_a00b3108();
  p = &DAT_a802d290;
  v = p->b;
  DAT_a8025c55 = v;
  _DAT_a802afec = v + 0xdd;
  FUN_a00a9650(v, 0);
  FUN_a00a9650(p->b, 1);
}
