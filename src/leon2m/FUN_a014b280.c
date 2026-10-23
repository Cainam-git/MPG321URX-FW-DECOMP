/* leon2m FUN_a014b280 @ 0xa014b280-0xa014b360 (224 bytes), flags -mcpu=v8 -O3 -g.
 * Callers: FUN_a00ce958, FUN_a00cfacc. Same start as FUN_a014b360: k = (u8)FUN_a01421c4(FUN_a0142218(
 * FUN_a0125198(param_1))); i = 0, then 0x61 -> 1, 0x71 -> 2, 0x81 -> 3; v = FUN_a0125124(byte +0x10 of entry i
 * of DAT_a802e116[] (0x12-byte entries)). Stores val (clear == 0) or 0xff (otherwise) to byte DAT_a802e1a0[0x1b + v]
 * and ends with the tail call FUN_a012c80c(v, 0, param_3, (u16)param_4, 0).
 * Source form: the store is written in both arms of 'if (clear == 0) ... else ...' and the call after it.
 */
struct Ent { unsigned char b00[0x10]; unsigned char b10; unsigned char b11; };
extern struct Ent DAT_a802e116[];
extern unsigned char DAT_a802e1a0[];
extern int FUN_a0125198(unsigned char);
extern int FUN_a0142218(unsigned char);
extern int FUN_a01421c4(unsigned char);
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a012c80c(unsigned char, unsigned short, int, unsigned short, unsigned char);

void FUN_a014b280(unsigned char param_1, unsigned char val, int param_3, unsigned short param_4, unsigned char clear)
{
  unsigned short i;
  unsigned char v;

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
  v = FUN_a0125124(DAT_a802e116[i].b10);
  if (clear == 0) {
    DAT_a802e1a0[0x1b + v] = val;
  } else {
    DAT_a802e1a0[0x1b + v] = 0xff;
  }
  FUN_a012c80c(v, 0, param_3, param_4, 0);
}
