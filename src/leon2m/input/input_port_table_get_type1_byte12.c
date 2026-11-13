/* input_port_table_get_type1_byte12  (FUN_a0125264)
 *
 * Return byte +0x12 of a type 1 input's entry, else 0x0F.
 * Returns: byte
 * Name basis: descriptive - used when the port list is built
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125264 @ 0xa0125264, flags -mcpu=v8 -O3 -g.
 */
/* Bytes +1 and +0x12 of an entry of the port table in ROM (0x16 bytes each); see docs/DATA.md. */
struct port_table_entry {
    unsigned char code, type;
    unsigned char unused_02[0x10];
    unsigned char byte_0x12;
    unsigned char unused_13[3];
};
extern const struct port_table_entry port_table[];

#define PORT_TYPE_1 1

/*
 * Return byte +0x12 of the port table entry when the entry is of type 1, else 0x0F.
 *
 *   index  entry of the port table
 */
unsigned char input_port_table_get_type1_byte12(unsigned char index)
{
    const struct port_table_entry *entry = &port_table[index];
    unsigned int value = 0xf;

    if (entry->type == PORT_TYPE_1)
        value = entry->byte_0x12;
    return value;
}
