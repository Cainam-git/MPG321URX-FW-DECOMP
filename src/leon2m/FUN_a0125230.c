/* leon2m FUN_a0125230 @ 0xa0125230 (-mcpu=v8 -O3 -g)
 */

extern unsigned char ARR_a802d880[];
unsigned char FUN_a0125230(unsigned int param_1)
{
  int new_var;
  unsigned int uVar2;
  unsigned short uVar1;
  uVar2 = ARR_a802d880[param_1 & 0xff];
  new_var = 0x1a42a8;
  uVar1 = 0xff;
  if (uVar2 != 0xff)
  {
    uVar1 = *((unsigned char *) (new_var + (uVar2 * 0x16)));
  }
  return uVar1;
}
