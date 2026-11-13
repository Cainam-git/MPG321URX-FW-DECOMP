/* dp_set_reg9f_field  (FUN_a00d65a0)
 *
 * Write the 2-bit field at bits 6-7 of register 0x9F of a port.
 * Name basis: descriptive - read, merge, write; set by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d65a0 @ 0xa00d65a0-0xa00d6624 (33 words).
 * One dp_reg_write8 call per case in the source (GCC merges them, each is a tail call). The ret/restore
 * epilogue at 0xa00d661c, reached by a branch, belongs to this function.
 */
extern unsigned char dp_reg_read8(unsigned char, unsigned int);
extern void dp_reg_write8(unsigned char, unsigned int, unsigned char);

/* Replace bits 6..7 of register 0x9F of DisplayPort receiver `port` by `value` (0..3), keeping bits
 * 0..5. Does nothing for port 1 (the register is read first) and for a value above 3. */
void dp_set_reg9f_field(unsigned char port, unsigned char value)
{
    unsigned char reg_value = dp_reg_read8(port, 0x9f);

    if (port == 1)
        return;
    switch (value) {
    case 0: dp_reg_write8(port, 0x9f, reg_value & 0x3f); break;
    case 1: dp_reg_write8(port, 0x9f, (reg_value & 0x3f) | 0x40); break;
    case 2: dp_reg_write8(port, 0x9f, (reg_value & 0x3f) | 0x80); break;
    case 3: dp_reg_write8(port, 0x9f, reg_value | 0xc0); break;
    }
}
