/* hdmi_rx21_is_event_pending  (FUN_a00a0588)
 *
 * Return 1 when an HDMI 2.1 event is pending; most events must also be enabled.
 *   port: receiver
 *   event: event 0..0x3F
 * Returns: 1 when pending
 * Name basis: derived - event table 0xA00B4A00 (type, register, bit) over status words 0x70..0x90
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0588 @ 0xa00a0588-0xa00a0798, flags -mcpu=v8 -Os -g (leaf).
 * Source forms the exact build depends on:
 *  - the event test is an early 'return 0' before `pending` is used;
 *  - one entry pointer for the three entry reads; both bit numbers are computed before the switch;
 *  - every register word is read through hdmi_rx21_reg_blocks[port & 0xff].block0 at its use (volatile);
 *  - the switch on the group compiles to the jump table of 8 words at 0xa00a0568.
 */

/* One entry of hdmi_rx21_event_table (8 bytes, 0x40 entries; entry n is event n). The table lists the events
   in groups of eight (group = event >> 3) with bit = event & 7. */
struct rx21_event_entry {
    unsigned int group;                 /* 0..7: selects the register words of the event */
    unsigned char status_byte;          /* byte of the status word that holds the event's status bit */
    unsigned char enable_byte;          /* byte of the enable word that hdmi_rx21_enable_event writes */
    unsigned char bit;                  /* bit within that byte */
    unsigned char pad;
};

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers). This routine reads block 0 only. */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char blocks_1_to_12[0x30];
};

/* Event words of register block 0 (word offsets), as the event table and hdmi_rx21_ack_event /
   hdmi_rx21_enable_event use them. */
#define EVENT_REG_70  (0x70 / 4)        /* bytes 1..3: status of groups 0..2 */
#define EVENT_REG_74  (0x74 / 4)        /* byte 0: status of group 3; bytes 1..3: enables of groups 0..2 */
#define EVENT_REG_78  (0x78 / 4)        /* byte 0: enable of group 3; byte 3: status of group 4 */
#define EVENT_REG_7C  (0x7c / 4)        /* byte 0: status of group 5; bytes 1..3: enables of groups 4..6 */
#define EVENT_REG_80  (0x80 / 4)        /* byte 3: status of group 6 */
#define EVENT_REG_90  (0x90 / 4)        /* byte 0: status of group 7; byte 1: its enable */

#define RX21_EVENT_COUNT  0x40
#define RX21_EVENT_04     4             /* status word 0x70 bit 12 */
#define RX21_EVENT_16     0x16          /* status word 0x70 bit 30 */

extern struct rx21_event_entry hdmi_rx21_event_table[];
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];

/*
 * Return 1 when event `event` of HDMI 2.1 receiver `port` is enabled and its status bit is set, else 0.
 *
 *   port   HDMI 2.1 receiver 0 or 1 (only the low byte counts)
 *   event  0..0x3F, the entry of hdmi_rx21_event_table; 0x40 and above return 0
 *
 * Nothing is acknowledged here. Callers: hdmi_rx21_service_sync_events (events 8, 0xB, 0xC, 0xE, 0x16, 0x1C)
 * and hdmi_rx21_update_port_mode (event 4).
 *
 * The status bit is bit status_byte * 8 + bit of the group's status word; the enable bit, for groups 0..3,
 * bit enable_byte * 8 + bit of the group's enable word. Groups 4..7 test the status bit's number in the
 * enable word instead, under the enable word's mask. With the table's entries this gives:
 *   - events 4 and 0x16 count from their status bit alone, enabled or not;
 *   - events 0x20..0x27 (group 4) test the enable bits of events 0x30..0x37 (word 0x7C byte 3);
 *   - events 0x28..0x2F (group 5) and 0x38..0x3F (group 7) never return 1: their number falls in byte 0,
 *     which the mask removes.
 */
unsigned char hdmi_rx21_is_event_pending(unsigned int port, unsigned int event)
{
    unsigned char pending = 0;
    struct rx21_event_entry *entry;
    unsigned int status_bit, enable_bit;

    if (event >= RX21_EVENT_COUNT)
        return 0;
    entry = &hdmi_rx21_event_table[event];
    status_bit = entry->status_byte * 8 + entry->bit;
    enable_bit = entry->enable_byte * 8 + entry->bit;
    switch (entry->group) {
    case 0:
    case 1:
    case 2:
        if (event == RX21_EVENT_04 || event == RX21_EVENT_16) {
            if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_70] & (1 << status_bit))
                pending = 1;
        } else if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_74] & (1 << enable_bit) & ~0xff) {
            if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_70] & (1 << status_bit))
                pending = 1;
        }
        break;
    case 3:
        if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_78] & (1 << enable_bit) & 0xffffff) {
            if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_74] & (1 << status_bit))
                pending = 1;
        }
        break;
    case 4:
        if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_7C] & (1 << status_bit) & ~0xff) {
            if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_78] & (1 << status_bit))
                pending = 1;
        }
        break;
    case 5:
        if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_7C] & (1 << status_bit) & ~0xff) {
            if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_7C] & (1 << status_bit))
                pending = 1;
        }
        break;
    case 6:
        if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_7C] & (1 << status_bit) & ~0xff) {
            if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_80] & (1 << status_bit))
                pending = 1;
        }
        break;
    case 7:
        if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_90] & (1 << status_bit) & 0xff00ff00) {
            if (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_90] & (1 << status_bit))
                pending = 1;
        }
        break;
    }

    return pending;
}
