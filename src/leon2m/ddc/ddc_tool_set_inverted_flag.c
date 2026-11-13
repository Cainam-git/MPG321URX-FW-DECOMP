/* ddc_tool_set_inverted_flag  (FUN_a00d1e08)
 *
 * Store the inverse of a factory tool on/off value in a flag byte.
 *   p: request
 * Returns: 0xE0
 * Note: Uncalled; byte 0xA802B09D (1 -> 0, 0 -> 1); no reader of the byte was found.
 * Name basis: descriptive - body only
 *
 * Matching notes
 * --------------
 * FUN_a00d1e08 (leon2m 0xa00d1e08-0xa00d1e3c, 52 bytes, leaf), flags -mcpu=v8 -O3.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 */
extern unsigned char ddc_tool_inverted_flag;

#define TOOL_RESULT_DONE 0xe0                   /* the command was carried out */

/*
 * Factory tool command 0x0B (TOOL_CMD_INVERTED_FLAG): request byte 7 = 1 clears ddc_tool_inverted_flag, 0 sets
 * it, any other value leaves it.
 *
 *   p  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
unsigned char ddc_tool_set_inverted_flag(unsigned char *p)
{
    if (p[7] == 1)
        ddc_tool_inverted_flag = 0;
    else if (p[7] == 0)
        ddc_tool_inverted_flag = 1;
    return TOOL_RESULT_DONE;
}
