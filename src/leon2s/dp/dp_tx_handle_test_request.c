/* dp_tx_handle_test_request  (FUN_a00883d0)
 *
 * Answer a sink's automated test request (link training test).
 * Returns: 0 = nothing more to do (also after a bit-1 request), 1 = retrain the link, 2 = test pattern set up
 * Name basis: derived - clears DPCD 0x201 bit 1, reads TEST_REQUEST 0x218, TEST_LINK_RATE 0x219,
 *   TEST_LANE_COUNT 0x220
 *
 * Matching notes
 * --------------
 * FUN_a00883d0 (leon2s 0xa00883d0-0xa008899c, 1484 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the shared AUX buffer and the limit bytes are volatile (the code reads them again for every test and after
 *    every store, and keeps the limit stores out of delay slots);
 *  - the first two link rate tests load into rate, the third into a second variable rate_10;
 *  - the two drive selectors are unsigned char locals cleared at the start and passed as (x & 3);
 *  - nested ifs with one final 'return 0' (one exit block shared by the three 0 results).
 */

/*
 * Despite their names, dp_tx_limits_port0 and dp_tx_limits_others are each one {link rate code, lane count}
 * pair: the first belongs to output 0, the second is shared by all other outputs.
 */
#define LIMIT_LINK_RATE   0
#define LIMIT_LANE_COUNT  1

extern volatile unsigned char dp_tx_aux_data_byte[];     /* shared buffer of the AUX transfers below */
extern volatile unsigned char dp_tx_limits_port0[];     /* limit pair of output 0 */
extern volatile unsigned char dp_tx_limits_others[];      /* limit pair of outputs 1..4 */
extern volatile unsigned char dp_tx_link_option_port0;
extern volatile unsigned char dp_tx_link_option_others;
#define REG_CF013000 (*(volatile unsigned int *)0xcf013000)

#define DP_TX_OUTPUT_0        0
#define AUX_CMD_WRITE         0x80
#define AUX_CMD_READ          0x90

/* Sink addresses read and written over AUX. */
#define SINK_ADDR_0x000       0x000     /* 6 bytes read; bit 0 of byte 3 becomes the link option */
#define SINK_LINK_RATE_COPY   0x100     /* receives the test link rate (bit 0 requests) */
#define SINK_LANE_COUNT_COPY  0x101     /* receives the test lane count (bit 0 requests) */
#define SINK_ADDR_0x201       0x201
#define SINK_ADJUST_0x206     0x206     /* bits 0..1 and 2..3 select the drive levels */
#define SINK_TEST_REQUEST     0x218
#define SINK_TEST_LINK_RATE   0x219
#define SINK_TEST_LANE_COUNT  0x220
#define SINK_ADDR_0x221       0x221
#define SINK_ADDR_0x232       0x232     /* read, value not used */
#define SINK_TEST_PATTERN     0x248     /* selects the link pattern (bit 3 requests) */
#define SINK_ADDR_0x260       0x260     /* 1 is written before the bit 0 answer */

/* Link status record of the caller (dp_tx_read_link_status): byte 2 is the sink byte at 0x201; when it is not 0
   the eDP caller prints 'eDPAction IRQVectorHandle'. */
#define LINK_STATUS_SINK_201  2
#define SINK_201_TEST_BIT     0x02      /* set: read the test request; written back to 0x201 */

/* Bits of the test request byte at 0x218, by what this routine does for them. */
#define TEST_REQUEST_LINK     0x01      /* take over the test link rate and lane count, retrain */
#define TEST_REQUEST_BIT1     0x02      /* follow the low nibble of sink byte 0x221 */
#define TEST_REQUEST_PATTERN  0x08      /* set up the link and the pattern of sink byte 0x248 */

/* Link rate codes (as dp_tx_limits_others). */
#define LINK_RATE_RBR         0x06
#define LINK_RATE_HBR         0x0A
#define LINK_RATE_HBR2        0x14
#define LINK_RATE_HBR3        0x1E

/* Transmitter registers (dp_tx_reg_*). */
#define TX_REG_LINK_RATE      2
#define TX_REG_LANE_COUNT     3         /* 0x80 + lane count; bit 6 is kept */
#define TX_REG_LANE_COUNT_KEEP 0x40
#define CTL_REG_0x64          100

/* Results. */
#define TEST_RESULT_NONE      0         /* nothing done, or only the bit 1 request */
#define TEST_RESULT_RETRAIN   1         /* the callers train the link again */
#define TEST_RESULT_DONE      2         /* the caller cancels all other steps */

