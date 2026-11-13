/* hdmi_rx21_run_link_state  (LINK_STANDBY_2)
 *
 * Run one step of the HDMI 2.1 receiver link state machine for one port.
 *   rec: port record
 *   port: port 0 or 1
 * Name basis: proven - prints 'HDMI21 RX(%d) go to LINK_READY', 'linkidx %d ucLINKStatus'; records 2/3
 *
 * Matching notes
 * --------------
 * leon2s LINK_STANDBY_2 @ 0xa006e444-0xa006e820 (988 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - STANDBY written with hdmi_rx21_input_records[port] at every use, and the cvtem_present == 1 arm as its own copy of
 *    the undoubled stores (the compiler joins the two copies);
 *  - READY written through a pointer local (rx) with the failing tests first;
 *  - hdmi_rx21_is_format_420 declared with an unsigned char result.
 */

/* Link states (byte +0 of a port record). The firmware's own texts name 3 and 5: LINK_STANDBY and LINK_READY. */
enum link_state {
    LINK_STATE_POWER_OFF = 1,
    LINK_STATE_POWER_ON  = 2,
    LINK_STATE_STANDBY   = 3,       /* 'LINK_STANDBY' */
    LINK_STATE_STABLE    = 4,
    LINK_STATE_READY     = 5        /* 'LINK_READY' */
};

#define HDMI21_PORTS            2
#define SETTLE_TICKS            200     /* the time stamp is set this far back on a colour-space change */

/* Bits of published_flags whose change also marks the port as changed (bits 3 and 6). */
#define PORT_FLAGS_CHANGED_MASK 0x48

/* Port record (20 bytes, input_port_records[2] / [3] for HDMI 2.1 ports 0 / 1). */
struct port_record {
    unsigned char state, byte_0x1;                  /* state: enum link_state */
    unsigned short htotal, vtotal, hactive, vactive, pixel_clock;  /* usLINKHtotal .. usLINKClk */
    unsigned char colour_space;                     /* +0xC: hdmi_rx21_get_colorimetry_code ('ucClrSpace') */
    unsigned char published_flags;                  /* +0xD: 'ucPHYStatus' */
    unsigned char byte_0xe;
    unsigned char publish;                          /* +0xF: 1 = send the record to the main processor */
    unsigned char changed;                          /* +0x10: 1 = send it and mark the port as changed */
    unsigned char step;                             /* +0x11: cleared by input_set_link_state */
    union {
        unsigned short word;                        /* bit 7 = flag from the main processor (input_load_port_flag_bits) */
        unsigned char colour_depth;                 /* high byte: 'ucColordepth' */
    } flags;
};

/* HDMI PHY record (24 bytes, one per PHY; PHYs 2 / 3 = the HDMI 2.1 receivers). */
struct hdmi_phy_record {
    unsigned char power, eq_done;
    unsigned char byte_0x2, byte_0x3, byte_0x4, byte_0x5;
    unsigned char byte_0x6;                         /* copy of bit 7 of the port record's flags */
    unsigned char option_byte;
    unsigned char rest_0x8[16];
};

/* HDMI 2.1 receiver record (400 bytes, hdmi_rx21_input_records); only the fields used here. */
struct rx21_record {
    unsigned char bytes_0x0[4];
    unsigned char byte_0x4;                         /* set to 1 by DRV_HDMI_ModeDetect_FSM_Complete */
    unsigned char bytes_0x5[0x1a - 5];
    unsigned short htotal, vtotal, hactive, vactive;    /* +0x1A..+0x20: the mode info's timing */
    unsigned char bytes_0x22[0x2d - 0x22];
    unsigned char cvtem_present;                    /* +0x2D: CVTEM packet seen at the last mode completion */
    unsigned char bytes_0x2e[4];
    unsigned short pixel_clock;                     /* +0x32 */
    unsigned char rest[400 - 0x34];
};

