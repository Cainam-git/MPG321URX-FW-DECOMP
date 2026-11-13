/* hdmi_rx21_track_ced_errors  (MAX_CED)
 *
 * Record the per-lane character error counts and report lanes with too many.
 *   param: HDMI 2.1 receiver 0/1
 * Note: Label MAX_CED is a printed value name, not the routine name; 10-sample history per lane.
 * Name basis: derived - prints 'Jex: ch%d CED error > 4 in 1s', 'CED error clear by TX read, reset CED array',
 *   'MAX_CED[%d]'
 *
 * Matching notes
 * --------------
 * leon2s MAX_CED @ 0xa009967c-0xa0099c18 (1436 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the port is an unsigned char local (port) in the reading part and param & 0xff in every later access;
 *  - the column byte is read again in each arm;
 *  - one variable (newest) holds the newest entry and then the difference;
 *  - the count halves of a PHY register word are a bit-field view of the word (union ced_word);
 *  - the end-of-row line is the firmware string at 0xa0069ee8 ("\n"), not a literal.
 */

#define PHY_RX21_0          2       /* PHY numbers of the HDMI 2.1 receivers 0 / 1 */
#define PHY_RX21_1          3

/* PHY registers read here: one word holds the counts of two lanes (see union ced_word). */
#define PHY_REG_CED_LANES_01    0x2e64
#define PHY_REG_CED_LANES_23    0x2e68
#define CED_EVEN_VALID_BIT      0xf     /* bit 15: count of lane 0 / 2 valid */
#define CED_ODD_VALID_BIT       0x1f    /* bit 31: count of lane 1 / 3 valid */

#define CED_COUNT_MAX           0x7fff  /* 15-bit count at its top value: 'MAX_CED[%d]' */
#define CED_ERROR_LIMIT         4       /* 'CED error > 4 in 1s' */
#define CED_HISTORY_LENGTH      10      /* samples kept per lane */

#define B3_REG_60               0x60    /* block 3 register; LTS initial settings clear its bits 0..2 */
#define B3_REG_60_ERROR_BIT     1       /* set here for a lane at CED_COUNT_MAX or above CED_ERROR_LIMIT */

#define HDMI_MSG_BIT13          0x2000  /* dbg_hdmi_message_flags bit 13: gates the prints of this routine */

/* Link training record of an HDMI 2.1 receiver (0xB0 bytes, hdmi_rx21_lts_records); the fields used here. The CED
   history is a ring of CED_HISTORY_LENGTH samples per lane; hdmi_rx21_reset_ced_history clears it. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;                       /* +0: 0, 3 or 4 */
    unsigned char pad_0x1[0x3d];
    unsigned short ced_history[4][10];              /* +0x3E: per lane */
    unsigned char ced_column;                       /* +0x8E: ring position of the next sample */
    unsigned char ced_sample_phase;                 /* +0x8F: a sample is taken when it is 0 */
    unsigned char ced_sample_divider;               /* +0x90: 100 / hdmi_rx21_rx_detect_period */
    unsigned char ced_history_full;                 /* +0x91: 1 once the ring has wrapped */
    unsigned char ced_max_reported[4];              /* +0x92: per lane, CED_COUNT_MAX already reported */
    unsigned char pad_0x96[0xb0 - 0x96];
};

/* Register block addresses of an HDMI 2.1 receiver (13 words, hdmi_rx21_reg_blocks). */
struct hdmi_rx21_reg_blocks {
    unsigned int block0, block1, block2;
    unsigned int block3;                            /* +0xC: 0xCE009300 (+0x1000 for receiver 1) */
    unsigned char blocks_4_to_12[0x34 - 0x10];
};

/* A PHY count word: the count of the even lane in bits 0..14, of the odd lane in bits 16..30, each with a
   valid bit above it. */
union ced_word {
    unsigned int word;
    struct {
        unsigned int odd_valid : 1;
        unsigned int odd_count : 15;
        unsigned int even_valid : 1;
        unsigned int even_count : 15;
    } lanes;
};

extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned int dbg_hdmi_message_flags;
extern const char s_a0069ee8[];                    /* "\n" */

extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void reg_set_bit(unsigned int, int);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void hdmi_rx21_reset_ced_history(unsigned int);

/*
 * Track the character error (CED) counts of the lanes of an HDMI 2.1 receiver.
 *
 *   param  HDMI 2.1 receiver 0 or 1; any other value returns at once
 *
 * Called by DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable on every pass of the trained-link state.
 *
 * Phases:
 *   1. Read: for each lane in use (lane_count), read its count from the PHY when its valid bit is set;
 *      otherwise the count is 0 ('CED non valid').
 *   2. Per lane: a count at CED_COUNT_MAX sets the error bit once ('MAX_CED[%d]'). On a sample pass
 *      (ced_sample_phase 0) the count goes into the history ring and the row is printed; then
 *        - ring full: a count lower than the oldest sample means the counter was cleared ('CED error clear by
 *          TX read'): the history is reset and the routine returns; a rise of more than CED_ERROR_LIMIT
 *          over the ring sets the error bit;
 *        - ring not yet full: a count above CED_ERROR_LIMIT sets the error bit.
 *   3. Advance: after a sample pass the ring position moves on (wrapping marks the ring full); the sample
 *      phase counts modulo ced_sample_divider.
 * The error bit is bit 1 of block 3 register 0x60 of the receiver.
 */
