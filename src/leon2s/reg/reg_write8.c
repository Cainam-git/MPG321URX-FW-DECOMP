/* reg_write8  (FUN_a0061578)
 *
 * Write one byte of a register through an aligned 32-bit read-modify-write.
 *   addr: byte address
 *   value: byte value
 * Name basis: proven - replaces byte (addr & 3) of the word at addr & ~3
 *
 * Matching notes
 * --------------
 * FUN_a0061578 (leon2s 0xa0061578-0xa00615ac, 52 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The only caller is the wrapper reg_write8_wrapper. The word is accessed through a volatile pointer as in
 * reg_read32, reg_write32 and reg_write32_masked (the store stays before retl).
 * Source form: the word is read into a local, updated in one expression and written back.
 */
/*
 * Write one byte through an aligned 32-bit read-modify-write; the other three bytes of the word keep their
 * value. Counterpart of reg_read8.
 *   addr:  byte address; byte (addr & 3) of the word at addr & ~3 is replaced (byte 0 = bits 0..7)
 *   value: new byte (only the low 8 bits are used)
 */
void reg_write8(unsigned int addr, unsigned int value)
{
    volatile unsigned int *word_ptr = (volatile unsigned int *)(addr & ~3);
    unsigned int shift = (addr & 3) << 3;
    unsigned int word = *word_ptr;
    word = (word & ~(0xff << shift)) | ((value & 0xff) << shift);
    *word_ptr = word;
}
