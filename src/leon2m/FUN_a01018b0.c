/* leon2m FUN_a01018b0 @ 0xa01018b0  MATCH (-mcpu=v8 -O2 -g)
 * Sets bit 5 (0x20) of the register at 0xCF0160CC when param_1 is non-zero and clears it otherwise. The `param_1
 * != 0` arm comes first, giving the target's fall-through into the set case.
 */
#define _DAT_cf0160cc (*(volatile unsigned int *)0xcf0160cc)

void FUN_a01018b0(unsigned char param_1)
{
    if (param_1 != 0) {
        _DAT_cf0160cc = _DAT_cf0160cc | 0x20;
    } else {
        _DAT_cf0160cc = _DAT_cf0160cc & 0xffffffdf;
    }
    return;
}
