/* hdmi_rx21_service_sync_events  (FUN_a00a0c84)
 *
 * Handle pending events 8, 0x1C, 0xE, 0x16, 0xB and 0xC of an HDMI 2.1 receiver.
 *   port: receiver
 * Returns: 0
 * Note: Events 8, 0x1C, 0xB and 0xC set the mode-change flag.
 * Name basis: derived - events 8, 0x1C, 0xE, 0x16, 0xB, 0xC through hdmi_rx21_is_event_pending; sets the mode-
 *   change flag
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0c84 @ 0xa00a0c84-0xa00a1098 (1044 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - phy is set by 'phy = 2; if (port != 0) { if (port == 1) phy = 3; }' (branches, not flag
 *    arithmetic);
 *  - event16_seen = 1 is written before the hdmi_rx21_enable_event call;
 *  - the event-word counter is one condition with the pre-increment inside it.
 */

/* Register block 1 of an HDMI 2.1 receiver, as far as this routine uses it. Words 0x40 and 0x44 are the AVI
   header word and data word 0 that hdmi_rx21_read_avi_infoframe decodes. */
struct rx21_block1 {
    unsigned char words_0x00_to_0x30[0x34];
    unsigned char bits_0x34[0xc];       /* tested bit by bit with reg_test_bit */
    unsigned int avi_header;
    unsigned int avi_data0;
};

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers): block k of receiver n is at 0xCE009000 + n * 0x1000 + k * 0x100. */
struct rx21_reg_blocks {
    unsigned int block0;
    struct rx21_block1 *block1;
    unsigned char blocks_2_to_12[0x2c];
};

/* The 400-byte record of an HDMI 2.1 receiver (hdmi_rx21_input_records), fields used here. */
struct rx21_record {
    unsigned char byte_0x0;
    unsigned char mode_detected;        /* 1 after DRV_HDMI_ModeDetect_FSM_Complete */
    unsigned char _2[5];
    unsigned char event16_seen;         /* 1 when event 0x16 was pending in the last pass of this routine */
    unsigned char avi_reread_request;   /* hdmi_rx21_service_packet_events reads the AVI data again and clears it */
    unsigned char _9[3];
    unsigned int avi_header_copy;       /* last block 1 word 0x40 seen here */
    unsigned int avi_data0_copy;        /* last block 1 word 0x44 seen here */
    unsigned char _14[4];
    unsigned char hdmi_mode;            /* compared with status word 0x30 bit 4 ('HDMI/DVI Changed') */
    unsigned char _19[0x18a - 0x19];
    unsigned char scramble_abnormal;    /* hdmi_rx21_detect_timing_change: 'Mode Change : scramble abnormal' */
    unsigned char _18b;
    unsigned int event10_ticks;         /* tick count when the event 0x10 status bit was last handled */
};

/* Event numbers of hdmi_rx21_event_table, with the status bit each one stands for. */
enum {
    RX21_EVENT_08 = 0x08,               /* status word 0x70 bit 16 */
    RX21_EVENT_0B = 0x0b,               /* status word 0x70 bit 19 */
    RX21_EVENT_0C = 0x0c,               /* status word 0x70 bit 20; handled only above chip revision 0x82 */
    RX21_EVENT_0E = 0x0e,               /* status word 0x70 bit 22 */
    RX21_EVENT_10 = 0x10,               /* status word 0x70 bit 24 (= hdmi_rx21_status70_bit24) */
    RX21_EVENT_16 = 0x16,               /* status word 0x70 bit 30 */
    RX21_EVENT_1C = 0x1c                /* status word 0x74 bit 4 */
};

#define CHIP_REV_82            0x82     /* sys_get_chip_revision: revisions 0x80..0x84 */
#define EVENT_WORD_MAX_PASSES  0x14     /* passes with an unchanged non-zero event word before it is dropped */

/* Bit 2 + n is the mode-change signal of HDMI 2.1 receiver n (cleared by hdmi_rx21_clear_mode_change_signal). */
#define reg_ipc_shared_hdmi_status (*(volatile unsigned int *)0xcf03c890)
#define MODE_CHANGE_SIGNAL(rx)     (4 << (rx))

