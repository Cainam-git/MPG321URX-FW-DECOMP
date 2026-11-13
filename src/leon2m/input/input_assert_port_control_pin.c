/* input_assert_port_control_pin  (FUN_a0124df8)
 *
 * Drive the control pin of an input to its active level.
 * Name basis: derived - pin from bytes +0x0E/+0x0F, level from byte +0x10 of the port table entry
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124df8 @ 0xa0124df8, flags -mcpu=v8 -O3 -g.
 * Source form: the entry pointer (sethi/or, smul, add) is computed before the compare with 7, as in the firmware.
 */
extern unsigned char port_table[];      /* entries of 0x16 bytes */
extern int gpio_write_pin();

#define PORT_ENTRY_SIZE         0x16
#define PORT_CONTROL_PORT       0xe     /* offsets in the entry */
#define PORT_CONTROL_MASK       0xf
#define PORT_CONTROL_LEVEL      0x10
#define PORT_NONE               0xff
#define PORT_LAST               7       /* highest index of the port table */

/*
 * Write the control pin of an input with the level byte of its entry (control_level), the active level.
 * Does nothing for indexes above 7 and for entries whose control port is 0xFF (no pin).
 *
 *   index  entry of the port table
 *
 * Counterpart of input_release_port_control_pin.
 */
void input_assert_port_control_pin(unsigned int index)
{
    unsigned char *entry;
    unsigned int n;

    n = index & 0xff;
    entry = (unsigned char *)port_table + n * PORT_ENTRY_SIZE;
    if (n <= PORT_LAST) {
        if (entry[PORT_CONTROL_PORT] != PORT_NONE) {
            gpio_write_pin(entry[PORT_CONTROL_PORT], entry[PORT_CONTROL_MASK], entry[PORT_CONTROL_LEVEL]);
        }
    }
    return;
}
