/* hdmi_rx21_update_frl_rate  (TxFFE_Max_L)
 *
 * Take over a new FRL rate request of the source and restart the LTP timer.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: derived - prints 'Upadte FRL_Rate = %d, TxFFE_Max_L = %d' and 'LTP Time start' (TxFFE_Max_L is a
 *   variable)
 *
 * Matching notes
 * --------------
 * leon2s TxFFE_Max_L @ 0xa0098468-0xa009860c, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the first part is a static helper (inlined) that reaches the link-training records through a constant
 *    pointer (the firmware keeps the whole address in a register there);
 *  - the helper reads lane_count into an unsigned int before the txffe_max store and copies it to an unsigned
 *    short loop limit;
 *  - the main part narrows the parameter with a cast at every use.
 */

#define HDMI_MSG_HDMI21         0x800   /* dbg_hdmi_message_flags bit 11: the "[HDMI21]" lines */

/* Block 6 register B6_LTS_STATUS (byte offset): the rate and TxFFE level the source asks for. */
#define B6_LTS_STATUS           0x90
#define LTS_STATUS_FRL_RATE     0x0f000000  /* bits 24..27 */
#define LTS_STATUS_RATE_SHIFT   24
#define LTS_STATUS_TXFFE_SHIFT  28          /* bits 28..31: TxFFE_Max_L */

#define PHY_REG_1F0C            0x1f0c
#define REG_1F0C_KEEP_HIGH      0xfffffff0  /* the FRL rate goes into bits 0..3 */

/* Bit numbers in block 3 register 0x60: hdmi_scdc_scrambling_enabled reads bit 8, hdmi_scdc_bit_ratio_40 bit 9. */
#define B3_REG_60               0x60
#define B3_SCRAMBLING_BIT       8
#define B3_BIT_RATIO_40_BIT     9

/* Bytes of the link-training record of a receiver (0xB0 bytes, hdmi_rx21_lts_records). */
#define LTS_RECORD_ADDRESS      0xa807d680
#define LTS_RECORD_SIZE         0xb0
#define LTS_LANE_COUNT          0       /* 0, 3 or 4, set here from the FRL rate */
#define LTS_FRL_RATE            1
#define LTS_TXFFE               0xf     /* TxFFE level of each lane ("TxFFE[%d]") */
#define LTS_TXFFE_MAX           0x13    /* "TxFFE_Max_L" */

/* Register block addresses of an HDMI 2.1 receiver (13 words, hdmi_rx21_reg_blocks). */
struct hdmi_rx21_reg_blocks {
    unsigned int block0;
    unsigned int block1;
    unsigned int block2;
    unsigned int block3;                /* +0xC */
    unsigned char blocks_4_to_5[8];
    volatile unsigned int *block6;      /* +0x18 */
    unsigned char blocks_7_to_12[0x34 - 0x1c];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_rx21_lts_records[][LTS_RECORD_SIZE];
extern unsigned int hdmi_rx21_ltp_timer_ticks[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern unsigned int dbg_print_string(const char *);
extern unsigned int timer_get_ticks(void);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void reg_clear_bit(unsigned int, unsigned int);

/* When the requested FRL rate differs from the stored one: restart the LTP timer, store the rate (also in
   PHY register 0x1F0C) and TxFFE_Max_L, and clear the TxFFE levels of the lanes in use so far. */
static void take_over_rate(unsigned char port)
{
    struct hdmi_rx21_reg_blocks *blocks = ARR_a807db00;
    struct hdmi_rx21_reg_blocks *rx = blocks + port;
    unsigned char (*lts_records)[LTS_RECORD_SIZE] = ((unsigned char (*)[LTS_RECORD_SIZE])LTS_RECORD_ADDRESS);
    unsigned char *record = lts_records[port];
    unsigned char lane;
    unsigned short lanes_used;
    unsigned int old_lane_count;

    if (record[LTS_FRL_RATE] != (rx->block6[B6_LTS_STATUS / 4] & LTS_STATUS_FRL_RATE) >> LTS_STATUS_RATE_SHIFT) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_print_string("[HDMI21]: LTP Time start\n");
        hdmi_rx21_ltp_timer_ticks[port] = timer_get_ticks();
        record[LTS_FRL_RATE] = (rx->block6[B6_LTS_STATUS / 4] & LTS_STATUS_FRL_RATE) >> LTS_STATUS_RATE_SHIFT;
        /* The PHY argument is the receiver number 0 / 1. */
        hdmi_phy_update_reg(port, PHY_REG_1F0C, REG_1F0C_KEEP_HIGH, record[LTS_FRL_RATE]);
        old_lane_count = lts_records[port][LTS_LANE_COUNT];
        record[LTS_TXFFE_MAX] = rx->block6[B6_LTS_STATUS / 4] >> LTS_STATUS_TXFFE_SHIFT;
        lanes_used = old_lane_count;
        for (lane = 0; lane < lanes_used; lane++)
            lts_records[port][LTS_TXFFE + lane] = 0;
    }
}

/*
 * Take over the FRL rate and TxFFE_Max_L that the source of an HDMI 2.1 receiver requests (block 6
 * register B6_LTS_STATUS) and set the lane count for it.
 *
 *   port  HDMI 2.1 receiver 0 or 1
 *
 * Called by DRV_HDMI21_RXDetect_FSM_LTS_3 and DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err.
 *
 * A changed rate restarts the LTP timer (hdmi_rx21_ltp_timer_ticks, "LTP Time start") and clears the TxFFE
 * levels (take_over_rate). Then, on every call, the lane count follows the stored rate: rate 0 no lanes,
 * rates 1 and 2 three lanes, higher rates four lanes; with any rate other than 0 the bits that
 * hdmi_scdc_scrambling_enabled and hdmi_scdc_bit_ratio_40 read are cleared.
 */
void hdmi_rx21_update_frl_rate(unsigned int port)
{
    take_over_rate(port);
    if (hdmi_rx21_lts_records[(unsigned char)port][LTS_FRL_RATE] == 0)
        hdmi_rx21_lts_records[(unsigned char)port][LTS_LANE_COUNT] = 0;
    else if ((unsigned char)(hdmi_rx21_lts_records[(unsigned char)port][LTS_FRL_RATE] - 1) <= 1) {
        hdmi_rx21_lts_records[(unsigned char)port][LTS_LANE_COUNT] = 3;
        reg_clear_bit(B3_SCRAMBLING_BIT, ARR_a807db00[(unsigned char)port].block3 + B3_REG_60);
        reg_clear_bit(B3_BIT_RATIO_40_BIT, ARR_a807db00[(unsigned char)port].block3 + B3_REG_60);
    } else {
        hdmi_rx21_lts_records[(unsigned char)port][LTS_LANE_COUNT] = 4;
        reg_clear_bit(B3_SCRAMBLING_BIT, ARR_a807db00[(unsigned char)port].block3 + B3_REG_60);
        reg_clear_bit(B3_BIT_RATIO_40_BIT, ARR_a807db00[(unsigned char)port].block3 + B3_REG_60);
    }
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: Upadte FRL_Rate = %d, TxFFE_Max_L = %d\n", hdmi_rx21_lts_records[(unsigned char)port][LTS_FRL_RATE], hdmi_rx21_lts_records[(unsigned char)port][LTS_TXFFE_MAX]);
}
