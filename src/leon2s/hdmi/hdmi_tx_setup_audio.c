/* hdmi_tx_setup_audio  (FUN_a00934c0)
 *
 * Set up the audio path of an HDMI TX port for its audio source.
 *   port: HDMI TX port
 *   mode: audio source id
 * Returns: 1; 0 when the port number is above 1 (nothing is done then)
 * Name basis: derived - mode = audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1); uses TMDS clock and
 *   FRL rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00934c0 @ 0xa00934c0-0xa0094308 (3656 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - old-style parameter declarations (unsigned char port, mode);
 *  - both mode dispatches are switches with grouped cases, each case group then tests the single modes again;
 *  - the row selections of the FRL path are switches with the default case first;
 *  - each scaling arm of the DisplayPort path computes both quotients itself;
 *  - the 24-bit values of the DisplayPort path are built in three statements each.
 */

/* The audio source (mode): which input feeds the audio, and through which register read routine. */
enum {
    AUDIO_SRC_DP_0     = 4,             /* DP receiver 0, dp_reg_read8 */
    AUDIO_SRC_DP_1     = 6,             /* DP receiver 1 */
    AUDIO_SRC_HDMI20_0 = 8,             /* HDMI 2.0 receiver 0, hdmi_reg_read8 */
    AUDIO_SRC_HDMI20_1 = 10,            /* HDMI 2.0 receiver 1 */
    AUDIO_SRC_HDMI21_0 = 12,            /* HDMI 2.1 receiver 0, hdmi_rx21_reg_read8 */
    AUDIO_SRC_HDMI21_1 = 14             /* HDMI 2.1 receiver 1 */
};

/* Registers of bank 0 of the HDMI transmitter. */
#define TX_BANK_0             0
#define TX_REG_101            0x101     /* bit 1 set before the N value is written */
#define   REG101_BIT1           2
#define TX_REG_AUDIO_N        0x103     /* 0x103..0x105: N, low byte first (hdmi_tx_audio_n_* tables) */
#define TX_REG_AUDIO_CTS      0x106     /* 0x106..0x108: CTS, low byte first */
#define TX_REG_11D            0x11D
#define TX_REG_124            0x124     /* 0x9B or 0x2B */
#define TX_REG_12F            0x12F
#define DEFAULT_AUDIO_N       0x1800    /* N without an audio input: the value of the 47.2..48.8 kHz window */

/* Registers of the HDMI input that feeds the audio (read through hdmi_tx_audio_reg_reader). */
#define RX_REG_100            0x100     /* bit 3 / bit 4 pick the register set of the two 24-bit values */
#define   REG100_FIRST_SET      0x08
#define   REG100_SECOND_SET     0x10
#define RX_REG_12A            0x12A
#define RX_REG_280            0x280
#define MIN_INPUT_DIVISOR     0x7D      /* 125: the divisor is divided by this, so it may not be smaller */

/* Registers of the DP input that feeds the audio. */
#define DP_REG_51             0x51      /* bits 2..4 all set: register 0x12F bits 2 and 1 cleared one by one */
#define DP_REG_SCALE          0x80      /* bits 0..1: which of the three scales below */
#define DP_REG_PAIR_SELECT    0x81      /* bit 5 picks which pair 0x82..0x87 shows; restored afterwards */
#define   PAIR_SELECT_BIT       0x20
#define DP_REG_PAIR           0x82      /* 0x82..0x84 value, 0x85..0x87 divisor, high byte first */

#define AUDIO_RATE_COUNT      0x12      /* entries of hdmi_tx_audio_rate_table: 3 families of 6 multiples */
#define RATES_PER_FAMILY      6
#define AUDIO_RATE_TOLERANCE  8         /* in 100 Hz */
#define MAX_FRL_RATE_INDEX    6         /* last entry of hdmi_tx_frl_clock_table */

typedef unsigned char (*RdFn)(unsigned char, unsigned short);

