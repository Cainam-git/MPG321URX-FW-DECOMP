/* DRV_HDMI21_LTS_STS_InitialSettings  (DRV_HDMI21_LTS_STS_InitialSettings)
 *
 * Clear the link training record and set the start-up PHY registers of an HDMI 2.1 receiver.
 *   port_arg: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed ('%s, PortID = %d'); caller hdmi_rx21_init_port
 *
 * Matching notes
 * --------------
 * DRV_HDMI21_LTS_STS_InitialSettings (leon2s 0xa009b5f4-0xa009bba8, 1460 bytes), flags -mcpu=v8 -Os -g (section
 * default).
 * Source forms the exact build depends on:
 *  - everything after the print is the static inline helper reset_record_and_phy(port, phy); its parameter
 *    copy is the firmware's 'mov %l4,%i0' before the lane loop (the record clears and the loop set-up use the
 *    caller's %l4, every later use the copy in %i0);
 *  - the lane halfwords are elements 2 * lane and 2 * lane + 1 of an unsigned short array at +0x1A, so the
 *    scheduler sees them as a different field from the byte arrays;
 *  - store order: in the lane loop +7, +0xB, +0xF, +3, then the two halfwords; after the loop bytes
 *    +0x13..+0x39, then hdmi_rx21_ltp_timer_ticks and hdmi_rx21_ltp_end_ticks;
 *  - hdmi_phy_update_reg takes an unsigned char first parameter.
 */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines (no name in the group list) */

/* PHY index of each HDMI 2.1 receiver (as hdmi_rx21_get_phy_index). */
#define PHY_RX21_0 2
#define PHY_RX21_1 3

/* PHY registers. Per-lane registers repeat on the pages 0x2000, 0x2400, 0x2800 and 0x3000 (lanes 0..3, as
   the lane register lists hdmi_rx21_lane_regs_*); the other registers written here exist once. */
#define PHY_LANE0  0x2000
#define PHY_LANE1  0x2400
#define PHY_LANE2  0x2800
#define PHY_LANE3  0x3000
#define PHY_REG_2E60 0x2e60             /* bits 24..27 read as the lane lock bits by the training checks */

#define BIT_CLEAR 0                     /* first argument of hdmi_phy_write_bit */
#define BIT_SET   1

/* Link training record of an HDMI 2.1 receiver (0xB0 bytes each, table at 0xA807D680). */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0: 0, 3 or 4, set from the FRL rate by hdmi_rx21_update_frl_rate */
    unsigned char frl_rate;             /* +1: FRL rate taken over by hdmi_rx21_update_frl_rate */
    unsigned char frl_rate_in_phy;      /* +2: FRL rate the PHY is set for ("u8FRL_Rate_SetInPhy") */
    unsigned char lane_bytes_0x3[4];    /* +3: start value hdmi_rx21_lts_lane_start */
    unsigned char lane_bytes_0x7[4];
    unsigned char lane_bytes_0xb[4];
    unsigned char txffe[4];             /* +0xF: TxFFE level of each lane ("TxFFE[%d]") */
    unsigned char txffe_max;            /* +0x13: "TxFFE_Max_L" */
    unsigned char byte_0x14;
    unsigned char pad_0x15[0x1a - 0x15];
    unsigned short scdc_error_counts[8];/* +0x1A: two per lane, [2 * lane + 0 / 1] */
    unsigned char lane_lock_fails;      /* +0x2A: counted by the stable check */
    unsigned char scdc_lock_fails;      /* +0x2B: counted by the SCDC error check */
    unsigned char pad_0x2c[4];
    unsigned int last_state;            /* +0x30: rx-detect state seen at the last pass */
    unsigned char byte_0x34;            /* set to (frl_rate >= 4) by the error check */
    unsigned char byte_0x35;
    unsigned char byte_0x36;
    unsigned char byte_0x37;
    unsigned char byte_0x38;
    unsigned char byte_0x39;
    unsigned char pad_0x3a[0xb0 - 0x3a];
};

