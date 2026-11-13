/* sys_set_five_block_bits  (FUN_a0122d5c)
 *
 * Set one bit each in five block control registers.
 * Name basis: descriptive - 0xCF009BB8, 0xCF012C00, 0xCF012C40, 0xCF00ED00 and a fifth register
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0122d5c, flags -mcpu=v8 -O3 -g.
 * Source form: Ghidra's form is kept (five read-modify-write statements on volatile registers in this order,
 * then an explicit return).
 */
#define reg_9bb8 (*(volatile unsigned int *)0xcf009bb8)
#define reg_ed00 (*(volatile unsigned int *)0xcf00ed00)
#define reg_2c00 (*(volatile unsigned int *)0xcf012c00)
#define reg_2c40 (*(volatile unsigned int *)0xcf012c40)
#define reg_7000 (*(volatile unsigned int *)0xcf017000)

/*
 * Set one bit in each of five registers: bit 2 of 0xcf009bb8, bit 4 of 0xcf012c00 and of 0xcf012c40,
 * bit 6 of 0xcf00ed00 and bit 4 of 0xcf017000.
 * Called from App_Initialize.
 */
void sys_set_five_block_bits(void)

{
  reg_9bb8 = reg_9bb8 | 4;
  reg_2c00 = reg_2c00 | 0x10;
  reg_2c40 = reg_2c40 | 0x10;
  reg_ed00 = reg_ed00 | 0x40;
  reg_7000 = reg_7000 | 0x10;
  return;
}
