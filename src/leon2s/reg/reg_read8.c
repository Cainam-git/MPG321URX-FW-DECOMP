/* reg_read8  (FUN_a006155c)
 *
 * Read one byte of a register through an aligned 32-bit access.
 *   addr: byte address
 * Returns: byte value
 * Name basis: proven - word read at addr & ~3, byte (addr & 3) extracted
 *
 * Matching notes
 * --------------
 * FUN_a006155c (leon2s, 0xa006155c-0xa0061578, 7 words, leaf). Flags -mcpu=v8 -Os -g.
 * The firmware code is: and 3, and -4, ld, sll 3, srl, and 0xff. The word is not volatile: nothing shows the
 * address is a hardware register.
 * Source form: the word load is a separate statement before the shift (the one-expression form schedules the
 * sll before the and -4 / ld).
 */
/*
 * Read one byte through an aligned 32-bit load.
 *   addr: byte address; the word at addr & ~3 is loaded and byte (addr & 3) of it is returned, counting from
 *         the least significant byte (byte 0 = bits 0..7).
 */
unsigned int reg_read8(unsigned int addr)
{
    unsigned int word = *(unsigned int *)(addr & ~3);
    return (word >> ((addr & 3) << 3)) & 0xff;
}
