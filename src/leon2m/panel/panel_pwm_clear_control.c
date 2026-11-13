/* panel_pwm_clear_control  (FUN_a011e148)
 *
 * Clear the enable and the two low control bits of a PWM channel.
 * Name basis: descriptive - control register masked with 0x7C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011e148, flags -mcpu=v8 -O3 -g.
 * Source form: the same case list as panel_pwm_enable, but the default arm covers only channels 1..4. The mask
 * 0x7c also clears every bit above bit 7 of the register.
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

/*
 * Clear bit 7 (on/off), bit 1 and bit 0 of the control register of a PWM channel; bits 2..6 are kept.
 *
 *   channel  1..6, 25 and 26 have a register each; 16..24 and 31 share PWM_CTRL_GROUP; every other number clears
 *            the registers of channels 1..4 only (not 5 and 6)
 *
 * Called by panel_blurfree_set_mode and panel_blurfree_apply_mode_second_port with the second blur port, when blur
 * reduction is off or not in GEN2 mode.
 */
void panel_pwm_clear_control(unsigned char channel)
{
    switch (channel) {
    case 1:
        R(PWM_CTRL_CH1) &= 0x7c;
        break;
    case 2:
        R(PWM_CTRL_CH2) &= 0x7c;
        break;
    case 3:
        R(PWM_CTRL_CH3) &= 0x7c;
        break;
    case 4:
        R(PWM_CTRL_CH4) &= 0x7c;
        break;
    case 5:
        R(PWM_CTRL_CH5) &= 0x7c;
        break;
    case 6:
        R(PWM_CTRL_CH6) &= 0x7c;
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
        R(PWM_CTRL_GROUP) &= 0x7c;
        break;
    case 25:
        R(PWM_CTRL_CH25) &= 0x7c;
        break;
    case 26:
        R(PWM_CTRL_CH26) &= 0x7c;
        break;
    default:
        R(PWM_CTRL_CH1) &= 0x7c;
        R(PWM_CTRL_CH2) &= 0x7c;
        R(PWM_CTRL_CH3) &= 0x7c;
        R(PWM_CTRL_CH4) &= 0x7c;
        break;
    }
}