/* Register block addresses of an HDMI 2.1 receiver (13 words, table at 0xA807DB00), filled by
   hdmi_rx21_init_register_pointers: block k at 0xCE009000 + k * 0x100, plus 0x1000 for receiver 1. */
struct hdmi_rx21_reg_blocks {
    unsigned int block0;                /* +0x00: 0xCE009000 */
    unsigned int block1_2[2];
    unsigned int block3;                /* +0x0C: 0xCE009300 */
    unsigned int block4_5[2];
    unsigned int block6;                /* +0x18: 0xCE009600 */
    unsigned char block7_12[0x34 - 0x1c];
};
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char hdmi_rx21_lts_lane_start;
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned int hdmi_rx21_ltp_end_ticks[];
extern unsigned int hdmi_rx21_ltp_timer_ticks[];
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern int dbg_printf(const char *, ...);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned char, unsigned short, unsigned int, unsigned int);
extern void reg_set_bit(unsigned int, int);
extern void reg_clear_bit(unsigned int, int);
extern void hdmi_rx21_reset_lane_setting(unsigned char);
extern void hdmi_phy_clear_ctrl_bits(unsigned char);

/*
 * The work of DRV_HDMI21_LTS_STS_InitialSettings after its print.
 *
 * Phases:
 *  1. Clear the link training record: the rates, the lane count, the per-lane bytes (lane_bytes_0x3 gets
 *     hdmi_rx21_lts_lane_start), the TxFFE levels, the SCDC error counts and the fail counters; clear the
 *     two time stamps.
 *  2. PHY lane registers: clear bit 3 of reg 0x70 and bits 20..21 of reg 0x60 on all four lanes, and bit 17
 *     of reg 0x28 (lane 0 also bit 24).
 *  3. Single PHY registers 0x2C20..0x2C38 and 0x3534: fixed bits and fields.
 *  4. PHY lane registers again: reg 0x60 bits 22..23 = 2, reg 0x68 bits 16..23 = 0x13 on all four lanes;
 *     regs 0x3608 / 0x3618: fixed bits, bits 24..26 of 0x3618 = 3.
 *  5. Receiver register blocks 0, 3 and 6: set bit 21 of block 0 word +4, clear bits 0..2 of block 3
 *     word +0x60, bits 3..7 of block 6 word +0x80 and bit 17 of block 6 word +0x90.
 *  6. Lane byte settings to their default (hdmi_rx21_reset_lane_setting), clear bits 0..1 of PHY reg
 *     0x3600 (hdmi_phy_clear_ctrl_bits), then clear bit 11 of block 0 word +8, bit 13 of block 6 word 0,
 *     bit 20 of PHY reg 0x2E60 and bit 11 of block 3 word +0x7C.
 * Values whose meaning the code does not show are written as numbers.
 */