extern struct rx21_record hdmi_rx21_input_records[];
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned int hdmi_rx21_sync_event_words[];
extern unsigned char hdmi_rx21_sync_event_flags[];
extern unsigned char hdmi_rx21_sync_event_bytes[];
extern unsigned char hdmi_rx21_is_event_pending(unsigned char, unsigned char);
extern void hdmi_rx21_ack_event(unsigned int, unsigned int);
extern void hdmi_rx21_enable_sync_events(unsigned char, unsigned char);
extern void hdmi_rx21_set_mode_change_flag(unsigned int);
extern void irq_raise_software_irq_bit1(void);
extern unsigned char sys_get_chip_revision(void);
extern unsigned char hdmi_rx21_status70_bit24(unsigned char);
extern void irq_empty_vector_handler_copy4(unsigned char);
extern void hdmi_rx21_set_event_reg78_bit(unsigned char, unsigned int, unsigned char);
extern unsigned int timer_get_ticks(void);
extern unsigned char hdmi_get_port_mode_byte(unsigned int);
extern unsigned char timer_stamp_older_than_50(unsigned int);
extern unsigned int reg_test_bit(unsigned int, void *);
extern void hdmi_rx21_enable_event(unsigned char, unsigned char, unsigned char);

/*
 * Handle the pending events 8, 0x1C, 0xE, 0x16, 0xB and 0xC of HDMI 2.1 receiver `port` (0 or 1).
 *
 * Returns 0. Called by hdmi_rx21_service_irq_port0 / _port1 while the receiver's mode_detected byte is set.
 *
 * "Report a mode change" below means: set the receiver's mode-change signal bit in reg_ipc_shared_hdmi_status,
 * raise software interrupt bit 1 for the main processor, switch the receiver's sync events off
 * (hdmi_rx21_enable_sync_events(port, 0)) and set the mode-change flag that hdmi_rx21_detect_timing_change
 * tests (hdmi_rx21_set_mode_change_flag).
 *
 * Phases, in this order:
 *   1. Event 8: report a mode change; up to chip revision 0x82 the event is acknowledged here.
 *   2. Event 0x1C: report a mode change when hdmi_mode is set; always acknowledged.
 *   3. Event 0xE:
 *      a. mode detected: when the event 0x10 status bit is set, take new copies of the AVI header and data
 *         word, ask for the AVI data to be read again, acknowledge event 0x10 and stamp the time;
 *      b. otherwise: set scramble_abnormal when the PHY's bHDMI_ONLYSCRAMBLE_GUESSMODE byte
 *         (hdmi_get_port_mode_byte) is set, more than 50 ticks passed since that stamp and bits 0 and 1 of
 *         block 1 word 0x34 are both set;
 *      c. count the passes in which the receiver's event word stays the same non-zero value; on the 21st
 *         pass in a row the word and its two companions are cleared;
 *      d. acknowledge event 0xE.
 *   4. Event 0x16: switch the event off and note it in event16_seen.
 *   5. Event 0xB: as event 8.
 *   6. Event 0xC, only above chip revision 0x82: report a mode change; not acknowledged here.
 *
 * The event word (hdmi_rx21_sync_event_words) is cleared by hdmi_rx21_clear_event_word; no other routine of
 * the program names it.
 */
