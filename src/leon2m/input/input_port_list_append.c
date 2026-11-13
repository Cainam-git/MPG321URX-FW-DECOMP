/* input_port_list_append  (FUN_a0152a20)
 *
 * Append one 3-byte port record to the list unless it is already present.
 * Name basis: descriptive - port codes 0x51/0x61/0x71/0x81/0xff; duplicate check over ten entries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0152a20 @ 0xa0152a20-0xa0152e28 (258 words), flags -mcpu=v8 -O3 -g.
 * Source form: cases in ascending code order, each record case ends with its own '(*count)++;' before 'break;';
 * the compiler merges the copies into the single increment at 0xa0152c74 and places the shared second-byte tail
 * (0xa0152c64..0xa0152c70) directly after the 0x61 case code before register renaming; one increment after the
 * switch places it after the 0x81 case and compiles with other registers from 0xa0152a84 on.
 * The bit 5 update of the 0x51 / 0x61 cases is a mask on the whole header byte ('srl 0xd; and 0x20' with
 * 'and -33; or' at 0xa0152ce0..0xa0152cec, 0xa0152dc4..0xa0152dd4); the other header writes are bit-field
 * stores. list_has_header takes the value as int ('and %l0, 0xff, %o3' at 0xa0152a9c, 0xa0152b8c). The result of
 * nvram_get_device_option_bit25 is compared as unsigned char ('and %o0, 0xff' at 0xa0152a84, 0xa0152b74), as in
 * input_port_list_build.
 */

#define PORT_CODE_ENTRY0     0x51               /* port codes of the port entries 0..3 */
#define PORT_CODE_ENTRY1     0x61
#define PORT_CODE_ENTRY2     0x71
#define PORT_CODE_ENTRY3     0x81
#define PORT_CODE_ROUTED     0xb1               /* stands for the pair that input_get_routed_port_pair returns */
#define PORT_LIST_END        0xff               /* code of the record that ends the list */
#define LIST_SEARCH_LIMIT    10                 /* records looked at when searching for a header byte */
#define RECORD_TYPE_END      0x1f               /* type of the end record; also stops the search */
#define RECORD_TYPE_ENTRY0   5                  /* record types per port entry; entries 2 and 3 have two, */
#define RECORD_TYPE_ENTRY1   6                  /* chosen by device option bit 25 (see below) */
#define RECORD_TYPE_ENTRY2_OPTION   9           /* entry 2 when option bit 25 is 1 */
#define RECORD_TYPE_ENTRY2_NO_OPTION 7          /* entry 2 otherwise */
#define RECORD_TYPE_ENTRY3_OPTION   8           /* entry 3 when option bit 25 is 1 */
#define RECORD_TYPE_ENTRY3_NO_OPTION 10         /* entry 3 otherwise */
#define NO_PORT              0xff               /* input_port_table_get_code result for an unused entry */

/* The first word of the system configuration record; only bit 18 is used here. */
struct sys_config_bits { unsigned int bits_31_19 : 13, bit_18 : 1, bits_17_0 : 18; };
/*
 * One 3-byte record of the list. The header byte holds the record type in bits 0..4 and a flag in bit 5; the
 * second byte comes from byte +0x11 of the port table entry; the third byte holds the bus id of the entry in
 * its low nibble and byte +0x12 of the entry in its high nibble.
 */
struct list_record {
    union {
        unsigned char raw;
        struct { unsigned char bits_7_6 : 2, bit_5 : 1, type : 5; } fields;
    } header;
    unsigned char byte_1;
    unsigned char byte_2;
};
extern struct sys_config_bits sys_config;
extern unsigned char port_entry0_bus_id, port_entry1_bus_id, port_entry2_bus_id, port_entry3_bus_id;
extern unsigned char nvram_get_device_option_bit25(void);
extern unsigned char input_get_routed_port_pair(void);
extern unsigned char input_port_table_get_code(unsigned char table_index);
extern unsigned char input_port_table_get_byte11(unsigned int);
extern unsigned char input_port_table_get_bus_id(unsigned int);
extern unsigned char input_port_table_get_type2_byte12(unsigned int);
extern unsigned char input_port_table_get_type1_byte12(unsigned char table_index);

/*
 * 1 when one of the first 10 records has a header byte equal to header, searching from the start and stopping
 * at the first record with the end type. The whole header byte is compared, so a record whose bit 5 is set
 * does not match its plain type number.
 */
static unsigned char list_has_header(struct list_record *list, int header)
{
    unsigned char found = 0;
    unsigned char i;

    for (i = 0; i < LIST_SEARCH_LIMIT; i++) {
        if (list[i].header.raw == header) {
            found = 1;
            break;
        }
        if (list[i].header.raw == RECORD_TYPE_END)
            break;
    }
    return found;
}

