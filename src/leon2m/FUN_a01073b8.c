/* leon2m FUN_a01073b8 @ 0xa01073b8-0xa010740c (21 words).
 * Writes fixed values to seven hardware registers: 0x33 to 0xcf00e9e8 and 0xcf00eaa8, 0x90 to 0xcf00e9f8 and
 * 0xcf00eab8, 0 to 0xcf00e9fc and 0xcf00eabc, and 0xfe to 0xcf0116f0, in that order. Called from FUN_a015202c.
 */
#define REG_cf00e9e8 (*(volatile unsigned int *)0xcf00e9e8)
#define REG_cf00eaa8 (*(volatile unsigned int *)0xcf00eaa8)
#define REG_cf00e9f8 (*(volatile unsigned int *)0xcf00e9f8)
#define REG_cf00eab8 (*(volatile unsigned int *)0xcf00eab8)
#define REG_cf00e9fc (*(volatile unsigned int *)0xcf00e9fc)
#define REG_cf00eabc (*(volatile unsigned int *)0xcf00eabc)
#define REG_cf0116f0 (*(volatile unsigned int *)0xcf0116f0)

void FUN_a01073b8(void)
{
    REG_cf00e9e8 = 0x33;
    REG_cf00eaa8 = 0x33;
    REG_cf00e9f8 = 0x90;
    REG_cf00eab8 = 0x90;
    REG_cf00e9fc = 0;
    REG_cf00eabc = 0;
    REG_cf0116f0 = 0xfe;
}
