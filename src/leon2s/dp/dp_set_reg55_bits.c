/* dp_set_reg55_bits  (FUN_a00b1224)
 *
 * Write bits 6 and 4 of register 0x55 by a mode 0..2.
 * Name basis: descriptive - 0 -> 0/0, 2 -> 1/0, 1 -> 1/1
 *
 * Matching notes
 * --------------
 * FUN_a00b1224 (leon2s, 0xa00b1224-0xa00b12c4, 160 bytes), flags -mcpu=v8 -Os -g.
 * The switch is on the u8 mode (signed case tree, root 1). The second dp_reg_update_bits call of each case
 * is a sibcall (call + restore). dp_reg_update_bits is void (u32, u16, u32, u32), the accepted
 * prototype in src/leon2s.
 * Source form: the case SOURCE order 0, 2, 1 gives the firmware's block layout (other orders give another
 * layout).
 */
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);

/* Write bit 6 (0x40) and bit 4 (0x10) of register 0x55 of DisplayPort receiver `port` by `mode`:
 *   mode 0: both cleared    mode 1: both set    mode 2: bit 6 set, bit 4 cleared
 * Any other mode does nothing. */
void dp_set_reg55_bits(unsigned char port, unsigned char mode)
{
    switch (mode) {
    case 0:
        dp_reg_update_bits(port, 0x55, 0x40, 0);
        dp_reg_update_bits(port, 0x55, 0x10, 0);
        break;
    case 2:
        dp_reg_update_bits(port, 0x55, 0x40, 1);
        dp_reg_update_bits(port, 0x55, 0x10, 0);
        break;
    case 1:
        dp_reg_update_bits(port, 0x55, 0x40, 1);
        dp_reg_update_bits(port, 0x55, 0x10, 1);
        break;
    }
}
