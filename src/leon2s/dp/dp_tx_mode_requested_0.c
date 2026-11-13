/* dp_tx_mode_requested_0  (FUN_a0070424)
 *
 * Return whether the main processor requested the DP output mode update 0.
 * Returns: non-zero when requested
 * Name basis: derived - bit 0x4 of the command byte; the caller dp_tx_run_output_tasks runs
 *   DPTX_SetBrilliantMode(0) when set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0070424 (-mcpu=v8 -Os -g)
 * Source form: unsigned char return type and flag byte.
 */
extern unsigned char input_command_flags;

/*
 * Return non-zero when bit 2 (mask 0x04) of input_command_flags (the port action flag byte set by the main
 * processor) is set. dp_tx_run_output_tasks runs DPTX_SetBrilliantMode(0) when it is.
 */
unsigned char dp_tx_mode_requested_0(void)
{
    return input_command_flags & 4;
}
