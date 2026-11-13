/* reg_write32_bytes  (FUN_a00f3134)
 *
 * Write a 32-bit value to four byte registers.
 * Name basis: proven - bytes 0..3 to p[0..3]
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3134 @ 0xa00f3134, flags -mcpu=v8 -O2 -g.
 * Source form: the pointer is to volatile words (as in reg_write24_bytes); with a plain pointer the compiler
 * reorders the stores and moves the last into the delay slot.
 */
/*
 * Write a 32-bit value to four registers that each hold one byte, lowest byte first: reg[0] gets bits 0..7,
 * reg[3] bits 24..31. Called by sys_frc_write_setting_values.
 */
void reg_write32_bytes(volatile unsigned int *reg, unsigned int value)
{
    reg[0] = value & 0xff;
    reg[1] = (value >> 8) & 0xff;
    reg[2] = (value >> 16) & 0xff;
    reg[3] = value >> 24;
}
