/* dp_tx_mode_requested_1  (FUN_a006ffb4)
 *
 * Return whether the main processor requested the DP output mode update 1.
 * Returns: non-zero when requested
 * Name basis: derived - bit 0x8 of the command byte; caller runs DPTX_SetBrilliantMode(1) when set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006ffb4 (-mcpu=v8 -Os -g)
 * Source form: unsigned char return type and flag byte.
 */
extern unsigned char input_command_flags;

/*
 * Return non-zero when bit 3 (mask 0x08) of input_command_flags (the port action flag byte set by the main
 * processor) is set. dp_tx_run_output_tasks runs DPTX_SetBrilliantMode(1) when it is.
 */
unsigned char dp_tx_mode_requested_1(void)
{
    return input_command_flags & 8;
}
