/* hdmi_poll_rx_status  (FUN_a00908d0)
 *
 * Poll the packet and status bits of a running HDMI 2.0 receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - status regs 0x72/0x73/0x74/0x84 -> InfoFrame captures; only caller
 *   hdmi_tmds_run_link_state in state 5
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00908d0 @ 0xa00908d0-0xa0090d7c (299 words; FUN_a0090d74 = unreachable ret/restore tail inside the
 * range), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - hdmi_get_port_mode_byte takes hdmi_is_second_port(port)'s result (phy), and hdmi_capture_hdr_packet takes
 *    the record itself (its packet area is at +0; the firmware leaves the record address in %o1);
 *  - unsigned char status locals; the register 0x74 and 0x84 blocks are static functions with an unsigned char
 *    port (inlined; they give the firmware's re-extensions of port at the joins);
 *  - each pair of packet flags is stored update first, then seen (the scheduler then gives the firmware's order);
 *  - in the register 0x74 block 'bit1 = status & 2' is taken before register 0x280 is read (the firmware
 *    keeps it in %l1 across the calls);
 *  - timer_stamp_older_than_50 and hdmi_status134_bit1 return unsigned char (both 0/1: subx / addx).
 * No volatile, no asm.
 */

/* Latched status registers of an HDMI 2.0 receiver. A set bit stays set until it is written back as 1. */
#define RX_STATUS_72            0x72
#define   STATUS72_RESTART_HINT   0x80    /* copied to restart_hint */
#define   STATUS72_VENDOR_PACKET  0x02    /* new packet in area 0x280 (hdmi_capture_vendor_packet) */
#define RX_STATUS_73            0x73
#define   STATUS73_RESTART_HINT   0x40    /* copied to restart_hint */
#define   STATUS73_AUDIO_INFO     0x04    /* new packet in area 0x180 (hdmi_capture_audio_infoframe) */
#define   STATUS73_SPD_INFO       0x02    /* new packet in area 0x160 (hdmi_capture_spd_packet) */
#define   STATUS73_AVI_INFO       0x01    /* new packet in area 0x140 (hdmi_capture_avi_infoframe) */
#define RX_STATUS_74            0x74
#define   STATUS74_BIT0           0x01
#define   STATUS74_BIT1           0x02
#define   STATUS74_REG137_UPDATE  0x80    /* hdmi_update_reg137_bit1 is run */
#define RX_STATUS_84            0x84
#define   STATUS84_HDR_PACKET     0x01    /* new packet in area 0x1B0 (hdmi_capture_hdr_packet) */
#define   STATUS84_BIT1           0x02
#define   STATUS84_BIT2           0x04

#define RX_REG_5                5
#define   REG5_BIT1               0x02    /* pulsed (set, cleared) for status 0x74 bits 0 and 1 */
#define RX_REG_7A               0x7A
#define RX_REG_134              0x134
#define RX_REG_1AF              0x1AF
#define RX_REG_280              0x280
#define RX_REG_281              0x281
#define   REG281_BIT4             0x10
#define RX_REG_29F              0x29F

#define BOTH_RECEIVERS          2       /* port argument of hdmi_reg_update_bits for both receivers */

/* Receiver record of an HDMI 2.0 port (0xB0 bytes, hdmi_rx_records[port]). Each packet area is followed by three
   flag bytes: seen and update are set by this poll when the packet arrives (hdmi_clear_packet_seen_flags and
   hdmi_clear_packet_update_flags clear them), and the packet is copied in only while hold is 0
   (hdmi_init_receivers sets hold to 1 for the HDR, audio and vendor areas). */
struct hdmi_rx_record {
    unsigned char hdr_packet[0x1f];             /* +0x00: copy of area 0x1B0 */
    unsigned char hdr_seen, hdr_update, hdr_hold;               /* +0x1F */
    unsigned char spd_packet[0x1f];             /* +0x22: copy of area 0x160 */
    unsigned char spd_seen, spd_update, spd_hold;               /* +0x41 */
    unsigned char avi_packet[0x13];             /* +0x44: copy of area 0x140 */
    unsigned char avi_seen, avi_update, avi_hold;               /* +0x57 */
    unsigned char audio_packet[0x0e];           /* +0x5A: copy of area 0x180 */
    unsigned char audio_seen, audio_update, audio_hold;         /* +0x68 */
    unsigned char vendor_packet[0x1f];          /* +0x6B: copy of area 0x280 */
    unsigned char vendor_seen, vendor_update, vendor_hold;      /* +0x8A */
    unsigned char bytes_0x8d[0xa6 - 0x8d];
    unsigned char restart_hint;                 /* +0xA6: read by hdmi_get_restart_hint */
    unsigned char byte_0xa7;                    /* +0xA7: 0, 1 or 2, set from register 0x84 bits 1 and 2 */
    unsigned int avi_ticks;                     /* +0xA8: time of the last AVI InfoFrame */
    unsigned char scramble_abnormal;            /* +0xAC: read and cleared by the READY state */
    unsigned char byte_0xad, byte_0xae, byte_0xaf;
};

