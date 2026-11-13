/* panel_pwm_set_mode_field  (FUN_a011e220)
 *
 * Write the mode of a PWM channel: a 2-bit field, or one bit plus a shared 2-bit group field.
 * Note: Channels other than 1..6, 16..26 and 31 write nothing; System_Initialize passes 7.
 * Name basis: descriptive - channels 1..6 and 26: bits 4-5 of the channel's control register; 16..25 and 31:
 *   bit 5 plus bits 6-7 of the group register
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011e220, flags -mcpu=v8 -O3 -g.
 * Source form: the map is a const local table and map[mode] is read into the unsigned char group_bits before the
 * bit-5 update of each arm (the address of the map is formed between the register read and its store, which gives
 * the firmware's save / frame pointer set-up); the case order 1..6, 25, 26, 16..24 and 31 gives the shared clear
 * tail and the shared 0xcf016404 tail of the firmware.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Control registers of the PWM channels (see panel_pwm_enable). */
#define PWM_CTRL_CH1   0xcf016120
#define PWM_CTRL_CH2   0xcf016138
#define PWM_CTRL_CH3   0xcf016150
#define PWM_CTRL_CH4   0xcf016168
#define PWM_CTRL_CH5   0xcf016180
#define PWM_CTRL_CH6   0xcf016198
#define PWM_CTRL_GROUP 0xcf016400   /* one register for channels 16..24 and 31 together */
#define PWM_CTRL_CH25  0xcf016494
#define PWM_CTRL_CH26  0xcf0164c0
#define PWM_GROUP_SYNC 0xcf016404   /* reg_panel_pwm_group_sync: bits 6..7 hold the group's mode */

#define PWM_CTRL_MODE_SHIFT 4       /* the mode field of channels 1..6 and 26 is bits 4..5 of the control register */
#define PWM_CTRL_MODE_BIT   0x20    /* channels 16..24, 31 and 25: bit 5 of the control register */

/*
 * Write the mode of a PWM channel.
 *
 *   channel  1..6: mode into bits 4..5 of that channel's control register;
 *            26: the same, but a mode above 1 is limited to 1;
 *            16..24, 31 and 25: mode 0 clears bit 5 of the control register (PWM_CTRL_GROUP for 16..24 and 31,
 *            PWM_CTRL_CH25 for 25); any other mode sets that bit and also writes map[mode] into bits 6..7 of
 *            PWM_GROUP_SYNC;
 *            any other number (System_Initialize passes 7) writes nothing
 *   mode     only the low two bits are used
 *
 * map is {2, 1, 0, 3}: mode 1 gives 1, mode 2 gives 0, mode 3 gives 3. What the modes mean is not shown by the
 * code. Callers: System_Initialize and panel_blurfree_set_mode (with mode 1 for the second blur port and for
 * channel 31) and panel_blurfree_apply_mode_second_port.
 */
void panel_pwm_set_mode_field(unsigned char channel, unsigned char mode)
{
    const unsigned char map[4] = {2, 1, 0, 3};
    unsigned char group_bits;

    mode &= 3;
    switch (channel) {
    case 1:
        R(PWM_CTRL_CH1) = (R(PWM_CTRL_CH1) & 0xcf) | (mode << PWM_CTRL_MODE_SHIFT);
        break;
    case 2:
        R(PWM_CTRL_CH2) = (R(PWM_CTRL_CH2) & 0xcf) | (mode << PWM_CTRL_MODE_SHIFT);
        break;
    case 3:
        R(PWM_CTRL_CH3) = (R(PWM_CTRL_CH3) & 0xcf) | (mode << PWM_CTRL_MODE_SHIFT);
        break;
    case 4:
        R(PWM_CTRL_CH4) = (R(PWM_CTRL_CH4) & 0xcf) | (mode << PWM_CTRL_MODE_SHIFT);
        break;
    case 5:
        R(PWM_CTRL_CH5) = (R(PWM_CTRL_CH5) & 0xcf) | (mode << PWM_CTRL_MODE_SHIFT);
        break;
    case 6:
        R(PWM_CTRL_CH6) = (R(PWM_CTRL_CH6) & 0xcf) | (mode << PWM_CTRL_MODE_SHIFT);
        break;
    case 25:
        if (mode == 0) {
            R(PWM_CTRL_CH25) &= ~PWM_CTRL_MODE_BIT;
        } else {
            group_bits = map[mode];
            R(PWM_CTRL_CH25) |= PWM_CTRL_MODE_BIT;
            R(PWM_GROUP_SYNC) = (R(PWM_GROUP_SYNC) & 0x3f) | (group_bits << 6);
        }
        break;
    case 26:
        if (mode > 1)
            mode = 1;
        R(PWM_CTRL_CH26) = (R(PWM_CTRL_CH26) & 0xcf) | (mode << PWM_CTRL_MODE_SHIFT);
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 31:
        if (mode == 0) {
            R(PWM_CTRL_GROUP) &= ~PWM_CTRL_MODE_BIT;
        } else {
            group_bits = map[mode];
            R(PWM_CTRL_GROUP) |= PWM_CTRL_MODE_BIT;
            R(PWM_GROUP_SYNC) = (R(PWM_GROUP_SYNC) & 0x3f) | (group_bits << 6);
        }
        break;
    }
}
