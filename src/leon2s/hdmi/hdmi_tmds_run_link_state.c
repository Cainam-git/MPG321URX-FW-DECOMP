/* hdmi_tmds_run_link_state  (LINK_STANDBY)
 *
 * Run one step of the HDMI 2.0 receiver link state machine for one port.
 *   rec: port record
 *   port: port 0 or 1
 * Note: Compares only active size and total width when checking for a timing change, not the refresh rate.
 * Name basis: proven - prints 'TMDS(%d) go to LINK_READY', 'go to LINK_STABLE', 'go to LINK_STANDBY'; ports
 *   0/1
 *
 * Matching notes
 * --------------
 * leon2s LINK_STANDBY @ 0xa006d7bc-0xa006e0e4 (2344 bytes, 586 words), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - every use takes the unsigned char parameter port itself (no local copy);
 *  - the start-of-pass copies are read in the order state, published_flags, byte_0xe;
 *  - the saved timing of LINK_READY is a 10-byte stack struct (struct saved_timing) of which four fields are
 *    written and pixel_clock never; it gives the firmware's 128-byte frame (8 bytes would give 120);
 *  - in LINK_STABLE the "only guess scramble" check copies phy into a block-local (guess_phy);
 *  - in LINK_READY 'mode_change = 1' comes before the "scramble abnormal" print, and the tail is written
 *    'if (rec->state != LINK_STATE_READY)' first;
 *  - hdmi_get_color_format_code is called a second time in LINK_STABLE and its result dropped.
 * No volatile, no asm.
 */

/* Link states (byte +0 of a port record). The firmware's own texts name 3..5: LINK_STANDBY, LINK_STABLE and
   LINK_READY. */
enum link_state {
    LINK_STATE_POWER_OFF = 1,
    LINK_STATE_POWER_ON  = 2,
    LINK_STATE_STANDBY   = 3,       /* 'LINK_STANDBY' */
    LINK_STATE_STABLE    = 4,       /* 'LINK_STABLE' */
    LINK_STATE_READY     = 5        /* 'LINK_READY' */
};

#define SETTLE_TICKS            200     /* LINK_STABLE waits this long after its time stamp before reading */
#define DEEP_COLOUR_WAIT_TICKS  0xF9    /* ... and up to this long while hdmi_is_deep_color reports 1 */

/* LINK_READY: differences from the saved timing that count as a mode change. */
#define HACTIVE_TOLERANCE       2
#define VACTIVE_TOLERANCE       1
#define HTOTAL_TOLERANCE        0x10
#define HACTIVE_MODE_CHANGE     0x1FFF  /* 'usLINKHrtlDE == 0x1FFF, mode change' */

#define HDMI_REG_5              5       /* receiver register 5: bit 4 set on leaving LINK_READY, cleared in it */
#define REG5_BIT4               0x10

/* Bits of published_flags (+0xD, 'ucPHYStatus') set by hdmi_update_port_status_flags: bit 2 from the VRR
   detector (hdmi_detect_vrr_signalling bit 0 or 2), bit 3 from its bit 1, bit 6 from hdr_source_active_flag.
   A change of these three also marks the port as changed. */
#define PORT_FLAGS_CHANGED_MASK 0x4C

/* Port record (20 bytes, input_port_records[0] / [1] for HDMI 2.0 ports 0 / 1). +0xF and +0x10 ask
   ipc_publish_port_status to send the record to the main processor. */
struct port_record {
    unsigned char state, byte_0x1;                  /* state: enum link_state */
    unsigned short htotal, vtotal, hactive, vactive, pixel_clock;  /* usLINKHtotal .. usLINKClk */
    unsigned char colour_space;                     /* +0xC: hdmi_get_color_format_code ('ucClrSpace') */
    unsigned char published_flags;                  /* +0xD: 'ucPHYStatus' */
    unsigned char byte_0xe;                         /* bit 7 = hdmi_status134_bit1, bit 6 = hdmi_get_restart_hint */
    unsigned char publish;                          /* +0xF: 1 = send the record to the main processor */
    unsigned char changed;                          /* +0x10: 1 = send it and mark the port as changed */
    unsigned char step;                             /* +0x11: cleared by input_set_link_state */
    union {
        unsigned short word;                        /* bit 7 = flag from the main processor (input_load_port_flag_bits) */
        unsigned char colour_depth;                 /* high byte: 'ucColordepth' */
    } flags;
};

