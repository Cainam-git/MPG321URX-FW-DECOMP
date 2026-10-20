/* leon2m FUN_a014b360 @ 0xa014b360-0xa014b3fc (39 words), flags -mcpu=v8 -O3 -g.
 * Code facts: k = (u8)FUN_a01421c4(FUN_a0142218(FUN_a0125198(param_1))) (u8 chain); i = 0, then 0x61 -> 1,
 * 0x71 -> 2, 0x81 -> 3 (same code map as FUN_a013dbcc, where 0x51 -> 0); v = FUN_a0125124(byte +0x10 of
 * entry i of DAT_a802e116[] (0x12-byte entries)); tail FUN_a012c80c(v, (u16)param_2, param_3, (u16)param_4, 1).
 * FUN_a012c80c never reads %i2 and %i5 before overwriting them; param_3 is passed through unchanged (no code).
 * The tail call takes 5 arguments.
 * Source form: switch with i preset to 0 and an explicit 'case 0x51: i = 0' (same behaviour as the default;
 * makes 0x61 the case-tree root, its block merges with the default); i is an unsigned short (the fw 'and 3'
 * is the reduced zero-extension; u8 gives 'and 0xff'); the base DAT_a802e116. Aids: none.
 */
struct Ent { unsigned char b00[0x10]; unsigned char b10; unsigned char b11; };
extern struct Ent DAT_a802e116[];
extern int FUN_a0125198(unsigned char);
extern int FUN_a0142218(unsigned char);
extern int FUN_a01421c4(unsigned char);
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a012c80c(unsigned char, unsigned short, int, unsigned short, unsigned char);

void FUN_a014b360(unsigned char param_1, unsigned short param_2, int param_3, unsigned short param_4)
{
  unsigned short i;

  i = 0;
  switch ((unsigned char)FUN_a01421c4(FUN_a0142218(FUN_a0125198(param_1)))) {
  case 0x51:
    i = 0;
    break;
  case 0x61:
    i = 1;
    break;
  case 0x71:
    i = 2;
    break;
  case 0x81:
    i = 3;
    break;
  }
  FUN_a012c80c(FUN_a0125124(DAT_a802e116[i].b10), param_2, param_3, param_4, 1);
}
