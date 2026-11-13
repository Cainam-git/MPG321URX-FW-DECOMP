/* input_is_port_cable_present  (FUN_a0124bf4)
 *
 * Return whether a cable is detected on an input.
 * Returns: 0 or 1
 * Name basis: derived - reads the detect pin named in the port table entry; always 1 for the three virtual
 *   ports
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124bf4 @ 0xa0124bf4-0xa0124d24 (76 words), flags -mcpu=v8 -O3 -g.
 * Source form: the second pin is copied with memcpy(&second, entry->second_pin, 4) (expanded inline, byte by byte,
 * as the entry is byte-aligned) into an 8-byte structure whose second word this function does not use (frame size);
 * its level bit is read through the unsigned int container (word load). The entry pointer is set up as
 * 'table = port_table; entry = table + index;' (table before the index multiply); the detect-pin test after the
 * second-pin check is written with port_table[index] (the firmware rebuilds the entry address there), the other one
 * with entry. The result goes through 'present & 1'.
 */
/* One entry of the port table in ROM (0x16 bytes); see docs/DATA.md. */
struct port_table_entry {
    unsigned char code;
    unsigned char type;
    unsigned char unused_02[9];
    unsigned char detect_port, detect_mask, detect_level;   /* +0x0B..+0x0D */
    unsigned char unused_0e[4];
    unsigned char second_pin[4];        /* +0x12..+0x15, read as struct second_pin for type 1 */
};
/* Bytes +0x12..+0x15 of a type 1 entry. A port of 0xFF means no pin. */
struct second_pin {
    unsigned char byte_0, port, mask;
    unsigned int level : 1, unused : 7;
    unsigned int unused_word;
};
extern const struct port_table_entry port_table[];
extern unsigned char sys_cable_mode_byte;
extern unsigned int gpio_read_pin(int, int);
extern void *memcpy(void *, const void *, unsigned int);

#define PORT_TYPE_1     1
#define PORT_NONE       0xff
#define PORT_LAST       7           /* highest index of the port table */

/*
 * Return 1 when a cable is detected on the input with the given port table index, else 0.
 *
 *   index  entry of the port table; 0xFC..0xFE (the three virtual ports) always count as present, 0xFF and
 *          indexes above 7 never do
 *
 * A pin counts as set when gpio_read_pin(port, mask) equals the level byte of the entry. For an entry of type 1
 * that has a second pin (bytes +0x13..+0x15), that pin decides as long as sys_cable_mode_byte is 0. In every
 * other case the detect pin of the entry (bytes +0x0B..+0x0D) decides, the same test as
 * input_is_port_detect_pin_active; an entry without detect pin (port 0xFF) gives 0.
 * input_report_present_ports calls it for the seven port entries.
 */
unsigned char input_is_port_cable_present(unsigned char index)
{
    const struct port_table_entry *table;
    const struct port_table_entry *entry;
    unsigned char present = 0;
    struct second_pin second;

    if ((unsigned char)(index + 4) <= 2)
        present = 1;
    else if (index != PORT_NONE) {
        if (index <= PORT_LAST) {
            table = port_table;
            entry = table + index;
            if (entry->type == PORT_TYPE_1) {
                memcpy(&second, entry->second_pin, 4);
                if (second.port != PORT_NONE && sys_cable_mode_byte == 0)
                    present = (gpio_read_pin(second.port, second.mask) & 0xff) == second.level;
                else if (port_table[index].detect_port != PORT_NONE
                         && (gpio_read_pin(port_table[index].detect_port, port_table[index].detect_mask) & 0xff)
                            == port_table[index].detect_level)
                    present = 1;
                else
                    present = 0;
            } else if (entry->detect_port != PORT_NONE
                       && (gpio_read_pin(entry->detect_port, entry->detect_mask) & 0xff) == entry->detect_level)
                present = 1;
            else
                present = 0;
        }
    }
    return present & 1;
}
