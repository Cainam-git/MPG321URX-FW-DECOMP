/* panel_pwm_set_channel_delay  (FUN_a011e4c8)
 *
 * Write the delay byte of a PWM channel 16..24, or of all nine.
 * Name basis: derived - registers 0xCF016450..0xCF01646C and 0xCF01647C; used by the blur-reduction delays
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011e4c8, flags -mcpu=v8 -O3 -g.
 * Source form: one case per channel 16..24 and a default arm that repeats the nine writes.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define PWM_CHANNEL_REFERENCE 24    /* the reference channel of blur reduction */

/*
 * Write the delay byte of one PWM channel of the group 16..24, or of all nine.
 *
 *   channel  16..23: register 0xCF016450 + 4 * (channel - 16); 24 (PWM_CHANNEL_REFERENCE): 0xCF01647C; any
 *            other number: all nine registers
 *   delay    byte written unchanged
 *
 * Only panel_blurfree_apply_channel_delays calls it: it writes the stored delay of each channel 16..23 whose
 * stored byte is not 0xFF, then the reference delay to channel 24.
 */
void panel_pwm_set_channel_delay(unsigned char channel, unsigned char delay)
{
    switch (channel) {
    case 16:
        R(0xcf016450) = delay;
        break;
    case 17:
        R(0xcf016454) = delay;
        break;
    case 18:
        R(0xcf016458) = delay;
        break;
    case 19:
        R(0xcf01645c) = delay;
        break;
    case 20:
        R(0xcf016460) = delay;
        break;
    case 21:
        R(0xcf016464) = delay;
        break;
    case 22:
        R(0xcf016468) = delay;
        break;
    case 23:
        R(0xcf01646c) = delay;
        break;
    case PWM_CHANNEL_REFERENCE:
        R(0xcf01647c) = delay;
        break;
    default:
        R(0xcf016450) = delay;
        R(0xcf016454) = delay;
        R(0xcf016458) = delay;
        R(0xcf01645c) = delay;
        R(0xcf016460) = delay;
        R(0xcf016464) = delay;
        R(0xcf016468) = delay;
        R(0xcf01646c) = delay;
        R(0xcf01647c) = delay;
        break;
    }
}