static inline void reset_record_and_phy(unsigned char port, int phy)
{
    unsigned char lane;

    /* 1. The link training record. */
    hdmi_rx21_lts_records[port].frl_rate = 0;
    hdmi_rx21_lts_records[port].frl_rate_in_phy = 0;
    hdmi_rx21_lts_records[port].byte_0x14 = 0;
    hdmi_rx21_lts_records[port].lane_count = 0;
    lane = 0;
    do {
        hdmi_rx21_lts_records[port].lane_bytes_0x7[lane] = 0;
        hdmi_rx21_lts_records[port].lane_bytes_0xb[lane] = 0;
        hdmi_rx21_lts_records[port].txffe[lane] = 0;
        hdmi_rx21_lts_records[port].lane_bytes_0x3[lane] = hdmi_rx21_lts_lane_start;
        hdmi_rx21_lts_records[port].scdc_error_counts[lane * 2] = 0;
        hdmi_rx21_lts_records[port].scdc_error_counts[lane * 2 + 1] = 0;
        lane++;
    } while (lane < 4);
    hdmi_rx21_lts_records[port].txffe_max = 0;
    hdmi_rx21_lts_records[port].lane_lock_fails = 0;
    hdmi_rx21_lts_records[port].scdc_lock_fails = 0;
    hdmi_rx21_lts_records[port].byte_0x34 = 0;
    hdmi_rx21_lts_records[port].byte_0x35 = 0;
    hdmi_rx21_lts_records[port].byte_0x36 = 0;
    hdmi_rx21_lts_records[port].byte_0x37 = 0;
    hdmi_rx21_lts_records[port].byte_0x38 = 0;
    hdmi_rx21_lts_records[port].byte_0x39 = 0;
    hdmi_rx21_ltp_timer_ticks[port] = 0;
    hdmi_rx21_ltp_end_ticks[port] = 0;

    /* 2. Per-lane PHY registers. */
    hdmi_phy_write_bit(BIT_CLEAR, 3, phy, PHY_LANE0 + 0x70);
    hdmi_phy_write_bit(BIT_CLEAR, 3, phy, PHY_LANE1 + 0x70);
    hdmi_phy_write_bit(BIT_CLEAR, 3, phy, PHY_LANE2 + 0x70);
    hdmi_phy_write_bit(BIT_CLEAR, 3, phy, PHY_LANE3 + 0x70);
    hdmi_phy_update_reg(phy, PHY_LANE0 + 0x60, 0xffcfffff, 0);
    hdmi_phy_update_reg(phy, PHY_LANE1 + 0x60, 0xffcfffff, 0);
    hdmi_phy_update_reg(phy, PHY_LANE2 + 0x60, 0xffcfffff, 0);
    hdmi_phy_update_reg(phy, PHY_LANE3 + 0x60, 0xffcfffff, 0);
    hdmi_phy_write_bit(BIT_CLEAR, 0x18, phy, PHY_LANE0 + 0x28);
    hdmi_phy_write_bit(BIT_CLEAR, 0x11, phy, PHY_LANE0 + 0x28);
    hdmi_phy_write_bit(BIT_CLEAR, 0x11, phy, PHY_LANE1 + 0x28);
    hdmi_phy_write_bit(BIT_CLEAR, 0x11, phy, PHY_LANE2 + 0x28);
    hdmi_phy_write_bit(BIT_CLEAR, 0x11, phy, PHY_LANE3 + 0x28);

    /* 3. Single PHY registers. */
    hdmi_phy_write_bit(BIT_CLEAR, 0x13, phy, 0x2c34);
    hdmi_phy_write_bit(BIT_SET, 0x19, phy, 0x2c34);
    hdmi_phy_write_bit(BIT_CLEAR, 0x10, phy, 0x2c34);
    hdmi_phy_write_bit(BIT_CLEAR, 0x11, phy, 0x2c34);
    hdmi_phy_write_bit(BIT_CLEAR, 0x12, phy, 0x2c34);
    hdmi_phy_update_reg(phy, 0x2c30, 0xfff0ffff, 0xb0000);
    hdmi_phy_update_reg(phy, 0x2c30, 0xff0fffff, 0x400000);
    hdmi_phy_update_reg(phy, 0x2c30, 0xf0ffffff, 0xd000000);
    hdmi_phy_update_reg(phy, 0x2c30, 0x0fffffff, 0x20000000);
    hdmi_phy_write_bit(BIT_CLEAR, 0, phy, 0x2c30);
    hdmi_phy_update_reg(phy, 0x2c34, 0xff1fffff, 0xc00000);
    hdmi_phy_update_reg(phy, 0x2c38, 0xfffff1ff, 0);
    hdmi_phy_update_reg(phy, 0x2c34, 0xfffff3ff, 0);
    hdmi_phy_write_bit(BIT_CLEAR, 0x12, phy, 0x2c34);
    hdmi_phy_update_reg(phy, 0x2c24, 0xfcffffff, 0);
    hdmi_phy_write_bit(BIT_CLEAR, 5, phy, 0x2c20);
    hdmi_phy_write_bit(BIT_CLEAR, 4, phy, 0x2c20);
    hdmi_phy_update_reg(phy, 0x3534, 0xffff00ff, 0x4000);

    /* 4. Per-lane PHY registers again, then 0x3608 / 0x3618. */
    hdmi_phy_update_reg(phy, PHY_LANE0 + 0x60, 0xff3fffff, 0x800000);
    hdmi_phy_update_reg(phy, PHY_LANE1 + 0x60, 0xff3fffff, 0x800000);
    hdmi_phy_update_reg(phy, PHY_LANE2 + 0x60, 0xff3fffff, 0x800000);
    hdmi_phy_update_reg(phy, PHY_LANE3 + 0x60, 0xff3fffff, 0x800000);
    hdmi_phy_update_reg(phy, PHY_LANE0 + 0x68, 0xff00ffff, 0x130000);
    hdmi_phy_update_reg(phy, PHY_LANE1 + 0x68, 0xff00ffff, 0x130000);
    hdmi_phy_update_reg(phy, PHY_LANE2 + 0x68, 0xff00ffff, 0x130000);
    hdmi_phy_update_reg(phy, PHY_LANE3 + 0x68, 0xff00ffff, 0x130000);
    hdmi_phy_write_bit(BIT_CLEAR, 4, phy, 0x3608);
    hdmi_phy_write_bit(BIT_CLEAR, 0x1d, phy, 0x3618);
    hdmi_phy_write_bit(BIT_SET, 0x1c, phy, 0x3618);
    hdmi_phy_update_reg(phy, 0x3618, 0xf8ffffff, 0x3000000);

    /* 5. Receiver register blocks (addresses + byte offset). */
    reg_set_bit(0x15, ARR_a807db00[port].block0 + 4);
    reg_clear_bit(0, ARR_a807db00[port].block3 + 0x60);
    reg_clear_bit(1, ARR_a807db00[port].block3 + 0x60);
    reg_clear_bit(2, ARR_a807db00[port].block3 + 0x60);
    reg_clear_bit(3, ARR_a807db00[port].block6 + 0x80);
    reg_clear_bit(4, ARR_a807db00[port].block6 + 0x80);
    reg_clear_bit(5, ARR_a807db00[port].block6 + 0x80);
    reg_clear_bit(6, ARR_a807db00[port].block6 + 0x80);
    reg_clear_bit(7, ARR_a807db00[port].block6 + 0x80);
    reg_clear_bit(0x11, ARR_a807db00[port].block6 + 0x90);

    /* 6. Lane defaults and the last control bits. */
    hdmi_rx21_reset_lane_setting(phy);
    hdmi_phy_clear_ctrl_bits(phy);
    reg_clear_bit(0xb, ARR_a807db00[port].block0 + 8);
    reg_clear_bit(0xd, ARR_a807db00[port].block6);
    hdmi_phy_write_bit(BIT_CLEAR, 0x14, phy, PHY_REG_2E60);
    reg_clear_bit(0xb, ARR_a807db00[port].block3 + 0x7c);
}

/*
 * Put the link training of an HDMI 2.1 receiver back to its start: clear its link training record and
 * write the start-up values of its PHY and receiver registers.
 *
 *   port_arg  HDMI 2.1 receiver 0/1 (any other value returns at once)
 *
 * Called by hdmi_rx21_init_port (INIT_handler). The phases are listed above reset_record_and_phy.
 */
void DRV_HDMI21_LTS_STS_InitialSettings(unsigned int port_arg)
{
    unsigned int port;
    int phy;

    port = port_arg & 0xff;
    if (port == 0)
        phy = PHY_RX21_0;
    else if (port == 1)
        phy = PHY_RX21_1;
    else
        return;
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: \033[36;1m%s, PortID = %d\n\033[m", "DRV_HDMI21_LTS_STS_InitialSettings", port);
    reset_record_and_phy(port, phy);
}
