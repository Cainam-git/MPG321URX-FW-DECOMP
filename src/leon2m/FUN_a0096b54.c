/* leon2m FUN_a0096b54 @ 0xa0096b54-0xa0096bd8 (33 words), flags -mcpu=v8 -O3 -g.
 * Code facts: byte 0xa802d434 = (u8)(word 0xa802afec - 0x70); byte 0xa802b08e |= 2; if bit 15 of the halfword
 * at 0xa802cff4+4 is set (fw lduh, and 0xffff8000, sll 16, cmp 0): set bit 10 of that halfword (or 0x400, sth)
 * and FUN_a00808ac(4, 0). Then on both paths afec = 0 (clr in the call delay slot, so BEFORE the call),
 * FUN_a00b5080(void), tail FUN_a0096858(void) (call + restore). void(void). No parameters; d434 / b08e are
 * bytes. Source form: the flag word is the cff4 record's u16 at +4 as BIT-FIELDS b15 / b10 (the FUN_a00875ec
 * form). Aids: none.
 */
struct Rcff4 { unsigned char pad[4]; unsigned short b15 : 1, b14 : 4, b10 : 1, rest : 10; };
extern struct Rcff4 DAT_a802cff4;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d434;
extern void FUN_a00808ac(unsigned char, unsigned char);
extern void FUN_a0096858(void);
extern void FUN_a00b5080(void);

void FUN_a0096b54(void)
{
  DAT_a802d434 = _DAT_a802afec - 0x70;
  DAT_a802b08e |= 2;
  if (DAT_a802cff4.b15) {
    DAT_a802cff4.b10 = 1;
    FUN_a00808ac(4, 0);
  }
  _DAT_a802afec = 0;
  FUN_a00b5080();
  FUN_a0096858();
}
