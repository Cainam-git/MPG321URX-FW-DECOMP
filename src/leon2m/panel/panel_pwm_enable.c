/* panel_pwm_enable  (FUN_a011e028)
 *
 * Switch a PWM channel on or off; other channel numbers switch the six main ones.
 * Name basis: derived - bit 7 of the channel's control register
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011e028, flags -mcpu=v8 -O3 -g.
 * Source form: the bit value starts as a copy of the argument (`bit = enable; if (bit) bit = 0x80;`), which keeps
 * the firmware's branch instead of an if-converted flag; the switch lists cases 1..6, 16..24 and 31, 25, 26 and
 * then default. The mask 0x7f also clears every bit above bit 7 of the register.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Control registers of the PWM channels; bit 7 of each switches the channel on. */
#define PWM_CTRL_CH1   0xcf016120
#define PWM_CTRL_CH2   0xcf016138
#define PWM_CTRL_CH3   0xcf016150
#define PWM_CTRL_CH4   0xcf016168
#define PWM_CTRL_CH5   0xcf016180
#define PWM_CTRL_CH6   0xcf016198
#define PWM_CTRL_GROUP 0xcf016400   /* one register for channels 16..24 and 31 together */
#define PWM_CTRL_CH25  0xcf016494
#define PWM_CTRL_CH26  0xcf0164c0
#define PWM_CTRL_ENABLE 0x80

/*
 * Switch a PWM channel on or off by writing bit 7 of its control register (bits 0..6 are kept).
 *
 *   channel  1..6, 25 and 26 have a register each; 16..24 and 31 share PWM_CTRL_GROUP; every other number
 *            (callers pass 0 for this) switches all six main channels 1..6
 *   enable   non-zero: on; 0: off
 *
 * Callers: startup_init_converter_sources and sys_shut_down_blocks (channel 0; the shut-down also switches
 * channel 31 off) and panel_blurfree_set_mode (the second blur port, and channel 31 on).
 */
void panel_pwm_enable(unsigned char channel, unsigned char enable)
{
    unsigned int bit = enable;

    if (bit)
        bit = PWM_CTRL_ENABLE;
    switch (channel) {
    case 1:
        R(PWM_CTRL_CH1) = (R(PWM_CTRL_CH1) & 0x7f) | bit;
        break;
    case 2:
        R(PWM_CTRL_CH2) = (R(PWM_CTRL_CH2) & 0x7f) | bit;
        break;
    case 3:
        R(PWM_CTRL_CH3) = (R(PWM_CTRL_CH3) & 0x7f) | bit;
        break;
    case 4:
        R(PWM_CTRL_CH4) = (R(PWM_CTRL_CH4) & 0x7f) | bit;
        break;
    case 5:
        R(PWM_CTRL_CH5) = (R(PWM_CTRL_CH5) & 0x7f) | bit;
        break;
    case 6:
        R(PWM_CTRL_CH6) = (R(PWM_CTRL_CH6) & 0x7f) | bit;
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
        R(PWM_CTRL_GROUP) = (R(PWM_CTRL_GROUP) & 0x7f) | bit;
        break;
    case 25:
        R(PWM_CTRL_CH25) = (R(PWM_CTRL_CH25) & 0x7f) | bit;
        break;
    case 26:
        R(PWM_CTRL_CH26) = (R(PWM_CTRL_CH26) & 0x7f) | bit;
        break;
    default:
        R(PWM_CTRL_CH1) = (R(PWM_CTRL_CH1) & 0x7f) | bit;
        R(PWM_CTRL_CH2) = (R(PWM_CTRL_CH2) & 0x7f) | bit;
        R(PWM_CTRL_CH3) = (R(PWM_CTRL_CH3) & 0x7f) | bit;
        R(PWM_CTRL_CH4) = (R(PWM_CTRL_CH4) & 0x7f) | bit;
        R(PWM_CTRL_CH5) = (R(PWM_CTRL_CH5) & 0x7f) | bit;
        R(PWM_CTRL_CH6) = (R(PWM_CTRL_CH6) & 0x7f) | bit;
        break;
    }
}
