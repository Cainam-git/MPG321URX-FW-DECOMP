/* hdmi_cec_match_console_name  (FUN_a0083c88)
 *
 * Return 0, 1 or 2 when the CEC source name is "Play", "Nint" or "XBOX", else 0xFF.
 * Returns: console index or 0xFF
 * Note: Nothing calls it directly.
 * Name basis: derived - code: name table Play / Nint / XBOX
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083c88 @ 0xa0083c88, flags -mcpu=v8 -O3 -g.
 * Source form: the three names are a local 3 x 4 byte array, the loop has no early exit (the last match wins),
 * and the index is kept in an unsigned char.
 */
extern unsigned char hdmi_cec_source_name[];

#define CONSOLE_NAME_COUNT 3                /* Play, Nint, XBOX */
#define CONSOLE_NO_MATCH   0xff

/*
 * Look the stored CEC source name (bytes 1 to 4 of hdmi_cec_source_name) up in a table of three four-letter
 * codes: "Play" is index 0, "Nint" 1, "XBOX" 2.
 * Returns the index of the code that matches (the last one, if several do), or 0xFF when none does.
 * Nothing calls this routine; APPCECGetSourceType contains the same search.
 */
unsigned char hdmi_cec_match_console_name(void)
{
    unsigned char codes[CONSOLE_NAME_COUNT][4] = { { 'P', 'l', 'a', 'y' }, { 'N', 'i', 'n', 't' }, { 'X', 'B', 'O', 'X' } };
    unsigned char i, result;

    result = CONSOLE_NO_MATCH;
    for (i = 0; i < CONSOLE_NAME_COUNT; i++)
        if (codes[i][0] == hdmi_cec_source_name[1] && codes[i][1] == hdmi_cec_source_name[2] && codes[i][2] == hdmi_cec_source_name[3]
            && codes[i][3] == hdmi_cec_source_name[4])
            result = i;
    return result;
}
