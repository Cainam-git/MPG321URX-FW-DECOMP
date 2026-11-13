/* fwupd_get_value_0109  (FUN_CODE_e4f8)
 *
 * Return the 32-bit value stored at XDATA 0x0109.
 * Returns: value
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e4f8 @ 0xe4f8, OPTIMIZE(7,SPEED).
 * Same code as fwupd_get_value_0717 (fwupd_get_value_0717) with another address.
 */
extern unsigned long xdata fwupd_file_size;

/* Return fwupd_file_size, the size in bytes of the selected update file (set by fwupd_set_target_file).
 * Only caller: fwupd_write_flash_blocks, which divides it by the block size to get the file's block count.
 * fwupd_get_value_0109_copy returns the same value for the mailbox. */
unsigned long fwupd_get_value_0109(void)
{
    return fwupd_file_size;
}
