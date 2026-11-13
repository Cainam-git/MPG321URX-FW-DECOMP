/* startup_init_pins  (FUN_a0124448)
 *
 * Set up the pins from the boot byte of the 8051 and the port table.
 * Name basis: proven - pin function and direction set-up; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124448 @ 0xa0124448..0xa0124828 (248 words), flags -mcpu=v8 -O3 -g.
 * Source form: the "boot <= 1" arm is written first, the bus search is a for loop with break, the counters are
 * unsigned char, and the two flag bytes are or-ed directly inside the loop (GCC keeps them in registers and
 * stores each once after the loop).
 */
/* One 0x16-byte record of the port table (docs/DATA.md); only the first four bytes are read here. */
struct port_table_entry {
    unsigned char code;         /* +0 */
    unsigned char type;         /* +1 */
    unsigned char bus_id;       /* +2 */
    unsigned char byte_0x03;    /* +3: 1 marks a port that gets its flag bits set at start-up */
    unsigned char rest[18];     /* +4..+0x15 */
};
extern const struct port_table_entry port_table[];
extern unsigned char port_table_index_by_bus_id[];   /* index in port_table by bus id; 0xFF = no record has that bus id */
extern unsigned char edid_port_flags, edid_internal_enabled_bits;
extern void gpio_write_port_data(unsigned char, unsigned char);
extern void gpio_write_port_direction(unsigned char, unsigned char);
extern void gpio_write_port_config_pair(unsigned char, unsigned char, unsigned char);
extern void gpio_init_adc_and_pin_groups(unsigned char);
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

#define PORT_TABLE_RECORDS 8
#define BUS_ID_COUNT       7        /* bus ids 0..6 */
#define NO_RECORD          0xff

/*
 * Set up the chip's GPIO pins and fill two start-up tables from the port table. Start-up step 3, called by
 * the start-up routine right after it has read the boot byte the 8051 reports (printed as "Boot from %02X").
 *   boot  that boot byte. The start-up loop waits for a non-zero byte, so the value here is 1 or more.
 *
 * Order:
 *   1. boot 1 (the "<= 1" test also covers 0): give each of the 17 GPIO ports its start values from three
 *      fixed byte lists: the data byte (gpio_write_port_data), the direction byte
 *      (gpio_write_port_direction) and two configuration bytes (gpio_write_port_config_pair).
 *      Any other boot value skips these lists and only drives bits 5 and 4 of port 7 high (masks 0x20 and
 *      0x10).
 *   2. gpio_init_adc_and_pin_groups(0x70) in both cases.
 *   3. port_table_index_by_bus_id[bus] for bus 0..6 gets the index of the first port-table record with that bus id, or 0xFF
 *      when there is none (docs: proposed name port_table_index_by_bus_id).
 *   4. every port-table record whose byte +3 is 1 sets bit (bus id) in edid_internal_enabled_bits and
 *      edid_port_flags. A bus id above 7 sets nothing, because the bit is shifted out of the byte.
 * Nothing waits or reads back; the loops are bounded by the table size.
 */
void startup_init_pins(unsigned char boot)
{
    unsigned char bus, index;

    if (boot <= 1) {
        /* Start values for the 17 ports: data bytes, then direction bytes, then configuration pairs. */
        gpio_write_port_data(1, 0xfb); gpio_write_port_data(2, 0xfb); gpio_write_port_data(3, 0xff); gpio_write_port_data(4, 0x0f);
        gpio_write_port_data(5, 0x3c); gpio_write_port_data(6, 0xf8); gpio_write_port_data(7, 0x7b); gpio_write_port_data(8, 0xff);
        gpio_write_port_data(9, 0xd7); gpio_write_port_data(10, 0xff); gpio_write_port_data(11, 0xff); gpio_write_port_data(12, 0xbe);
        gpio_write_port_data(13, 0x8f); gpio_write_port_data(14, 0xff); gpio_write_port_data(15, 0xff); gpio_write_port_data(16, 0xff);
        gpio_write_port_data(17, 0xff);
        gpio_write_port_direction(1, 0xff); gpio_write_port_direction(2, 0xfb); gpio_write_port_direction(3, 0xff); gpio_write_port_direction(4, 0x0f);
        gpio_write_port_direction(5, 0x0c); gpio_write_port_direction(6, 0xf0); gpio_write_port_direction(7, 0x49); gpio_write_port_direction(8, 0x55);
        gpio_write_port_direction(9, 0xd7); gpio_write_port_direction(10, 0xff); gpio_write_port_direction(11, 0xdf); gpio_write_port_direction(12, 0x2e);
        gpio_write_port_direction(13, 0x93); gpio_write_port_direction(14, 0xff); gpio_write_port_direction(15, 0xff); gpio_write_port_direction(16, 0xff);
        gpio_write_port_direction(17, 0xff);
        gpio_write_port_config_pair(1, 7, 0); gpio_write_port_config_pair(2, 7, 2); gpio_write_port_config_pair(3, 0, 0); gpio_write_port_config_pair(4, 0xf0, 0);
        gpio_write_port_config_pair(5, 3, 0); gpio_write_port_config_pair(6, 7, 0); gpio_write_port_config_pair(7, 0x84, 0); gpio_write_port_config_pair(8, 0, 0);
        gpio_write_port_config_pair(9, 8, 0); gpio_write_port_config_pair(10, 0, 0); gpio_write_port_config_pair(11, 0, 0); gpio_write_port_config_pair(12, 0xc1, 0);
        gpio_write_port_config_pair(13, 0x6c, 0); gpio_write_port_config_pair(14, 0, 0); gpio_write_port_config_pair(15, 0, 0); gpio_write_port_config_pair(16, 0, 0);
        gpio_write_port_config_pair(17, 0, 0);
    } else {
        gpio_write_pin(7, 0x20, 0xff);
        gpio_write_pin(7, 0x10, 0xff);
    }
    gpio_init_adc_and_pin_groups(0x70);

    /* Bus id -> index of its port-table record. */
    for (bus = 0; bus < BUS_ID_COUNT; bus++) {
        port_table_index_by_bus_id[bus] = NO_RECORD;
        for (index = 0; index < PORT_TABLE_RECORDS; index++)
            if (port_table[index].bus_id == bus) {
                port_table_index_by_bus_id[bus] = index;
                break;
            }
    }
    /* Ports flagged in byte +3 of their record: set their bit in the two EDID flag bytes. */
    for (index = 0; index < PORT_TABLE_RECORDS; index++)
        if (port_table[index].byte_0x03 == 1) {
            edid_internal_enabled_bits |= 1 << port_table[index].bus_id;
            edid_port_flags |= 1 << port_table[index].bus_id;
        }
}
