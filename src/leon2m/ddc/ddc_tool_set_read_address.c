/* ddc_tool_set_read_address  (FUN_a00d2974)
 *
 * Tool command: store the two address bytes for the next table read.
 * Returns: 0xE0
 * Name basis: descriptive - bytes at 0xA802B09E / 0xA802B09F; unused
 *
 * Matching notes
 * --------------
 * FUN_a00d2974 (leon2m 0xa00d2974-0xa00d2994, 32 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * Source form: two separate extern byte symbols (each store has its own sethi).
 */
extern unsigned char ddc_tool_read_address_low;
extern unsigned char ddc_tool_read_address_high;

#define TOOL_RESULT_DONE 0xe0                   /* the command was carried out */

/*
 * Factory tool command 0x55 (TOOL_CMD_READ_ADDRESS): remember request byte 6 as the low and byte 7 as the high
 * address byte. ddc_tool_answer_read_request reads them for the next table read: the low byte must match the
 * table asked for and the high byte picks the stored record.
 *
 *   p  the request
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
unsigned char ddc_tool_set_read_address(unsigned char *p)
{
    ddc_tool_read_address_low = p[6];
    ddc_tool_read_address_high = p[7];
    return TOOL_RESULT_DONE;
}
