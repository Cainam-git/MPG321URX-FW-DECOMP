/* input_refresh_port_entries  (FUN_a002f550)
 *
 * Reload the four port entries from the Leon2S templates and fix their type and HDCP bits.
 * Note: Entries are the 18-byte records at 0xA802E116..0xA802E14C; prints 'Mute when Hdcp22Auth'.
 * Name basis: derived - header; text 'Mute when Hdcp22Auth'; main-loop caller sys_main_loop_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f550 @ 0xa002f550 (RAM copy, runs at 0x4008F550), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - one extern per entry (entries 0 and 1 are addressed with their own %hi/%lo); entries 2 and 3 go through a
 *    pointer local (gcc keeps the entry address in a register);
 *  - the outer type test is written as '(unsigned char)entry.bits.type == 5' (keeps the sll/srl 28 extraction),
 *    the inner and the other tests as plain 'entry.bits.type == 5' (folded to '(halfword & 0xf000) == 0x5000');
 *  - the flag bits of the entry are a bitfield struct.
 * The 'else' arm for entries 0 and 1 is dead code (outer and inner test are the same condition) but is part of
 * the firmware's code.
 */

/* First halfword of a port entry and the flag that sits in halfword +2. */
struct port_entry_bits {
    unsigned short type:4;      /* bits 15..12: the class of the entry; 5 is the class tested below */
    unsigned short bit_11:1;
    unsigned short bit_10:1;    /* 0x400, only written for class 5 on entries 0 and 1 */
    unsigned short bit_9:1;     /* 0x200, same */
    unsigned short bit_8:1;     /* 0x100, only written when bit_9 is set */
    unsigned short low_byte:8;  /* bits 7..0: flags copied from the template by input_load_port_template */
    unsigned short template_flag_5:1;   /* halfword +2, bit 15: template flags bit 5 */
    unsigned short rest_of_halfword_2:15;
};
/* One port entry, 0x12 bytes. The other halfwords are not used here. */
struct port_entry {
    struct port_entry_bits bits;
    unsigned short other[7];
};
/* Bits of hdmi_hdcp22_mute_started_bits (and of DAT_a802cc0a): bit 0 is entry 2, bit 1 is entry 3. */
extern struct port_entry port_entries, port_entry1, port_entry2, port_entry3;
extern unsigned char DAT_a802cc0a, hdmi_hdcp22_mute_started_bits;
extern unsigned short hdmi_hdcp22_mute_ticks[];
extern unsigned int sys_config;
extern void input_load_port_template(unsigned char);
extern int sys_return_zero();
extern int sys_return_zero_copy();
extern int dbg_printf();
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);

#define PORT_CLASS_5            5       /* the class (entry type) these tests look for */
#define SYS_CONFIG_BIT_19       0x80000 /* bit of the system configuration record that gates the mute wait */
#define HDCP22_MUTE_TICKS       1000    /* length of the mute wait, in ticks */

/* Both forms test "type == 5"; they differ only in the code gcc builds (see the matching notes). */
#define OUTER(e) ((unsigned char)(e).bits.type == PORT_CLASS_5)
#define IS5(e) ((e).bits.type == PORT_CLASS_5)

/*
 * Copy the port templates received from the input processor into port entries 0 to 3 (one call of
 * input_load_port_template each, entry n takes template n + 2), then adjust the entries that came out as class 5.
 *
 * Entries 0 and 1: for a class 5 entry, bits 0x400 and 0x200 are set from sys_return_zero(2 / 3) and, when 0x200
 * ended up set, bit 0x100 from sys_return_zero_copy(2 / 3). Both getters return 0 in this firmware, so the three
 * bits end up 0 (0x100 is left as the template set it when 0x200 is 0).
 *
 * Entries 2 and 3 (bit 0 / bit 1 of the two byte masks): a class 5 entry with bit 19 of the system configuration
 * set and template flag 5 set is held back for 1000 ticks counted from the first time it was seen like that
 * (time stamp in hdmi_hdcp22_mute_ticks[0 / 1]). During those ticks the entry's class is changed from 5 to 2 and
 * 'Mute when Hdcp22Auth' is printed. The started bit is cleared again as soon as the entry is no longer class 5;
 * the same bit of the second mask (DAT_a802cc0a) is cleared at the end for a non-class-5 entry.
 * Nothing in this routine reads DAT_a802cc0a.
 *
 * Called first by sys_main_loop_periodic_task, followed by input_port_sync_task.
 */
void input_refresh_port_entries(void)
{
    struct port_entry *entry;   /* entries 2 and 3 */

    input_load_port_template(0);
    if (OUTER(port_entries)) {
        if (IS5(port_entries)) {
            port_entries.bits.bit_10 = sys_return_zero(2);
            port_entries.bits.bit_9 = sys_return_zero(2);
            if (port_entries.bits.bit_9)
                port_entries.bits.bit_8 = sys_return_zero_copy(2);
        } else {
            port_entries.bits.bit_10 = 0;
            port_entries.bits.bit_9 = 0;
        }
    }
    input_load_port_template(1);
    if (OUTER(port_entry1)) {
        if (IS5(port_entry1)) {
            port_entry1.bits.bit_10 = sys_return_zero(3);
            port_entry1.bits.bit_9 = sys_return_zero(3);
            if (port_entry1.bits.bit_9)
                port_entry1.bits.bit_8 = sys_return_zero_copy(3);
        } else {
            port_entry1.bits.bit_10 = 0;
            port_entry1.bits.bit_9 = 0;
        }
    }
    input_load_port_template(2);
    entry = &port_entry2;
    if (!IS5(*entry))
        hdmi_hdcp22_mute_started_bits &= ~1;
    if (OUTER(*entry) && (sys_config & SYS_CONFIG_BIT_19) && entry->bits.template_flag_5) {
        if (!(hdmi_hdcp22_mute_started_bits & 1)) {
            /* First time seen: start the wait. */
            hdmi_hdcp22_mute_started_bits |= 1;
            hdmi_hdcp22_mute_ticks[0] = timer_get_ticks16();
        }
        if (timer_ticks_since(hdmi_hdcp22_mute_ticks[0]) < HDCP22_MUTE_TICKS) {
            dbg_printf("Mute when Hdcp22Auth\r\n");
            entry->bits.type = 2;
        }
    }
    if (!IS5(*entry))
        DAT_a802cc0a &= ~1;
    input_load_port_template(3);
    entry = &port_entry3;
    if (!IS5(*entry))
        hdmi_hdcp22_mute_started_bits &= ~2;
    if (OUTER(*entry) && (sys_config & SYS_CONFIG_BIT_19) && entry->bits.template_flag_5) {
        if (!(hdmi_hdcp22_mute_started_bits & 2)) {
            hdmi_hdcp22_mute_started_bits |= 2;
            hdmi_hdcp22_mute_ticks[1] = timer_get_ticks16();
        }
        if (timer_ticks_since(hdmi_hdcp22_mute_ticks[1]) < HDCP22_MUTE_TICKS) {
            dbg_printf("Mute when Hdcp22Auth\r\n");
            entry->bits.type = 2;
        }
    }
    if (!IS5(*entry))
        DAT_a802cc0a &= ~2;
}
