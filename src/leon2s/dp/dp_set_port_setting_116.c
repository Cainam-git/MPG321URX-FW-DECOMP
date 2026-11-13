/* dp_set_port_setting_116  (FUN_a00afd3c)
 *
 * Store a setting byte of a port and apply the port's settings again.
 * Name basis: descriptive - byte +0x116 of the port's 300-byte record; set by a command from the main
 *   processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00afd3c @ 0xa00afd3c (-mcpu=v8 -Os -g)
 * Same code as dp_set_port_setting_115 with another offset. Source form: the record byte is addressed as an index
 * into a char array; the last call is a tail call.
 */

#define DP_INPUT_RECORD_SIZE 300        /* bytes per port in the table of DP input records */

extern int dp_program_port(int);
extern int dp_setup_port_regs(int);
extern int dp_apply_port_settings(int);
extern char dp_input_records[];

/*
 * Store value in byte 0x116 of the port's DP input record (dp_program_port writes the register group
 * 0x450..0x45D when it is non-zero), then run dp_program_port, dp_setup_port_regs and dp_apply_port_settings
 * for the port.
 *   port: DP receiver (0 or 1)
 *   value: new byte
 * Called for mailbox command 0x2D.
 */
void dp_set_port_setting_116(unsigned int port, unsigned char value)
{
    port = port & 0xff;
    dp_input_records[port * DP_INPUT_RECORD_SIZE + 0x116] = (char)value;
    dp_program_port(port);
    dp_setup_port_regs(port);
    dp_apply_port_settings(port);
}
