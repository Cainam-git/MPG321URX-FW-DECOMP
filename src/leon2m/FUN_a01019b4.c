/* leon2m FUN_a01019b4 @ 0xa01019b4 (-mcpu=v8 -O2 -g)
 * Two separate volatile read-modify-writes of the register at 0xCF0160F4: AND with 0xEF (keeps bits 0..3 and
 * 5..7), then OR with (param_1 & 0xFF) << 4.
 */
#define _DAT_cf0160f4 (*(volatile unsigned int *)0xcf0160f4)

void FUN_a01019b4(unsigned int param_1)
{
    _DAT_cf0160f4 = _DAT_cf0160f4 & 0xef;
    _DAT_cf0160f4 = _DAT_cf0160f4 | ((param_1 & 0xff) << 4);
    return;
}
