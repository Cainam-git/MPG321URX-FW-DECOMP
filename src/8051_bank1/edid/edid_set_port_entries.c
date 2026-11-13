/* edid_set_port_entries  (FUN_CODE_bbca)
 *
 * Enable and set the EDID slave entry of each port selected by mask.
 *   port_mask: channels 0..6
 *   entry_value: value
 * Name basis: derived - mailbox command 0x0E; port pairs 0xF180 + 2i / 0xF181 + 2i bit 7, the pairs
 *   edid_clear_port_entries clears
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_bbca @ 0xbbca, OPTIMIZE(7,SPEED).
 * Source form: seven separate ifs in bit order 0..6; in each the control register is written before the entry.
 */
extern unsigned char xdata reg_edid0_entry _at_ 0xf180;
extern unsigned char xdata reg_edid0_entry_ctrl _at_ 0xf181;
extern unsigned char xdata reg_edid1_entry _at_ 0xf182;
extern unsigned char xdata reg_edid1_entry_ctrl _at_ 0xf183;
extern unsigned char xdata reg_edid2_entry _at_ 0xf184;
extern unsigned char xdata reg_edid2_entry_ctrl _at_ 0xf185;
extern unsigned char xdata reg_edid3_entry _at_ 0xf186;
extern unsigned char xdata reg_edid3_entry_ctrl _at_ 0xf187;
extern unsigned char xdata reg_edid4_entry _at_ 0xf188;
extern unsigned char xdata reg_edid4_entry_ctrl _at_ 0xf189;
extern unsigned char xdata reg_edid5_entry _at_ 0xf18a;
extern unsigned char xdata reg_edid5_entry_ctrl _at_ 0xf18b;
extern unsigned char xdata reg_edid6_entry _at_ 0xf18c;
extern unsigned char xdata reg_edid6_entry_ctrl _at_ 0xf18d;

#define EDID_ENTRY_ON  0x80  /* reg_edid<N>_entry_ctrl bit 7: the port's extra EDID entry is on */

/*
 * edid_set_port_entries - switch on the extra EDID entry of every port whose bit is set in port_mask.
 *   port_mask    bit N = port N (0..6); bit 7 and ports whose bit is clear are left as they are
 *   entry_value  written unchanged into reg_edid<N>_entry of each chosen port
 * For each chosen port: set bit 7 of reg_edid<N>_entry_ctrl, then store entry_value in reg_edid<N>_entry.
 * Only caller: mailbox command IPC_8051_CMD_SET_EDID_ENTRIES (0x0E) in ipc_run_command, which the main processor
 * sends for EDIDs longer than 256 bytes (docs/MAILBOX.md). Command 0x0F (edid_clear_port_entries) clears bit 7
 * again.
 */
void edid_set_port_entries(unsigned char port_mask, unsigned char entry_value)
{
    if (port_mask & 0x01) {
        reg_edid0_entry_ctrl |= EDID_ENTRY_ON;
        reg_edid0_entry = entry_value;
    }
    if (port_mask & 0x02) {
        reg_edid1_entry_ctrl |= EDID_ENTRY_ON;
        reg_edid1_entry = entry_value;
    }
    if (port_mask & 0x04) {
        reg_edid2_entry_ctrl |= EDID_ENTRY_ON;
        reg_edid2_entry = entry_value;
    }
    if (port_mask & 0x08) {
        reg_edid3_entry_ctrl |= EDID_ENTRY_ON;
        reg_edid3_entry = entry_value;
    }
    if (port_mask & 0x10) {
        reg_edid4_entry_ctrl |= EDID_ENTRY_ON;
        reg_edid4_entry = entry_value;
    }
    if (port_mask & 0x20) {
        reg_edid5_entry_ctrl |= EDID_ENTRY_ON;
        reg_edid5_entry = entry_value;
    }
    if (port_mask & 0x40) {
        reg_edid6_entry_ctrl |= EDID_ENTRY_ON;
        reg_edid6_entry = entry_value;
    }
}
