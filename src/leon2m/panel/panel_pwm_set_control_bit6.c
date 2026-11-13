/* panel_pwm_set_control_bit6  (FUN_a011e388)
 *
 * Write control bit 6 of a PWM channel.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011e388, flags -mcpu=v8 -O3 -g.
 * Source form: the value is masked to one bit first; the mask 0xbf also clears every bit above bit 7 of the
 * register. The case list is that of panel_pwm_enable.
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

#define PWM_CTRL_BIT6_SHIFT 6

/*
 * Write bit 6 of the control register of a PWM channel; the other bits 0..5 and 7 are kept.
 *
 *   channel  1..6, 25 and 26 have a register each; 16..24 and 31 share PWM_CTRL_GROUP; any other number
 *            writes nothing
 *   value    only the lowest bit is used
 *
 * The only caller, panel_blurfree_set_mode, sets bit 6 of channel 31 with it. What the bit does is not shown by
 * the code.
 */
void panel_pwm_set_control_bit6(unsigned char channel, unsigned char value)
{
    value &= 1;
    switch (channel) {
    case 1:
        R(PWM_CTRL_CH1) = (R(PWM_CTRL_CH1) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
        break;
    case 2:
        R(PWM_CTRL_CH2) = (R(PWM_CTRL_CH2) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
        break;
    case 3:
        R(PWM_CTRL_CH3) = (R(PWM_CTRL_CH3) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
        break;
    case 4:
        R(PWM_CTRL_CH4) = (R(PWM_CTRL_CH4) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
        break;
    case 5:
        R(PWM_CTRL_CH5) = (R(PWM_CTRL_CH5) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
        break;
    case 6:
        R(PWM_CTRL_CH6) = (R(PWM_CTRL_CH6) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
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
        R(PWM_CTRL_GROUP) = (R(PWM_CTRL_GROUP) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
        break;
    case 25:
        R(PWM_CTRL_CH25) = (R(PWM_CTRL_CH25) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
        break;
    case 26:
        R(PWM_CTRL_CH26) = (R(PWM_CTRL_CH26) & 0xbf) | (value << PWM_CTRL_BIT6_SHIFT);
        break;
    }
}