extern RdFn hdmi_tx_audio_reg_reader;
extern const unsigned short hdmi_tx_frl_clock_table[];
extern const unsigned short hdmi_tx_audio_rate_table[];
extern const unsigned int hdmi_tx_audio_n_32k_rows[4][6];
extern const unsigned int hdmi_tx_audio_n_44k_rows[2][6];
extern const unsigned int hdmi_tx_audio_n_48k_rows[4][6];
extern const unsigned int hdmi_tx_audio_n_by_tmds_clock[];
extern const unsigned int hdmi_tx_audio_cts_by_tmds_clock[];
extern unsigned char hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned char hdmi_rx21_reg_read8(unsigned char, unsigned short);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_tx_copy_audio_info_from_hdmi(unsigned int, unsigned char);
extern void hdmi_tx_copy_audio_info_from_dp(unsigned int, unsigned char);
extern void hdmi_tx_load_stored_audio_info(unsigned char);
extern unsigned char hdmi_rx21_is_frl_mode(unsigned char);
extern unsigned char hdmi_rx21_read_frl_rate(unsigned char);
extern unsigned char hdmi_tx_get_frl_rate(unsigned char);
extern unsigned short hdmi_get_saved_tmds_clock(unsigned char);
extern unsigned short hdmi_rx21_calc_tmds_clock(unsigned char);
extern int abs(int);

/*
 * Set up the audio of one HDMI output for the input that feeds it.
 *
 *   port  HDMI TX port 0 or 1; any other value returns 0 at once
 *   mode  the audio source (AUDIO_SRC_*): the channel record's audio_source byte
 *
 * Returns 1. Called by hdmi_tx_run_step in set-up steps 1 and 2 when the channel record's audio_packet bit is
 * set.
 *
 * Phases:
 *   1. By source: pick the input's register read routine (hdmi_tx_audio_reg_reader) and receiver number, write
 *      transmitter registers 0x124 / 0x12F / 0x11D, and copy the input's audio InfoFrame and settings
 *      (hdmi_tx_copy_audio_info_from_hdmi / _from_dp); without a known source the stored ones are loaded.
 *   2. The N value for registers 0x103..0x105:
 *      HDMI inputs: read two 24-bit values of the input and compute the audio sample rate from them and the
 *        input's clock (in 100 Hz, the unit of hdmi_tx_audio_rate_table).
 *        - HDMI 2.1 input in FRL mode: the clock is the link clock of the input's FRL rate
 *          (hdmi_tx_frl_clock_table); the rate is looked up in hdmi_tx_audio_rate_table (within 8) and N is
 *          taken from the 32k / 44.1k / 48k rows, row by this output's FRL rate, column by the multiple.
 *          A rate that is not in the table takes column 0 of the 32k rows.
 *        - otherwise: the clock is the input's TMDS clock; one of twelve windows gives N. A rate outside all
 *          windows leaves the first value read from the input as N.
 *      DisplayPort inputs: two value/divisor pairs of the input give a row (from the second pair) and a column
 *        (from the first pair) of the N and CTS tables; both are written (0x103..0x108). A zero divisor
 *        returns before anything is written.
 *      Other sources: N = DEFAULT_AUDIO_N.
 */
