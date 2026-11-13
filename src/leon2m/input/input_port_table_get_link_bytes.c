/* input_port_table_get_link_bytes  (FUN_a0124b88)
 *
 * Copy bytes +0x12..+0x15 of an input's port table entry to a buffer.
 * Note: input_init_port_link_row takes link row bytes 8, 0x0A and 0x0B from them.
 * Name basis: descriptive - bytes +0x12..+0x15 of the 22-byte ROM entries at 0x1A42A8; their only shown use is
 *   the port link row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124b88 @ 0xa0124b88-0xa0124bf4 (27 words), flags -mcpu=v8 -O3 -g.
 * Source form: the four-byte copy is written in both arms of the test; the firmware holds both copies of the four
 * loads (0xa0124bac..0xa0124bbc for the else arm, 0xa0124bd0..0xa0124bdc for the then arm) and one copy of the four
 * stores (0xa0124be0..0xa0124bf0). Every access is port_table[index].field.
 */
/* One entry of the port table in ROM (0x16 bytes); see docs/DATA.md. */
struct port_table_entry {
    unsigned char code;                 /* +0x00 */
    unsigned char type;                 /* +0x01 */
    unsigned char unused_02[9];         /* +0x02..+0x0A, not read here */
    unsigned char detect_port, detect_mask, detect_level;   /* +0x0B..+0x0D */
    unsigned char unused_0e[4];         /* +0x0E..+0x11, not read here */
    union {
        unsigned char order[4];         /* +0x12..+0x15 */
        struct { unsigned char byte_0, byte_1; unsigned short flags; } w;   /* flags = halfword +0x14 */
    } u;
};
extern const struct port_table_entry port_table[];

#define PORT_TYPE_2        2
#define PORT_FLAG_0x400    0x400        /* bit 10 of halfword +0x14 */

/*
 * Copy the four bytes +0x12..+0x15 of a port table entry to out[0..3]. input_init_port_link_row reads the
 * values of link row bytes 8, 0x0A and 0x0B from them.
 *
 *   index  entry of the port table
 *   out    receives the four bytes
 *
 * The test on type 2 and flag 0x400 has the same copy in both arms, so it does not change the result.
 */
void input_port_table_get_link_bytes(unsigned char index, unsigned char *out)
{
    if (port_table[index].type == PORT_TYPE_2 && (port_table[index].u.w.flags & PORT_FLAG_0x400)) {
        out[0] = port_table[index].u.order[0];
        out[1] = port_table[index].u.order[1];
        out[2] = port_table[index].u.order[2];
        out[3] = port_table[index].u.order[3];
    } else {
        out[0] = port_table[index].u.order[0];
        out[1] = port_table[index].u.order[1];
        out[2] = port_table[index].u.order[2];
        out[3] = port_table[index].u.order[3];
    }
}
