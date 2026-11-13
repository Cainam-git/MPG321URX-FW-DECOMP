/* input_find_mode_row_by_id  (FUN_a013ffb0)
 *
 * Return the index of the mode-table row with a given id.
 * Returns: row index
 * Name basis: derived - scan of the ROM table up to its end marker; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013ffb0 @ 0xa013ffb0-0xa0140034, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Nothing in the image refers to it (no call, branch or address constant).
 */

/* A row of the mode table (0x24 bytes), up to the fields used here. */
struct mode_row {
    unsigned char pad0[2];
    unsigned short end_marker;          /* +2: 0xFFFF in the row that ends the table */
    unsigned char pad4[0x22 - 4];
    unsigned short mode_id;             /* +0x22 */
};
extern const struct mode_row input_mode_table[];

#define MODE_TABLE_END 0xffff

/*
 * Return the index of the first mode-table row whose id (halfword +0x22) is mode_id. When no row has it, the
 * index of the row that ends the table is returned. Nothing in the image calls this routine.
 */
unsigned char input_find_mode_row_by_id(unsigned short mode_id)
{
    unsigned char i;

    for (i = 0; input_mode_table[i].end_marker != MODE_TABLE_END; i++)
        if (input_mode_table[i].mode_id == mode_id)
            break;
    return i;
}
