/* startup_reset_output_blocks  (FUN_a01073b8)
 *
 * Write the fixed start values of seven output block registers.
 * Name basis: descriptive - registers between 0xCF00E9E8 and 0xCF0116F0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01073b8, flags -mcpu=v8 -O3 -g.
 */
#define REG_cf00e9e8 (*(volatile unsigned int *)0xcf00e9e8)
#define REG_cf00eaa8 (*(volatile unsigned int *)0xcf00eaa8)
#define REG_cf00e9f8 (*(volatile unsigned int *)0xcf00e9f8)
#define REG_cf00eab8 (*(volatile unsigned int *)0xcf00eab8)
#define REG_cf00e9fc (*(volatile unsigned int *)0xcf00e9fc)
#define REG_cf00eabc (*(volatile unsigned int *)0xcf00eabc)
#define REG_cf0116f0 (*(volatile unsigned int *)0xcf0116f0)

/*
 * Write the start values: 0x33 to 0xCF00E9E8 and 0xCF00EAA8, 0x90 to 0xCF00E9F8 and 0xCF00EAB8, 0 to 0xCF00E9FC
 * and 0xCF00EABC, 0xFE to 0xCF0116F0, in that order. Called by sys_init_enable_output_blocks.
 */
void startup_reset_output_blocks(void)
{
    REG_cf00e9e8 = 0x33;
    REG_cf00eaa8 = 0x33;
    REG_cf00e9f8 = 0x90;
    REG_cf00eab8 = 0x90;
    REG_cf00e9fc = 0;
    REG_cf00eabc = 0;
    REG_cf0116f0 = 0xfe;
}
