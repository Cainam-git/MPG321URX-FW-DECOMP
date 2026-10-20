/* leon2s FUN_a00c7bc4 @ 0xa00c7bc4  MATCH (-mcpu=v8 -Os -g)
 * This should force the exact sequence: and, or, and on the result of the first call.
 */
typedef unsigned int uint;
extern int func_0xa0fb7fd8();
extern int func_0xa0fb8054();

void FUN_a00c7bc4(uint param_1)

{
  uint uVar1;
  unsigned char uVar2;
  
  param_1 = param_1 & 0xff;
  uVar1 = func_0xa0fb7fd8(param_1,0,0xf3);
  uVar2 = uVar1 & 0xfffffff0;
  uVar2 = uVar2 | 0xa;
  uVar2 = uVar2 & 0xfa;
  func_0xa0fb8054(param_1,0,0xf3,uVar2);
  return;
}
