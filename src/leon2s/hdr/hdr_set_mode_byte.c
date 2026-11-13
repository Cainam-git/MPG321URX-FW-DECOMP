/* hdr_set_mode_byte  (FUN_a00d3f88)
 *
 * Store an HDR mode byte and mark the settings as changed.
 * Name basis: descriptive - byte at 0xA8078C33
 *
 * Matching notes
 * --------------
 * FUN_a00d3f88 (leon2s 0xa00d3f88-0xa00d3fa0, 24 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The two stores use separate sethi instructions: the bytes are separate symbols.
 * It lies in the code range 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c
 * (byte tables and '[HDR]' format strings).
 */
extern unsigned char hdr_settings_changed_flag;
extern unsigned char hdr_mode_byte;

/*
 * Set hdr_settings_changed_flag and store mode in hdr_mode_byte. hdr_task runs hdr_update_smoothed_level only
 * when the byte is 1. Called by the mailbox command IPC_CMD_SET_HDR_MODE_BYTE.
 */
void hdr_set_mode_byte(unsigned char mode)
{
    hdr_settings_changed_flag = 1;
    hdr_mode_byte = mode;
}
