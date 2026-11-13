/* hdmi_rx21_track_rsed_errors  (MAX_RSED)
 *
 * Record the Reed-Solomon error count of the link and report when it is too high.
 *   port_number: HDMI 2.1 receiver 0/1
 * Note: Label MAX_RSED is a printed text, not the routine name.
 * Name basis: derived - prints 'Jex: RSED err>4 in 1s', 'RSED error clear by TX read, reset RSED array', 'RSED
 *   non valid, ERR'
 *
 * Matching notes
 * --------------
 * MAX_RSED (leon2s 0xa0099c18-0xa0099ffc, 996 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the block 8 pointer is volatile, as are all register-block pointers of hdmi_rx21_reg_blocks (see hdmi_rx21_read_frl_rate);
 *    block6 is a plain unsigned int with the byte offset added;
 *  - total is an unsigned short;
 *  - one variable (newest) holds the newest sample and then the rise; the branch without a full ring uses its
 *    own unsigned short (sample).
 */

#define HDMI_MSG_BIT14          0x4000  /* dbg_hdmi_message_flags bit 14: gates most prints of this routine */

#define RSED_HISTORY_LENGTH     10      /* samples in the ring */
#define RSED_ERROR_LIMIT        4       /* 'RSED err>4 in 1s' */
#define RSED_COUNT_MASK         0x7fff  /* low 15 bits of each block 8 word */
#define RSED_VALID_BIT          0xf     /* bit 15 of block 8 word 0 */
#define RSED_TOTAL_ALL_MAX      0x7ffc  /* low 15 bits of 4 * 0x7FFF: all four counts at their top value */

#define B6_LTS_CONTROL          0x80    /* block 6 register (byte offset) */
#define RSED_ERROR_BIT          6       /* of B6_LTS_CONTROL: set here; DRV_HDMI21_LTS_STS_InitialSettings clears it */

/* Link training record of an HDMI 2.1 receiver (0xB0 bytes, hdmi_rx21_lts_records): the RSED fields.
   hdmi_rx21_reset_rsed_history clears them. */
struct hdmi_rx21_lts_record {
    unsigned char pad_0x0[0x96];
    unsigned short rsed_history[RSED_HISTORY_LENGTH];  /* +0x96: ring of samples */
    unsigned char rsed_column;                      /* +0xAA: ring position of the next sample */
    unsigned char rsed_sample_phase;                /* +0xAB: a sample is taken when it is 0 */
    unsigned char rsed_sample_divider;              /* +0xAC: 100 / hdmi_rx21_rx_detect_period */
    unsigned char rsed_history_full;                /* +0xAD: 1 once the ring has wrapped */
    unsigned char rsed_max_reported;                /* +0xAE: 'MAX_RSED' already reported */
    unsigned char rsed_limit_reported;              /* +0xAF: a rise above RSED_ERROR_LIMIT already reported */
};
/* Register block addresses of an HDMI 2.1 receiver (13 words, hdmi_rx21_reg_blocks). */
struct hdmi_rx21_reg_blocks {
    unsigned char blocks_0_to_5[0x18];
    unsigned int block6;                            /* +0x18 */
    unsigned char block7[4];
    volatile unsigned int *block8;                  /* +0x20: four count words */
    unsigned char blocks_9_to_12[0x34 - 0x24];
};

extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned int dbg_hdmi_message_flags;
extern const char s_a0069ee8[];                    /* "\n" */

extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern void reg_set_bit(unsigned int, int);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void hdmi_rx21_reset_rsed_history(unsigned char);

/*
 * Track the RSED count of an HDMI 2.1 receiver: the sum of the low 15 bits of the four words of register
 * block 8 (DRV_HDMI21_RXDetect_FSM_LTS_P prints the same sum as "correct error").
 *
 *   port_number  HDMI 2.1 receiver 0 or 1
 *
 * Called by DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable on every pass.
 *
 * Phases:
 *   1. Read: without the valid bit (bit 15 of word 0) only 'RSED non valid, ERR' is printed. A total of
 *      RSED_TOTAL_ALL_MAX sets the error bit and prints 'MAX_RSED' once.
 *   2. On a sample pass (rsed_sample_phase 0) the total goes into the ring, the ring is printed, and then
 *        - ring full: a total lower than the oldest sample means the count was cleared ('RSED error clear by
 *          TX read'): the history is reset and the routine returns; a rise of more than RSED_ERROR_LIMIT over
 *          the ring sets the error bit once;
 *        - ring not yet full: a total below the first sample resets the same way; a total above
 *          RSED_ERROR_LIMIT sets the error bit once.
 *   3. Advance: after a sample pass the ring position moves on (wrapping marks the ring full); the sample
 *      phase counts modulo rsed_sample_divider.
 * The error bit is RSED_ERROR_BIT of block 6 register B6_LTS_CONTROL.
 */
