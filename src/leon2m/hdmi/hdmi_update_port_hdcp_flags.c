/* hdmi_update_port_hdcp_flags  (FUN_a0141edc)
 *
 * Copy three state bits of a class 5 port into its port entry.
 * Name basis: descriptive - bits 10, 9 and 8 from two status getters; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141edc @ 0xa0141edc, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on (same as the per-entry code in input_refresh_port_entries):
 *  - the outer type test reads the field through an (unsigned char) cast (keeps the sll/srl extraction), the inner
 *    one is the plain field test (folded to (halfword & 0xf000) == 0x5000);
 *  - the inner else arm, which clears bits 9 and 10, can never run (outer and inner test are the same
 *    condition) but is part of the code;
 *  - both flag bits are set from separate calls of the same getter.
 */
/* First halfword of a port entry (the same layout as in input_refresh_port_entries). */
struct port_entry_bits {
    unsigned short type:4;      /* bits 15..12: the class of the entry; 5 is the class tested below */
    unsigned short bit_11:1;
    unsigned short bit_10:1;    /* 0x400 */
    unsigned short bit_9:1;     /* 0x200 */
    unsigned short bit_8:1;     /* 0x100, only written when bit_9 is set */
    unsigned short low_byte:8;
};
/* One port entry, 0x12 bytes. The other halfwords are not used here. */
struct port_entry {
    struct port_entry_bits bits;
    unsigned short other[8];
};
extern int sys_return_zero(unsigned char port);
extern int sys_return_zero_copy(unsigned char port);

#define PORT_CLASS_5 5          /* the class (entry type) this routine acts on */
#define LAST_PORT    3

/*
 * For a port entry of class 5, set its bits 10 and 9 from sys_return_zero(port) and, when bit 9 is then set,
 * its bit 8 from sys_return_zero_copy(port). Other entries, and ports above 3, are left alone.
 *
 *   entry  the port entry to update
 *   port   0..3
 *
 * Both getters return 0 in this firmware, so bits 10 and 9 end up 0 and bit 8 is never written.
 * Nothing calls this routine. input_refresh_port_entries contains the same steps for entries 0 and 1.
 */
void hdmi_update_port_hdcp_flags(struct port_entry *entry, unsigned char port)
{
    if (port <= LAST_PORT && (unsigned char)entry->bits.type == PORT_CLASS_5) {
        if (entry->bits.type == PORT_CLASS_5) {
            entry->bits.bit_10 = sys_return_zero(port);
            entry->bits.bit_9 = sys_return_zero(port);
            if (entry->bits.bit_9)
                entry->bits.bit_8 = sys_return_zero_copy(port);
        } else {
            entry->bits.bit_10 = 0;
            entry->bits.bit_9 = 0;
        }
    }
}