int hdmi_rx21_service_sync_events(unsigned char port)
{
    unsigned char event16 = 0;
    unsigned char phy;

    /* Phase 1: event 8. */
    if (hdmi_rx21_is_event_pending(port, RX21_EVENT_08)) {
        reg_ipc_shared_hdmi_status |= MODE_CHANGE_SIGNAL(port);
        irq_raise_software_irq_bit1();
        if (sys_get_chip_revision() <= CHIP_REV_82)
            hdmi_rx21_ack_event(port, RX21_EVENT_08);
        hdmi_rx21_enable_sync_events(port, 0);
        hdmi_rx21_set_mode_change_flag(port);
    }

    /* Phase 2: event 0x1C. */
    if (hdmi_rx21_is_event_pending(port, RX21_EVENT_1C)) {
        if (hdmi_rx21_input_records[port].hdmi_mode) {
            reg_ipc_shared_hdmi_status |= MODE_CHANGE_SIGNAL(port);
            irq_raise_software_irq_bit1();
            hdmi_rx21_enable_sync_events(port, 0);
            hdmi_rx21_set_mode_change_flag(port);
        }
        hdmi_rx21_ack_event(port, RX21_EVENT_1C);
    }

    /* Phase 3: event 0xE. */
    if (hdmi_rx21_is_event_pending(port, RX21_EVENT_0E)) {
        /* The receiver's PHY index: 2 for receiver 0, 3 for receiver 1 (hdmi_is_hdmi21_phy). */
        phy = 2;
        if (port != 0) {
            if (port == 1)
                phy = 3;
        }
        if (hdmi_rx21_input_records[port].mode_detected == 1) {
            /* 3a. */
            if (hdmi_rx21_status70_bit24(port)) {
                if (hdmi_rx21_input_records[port].avi_header_copy != hdmi_rx21_reg_blocks[port].block1->avi_header) {
                    if ((hdmi_rx21_input_records[port].avi_data0_copy & 0xe0) != (hdmi_rx21_reg_blocks[port].block1->avi_data0 & 0xe0)) {
                        /* An empty routine: this call has no effect. */
                        irq_empty_vector_handler_copy4(port);
                        hdmi_rx21_input_records[port].avi_data0_copy = hdmi_rx21_reg_blocks[port].block1->avi_data0;
                    }
                    hdmi_rx21_input_records[port].avi_header_copy = hdmi_rx21_reg_blocks[port].block1->avi_header;
                }
                hdmi_rx21_input_records[port].avi_reread_request = 1;
                hdmi_rx21_ack_event(port, RX21_EVENT_10);
                hdmi_rx21_set_event_reg78_bit(port, 0x10, 0);      /* bit 16 of block 0 word 0x78 cleared */
                hdmi_rx21_input_records[port].event10_ticks = timer_get_ticks();
            }
        } else if (hdmi_get_port_mode_byte(phy & 3) && timer_stamp_older_than_50(hdmi_rx21_input_records[port].event10_ticks)
                   && reg_test_bit(0, hdmi_rx21_reg_blocks[port].block1->bits_0x34)
                   && reg_test_bit(1, hdmi_rx21_reg_blocks[port].block1->bits_0x34)) {
            /* 3b. */
            hdmi_rx21_input_records[port].scramble_abnormal = 1;
        }
        /* 3c. The flag byte keeps the low byte of the word seen in the previous pass. */
        if (hdmi_rx21_sync_event_words[port] == hdmi_rx21_sync_event_flags[port]) {
            if (hdmi_rx21_sync_event_words[port] != 0 && ++hdmi_rx21_sync_event_bytes[port] > EVENT_WORD_MAX_PASSES) {
                hdmi_rx21_sync_event_words[port] = 0;
                hdmi_rx21_sync_event_bytes[port] = 0;
                hdmi_rx21_sync_event_flags[port] = 0;
            }
        } else {
            hdmi_rx21_sync_event_flags[port] = hdmi_rx21_sync_event_words[port];
            hdmi_rx21_sync_event_bytes[port] = 0;
        }
        /* 3d. */
        hdmi_rx21_ack_event(port, RX21_EVENT_0E);
    }

    /* Phase 4: event 0x16. */
    if (hdmi_rx21_is_event_pending(port, RX21_EVENT_16)) {
        event16 = 1;
        hdmi_rx21_enable_event(port, RX21_EVENT_16, 0);
        hdmi_rx21_ack_event(port, RX21_EVENT_16);
    }

    /* Phase 5: event 0xB. */
    if (hdmi_rx21_is_event_pending(port, RX21_EVENT_0B)) {
        reg_ipc_shared_hdmi_status |= MODE_CHANGE_SIGNAL(port);
        irq_raise_software_irq_bit1();
        if (sys_get_chip_revision() <= CHIP_REV_82)
            hdmi_rx21_ack_event(port, RX21_EVENT_0B);
        hdmi_rx21_enable_sync_events(port, 0);
        hdmi_rx21_set_mode_change_flag(port);
    }

    /* Phase 6: event 0xC on newer chips. */
    if (sys_get_chip_revision() > CHIP_REV_82 && hdmi_rx21_is_event_pending(port, RX21_EVENT_0C)) {
        reg_ipc_shared_hdmi_status |= MODE_CHANGE_SIGNAL(port);
        irq_raise_software_irq_bit1();
        hdmi_rx21_enable_sync_events(port, 0);
        hdmi_rx21_set_mode_change_flag(port);
    }
    hdmi_rx21_input_records[port].event16_seen = event16;
    return 0;
}
