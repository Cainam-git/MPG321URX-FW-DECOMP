/* edid_set_port_control_bit6  (FUN_CODE_c87f)
 *
 * Write bit 6 of one port's EDID slave control register and clear its bits 0 and 1.
 *   port: one-hot port bit 0x01..0x40 (ports 0..6)
 *   on: 1 sets bit 6, every other value clears it
 * Note: The register becomes (old & 0xBC) | 0x40 for on == 1 and (old & 0xBC) for every other value; a port
 *   value that is not one of the seven bits changes nothing.
 * Name basis: descriptive - one-hot port 0x01..0x40 -> 0xF01C.. (reg & 0xBC) | 0x40; command 0x1F (main side
 *   ipc_8051_set_edid_slave_bit6)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c87f @ 0xc87f (78 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Source form: 'bit6_value' must be a '?:' (an if/else puts it in a memory location instead of R6). Keil shares
 * the read-modify-write tail of the seven cases and tests 'port' in the order 2, 4, 8, 0x10, 0x20, 0x40, 1.
 */
extern unsigned char xdata reg_edid0_ctrl, reg_edid1_ctrl, reg_edid2_ctrl, reg_edid3_ctrl;
extern unsigned char xdata reg_edid4_ctrl, reg_edid5_ctrl, reg_edid6_ctrl;

/*
 * Set (on == 1) or clear (any other value) bit 6 of the control register of
 * one port. 'port' is one-hot: 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40 pick
 * ports 0..6; any other value changes nothing. The register is rewritten as
 * (reg & 0xbc) | bit6_value: bits 0, 1 and 6 are cleared and
 * bit 6 is then set when on == 1; bits 2..5 and 7 keep their value.
 * Only caller: command 0x1F of the command switch.
 */
void edid_set_port_control_bit6(unsigned char port, unsigned char on)
{
    unsigned char bit6_value;

    bit6_value = (on == 1) ? 0x40 : 0;
    switch (port) {
    case 0x01: reg_edid0_ctrl = (reg_edid0_ctrl & 0xbc) | bit6_value; break;
    case 0x02: reg_edid1_ctrl = (reg_edid1_ctrl & 0xbc) | bit6_value; break;
    case 0x04: reg_edid2_ctrl = (reg_edid2_ctrl & 0xbc) | bit6_value; break;
    case 0x08: reg_edid3_ctrl = (reg_edid3_ctrl & 0xbc) | bit6_value; break;
    case 0x10: reg_edid4_ctrl = (reg_edid4_ctrl & 0xbc) | bit6_value; break;
    case 0x20: reg_edid5_ctrl = (reg_edid5_ctrl & 0xbc) | bit6_value; break;
    case 0x40: reg_edid6_ctrl = (reg_edid6_ctrl & 0xbc) | bit6_value; break;
    }
}
