/* pq_api_get_mode_color_value  (FUN_a0145920)
 *
 * Return one colour value of the picture modes.
 * Returns: value, 0xFF for an unknown id
 * Name basis: derived - byte of the 3-byte colour entries; counterpart of pq_api_set_mode_color_value
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145920 @ 0xa0145920-0xa0145af8 (118 words; the asm header's '44 bytes' label is wrong, its range is
 * right), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: one case per id in ascending order; the result is an int set to -1 at
 * the start and narrowed to the unsigned char return value (0xff for an unknown id).
 */
extern unsigned char part_record[0x24];

/*
 * Return colour value number id of the part record (the counterpart of pq_api_set_mode_color_value).
 *
 *   id  0..35: ids 0..23 are part record bytes 0..0x17; ids 24..26 bytes 0x21..0x23; ids 27..35 bytes 0x18..0x20
 *
 * From byte 6 on the bytes form red / green / blue triples, one per picture mode (see pq_api_set_mode_color_value):
 * ids 6..8 are the Warm 50 triple, 9..11 Normal 65, 18..20 Cool 93. Returns 0xff for any other id.
 *
 * Called by pq_user_apply_color_temperature (the triple of the chosen Color Temperature), by
 * pq_user_apply_mode_colors (ids 0..5) and by uart_cmd_get_color_values (ids 6..14 and 18..20 for the PC tool).
 */
unsigned char pq_api_get_mode_color_value(unsigned int id)
{
    int value = -1;

    switch (id) {
    case 0:
        value = part_record[0x00];
        break;
    case 1:
        value = part_record[0x01];
        break;
    case 2:
        value = part_record[0x02];
        break;
    case 3:
        value = part_record[0x03];
        break;
    case 4:
        value = part_record[0x04];
        break;
    case 5:
        value = part_record[0x05];
        break;
    case 6:     /* Warm 50: red, green, blue */
        value = part_record[0x06];
        break;
    case 7:
        value = part_record[0x07];
        break;
    case 8:
        value = part_record[0x08];
        break;
    case 9:     /* Normal 65 */
        value = part_record[0x09];
        break;
    case 10:
        value = part_record[0x0a];
        break;
    case 11:
        value = part_record[0x0b];
        break;
    case 12:
        value = part_record[0x0c];
        break;
    case 13:
        value = part_record[0x0d];
        break;
    case 14:
        value = part_record[0x0e];
        break;
    case 15:
        value = part_record[0x0f];
        break;
    case 16:
        value = part_record[0x10];
        break;
    case 17:
        value = part_record[0x11];
        break;
    case 18:    /* Cool 93 */
        value = part_record[0x12];
        break;
    case 19:
        value = part_record[0x13];
        break;
    case 20:
        value = part_record[0x14];
        break;
    case 21:
        value = part_record[0x15];
        break;
    case 22:
        value = part_record[0x16];
        break;
    case 23:
        value = part_record[0x17];
        break;
    case 24:    /* the triple of picture mode 15, stored after the others */
        value = part_record[0x21];
        break;
    case 25:
        value = part_record[0x22];
        break;
    case 26:
        value = part_record[0x23];
        break;
    case 27:    /* picture modes 9, 10, 11 */
        value = part_record[0x18];
        break;
    case 28:
        value = part_record[0x19];
        break;
    case 29:
        value = part_record[0x1a];
        break;
    case 30:
        value = part_record[0x1b];
        break;
    case 31:
        value = part_record[0x1c];
        break;
    case 32:
        value = part_record[0x1d];
        break;
    case 33:
        value = part_record[0x1e];
        break;
    case 34:
        value = part_record[0x1f];
        break;
    case 35:
        value = part_record[0x20];
        break;
    }
    return value;
}
