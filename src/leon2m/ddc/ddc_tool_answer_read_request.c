/* ddc_tool_answer_read_request  (FUN_a00d3650)
 *
 * Answer a factory tool table read: 16 bytes of a stored EDID record, or an error result.
 * Note: Request byte 3 = 0x29 / 0x33 / 0x37 / 0x3B with ddc_tool_read_address_low = 1 / 2 / 0x11 / 0x21;
 *   ddc_tool_read_address_high picks the record, request byte 5 the block; other requests get the header only.
 * Name basis: derived - edid_copy_stored_block into reply bytes 7..22; reply finished by ddc_tool_build_reply
 *   and queued with ddc_api_queue_reply
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d3650 @ 0xa00d3650-0xa00d3a30 (992 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the header fill is a static copy of ddc_tool_build_reply_header, inlined (fw: its reply pointer is %l0, set
 *    at 0xa00d36ac, and request[3] is read again for the switch at 0xa00d3748);
 *  - in it the two byte 1 tests are each one '||' condition on request[3] read through the pointer: only the
 *    first two compares of each condition are one xor/subx/orcc pair (0xa00d3684 .. 0xa00d36a0, 0xa00d36e8 ..
 *    0xa00d3700), the others are single compares, and each condition has one byte 1 store block (0xa00d373c,
 *    0xa00d3994) storing through %l0 at 0xa00d3740;
 *  - every case of the four inner switches stores result itself (jump tables 0xa00cf144, 0xa00cf110,
 *    0xa00cf0f4, 0xa00cf178).
 */
extern unsigned char ddc_tool_read_address_low;
extern unsigned char ddc_tool_read_address_high;
extern void timer_sleep_ticks(int ticks);
extern void edid_copy_stored_block(unsigned short record, unsigned char *dst, unsigned char block);
extern void ddc_tool_build_reply(const unsigned char *request, unsigned char *reply, unsigned char cmd);
extern void ddc_set_checksum_byte(unsigned char value);
extern void ddc_api_queue_reply(unsigned char port, unsigned short length, unsigned char *reply);

#define DDC_ADDRESS               0x6e          /* byte 0 of every reply (docs/MAP.md) */
#define DDC_LENGTH_BYTE(n)        ((n) + 0x80)  /* reply byte 1: 0x80 + the number of bytes that follow it */
#define DDC_CMD_TOOL_COMMAND      0xc0          /* DDC/CI command of ddc_tool_dispatch_command */
#define DDC_CMD_TOOL_READ         0xd0          /* DDC/CI command of this routine */
#define DDC_CHECKSUM_SEED         0x50          /* first value of the reply XOR checksum */

/* Third argument of ddc_tool_build_reply_header: which header to write. */
#define HEADER_TOOL_COMMAND       0             /* as ddc_tool_dispatch_command writes it */
#define HEADER_TOOL_READ          1
#define READ_DATA_MARKER          0x40          /* request byte 6 value that gives length byte DDC_LENGTH_BYTE(0x45) */

/* Request byte 3 of a table read, and the value ddc_tool_read_address_low (request byte 6 of the earlier tool
   command 0x55) must have for it. Each pair has its own table of stored EDID records. The record numbers of
   the 0x37 and 0x3B tables are the ones UserSwitchEDID loads into inputs 0xC and 0xD; those of the 0x29 and
   0x33 tables include the ones it loads into inputs 5 and 6, and records 0x1C..0x23, which it does not load. */
#define READ_TABLE_INPUT_5        0x29
#define READ_TABLE_INPUT_6        0x33
#define READ_TABLE_INPUT_C        0x37
#define READ_TABLE_INPUT_D        0x3b
#define READ_ADDRESS_INPUT_5      1
#define READ_ADDRESS_INPUT_6      2
#define READ_ADDRESS_INPUT_C      0x11
#define READ_ADDRESS_INPUT_D      0x21

