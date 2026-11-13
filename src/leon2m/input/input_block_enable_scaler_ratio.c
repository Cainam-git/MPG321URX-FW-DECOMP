/* input_block_enable_scaler_ratio  (FUN_a00f88e8)
 *
 * Write a ratio to register 0x99 of an input block and switch its scaling bit on.
 * Name basis: descriptive - bit 7 of register 0x9C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f88e8 @ 0xa00f88e8, flags -mcpu=v8 -O2 -g.
 */
extern int input_capture_update_bits();
extern int input_capture_write16();

/* Write the ratio to 16-bit register 0x99 of the capture block, then set bit 7 of register 0x9C.
 * input_block_disable_scaler clears that bit again. */
void input_block_enable_scaler_ratio(unsigned int block, unsigned short ratio)
{
    input_capture_write16(block & 0xff, 0x99, ratio & 0xffff);
    input_capture_update_bits(block & 0xff, 0x9c, 0x80, '\x01');
    return;
}
