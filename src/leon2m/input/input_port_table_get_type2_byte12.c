/* input_port_table_get_type2_byte12  (FUN_a0125294)
 *
 * Return byte +0x12 of a type 2 input's entry, else a default.
 * Returns: byte
 * Name basis: descriptive - used when the port list is built
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125294 @ 0xa0125294, flags -mcpu=v8 -O3 -g.
 * Source form: the table is a byte array indexed with a computed offset (index * 0x16 + 1 and + 0x12).
 */
extern unsigned char port_table[];      /* entries of 0x16 bytes */
extern unsigned char port_table_type;       /* 0x001a42a9: the type byte of entry 0, not used here */
extern unsigned char port_table_byte_0x12;  /* 0x001a42ba: byte +0x12 of entry 0, not used here */

#define PORT_ENTRY_SIZE   0x16
#define PORT_TYPE         1             /* offset of the type byte in the entry */
#define PORT_BYTE_0x12    0x12
#define PORT_TYPE_2       2

/*
 * Return byte +0x12 of the port table entry when the entry is of type 2, else 0x0F. Same as
 * input_port_table_get_type1_byte12 for the other type.
 *
 *   param_1  entry of the port table (low byte used)
 */
unsigned char input_port_table_get_type2_byte12(unsigned int param_1)
{
    int result;
    unsigned char *base = (unsigned char *)port_table;
    unsigned int offset = (param_1 & 0xff) * PORT_ENTRY_SIZE;

    result = 0xf;
    if (base[offset + PORT_TYPE] == PORT_TYPE_2) {
        result = base[offset + PORT_BYTE_0x12];
    }
    return result;
}
