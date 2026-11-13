/* fwupd_post_value_0109  (FUN_CODE_dc24)
 *
 * Copy the 32-bit value at XDATA 0x0109 into port registers 0xF19C..0xF19F.
 * Name basis: descriptive - low byte first; port command 0x44
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED). The shifts by 8 / 16 / 24 are ?C?ULSHR; the low byte is read straight from XDATA
 * 0x010C (Keil stores a long high byte first).
 */
extern unsigned long xdata fwupd_file_size;
extern unsigned char xdata reg_fwupd_mailbox_f19c, reg_fwupd_mailbox_f19d, reg_fwupd_mailbox_f19e, reg_fwupd_mailbox_f19f;

/* fwupd_post_value_0109: put fwupd_file_size into mailbox bytes 0xF19C..0xF19F, low byte first.
 * The mailbox command MBOX_CMD_GET_FILE_SIZE (0x5A) of fwupd_run_mailbox_command posts the same value one byte
 * lower, in 0xF19B..0xF19E.
 * Caller: fwupd_step_port_state (port command CMD_POST_0109 0x44). */
void fwupd_post_value_0109(void)
{
    reg_fwupd_mailbox_f19c = fwupd_file_size;
    reg_fwupd_mailbox_f19d = fwupd_file_size >> 8;
    reg_fwupd_mailbox_f19e = fwupd_file_size >> 16;
    reg_fwupd_mailbox_f19f = fwupd_file_size >> 24;
}
