/* input_set_command_flags  (FUN_a006fff4)
 *
 * Store the port action flag byte sent by the main processor.
 *   flags: flag byte
 * Name basis: derived - byte read bit by bit by the dp_tx_mode_requested_* and input_get_command_flag_*
 *   getters; caller ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006fff4 @ 0xa006fff4, flags -mcpu=v8 -Os -g.
 */

extern unsigned char input_command_flags;

/*
 * Store the port action flag byte sent by the main processor. Bits 0 and 1 are read by
 * hdmi_tx_is_port0_enabled / _bit1 (enables of HDMI TX ports 0 and 1); the dp_tx_mode_requested_* routines
 * read it too. Called from
 * ipc_dispatch_command.
 */
void input_set_command_flags(unsigned char flags)
{
  input_command_flags = flags;
}