extern struct hdmi_phy_record hdmi_phy_records[];
extern struct rx21_record hdmi_rx21_input_records[];
extern unsigned char hdmi_rx21_power_flags[];
extern unsigned char hdmi_rx21_power_init_flag;
extern unsigned int hdmi_rx21_link_ticks[];

extern unsigned char hdmi_rx21_get_phy_index(unsigned char);
extern void TMDS_PowerOff(unsigned char, unsigned char);
extern void TMDS_PowerOn(unsigned char);
extern unsigned int hdmi_rx21_stop_port(unsigned int);
extern int hdmi_rx21_start_port(int);
extern unsigned char hdmi_rx21_is_format_420(unsigned int);
extern unsigned int timer_get_ticks(void);
extern unsigned char hdmi_rx21_get_colorimetry_code(unsigned char);
extern void hdmi_rx21_copy_link_timing(struct port_record *, unsigned char);
extern void input_set_link_state(struct port_record *, unsigned char);
extern void hdmi_rx21_clear_mode_change_signal(unsigned char);
extern void hdmi_rx21_update_port_status_flags(struct port_record *, unsigned int, struct rx21_record *);
extern int dbg_printf(char *, ...);

/*
 * One pass of the link state machine of an HDMI 2.1 input.
 *
 *   rec   the input's port record
 *   port  HDMI 2.1 receiver 0 or 1; any other value returns at once
 *
 * The only caller is input_run_link_tasks, every main-loop pass, with (input_port_records[2], 0) and
 * (input_port_records[3], 1). The PHY record used is hdmi_phy_records[phy], phy = 2 + port
 * (hdmi_rx21_get_phy_index). The timing comes from the receiver record hdmi_rx21_input_records[port], which the mode
 * detection fills; byte_0x4 of it is the condition of STANDBY, STABLE and READY.
 *
 * Phases of a pass:
 *   1. Remember state, published flags and byte 0xE, to report changes at the end. On the very first pass
 *      mark both receivers as powered (hdmi_rx21_power_flags). Copy the main processor's port flag (bit 7 of
 *      the flags halfword) into byte 6 of the PHY record.
 *   2. One step of the state:
 *        POWER_OFF  power the PHY off and stop the receiver port, once.
 *        POWER_ON   power the PHY on and start the receiver port, once; go to STANDBY.
 *        STANDBY    once byte_0x4 is 1: copy the timing into the port record (htotal, hactive and the pixel
 *                   clock doubled for colour format 4:2:0 unless a CVTEM packet was seen), go to STABLE.
 *        STABLE     byte_0x4 still 1: colour space and timing into the record, go to READY and ask for the
 *                   record to be sent; else back to STANDBY.
 *        READY      leave for STANDBY when byte_0x4 is no longer 1 or the colour space changed; otherwise
 *                   refresh the status flags.
 *   3. Report: leaving READY marks the record as changed; a change of the published flags or byte 0xE copies
 *      the timing again (hdmi_rx21_copy_link_timing, which asks for the record to be sent).
 *
 * This routine writes hdmi_rx21_link_ticks but does not read it.
 */