void hdmi_rx21_track_rsed_errors(unsigned int port_number)
{
    unsigned char port = port_number;
    volatile unsigned int *counts;
    unsigned short total;
    unsigned int newest, oldest;
    unsigned short sample;
    unsigned char k;

    if (hdmi_rx21_lts_records[port].rsed_sample_phase == 0 && (dbg_hdmi_message_flags & HDMI_MSG_BIT14))
        dbg_printf("Jex: RSED CNT debug, index = %d\n\n", hdmi_rx21_lts_records[port].rsed_column);

    /* 1. Read the total. */
    if (reg_test_bit(RSED_VALID_BIT, ARR_a807db00[port].block8) != 0) {
        counts = ARR_a807db00[port].block8;
        total = ((counts[0] & RSED_COUNT_MASK) + (counts[1] & RSED_COUNT_MASK) + (counts[2] & RSED_COUNT_MASK)
                 + (counts[3] & RSED_COUNT_MASK)) & RSED_COUNT_MASK;
        if (total == RSED_TOTAL_ALL_MAX && hdmi_rx21_lts_records[port].rsed_max_reported == 0) {
            reg_set_bit(RSED_ERROR_BIT, ARR_a807db00[port].block6 + B6_LTS_CONTROL);
            hdmi_rx21_lts_records[port].rsed_max_reported = 1;
            dbg_print_string("MAX_RSED\n");
        }

        /* 2. Sample pass: store and print the ring. */
        if (hdmi_rx21_lts_records[port].rsed_sample_phase == 0) {
            hdmi_rx21_lts_records[port].rsed_history[hdmi_rx21_lts_records[port].rsed_column] = total;
            for (k = 0; k < RSED_HISTORY_LENGTH; k++) {
                if (dbg_hdmi_message_flags & HDMI_MSG_BIT14)
                    dbg_printf("%04X ", hdmi_rx21_lts_records[port].rsed_history[k]);
            }
            if (hdmi_rx21_lts_records[port].rsed_history_full != 0) {
                /* The entry after the newest one is the oldest of the ring. */
                newest = hdmi_rx21_lts_records[port].rsed_history[hdmi_rx21_lts_records[port].rsed_column];
                oldest = hdmi_rx21_lts_records[port].rsed_history[(hdmi_rx21_lts_records[port].rsed_column + 1) % RSED_HISTORY_LENGTH];
                if (newest < oldest) {
                    if (dbg_hdmi_message_flags & HDMI_MSG_BIT14)
                        dbg_print_string("\n\nRSED error clear by TX read, reset RSED array\n");
                    hdmi_rx21_reset_rsed_history(port);
                    return;
                }
                newest -= oldest;           /* the rise over the ring */
                if ((int)newest > RSED_ERROR_LIMIT && hdmi_rx21_lts_records[port].rsed_limit_reported == 0) {
                    if (dbg_hdmi_message_flags & HDMI_MSG_BIT14)
                        dbg_printf(" Jex: RSED err>4 in 1s, Total=0x%04X ", newest);
                    reg_set_bit(RSED_ERROR_BIT, ARR_a807db00[port].block6 + B6_LTS_CONTROL);
                    hdmi_rx21_lts_records[port].rsed_limit_reported = 1;
                }
            } else {
                sample = hdmi_rx21_lts_records[port].rsed_history[hdmi_rx21_lts_records[port].rsed_column];
                if (sample < hdmi_rx21_lts_records[port].rsed_history[0]) {
                    if (dbg_hdmi_message_flags & HDMI_MSG_BIT14)
                        dbg_print_string("\n\nRSED error clear by TX read, reset RSED array\n");
                    hdmi_rx21_reset_rsed_history(port);
                    return;
                }
                if (sample > RSED_ERROR_LIMIT && hdmi_rx21_lts_records[port].rsed_limit_reported == 0) {
                    reg_set_bit(RSED_ERROR_BIT, ARR_a807db00[port].block6 + B6_LTS_CONTROL);
                    hdmi_rx21_lts_records[port].rsed_limit_reported = 1;
                    if (dbg_hdmi_message_flags & HDMI_MSG_BIT14)
                        dbg_printf(" Jex: RSED err>4 in 1s, Total=0x%04X ", sample);
                }
            }
            if (dbg_hdmi_message_flags & HDMI_MSG_BIT14)
                dbg_print_string(s_a0069ee8);
        }
    } else {
        if (dbg_hdmi_message_flags & HDMI_MSG_BIT14)
            dbg_print_string("Jex: RSED non valid, ERR\n");
    }

    /* 3. Advance the ring position and the sample phase. */
    if (hdmi_rx21_lts_records[port].rsed_sample_phase == 0) {
        if (++hdmi_rx21_lts_records[port].rsed_column == RSED_HISTORY_LENGTH) {
            hdmi_rx21_lts_records[port].rsed_history_full = 1;
            hdmi_rx21_lts_records[port].rsed_column = 0;
        }
    }
    hdmi_rx21_lts_records[port].rsed_sample_phase = (hdmi_rx21_lts_records[port].rsed_sample_phase + 1) % hdmi_rx21_lts_records[port].rsed_sample_divider;
}
