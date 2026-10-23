/* leon2m FUN_a0122d0c @ 0xa0122d0c, flags -mcpu=v8 -O3 -g
 * ResetVx1: prints "\x1b[1;31mResetVx1\r\n\x1b[m" (s_001a3048), pulses register 0xCF00EB44:
 * write 1, wait 1 ms (func_0x4008d1a0 = delay), write 0.
 */
#define _DAT_cf00eb44 (*(volatile unsigned int *)0xcf00eb44)
extern int FUN_a00df170();                 /* formatted output (vsnprintf) */
extern void func_0x4008d1a0(int ms);       /* delay */
extern const char s_001a3048[];            /* "\x1b[1;31mResetVx1\r\n\x1b[m" */

void FUN_a0122d0c(void)
{
  FUN_a00df170(s_001a3048);
  _DAT_cf00eb44 = 1;
  func_0x4008d1a0(1);
  _DAT_cf00eb44 = 0;
}
