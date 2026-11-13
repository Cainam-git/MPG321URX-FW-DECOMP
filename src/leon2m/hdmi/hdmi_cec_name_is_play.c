/* hdmi_cec_name_is_play  (FUN_a0083c34)
 *
 * Return 1 when the stored CEC source name starts with "Play".
 * Returns: 0 or 1
 * Note: Name bytes 1..4 at 0xA8024018; nothing calls it.
 * Name basis: derived - code compares 'Play'; same buffer as APPCECGetSourceType
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083c34 @ 0xa0083c34, flags -mcpu=v8 -O3 -g.
 * Source form: four separate byte compares joined by &&, with two returns.
 */
/* The CEC name block holds five bytes; byte 0 is not compared, bytes 1 to 4 are the four letters. */
extern unsigned char hdmi_cec_source_name[];

/*
 * Tell whether the stored CEC source name starts with the letters "Play".
 * Returns 1 for a match, 0 otherwise. Nothing calls this routine; APPCECGetSourceType holds the same test
 * inline.
 */
int hdmi_cec_name_is_play(void)
{
    if (hdmi_cec_source_name[1] == 'P' && hdmi_cec_source_name[2] == 'l' && hdmi_cec_source_name[3] == 'a' && hdmi_cec_source_name[4] == 'y')
        return 1;
    return 0;
}
