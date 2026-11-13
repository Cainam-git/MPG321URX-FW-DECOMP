/* input_is_port_detect_pin_active  (FUN_a0124d24)
 *
 * Return whether the detect pin of an input reads its active level.
 * Returns: 0 or 1
 * Name basis: derived - pin and level from bytes +0x0B..+0x0D of the port table entry
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124d24 @ 0xa0124d24-0xa0124da4 (32 words), flags -mcpu=v8 -O3 -g.
 * Source form: 'present' initialised to 0 in its declaration, the 0xFF and <= 7 tests as separate nested ifs, and the
 * entry test with the call as one '&&' condition with an explicit 'else present = 0;' (present is then set after the
 * call on that path and is not kept across it). The result goes through 'present & 1'.
 */
/* Fields +0x0B..+0x0D of an entry of the port table in ROM (0x16 bytes each); see docs/DATA.md. */
struct port_table_entry {
    unsigned char unused_00[0xb];
    unsigned char detect_port, detect_mask, detect_level;
    unsigned char unused_0e[8];
};
extern const struct port_table_entry port_table[];
extern unsigned int gpio_read_pin(int, int);

#define PORT_NONE       0xff
#define PORT_LAST       7           /* highest index of the port table */

/*
 * Return 1 when the detect pin of the input reads its active level, else 0.
 *
 *   index  entry of the port table; 0xFC..0xFE (the three virtual ports) give 1, 0xFF and indexes above 7 give 0
 *
 * The pin is detect_port / detect_mask of the entry, the active level is detect_level; an entry whose detect
 * port is 0xFF has no pin and gives 0. Called by input_update_present_ports_alt.
 */
unsigned char input_is_port_detect_pin_active(unsigned char index)
{
    const struct port_table_entry *entry;
    unsigned char present = 0;

    if ((unsigned char)(index + 4) <= 2)
        present = 1;
    else if (index != PORT_NONE) {
        if (index <= PORT_LAST) {
            entry = &port_table[index];
            if (entry->detect_port != PORT_NONE
                && (gpio_read_pin(entry->detect_port, entry->detect_mask) & 0xff) == entry->detect_level)
                present = 1;
            else
                present = 0;
        }
    }
    return present & 1;
}
