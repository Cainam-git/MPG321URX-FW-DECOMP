/* fwupd_set_value_0156  (FUN_CODE_e532)
 *
 * Store a 16-bit value at XDATA 0x0156.
 * Name basis: descriptive - plain setter
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e532 @ 0xe532..0xe53b, no options recorded: the default OPTIMIZE(7,SPEED).
 */
extern unsigned int xdata fwupd_config_sum;

/* Set fwupd_config_sum, the 16-bit sum taken from the CONFIG.bin record (fwupd_verify_file_sum fills it too).
 * Callers: fwupd_mount_volume clears it (0) at its end; fwupd_run_mailbox_command, command 0x59
 * (SET_CONFIG_SUM), stores mailbox byte 0xF19A as the high byte and 0xF19B as the low byte. */
void fwupd_set_value_0156(unsigned int sum)
{
    fwupd_config_sum = sum;
}
