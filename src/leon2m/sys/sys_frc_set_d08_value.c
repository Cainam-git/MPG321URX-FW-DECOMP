/* sys_frc_set_d08_value  (FUN_a0109b70)
 *
 * Write a 16-bit value to 0xCF011D08 and split it over 0xCF011EC4 and 0xCF011EC0.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109b70 @ 0xa0109b70, flags -mcpu=v8 -O3 -g.
 * Source form: the decompiler's shape is kept: a second parameter that is not used and a CONCAT44 return of
 * the last value ORed with 0x80, in a function declared void.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern void reg_write16_bytes();
#define REG_CF011EC0 (*(volatile unsigned int *)0xcf011ec0)
#define REG_CF011EC4 (*(volatile unsigned int *)0xcf011ec4)

/*
 * Write the 16-bit `value` to the register 0xCF011D08 (reg_write16_bytes) and 0 to 0xCF011D00; then write the low
 * byte of `value` to 0xCF011EC4 and its high byte ORed with 0x80 to 0xCF011EC0.
 * Nothing in the image calls it; `unused` is not used.
 */
void sys_frc_set_d08_value(unsigned short value,unsigned int unused)

{
  unsigned int high_byte;
  
  reg_write16_bytes(0xcf011d08,value & 0xffff);
  reg_write16_bytes(0xcf011d00,0);
  REG_CF011EC4 = value & 0xff;
  high_byte = (value & 0xffff) >> 8;
  REG_CF011EC0 = high_byte | 0x80;
  return CONCAT44(unused,high_byte) | 0x80;
}