/* HDMI PHY record (24 bytes, one per PHY; index 0 / 1 = the HDMI 2.0 receivers). */
struct hdmi_phy_record {
    unsigned char power, eq_done;                   /* eq_done: 1 once the EQ scan has finished */
    unsigned char byte_0x2, byte_0x3, byte_0x4, byte_0x5;
    unsigned char byte_0x6;                         /* copy of bit 7 of the port record's flags */
    unsigned char option_byte;
    unsigned char rest_0x8[16];
};

/* Receiver record of an HDMI 2.0 port (0xB0 bytes); hdmi_poll_rx_status fills it. */
struct hdmi_rx_record {
    unsigned char bytes[0xa8];
    unsigned int avi_ticks;                         /* +0xA8: time of the last AVI InfoFrame capture */
    unsigned char scramble_abnormal;                /* +0xAC: set by hdmi_poll_rx_status */
    unsigned char byte_0xad, byte_0xae, byte_0xaf;
};

/* The timing of LINK_READY's last pass, compared with the new reading. */
struct saved_timing { unsigned short hactive, vactive, htotal, vtotal, pixel_clock; };

extern struct hdmi_phy_record hdmi_phy_records[];
extern struct hdmi_rx_record hdmi_rx_records[];
extern unsigned int hdmi_tmds_link_ticks[];
extern unsigned char hdmi_tmds_link_flags[];
extern unsigned char hdmi_tmds_link_retry_counts[];

extern void input_set_link_state(struct port_record *, unsigned char);
extern void hdmi_set_port_reg5_bit4(struct port_record *, unsigned char);
extern void hdmi_update_port_status_flags(struct port_record *, unsigned int);
extern int dbg_printf(char *, ...);
extern unsigned int dbg_print_string(char *);
extern unsigned char hdmi_phy_is_eq_done(unsigned int);
extern void TMDS_PowerOn(unsigned char);
extern void TMDS_PowerOff(unsigned char, unsigned char);
extern unsigned char hdmi_get_port_mode_byte(unsigned int);
extern void hdmi_set_port_mode_byte(unsigned int, unsigned char);
extern void hdmi_eq_monitor_errors(unsigned char, unsigned char);
extern unsigned char hdmi_is_second_port(unsigned char);
extern void hdmi_reset_reg340_block(unsigned char);
extern void hdmi_pulse_reg133_bit7(unsigned char);
extern void hdmi_clear_packet_status(unsigned char);
extern void hdmi_clear_packet_update_flags(unsigned int);
extern void hdmi_clear_packet_seen_flags(unsigned int);
extern void hdmi_set_reg08_from_avi(unsigned int);
extern unsigned char hdmi_apply_color_depth(unsigned char);
extern void hdmi_set_ycbcr422_bit(unsigned int);
extern unsigned char hdmi_is_deep_color(unsigned int);
extern void hdmi_set_reg135_mode(unsigned char, unsigned char);
extern void hdmi_set_regb5_bit2(unsigned char, unsigned char);
extern unsigned char hdmi_get_port1_double_flag(unsigned char);
extern unsigned short hdmi_read_hactive(unsigned int);
extern unsigned short hdmi_read_vactive(unsigned int);
extern unsigned short hdmi_read_htotal(unsigned int);
extern unsigned short hdmi_read_vtotal(unsigned int);
extern unsigned char hdmi_get_color_format_code(unsigned char);
extern void hdmi_clear_port1_double_flag(unsigned char);
extern void hdmi_poll_rx_status(unsigned char);
extern unsigned short hdmi_calc_pixel_clock(unsigned char);
extern void hdmi_save_link_timing(unsigned int);
extern void hdmi_set_ycbcr_regs(unsigned char);
extern void hdmi_clear_shared_port_bit(unsigned char);
extern void hdmi_set_reg2fd_bit3(unsigned char);
extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);
extern void hdmi_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern void timer_delay_long_units(int);
extern unsigned int timer_get_ticks(void);
extern int abs(int);