#define READ_WAIT_TICKS           10            /* timer_sleep_ticks waits this + 1 ticks */
#define TOOL_ANSWER_TABLE_READ    0x99          /* ddc_tool_build_reply: store the checksum behind the data */
#define TOOL_RESULT_UNKNOWN       0xe3          /* no table for this address */
#define RESULT_KEEP_MASK          0xfb          /* clears bit 2, which neither result above has */
#define REPLY_BUFFER_SIZE         40
#define REPLY_DATA                7             /* reply byte of the first of the 16 record bytes */
#define REPLY_LENGTH              0x19          /* bytes queued */

/* Copy of ddc_tool_build_reply_header (inlined): reply bytes 0..6. HEADER_TOOL_READ chooses length byte 1 from
   request byte 3 (two fixed lists; any other value, which includes the table reads, gives DDC_LENGTH_BYTE(0x15),
   or DDC_LENGTH_BYTE(0x45) when request byte 6 is READ_DATA_MARKER). Bytes 3..6 are request bytes 3..6. */
static void ddc_tool_build_reply_header(const unsigned char *request, unsigned char *reply, unsigned char header)
{
    reply[0] = DDC_ADDRESS;
    if (header == HEADER_TOOL_COMMAND) {
        reply[1] = DDC_LENGTH_BYTE(6);
        reply[2] = DDC_CMD_TOOL_COMMAND;
    } else if (header == HEADER_TOOL_READ) {
        if (request[3] == 0x63 ||
            request[3] == 0x31 ||
            request[3] == 0x32 ||
            request[3] == 0x27 ||
            request[3] == 0x28 ||
            request[3] == 0x35 ||
            request[3] == 0x36 ||
            request[3] == 0x39 ||
            request[3] == 0x3a)
            reply[1] = DDC_LENGTH_BYTE(6);
        else if (request[3] == 0x34 ||
                 request[3] == 0x30 ||
                 request[3] == 0x38 ||
                 request[3] == 0x3c)
            reply[1] = DDC_LENGTH_BYTE(0x13);
        else if (request[6] == READ_DATA_MARKER)
            reply[1] = DDC_LENGTH_BYTE(0x45);
        else
            reply[1] = DDC_LENGTH_BYTE(0x15);
        reply[2] = DDC_CMD_TOOL_READ;
    }
    reply[3] = request[3];
    reply[4] = request[4];
    reply[5] = request[5];
    reply[6] = request[6];
}

/*
 * Answer one factory tool read request: 16 bytes of a stored EDID record.
 *
 *   port     the port ddc_api_take_request gave with the request; passed on to ddc_api_queue_reply
 *   request  the request; byte 3 = which table (READ_TABLE_*), byte 5 = the 16-byte block of the record
 *
 * Called by ddc_handle_request for DDC/CI command DDC_CMD_TOOL_READ (0xD0); ddc_handle_request leaves the
 * on-screen menu open afterwards. The record is chosen by the two bytes the tool sent earlier with tool command
 * 0x55 (ddc_tool_set_read_address): the low byte must match the table, the high byte picks the record.
 *
 * Phases:
 *   1. Clear the 40-byte reply and write its header (HEADER_TOOL_READ).
 *   2. For a table read: wait READ_WAIT_TICKS + 1 ticks, then copy block request[5] of the record into reply
 *      bytes 7..22. A low address byte that does not match the table, or a high byte without a record, gives
 *      TOOL_RESULT_UNKNOWN. Any other request byte 3 leaves the reply as the header made it.
 *   3. ddc_tool_build_reply stores the checksum (TOOL_ANSWER_TABLE_READ) or the result in byte 7; the shared
 *      DDC/CI checksum byte is set back to its seed 0x50 and REPLY_LENGTH bytes are queued.
 */
