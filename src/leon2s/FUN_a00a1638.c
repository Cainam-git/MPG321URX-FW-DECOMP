/* leon2s FUN_a00a1638 @ 0xa00a1638 (-mcpu=v8 -Os -g)
 */

extern unsigned char ARR_a807d7e0[];
extern unsigned char DAT_a807db68;
extern void FUN_a00962ec(unsigned int param_1, unsigned char param_2);
extern void FUN_a009e9fc(unsigned int param_1);
extern void FUN_a00b1a00(void);
extern void FUN_a00b1acc(void);
extern void DRV_HDMI_Setup_IntIRQ_Events(unsigned int param_1, unsigned int param_2);
extern void FUN_a00a0b10(unsigned int param_1, unsigned int param_2);
unsigned int FUN_a00a1638(unsigned int param_1, unsigned int param_2)
{
  unsigned int uVar2;
  unsigned int uVar3;
  unsigned int l0;
  unsigned int l1;
  ;
  l1 = param_1;
  uVar3 = 1;
  if (DAT_a807db68 != 0)
  {
    FUN_a00962ec(param_1 & 0xff, 0);
    ARR_a807d7e0[(l1 * 400) + 4] = 0;
    ARR_a807d7e0[(l1 * 400) + 5] = 0;
    DRV_HDMI_Setup_IntIRQ_Events(param_1 & 0xff, 0);
    FUN_a00a0b10(param_1 & 0xff, 0);
    if (l1 == 0)
    {
      FUN_a00b1a00();
    }
    else
    {
      FUN_a00b1acc();
    }
    FUN_a009e9fc(param_1 & 0xff);
    uVar3 = 0;
  }
  return uVar3;
}