unsigned int hdmi_tx_setup_audio(port, mode)
    unsigned char port, mode;
{
    unsigned char rx = 0;               /* receiver 0/1 of the source */
    unsigned char phy = 0;              /* 0..3 for the four HDMI sources */
    unsigned char frl_rate_index, rate_index, row, column, pair_select;
    unsigned short sample_rate;         /* in 100 Hz */
    unsigned int audio_n, input_divisor, value1, divisor1, value2, divisor2, row_quotient;
    int column_quotient;

    if (port > 1)
        return 0;

    /* 1. Source registers, transmitter registers 0x124 / 0x12F / 0x11D, audio InfoFrame. */
    switch (mode) {
    case AUDIO_SRC_HDMI20_0:
    case AUDIO_SRC_HDMI20_1:
    case AUDIO_SRC_HDMI21_0:
    case AUDIO_SRC_HDMI21_1:
        if (mode == AUDIO_SRC_HDMI20_0)
            hdmi_tx_audio_reg_reader = hdmi_reg_read8;
        else if (mode == AUDIO_SRC_HDMI20_1) {
            hdmi_tx_audio_reg_reader = hdmi_reg_read8;
            rx = 1;
        } else if (mode == AUDIO_SRC_HDMI21_0)
            hdmi_tx_audio_reg_reader = hdmi_rx21_reg_read8;
        else if (mode == AUDIO_SRC_HDMI21_1) {
            hdmi_tx_audio_reg_reader = hdmi_rx21_reg_read8;
            rx = 1;
        }
        if ((hdmi_tx_audio_reg_reader(rx, RX_REG_12A) & 2) && hdmi_tx_audio_reg_reader(rx, RX_REG_280) == 9) {
            hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_124, 0x9b);
            hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_12F, 6, 0);
            hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_11D, 0x80, 1);
        } else {
            hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_124, 0x2b);
            hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_12F, 4, 0);
            hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_12F, 2, 0);
        }
        hdmi_tx_copy_audio_info_from_hdmi(rx, port);
        break;
    case AUDIO_SRC_DP_0:
    case AUDIO_SRC_DP_1:
        if (mode == AUDIO_SRC_DP_0)
            rx = 0;
        else if (mode == AUDIO_SRC_DP_1)
            rx = 1;
        if ((dp_reg_read8(rx, DP_REG_51) & 0x1c) == 0x1c) {
            hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_124, 0x2b);
            hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_12F, 4, 0);
            hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_12F, 2, 0);
        } else {
            hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_124, 0x2b);
            hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_12F, 6, 0);
        }
        hdmi_tx_copy_audio_info_from_dp(rx, port);
        break;
    default:
        hdmi_tx_load_stored_audio_info(port);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_124, 0x2b);
        hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_12F, 6, 0);
        break;
    }

    /* 2. The N value (and for DP sources the CTS value). */
    switch (mode) {
    case AUDIO_SRC_HDMI20_0:
    case AUDIO_SRC_HDMI20_1:
    case AUDIO_SRC_HDMI21_0:
    case AUDIO_SRC_HDMI21_1:
        if (mode == AUDIO_SRC_HDMI20_0) {
            hdmi_tx_audio_reg_reader = hdmi_reg_read8;
            rx = 0;
            phy = 0;
        } else if (mode == AUDIO_SRC_HDMI20_1) {
            hdmi_tx_audio_reg_reader = hdmi_reg_read8;
            rx = 1;
            phy = 1;
        } else if (mode == AUDIO_SRC_HDMI21_0) {
            hdmi_tx_audio_reg_reader = hdmi_rx21_reg_read8;
            rx = 0;
            phy = 2;
        } else if (mode == AUDIO_SRC_HDMI21_1) {
            hdmi_tx_audio_reg_reader = hdmi_rx21_reg_read8;
            rx = 1;
            phy = 3;
        }
        hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_101, REG101_BIT1, 1);
        /* The two 24-bit values of the input, each from one of two register sets. */
        if (hdmi_tx_audio_reg_reader(rx, RX_REG_100) & REG100_FIRST_SET)
            audio_n = (hdmi_tx_audio_reg_reader(rx, 0x105) << 16) + (hdmi_tx_audio_reg_reader(rx, 0x104) << 8) + hdmi_tx_audio_reg_reader(rx, 0x103);
        else
            audio_n = (hdmi_tx_audio_reg_reader(rx, 0x108) << 16) + (hdmi_tx_audio_reg_reader(rx, 0x107) << 8) + hdmi_tx_audio_reg_reader(rx, 0x106);
        if (hdmi_tx_audio_reg_reader(rx, RX_REG_100) & REG100_SECOND_SET)
            input_divisor = (hdmi_tx_audio_reg_reader(rx, 0x10b) << 16) + (hdmi_tx_audio_reg_reader(rx, 0x10a) << 8) + hdmi_tx_audio_reg_reader(rx, 0x109);
        else
            input_divisor = (hdmi_tx_audio_reg_reader(rx, 0x10e) << 16) + (hdmi_tx_audio_reg_reader(rx, 0x10d) << 8) + hdmi_tx_audio_reg_reader(rx, 0x10c);
        if (input_divisor < MIN_INPUT_DIVISOR)
            input_divisor = MIN_INPUT_DIVISOR;
        if ((mode == AUDIO_SRC_HDMI21_0 || mode == AUDIO_SRC_HDMI21_1) && hdmi_rx21_is_frl_mode(rx) == 1) {
            /* FRL input: the clock is the link clock of the input's FRL rate (block 6 word 0x90 bits 24..27). */
            frl_rate_index = hdmi_rx21_read_frl_rate(phy & 3);
            if (frl_rate_index > MAX_FRL_RATE_INDEX)
                frl_rate_index = MAX_FRL_RATE_INDEX;
            sample_rate = (audio_n >> 7) * hdmi_tx_frl_clock_table[frl_rate_index] / (input_divisor / 125) << 3;
            for (rate_index = 0; rate_index < AUDIO_RATE_COUNT; rate_index++)
                if (abs(sample_rate - hdmi_tx_audio_rate_table[rate_index]) <= AUDIO_RATE_TOLERANCE)
                    break;
            /* Family (32k, 44.1k, 48k) by rate_index / 6, row by the output's FRL rate, column by the multiple. */
            switch (rate_index / RATES_PER_FAMILY) {
            default:
                    switch (hdmi_tx_get_frl_rate(port)) {
                    default:
                        audio_n = hdmi_tx_audio_n_32k_rows[0][rate_index % 6];
                        break;
                    case 2:
                    case 3:
                    case 4:
                        audio_n = hdmi_tx_audio_n_32k_rows[1][rate_index % 6];
                        break;
                    case 5:
                        audio_n = hdmi_tx_audio_n_32k_rows[2][rate_index % 6];
                        break;
                    case 6:
                        audio_n = hdmi_tx_audio_n_32k_rows[3][rate_index % 6];
                        break;
                    }
                break;
            case 1:
                    switch (hdmi_tx_get_frl_rate(port)) {
                    default:
                        audio_n = hdmi_tx_audio_n_44k_rows[0][rate_index % 6];
                        break;
                    case 4:
                    case 5:
                    case 6:
                        audio_n = hdmi_tx_audio_n_44k_rows[1][rate_index % 6];
                        break;
                    }
                break;
            case 2:
                    switch (hdmi_tx_get_frl_rate(port)) {
                    default:
                        audio_n = hdmi_tx_audio_n_48k_rows[0][rate_index % 6];
                        break;
                    case 2:
                    case 3:
                    case 4:
                        audio_n = hdmi_tx_audio_n_48k_rows[1][rate_index % 6];
                        break;
                    case 5:
                        audio_n = hdmi_tx_audio_n_48k_rows[2][rate_index % 6];
                        break;
                    case 6:
                        audio_n = hdmi_tx_audio_n_48k_rows[3][rate_index % 6];
                        break;
                    }
                break;
            }
        } else {
            /* TMDS input: the clock is the input's TMDS clock (the HDMI 2.0 one times 10). */
            if (mode == AUDIO_SRC_HDMI20_0 || mode == AUDIO_SRC_HDMI20_1)
                sample_rate = (audio_n >> 7) * hdmi_get_saved_tmds_clock(rx) * 10 / (input_divisor / 125) << 3;
            else
                sample_rate = (audio_n >> 7) * hdmi_rx21_calc_tmds_clock(rx) / (input_divisor / 125) << 3;
            /* Windows of +-0.8 kHz around 32, 64, 128, 256 / 44.1, 88.2, 176.4, 352.8 / 48, 96, 192, 384 kHz. */
            if (sample_rate >= 312 && sample_rate <= 328)
                audio_n = 0x1000;
            else if (sample_rate >= 632 && sample_rate <= 648)
                audio_n = 0x2000;
            else if (sample_rate >= 1272 && sample_rate <= 1288)
                audio_n = 0x4000;
            else if (sample_rate >= 2552 && sample_rate <= 2568)
                audio_n = 0x8000;
            else if (sample_rate >= 433 && sample_rate <= 449)
                audio_n = 0x1880;
            else if (sample_rate >= 874 && sample_rate <= 890)
                audio_n = 0x3100;
            else if (sample_rate >= 1756 && sample_rate <= 1772)
                audio_n = 0x6200;
            else if (sample_rate >= 3520 && sample_rate <= 3536)
                audio_n = 0xc400;
            else if (sample_rate >= 472 && sample_rate <= 488)
                audio_n = 0x1800;
            else if (sample_rate >= 952 && sample_rate <= 968)
                audio_n = 0x3000;
            else if (sample_rate >= 1912 && sample_rate <= 1928)
                audio_n = 0x6000;
            else if (sample_rate >= 3832 && sample_rate <= 3848)
                audio_n = 0xc000;
        }
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N + 2, (audio_n >> 16) & 0xff);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N + 1, (audio_n >> 8) & 0xff);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N, audio_n & 0xff);
        break;
    case AUDIO_SRC_DP_0:
    case AUDIO_SRC_DP_1:
        if (mode == AUDIO_SRC_DP_0)
            rx = 0;
        else if (mode == AUDIO_SRC_DP_1)
            rx = 1;
        hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_101, REG101_BIT1, 1);
        /* Pair 1 with register 0x81 bit 5 clear, pair 2 with it set. */
        pair_select = dp_reg_read8(rx, DP_REG_PAIR_SELECT);
        dp_reg_write8(rx, DP_REG_PAIR_SELECT, pair_select & 0xdf);
        value1 = dp_reg_read8(rx, 0x82);
        value1 = value1 << 8 | dp_reg_read8(rx, 0x83);
        value1 = value1 << 8 | dp_reg_read8(rx, 0x84);
        divisor1 = dp_reg_read8(rx, 0x85);
        divisor1 = divisor1 << 8 | dp_reg_read8(rx, 0x86);
        divisor1 = divisor1 << 8 | dp_reg_read8(rx, 0x87);
        dp_reg_write8(rx, DP_REG_PAIR_SELECT, pair_select | PAIR_SELECT_BIT);
        value2 = dp_reg_read8(rx, 0x82);
        value2 = value2 << 8 | dp_reg_read8(rx, 0x83);
        value2 = value2 << 8 | dp_reg_read8(rx, 0x84);
        divisor2 = dp_reg_read8(rx, 0x85);
        divisor2 = divisor2 << 8 | dp_reg_read8(rx, 0x86);
        divisor2 = divisor2 << 8 | dp_reg_read8(rx, 0x87);
        if (divisor1 == 0 || divisor2 == 0)
            return 1;               /* register 0x81 is left with bit 5 set */
        /* Scale 1620000, 2700000 or 5400000 by register 0x80 bits 0..1. */
        if ((dp_reg_read8(rx, DP_REG_SCALE) & 3) == 0) {
            row_quotient = (value2 * 0x18b820 >> 9) / divisor2;
            column_quotient = value1 * 0x654 / divisor1 * 2;
        } else if ((dp_reg_read8(rx, DP_REG_SCALE) & 3) == 1) {
            row_quotient = (value2 * 2700000 >> 9) / divisor2;
            column_quotient = value1 * 0xa8c / divisor1 * 2;
        } else {
            row_quotient = (value2 * 5400000 >> 9) / divisor2;
            column_quotient = value1 * 0x1518 / divisor1 * 2;
        }
        dp_reg_write8(rx, DP_REG_PAIR_SELECT, pair_select);
        if (row_quotient >= 436 && row_quotient <= 446)
            row = 0;
        else if (row_quotient >= 475 && row_quotient <= 485)
            row = 2;
        else
            row = 1;
        if (column_quotient <= 0x104)
            column = 0;
        else if (column_quotient <= 0x195)
            column = 1;
        else if (column_quotient <= 0x280)
            column = 2;
        else if (column_quotient <= 0x456)
            column = 3;
        else if (column_quotient <= 0x8b1)
            column = 4;
        else
            column = 5;
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N, hdmi_tx_audio_n_by_tmds_clock[row * 6 + column] & 0xff);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N + 1, (hdmi_tx_audio_n_by_tmds_clock[row * 6 + column] >> 8) & 0xff);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N + 2, (hdmi_tx_audio_n_by_tmds_clock[row * 6 + column] >> 16) & 0xff);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_CTS, hdmi_tx_audio_cts_by_tmds_clock[row * 6 + column] & 0xff);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_CTS + 1, (hdmi_tx_audio_cts_by_tmds_clock[row * 6 + column] >> 8) & 0xff);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_CTS + 2, (hdmi_tx_audio_cts_by_tmds_clock[row * 6 + column] >> 16) & 0xff);
        break;
    default:
        hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_101, REG101_BIT1, 1);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N, 0);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N + 1, DEFAULT_AUDIO_N >> 8);
        hdmi_tx_reg_write8(port, TX_BANK_0, TX_REG_AUDIO_N + 2, 0);
        break;
    }
    return 1;
}
