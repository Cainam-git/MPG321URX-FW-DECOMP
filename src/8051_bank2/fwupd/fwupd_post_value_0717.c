/* fwupd_post_value_0717  (FUN_CODE_dbd0)
 *
 * Copy the 32-bit value at XDATA 0x0717 into port registers 0xF19B..0xF19E.
 * Name basis: descriptive - low byte first; port command 0x43 and the command switch
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED). The shifts by 8 / 16 / 24 are ?C?ULSHR; the low byte is read straight from XDATA
 * 0x071A (Keil stores a long high byte first). The mailbox bytes are only written, so no volatile.
 */
extern unsigned long xdata fwupd_dram_address;
extern unsigned char xdata reg_fwupd_mailbox_f19b, reg_fwupd_mailbox_f19c, reg_fwupd_mailbox_f19d, reg_fwupd_mailbox_f19e;

/* fwupd_post_value_0717: put fwupd_dram_address (the first block of the loaded file in memory) into mailbox bytes
 * 0xF19B..0xF19E, low byte first, for the main processor to read.
 * Callers: fwupd_run_mailbox_command (MBOX_CMD_GET_DRAM_ADDRESS 0x5B) and fwupd_step_port_state (port command
 * CMD_POST_0717 0x43). */
void fwupd_post_value_0717(void)
{
    reg_fwupd_mailbox_f19b = fwupd_dram_address;
    reg_fwupd_mailbox_f19c = fwupd_dram_address >> 8;
    reg_fwupd_mailbox_f19d = fwupd_dram_address >> 16;
    reg_fwupd_mailbox_f19e = fwupd_dram_address >> 24;
}
