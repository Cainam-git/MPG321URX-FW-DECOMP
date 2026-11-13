/* dp_tx_mode_requested_4  (FUN_a006ffe4)
 *
 * Return whether the main processor requested the DP output mode update 4.
 * Returns: non-zero when requested
 * Name basis: derived - bit 0x40 of the command byte; caller runs DPTX_SetBrilliantMode(4) when set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006ffe4 (-mcpu=v8 -Os -g)
 * Source form: unsigned char return type and flag byte.
 */
extern unsigned char input_command_flags;

/*
 * Return non-zero when bit 0x40 of input_command_flags (the port action flag byte set by the main
 * processor) is set. dp_tx_run_output_tasks runs DPTX_SetBrilliantMode(4) when it is.
 */
unsigned char dp_tx_mode_requested_4(void)
{
    return input_command_flags & 0x40;
}
