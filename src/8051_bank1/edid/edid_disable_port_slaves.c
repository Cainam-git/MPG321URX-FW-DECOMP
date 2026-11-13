/* edid_disable_port_slaves  (FUN_CODE_c790)
 *
 * Switch off the EDID slave of the ports chosen by a bit mask.
 *   port_mask: port bits 0..6
 * Name basis: derived - clears bit 7 of the registers that edid_enable_port_slaves sets; command 0x02 (main
 *   side ipc_8051_disable_internal_edid)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c790 @ 0xc790  OPTIMIZE(8,SPEED) LARGE
 */
extern xdata unsigned char reg_edid0_ctrl;
extern xdata unsigned char reg_edid1_ctrl;
extern xdata unsigned char reg_edid2_ctrl;
extern xdata unsigned char reg_edid3_ctrl;
extern xdata unsigned char reg_edid4_ctrl;
extern xdata unsigned char reg_edid5_ctrl;
extern xdata unsigned char reg_edid6_ctrl;

/*
 * Bit i of port_mask (i = 0..6) selects port i; for each selected port bit 7
 * of its control register (0x7f keeps the other bits) is cleared, undoing
 * edid_enable_port_slaves. Command 0x02 of the command switch.
 */
void edid_disable_port_slaves(unsigned char port_mask)
{
    if (port_mask & 0x01) {
        reg_edid0_ctrl &= 0x7f;
    }
    if (port_mask & 0x02) {
        reg_edid1_ctrl &= 0x7f;
    }
    if (port_mask & 0x04) {
        reg_edid2_ctrl &= 0x7f;
    }
    if (port_mask & 0x08) {
        reg_edid3_ctrl &= 0x7f;
    }
    if (port_mask & 0x10) {
        reg_edid4_ctrl &= 0x7f;
    }
    if (port_mask & 0x20) {
        reg_edid5_ctrl &= 0x7f;
    }
    if (port_mask & 0x40) {
        reg_edid6_ctrl &= 0x7f;
    }
}
