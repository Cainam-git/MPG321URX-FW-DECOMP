/* leon2s FUN_a00a621c @ 0xa00a621c (-mcpu=v8 -Os -g)
 * Returns 1 when the selected byte is zero, else 0: DAT_a807d7e1 for param_1 == 'Q' (0x51), DAT_a807d971 for
 * param_1 == 'a' (0x61), the constant 1 (result 0) for other values.
 */
extern unsigned char DAT_a807d7e1;
extern unsigned char DAT_a807d971;

unsigned int FUN_a00a621c(unsigned char param_1)

{
  int uVar1;
  unsigned char uVar2;
  
  uVar2 = 0;
  if (param_1 == 'Q') {
    uVar1 = DAT_a807d7e1;
  } else {
    if (param_1 == 'a') {
      uVar1 = DAT_a807d971;
    } else {
      uVar1 = 1;
    }
  }
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  return uVar2;
}
