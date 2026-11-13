/* input_port_table_find_flagged_type2  (FUN_a01250c4)
 *
 * Return the first type 2 input whose flag bit 0x400 is set in the port table.
 * Returns: index or 0xFF
 * Name basis: descriptive - scan of the eight ROM entries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01250c4 @ 0xa01250c4-0xa0125124 (24 words), flags -mcpu=v8 -O2 -g. Leaf.
 * Source form: the base is the struct array port_table (not the field addresses 0x1a42a9 / 0x1a42bc as constants);
 * a plain unsigned char for loop with break and 'if (i == 8) i = 0xff'.
 */
/* One entry of the port table in ROM (0x16 bytes); see docs/DATA.md. */
struct port_table_entry {
    unsigned char code, type;
    unsigned char unused_02[0x12];
    unsigned short flags;               /* halfword +0x14 */
};
extern const struct port_table_entry port_table[];

#define PORT_TYPE_2        2
#define PORT_FLAG_0x400    0x400        /* bit 10 of halfword +0x14 */

/*
 * Return the index of the first entry of the port table that is of type 2 and has flag bit 0x400 set, or
 * 0xFF when none has. input_init_port_link_row uses the result.
 */
unsigned char input_port_table_find_flagged_type2(void)
{
    unsigned char i;

    for (i = 0; i < 8; i++)
        if (port_table[i].type == PORT_TYPE_2 && (port_table[i].flags & PORT_FLAG_0x400))
            break;
    if (i == 8)
        i = 0xff;
    return i;
}