extern struct hdmi_rx_record hdmi_rx_records[];
extern unsigned char hdmi_is_second_port(unsigned char);
extern unsigned char hdmi_get_port_mode_byte(unsigned int);
extern void hdmi_update_reg137_bit1(unsigned char);
extern unsigned char hdmi_detect_vrr_signalling(unsigned char);
extern unsigned char timer_stamp_older_than_50(unsigned int t0);
extern unsigned char hdmi_status134_bit1(unsigned char);
extern void hdmi_capture_vendor_packet(unsigned char, unsigned char *);
extern void hdmi_capture_spd_packet(unsigned char, unsigned char *);
extern void hdmi_capture_hdr_packet(unsigned char, unsigned char *);
extern void hdmi_capture_audio_infoframe(unsigned char, unsigned char *);
extern int hdmi_capture_avi_infoframe(unsigned char, unsigned char *);
extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);
extern void hdmi_reg_write8(unsigned int, unsigned short, unsigned int);
extern void hdmi_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern void timer_delay_long_units(int);
extern unsigned int timer_get_ticks(void);

/* Status register 0x74: when registers 0x280 and 0x281 both read nonzero, bits 0 and 1 each pulse register 5
   bit 1; bit 7 runs hdmi_update_reg137_bit1. */
static void poll_status_74(unsigned char port)
{
    unsigned int bit1; unsigned char status;
    status = hdmi_reg_read8(port, RX_STATUS_74);
    if (status != 0) {
        bit1 = status & STATUS74_BIT1;
        if (hdmi_reg_read8(port, RX_REG_280) & 0xff) {
            if (hdmi_reg_read8(port, RX_REG_281) & 0xff) {
                if (status & STATUS74_BIT0) {
                    hdmi_reg_update_bits(port, RX_REG_5, REG5_BIT1, 1);
                    hdmi_reg_update_bits(port, RX_REG_5, REG5_BIT1, 0);
                    timer_delay_long_units(5);
                }
                if (bit1) {
                    hdmi_reg_update_bits(port, RX_REG_5, REG5_BIT1, 1);
                    hdmi_reg_update_bits(port, RX_REG_5, REG5_BIT1, 0);
                    timer_delay_long_units(5);
                }
            }
        }
        if (status & STATUS74_REG137_UPDATE)
            hdmi_update_reg137_bit1(port);
        hdmi_reg_write8(port, RX_STATUS_74, status);       /* acknowledge every bit read */
    }
}

/* Status register 0x84: the HDR InfoFrame and byte_0xa7. */
static void poll_status_84(unsigned char port)
{
    unsigned char status;
    status = hdmi_reg_read8(port, RX_STATUS_84);
    if (status != 0) {
        if (status & STATUS84_HDR_PACKET) {
            hdmi_rx_records[port].hdr_update = 1;
            hdmi_rx_records[port].hdr_seen = 1;
            if (hdmi_rx_records[port].hdr_hold == 0)
                hdmi_capture_hdr_packet(port, hdmi_rx_records[port].hdr_packet);
        } else {
            /* Unlike the other packets, the HDR flags are cleared when the bit is not set. */
            hdmi_rx_records[port].hdr_update = 0;
            hdmi_rx_records[port].hdr_seen = 0;
        }
        /* byte_0xa7: 0 unless register 0x29F reads 2; then, when bit 1 is set, register 0x281 bit 4.
           Register 0x1AF reading 9 together with bit 2 makes it 2. */
        if ((hdmi_reg_read8(port, RX_REG_29F) & 0xff) == 2) {
            if (status & STATUS84_BIT1) {
                if (hdmi_reg_read8(port, RX_REG_281) & REG281_BIT4)
                    hdmi_rx_records[port].byte_0xa7 = 1;
                else
                    hdmi_rx_records[port].byte_0xa7 = 0;
            }
        } else {
            hdmi_rx_records[port].byte_0xa7 = 0;
        }
        if ((hdmi_reg_read8(port, RX_REG_1AF) & 0xff) == 9 && (status & STATUS84_BIT2))
            hdmi_rx_records[port].byte_0xa7 = 2;
        hdmi_reg_write8(port, RX_STATUS_84, status);       /* acknowledge every bit read */
    }
}

