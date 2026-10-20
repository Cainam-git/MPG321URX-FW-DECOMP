/* leon2m FUN_a00964fc @ 0xa00964fc  MATCH (-mcpu=v8 -O2 -g)
 * You need to include a typedef for `uint`. The Ghidra output uses `uint` but it's not defined. Add `typedef unsigned int uint;` at the top.
 */
typedef unsigned int uint;

extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a802d2a1;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c();
extern int FUN_a00a900c();
extern int FUN_a00a93bc();
extern int FUN_a00a9650();
extern int FUN_a00d9764();

uint FUN_a00964fc(uint param_1,uint param_2)
{
  FUN_a00a93bc(DAT_a8025c56);
  FUN_a00a813c(1, DAT_a8025c56, 0);
  unsigned int tmp = FUN_a00a9650((_DAT_a802afec - 0x6cU) & 0xff, 0);
  DAT_a802d2a1 = (unsigned char)(_DAT_a802afec - 0x6cU);
  FUN_a00d9764(tmp);
  FUN_a00a813c(1, (_DAT_a802afec - 0x6cU) & 0xff, 1);
  _DAT_a802afec = 0x1b;
  FUN_a00a900c(3, 1);
  DAT_a802b08f = 3;
  DAT_a802b08e = DAT_a802b08e | 2;
  return param_1;
}
