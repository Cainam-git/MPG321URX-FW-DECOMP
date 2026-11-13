/* ddc_tool_build_reply_header  (FUN_a00d0e48)
 *
 * Fill the header of a factory tool reply from its request.
 *   req: request
 *   p: reply
 *   mode: 0 or 1
 * Note: Uncalled copy (inlined in ddc_tool_answer_read_request).
 * Name basis: descriptive - bytes 6E, 86 / 93 / C5 / 95, C0 / D0 + request bytes 3..6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d0e48 (0xa00d0e48-0xa00d0f68, 288 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: each length byte group is one || condition on req[3] (the same form as its inlined copy in
 * ddc_tool_answer_read_request).
 */

#define DDC_ADDRESS               0x6e          /* byte 0 of every reply (docs/MAP.md) */
#define DDC_LENGTH_BYTE(n)        ((n) + 0x80)  /* reply byte 1: 0x80 + the number of bytes that follow it */
#define DDC_CMD_TOOL_COMMAND      0xc0          /* DDC/CI command of a tool command reply */
#define DDC_CMD_TOOL_READ         0xd0          /* DDC/CI command of a tool read reply */
#define HEADER_TOOL_COMMAND       0             /* values of the mode argument */
#define HEADER_TOOL_READ          1
#define READ_DATA_MARKER          0x40          /* request byte 6 value that gives length byte DDC_LENGTH_BYTE(0x45) */

/*
 * Write reply bytes 0..6: the address, the length byte, the DDC/CI command, and a copy of request bytes 3..6.
 *
 *   req   the tool request
 *   p     the reply
 *   mode  HEADER_TOOL_COMMAND: length DDC_LENGTH_BYTE(6), command DDC_CMD_TOOL_COMMAND.
 *         HEADER_TOOL_READ: command DDC_CMD_TOOL_READ; the length byte comes from request byte 3: DDC_LENGTH_BYTE(6)
 *         for 0x63, 0x31, 0x32, 0x27, 0x28, 0x35, 0x36, 0x39 and 0x3A; DDC_LENGTH_BYTE(0x13) for 0x34, 0x30,
 *         0x38 and 0x3C; any other value gives DDC_LENGTH_BYTE(0x45) when request byte 6 is READ_DATA_MARKER,
 *         else DDC_LENGTH_BYTE(0x15).
 *   Any other mode value leaves bytes 1 and 2 unwritten.
 *
 * Nothing calls this copy; ddc_tool_answer_read_request carries an inlined copy of it.
 */
void ddc_tool_build_reply_header(const unsigned char *req, unsigned char *p, unsigned char mode)
{
    p[0] = DDC_ADDRESS;
    if (mode == HEADER_TOOL_COMMAND) {
        p[1] = DDC_LENGTH_BYTE(6);
        p[2] = DDC_CMD_TOOL_COMMAND;
    } else if (mode == HEADER_TOOL_READ) {
        if (req[3] == 0x63 ||
            req[3] == 0x31 ||
            req[3] == 0x32 ||
            req[3] == 0x27 ||
            req[3] == 0x28 ||
            req[3] == 0x35 ||
            req[3] == 0x36 ||
            req[3] == 0x39 ||
            req[3] == 0x3a)
            p[1] = DDC_LENGTH_BYTE(6);
        else if (req[3] == 0x34 ||
                 req[3] == 0x30 ||
                 req[3] == 0x38 ||
                 req[3] == 0x3c)
            p[1] = DDC_LENGTH_BYTE(0x13);
        else if (req[6] == READ_DATA_MARKER)
            p[1] = DDC_LENGTH_BYTE(0x45);
        else
            p[1] = DDC_LENGTH_BYTE(0x15);
        p[2] = DDC_CMD_TOOL_READ;
    }
    p[3] = req[3];
    p[4] = req[4];
    p[5] = req[5];
    p[6] = req[6];
}
