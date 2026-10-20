/* leon2s FUN_a00aa88c @ 0xa00aa88c-0xa00aa904 (30 words), flags -mcpu=v8 -Os -g.
 * Code facts: leaf wrapper; sel = arg & 0xff, sel > 4 -> return; mode = arg2 & 0xff (in the jmp delay
 * slot, i.e. after the range test, before the jump table 0xa00aa878); switch picks (ch, reg, mask):
 * 0 -> (1, 0x67, 0xf), 1 -> (1, 0x67, 0xf0), 2 -> (1, 0x8a, 0xf), 3 -> (1, 0x8a, 0xf0),
 * 4 -> (4, 0x49, 0xf0); tail call FUN_a00a7d04(ch, reg, mask, mode) (mov %o7,%g1 / call / mov %g1,%o7).
 * Fixes vs the autoc draft (96.67): BEHAVIOUR, the 4th argument is param_2 & 0xff (the draft passed
 * an uninitialised local); 'param_2 &= 0xff;' sits between the range test and the switch (at the top
 * of the function or in the call it gives other code). Aids: none.
 */
typedef unsigned int uint;

extern int FUN_a00a7d04();

void FUN_a00aa88c(unsigned int param_1, unsigned int param_2) {
  uint uVar1, uVar2;
  
  param_1 &= 0xff;
  if (param_1 > 4) return;
  param_2 &= 0xff;
  
  switch (param_1) {
    case 0:
      param_1 = 1;
      uVar1 = 0x67;
      uVar2 = 0xf;
      break;
    case 1:
      param_1 = 1;
      uVar1 = 0x67;
      uVar2 = 0xf0;
      break;
    case 2:
      param_1 = 1;
      uVar1 = 0x8a;
      uVar2 = 0xf;
      break;
    case 3:
      param_1 = 1;
      uVar1 = 0x8a;
      uVar2 = 0xf0;
      break;
    case 4:
      uVar1 = 0x49;
      uVar2 = 0xf0;
      break;
  }
  FUN_a00a7d04(param_1, uVar1, uVar2, param_2);
}
