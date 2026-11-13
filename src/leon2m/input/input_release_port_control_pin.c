/* input_release_port_control_pin  (FUN_a0124da4)
 *
 * Drive the control pin of an input to its inactive level.
 * Name basis: derived - pin from bytes +0x0E/+0x0F, inverse of the level in byte +0x10; used when ports are
 *   switched on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124da4 @ 0xa0124da4-0xa0124df8 (21 words), flags -mcpu=v8 -O3 -g.
 * Leaf apart from the tail call of gpio_write_pin. The third argument is the complement of the level byte (xnor with
 * %g0, then 'and 0xff').
 */
/* Fields +0x0E..+0x10 of an entry of the port table in ROM (0x16 bytes each); see docs/DATA.md. */
struct port_table_entry {
    unsigned char unused_00[0xe];
    unsigned char control_port, control_mask, control_level;
    unsigned char unused_11[5];
};
extern const struct port_table_entry port_table[];
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

#define PORT_NONE       0xff
#define PORT_LAST       7           /* highest index of the port table */

/*
 * Write the control pin of an input with the complement of its level byte (control_level), so it is not at its
 * active level. Does nothing for indexes above 7 and for entries whose control port is 0xFF (no pin).
 *
 *   index  entry of the port table
 *
 * Counterpart of input_assert_port_control_pin.
 */
void input_release_port_control_pin(unsigned char index)
{
    const struct port_table_entry *entry = &port_table[index];

    if (index <= PORT_LAST && entry->control_port != PORT_NONE)
        gpio_write_pin(entry->control_port, entry->control_mask, ~entry->control_level);
}
