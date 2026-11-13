/* DPTX_SetBrilliantMode  (DPTX_SetBrilliantMode)
 *
 * Recompute the DP output pacing registers when clock, depth or lanes change.
 *   port: DP output 0..4
 * Name basis: proven - original name printed ('Start DPTX_SetBrilliantMode'); writes regs 0x7E, 0x7C, 0x7B
 *   from clk, bpp, lanes
 *
 * Matching notes
 * --------------
 * DPTX_SetBrilliantMode (leon2s 0xa0089a38-0xa0089d38), flags -mcpu=v8 -Os -g.
 * Source form: one unsigned int temporary `value` for the register 0x66 read and both computed values; the pixel
 * clock distance as nested ifs (a combined test folds to one unsigned range check); the divisor is unsigned short.
 */
/* 8-byte pacing record of one DP output (dp_tx_pacing_records). */
struct pacing_record {
    unsigned char enabled;              /* 0: this output is skipped */
    unsigned char updated;              /* set to 1 after the registers were written */
    unsigned short updated_ticks;       /* timer_get_ticks() at that moment */
    unsigned int word_0x04;
};
extern struct pacing_record dp_tx_pacing_records[];
extern unsigned int dp_tx_pacing_clocks[];
extern unsigned char dp_tx_pacing_depths[];
extern unsigned char dp_tx_pacing_lane_counts[];
extern int dbg_printf(const char *, ...);
extern unsigned int dp_tx_calc_pixel_clock(unsigned char);
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);
extern void dp_tx_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned char sys_get_chip_revision(void);
extern void dp_tx_reg_update_bits(unsigned int, short, unsigned int, unsigned int);
extern unsigned int timer_get_ticks(void);

/* Registers of the DP transmitter used here. */
#define TX_REG_LINK_RATE     2          /* link rate code: 6, 0xa, 0x14 or 0x1e */
#define TX_REG_LANE_COUNT    3          /* low nibble: lane count */
#define TX_REG_COLOR_DEPTH   0x66       /* bits 5..7: 0 = 0x12 bits per pixel, 2 = 0x1e, else 0x18 */
#define TX_REG_PACE_A        0x7e       /* written from clock * depth * lanes / divisor */
#define TX_REG_PACE_B        0x7c       /* written from divisor * lanes / clock */
#define TX_REG_PACE_C        0x7b

/*
 * Recompute the three pacing registers of a DP output (0x7e, 0x7c, 0x7b) from its pixel clock, bits per pixel
 * and lane count, but only when one of them has changed.
 *
 *   port  DP output 0..4
 *
 * Called from dp_tx_run_output_tasks for every output whose update was requested.
 *
 * Does nothing when the output's pacing record is not enabled or when no pixel clock can be computed. A clock
 * within 2 of the stored one, with the same depth and lane count, also counts as unchanged. Otherwise the three
 * values are stored, printed, and the registers are written: the divisor comes from the link rate register
 * (6: 0xa2, 0xa: 0x10e, 0x1e: 0x32a, anything else 0x21c). Register 0x7b gets 0x12 for a clock above 0x2bb at
 * divisor 0x21c; otherwise 0x20 when bits 0..5 of register 0x7e (as just written) are above 0x10, else those bits plus one, times 2.
 */
void DPTX_SetBrilliantMode(unsigned char port)
{
    unsigned int clk;
    unsigned char lanes;
    unsigned char bpp;
    unsigned short divisor;
    int clk_diff;
    unsigned int value;

    if (dp_tx_pacing_records[port].enabled == 0)
        return;
    clk = dp_tx_calc_pixel_clock(port);
    lanes = dp_tx_reg_read8(port, TX_REG_LANE_COUNT) & 0xf;
    value = dp_tx_reg_read8(port, TX_REG_COLOR_DEPTH) & 0xe0;
    bpp = 0x1e;
    if (value != 0x40)
        bpp = value == 0 ? 0x12 : 0x18;
    if (clk == 0)
        return;
    clk_diff = dp_tx_pacing_clocks[port] - clk;
    if (clk_diff >= -2) {
        if (clk_diff <= 2) {
            if (dp_tx_pacing_depths[port] == bpp && dp_tx_pacing_lane_counts[port] == lanes)
                return;
        }
    }
    dp_tx_pacing_clocks[port] = clk;
    dp_tx_pacing_depths[port] = bpp;
    dp_tx_pacing_lane_counts[port] = lanes;
    dbg_printf("\r\n Start DPTX_SetBrilliantMode %d  = %ld\r\n", port, clk);
    dbg_printf("ucbpp  = %d\r\n", bpp);
    dbg_printf("uclanecount  = %d\r\n", lanes);
    switch (dp_tx_reg_read8(port, TX_REG_LINK_RATE)) {
    case 6:
        divisor = 0xa2;
        break;
    case 0xa:
        divisor = 0x10e;
        break;
    case 0x14:
        divisor = 0x21c;
        break;
    case 0x1e:
        divisor = 0x32a;
        break;
    default:
        divisor = 0x21c;
        break;
    }
    dbg_printf("\r\nDPTX_SetBrilliantMode  = %ld\r\n", clk);
    value = ((clk * bpp >> 5) * lanes * 8 / divisor >> 1) + 1;
    dp_tx_reg_write8(port, TX_REG_PACE_A, value);
    value = divisor * lanes * 3 / (clk * 2) + 5;
    dp_tx_reg_write8(port, TX_REG_PACE_B, value);
    /* On chip revisions above 0x83 the other outputs also set bit 7 of register 0x7c. */
    if (sys_get_chip_revision() > 0x83 && port != 0)
        dp_tx_reg_update_bits(port, TX_REG_PACE_B, 0x80, 1);
    if (clk > 0x2bb && divisor == 0x21c)
        dp_tx_reg_write8(port, TX_REG_PACE_C, 0x12);
    else if ((dp_tx_reg_read8(port, TX_REG_PACE_A) & 0x3f) > 0x10)
        dp_tx_reg_write8(port, TX_REG_PACE_C, 0x20);
    else
        dp_tx_reg_write8(port, TX_REG_PACE_C, ((dp_tx_reg_read8(port, TX_REG_PACE_A) & 0x3f) + 1) << 1);
    dp_tx_reg_update_bits(port, TX_REG_PACE_C, 1, 1);
    dp_tx_pacing_records[port].updated_ticks = timer_get_ticks();
    dp_tx_pacing_records[port].updated = 1;
}
