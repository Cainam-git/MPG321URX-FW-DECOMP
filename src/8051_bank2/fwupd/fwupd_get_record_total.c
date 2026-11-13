/* fwupd_get_record_total  (FUN_CODE_e507)
 *
 * Return the record total of the update image (fwupd_record_total, in 256-byte units).
 * Returns: 32-bit total
 * Name basis: derived - plain getter of fwupd_record_total; only caller fwupd_run_mailbox_command, command
 *   0x60
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e507 @ 0xe507, OPTIMIZE(7,SPEED).
 * Same code as fwupd_get_value_0717 (fwupd_get_value_0717) with another address.
 */

/* XDATA 0x0113: the sizes of records 1 and up of the update image, each rounded up to 256-byte units and added
 * (fwupd_build_record_table). */
extern unsigned long xdata fwupd_record_total;

/* Return the record total at XDATA 0x0113.
 * Only caller: fwupd_run_mailbox_command, command 0x60 (GET_RECORD_TOTAL), which posts bits 0..23 in mailbox
 * bytes 0xF19B..0xF19D. */
unsigned long fwupd_get_record_total(void)
{
    return fwupd_record_total;
}
