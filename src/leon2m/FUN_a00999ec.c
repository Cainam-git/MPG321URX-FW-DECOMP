/* leon2m FUN_a00999ec @ 0xa00999ec-0xa0099a34 (18 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 18 words. Family of FUN_a00934dc / FUN_a00957e8.
 * Code facts: FUN_a00b31a0() (no argument: the 'mov 1,%i1' in its delay slot is the tail call's 2nd arg);
 * v = byte 0xa802d290+0x4b; byte 0xa8025c55 = v; word 0xa802afec = v + 0xe7; FUN_a00a9650(v, 0);
 * tail FUN_a00a9650(rec+0x4b re-read, 1). void(void).
 * Required forms: FUN_a00b31a0 takes no argument (void(void), as in its own file);
 * real base DAT_a802d290 (not DAT_a802d2db); the tail call re-reads the record byte. Aids: none.
 */
struct R290 { unsigned char pad[0x4b]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00b31a0(void);

void FUN_a00999ec(void)
{
  struct R290 *p;
  unsigned char v;

  FUN_a00b31a0();
  p = &DAT_a802d290;
  v = p->b;
  DAT_a8025c55 = v;
  _DAT_a802afec = v + 0xe7;
  FUN_a00a9650(v, 0);
  FUN_a00a9650(p->b, 1);
}
