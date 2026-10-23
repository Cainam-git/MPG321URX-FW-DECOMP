/* leon2m FUN_a00936fc @ 0xa00936fc (-mcpu=v8 -O3 -g)
 * Calls FUN_a00a93bc(word 0xA802AFEC - 0x56) and FUN_a00b3070(); v = byte 0xA802D3CF (0xA802D290 + 0x13F); stores
 * v in byte 0xA8025C55 and v + 0xE2 in word 0xA802AFEC; calls FUN_a00a9650(v, 0), then FUN_a00a9650 with the byte
 * read again and 1. Same code as FUN_a00934dc with other constants.
 * See FUN_a00934dc for the explanation; this copy's constants differ, so its comments were removed.
 */
struct R290 { unsigned char pad[0x13f]; unsigned char b; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00b3070(void);

void FUN_a00936fc(void)
{
  struct R290 *p;
  unsigned char v;

  FUN_a00a93bc(_DAT_a802afec - 0x56);
  FUN_a00b3070();
  p = &DAT_a802d290;
  v = p->b;
  DAT_a8025c55 = v;
  _DAT_a802afec = v + 0xe2;
  FUN_a00a9650(v, 0);
  FUN_a00a9650(p->b, 1);
}
