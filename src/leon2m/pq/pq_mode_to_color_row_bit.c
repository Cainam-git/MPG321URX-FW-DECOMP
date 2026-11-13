/* pq_mode_to_color_row_bit  (FUN_a012e8c0)
 *
 * Convert a picture mode 0x10..0x16 to a single-bit byte that selects a stored colour row; else 1.
 * Returns: single-bit byte
 * Name basis: descriptive - switch on the mode; pq_fga_load_color_matrix_row uses the result as a row bit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e8c0 @ 0xa012e8c0, flags -mcpu=v8 -O3 -g.
 * Source form: a switch (jump table at ROM 0xccea0) with case 0x12 written last, setting an unsigned char that
 * is returned as int; the final and 0xf7 is the zero extension reduced to the bits any result can have.
 */

/*
 * Map a picture mode to a single-bit byte:
 *   0x10 -> 0x02, 0x11 -> 0x04, 0x12 -> 0x01, 0x13 -> 0x10, 0x14 -> 0x20, 0x15 -> 0x40, 0x16 -> 0x80,
 *   any other mode -> 0x01.
 *
 * The only caller, pq_apply_picture_mode, calls it for picture modes 15..22 and stores the result in
 * sys_config matrix_row_bit; pq_fga_load_color_matrix_row reads that value as the row bit of the stored
 * colour rows (1 / 2 / 4 = rows 0 / 1 / 2).
 */
int pq_mode_to_color_row_bit(unsigned char picture_mode)
{
    unsigned char bit;

    switch (picture_mode) {
    case 0x10:
        bit = 0x2;
        break;
    case 0x11:
        bit = 0x4;
        break;
    case 0x13:
        bit = 0x10;
        break;
    case 0x14:
        bit = 0x20;
        break;
    case 0x15:
        bit = 0x40;
        break;
    case 0x16:
        bit = 0x80;
        break;
    case 0x12:
        bit = 0x1;
        break;
    default:
        bit = 1;
        break;
    }
    return bit;
}
