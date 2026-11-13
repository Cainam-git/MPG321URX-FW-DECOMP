/* hdr_set_enable  (FUN_a00d3f30)
 *
 * Switch the HDR curve service on or off.
 * Name basis: descriptive - byte at 0xA8078C31; set by a command from the main processor
 *
 * Matching notes
 * --------------
 * FUN_a00d3f30 (leon2s 0xa00d3f30-0xa00d3f54, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * It lies in the code range 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c
 * (byte tables and '[HDR]' format strings).
 */
extern unsigned char hdr_enable;

/*
 * Store 1 (on != 0) or 0 in hdr_enable. hdr_update_tone_curve tests it when it picks the luminance for an ST2084
 * source. Called by the mailbox command IPC_CMD_SET_HDR_ENABLE.
 */
void hdr_set_enable(unsigned char on)
{
    if (on)
        hdr_enable = 1;
    else
        hdr_enable = 0;
}
