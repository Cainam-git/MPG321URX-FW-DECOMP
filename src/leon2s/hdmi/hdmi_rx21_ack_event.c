/* hdmi_rx21_ack_event  (FUN_a00a07b8)
 *
 * Acknowledge (clear) one interrupt event of an HDMI 2.1 receiver.
 *   port: receiver
 *   id: event 0..0x3F
 * Name basis: derived - writes the event's status bit (write-one-to-clear) from table 0xA00B4A00
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a07b8, flags -mcpu=v8 -Os -g (section default). Leaf.
 * Source forms: one entry pointer for all three entry reads; the register block pointer is volatile (the firmware
 * keeps the stores out of the branch delay slots). The switch is the jump table of 8 words at 0xa00a0798.
 */
/* One entry of hdmi_rx21_event_table (8 bytes, 0x40 entries; entry n is event n, group = n >> 3). */
struct rx21_event_entry {
    unsigned int group;                 /* 0..7: selects the register word of the event */
    unsigned char status_byte;          /* byte of that word that holds the event's status bit */
    unsigned char enable_byte;
    unsigned char bit;                  /* bit within that byte */
    unsigned char pad;
};

/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;      /* 0xCE009000 (+0x1000 for receiver 1) */
    unsigned char blocks_1_to_12[0x30];
};

/* Event words of register block 0 (word offsets). */
#define EVENT_REG_70  (0x70 / 4)
#define EVENT_REG_74  (0x74 / 4)
#define EVENT_REG_78  (0x78 / 4)
#define EVENT_REG_7C  (0x7c / 4)
#define EVENT_REG_80  (0x80 / 4)
#define EVENT_REG_90  (0x90 / 4)

#define RX21_EVENT_COUNT 0x40

extern struct rx21_event_entry hdmi_rx21_event_table[];
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];

/*
 * Write a 1 to the status bit of event `id` of receiver `port` (the way status bits are cleared). The event's
 * group picks the word of register block 0: groups 0..2 word 0x70, 3 word 0x74, 4 word 0x78, 5 word 0x7C,
 * 6 word 0x80, 7 word 0x90. The bits under the mask in the case are written back as read, all other bits are
 * written as 0. Ids from 0x40 up do nothing. Called by hdmi_rx21_enable_event, hdmi_rx21_service_sync_events
 * and hdmi_rx21_mode_detect_settle.
 *   port  HDMI 2.1 receiver 0/1
 *   id    event number 0..0x3F
 */
void hdmi_rx21_ack_event(unsigned int port, unsigned int id)
{
    unsigned char bit;
    struct rx21_event_entry *event;

    if (id < RX21_EVENT_COUNT) {
        event = &hdmi_rx21_event_table[id];
        bit = event->status_byte * 8 + event->bit;
        switch (event->group) {
        case 0:
        case 1:
        case 2:
            hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_70] = (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_70] & 0xff) | (1 << bit);
            break;
        case 3:
            hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_74] = (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_74] & ~0xff) | (1 << bit);
            break;
        case 4:
            hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_78] = (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_78] & 0xffffff) | (1 << bit);
            break;
        case 5:
            hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_7C] = (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_7C] & ~0xff) | (1 << bit);
            break;
        case 6:
            hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_80] = (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_80] & 0xffffff) | (1 << bit);
            break;
        case 7:
            hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_90] = (hdmi_rx21_reg_blocks[port & 0xff].block0[EVENT_REG_90] & 0xff00ff00) | (1 << bit);
            break;
        }
    }
}
