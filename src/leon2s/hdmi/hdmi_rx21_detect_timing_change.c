/* hdmi_rx21_detect_timing_change  (H_ACTIVE_DIFF)
 *
 * Compare the HDMI 2.1 input timing with the stored one and report a mode change.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 1 when the mode changed
 * Name basis: proven - prints 'H_TOTAL_DIFF', 'V_TOTAL_DIFF', 'H_ACTIVE_DIFF', 'V_ACTIVE_DIFF', 'HDMI/DVI
 *   Changed', 'Int Set Mode Change'
 *
 * Matching notes
 * --------------
 * leon2s H_ACTIVE_DIFF @ 0xa009cb34-0xa009d2f8 (1988 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the register blocks are read through hdmi_rx21_reg_blocks[rx] in every expression (no pointer locals), and they
 *    are volatile;
 *  - H_TOTAL is written 'part2 + (h_active + part1) + part3'; the timing locals are unsigned short;
 *  - the print tests repeat the abs() expressions; the H_TOTAL store comes before the H_ACTIVE store;
 *  - after the receiver number is checked, the code indexes with 'port & 0xff' (not with rx).
 */

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers): block k of receiver n is at 0xCE009000 + n * 0x1000 + k * 0x100.
   Block 11 holds the CVTEM packet that hdmi_rx21_has_cvtem tests. */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char blocks_1_to_10[0x28];
    volatile unsigned int *block11;
    unsigned char block12[4];
};

/* The 400-byte record of an HDMI 2.1 receiver (hdmi_rx21_input_records), fields used here. */
struct rx21_record {
    unsigned char _00[2];
    unsigned char connected;            /* printed 'Connected' / 'Not Connected' */
    unsigned char _03[3];
    unsigned char vrr_flags;            /* written by hdmi_rx21_detect_vrr_signalling; 0 = none */
    unsigned char _07[0x11];
    unsigned char hdmi_mode;            /* compared with status word 0x30 bit 4 ('HDMI/DVI Changed') */
    unsigned char colour_depth;
    unsigned short h_total;             /* the stored timing that the new one is compared with */
    unsigned short v_total;
    unsigned short h_active;
    unsigned short v_active;
    unsigned char _22[0xb];
    unsigned char cvtem_present;        /* hdmi_rx21_has_cvtem result kept by DRV_HDMI_ModeDetect_FSM_Complete */
    unsigned char _2e[0x18a - 0x2e];
    unsigned char scramble_abnormal;    /* set by hdmi_rx21_service_sync_events */
    unsigned char _18b[5];
};

/* Mode-detect record of an HDMI 2.1 receiver, 0x18 bytes (hdmi_rx21_mode_detect_states). */
struct rx21_mode_detect_state {
    unsigned int state;
    unsigned char _4[6];
    unsigned char mode_change_flag;     /* hdmi_rx21_set_mode_change_flag; printed 'Int Set Mode Change' */
    unsigned char _b[9];
    unsigned char avi_byte30_changed;   /* 1 when hdmi_rx21_service_packet_events saw AVI byte_0x30 change */
    unsigned char _15[3];
};

/* HDMI PHY record, 24 bytes per PHY (hdmi_phy_records). */
struct hdmi_phy_record {
    unsigned char b0;
    unsigned char eq_done;              /* set to 1 by hdmi_eq_run_scan_fsm at 'finish FSM_EQSCAN_DONE' */
    unsigned char _2[0x16];
};

#define PHY_OF_RX0           2          /* PHY index of HDMI 2.1 receiver 0; receiver 1 is PHY 3 */
#define PHY_OF_RX1           3
#define TOTAL_TOLERANCE      5          /* H_TOTAL / V_TOTAL differences up to this are no change */
#define ACTIVE_TOLERANCE     1          /* H_ACTIVE / V_ACTIVE differences up to this are no change */
#define DBG_MODEDET_FLOW     4          /* dbg_hdmi_message_flags bit 2, EN_HDMI_MSG_MODEDET_FLOW */