void hdmi_rx21_track_ced_errors(unsigned int param)
{
    unsigned short ced[4] = {0, 0, 0, 0};
    unsigned char valid = 0;
    unsigned char phy;
    unsigned char lane, k;
    unsigned char port = param;
    union ced_word count_word;
    unsigned int newest, oldest;
    unsigned short count;

    if (port == 0)
        phy = PHY_RX21_0;
    else if (port == 1)
        phy = PHY_RX21_1;
    else
        return;

    if (hdmi_rx21_lts_records[port].ced_sample_phase == 0 && (dbg_hdmi_message_flags & HDMI_MSG_BIT13))
        dbg_printf("Jex: CED CNT debug, index = %d\n\n", hdmi_rx21_lts_records[port].ced_column);

    /* 1. Read the counts. For a lane above 3 the valid flag of the lane before is kept. */
    for (lane = 0; lane < hdmi_rx21_lts_records[port].lane_count; lane++) {
        if (lane == 0)
            valid = hdmi_phy_test_bit(CED_EVEN_VALID_BIT, phy, PHY_REG_CED_LANES_01) != 0;
        else if (lane == 1)
            valid = hdmi_phy_test_bit(CED_ODD_VALID_BIT, phy, PHY_REG_CED_LANES_01) != 0;
        else if (lane == 2)
            valid = hdmi_phy_test_bit(CED_EVEN_VALID_BIT, phy, PHY_REG_CED_LANES_23) != 0;
        else if (lane == 3)
            valid = hdmi_phy_test_bit(CED_ODD_VALID_BIT, phy, PHY_REG_CED_LANES_23) != 0;
        if (valid) {
            if (lane == 0) {
                count_word.word = hdmi_phy_read_reg(phy, PHY_REG_CED_LANES_01);
                ced[0] = count_word.lanes.even_count;
            } else if (lane == 1) {
                count_word.word = hdmi_phy_read_reg(phy, PHY_REG_CED_LANES_01);
                ced[1] = count_word.lanes.odd_count;
            } else if (lane == 2) {
                count_word.word = hdmi_phy_read_reg(phy, PHY_REG_CED_LANES_23);
                ced[2] = count_word.lanes.even_count;
            } else if (lane == 3) {
                count_word.word = hdmi_phy_read_reg(phy, PHY_REG_CED_LANES_23);
                ced[3] = count_word.lanes.odd_count;
            }
        } else {
            ced[lane] = 0;
            if (dbg_hdmi_message_flags & HDMI_MSG_BIT13)
                dbg_print_string("Jex: CED non valid, ERR\n");
        }
    }

    /* 2. Check each lane. */
    for (lane = 0; lane < hdmi_rx21_lts_records[param & 0xff].lane_count; lane++) {
        if (ced[lane] == CED_COUNT_MAX && hdmi_rx21_lts_records[param & 0xff].ced_max_reported[lane] == 0) {
            reg_set_bit(B3_REG_60_ERROR_BIT, ARR_a807db00[param & 0xff].block3 + B3_REG_60);
            hdmi_rx21_lts_records[param & 0xff].ced_max_reported[lane] = 1;
            dbg_printf("MAX_CED[%d]\n\n", lane);
        }
        if (hdmi_rx21_lts_records[param & 0xff].ced_sample_phase == 0) {
            /* Sample pass: store and print the lane's ring. */
            hdmi_rx21_lts_records[param & 0xff].ced_history[lane][hdmi_rx21_lts_records[param & 0xff].ced_column] = ced[lane];
            for (k = 0; k < CED_HISTORY_LENGTH; k++) {
                if (dbg_hdmi_message_flags & HDMI_MSG_BIT13)
                    dbg_printf("%04X ", hdmi_rx21_lts_records[param & 0xff].ced_history[lane][k]);
            }
            if (hdmi_rx21_lts_records[param & 0xff].ced_history_full != 0) {
                /* Ring full: compare the newest sample with the oldest one (the next ring position). */
                newest = hdmi_rx21_lts_records[param & 0xff].ced_history[lane][hdmi_rx21_lts_records[param & 0xff].ced_column];
                oldest = hdmi_rx21_lts_records[param & 0xff].ced_history[lane][(hdmi_rx21_lts_records[param & 0xff].ced_column + 1) % CED_HISTORY_LENGTH];
                if (newest < oldest) {
                    if (dbg_hdmi_message_flags & HDMI_MSG_BIT13)
                        dbg_print_string("\n\nCED error clear by TX read, reset CED array\n");
                    hdmi_rx21_reset_ced_history(param & 0xff);
                    return;
                }
                newest -= oldest;
                if ((int)newest > CED_ERROR_LIMIT) {
                    if (dbg_hdmi_message_flags & HDMI_MSG_BIT13)
                        dbg_printf(" Jex: ch%d CED error > 4 in 1s, Total=0x%04X ", lane, newest);
                    reg_set_bit(B3_REG_60_ERROR_BIT, ARR_a807db00[param & 0xff].block3 + B3_REG_60);
                }
            } else {
                /* Ring not yet full: the count itself is checked. */
                count = hdmi_rx21_lts_records[param & 0xff].ced_history[lane][hdmi_rx21_lts_records[param & 0xff].ced_column];
                if (count > CED_ERROR_LIMIT) {
                    reg_set_bit(B3_REG_60_ERROR_BIT, ARR_a807db00[param & 0xff].block3 + B3_REG_60);
                    if (dbg_hdmi_message_flags & HDMI_MSG_BIT13)
                        dbg_printf(" Jex: ch%d CED error > 4 in 1s, Total=0x%04X ", lane, count);
                }
            }
            if (dbg_hdmi_message_flags & HDMI_MSG_BIT13)
                dbg_print_string(s_a0069ee8);
        }
    }

    /* 3. Advance the ring after a sample pass, and the sample phase on every pass. */
    if (hdmi_rx21_lts_records[param & 0xff].ced_sample_phase == 0) {
        if (++hdmi_rx21_lts_records[param & 0xff].ced_column == CED_HISTORY_LENGTH) {
            hdmi_rx21_lts_records[param & 0xff].ced_history_full = 1;
            hdmi_rx21_lts_records[param & 0xff].ced_column = 0;
        }
    }
    hdmi_rx21_lts_records[param & 0xff].ced_sample_phase = (hdmi_rx21_lts_records[param & 0xff].ced_sample_phase + 1) % hdmi_rx21_lts_records[param & 0xff].ced_sample_divider;
}
