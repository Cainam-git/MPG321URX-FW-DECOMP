/* input_is_port_control_pin_active  (FUN_a0124e44)
 *
 * Return whether the control pin of an input reads its active level.
 * Returns: 0 or 1
 * Name basis: derived - pin from bytes +0x0E/+0x0F; 1 when the entry has no such pin; polled by the main-loop
 *   task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124e44 @ 0xa0124e44-0xa0124ea4 (24 words), flags -mcpu=v8 -O3 -g.
 * Source form: the pin value from gpio_read_pin is an unsigned int masked with 0xff before the compare.
 */
/* Fields +0x0E..+0x10 of an entry of the port table in ROM (0x16 bytes each); see docs/DATA.md. */
struct port_table_entry {
    unsigned char unused_00[0xe];
    unsigned char control_port, control_mask, control_level;
    unsigned char unused_11[5];
};
extern const struct port_table_entry port_table[];
extern unsigned int gpio_read_pin(int, int);

#define PORT_NONE       0xff
#define PORT_LAST       7           /* highest index of the port table */

/*
 * Return 1 when the control pin of an input reads its level byte (control_level), else 0. Returns 1 for indexes
 * above 7 and for entries whose control port is 0xFF (no pin).
 *
 *   index  entry of the port table
 */
unsigned char input_is_port_control_pin_active(unsigned char index)
{
    const struct port_table_entry *entry = &port_table[index];
    unsigned char active = 1;
    unsigned int pin;

    if (index <= PORT_LAST && entry->control_port != PORT_NONE) {
        pin = gpio_read_pin(entry->control_port, entry->control_mask);
        active = (pin & 0xff) == entry->control_level;
    }
    return active;
}
