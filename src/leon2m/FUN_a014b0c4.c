/* FUN_a014b0c4: k = (u8)FUN_a01421c4(FUN_a0142218(FUN_a0125198(param_1))); entry index i = 1 / 2 / 3 for
 * k 0x61 / 0x71 / 0x81, else 0; tail-calls FUN_a012c320(FUN_a0125124(byte +0x10 of entry i of DAT_a802e116[]
 * (0x12-byte entries)), 0, param_2, param_3, 0). Callers: FUN_a00cf2d4.
 * Same source form as FUN_a014b360 (switch with i preset to 0 and an explicit case 0x51, u16 index); the callee
 * takes five arguments.
 */
struct Ent { unsigned char b00[0x10]; unsigned char b10; unsigned char b11; };
extern struct Ent DAT_a802e116[];
extern int FUN_a0125198(unsigned char);
extern int FUN_a0142218(unsigned char);
extern int FUN_a01421c4(unsigned char);
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a012c320(unsigned char, unsigned short, int, unsigned short *, unsigned char);

void FUN_a014b0c4(unsigned char param_1, int param_2, unsigned short *param_3)
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
  FUN_a012c320(FUN_a0125124(DAT_a802e116[i].b10), 0, param_2, param_3, 0);
}