void hdmi_rx21_run_link_state(struct port_record *rec, unsigned char port)
{
    /* 1. State at the start of the pass. */
    unsigned char phy = hdmi_rx21_get_phy_index(port);
    unsigned char old_state = rec->state, old_flags = rec->published_flags, old_byte_0xe = rec->byte_0xe;
    unsigned char i;
    struct rx21_record *rx;

    if (port > 1)
        return;
    if (hdmi_rx21_power_init_flag == 0) {
        for (i = 0; i < HDMI21_PORTS; i++)
            hdmi_rx21_power_flags[i] = 1;
        hdmi_rx21_power_init_flag = 1;
    }
    hdmi_phy_records[phy].byte_0x6 = (rec->flags.word >> 7) & 1;

    /* 2. One step of the current state. */
    switch (rec->state) {
    case LINK_STATE_POWER_OFF:
        if (hdmi_rx21_power_flags[port] == 1) {
            TMDS_PowerOff(phy, 0);
            hdmi_rx21_power_flags[port] = 0;
            hdmi_rx21_stop_port(port);
        }
        break;
    case LINK_STATE_POWER_ON:
        if (hdmi_rx21_power_flags[port] == 0) {
            TMDS_PowerOn(phy);
            hdmi_rx21_power_flags[port] = 1;
            hdmi_rx21_start_port(port);
        }
        input_set_link_state(rec, LINK_STATE_STANDBY);
        break;
    case LINK_STATE_STANDBY:
        if (hdmi_rx21_input_records[port].byte_0x4 == 1) {
            /* Horizontal values are doubled for 4:2:0 (hdmi_rx21_is_format_420), except with CVTEM. */
            if (hdmi_rx21_input_records[port].cvtem_present == 1) {
                rec->htotal = hdmi_rx21_input_records[port].htotal;
                rec->hactive = hdmi_rx21_input_records[port].hactive;
                rec->pixel_clock = hdmi_rx21_input_records[port].pixel_clock / 10;
            } else if (hdmi_rx21_is_format_420(port)) {
                rec->htotal = hdmi_rx21_input_records[port].htotal * 2;
                rec->hactive = hdmi_rx21_input_records[port].hactive * 2;
                rec->pixel_clock = hdmi_rx21_input_records[port].pixel_clock / 10 * 2;
            } else {
                rec->htotal = hdmi_rx21_input_records[port].htotal;
                rec->hactive = hdmi_rx21_input_records[port].hactive;
                rec->pixel_clock = hdmi_rx21_input_records[port].pixel_clock / 10;
            }
            rec->vtotal = hdmi_rx21_input_records[port].vtotal;
            rec->vactive = hdmi_rx21_input_records[port].vactive;
            hdmi_rx21_link_ticks[port] = timer_get_ticks();
            input_set_link_state(rec, LINK_STATE_STABLE);
        }
        break;
    case LINK_STATE_STABLE:
        if (hdmi_rx21_input_records[port].byte_0x4 == 1) {
            rec->colour_space = hdmi_rx21_get_colorimetry_code(port);
            hdmi_rx21_copy_link_timing(rec, port);      /* also sets rec->publish */
            input_set_link_state(rec, LINK_STATE_READY);
            dbg_printf("HDMI21 RX(%d) go to LINK_READY\r\n", port);
            rec->publish = 1;
            hdmi_rx21_clear_mode_change_signal(port);   /* bit (4 << port) of reg_ipc_shared_hdmi_status */
        } else
            input_set_link_state(rec, LINK_STATE_STANDBY);
        break;
    case LINK_STATE_READY:
        rx = &hdmi_rx21_input_records[port];
        if (rx->byte_0x4 != 1) {
            dbg_printf("go to LINK_STANDBY\n ");
            input_set_link_state(rec, LINK_STATE_STANDBY);
        } else if (hdmi_rx21_get_colorimetry_code(port) != rec->colour_space) {
            dbg_printf("go to LINK_STANDBY\n ");
            rec->colour_space = hdmi_rx21_get_colorimetry_code(port);
            input_set_link_state(rec, LINK_STATE_STANDBY);
            hdmi_rx21_link_ticks[port] = timer_get_ticks() - SETTLE_TICKS;
        } else
            hdmi_rx21_update_port_status_flags(rec, port, rx);
        break;
    }

    /* 3. Report what changed in this pass. */
    if (rec->state != LINK_STATE_READY && old_state == LINK_STATE_READY) {
        rec->changed = 1;
        dbg_printf("linkidx %d ucLINKStatus %d\r\n", port, rec->state);
    }
    if (rec->published_flags != old_flags || rec->byte_0xe != old_byte_0xe) {
        hdmi_rx21_copy_link_timing(rec, port);
        if ((rec->published_flags & PORT_FLAGS_CHANGED_MASK) != (old_flags & PORT_FLAGS_CHANGED_MASK))
            rec->changed = 1;
        dbg_printf("linkidx %d ucPHYStatus (%02xh,%02xh)\r\n", port, rec->published_flags, rec->byte_0xe);
    }
}