/*
 * Append the record for one port code to the port list, unless the list already has one of that type.
 *
 * code:  PORT_CODE_ENTRY0..3 append a record for that port entry; PORT_CODE_ROUTED appends the record of the
 *        pair input_get_routed_port_pair returns (by calling itself); PORT_LIST_END appends the end record
 *        (type 0x1f, second byte 1, third byte 0xFF). Any other code appends nothing.
 * list:  the record buffer.
 * count: records in the list so far; incremented when a record is appended, and used as the index of the
 *        new record.
 *
 * Entries 0 and 1 (codes 0x51, 0x61): record type 5 or 6; bit 5 of the header is copied from bit 18 of
 * sys_config word 0. Entries 2 and 3 (codes 0x71, 0x81): record type 9 / 8 when device option bit 25 is 1, else
 * 7 / 10; bit 5 is cleared; nothing is appended when the port table has no code (0xFF) for the entry. In both
 * cases the second byte is byte +0x11 of the entry's port table row, the third byte its bus id in the low
 * nibble and byte +0x12 in the high nibble.
 * Caller: input_port_list_build.
 */
void input_port_list_append(unsigned char code, struct list_record *list, unsigned char *count)
{
    unsigned char type, bus_id;

    switch (code) {
    case PORT_CODE_ENTRY0:
        if (list_has_header(list, RECORD_TYPE_ENTRY0))
            return;
        bus_id = port_entry0_bus_id;
        list[*count].header.raw = (list[*count].header.raw & ~0x20) | (sys_config.bit_18 << 5);
        list[*count].header.fields.type = RECORD_TYPE_ENTRY0;
        list[*count].byte_1 = input_port_table_get_byte11(bus_id);
        list[*count].byte_2 = (input_port_table_get_bus_id(bus_id) & 0xf) | ((input_port_table_get_type1_byte12(bus_id) & 0xf) << 4);
        (*count)++;
        break;
    case PORT_CODE_ENTRY1:
        if (list_has_header(list, RECORD_TYPE_ENTRY1))
            return;
        bus_id = port_entry1_bus_id;
        list[*count].header.raw = (list[*count].header.raw & ~0x20) | (sys_config.bit_18 << 5);
        list[*count].header.fields.type = RECORD_TYPE_ENTRY1;
        list[*count].byte_1 = input_port_table_get_byte11(bus_id);
        list[*count].byte_2 = (input_port_table_get_bus_id(bus_id) & 0xf) | ((input_port_table_get_type1_byte12(bus_id) & 0xf) << 4);
        (*count)++;
        break;
    case PORT_CODE_ENTRY2:
        type = RECORD_TYPE_ENTRY2_OPTION;
        if (nvram_get_device_option_bit25() != 1)
            type = RECORD_TYPE_ENTRY2_NO_OPTION;
        bus_id = port_entry2_bus_id;
        if (list_has_header(list, type))
            return;
        if (input_port_table_get_code(bus_id) == NO_PORT)
            return;
        list[*count].header.fields.bit_5 = 0;
        list[*count].header.fields.type = type;
        list[*count].byte_1 = input_port_table_get_byte11(bus_id);
        list[*count].byte_2 = (input_port_table_get_bus_id(bus_id) & 0xf) | ((input_port_table_get_type2_byte12(bus_id) & 0xf) << 4);
        (*count)++;
        break;
    case PORT_CODE_ENTRY3:
        type = RECORD_TYPE_ENTRY3_OPTION;
        if (nvram_get_device_option_bit25() != 1)
            type = RECORD_TYPE_ENTRY3_NO_OPTION;
        bus_id = port_entry3_bus_id;
        if (list_has_header(list, type))
            return;
        if (input_port_table_get_code(bus_id) == NO_PORT)
            return;
        list[*count].header.fields.bit_5 = 0;
        list[*count].header.fields.type = type;
        list[*count].byte_1 = input_port_table_get_byte11(bus_id);
        list[*count].byte_2 = (input_port_table_get_bus_id(bus_id) & 0xf) | ((input_port_table_get_type2_byte12(bus_id) & 0xf) << 4);
        (*count)++;
        break;
    case PORT_CODE_ROUTED:
        input_port_list_append(input_get_routed_port_pair(), list, count);
        break;
    case PORT_LIST_END:
        list[*count].header.fields.bit_5 = 0;
        list[*count].header.fields.type = RECORD_TYPE_END;
        list[*count].byte_1 = 1;
        list[*count].byte_2 = 0xff;
        (*count)++;
        break;
    }
}
