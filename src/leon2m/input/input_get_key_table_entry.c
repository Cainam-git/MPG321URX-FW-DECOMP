/* input_get_key_table_entry  (FUN_a012629c)
 *
 * Fetch the key table entry for the lowest set bit of a mask that is the constant 1: always entry 0.
 * Note: Fills the 8051 address of the entry's port, its mask and its level. Nothing calls it.
 * Name basis: descriptive - 3-byte entries at 0x1A4371; the search mask is the constant 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012629c @ 0xa012629c-0xa0126310 (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: the search runs on a byte variable initialised to 1; GCC keeps the loop, so the firmware computes
 * index = 0 at run time. Byte +3 is stored before byte +2.
 */
/* One entry of input_control_key_table (3 bytes). */
struct key_table_entry { unsigned char port, mask, level; };
/* The result: the 8051 address of the port, then the mask and the level. */
struct key_pin { unsigned short address; unsigned char level, mask; };
extern unsigned short gpio_get_port_8051_address(unsigned char port);
extern const struct key_table_entry input_control_key_table[];

/*
 * Fill `out` from the entry of input_control_key_table that belongs to the lowest set bit of a mask. The mask is
 * the constant 1, so the entry is always entry 0: out->address is the 8051 address of the entry's port,
 * out->mask its mask byte and out->level its level byte. Nothing calls it directly.
 */
void input_get_key_table_entry(struct key_pin *out)
{
    unsigned char mask = 1;
    unsigned char index;

    for (index = 0; index <= 7; index++) {
        if (mask & 1)
            break;
        mask >>= 1;
    }
    out->address = gpio_get_port_8051_address(input_control_key_table[index].port);
    out->mask = input_control_key_table[index].mask;
    out->level = input_control_key_table[index].level;
}