/*
 * One pass of the link state machine of an HDMI 2.0 input ("TMDS" in the firmware's texts).
 *
 *   rec   the input's port record
 *   port  HDMI 2.0 receiver 0 or 1; any other value returns at once
 *
 * The only caller is input_run_link_tasks, every main-loop pass, with (input_port_records[0], 0) and
 * (input_port_records[1], 1). The PHY record used is hdmi_phy_records[phy] with phy = 1 for port 1, else 0.
 *
 * Phases of a pass:
 *   1. Remember state, published flags and byte 0xE, to report changes at the end; copy the main processor's
 *      port flag (bit 7 of the flags halfword) into byte 6 of the PHY record.
 *   2. One step of the state:
 *        POWER_OFF  power the receiver off once (TMDS_PowerOff).
 *        POWER_ON   power it on once (TMDS_PowerOn), go to STANDBY.
 *        STANDBY    wait for the PHY's EQ scan to finish; set the receiver up, capture the timing, stamp the
 *                   time, go to STABLE.
 *        STABLE     after SETTLE_TICKS: read colour depth, colour space and timing again; a zero size goes back
 *                   to STANDBY; otherwise (once hdmi_is_deep_color reports 0, or after DEEP_COLOUR_WAIT_TICKS)
 *                   clear the packet status, store the timing and go to READY. Each fall back to STANDBY
 *                   counts a retry: two retries switch the port to "only guess scramble" mode, a fall back in
 *                   that mode switches it off again.
 *        READY      poll the receiver's status; leave for STANDBY when the EQ is no longer done, for STABLE when
 *                   the colour space changed; compare the timing with the saved one and leave for STANDBY on a
 *                   mode change or a "scramble abnormal" flag.
 *   3. Report: leaving READY marks the record as changed; a change of the published flags or byte 0xE asks for
 *      the record to be sent to the main processor.
 *
 * In READY only hactive, vactive and htotal are compared; vtotal and the pixel clock are read and stored but never
 * compared, so a change of the refresh rate alone does not make the link leave READY.
 */
