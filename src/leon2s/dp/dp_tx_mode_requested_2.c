/* dp_tx_mode_requested_2  (FUN_a006ffc4)
 *
 * Return whether the main processor requested the DP output mode update 2.
 * Returns: non-zero when requested
 * Name basis: derived - bit 0x10 of the command byte; caller runs DPTX_SetBrilliantMode(2) when set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006ffc4 (-mcpu=v8 -Os -g)
 * Source form: unsigned char return type and flag byte.
 */
extern unsigned char input_command_flags;

/*
 * Return non-zero when bit 0x10 of input_command_flags (the port action flag byte set by the main
 * processor) is set. dp_tx_run_output_tasks runs DPTX_SetBrilliantMode(2) when it is.
 */
unsigned char dp_tx_mode_requested_2(void)
{
    return input_command_flags & 0x10;
}
