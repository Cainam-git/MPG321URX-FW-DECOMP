/* leon2m FUN_a0101d9c @ 0xa0101d9c-0xa0101e24 (34 words).
 * Writes 0 to hardware register 0xcf00ec04, then splits four 16-bit values into register pairs: for a, b, c and d
 * in turn, the low byte goes to 0xcf00ec08 / 0xcf00ec10 / 0xcf00ec18 / 0xcf00ec20 and bits 8-12 go to 0xcf00ec0c /
 * 0xcf00ec14 / 0xcf00ec1c / 0xcf00ec24. The parameters are unsigned short (no masking of the upper half before the
 * shift). No direct callers were found.
 */
#define REG_cf00ec04 (*(volatile unsigned int *)0xcf00ec04)
#define REG_cf00ec08 (*(volatile unsigned int *)0xcf00ec08)
#define REG_cf00ec0c (*(volatile unsigned int *)0xcf00ec0c)
#define REG_cf00ec10 (*(volatile unsigned int *)0xcf00ec10)
#define REG_cf00ec14 (*(volatile unsigned int *)0xcf00ec14)
#define REG_cf00ec18 (*(volatile unsigned int *)0xcf00ec18)
#define REG_cf00ec1c (*(volatile unsigned int *)0xcf00ec1c)
#define REG_cf00ec20 (*(volatile unsigned int *)0xcf00ec20)
#define REG_cf00ec24 (*(volatile unsigned int *)0xcf00ec24)

void FUN_a0101d9c(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    REG_cf00ec04 = 0;
    REG_cf00ec08 = a & 0xff;
    REG_cf00ec0c = (a >> 8) & 0x1f;
    REG_cf00ec10 = b & 0xff;
    REG_cf00ec14 = (b >> 8) & 0x1f;
    REG_cf00ec18 = c & 0xff;
    REG_cf00ec1c = (c >> 8) & 0x1f;
    REG_cf00ec20 = d & 0xff;
    REG_cf00ec24 = (d >> 8) & 0x1f;
}
