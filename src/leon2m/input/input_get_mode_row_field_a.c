/* input_get_mode_row_field_a  (FUN_a0140034)
 *
 * Return the 16-bit field at +0x0A of a mode-table row.
 * Returns: value
 * Name basis: descriptive - plain table read; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140034 @ 0xa0140034-0xa0140058, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Nothing in the image refers to it (no call, branch or address constant).
 */

/* A row of the mode table (0x24 bytes), up to the field used here. */
struct mode_row {
    unsigned char pad0[0xa];
    unsigned short half_0xa;
    unsigned char pad_c[0x24 - 0xc];
};
extern const struct mode_row input_mode_table[];

/*
 * Return the halfword at +0xA of a mode-table row.
 *
 *   row  the row index
 *
 * Nothing in the image calls this routine.
 */
unsigned short input_get_mode_row_field_a(unsigned char row)
{
    return input_mode_table[row].half_0xa;
}
