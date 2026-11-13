/* hdmi_mute_port_until_hdcp22_auth  (FUN_a0141f98)
 *
 * Keep a class 5 port muted while its HDCP 2.2 authentication is checked.
 * Name basis: derived - prints 'Mute when Hdcp22Auth'; time-stamped; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141f98 @ 0xa0141f98, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on (same as the per-entry code in input_refresh_port_entries):
 *  - the type tests use the bit-field directly (folds to the 0xf000 mask) and, for the test in the second 'if',
 *    through an (unsigned char) cast (keeps the sll/srl extraction);
 *  - the byte at 0xa802cc0a is used under its address label, the flag byte under its name.
 */
/* First two halfwords of a port entry (the same layout as in input_refresh_port_entries). */
struct port_entry_bits {
    unsigned short type:4;      /* bits 15..12: the class of the entry; 5 is the class tested below */
    unsigned short bit_11:1;
    unsigned short bit_10:1;
    unsigned short bit_9:1;
    unsigned short bit_8:1;
    unsigned short low_byte:8;
    unsigned short template_flag_5:1;   /* halfword +2, bit 15 */
    unsigned short rest_of_halfword_2:15;
};
/* One port entry, 0x12 bytes. The other halfwords are not used here. */
struct port_entry {
    struct port_entry_bits bits;
    unsigned short other[7];
};
extern unsigned char DAT_a802cc0a, hdmi_hdcp22_mute_started_bits;
extern unsigned short hdmi_hdcp22_mute_ticks[];
extern unsigned int sys_config;
extern int dbg_printf(const char *, ...);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);

#define PORT_CLASS_5            5               /* the class (entry type) tested below */
#define PORT_CLASS_MUTED        2               /* the class the entry gets while the mute lasts */
#define SYS_CONFIG_BIT_19       0x80000         /* bit of the system configuration record that gates the mute */
#define HDCP22_MUTE_LAST_TICK   999             /* the mute lasts while fewer than 1000 ticks have passed */

/*
 * While HDCP 2.2 authentication of a port is awaited, change the class of its entry from 5 to 2 for the first
 * 1000 ticks, printing "Mute when Hdcp22Auth" each time it does.
 *
 *   entry  the port entry (same layout as in input_refresh_port_entries)
 *   k      0 or 1: bit k of hdmi_hdcp22_mute_started_bits and of the byte at DAT_a802cc0a, and
 *          hdmi_hdcp22_mute_ticks[k], belong to this entry; a larger value returns at once
 *
 * The mute applies when the entry is of class 5, bit 19 of sys_config is set and template_flag_5 of the entry is
 * set. The first time all of that holds, the start bit is set and the tick count noted; the start bit is cleared
 * again whenever the entry is not of class 5. The byte at DAT_a802cc0a loses bit k at the end whenever the entry
 * is not of class 5 (which includes the case that this call has just changed it to 2). Nothing calls this
 * routine by name.
 */
void hdmi_mute_port_until_hdcp22_auth(struct port_entry *entry, unsigned char k)
{
    if (k > 1)
        return;
    if (entry->bits.type != PORT_CLASS_5)
        hdmi_hdcp22_mute_started_bits &= ~(1 << k);
    if ((unsigned char)entry->bits.type == PORT_CLASS_5 && (sys_config & SYS_CONFIG_BIT_19) && entry->bits.template_flag_5) {
        /* First time seen: start the count. */
        if (!((hdmi_hdcp22_mute_started_bits >> k) & 1)) {
            hdmi_hdcp22_mute_started_bits |= 1 << k;
            hdmi_hdcp22_mute_ticks[k] = timer_get_ticks16();
        }
        if (timer_ticks_since(hdmi_hdcp22_mute_ticks[k]) <= HDCP22_MUTE_LAST_TICK) {
            dbg_printf("Mute when Hdcp22Auth\r\n");
            entry->bits.type = PORT_CLASS_MUTED;
        }
    }
    if (entry->bits.type != PORT_CLASS_5)
        DAT_a802cc0a &= ~(1 << k);
}
