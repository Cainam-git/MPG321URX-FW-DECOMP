/* panel_pwm_enable_channel  (FUN_a011e8fc)
 *
 * Switch a grouped PWM channel 0x10..0x17 on or off.
 * Name basis: derived - one bit per channel in 0xCF016470
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011e8fc, flags -mcpu=v8 -O3 -g.
 * Source form: one switch in each arm of the if (two jump tables in the firmware).
 */
#define R(a) (*(volatile unsigned int *)(a))

#define PWM_GROUP_ENABLE 0xcf016470     /* one enable bit per grouped channel: bit (channel - 0x10) */

/*
 * Switch one of the grouped PWM channels 0x10..0x17 on or off through its bit in PWM_GROUP_ENABLE.
 *
 *   channel  0x10..0x17; any other number writes nothing
 *   enable   1: set the bit; any other value: clear it
 *
 * Called by panel_blurfree_enable_channels for every channel of the blur-reduction channel mask.
 */
void panel_pwm_enable_channel(unsigned char channel, unsigned char enable)
{
    if (enable == 1) {
        switch (channel) {
        case 0x10:
            R(PWM_GROUP_ENABLE) |= 1;
            break;
        case 0x11:
            R(PWM_GROUP_ENABLE) |= 2;
            break;
        case 0x12:
            R(PWM_GROUP_ENABLE) |= 4;
            break;
        case 0x13:
            R(PWM_GROUP_ENABLE) |= 8;
            break;
        case 0x14:
            R(PWM_GROUP_ENABLE) |= 0x10;
            break;
        case 0x15:
            R(PWM_GROUP_ENABLE) |= 0x20;
            break;
        case 0x16:
            R(PWM_GROUP_ENABLE) |= 0x40;
            break;
        case 0x17:
            R(PWM_GROUP_ENABLE) |= 0x80;
            break;
        }
    } else {
        switch (channel) {
        case 0x10:
            R(PWM_GROUP_ENABLE) &= ~1;
            break;
        case 0x11:
            R(PWM_GROUP_ENABLE) &= ~2;
            break;
        case 0x12:
            R(PWM_GROUP_ENABLE) &= ~4;
            break;
        case 0x13:
            R(PWM_GROUP_ENABLE) &= ~8;
            break;
        case 0x14:
            R(PWM_GROUP_ENABLE) &= ~0x10;
            break;
        case 0x15:
            R(PWM_GROUP_ENABLE) &= ~0x20;
            break;
        case 0x16:
            R(PWM_GROUP_ENABLE) &= ~0x40;
            break;
        case 0x17:
            R(PWM_GROUP_ENABLE) &= ~0x80;
            break;
        }
    }
}
