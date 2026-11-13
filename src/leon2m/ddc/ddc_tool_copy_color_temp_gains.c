/* ddc_tool_copy_color_temp_gains  (FUN_a00d23b8)
 *
 * Copy one three-byte colour row of the part record to another and save the part record.
 *   request
 * Returns: 0xE0, or 0xE3
 * Note: Byte 6 = source row, byte 7 = target row (1 Warm, 2 Cool, 3 Normal, 5 the row at +0x21); other numbers
 *   return 0xE3. Nothing calls this copy; ddc_tool_dispatch_command has the code inline.
 * Name basis: derived - 3-byte rows of the part record at offsets 6 / 0x12 / 9 / 0x21; factory tool command
 *   0x6D
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d23b8 @ 0xa00d23b8-0xa00d24d8 (72 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three bytes are copied through three byte locals (a structure copy goes through the stack);
 * the case order of the two switches (1, 3, 2, 5) decides the base registers.
 */

/* The three colour bytes of one colour temperature in the part record (docs/RECORDS.md). */
struct color_gains { unsigned char red, green, blue; };
struct part_record_layout {
    unsigned char pad00[6];
    struct color_gains warm50;                  /* +0x06: the row of Color Temperature Warm */
    struct color_gains normal65;                /* +0x09: the row of Color Temperature Normal */
    unsigned char pad0c[0x12 - 0xc];
    struct color_gains cool93;                  /* +0x12: the row of Color Temperature Cool */
    unsigned char pad15[0x21 - 0x15];
    struct color_gains row_0x21;                /* +0x21: copied like the three above; what it holds is not shown */
};
extern struct part_record_layout part_record;
extern void nvram_api_store_by_selector(unsigned char);

#define TOOL_RESULT_DONE     0xe0               /* the command was carried out */
#define TOOL_RESULT_UNKNOWN  0xe3               /* a value the routine does not know */
#define STORE_PART_RECORD    0                  /* nvram_api_store_by_selector: save the part record */

/* Row numbers of request bytes 6 and 7. 1..3 are the tool's colour temperature numbers (as
   ddc_tool_set_color_temperature: 1 Warm, 2 Cool, 3 Normal). */
#define TOOL_ROW_WARM50      1
#define TOOL_ROW_COOL93      2
#define TOOL_ROW_NORMAL65    3
#define TOOL_ROW_0x21        5

/*
 * Factory tool command 0x6D (TOOL_CMD_COPY_GAINS): copy the three colour bytes of one part record row to
 * another and save the part record.
 *
 *   request  the tool request; byte 6 = the row to copy from, byte 7 = the row to copy to (TOOL_ROW_*)
 *
 * The source row is read first; an unknown source returns at once. An unknown destination also returns, after
 * the source was read, so nothing is written either way. The routine does not apply the copied values to the
 * picture.
 *
 * Returns TOOL_RESULT_DONE, or TOOL_RESULT_UNKNOWN for a row number other than 1, 2, 3 and 5.
 * ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls this one.
 */
int ddc_tool_copy_color_temp_gains(unsigned char *request)
{
    unsigned char red, green, blue;

    switch (request[6]) {
    case TOOL_ROW_WARM50:
        red = part_record.warm50.red;
        green = part_record.warm50.green;
        blue = part_record.warm50.blue;
        break;
    case TOOL_ROW_NORMAL65:
        red = part_record.normal65.red;
        green = part_record.normal65.green;
        blue = part_record.normal65.blue;
        break;
    case TOOL_ROW_COOL93:
        red = part_record.cool93.red;
        green = part_record.cool93.green;
        blue = part_record.cool93.blue;
        break;
    case TOOL_ROW_0x21:
        red = part_record.row_0x21.red;
        green = part_record.row_0x21.green;
        blue = part_record.row_0x21.blue;
        break;
    default:
        return TOOL_RESULT_UNKNOWN;
    }
    switch (request[7]) {
    case TOOL_ROW_WARM50:
        part_record.warm50.red = red;
        part_record.warm50.green = green;
        part_record.warm50.blue = blue;
        break;
    case TOOL_ROW_NORMAL65:
        part_record.normal65.red = red;
        part_record.normal65.green = green;
        part_record.normal65.blue = blue;
        break;
    case TOOL_ROW_COOL93:
        part_record.cool93.red = red;
        part_record.cool93.green = green;
        part_record.cool93.blue = blue;
        break;
    case TOOL_ROW_0x21:
        part_record.row_0x21.red = red;
        part_record.row_0x21.green = green;
        part_record.row_0x21.blue = blue;
        break;
    default:
        return TOOL_RESULT_UNKNOWN;
    }
    nvram_api_store_by_selector(STORE_PART_RECORD);
    return TOOL_RESULT_DONE;
}