/* Bit 2 + n is the mode-change signal of HDMI 2.1 receiver n (cleared by hdmi_rx21_clear_mode_change_signal). */
#define reg_ipc_shared_hdmi_status (*(volatile unsigned int *)0xcf03c890)
#define MODE_CHANGE_SIGNAL(rx)     (4 << (rx))

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern struct rx21_record hdmi_rx21_input_records[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned char hdmi_rx21_two_port_mode_flags[];        /* used here as a left shift of H_TOTAL and H_ACTIVE */
extern unsigned char hdmi_rx21_vrr_was_on_flags[];  /* 1 when vrr_flags was non-zero at the last look */
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_rx21_has_cvtem(unsigned char);
extern unsigned int hdmi_rx21_read_vtotal(unsigned char, unsigned char);
extern unsigned int hdmi_rx21_status30_bit4(unsigned int);
extern void irq_raise_software_irq_bit1(void);
extern void hdmi_rx21_clear_mode_status(unsigned int);
extern void hdmi_rx21_enable_sync_events(unsigned int, unsigned int);
extern void DRV_HDMI_Setup_IntIRQ_Events(unsigned int, unsigned int);

/*
 * Read the current timing of HDMI 2.1 receiver `port` (0 or 1), compare it with the stored one and handle a
 * mode change.
 *
 * Returns 1 when a mode change was found and handled, else 0 (also for a receiver number above 1).
 * Called by hdmi_rx21_modedet_watch_stable (mode-detect state 8), which on 1 sets the mode-detect state to 0.
 *
 * Phases:
 *   1. Read the timing. With a CVTEM packet present: H_ACTIVE and V_ACTIVE from block 11 words 0x0C / 0x10,
 *      H_TOTAL = H_ACTIVE plus three 16-bit values put together from bytes of block 11 words 0x84..0x8C, and
 *      V_TOTAL from hdmi_rx21_read_vtotal (block 0 words 0x64 and 0x60 are read and not used). Otherwise from
 *      block 0: H_TOTAL = word 0x38 bits 16..31, V_TOTAL = word 0x3C, H_ACTIVE = word 0x4C bits 16..31,
 *      V_ACTIVE = word 0x50, the two horizontal values shifted left by hdmi_rx21_two_port_mode_flags[rx].
 *   2. When vrr_flags went from non-zero to zero ('free sync to non free sync'), take the new V_TOTAL as
 *      the stored one, so that this step is no change.
 *   3. A change is any of: V_TOTAL differs by more than 5 (only without CVTEM and without VRR); H_ACTIVE
 *      differs by more than 1 (only without CVTEM); V_ACTIVE differs by more than 1; the HDMI/DVI bit differs
 *      from hdmi_mode; the mode-change flag is set; scramble_abnormal is set.
 *      A change sets the mode-change signal and raises software interrupt bit 1 for the main processor.
 *   4. When H_ACTIVE differs by more than 1 and H_TOTAL by more than 5, and the stored values are both exactly
 *      twice or both exactly half the new ones, the new values are stored and the change is dropped
 *      ('Enter Our Expection'), whatever else fired in phase 3; the signal raised there stays.
 *   5. No change: return 0.
 *   6. Print each difference above its tolerance and the reasons. Unless AVI byte_0x30 changed, print
 *      'HDMI 21 Port%c modechange' and clear the PHY's eq_done; clear scramble_abnormal (also clearing
 *      eq_done); clear the detected-mode flags.
 *   7. Connected: switch the sync events and the interrupt events off ('Call Sync Lost & Internal Mute').
 *      Return 1.
 */
unsigned char hdmi_rx21_detect_timing_change(unsigned int port)
{
    unsigned char rx = port;
    unsigned char phy;
    unsigned short h_total, v_total, h_active, v_active;
    unsigned int part1, part2, part3;
    unsigned int unused_64, unused_60a, unused_60b, unused_60c;
    unsigned char changed;

    if (rx == 0)
        phy = PHY_OF_RX0;
    else if (rx == 1)
        phy = PHY_OF_RX1;
    else
        return 0;

    /* Phase 1: current timing. */
    if (hdmi_rx21_has_cvtem(rx)) {
        h_active = ((hdmi_rx21_reg_blocks[rx].block11[0xc / 4] >> 24) << 8) + (hdmi_rx21_reg_blocks[rx].block11[0x10 / 4] & 0xff);
        v_active = (((hdmi_rx21_reg_blocks[rx].block11[0xc / 4] >> 8) & 0xff) << 8) + ((hdmi_rx21_reg_blocks[rx].block11[0xc / 4] >> 16) & 0xff);
        part1 = (((hdmi_rx21_reg_blocks[rx].block11[0x88 / 4] >> 16) & 0xff) << 8) + ((hdmi_rx21_reg_blocks[rx].block11[0x88 / 4] >> 8) & 0xff);
        part2 = ((hdmi_rx21_reg_blocks[rx].block11[0x88 / 4] & 0xff) << 8) + (hdmi_rx21_reg_blocks[rx].block11[0x84 / 4] >> 24);
        unused_64 = hdmi_rx21_reg_blocks[rx].block0[0x64 / 4];
        unused_60a = hdmi_rx21_reg_blocks[rx].block0[0x60 / 4];
        unused_60b = hdmi_rx21_reg_blocks[rx].block0[0x60 / 4];
        unused_60c = hdmi_rx21_reg_blocks[rx].block0[0x60 / 4];
        part3 = ((hdmi_rx21_reg_blocks[rx].block11[0x8c / 4] & 0xff) << 8) + (hdmi_rx21_reg_blocks[rx].block11[0x88 / 4] >> 24);
        h_total = part2 + (h_active + part1) + part3;
        v_total = hdmi_rx21_read_vtotal(rx, hdmi_rx21_input_records[rx].colour_depth);
    } else {
        h_total = (hdmi_rx21_reg_blocks[rx].block0[0x38 / 4] >> 16) << hdmi_rx21_two_port_mode_flags[rx];
        v_total = hdmi_rx21_reg_blocks[rx].block0[0x3c / 4];
        h_active = (hdmi_rx21_reg_blocks[rx].block0[0x4c / 4] >> 16) << hdmi_rx21_two_port_mode_flags[rx];
        v_active = hdmi_rx21_reg_blocks[rx].block0[0x50 / 4];
    }

    /* Phase 2: VRR switched off. */
    if (hdmi_rx21_vrr_was_on_flags[rx] != (hdmi_rx21_input_records[rx].vrr_flags != 0)) {
        if (hdmi_rx21_vrr_was_on_flags[rx] == 1 && hdmi_rx21_input_records[rx].vrr_flags == 0) {
            hdmi_rx21_input_records[rx].v_total = v_total;
            dbg_printf("free sync to non free sync Vtotal %d\r\n", v_total);
        }
        hdmi_rx21_vrr_was_on_flags[rx] = hdmi_rx21_input_records[rx].vrr_flags != 0;
    }

    /* Phase 3: the change tests. */
    changed = 0;
    if ((hdmi_rx21_input_records[port & 0xff].cvtem_present == 0 && hdmi_rx21_input_records[port & 0xff].vrr_flags == 0
         && __builtin_abs(hdmi_rx21_input_records[port & 0xff].v_total - v_total) > TOTAL_TOLERANCE)
        || (__builtin_abs(hdmi_rx21_input_records[port & 0xff].h_active - h_active) > ACTIVE_TOLERANCE
            && hdmi_rx21_input_records[port & 0xff].cvtem_present == 0)
        || __builtin_abs(hdmi_rx21_input_records[port & 0xff].v_active - v_active) > ACTIVE_TOLERANCE
        || (unsigned char)hdmi_rx21_status30_bit4(port & 0xff) != hdmi_rx21_input_records[port & 0xff].hdmi_mode
        || hdmi_rx21_mode_detect_states[port & 0xff].mode_change_flag == 1
        || hdmi_rx21_input_records[port & 0xff].scramble_abnormal == 1) {
        reg_ipc_shared_hdmi_status |= MODE_CHANGE_SIGNAL(port & 0xff);
        irq_raise_software_irq_bit1();
        changed = 1;

        /* Phase 4: the horizontal values exactly doubled or halved are taken over without a mode change. */
        if (__builtin_abs(hdmi_rx21_input_records[port & 0xff].h_active - h_active) > ACTIVE_TOLERANCE
            && __builtin_abs(hdmi_rx21_input_records[port & 0xff].h_total - h_total) > TOTAL_TOLERANCE) {
            if (hdmi_rx21_input_records[port & 0xff].h_active == h_active * 2
                && hdmi_rx21_input_records[port & 0xff].h_total == h_total * 2)
                changed = 0;
            else if (hdmi_rx21_input_records[port & 0xff].h_active == h_active >> 1
                     && hdmi_rx21_input_records[port & 0xff].h_total == h_total >> 1)
                changed = 0;
            if (changed == 0) {
                hdmi_rx21_input_records[port & 0xff].h_total = h_total;
                hdmi_rx21_input_records[port & 0xff].h_active = h_active;
                dbg_printf("## Jay debug ==> Port%c Enter Our Expection ##\n", (char)(port + 'A'));
            }
        }
    }

    /* Phase 5. */
    if (changed == 0)
        return 0;

    /* Phase 6: report the reasons and reset the mode state. */
    if (__builtin_abs(hdmi_rx21_input_records[port & 0xff].h_total - h_total) > TOTAL_TOLERANCE && (dbg_hdmi_message_flags & DBG_MODEDET_FLOW))
        dbg_printf("[MODEDET]: Port%c H_TOTAL_DIFF = %d\n", (char)(port + 'A'),
                     __builtin_abs(hdmi_rx21_input_records[port & 0xff].h_total - h_total));
    if (__builtin_abs(hdmi_rx21_input_records[port & 0xff].v_total - v_total) > TOTAL_TOLERANCE && (dbg_hdmi_message_flags & DBG_MODEDET_FLOW))
        dbg_printf("[MODEDET]: Port%c V_TOTAL_DIFF = %d\n", (char)(port + 'A'),
                     __builtin_abs(hdmi_rx21_input_records[port & 0xff].v_total - v_total));
    if (__builtin_abs(hdmi_rx21_input_records[port & 0xff].h_active - h_active) > ACTIVE_TOLERANCE && (dbg_hdmi_message_flags & DBG_MODEDET_FLOW))
        dbg_printf("[MODEDET]: Port%c H_ACTIVE_DIFF = %d\n", (char)(port + 'A'),
                     __builtin_abs(hdmi_rx21_input_records[port & 0xff].h_active - h_active));
    if (__builtin_abs(hdmi_rx21_input_records[port & 0xff].v_active - v_active) > ACTIVE_TOLERANCE && (dbg_hdmi_message_flags & DBG_MODEDET_FLOW))
        dbg_printf("[MODEDET]: Port%c V_ACTIVE_DIFF = %d\n", (char)(port + 'A'),
                     __builtin_abs(hdmi_rx21_input_records[port & 0xff].v_active - v_active));
    if (hdmi_rx21_input_records[port & 0xff].hdmi_mode != (unsigned char)hdmi_rx21_status30_bit4(port & 0xff) && (dbg_hdmi_message_flags & DBG_MODEDET_FLOW))
        dbg_printf("[MODEDET]: Port%c HDMI/DVI Changed = %d to %d\n", (char)(port + 'A'),
                     hdmi_rx21_input_records[port & 0xff].hdmi_mode, (unsigned char)hdmi_rx21_status30_bit4(port & 0xff));
    if (hdmi_rx21_mode_detect_states[port & 0xff].mode_change_flag == 1 && (dbg_hdmi_message_flags & DBG_MODEDET_FLOW))
        dbg_printf("[MODEDET]: Port%c Int Set Mode Change\n", (char)(port + 'A'));
    if (hdmi_rx21_mode_detect_states[port & 0xff].avi_byte30_changed == 0) {
        dbg_printf("HDMI 21 Port%c modechange\r\n", (char)(port + 'A'));
        hdmi_phy_records[phy].eq_done = 0;
    }
    if (hdmi_rx21_input_records[port & 0xff].scramble_abnormal == 1) {
        hdmi_rx21_input_records[port & 0xff].scramble_abnormal = 0;
        hdmi_phy_records[phy].eq_done = 0;
        if (dbg_hdmi_message_flags & DBG_MODEDET_FLOW)
            dbg_printf("[MODEDET]: Port%c Mode Change : scramble abnormal \n", (char)(port + 'A'));
    }
    hdmi_rx21_clear_mode_status(port & 0xff);

    /* Phase 7. */
    if (hdmi_rx21_input_records[port & 0xff].connected != 0) {
        if (dbg_hdmi_message_flags & DBG_MODEDET_FLOW)
            dbg_printf("[MODEDET]: Port%c Connected, Call Sync Lost & Internal Mute\n", (char)(port + 'A'));
        hdmi_rx21_enable_sync_events(port & 0xff, 0);
        DRV_HDMI_Setup_IntIRQ_Events(port & 0xff, 0);
    } else {
        if (dbg_hdmi_message_flags & DBG_MODEDET_FLOW)
            dbg_printf("[MODEDET]: Port%c Not Connected, Bypass Sync Lost\n", (char)(port + 'A'));
    }
    return 1;
}