/*
 * One status poll of an HDMI 2.0 receiver whose link is up.
 *
 *   port  HDMI 2.0 receiver 0 or 1
 *
 * The only caller is hdmi_tmds_run_link_state, once per pass in LINK_READY (state 5). The step into LINK_READY
 * clears the four status registers (hdmi_clear_packet_status), so a set bit here arrived after that.
 *
 * Phases:
 *   1. restart_hint is cleared, then set when status 0x72 bit 7 or status 0x73 bit 6 is set; it is therefore 1
 *      only in a pass that saw one of them. hdmi_update_port_status_flags copies it to bit 6 of the port
 *      record's byte 0xE.
 *   2. Status 0x72 bit 1 and status 0x73 bits 2, 1, 0: for each new packet the seen and update flags are set and
 *      the packet is copied into the record (vendor packet, audio InfoFrame, SPD InfoFrame, AVI InfoFrame).
 *      The SPD InfoFrame is taken only when hdmi_detect_vrr_signalling reports no flags. Each bit handled is
 *      written back.
 *   3. AVI time-out: when no AVI InfoFrame arrived in this pass, the port is in "only guess scramble" mode
 *      (hdmi_get_port_mode_byte), more than 50 ticks have passed since the last one and status register 0x134
 *      bit 1 is set, scramble_abnormal is set; the READY state then treats it as a mode change.
 *   4. Status 0x74 and status 0x84 (poll_status_74, poll_status_84).
 */
void hdmi_poll_rx_status(unsigned char port)
{
    unsigned char phy;
    unsigned char status;

    phy = hdmi_is_second_port(port);

    /* 1. + 2. Status register 0x72. */
    hdmi_rx_records[port].restart_hint = 0;

    status = hdmi_reg_read8(port, RX_STATUS_72);
    if (status != 0) {
        if (status & STATUS72_RESTART_HINT) {
            hdmi_rx_records[port].restart_hint = 1;
            hdmi_reg_write8(port, RX_STATUS_72, STATUS72_RESTART_HINT);
        }
        if (status & STATUS72_VENDOR_PACKET) {
            hdmi_rx_records[port].vendor_update = 1;
            hdmi_rx_records[port].vendor_seen = 1;
            if (hdmi_rx_records[port].vendor_hold == 0)
                hdmi_capture_vendor_packet(port, &hdmi_rx_records[port].vendor_packet[0]);
            hdmi_reg_write8(port, RX_STATUS_72, STATUS72_VENDOR_PACKET);
        }
    }

    /* 1. + 2. Status register 0x73. */
    status = hdmi_reg_read8(port, RX_STATUS_73);
    if (status & STATUS73_RESTART_HINT) {
        hdmi_rx_records[port].restart_hint = 1;
        hdmi_reg_write8(port, RX_STATUS_73, STATUS73_RESTART_HINT);
    }
    if (status & STATUS73_AUDIO_INFO) {
        hdmi_rx_records[port].audio_update = 1;
        hdmi_rx_records[port].audio_seen = 1;
        if (hdmi_rx_records[port].audio_hold == 0)
            hdmi_capture_audio_infoframe(port, &hdmi_rx_records[port].audio_packet[0]);
        hdmi_reg_write8(port, RX_STATUS_73, STATUS73_AUDIO_INFO);
        /* Register 0x7A bit 2 is cleared on both receivers. */
        hdmi_reg_update_bits(BOTH_RECEIVERS, RX_REG_7A, STATUS73_AUDIO_INFO, 0);
    }
    if (status & STATUS73_SPD_INFO) {
        if (hdmi_detect_vrr_signalling(port) == 0) {
            hdmi_rx_records[port].spd_update = 1;
            hdmi_rx_records[port].spd_seen = 1;
            if (hdmi_rx_records[port].spd_hold == 0)
                hdmi_capture_spd_packet(port, &hdmi_rx_records[port].spd_packet[0]);
        }
        hdmi_reg_write8(port, RX_STATUS_73, STATUS73_SPD_INFO);
        /* Register 0x7A bit 1 is cleared on both receivers. */
        hdmi_reg_update_bits(BOTH_RECEIVERS, RX_REG_7A, STATUS73_SPD_INFO, 0);
    }
    if (status & STATUS73_AVI_INFO) {
        hdmi_rx_records[port].avi_update = 1;
        hdmi_rx_records[port].avi_seen = 1;
        if (hdmi_rx_records[port].avi_hold == 0)
            hdmi_capture_avi_infoframe(port, &hdmi_rx_records[port].avi_packet[0]);
        hdmi_reg_write8(port, RX_STATUS_73, STATUS73_AVI_INFO);
        hdmi_rx_records[port].avi_ticks = timer_get_ticks();
    } else if (hdmi_get_port_mode_byte(phy)) {
        /* 3. No AVI InfoFrame in "only guess scramble" mode. */
        if (timer_stamp_older_than_50(hdmi_rx_records[port].avi_ticks))
            if (hdmi_status134_bit1(port))
                hdmi_rx_records[port].scramble_abnormal = 1;
    }

    /* 4. */
    poll_status_74(port);
    poll_status_84(port);
}
