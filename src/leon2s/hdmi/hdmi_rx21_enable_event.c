/* hdmi_rx21_enable_event  (FUN_a00a0930)
 *
 * Acknowledge and enable or disable one interrupt event of an HDMI 2.1 receiver.
 *   port: receiver
 *   event: event 0..0x3F
 *   mode: 1 = enable
 * Name basis: derived - sets the enable bit of the table 0xA00B4A00 entry after hdmi_rx21_ack_event
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0930 @ 0xa00a0930-0xa00a0b10, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the enable arm or's in `mode << bit` (not 1 << bit);
 *  - the disable arm is 'word & ~(1 << bit) & mask' in that order;
 *  - every register word is read and written through hdmi_rx21_reg_blocks[port].block0 at its use (volatile);
 *  - the switch on the group compiles to the jump table of 8 words at 0xa00a0910.
 */

/* One entry of hdmi_rx21_event_table (8 bytes, 0x40 entries; entry n is event n, group = n >> 3). */
struct rx21_event_entry {
    unsigned int group;                 /* 0..7: selects the register words of the event */
    unsigned char status_byte;          /* byte of the status word that holds the event's status bit */
    unsigned char enable_byte;          /* byte of the enable word written here */
    unsigned char bit;                  /* bit within that byte */
    unsigned char pad;
};

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers). This routine writes block 0 only. */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char blocks_1_to_12[0x30];
};

/* Enable words of register block 0 (word offsets). Each write keeps the bits under the mask given and writes
   the other bits as 0. */
#define EVENT_REG_74  (0x74 / 4)        /* bytes 1..3: enables of groups 0..2 (mask ~0xff) */
#define EVENT_REG_78  (0x78 / 4)        /* byte 0: enable of group 3 (mask 0xffffff; byte 3 is group 4's status) */
#define EVENT_REG_7C  (0x7c / 4)        /* bytes 1..3: enables of groups 4..6 (mask ~0xff) */
#define EVENT_REG_90  (0x90 / 4)        /* byte 1: enable of group 7 (mask 0xff00ff00) */

#define RX21_EVENT_COUNT  0x40
#define EVENT_ENABLE      1             /* value of `mode` that sets the enable bit */

extern struct rx21_event_entry hdmi_rx21_event_table[];
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern void hdmi_rx21_ack_event(unsigned int, unsigned int);

/*
 * Acknowledge event `event` of HDMI 2.1 receiver `port`, then set or clear its enable bit.
 *
 *   port   HDMI 2.1 receiver 0 or 1
 *   event  0..0x3F, the entry of hdmi_rx21_event_table; 0x40 and above do nothing
 *   mode   1 (EVENT_ENABLE) sets the enable bit, any other value clears it
 *
 * The enable bit is bit enable_byte * 8 + bit of the group's enable word. Callers:
 * hdmi_rx21_enable_sync_events (events 0x16, 0xE, 0x1C, 0xB, 8, and 0xC above chip revision 0x82; all on or
 * all off) and
 * hdmi_rx21_service_sync_events (event 0x16 off once it was seen).
 */
void hdmi_rx21_enable_event(unsigned char port, unsigned int event, unsigned char mode)
{
    struct rx21_event_entry *entry;
    unsigned char bit;

    if (event < RX21_EVENT_COUNT) {
        hdmi_rx21_ack_event(port, event);
        entry = &hdmi_rx21_event_table[event];
        bit = entry->enable_byte * 8 + entry->bit;
        switch (entry->group) {
        case 0:
        case 1:
        case 2:
            if (mode == EVENT_ENABLE)
                hdmi_rx21_reg_blocks[port].block0[EVENT_REG_74] = (hdmi_rx21_reg_blocks[port].block0[EVENT_REG_74] & ~0xff) | (mode << bit);
            else
                hdmi_rx21_reg_blocks[port].block0[EVENT_REG_74] = hdmi_rx21_reg_blocks[port].block0[EVENT_REG_74] & ~(1 << bit) & ~0xff;
            break;
        case 3:
            if (mode == EVENT_ENABLE)
                hdmi_rx21_reg_blocks[port].block0[EVENT_REG_78] = (hdmi_rx21_reg_blocks[port].block0[EVENT_REG_78] & 0xffffff) | (mode << bit);
            else
                hdmi_rx21_reg_blocks[port].block0[EVENT_REG_78] = hdmi_rx21_reg_blocks[port].block0[EVENT_REG_78] & ~(1 << bit) & 0xffffff;
            break;
        case 4:
        case 5:
        case 6:
            if (mode == EVENT_ENABLE)
                hdmi_rx21_reg_blocks[port].block0[EVENT_REG_7C] = (hdmi_rx21_reg_blocks[port].block0[EVENT_REG_7C] & ~0xff) | (mode << bit);
            else
                hdmi_rx21_reg_blocks[port].block0[EVENT_REG_7C] = hdmi_rx21_reg_blocks[port].block0[EVENT_REG_7C] & ~(1 << bit) & ~0xff;
            break;
        case 7:
            if (mode == EVENT_ENABLE)
                hdmi_rx21_reg_blocks[port].block0[EVENT_REG_90] = (hdmi_rx21_reg_blocks[port].block0[EVENT_REG_90] & 0xff00ff00) | (mode << bit);
            else
                hdmi_rx21_reg_blocks[port].block0[EVENT_REG_90] = hdmi_rx21_reg_blocks[port].block0[EVENT_REG_90] & ~(1 << bit) & 0xff00ff00;
            break;
        }
    }
}
