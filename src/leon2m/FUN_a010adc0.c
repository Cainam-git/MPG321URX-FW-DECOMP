/* leon2m FUN_a010adc0 @ 0xa010adc0  MATCH (-mcpu=v8 -O2 -g)
 * Sets bit 7 of register 0xCF00EAC0 when param_1 is zero and clears it otherwise; sets bit 6 of register
 * 0xCF00EAC8 when param_2 is zero and clears it otherwise. Both parameters are int.
 */
#define _DAT_cf00eac0 (*(volatile unsigned int *)0xcf00eac0)
#define _DAT_cf00eac8 (*(volatile unsigned int *)0xcf00eac8)

void FUN_a010adc0(int param_1, int param_2)
{
    if (param_1 == 0) {
        _DAT_cf00eac0 = _DAT_cf00eac0 | 0x80;
    } else {
        _DAT_cf00eac0 = _DAT_cf00eac0 & 0xffffff7f;
    }
    if (param_2 == 0) {
        _DAT_cf00eac8 = _DAT_cf00eac8 | 0x40;
    } else {
        _DAT_cf00eac8 = _DAT_cf00eac8 & 0xffffffbf;
    }
    return;
}
