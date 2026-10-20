/* leon2m FUN_a01185d4 @ 0xa01185d4-0xa0118628 (21 words), flags -mcpu=v8 -O3 -g.
 * Code facts: hardware registers by constant address (sethi/or into a register, plain [reg] ld/st): 0xcf011800 |=
 * 0x20, 0xcf011a00 |= 0x20, 0xcf012e00 |= 1, ROM delay func_0x4008d1a0(0x32), then 0xcf012e80 = 1. void(void).
 * 0xcf012e80 gets the constant 1 after the delay (not the delay call's return value); the registers are constant
 * hardware addresses. volatile only on the 0xcf... registers. Compiler aids: none.
 */
#define REG(a) (*(volatile unsigned int *)(a))
extern void func_0x4008d1a0(int);

void FUN_a01185d4(void)
{
  REG(0xcf011800) |= 0x20;
  REG(0xcf011a00) |= 0x20;
  REG(0xcf012e00) |= 1;
  func_0x4008d1a0(0x32);
  REG(0xcf012e80) = 1;
}
