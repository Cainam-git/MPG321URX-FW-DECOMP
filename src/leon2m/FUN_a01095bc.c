/* leon2m FUN_a01095bc @ 0xa01095bc-0xa0109654 (38 words).
 * Prints "FRC_SetMainBypassMode enable" or "FRC_SetMainBypassMode disable " through FUN_a00df170, by en.
 * en != 0: sets bit 0 of hardware registers 0xcf0116d4 and 0xcf011a80 and clears bit 0 of 0xcf011800 and
 * 0xcf011a00. en == 0: clears bit 0 of 0xcf0116d4 and 0xcf011a80 (the last read-modify-write of both arms is shared
 * code). Called from FUN_a012fcf4.
 */
#define REG_cf0116d4 (*(volatile unsigned int *)0xcf0116d4)
#define REG_cf011a80 (*(volatile unsigned int *)0xcf011a80)
#define REG_cf011800 (*(volatile unsigned int *)0xcf011800)
#define REG_cf011a00 (*(volatile unsigned int *)0xcf011a00)

extern int FUN_a00df170(const char *fmt, ...);

void FUN_a01095bc(unsigned char en)
{
    if (en) {
        FUN_a00df170("FRC_SetMainBypassMode enable\r\n");
        REG_cf0116d4 |= 1;
        REG_cf011a80 |= 1;
        REG_cf011800 &= ~1;
        REG_cf011a00 &= ~1;
    } else {
        FUN_a00df170("FRC_SetMainBypassMode disable \r\n");
        REG_cf0116d4 &= ~1;
        REG_cf011a80 &= ~1;
    }
}
