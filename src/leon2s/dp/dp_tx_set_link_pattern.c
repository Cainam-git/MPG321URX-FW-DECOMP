/* dp_tx_set_link_pattern  (FUN_a00aa930)
 *
 * Set the link pattern registers of a DP / eDP transmitter for a pattern mode.
 *   output
 *   pattern: pattern 0..10
 * Name basis: derived - modes 0..10 rewrite control registers 9 / 10 / 0x63 / 0x2C..0x2D; callers both link
 *   training phases, TRAINING_NORESPONSE, the test request routine and the unplug step of
 *   dp_tx_run_hpd_actions (pattern 7)
 *
 * Matching notes
 * --------------
 * FUN_a00aa930 (leon2s 0xa00aa930-0xa00aaf90, 1632 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the cases are written in the order 0, 1, 2, 4, 5, 6, 8, 9, 10, 3, default (jump table at 0xa00aa904;
 *    pattern 7 and patterns above 10 take the default arm);
 *  - the dp_tx_phy_write_output_field calls are written inside both arms of the output test (one shared call
 *    after the if changes the argument order of the dp_tx_ctl_reg_update_bits call in pattern 0).
 */

/*
 * Link pattern numbers, by their callers:
 *   0..3  link training: dp_tx_train_clock_recovery uses 0, dp_tx_train_channel_eq 1..3; the same numbers go
 *         to the sink through dp_tx_set_training_pattern / dp_tx_set_pattern_and_levels
 *   4     after a successful training ('Channel[..] is Training done!!', dp_tx_train_links)
 *   7     (default arm) after a failed training ('Training fail') and after an unplug
 *   0, 3, 6, 8, 9, 10  sink test requests: test pattern byte 1, 7, 3, 4, 5, 6 (dp_tx_handle_test_request)
 *   5     no caller passes it
 */
enum link_pattern {
    LINK_PATTERN_TRAIN_0 = 0,
    LINK_PATTERN_TRAIN_1 = 1,
    LINK_PATTERN_TRAIN_2 = 2,
    LINK_PATTERN_TRAIN_3 = 3,
    LINK_PATTERN_TRAINED = 4,
    LINK_PATTERN_5       = 5,
    LINK_PATTERN_6       = 6,
    LINK_PATTERN_DEFAULT = 7,
    LINK_PATTERN_8       = 8,
    LINK_PATTERN_9       = 9,
    LINK_PATTERN_10      = 10
};

#define DP_TX_OUTPUT_0      0       /* output 0 = DP transmitter (control bank 0); 1..4 = eDP outputs */
#define EDP_BLOCK           1       /* any eDP output number reaches the one eDP control block; registers
                                       above 0x5F are not banked (dp_tx_ctl_reg_write8) */

/* Control registers (dp_tx_ctl_reg_*). */
#define CTL_REG_9           9
#define CTL_REG_9_KEEP      0x08    /* output 0: bit 3 of register 9 is kept */
#define CTL_REG_9_BIT7      0x80    /* eDP outputs: only bit 7 of register 9 changes (patterns 3, 9, 10 write it whole) */
#define CTL_REG_10          10
#define CTL_REG_0x2C        0x2c    /* written in pairs: a number 0..0xE to 0x2c, then a byte to 0x2d */
#define CTL_REG_0x2D        0x2d
#define CTL_REG_0x63        0x63    /* eDP block; bits 4..6 take the pattern value, the others are kept */
#define CTL_REG_0x63_KEEP   0x8f
#define CTL_REG_0x64        0x64    /* eDP block */

/* Output 0: register 9 = (old bit 3) | value. */
#define DPTX_SET_REG9(value) \
    dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_9, (dp_tx_ctl_reg_read8(DP_TX_OUTPUT_0, CTL_REG_9) & CTL_REG_9_KEEP) | (value))
/* eDP outputs: register 0x63 = (register 0x63 of the output & 0x8f) | value, written through write_bank. */
#define EDP_SET_REG63(write_bank, output, value) \
    dp_tx_ctl_reg_write8(write_bank, CTL_REG_0x63, (dp_tx_ctl_reg_read8(output, CTL_REG_0x63) & CTL_REG_0x63_KEEP) | (value))

extern unsigned char dp_tx_ctl_reg_read8(unsigned char, short);
extern void dp_tx_ctl_reg_write8(unsigned char, short, unsigned char);
extern void dp_tx_ctl_reg_update_bits(unsigned char, short, unsigned char, unsigned char);
extern void dp_tx_phy_write_output_field(unsigned int, unsigned int);

/*
 * Set the transmitter control registers of a DP or eDP output for one link pattern.
 *
 *   output   0 = DP transmitter, 1..4 = eDP outputs (also the control bank)
 *   pattern  enum link_pattern; 7 and anything above 10 take the default arm
 *
 * Phases, in order:
 *   1. Patterns 3, 6, 8, 9 and 10 first write numbered bytes through registers 0x2c / 0x2d (pattern 8: ten
 *      bytes 0x1f, 0x7c, 0xf0, 0xc1, 0x07 twice for the numbers 0..9, then 1 for 0xE; patterns 3 / 9 / 10:
 *      0xfc, 0, and 2 / 1 / 0 for 0xA..0xC; pattern 6: 0 for 0xE).
 *   2. Output 0: register 9 gets the pattern value with its bit 3 kept, register 10 a second value.
 *      Other outputs: bit 7 of register 9 is set or cleared (patterns 3, 9, 10 write 0x77 to the whole
 *      register), and register 0x63 of the eDP block gets the pattern value in bits 4..6 (patterns 3, 8, 9, 10
 *      write it whole, and 7 to register 0x64 first).
 *   3. Pattern 0 sets the output's PHY field (dp_tx_phy_write_output_field) after the registers; the default
 *      arm clears it before them.
 *
 *   pattern   reg 9 (out 0)   reg 10   eDP reg 9 bit 7   eDP reg 0x63
 *   0         0x91            0x11     set               bits 4..6 = 1
 *   1         0xa2            0x22     set               2
 *   2         0xe6            0x66     set               6
 *   4         0x44            0x44     clear             4
 *   5         0x33            0x33     clear             3
 *   6         0xd5            0x55     set               5
 *   8         0xd5            0x55     set               0xd5 (whole)
 *   3, 9, 10  0x77            0x77     reg 9 = 0x77      0xf5 (whole)
 *   default   0x80            0        clear             0
 */
