/* input_update_present_ports_alt  (FUN_a0129980)
 *
 * Rebuild the second present-ports mask from the detect pins of the port entries.
 * Note: Unlike input_report_present_ports it does not use the second pin of type 1 entries and sends nothing.
 *   Nothing calls it.
 * Name basis: descriptive - bit i of port_present_mask_alt set when the detect pin of port entry i is active
 *   and its table entry has a port code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129980 @ 0xa0129980, flags -mcpu=v8 -O3 -g.
 */
/* One port entry (0x12 bytes at port_entries); see docs/DATA.md. */
struct port_entry {
    unsigned short class_and_flags;     /* +0x00: class in bits 12..15 */
    unsigned short halfword_0x02;
    unsigned char byte_0x04, byte_0x05;
    unsigned short halfword_0x06, halfword_0x08, halfword_0x0a, halfword_0x0c, halfword_0x0e;
    unsigned char bus_id;               /* +0x10: passed to the port table routines as the table index */
    unsigned char byte_0x11;
};
extern struct port_entry port_entries[7];
extern unsigned short port_present_mask_alt;
extern unsigned char input_is_port_detect_pin_active(unsigned char);
extern unsigned char input_port_table_get_code(unsigned char);

#define PORT_NONE 0xff

/*
 * Rebuild port_present_mask_alt: bit i is set when the detect pin of port entry i is active
 * (input_is_port_detect_pin_active) and its port table entry has a port code. Unlike
 * input_report_present_ports it does not use the second pin of type 1 entries and sends nothing.
 */
void input_update_present_ports_alt(void)
{
    unsigned char i;

    for (i = 0; i <= 6; i++) {
        if (input_is_port_detect_pin_active(port_entries[i].bus_id) && input_port_table_get_code(port_entries[i].bus_id) != PORT_NONE)
            port_present_mask_alt |= 1 << i;
        else
            port_present_mask_alt &= ~(1 << i);
    }
}
