/* input_report_present_ports  (FUN_a01298d8)
 *
 * Build the mask of inputs that are present and report it to the input processor.
 * Name basis: derived - over the seven port entries; called from start-up and the main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01298d8 @ 0xa01298d8, flags -mcpu=v8 -O3 -g (the file builds with the section default; -msoft-float is not part of it).
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
extern unsigned short port_present_mask;
extern unsigned char input_is_port_cable_present(unsigned char);
extern unsigned char input_port_table_get_code(unsigned char);
extern void ipc_input_cpu_write_flags_word(unsigned short);

#define PORT_NONE 0xff

/*
 * Rebuild port_present_mask: bit i is set when port entry i has a cable (input_is_port_cable_present) and its
 * port table entry has a port code. The mask is then sent to the input processor.
 */
void input_report_present_ports(void)
{
    unsigned char i;

    for (i = 0; i <= 6; i++) {
        if (input_is_port_cable_present(port_entries[i].bus_id) && input_port_table_get_code(port_entries[i].bus_id) != PORT_NONE)
            port_present_mask |= 1 << i;
        else
            port_present_mask &= ~(1 << i);
    }
    ipc_input_cpu_write_flags_word(port_present_mask);
}
