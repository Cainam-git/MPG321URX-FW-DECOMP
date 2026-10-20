/* leon2m FUN_a0097c54 @ 0xa0097c54-0xa0097cb4 (24 words), flags -mcpu=v8 -O3 -g.
 * Uses the same d290 +0x30 4-bit field as FUN_a0095020.
 * Code facts: byte 0xa802b08f = 5 (in the delay slot of the call); FUN_a00ab340() (no args); v = bits 4..7 of
 * word DAT_a802d290 + 0x30 (srl 4, and 0xf); word 0xa802afec = (u8)v + 0xd8 (the fw re-extends with and 0xff);
 * byte 0xa8025c55 = v; FUN_a00a9650(v, 0); tail FUN_a00a9650(field re-read, 1). void(void).
 * FUN_a00ab340 takes no arguments. Source form: the record base with a bit-field (no volatile on RAM); v is a u32
 * local with the u8 cast at the add (a u8 local drops the and 0xff). Aids: none.
 */
struct R290 { unsigned char pad[0x30]; unsigned int hi : 24, f4 : 4, lo : 4; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08f;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00ab340(void);

void FUN_a0097c54(void)
{
  unsigned int v;

  DAT_a802b08f = 5;
  FUN_a00ab340();
  v = DAT_a802d290.f4;
  _DAT_a802afec = (unsigned char)v + 0xd8;
  DAT_a8025c55 = v;
  FUN_a00a9650(v, 0);
  FUN_a00a9650(DAT_a802d290.f4, 1);
}