void hdmi_tmds_run_link_state(struct port_record *rec, unsigned char port)
{
    /* 1. State at the start of the pass. */
    unsigned char phy = hdmi_is_second_port(port);
    unsigned char old_state = rec->state, old_flags = rec->published_flags, old_byte_0xe = rec->byte_0xe;
    unsigned short hactive, vactive, htotal, vtotal, pixel_clock;
    unsigned char mode_change;
    struct saved_timing saved;

    if (port > 1)
        return;
    hdmi_phy_records[phy].byte_0x6 = (rec->flags.word >> 7) & 1;

    /* 2. One step of the current state. */
    switch (rec->state) {
    case LINK_STATE_POWER_OFF:
        /* hdmi_tmds_link_flags: 1 while the receiver is powered on by this state machine. */
        if (hdmi_tmds_link_flags[port] == 1) {
            TMDS_PowerOff(phy, 0);
            hdmi_tmds_link_flags[port] = 0;
        }
        break;
    case LINK_STATE_POWER_ON:
        if (hdmi_tmds_link_flags[port] == 0) {
            TMDS_PowerOn(phy);
            hdmi_tmds_link_flags[port] = 1;
        }
        input_set_link_state(rec, LINK_STATE_STANDBY);
        break;
    case LINK_STATE_STANDBY:
        /* Wait for the EQ scan of the PHY, then set the receiver up and capture the timing. */
        if (hdmi_phy_is_eq_done(phy) == 1) {
            hdmi_reset_reg340_block(port);
            hdmi_set_reg2fd_bit3(port);
            hdmi_set_reg135_mode(port, 1);
            hdmi_set_regb5_bit2(port, 1);
            rec->htotal = hdmi_read_htotal(port);
            rec->vtotal = hdmi_read_vtotal(port);
            rec->hactive = hdmi_read_hactive(port);
            rec->vactive = hdmi_read_vactive(port);
            rec->pixel_clock = hdmi_calc_pixel_clock(port);
            hdmi_tmds_link_ticks[port] = timer_get_ticks();
            dbg_printf("\nTMDS(%d) go to LINK_STABLE\r\n", port);
            hdmi_clear_packet_seen_flags(port);
            hdmi_clear_packet_update_flags(port);
            input_set_link_state(rec, LINK_STATE_STABLE);
        }
        break;
    case LINK_STATE_STABLE:
        if (!hdmi_phy_is_eq_done(phy)) {
            input_set_link_state(rec, LINK_STATE_STANDBY);
            dbg_printf("\n1 go to LINK_STANDBY %d\n", port);
        } else if (timer_get_ticks() - hdmi_tmds_link_ticks[port] > SETTLE_TICKS) {
            /* Settled: read the colour settings and the timing again. */
            hdmi_clear_port1_double_flag(port);
            rec->flags.colour_depth = hdmi_apply_color_depth(port);
            hdmi_set_reg08_from_avi(port);
            hdmi_set_ycbcr_regs(port);
            rec->htotal = hdmi_read_htotal(port);
            rec->vtotal = hdmi_read_vtotal(port);
            rec->hactive = hdmi_read_hactive(port);
            rec->vactive = hdmi_read_vactive(port);
            rec->pixel_clock = hdmi_calc_pixel_clock(port);
            rec->colour_space = hdmi_get_color_format_code(port);
            hdmi_get_color_format_code(port);
            hdmi_update_port_status_flags(rec, port);
            if (rec->hactive == 0 || rec->vactive == 0 || rec->htotal == 0 || rec->vtotal == 0) {
                /* No usable timing: back to STANDBY, and clear eq_done so that STANDBY waits for it again. */
                input_set_link_state(rec, LINK_STATE_STANDBY);
                dbg_printf("\n3 go to LINK_STANDBY %d\n", port);
                hdmi_phy_records[phy].eq_done = 0;
            } else {
                /* Wait a little longer while hdmi_is_deep_color reports 1 (register 0x45 bits 0..2 not 4);
                   the pass ends here without the error check. */
                if (timer_get_ticks() - hdmi_tmds_link_ticks[port] <= DEEP_COLOUR_WAIT_TICKS && hdmi_is_deep_color(port) == 1)
                    break;
                /* Go to READY: clear the latched status registers 0x72/0x73/0x74/0x84 and the packet flags,
                   so the READY passes see only what arrives from now on; store the timing; leave the
                   "only guess scramble" mode. */
                hdmi_pulse_reg133_bit7(port);
                hdmi_clear_packet_status(port);
                hdmi_clear_packet_seen_flags(port);
                hdmi_clear_packet_update_flags(port);
                hdmi_save_link_timing(port);
                hdmi_set_port_mode_byte(phy, 0);
                hdmi_tmds_link_retry_counts[port] = 0;
                hdmi_rx_records[port].avi_ticks = timer_get_ticks();
                input_set_link_state(rec, LINK_STATE_READY);
                dbg_printf("\033[1;32mTMDS(%d) go to LINK_READY %d\r\n\033[m", port, rec->pixel_clock);
                dbg_printf("usLINKHtotal(%d)\r\n", rec->htotal);
                dbg_printf("usLINKVtotal(%d)\r\n", rec->vtotal);
                dbg_printf("usLINKHrtlDE(%d)\r\n", rec->hactive);
                dbg_printf("usLINKVrtlDE(%d)\r\n", rec->vactive);
                dbg_printf("usLINKClk(%d)\r\n", rec->pixel_clock);
                dbg_printf("ucClrSpace(%d)\r\n", rec->colour_space);
                dbg_printf("ucColordepth(%d)\r\n", rec->flags.colour_depth);
                dbg_printf("ucPHYStatus(%d)\r\n\r\n", rec->published_flags);
                rec->publish = 1;
                hdmi_set_regb5_bit2(port, 0);
                hdmi_set_ycbcr422_bit(port);
                hdmi_clear_shared_port_bit(port);
            }
            hdmi_eq_monitor_errors(port, 0);
        }
        /* Fallen back to STANDBY in this pass: "only guess scramble" mode (hdmi_get_port_mode_byte) is left
           when it was on; otherwise the second retry turns it on. */
        if (rec->state == LINK_STATE_STANDBY) {
            unsigned char guess_phy = phy;
            if (hdmi_get_port_mode_byte(guess_phy)) {
                dbg_printf("Port %d only guess scramble fail, back to origin flow \n", port);
                hdmi_set_port_mode_byte(guess_phy, 0);
            } else if (++hdmi_tmds_link_retry_counts[port] > 1) {
                dbg_printf("Port %d start only guess scramble \n", port);
                hdmi_set_port_mode_byte(guess_phy, 1);
                hdmi_tmds_link_retry_counts[port] = 0;
            }
        }
        break;
    case LINK_STATE_READY:
        /* The status poll sets the restart hint (record byte 0xA6) and scramble_abnormal, used below. */
        hdmi_poll_rx_status(port);
        if (!hdmi_phy_is_eq_done(phy)) {
            dbg_printf("\n go to LINK_STANDBY %d\r\n", 1);
            input_set_link_state(rec, LINK_STATE_STANDBY);
        } else if (hdmi_get_color_format_code(port) != rec->colour_space) {
            /* Colour space changed: back to STABLE, with the time stamp set SETTLE_TICKS back so that its
               settle wait ends after one more tick. */
            dbg_printf("\n go to LINK_STANDBY %d\r\n", 3);
            rec->colour_space = hdmi_get_color_format_code(port);
            input_set_link_state(rec, LINK_STATE_STABLE);
            hdmi_tmds_link_ticks[port] = timer_get_ticks() - SETTLE_TICKS;
        } else {
            /* Timing check. */
            saved.htotal = rec->htotal;
            saved.vtotal = rec->vtotal;
            saved.hactive = rec->hactive;
            saved.vactive = rec->vactive;
            hactive = hdmi_read_hactive(port);
            vactive = hdmi_read_vactive(port);
            htotal = hdmi_read_htotal(port);
            vtotal = hdmi_read_vtotal(port);
            pixel_clock = hdmi_calc_pixel_clock(port);
            mode_change = 0;
            /* A different line length is read once more after a short wait. */
            if (htotal != saved.htotal) {
                timer_delay_long_units(1);
                htotal = hdmi_read_htotal(port);
            }
            /* No mode-change test while port 1's horizontal doubling flag is set. */
            if (!hdmi_get_port1_double_flag(port)) {
                if (abs(hactive - saved.hactive) > HACTIVE_TOLERANCE) {
                    dbg_printf("HDE %d %d\r\n", hactive, saved.hactive);
                    mode_change = 1;
                }
                if (abs(vactive - saved.vactive) > VACTIVE_TOLERANCE) {
                    dbg_printf("VDE %d %d\r\n", vactive, saved.vactive);
                    mode_change = 1;
                }
                if (hactive == HACTIVE_MODE_CHANGE) {
                    dbg_print_string("usLINKHrtlDE == 0x1FFF, mode change\r");
                    mode_change = 1;
                }
                if (vactive == 0) {
                    dbg_print_string("usLINKVrtlDE == 0x0000, mode change\r");
                    mode_change = 1;
                }
                if (abs(htotal - saved.htotal) > HTOTAL_TOLERANCE) {
                    dbg_printf("Htotal %d %d\r\n", htotal, saved.htotal);
                    mode_change = 1;
                }
            }
            hdmi_update_port_status_flags(rec, port);
            /* Any difference (also below the tolerances) is stored in the record. */
            if (rec->hactive != hactive || rec->vactive != vactive || rec->htotal != htotal || rec->vtotal != vtotal) {
                rec->hactive = hactive;
                rec->vactive = vactive;
                rec->htotal = htotal;
                rec->vtotal = vtotal;
                rec->pixel_clock = pixel_clock;
                if (mode_change)
                    dbg_printf("\n ======= HDMI %d ModeChange   =======\r\n", port);
            }
            if (hdmi_rx_records[port].scramble_abnormal) {
                hdmi_rx_records[port].scramble_abnormal = 0;
                mode_change = 1;
                dbg_printf("Port %d Mode Change : scramble abnormal \n", port);
            }
            if (mode_change) {
                /* Mode change: clear eq_done so that STANDBY waits for it again. */
                dbg_printf("\n go to LINK_STANDBY %d\r\n", 4);
                hdmi_phy_records[phy].eq_done = 0;
                input_set_link_state(rec, LINK_STATE_STANDBY);
            }
        }
        if (rec->state != LINK_STATE_READY) {
            dbg_print_string("\n TMDSLinkUnstableTask\r");
            hdmi_set_port_reg5_bit4(rec, port);
        } else {
            /* Still ready: refresh the flags, clear register 5 bit 4, check the error counters. */
            hdmi_update_port_status_flags(rec, port);
            if (hdmi_reg_read8(port, HDMI_REG_5) & REG5_BIT4)
                hdmi_reg_update_bits(port, HDMI_REG_5, REG5_BIT4, 0);
            hdmi_eq_monitor_errors(port, 0);
        }
        break;
    }

    /* 3. Report what changed in this pass. */
    if (rec->state != LINK_STATE_READY && old_state == LINK_STATE_READY) {
        rec->changed = 1;
        dbg_printf("TMDS linkidx %d ucLINKStatus %d\r\n", port, rec->state);
    }
    if (rec->published_flags != old_flags || rec->byte_0xe != old_byte_0xe) {
        rec->publish = 1;
        if ((rec->published_flags & PORT_FLAGS_CHANGED_MASK) != (old_flags & PORT_FLAGS_CHANGED_MASK))
            rec->changed = 1;
        dbg_printf("TMDS linkidx %d ucPHYStatus (%02xh,%02xh)\r\n", port, rec->published_flags, rec->byte_0xe);
    }
}
