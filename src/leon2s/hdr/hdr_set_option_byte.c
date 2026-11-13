/* hdr_set_option_byte  (FUN_a00d3f70)
 *
 * Store an HDR option byte and mark the settings as changed.
 * Name basis: descriptive - byte at 0xA8078C30
 *
 * Matching notes
 * --------------
 * FUN_a00d3f70 (leon2s 0xa00d3f70-0xa00d3f88, 24 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The two stores use separate sethi instructions: the bytes are separate symbols.
 * It lies in the code range 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c
 * (byte tables and '[HDR]' format strings).
 */
extern unsigned char hdr_settings_changed_flag;
extern unsigned char hdr_option_byte;

/*
 * Set hdr_settings_changed_flag and store option in hdr_option_byte, the option bits that hdr_task and the curve
 * loader test. Called by the mailbox command IPC_CMD_SET_HDR_OPTION_BYTE.
 */
void hdr_set_option_byte(unsigned char option)
{
    hdr_settings_changed_flag = 1;
    hdr_option_byte = option;
}
