/* reg_read32_bytes  (FUN_a00f3164)
 *
 * Read a 32-bit value from four byte registers.
 * Returns: value
 * Name basis: proven - p[0] | p[1] << 8 | p[2] << 16 | p[3] << 24
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3164 @ 0xa00f3164, flags -mcpu=v8 -O3 -g.
 * Source form: the pointer is to volatile words, read in the order reg[0], reg[1], reg[2], reg[3] (reg[0] into
 * a local first).
 */
/*
 * Return a 32-bit value held in four registers that each hold one byte, lowest byte first: reg[0] is bits
 * 0..7, reg[3] bits 24..31. The counterpart of reg_write32_bytes. Called by sys_get_region_address.
 */
unsigned int reg_read32_bytes(volatile unsigned int *reg)
{
    unsigned int low = reg[0];

    return (reg[1] << 8) | low | (reg[2] << 16) | (reg[3] << 24);
}
