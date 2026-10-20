/* leon2m FUN_a00e4538 @ 0xa00e4538 (-mcpu=v8 -O2 -g)
 * The key structure points: the global toggle is a word at 0xa802b72c (0xa802b400+0x32c), the switch on param_2 has cases 0/1/2 with case 1 falling into case 2's body, and the loop condition uses the counter check after incrementing. The function returns the result of `FUN_a00e40f4`.
 */
extern int FUN_a00dfc50();
extern void FUN_a00e03b0();
extern void FUN_a00e05d8();
extern void FUN_a00e0774();
extern int FUN_a00e40f4();
extern unsigned int DAT_a802b72c;

int FUN_a00e4538(int param_1, int param_2, unsigned int param_3, unsigned int param_4)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  FUN_a00dfc50(param_1, param_2, param_3);
  for (;;) {
    FUN_a00e03b0(param_1, 0x44, 0);
    FUN_a00e03b0(param_1, 0x45, 0);
    FUN_a00e03b0(param_1, 0x46, 0xff);
    FUN_a00e03b0(param_1, 0x47, 0xff);
    FUN_a00e03b0(param_1, 0x48, 0);
    FUN_a00e03b0(param_1, 0x49, 0);
    FUN_a00e03b0(param_1, 0x4a, 0xff);
    FUN_a00e03b0(param_1, 0x4b, 0xff);
    FUN_a00e03b0(param_1, 0x4c, 0);
    FUN_a00e03b0(param_1, 0x4d, 0);
    FUN_a00e03b0(param_1, 0x4e, 0xff);
    FUN_a00e03b0(param_1, 0x4f, 0xff);
    FUN_a00e03b0(param_1, 0x50, 0);
    FUN_a00e03b0(param_1, 0x51, 0);
    FUN_a00e03b0(param_1, 0x52, 0xff);
    FUN_a00e03b0(param_1, 0x53, 0xff);
    DAT_a802b72c = DAT_a802b72c ^ 1;
    FUN_a00e03b0(param_1, 0x40, 3);
    FUN_a00e03b0(param_1, 0x41, 0);
    FUN_a00e03b0(param_1, 0x5b, 0x3c);
    FUN_a00e03b0(param_1, 0x5c, 0);
    FUN_a00e03b0(param_1, 0x42, 0);
    if (param_2 == 0) {
      FUN_a00e03b0(param_1, 0x5a, 7);
    }
    else if (param_2 == 1) {
      FUN_a00e05d8(param_1, 0x5a, 0x87, 0x81);
    }
    else if (param_2 == 2) {
      FUN_a00e05d8(param_1, 0x5a, 0x87, 0x81);
    }
    FUN_a00e03b0(param_1, 0x2cd, 0x8f);
    FUN_a00e03b0(param_1, 0x2cd, 0x80);
    FUN_a00e03b0(param_1, 0x2cd, 0x8f);
    FUN_a00e05d8(param_1, 0x6c, 0x20, 0);
    FUN_a00e05d8(param_1, 0x6c, 0x20, 0x20);
    FUN_a00e05d8(param_1, 0x40, 0x80, 0x80);
    iVar1 = FUN_a00e40f4(param_1, param_4);
    if (iVar1 == 1) {
      iVar2 = iVar2 + 1;
      if (0 < iVar2) break;
      FUN_a00e0774(param_1, 0x54, 8, 3, 1);
      FUN_a00e0774(param_1, 0x54, 8, 3, 0);
    }
    else if (iVar1 == 3) {
      continue;
    }
    else {
      break;
    }
  }
  return iVar1;
}
