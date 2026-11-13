/* edid_clear_port_entries  (FUN_CODE_c7e0)
 *
 * Clear the enable bit of the port entries chosen by a bit mask.
 *   port_mask: port bits 0..6
 * Name basis: descriptive - clears bit 7 of 0xF181 + 2i; command 0x0F (main side
 *   ipc_8051_disable_internal_edid); command 0x0E sets them
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c7e0 @ 0xc7e0  OPTIMIZE(8,SPEED) LARGE
 * Source form: the seven entry registers are declared with '_at_' addresses.
 */
extern xdata unsigned char reg_edid0_entry_ctrl _at_ 0xF181;
extern xdata unsigned char reg_edid1_entry_ctrl _at_ 0xF183;
extern xdata unsigned char reg_edid2_entry_ctrl _at_ 0xF185;
extern xdata unsigned char reg_edid3_entry_ctrl _at_ 0xF187;
extern xdata unsigned char reg_edid4_entry_ctrl _at_ 0xF189;
extern xdata unsigned char reg_edid5_entry_ctrl _at_ 0xF18B;
extern xdata unsigned char reg_edid6_entry_ctrl _at_ 0xF18D;

/*
 * Bit i of port_mask (i = 0..6) selects port i; for each selected port bit 7
 * of its extra EDID entry (0xF181 + 2 * i) is cleared. edid_set_port_entries
 * sets the same bits. Command 0x0F of the command switch.
 */
void edid_clear_port_entries(unsigned char port_mask)
{
    if (port_mask & 0x01) {
        reg_edid0_entry_ctrl &= 0x7F;
    }
    if (port_mask & 0x02) {
        reg_edid1_entry_ctrl &= 0x7F;
    }
    if (port_mask & 0x04) {
        reg_edid2_entry_ctrl &= 0x7F;
    }
    if (port_mask & 0x08) {
        reg_edid3_entry_ctrl &= 0x7F;
    }
    if (port_mask & 0x10) {
        reg_edid4_entry_ctrl &= 0x7F;
    }
    if (port_mask & 0x20) {
        reg_edid5_entry_ctrl &= 0x7F;
    }
    if (port_mask & 0x40) {
        reg_edid6_entry_ctrl &= 0x7F;
    }
}
