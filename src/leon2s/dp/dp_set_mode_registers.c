/* dp_set_mode_registers  (FUN_a00b115c)
 *
 * Write the register values for mode 0, 1 or 2 of a DisplayPort block.
 * Name basis: descriptive - two or three fixed register writes per mode
 *
 * Matching notes
 * --------------
 * FUN_a00b115c (leon2s 0xa00b115c-0xa00b1224, 200 bytes), flags -mcpu=v8 -Os -g.
 * The final dp_reg_write8 call of each case is a tail call; the range includes the trailing ret/restore of
 * the no-match path.
 */
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);

/* Write registers 0x56 and 0x57 of DisplayPort receiver `port` for mode 0, 1 or 2:
 *   mode 0: reg 0x56 bits 0..1 cleared, reg 0x57 = 3
 *   mode 1: reg 0x56 bit 1 cleared and bit 0 set, reg 0x57 = 7
 *   mode 2: reg 0x56 bit 1 set and bit 0 cleared, reg 0x57 = 3
 * Any other mode does nothing. */
void dp_set_mode_registers(unsigned char port, unsigned char mode)
{
    switch (mode) {
    case 0:
        dp_reg_update_bits(port, 0x56, 3, 0);
        dp_reg_write8(port, 0x57, 3);
        break;
    case 1:
        dp_reg_update_bits(port, 0x56, 2, 0);
        dp_reg_update_bits(port, 0x56, 1, 1);
        dp_reg_write8(port, 0x57, 7);
        break;
    case 2:
        dp_reg_update_bits(port, 0x56, 2, 1);
        dp_reg_update_bits(port, 0x56, 1, 0);
        dp_reg_write8(port, 0x57, 3);
        break;
    }
}
