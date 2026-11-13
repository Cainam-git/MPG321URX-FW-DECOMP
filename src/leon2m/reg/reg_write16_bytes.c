/* reg_write16_bytes  (FUN_a00f308c)
 *
 * Write a 16-bit value to two byte registers.
 * Name basis: proven - low byte to p[0], high byte to p[1]
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f308c @ 0xa00f308c, flags -mcpu=v8 -O2 -g.
 * Source form: a volatile word pointer.
 */
/*
 * Write a 16-bit value to two registers that each hold one byte: bits 0..7 to reg[0], bits 8..15 to reg[1].
 * The write counterpart of reg_read16_bytes. Used by panel_output_setup_clock for the register pairs from
 * 0xCF00B81C.
 */
void reg_write16_bytes(volatile unsigned int *reg, unsigned int value)
{
    reg[0] = value & 0xff;
    reg[1] = (value >> 8) & 0xff;
}
