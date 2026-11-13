/* reg_write24_bytes  (FUN_a00f30c8)
 *
 * Write a 24-bit value to three byte registers.
 * Name basis: proven - without a delay; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f30c8 @ 0xa00f30c8, flags -mcpu=v8 -O3 -g.
 * Source form: the pointer is to volatile words (with a plain pointer the compiler reorders the stores and
 * moves the last into the delay slot).
 */
/*
 * Write a 24-bit value to three registers that each hold one byte: bits 0..7 to reg[0], bits 8..15 to reg[1],
 * bits 16..23 to reg[2]. Nothing calls it. reg_write24_bytes_settle does the same and then waits.
 */
void reg_write24_bytes(volatile unsigned int *reg, unsigned int value)
{
    reg[0] = value & 0xff;
    reg[1] = (value >> 8) & 0xff;
    reg[2] = (value >> 16) & 0xff;
}
