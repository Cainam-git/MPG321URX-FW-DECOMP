/* input_block_detect_sync_mode  (FUN_a0120de4)
 *
 * Work out the sync mode 1..5 of the signal on an input block.
 * Returns: mode
 * Name basis: derived - from register 0x11 bits, the block configuration and range checks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120de4 @ 0xa0120de4-0xa01211ac (242 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: a switch with an explicit 'default: sync_mode = 1' (case 0xc1 keeps its own compare node) and
 * 0xe1/0xe2 on one label (a range node), which gives the firmware's compare tree; measure_values_plausible is a
 * static helper returning unsigned char with early returns and unsigned short locals; the record test is one
 * '||' condition; the limits are written as 602.6 * 0.1, 503 * 0.1 and 303.8 * 0.1, whose folded products are the
 * firmware's constants at 0x1a2fe0/0x1a2fe8/0x1a2ff0 (the literals 60.26, 50.3 and 30.38 round one unit lower).
 * Cases 0x13 and 0x21 share one label and the case ends with 'goto out;' to 'out: return sync_mode;' after the
 * switch; this gives the firmware's placement of the 0x51/0x61 compare block (0xa0120fa8) before the 0xa1
 * compare block (0xa0120fc0).
 */
/* One entry of input_block_configs (12 bytes). Only word_0 is read here. */
struct input_block_config { unsigned int word_0; unsigned int word_4; unsigned int word_8; };
extern struct input_block_config input_block_configs[];
extern unsigned char input_measure_read8(unsigned char blk, unsigned char reg);
extern unsigned short input_measure_read16(unsigned char, unsigned char);

/* Measure block registers read here. */
#define MEASURE_REG_STATUS      0x11        /* the bits tested per signal code in input_block_detect_sync_mode */
#define MEASURE_REG_22          0x22
#define MEASURE_REG_23          0x23
#define MEASURE_PAIR_12         0x12        /* 16-bit, low 13 bits used */
#define MEASURE_PAIR_14         0x14        /* 16-bit, low 13 bits used */
#define MEASURE_PAIR_26         0x26        /* 16-bit; the value plus 1 is tested */
#define MEASURE_13BIT_MASK      0x1fff      /* 0x1fff itself is rejected in both pairs */

/*
 * Check the readings of a measure block that sync mode 4 (signal codes 0x13 and 0x21) requires. Returns 1 when
 * all of these hold, 0 as soon as one fails:
 *   register 0x23 is 1..15;
 *   register 0x22 is not above (13-bit pair 0x12) / 48;
 *   13-bit pair 0x12 is at least 0x280 and not 0x1fff;
 *   13-bit pair 0x14 is at least 0x200 and not 0x1fff;
 *   n = pair 0x26 + 1 is at least 0xc8, and register 0x22 (compared as a floating-point number) is not above
 *   60.26 when n is up to 0x17b, 50.3 when n is up to 0x2d9, and 30.38 for larger n.
 * The purpose of the single limits is not shown by the code.
 */
static unsigned char measure_values_plausible(unsigned char blk)
{
    unsigned short reg23_value, count_plus_one;
    unsigned short reg22_value;
    unsigned short pair_value;

    reg23_value = input_measure_read8(blk, MEASURE_REG_23);
    if (reg23_value < 1 || reg23_value > 15)
        return 0;
    reg22_value = input_measure_read8(blk, MEASURE_REG_22);
    pair_value = input_measure_read16(blk, MEASURE_PAIR_12) & MEASURE_13BIT_MASK;
    if (reg22_value > (unsigned short)(pair_value / 48))
        return 0;
    pair_value = input_measure_read16(blk, MEASURE_PAIR_12) & MEASURE_13BIT_MASK;
    if (pair_value < 0x280 || pair_value == 0x1fff)
        return 0;
    pair_value = input_measure_read16(blk, MEASURE_PAIR_14) & MEASURE_13BIT_MASK;
    if (pair_value < 0x200 || pair_value == 0x1fff)
        return 0;
    reg22_value = input_measure_read8(blk, MEASURE_REG_22);
    count_plus_one = input_measure_read16(blk, MEASURE_PAIR_26) + 1;
    if (count_plus_one < 0xc8)
        return 0;
    if (count_plus_one <= 0x17b) {
        if (reg22_value > 602.6 * 0.1)
            return 0;
    } else if (count_plus_one <= 0x2d9) {
        if (reg22_value > 503 * 0.1)
            return 0;
    } else {
        if (reg22_value > 303.8 * 0.1)
            return 0;
    }
    return 1;
}

