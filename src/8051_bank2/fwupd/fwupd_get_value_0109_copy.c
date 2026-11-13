/* fwupd_get_value_0109_copy  (FUN_CODE_e516)
 *
 * Return the 32-bit value stored at XDATA 0x0109 (second copy).
 * Returns: value
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e516 @ 0xe516, no options recorded: the default OPTIMIZE(7,SPEED).
 * Source form: the value is read through a cast of the address 0x0109, not through the name fwupd_file_size.
 */

#define FILE_SIZE_ADDRESS   0x0109  /* XDATA place of fwupd_file_size */

/* Return the size in bytes of the selected update file (fwupd_file_size, as fwupd_get_value_0109).
 * Only caller: fwupd_run_mailbox_command, command 0x5A (GET_FILE_SIZE), which posts it in mailbox bytes
 * 0xF19B..0xF19E, low byte first. */
unsigned long fwupd_get_value_0109_copy(void)
{
    return *(unsigned long xdata *)FILE_SIZE_ADDRESS;
}