extern unsigned char dp_tx_aux_write_byte(unsigned char, unsigned char, unsigned int, unsigned char);
extern unsigned char dp_tx_aux_read_byte(unsigned char, unsigned char, unsigned int, volatile unsigned char *);
extern unsigned char dp_tx_aux_request_copy(unsigned char, unsigned char, unsigned int, char, volatile unsigned char *);
extern void dp_tx_reg_update_bits(unsigned int, short, unsigned int, unsigned int);
extern void dp_tx_set_drive_levels(unsigned char, unsigned char, unsigned char);
extern void dp_tx_phy_write_output_field(unsigned int, unsigned int);
extern void dp_tx_phy_set_link_rate(unsigned char, unsigned char, unsigned char, unsigned char);
extern void dp_tx_ctl_reg_write8(unsigned char, short, unsigned char);
extern void dp_tx_set_link_pattern(unsigned char, unsigned char);
extern void dp_tx_reg_write8(unsigned int, unsigned short, unsigned int);
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);

/*
 * Look at the sink's test request and carry it out.
 *
 *   port         DP output 0..4
 *   link_status  the 16-byte link status record the caller has just read (dp_tx_read_link_status)
 *
 * Called by dp_tx_run_hpd_actions (DPTX_IsHPDAction_Off) and dp_tx_edp_run_hpd_actions (eDP_IsHPDAction_Off)
 * when byte 2 of the record is not 0. Returns TEST_RESULT_NONE, _RETRAIN or _DONE (see above).
 *
 * Nothing happens unless bit 1 of sink byte 0x201 is set. Then 2 is written to 0x201, the test request at
 * 0x218 is read, and the first matching bit decides:
 *   bit 0  write 1 to 0x260; read the test link rate (0x219) and the test lane count (0x220), store them in the
 *          limit pair of output 0 (whatever the output) and copy them to sink addresses 0x100 and 0x101.
 *          Returns _RETRAIN.
 *   bit 1  read 0x221: a non-zero low nibble sets bit 0 of transmitter register 0x78 and bit 4 of 0xCF013000,
 *          otherwise both are cleared. Returns _NONE.
 *   bit 3  phases, in order:
 *            1. write byte 1 of the shared AUX buffer (not filled by this routine) to 0x201;
 *            2. read 6 bytes from sink address 0: bit 0 of byte 3 becomes the output's link option;
 *            3. read 0x206..0x208 and set the drive levels from the two low bit pairs of 0x206;
 *            4. read 0x218..0x21a; clear the output's PHY field; the test link rate (0x219; 0x1E, 0x14 and 0x0A
 *               are kept, anything else becomes 0x06) goes to the output's limit pair and to
 *               dp_tx_phy_set_link_rate;
 *            5. read 0x220..0x222 and store 0x80 + lane count (1, 2 or 4) in the limit pair; for output 0 the
 *               values 2 and 4 are taken from 0x221, not 0x220; any other value leaves the stored byte;
 *            6. read 0x232..0x234 and the pattern byte 0x248;
 *            7. control register 0x64 = 7 (outputs 1..4 only); link pattern 0; transmitter registers 2 and 3
 *               get the link rate and lane count;
 *            8. the pattern byte 1, 3, 4, 5, 6, 7 selects link pattern 0, 6, 8, 9, 10, 3; 2 and other values keep
 *               pattern 0.
 *          Returns _DONE.
 */
