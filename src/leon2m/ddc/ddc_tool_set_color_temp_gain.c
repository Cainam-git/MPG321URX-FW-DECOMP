/* ddc_tool_set_color_temp_gain  (FUN_a00d1f58)
 *
 * Set one colour gain of the current colour temperature from the factory tool.
 *   request
 * Returns: 0xE0, or 0xE3
 * Note: Byte 6 picks red, green or blue, byte 7 is the gain: stored in the part record row of the current
 *   colour temperature (nothing stored for Custom), applied, and the part record is saved.
 * Name basis: proven - pq_color_matrix_set_red_gain / _green_gain / _blue_gain; caller
 *   ddc_tool_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1f58 @ 0xa00d1f58-0xa00d20a4, flags -mcpu=v8 -O3 -g.
 * Source form: switch cases in the order GAIN_RED, GAIN_GREEN, GAIN_BLUE, each ending with its own
 * 'nvram_api_store_by_selector(STORE_PART_RECORD); return TOOL_RESULT_DONE;'.
 */

/* The three colour bytes of one colour temperature in the part record (docs/RECORDS.md). */
struct color_gains { unsigned char red, green, blue; };
struct part_record_layout {
    unsigned char pad00[6];
    struct color_gains warm50;                  /* +0x06: the row of Color Temperature Warm */
    struct color_gains normal65;                /* +0x09: the row of Color Temperature Normal */
    unsigned char pad0c[0x12 - 0xc];
    struct color_gains cool93;                  /* +0x12: the row of Color Temperature Cool */
};
extern struct part_record_layout part_record;
extern unsigned char user_settings_color_temperature;
extern void pq_color_matrix_set_red_gain(unsigned short);
extern void pq_color_matrix_set_green_gain(unsigned short);
extern void pq_color_matrix_set_blue_gain(unsigned short);
extern void nvram_api_store_by_selector(unsigned char);

#define TOOL_RESULT_DONE     0xe0               /* the command was carried out */
#define TOOL_RESULT_UNKNOWN  0xe3               /* a value the routine does not know */
#define STORE_PART_RECORD    0                  /* nvram_api_store_by_selector: save the part record */

/* Colour temperature values (settings +0x11). */
#define COLOR_TEMP_COOL      0
#define COLOR_TEMP_NORMAL    1
#define COLOR_TEMP_WARM      2

/* Request byte 6: the colour the gain is for. */
#define GAIN_RED             0
#define GAIN_GREEN           1
#define GAIN_BLUE            2

/*
 * Factory tool command 0x11 (TOOL_CMD_COLOR_GAIN): set one colour gain of the current colour temperature.
 *
 *   request  the tool request; byte 6 = the colour (GAIN_RED, GAIN_GREEN, GAIN_BLUE), byte 7 = the gain
 *
 * Three steps, the same for each colour:
 *   1. The gain is stored in the part record row of the Color Temperature setting: Warm -> warm50,
 *      Normal -> normal65, Cool -> cool93. With any other setting (Custom = 3) nothing is stored here, but the
 *      next two steps still run.
 *   2. The gain goes to the colour matrix (pq_color_matrix_set_red_gain / _green_gain / _blue_gain).
 *   3. The part record is saved (nvram_api_store_by_selector(STORE_PART_RECORD)).
 *
 * Returns TOOL_RESULT_DONE, or TOOL_RESULT_UNKNOWN for a colour other than 0..2 (nothing is changed then).
 * Called by ddc_tool_dispatch_command.
 */
int ddc_tool_set_color_temp_gain(unsigned char *request)
{
    switch (request[6]) {
    case GAIN_RED:
        if (user_settings_color_temperature == COLOR_TEMP_WARM)
            part_record.warm50.red = request[7];
        else if (user_settings_color_temperature == COLOR_TEMP_NORMAL)
            part_record.normal65.red = request[7];
        else if (user_settings_color_temperature == COLOR_TEMP_COOL)
            part_record.cool93.red = request[7];
        pq_color_matrix_set_red_gain(request[7]);
        nvram_api_store_by_selector(STORE_PART_RECORD);
        return TOOL_RESULT_DONE;
    case GAIN_GREEN:
        if (user_settings_color_temperature == COLOR_TEMP_WARM)
            part_record.warm50.green = request[7];
        else if (user_settings_color_temperature == COLOR_TEMP_NORMAL)
            part_record.normal65.green = request[7];
        else if (user_settings_color_temperature == COLOR_TEMP_COOL)
            part_record.cool93.green = request[7];
        pq_color_matrix_set_green_gain(request[7]);
        nvram_api_store_by_selector(STORE_PART_RECORD);
        return TOOL_RESULT_DONE;
    case GAIN_BLUE:
        if (user_settings_color_temperature == COLOR_TEMP_WARM)
            part_record.warm50.blue = request[7];
        else if (user_settings_color_temperature == COLOR_TEMP_NORMAL)
            part_record.normal65.blue = request[7];
        else if (user_settings_color_temperature == COLOR_TEMP_COOL)
            part_record.cool93.blue = request[7];
        pq_color_matrix_set_blue_gain(request[7]);
        nvram_api_store_by_selector(STORE_PART_RECORD);
        return TOOL_RESULT_DONE;
    default:
        return TOOL_RESULT_UNKNOWN;
    }
}
