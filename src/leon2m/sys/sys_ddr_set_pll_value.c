/* sys_ddr_set_pll_value  (FUN_a00df648)
 *
 * Write a clock value to the three clock registers of a memory interface.
 * Name basis: descriptive - value << 17 divided by 12, in three bytes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df648 @ 0xa00df648, flags -mcpu=v8 -O3 -g.
 * Source form: the register addresses are written as offsets of the unsigned parameter (index * 4 + constant),
 * as the decompiler shows them.
 */
/*
 * Write a 24-bit value to the three registers 0xCF000000 + 4 * index, +4 and +8, one byte each (lowest
 * byte first). The 24-bit value is (value << 17) / 12; sys_ddr_measure_pll reads the same registers and
 * returns (v * 12) >> 17. Called from sys_ddr_set_pll.
 */
void sys_ddr_set_pll_value(int index,int value)

{
  unsigned int scaled;
  
  scaled = value << 0x11;
  index = index * 4;
  *(volatile unsigned int *)(index + -0x31000000) = scaled / 0xc & 0xff;
  *(volatile unsigned int *)(index + -0x30fffffc) = scaled / 0xc00 & 0xff;
  *(volatile unsigned int *)(index + -0x30fffff8) = scaled / 0xc0000 & 0xff;
  return;
}
