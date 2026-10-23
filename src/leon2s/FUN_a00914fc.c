/* leon2s FUN_a00914fc @ 0xa00914fc (-mcpu=v8 -Os -g)
 * Clears bit p of the register 0xCF03C890: reg &= ~(1 << p).
 */
#define _DAT_cf03c890 (*(volatile unsigned int *)0xcf03c890)

void FUN_a00914fc(unsigned char param_1)
{
    _DAT_cf03c890 = _DAT_cf03c890 & ~(1 << param_1);
    return;
}
