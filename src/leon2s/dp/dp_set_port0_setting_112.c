/* dp_set_port0_setting_112  (FUN_a00afd74)
 *
 * Store a setting byte of port 0 and apply the port's settings again.
 * Name basis: descriptive - byte at 0xA807DD2A; set by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00afd74 @ 0xa00afd74 (-mcpu=v8 -Os -g)
 * Source form: the routine is declared void but contains 'return' statements with a value (the shifted second
 * parameter for ports other than 0, the last call's result for port 0); the build depends on them, so they stay.
 * The unused parameters 3 to 6 are handed on to the last call, which is declared without a parameter list. The
 * local result variable is set to 0 and never read.
 */
extern unsigned char dp_input_record0_setting_0x112;    /* byte 0x112 of the DP input record of port 0 */
extern int dp_program_port();
extern int dp_setup_port_regs();
extern int dp_apply_port_settings();

/*
 * For port 0 only: store value in byte 0x112 of the DP input record (dp_program_port: non-zero selects the
 * alternative set-up of port 0), then run dp_program_port, dp_setup_port_regs and dp_apply_port_settings for
 * port 0. Any other port is ignored.
 *   port: DP receiver (0 or 1)
 *   value: new byte
 * Called for mailbox command 0x24 (prints '_SetDPMST'), which switches DP multi-stream on or off. The returned
 * value is not used.
 */
void dp_set_port0_setting_112(unsigned char port, unsigned int value, unsigned int arg3, unsigned int arg4,
                              unsigned int arg5, unsigned int arg6)

{
  unsigned int unused_result;

  if (port != 0) {
    return (unsigned long long)value << 0x20;
  }
  dp_input_record0_setting_0x112 = (unsigned char)value;
  dp_program_port(0);
  dp_setup_port_regs(0);
  unused_result = 0;
  return dp_apply_port_settings(0, value, arg3, arg4, arg5, arg6);
}
