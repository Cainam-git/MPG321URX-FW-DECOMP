/* leon2m FUN_a012536c @ 0xa012536c  MATCH (-mcpu=v8 -O2 -g)
 * Returns bit n of the byte at 0xA802C9FA (0 or 1), n being the parameter. The shift count is used unmasked (no `&
 * 0x1f`), since the target has no and before the shift.
 */
extern unsigned char DAT_a802c9fa; /* 0xa802c9fa */

int FUN_a012536c(int param_1)
{
    return (DAT_a802c9fa >> param_1) & 1;
}