unsigned char dp_tx_handle_test_request(unsigned char port, unsigned char *link_status)
{
    unsigned char adjust_low = 0;   /* bits 0..1 of sink byte 0x206 */
    unsigned char adjust_high = 0;  /* bits 2..3 of sink byte 0x206 */
    unsigned char rate;
    unsigned char rate_10;
    unsigned int reg3_kept;

    if (link_status[LINK_STATUS_SINK_201] & SINK_201_TEST_BIT) {
        dp_tx_aux_write_byte(port, AUX_CMD_WRITE, SINK_ADDR_0x201, SINK_201_TEST_BIT);
        dp_tx_aux_request_copy(port, AUX_CMD_READ, SINK_TEST_REQUEST, 0, dp_tx_aux_data_byte);

        /* Bit 0: copy the requested link rate and lane count to the sink and retrain. */
        if (dp_tx_aux_data_byte[0] & TEST_REQUEST_LINK) {
            dp_tx_aux_write_byte(port, AUX_CMD_WRITE, SINK_ADDR_0x260, 1);
            dp_tx_aux_read_byte(port, AUX_CMD_READ, SINK_TEST_LINK_RATE, dp_tx_aux_data_byte);
            dp_tx_limits_port0[LIMIT_LINK_RATE] = dp_tx_aux_data_byte[0];
            dp_tx_aux_write_byte(port, AUX_CMD_WRITE, SINK_LINK_RATE_COPY, dp_tx_aux_data_byte[0]);
            dp_tx_aux_read_byte(port, AUX_CMD_READ, SINK_TEST_LANE_COUNT, dp_tx_aux_data_byte);
            dp_tx_limits_port0[LIMIT_LANE_COUNT] = dp_tx_aux_data_byte[0];
            dp_tx_aux_write_byte(port, AUX_CMD_WRITE, SINK_LANE_COUNT_COPY, dp_tx_aux_data_byte[0]);
            return TEST_RESULT_RETRAIN;
        }

        /* Bit 1: register 0x78 bit 0 and 0xCF013000 bit 4 follow the low nibble of sink byte 0x221. */
        if (dp_tx_aux_data_byte[0] & TEST_REQUEST_BIT1) {
            dp_tx_aux_read_byte(port, AUX_CMD_READ, SINK_ADDR_0x221, dp_tx_aux_data_byte);
            if (dp_tx_aux_data_byte[0] & 0xf) {
                dp_tx_reg_update_bits(port, 0x78, 1, 1);
                REG_CF013000 |= 0x10;
            } else {
                dp_tx_reg_update_bits(port, 0x78, 1, 0);
                REG_CF013000 &= ~0x10;
            }
        } else if (dp_tx_aux_data_byte[0] & TEST_REQUEST_PATTERN) {
            /* Bit 3, phase 1. */
            dp_tx_aux_write_byte(port, AUX_CMD_WRITE, SINK_ADDR_0x201, dp_tx_aux_data_byte[1]);

            /* Phase 2: link option from sink byte 3. */
            dp_tx_aux_request_copy(port, AUX_CMD_READ, SINK_ADDR_0x000, 5, dp_tx_aux_data_byte);
            if (port == DP_TX_OUTPUT_0)
                dp_tx_link_option_port0 = dp_tx_aux_data_byte[3] & 1;
            else
                dp_tx_link_option_others = dp_tx_aux_data_byte[3] & 1;

            /* Phase 3: drive levels. */
            dp_tx_aux_request_copy(port, AUX_CMD_READ, SINK_ADJUST_0x206, 2, dp_tx_aux_data_byte);
            if ((dp_tx_aux_data_byte[0] & 3) == 0)
                adjust_low = 0;
            else if ((dp_tx_aux_data_byte[0] & 3) == 1)
                adjust_low = 1;
            else if ((dp_tx_aux_data_byte[0] & 3) == 2)
                adjust_low = 2;
            else if ((dp_tx_aux_data_byte[0] & 3) == 3)
                adjust_low = 3;
            if ((dp_tx_aux_data_byte[0] & 0xc) == 0)
                adjust_high = 0;
            else if ((dp_tx_aux_data_byte[0] & 0xc) == 4)
                adjust_high = 1;
            else if ((dp_tx_aux_data_byte[0] & 0xc) == 8)
                adjust_high = 2;
            else if ((dp_tx_aux_data_byte[0] & 0xc) == 0xc)
                adjust_high = 3;
            dp_tx_set_drive_levels(port, adjust_high & 3, adjust_low & 3);    /* level, mode */

            /* Phase 4: link rate from 0x219 (buffer byte 1). */
            dp_tx_aux_request_copy(port, AUX_CMD_READ, SINK_TEST_REQUEST, 2, dp_tx_aux_data_byte);
            dp_tx_phy_write_output_field(port, 0);
            if (port == DP_TX_OUTPUT_0) {
                if ((rate = dp_tx_aux_data_byte[1]) == LINK_RATE_HBR3 || (rate = dp_tx_aux_data_byte[1]) == LINK_RATE_HBR2)
                    dp_tx_limits_port0[LIMIT_LINK_RATE] = rate;
                else if ((rate_10 = dp_tx_aux_data_byte[1]) == LINK_RATE_HBR)
                    dp_tx_limits_port0[LIMIT_LINK_RATE] = rate_10;
                else
                    dp_tx_limits_port0[LIMIT_LINK_RATE] = LINK_RATE_RBR;
                dp_tx_phy_set_link_rate(port, dp_tx_limits_port0[LIMIT_LINK_RATE], dp_tx_link_option_port0, 1);
            } else {
                if ((rate = dp_tx_aux_data_byte[1]) == LINK_RATE_HBR3 || (rate = dp_tx_aux_data_byte[1]) == LINK_RATE_HBR2)
                    dp_tx_limits_others[LIMIT_LINK_RATE] = rate;
                else if ((rate_10 = dp_tx_aux_data_byte[1]) == LINK_RATE_HBR)
                    dp_tx_limits_others[LIMIT_LINK_RATE] = rate_10;
                else
                    dp_tx_limits_others[LIMIT_LINK_RATE] = LINK_RATE_RBR;
                dp_tx_phy_set_link_rate(port, dp_tx_limits_others[LIMIT_LINK_RATE], dp_tx_link_option_others, 1);
            }

            /* Phase 5: lane count from 0x220 (output 0 tests 0x221 for 2 and 4). */
            dp_tx_aux_request_copy(port, AUX_CMD_READ, SINK_TEST_LANE_COUNT, 2, dp_tx_aux_data_byte);
            if (port == DP_TX_OUTPUT_0) {
                if (dp_tx_aux_data_byte[0] == 1)
                    dp_tx_limits_port0[LIMIT_LANE_COUNT] = 0x81;
                else if (dp_tx_aux_data_byte[1] == 2)
                    dp_tx_limits_port0[LIMIT_LANE_COUNT] = 0x82;
                else if (dp_tx_aux_data_byte[1] == 4)
                    dp_tx_limits_port0[LIMIT_LANE_COUNT] = 0x84;
            } else {
                if (dp_tx_aux_data_byte[0] == 1)
                    dp_tx_limits_others[LIMIT_LANE_COUNT] = 0x81;
                else if (dp_tx_aux_data_byte[0] == 2)
                    dp_tx_limits_others[LIMIT_LANE_COUNT] = 0x82;
                else if (dp_tx_aux_data_byte[0] == 4)
                    dp_tx_limits_others[LIMIT_LANE_COUNT] = 0x84;
            }

            /* Phase 6: the pattern byte ends up in buffer byte 0. */
            dp_tx_aux_request_copy(port, AUX_CMD_READ, SINK_ADDR_0x232, 2, dp_tx_aux_data_byte);
            dp_tx_aux_read_byte(port, AUX_CMD_READ, SINK_TEST_PATTERN, dp_tx_aux_data_byte);

            /* Phase 7: link rate and lane count into the transmitter. */
            if (port != DP_TX_OUTPUT_0)
                dp_tx_ctl_reg_write8(port, CTL_REG_0x64, 7);
            dp_tx_set_link_pattern(port, 0);
            if (port == DP_TX_OUTPUT_0) {
                dp_tx_reg_write8(port, TX_REG_LINK_RATE, dp_tx_limits_port0[LIMIT_LINK_RATE]);
                reg3_kept = dp_tx_reg_read8(port, TX_REG_LANE_COUNT) & TX_REG_LANE_COUNT_KEEP;
                dp_tx_reg_write8(port, TX_REG_LANE_COUNT, dp_tx_limits_port0[LIMIT_LANE_COUNT] | reg3_kept);
            } else {
                dp_tx_reg_write8(port, TX_REG_LINK_RATE, dp_tx_limits_others[LIMIT_LINK_RATE]);
                reg3_kept = dp_tx_reg_read8(port, TX_REG_LANE_COUNT) & TX_REG_LANE_COUNT_KEEP;
                dp_tx_reg_write8(port, TX_REG_LANE_COUNT, dp_tx_limits_others[LIMIT_LANE_COUNT] | reg3_kept);
            }

            /* Phase 8: link pattern requested by sink byte 0x248. */
            switch (dp_tx_aux_data_byte[0]) {
            case 1:
                dp_tx_set_link_pattern(port, 0);
                break;
            case 2:
                break;
            case 3:
                dp_tx_set_link_pattern(port, 6);
                break;
            case 4:
                dp_tx_set_link_pattern(port, 8);
                break;
            case 5:
                dp_tx_set_link_pattern(port, 9);
                break;
            case 6:
                dp_tx_set_link_pattern(port, 10);
                break;
            case 7:
                dp_tx_set_link_pattern(port, 3);
                break;
            }
            return TEST_RESULT_DONE;
        }
    }
    return TEST_RESULT_NONE;
}
