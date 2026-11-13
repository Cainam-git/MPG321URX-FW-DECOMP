/* input_port_table_get_code  (FUN_a0125140)
 *
 * Return the port code of an input index.
 * Returns: port code or 0xFF
 * Name basis: derived - byte 0 of the port table entry; 0x12..0x14 for the three virtual ports
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125140 @ 0xa0125140-0xa0125198 (22 words), flags -mcpu=v8 -O3 -g. Leaf.
 * Source form: the table is the struct array port_table; the values for 0xfc..0xfe are a switch (case tree root
 * 0xfd, signed branch); the index >= 8 arm comes first in the source, so the table read is the out-of-line block
 * like in the firmware.
 */
/* Byte +0 of an entry of the port table in ROM (0x16 bytes each); see docs/DATA.md. */
struct port_table_entry {
    unsigned char code;
    unsigned char type;
    unsigned char unused_02[0x10];
    unsigned char byte_0x12;
    unsigned char unused_13[3];
};
extern const struct port_table_entry port_table[];

#define PORT_NONE 0xff

/*
 * Return the port code of an input: byte +0 of its port table entry. The three virtual indexes 0xFC, 0xFD and
 * 0xFE give the codes 0x12, 0x13 and 0x14; any other index above 7 gives 0xFF.
 *
 *   index  entry of the port table
 */
unsigned char input_port_table_get_code(unsigned char index)
{
    unsigned char code = PORT_NONE;

    if (index >= 8) {
        switch (index) {
        case 0xfc: code = 0x12; break;
        case 0xfd: code = 0x13; break;
        case 0xfe: code = 0x14; break;
        }
    } else
        code = port_table[index].code;
    return code;
}