void dp_tx_set_link_pattern(unsigned char output, unsigned char pattern)
{
    switch (pattern) {
    case LINK_PATTERN_TRAIN_0:
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0x91);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x11);
            dp_tx_phy_write_output_field(DP_TX_OUTPUT_0, 1);
        } else {
            dp_tx_ctl_reg_update_bits(output, CTL_REG_9, CTL_REG_9_BIT7, 1);
            EDP_SET_REG63(EDP_BLOCK, output, 0x10);
            dp_tx_phy_write_output_field(output, 1);
        }
        break;
    case LINK_PATTERN_TRAIN_1:
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0xa2);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x22);
        } else {
            dp_tx_ctl_reg_update_bits(output, CTL_REG_9, CTL_REG_9_BIT7, 1);
            EDP_SET_REG63(EDP_BLOCK, output, 0x20);
        }
        break;
    case LINK_PATTERN_TRAIN_2:
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0xe6);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x66);
        } else {
            dp_tx_ctl_reg_update_bits(output, CTL_REG_9, CTL_REG_9_BIT7, 1);
            EDP_SET_REG63(EDP_BLOCK, output, 0x60);
        }
        break;
    case LINK_PATTERN_TRAINED:
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0x44);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x44);
        } else {
            dp_tx_ctl_reg_update_bits(output, CTL_REG_9, CTL_REG_9_BIT7, 0);
            EDP_SET_REG63(EDP_BLOCK, output, 0x40);
        }
        break;
    case LINK_PATTERN_5:
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0x33);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x33);
        } else {
            dp_tx_ctl_reg_update_bits(output, CTL_REG_9, CTL_REG_9_BIT7, 0);
            EDP_SET_REG63(output, output, 0x30);
        }
        break;
    case LINK_PATTERN_6:
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xe);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x0);
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0xd5);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x55);
        } else {
            dp_tx_ctl_reg_update_bits(output, CTL_REG_9, CTL_REG_9_BIT7, 1);
            EDP_SET_REG63(EDP_BLOCK, output, 0x50);
        }
        break;
    case LINK_PATTERN_8:
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x0);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x1f);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x1);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x7c);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x2);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0xf0);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x3);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0xc1);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x4);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x7);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x5);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x1f);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x6);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x7c);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x7);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0xf0);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x8);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0xc1);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0x9);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x7);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xe);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x1);
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0xd5);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x55);
        } else {
            dp_tx_ctl_reg_write8(EDP_BLOCK, CTL_REG_0x64, 7);
            dp_tx_ctl_reg_update_bits(output, CTL_REG_9, CTL_REG_9_BIT7, 1);
            dp_tx_ctl_reg_write8(EDP_BLOCK, CTL_REG_0x63, 0xd5);
        }
        break;
    case LINK_PATTERN_9:
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xa);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0xfc);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xb);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x0);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xc);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x1);
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0x77);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x77);
        } else {
            dp_tx_ctl_reg_write8(EDP_BLOCK, CTL_REG_0x64, 7);
            dp_tx_ctl_reg_write8(output, CTL_REG_9, 0x77);
            dp_tx_ctl_reg_write8(EDP_BLOCK, CTL_REG_0x63, 0xf5);
        }
        break;
    case LINK_PATTERN_10:
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xa);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0xfc);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xb);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x0);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xc);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x0);
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0x77);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x77);
        } else {
            dp_tx_ctl_reg_write8(EDP_BLOCK, CTL_REG_0x64, 7);
            dp_tx_ctl_reg_write8(output, CTL_REG_9, 0x77);
            dp_tx_ctl_reg_write8(EDP_BLOCK, CTL_REG_0x63, 0xf5);
        }
        break;
    case LINK_PATTERN_TRAIN_3:
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xa);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0xfc);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xb);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x0);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2C, 0xc);
        dp_tx_ctl_reg_write8(output, CTL_REG_0x2D, 0x2);
        if (output == DP_TX_OUTPUT_0) {
            DPTX_SET_REG9(0x77);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0x77);
        } else {
            dp_tx_ctl_reg_write8(EDP_BLOCK, CTL_REG_0x64, 7);
            dp_tx_ctl_reg_write8(output, CTL_REG_9, 0x77);
            dp_tx_ctl_reg_write8(EDP_BLOCK, CTL_REG_0x63, 0xf5);
        }
        break;
    default:
        if (output == DP_TX_OUTPUT_0) {
            dp_tx_phy_write_output_field(DP_TX_OUTPUT_0, 0);
            DPTX_SET_REG9(0x80);
            dp_tx_ctl_reg_write8(DP_TX_OUTPUT_0, CTL_REG_10, 0);
        } else {
            dp_tx_phy_write_output_field(output, 0);
            dp_tx_ctl_reg_update_bits(output, CTL_REG_9, CTL_REG_9_BIT7, 0);
            dp_tx_ctl_reg_write8(output, CTL_REG_0x63, dp_tx_ctl_reg_read8(output, CTL_REG_0x63) & CTL_REG_0x63_KEEP);
        }
        break;
    }
}