void ddc_tool_answer_read_request(unsigned char port, unsigned char *request)
{
    unsigned char reply[REPLY_BUFFER_SIZE];
    unsigned char result = TOOL_ANSWER_TABLE_READ;
    unsigned char i;

    /* Phase 1: the reply header. */
    for (i = 0; i < REPLY_BUFFER_SIZE; i++)
        reply[i] = 0;
    ddc_tool_build_reply_header(request, reply, HEADER_TOOL_READ);

    /* Phase 2: the table read; the high address byte gives the record number. */
    switch (request[3]) {
    case READ_TABLE_INPUT_5:
    case READ_TABLE_INPUT_6:
    case READ_TABLE_INPUT_C:
    case READ_TABLE_INPUT_D:
        timer_sleep_ticks(READ_WAIT_TICKS);
        if (ddc_tool_read_address_low == READ_ADDRESS_INPUT_5 && request[3] == READ_TABLE_INPUT_5) {
            switch (ddc_tool_read_address_high) {
            case 1: edid_copy_stored_block(0, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 2: edid_copy_stored_block(0x14, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 3: edid_copy_stored_block(0x10, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 4: edid_copy_stored_block(0x16, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 5: edid_copy_stored_block(0x1c, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 6: edid_copy_stored_block(0x20, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 7: edid_copy_stored_block(0x1e, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 8: edid_copy_stored_block(0x22, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 9: edid_copy_stored_block(4, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 10: edid_copy_stored_block(8, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 11: edid_copy_stored_block(0xc, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 12: edid_copy_stored_block(0x18, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            default: result = TOOL_RESULT_UNKNOWN; break;
            }
        } else if (ddc_tool_read_address_low == READ_ADDRESS_INPUT_6 && request[3] == READ_TABLE_INPUT_6) {
            /* The records one above those of the input 5 table. */
            switch (ddc_tool_read_address_high) {
            case 1: edid_copy_stored_block(1, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 2: edid_copy_stored_block(0x15, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 3: edid_copy_stored_block(0x11, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 4: edid_copy_stored_block(0x17, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 5: edid_copy_stored_block(0x1d, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 6: edid_copy_stored_block(0x21, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 7: edid_copy_stored_block(0x1f, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 8: edid_copy_stored_block(0x23, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 9: edid_copy_stored_block(5, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 10: edid_copy_stored_block(9, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 11: edid_copy_stored_block(0xd, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 12: edid_copy_stored_block(0x19, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            default: result = TOOL_RESULT_UNKNOWN; break;
            }
        } else if (ddc_tool_read_address_low == READ_ADDRESS_INPUT_C && request[3] == READ_TABLE_INPUT_C) {
            switch (ddc_tool_read_address_high) {
            case 1: edid_copy_stored_block(2, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 2: edid_copy_stored_block(0x12, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 3: edid_copy_stored_block(6, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 4: edid_copy_stored_block(0xa, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 5: edid_copy_stored_block(0xe, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 6: edid_copy_stored_block(0x1a, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            default: result = TOOL_RESULT_UNKNOWN; break;
            }
        } else if (ddc_tool_read_address_low == READ_ADDRESS_INPUT_D && request[3] == READ_TABLE_INPUT_D) {
            /* The records one above those of the input 0xC table. */
            switch (ddc_tool_read_address_high) {
            case 1: edid_copy_stored_block(3, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 2: edid_copy_stored_block(0x13, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 3: edid_copy_stored_block(7, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 4: edid_copy_stored_block(0xb, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 5: edid_copy_stored_block(0xf, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            case 6: edid_copy_stored_block(0x1b, &reply[REPLY_DATA], request[5]); result = TOOL_ANSWER_TABLE_READ; break;
            default: result = TOOL_RESULT_UNKNOWN; break;
            }
        } else
            result = TOOL_RESULT_UNKNOWN;
        break;
    }

    /* Phase 3: finish and queue the reply. */
    ddc_tool_build_reply(request, reply, result & RESULT_KEEP_MASK);
    ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
    ddc_api_queue_reply(port, REPLY_LENGTH, reply);
}
