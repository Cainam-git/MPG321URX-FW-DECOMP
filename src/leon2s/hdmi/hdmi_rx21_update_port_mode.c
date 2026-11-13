/* hdmi_rx21_update_port_mode  (FUN_a00980a8)
 *
 * Update the mode byte and registers of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - record byte +0x189 with register writes; caller the mode-detect handler
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00980a8 @ 0xa00980a8-0xa0098240 (408 bytes, including the ret/restore tail), flags -mcpu=v8 -Os
 * -g.
 * Source forms the exact build depends on: the block 2 pointer is 'volatile unsigned long *' (the alias set
 * keeps the next record load ahead of the register store, as in the firmware); bit 12 of block 2 + 0x80 is
 * tested as bit 4 of the byte (register >> 8); the record is reached through a byte pointer.
 */
/* One row per HDMI 2.1 receiver (hdmi_rx21_reg_blocks): the addresses of its register blocks. */
struct hdmi_rx21_reg_blocks {
    unsigned int block0;                /* address of block 0, used with reg_set_bit / reg_clear_bit */
    unsigned int block1;
    volatile unsigned long *block2;     /* +8 */
    unsigned char blocks_3_to_12[0x34 - 0xc];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_rx21_input_records[][400];   /* struct rx21_record, 400 bytes per receiver */
extern unsigned char hdmi_rx21_is_event_pending(unsigned char, unsigned char);
extern void hdmi_rx21_update_ctrl_bit19(unsigned char);
extern void reg_set_bit(unsigned int bit, unsigned int address);
extern void reg_clear_bit(unsigned int bit, unsigned int address);

/* Bytes of the receiver's rx21_record. */
#define RX21_CONNECTED      2           /* 0: nothing is done */
#define RX21_PORT_MODE      0x189       /* the mode last set here: PORT_MODE_* */

enum {
    PORT_MODE_BIT12_CLEAR = 0,          /* block 2 + 0x80 bit 12 clear */
    PORT_MODE_BIT12_SET   = 1,          /* block 2 + 0x80 bit 12 set */
    PORT_MODE_EVENT_04    = 2           /* receiver event 4 pending */
};

#define RX21_EVENT_04       4           /* receiver event (status bit listed in hdmi_rx21_event_table) */

/* Registers, as byte offsets in their block. */
#define BLOCK0_REG_0C       0xc         /* bit 24 (0x18) and bit 23 (0x17) */
#define BLOCK0_REG_84       0x84        /* bit 8 pulsed at the end of every call */
#define BLOCK2_REG_80       0x80        /* bit 12 picks mode 1 or 0 */
#define BLOCK2_REG_9C       0x9c        /* bits 24..31: 9 in mode 2, 2 in modes 0 and 1 */
#define BIT_23              0x17
#define BIT_24              0x18
#define BIT_8               8
#define TOP_BYTE            0xff000000

/*
 * Set the receiver's registers for one of three modes, and remember the mode in byte +0x189 of its
 * rx21_record so that the registers are only rewritten when the mode changes. Called by
 * hdmi_rx21_modedet_watch_stable.
 *
 *   port   HDMI 2.1 receiver 0 or 1
 *
 * Nothing happens while the record's connected byte is 0. The mode, in this order:
 *   2  receiver event 4 is pending: block 0 + 0xC bit 24 set, top byte of block 2 + 0x9C = 9;
 *   1  otherwise, after hdmi_rx21_update_ctrl_bit19, when bit 12 of block 2 + 0x80 is set: block 0 + 0xC
 *      bit 24 cleared and bit 23 set, top byte of block 2 + 0x9C = 2;
 *   0  else: the same with bit 23 cleared.
 * Every call (with the receiver connected) ends with a pulse of bit 8 of block 0 + 0x84.
 */
void hdmi_rx21_update_port_mode(unsigned char port)
{
    unsigned char *record = hdmi_rx21_input_records[port];

    if (record[RX21_CONNECTED] == 0)
        return;
    if (hdmi_rx21_is_event_pending(port, RX21_EVENT_04)) {
        if (record[RX21_PORT_MODE] != PORT_MODE_EVENT_04) {
            reg_set_bit(BIT_24, ARR_a807db00[port].block0 + BLOCK0_REG_0C);
            ARR_a807db00[port].block2[BLOCK2_REG_9C / 4] = (ARR_a807db00[port].block2[BLOCK2_REG_9C / 4] & ~TOP_BYTE) | 0x09000000;
            record[RX21_PORT_MODE] = PORT_MODE_EVENT_04;
        }
    } else {
        hdmi_rx21_update_ctrl_bit19(port);
        if ((unsigned char)(ARR_a807db00[port].block2[BLOCK2_REG_80 / 4] >> 8) & 0x10) {
            if (record[RX21_PORT_MODE] != PORT_MODE_BIT12_SET) {
                reg_clear_bit(BIT_24, ARR_a807db00[port].block0 + BLOCK0_REG_0C);
                ARR_a807db00[port].block2[BLOCK2_REG_9C / 4] = (ARR_a807db00[port].block2[BLOCK2_REG_9C / 4] & ~TOP_BYTE) | 0x02000000;
                reg_set_bit(BIT_23, ARR_a807db00[port].block0 + BLOCK0_REG_0C);
                record[RX21_PORT_MODE] = PORT_MODE_BIT12_SET;
            }
        } else {
            if (record[RX21_PORT_MODE] != PORT_MODE_BIT12_CLEAR) {
                reg_clear_bit(BIT_24, ARR_a807db00[port].block0 + BLOCK0_REG_0C);
                ARR_a807db00[port].block2[BLOCK2_REG_9C / 4] = (ARR_a807db00[port].block2[BLOCK2_REG_9C / 4] & ~TOP_BYTE) | 0x02000000;
                reg_clear_bit(BIT_23, ARR_a807db00[port].block0 + BLOCK0_REG_0C);
                record[RX21_PORT_MODE] = PORT_MODE_BIT12_CLEAR;
            }
        }
    }
    reg_set_bit(BIT_8, ARR_a807db00[port].block0 + BLOCK0_REG_84);
    reg_clear_bit(BIT_8, ARR_a807db00[port].block0 + BLOCK0_REG_84);
}
