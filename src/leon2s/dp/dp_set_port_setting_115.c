/* dp_set_port_setting_115  (FUN_a00afd04)
 *
 * Store a setting byte of a port and apply the port's settings again.
 * Name basis: descriptive - byte +0x115 of the port's 300-byte record; set by a command from the main
 *   processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00afd04 @ 0xa00afd04 (-mcpu=v8 -Os -g)
 * Source form: the record byte is addressed as an index into a char array; the last call is a tail call. Each
 * callee takes one argument.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern int dp_program_port(int);
extern int dp_setup_port_regs(int);
extern int dp_apply_port_settings(int);
extern char dp_input_records[];

/*
 * Store value in byte 0x115 of the port's DP input record (dp_program_port uses it to set or clear bit 0x40 of
 * register 0x207), then run dp_program_port, dp_setup_port_regs and dp_apply_port_settings for the port.
 *   port: DP receiver (0 or 1)
 *   value: new byte
 * Called for mailbox command 0x26.
 */
void dp_set_port_setting_115(unsigned int port, unsigned char value)
{
    port = port & 0xff;
    dp_input_records[port * DP_INPUT_RECORD_SIZE + 0x115] = (char)value;
    dp_program_port(port);
    dp_setup_port_regs(port);
    dp_apply_port_settings(port);
}
