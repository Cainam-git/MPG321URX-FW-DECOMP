/* leon2m FUN_a00961d4 @ 0xa00961d4-0xa0096230 (23 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 23 words.
 * Code facts: v = low 4 bits of the u16 at 0xa802d290+0x34 (lduh + and 0xf, re-read for every use);
 * byte 0xa8025c56 = v; FUN_a00a813c(1, v, 0); FUN_a00a900c(word 0xa802afec - 0x15, 2); word 0xa802afec = v + 100;
 * tail FUN_a00a9650(v, 1). void(void).
 * Fix vs the autoc draft (69.57): real base DAT_a802d290 (draft used mid-record _DAT_a802d2c4); the field is a
 * 4-bit BIT-FIELD 'lo:4' in a u16 container (a mask on a plain u16 narrows the load to ldub +0x35); tail call
 * takes 2 args; real callee prototypes. Aids: none.
 */
struct R290 { unsigned char pad[0x34]; unsigned short hi : 12, lo : 4; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a00961d4(void)
{
  struct R290 *p = &DAT_a802d290;

  DAT_a8025c56 = p->lo;
  FUN_a00a813c(1, p->lo, 0);
  FUN_a00a900c(_DAT_a802afec - 0x15, 2);
  _DAT_a802afec = p->lo + 100;
  FUN_a00a9650(p->lo, 1);
}