/*
 * Work out the sync mode (1 to 5) of the signal on an input block from the bits of its status register.
 *
 *   signal_code  the signal code of the block (input_block_get_signal_code)
 *   blk          input block (measure block registers; the entry of input_block_configs for the block)
 *
 * Returns 1 when no sync mode is recognised, or 2 to 5. The test depends on the signal code; "status" is
 * measure register 0x11:
 *   0x11           (status & 0xf8) == 0x18 gives 2, == 0x38 gives 3
 *   0x12           (status & 0xf8) == 0x28 gives 3
 *   0x13, 0x21     (status & 0xe0) == 0x20 and measure_values_plausible gives 4
 *   0x31, 0x41, 0x51, 0x61   5 when word_0 of the block's configuration is 1 and (status & 0xc0) == 0, or
 *                  when word_0 is not 1 and (status & 0x18) == 0x18
 *   0x71, 0x81     (status & 0xc0) == 0 gives 5
 *   0x91, 0xa1     always 5
 *   0xb1, 0xe1, 0xe2   (status & 0xd8) == 0x18 gives 5
 *   0xe8           always 2 (nothing is read)
 *   0xc1 and any other code   1
 * Every case that does not match gives 1.
 *
 * Called by input_block_handle_mode_change (and by input_block_detect_sync_mode_auto, which nothing calls).
 * input_port_sync_task stays in (or goes back to) its state 2 while the result is 1; a result of 2 to 5 that
 * stays the same for more than 100 ticks takes it on to its state 4.
 */
unsigned char input_block_detect_sync_mode(unsigned char signal_code, unsigned char blk)
{
    int sync_mode = 1;

    switch (signal_code) {
    case 0x11:
        if ((input_measure_read8(blk, MEASURE_REG_STATUS) & 0xf8) == 0x18)
            sync_mode = 2;
        else if ((input_measure_read8(blk, MEASURE_REG_STATUS) & 0xf8) == 0x38)
            sync_mode = 3;
        break;
    case 0x12:
        if ((input_measure_read8(blk, MEASURE_REG_STATUS) & 0xf8) == 0x28)
            sync_mode = 3;
        break;
    case 0x13:
    case 0x21:
        if ((input_measure_read8(blk, MEASURE_REG_STATUS) & 0xe0) == 0x20)
            sync_mode = measure_values_plausible(blk) ? 4 : 1;
        goto out;
    case 0x31:
    case 0x41:
    case 0x51:
    case 0x61:
        if ((input_block_configs[blk].word_0 == 1 && (input_measure_read8(blk, MEASURE_REG_STATUS) & 0xc0) == 0)
            || (input_block_configs[blk].word_0 != 1 && (input_measure_read8(blk, MEASURE_REG_STATUS) & 0x18) == 0x18))
            sync_mode = 5;
        break;
    case 0x71:
    case 0x81:
        if ((input_measure_read8(blk, MEASURE_REG_STATUS) & 0xc0) == 0)
            sync_mode = 5;
        break;
    case 0x91:
    case 0xa1:
        sync_mode = 5;
        break;
    case 0xb1:
    case 0xe1:
    case 0xe2:
        if ((input_measure_read8(blk, MEASURE_REG_STATUS) & 0xd8) == 0x18)
            sync_mode = 5;
        break;
    case 0xc1:
        break;
    case 0xe8:
        sync_mode = 2;
        break;
    default:
        sync_mode = 1;
        break;
    }
out:
    return sync_mode;
}
