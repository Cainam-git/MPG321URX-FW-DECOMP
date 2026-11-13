/* hdmi_tx_phy_tune_for_tmds_clock  (FUN_a008f270)
 *
 * Tune the HDMI TX PHY for the TMDS clock range (up to 148, 340, above).
 *   port: HDMI TX port
 *   clk: TMDS clock in MHz
 * Name basis: proven - prints 'Input Clock', 'Pixel Clock <= 148Mhz', '148MHz < Pixel Clock <= 340Mhz',
 *   '340MHz <Pixel Clock <= 594Mhz'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f270 @ 0xa008f270, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - all parameters are int, and the port is masked to its low byte once (port &= 0xff) after the switch;
 *  - the six settings are unsigned char locals, all set to 0 before the range test and again in case 0;
 *  - the range test is clock > 0x94, then (unsigned int)(clock - 149) <= 0xbf; the switch lists the cases in
 *    the order 0, 1, 2 with an empty default;
 *  - the texts are reached by their labels (DAT_a0068de8 ..), the callees through the plain int prototypes
 *    below.
 */
/* Texts printed here. */
extern unsigned int DAT_a0068de8;   /* "\x1b[0m\t\t - Input Clock = %d \r\n" */
extern unsigned int DAT_a0068e08;   /* "\x1b[0m\t\t - 148MHz < Pixel Clock <= 340Mhz \n" */
extern unsigned int DAT_a0068e38;   /* "\x1b[0m\t\t - Pixel Clock <= 148Mhz \n" */
extern unsigned int DAT_a0068e60;   /* "\x1b[0m\t\t - 340MHz <Pixel Clock <= 594Mhz \n" */

extern void dbg_printf(unsigned int *, int);
extern void dbg_print_string(unsigned int *);
extern void hdmi_tx_reg_update_bits(int, int, int, int, int);
extern void hdmi_tx_set_lane_regs_7b_9f(int, int);
extern void hdmi_tx_set_regs_08_98(int, int, int);
extern void hdmi_tx_set_regs_0e_9b(int, int);
extern void hdmi_tx_reg_write_field(int, int, int, int, int);
extern void hdmi_tx_set_regs_0a_99(int, int, int);
extern void hdmi_tx_set_regs_7c_9a(int, int);
extern void hdmi_tx_scdc_write(int, int, int);
extern void hdmi_tx_reg_write8(int, int, int, int);
extern void hdmi_tx_set_regs_39_30(int, int, int, int, int, int);

#define HDMI_TX_BANK_PHY  1         /* bank 1 of an HDMI transmitter's registers */
#define BITS_CLEAR        0         /* last argument of hdmi_tx_reg_update_bits */

/* Clock ranges, named from the printed texts (limits in MHz). */
enum {
    CLOCK_UP_TO_148  = 0,
    CLOCK_UP_TO_340  = 1,
    CLOCK_ABOVE_340  = 2            /* the text says up to 594; no upper limit is tested */
};
#define CLOCK_LIMIT_148   0x94      /* above it: clock - 149 <= 0xbf is the range up to 340 */

#define SCDC_REG_20       0x20      /* SCDC register of the display written with scdc_20_value */
#define LINK_MODE_HIGH    2         /* link_mode of CLOCK_ABOVE_340 */
#define SCDC_20_HIGH      3         /* scdc_20_value of CLOCK_ABOVE_340 */

/*
 * Set the PHY of an HDMI transmitter up for the TMDS clock of the link.
 *
 *   port         the HDMI TX port (only the low byte is used)
 *   clock        the TMDS clock in MHz
 *   arg_3..arg_6 passed on to hdmi_tx_set_regs_39_30, which does not use them
 *
 * Called by hdmi_tx_run_step in set-up step 10 (TX_STEP_LINK_TMDS) with the channel's pixel clock times its
 * colour depth / 8.
 *
 * The clock picks one of three ranges and with it six settings:
 *
 *   range             lane_value  link_mode  field_0e_9b  scdc_20_value  reg39_mode
 *   up to 148 MHz     0           0          0x00         0              0
 *   149..340 MHz      6           1          0x11         0              0
 *   above 340 MHz     0x1B        2          0x22         3              1
 *
 * They are written in this order: bit 7 of register 0x7D cleared, lane_value to registers 0x7B and
 * 0x9D..0x9F, link_mode to registers 8 / 0x98, field_0e_9b to registers 0x0E / 0x9B (above 340 MHz also
 * bits 4..6 of 0x9B = 1), link_mode to registers 0x0A / 0x99, 0 to registers 0x7C / 0x9A, scdc_20_value to SCDC
 * register 0x20 of the display (above 340 MHz also registers 0x31..0x34 = 0, 0, 0x32, 0), and reg39_mode to
 * registers 0x39 / 0x30.
 */
void hdmi_tx_phy_tune_for_tmds_clock(int port, int clock, int arg_3, int arg_4,
                  int arg_5, int arg_6)
{
    unsigned char range;
    unsigned char lane_value;
    unsigned char link_mode;
    unsigned char field_0e_9b;
    unsigned char scdc_20_value;
    unsigned char reg39_mode;

    dbg_printf(&DAT_a0068de8, clock);

    lane_value = 0;
    link_mode = 0;
    field_0e_9b = 0;
    scdc_20_value = 0;
    reg39_mode = 0;
    range = CLOCK_UP_TO_148;

    if (clock > CLOCK_LIMIT_148) {
        if ((unsigned int)(clock - 149) <= 0xbf)
            range = CLOCK_UP_TO_340;
        else
            range = CLOCK_ABOVE_340;
    }

    switch (range) {
    case CLOCK_UP_TO_148:
        dbg_print_string(&DAT_a0068e38);
        lane_value = 0;
        link_mode = 0;
        field_0e_9b = 0;
        scdc_20_value = 0;
        reg39_mode = 0;
        break;
    case CLOCK_UP_TO_340:
        dbg_print_string(&DAT_a0068e08);
        lane_value = 6;
        link_mode = 1;
        field_0e_9b = 0x11;
        scdc_20_value = 0;
        reg39_mode = 0;
        break;
    case CLOCK_ABOVE_340:
        dbg_print_string(&DAT_a0068e60);
        lane_value = 0x1b;
        link_mode = LINK_MODE_HIGH;
        field_0e_9b = 0x22;
        scdc_20_value = SCDC_20_HIGH;
        reg39_mode = 1;
        break;
    default:
        break;
    }

    port &= 0xff;

    hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x7d, 0x80, BITS_CLEAR);
    hdmi_tx_set_lane_regs_7b_9f(port, lane_value & 0x1f);
    hdmi_tx_set_regs_08_98(port, link_mode, 0);
    hdmi_tx_set_regs_0e_9b(port, field_0e_9b & 0x33);

    if (link_mode == LINK_MODE_HIGH) {
        hdmi_tx_reg_write_field(port, HDMI_TX_BANK_PHY, 0x9b, 0x70, 0x10);
    }

    hdmi_tx_set_regs_0a_99(port, link_mode, 0);
    hdmi_tx_set_regs_7c_9a(port, 0);
    hdmi_tx_scdc_write(port, SCDC_REG_20, scdc_20_value);

    if (scdc_20_value == SCDC_20_HIGH) {
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x31, 0);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x32, 0);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x33, 0x32);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x34, 0);
    }

    hdmi_tx_set_regs_39_30(port, reg39_mode & 1, arg_3, arg_4, arg_5, arg_6);
}
