/* panel_pwm_set_duty  (FUN_a011dd9c)
 *
 * Write the 10-bit duty value of a PWM channel.
 * Note: Channels without a case (7, 0xFF and all others outside 1..6 and 16..26) write nothing.
 * Name basis: derived - low two bits and upper eight bits to the register pair of one of 17 channels
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011dd9c, flags -mcpu=v8 -O3 -g.
 * Source form: the case order 1, 17..22, 26, 24, 2..6, 25, 23, 16 gives the firmware's block order and register
 * use; the upper part is (unsigned short)duty >> 2, the lower part duty & 3.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define PWM_CHANNEL_REFERENCE 24    /* the channel blur reduction sets to its cycle length */

/*
 * Write the 10-bit duty value of one PWM channel. The value is split over two registers of the channel: the
 * lowest two bits go to the "low" register, the rest (value >> 2) to the "high" register, which sits 4 bytes below
 * it for the main channels and 4 bytes above it for the others.
 *
 *   channel  1..6, 16..26; any other number (7 and 0xFF are passed by some callers) writes nothing
 *   duty     10-bit duty value, 0..0x3FF. It is not masked: bits above bit 9 of the 16-bit value would reach
 *            the high register
 *
 * Registers (low / high):
 *   channels 1..6     0xCF016130 + 0x18 * (channel - 1)  /  4 bytes below it
 *   channels 16..23   0xCF016410 + 8 * (channel - 16)    /  4 bytes above it
 *   channel 24        0xCF016474 / 0xCF016478
 *   channel 25        0xCF0164A0 / 0xCF0164A4
 *   channel 26        0xCF0164CC / 0xCF0164D0
 *
 * Called by the blur-reduction routines (panel_blurfree_set_mode, SetPSMMixMode, the periodic task and the
 * channel-mask writers) and by panel_user_set_pwm7_percent, sys_api_set_pwm7_duty and panel_api_set_pwm_duty_channel_ff,
 * which pass channels this routine does not handle.
 */
void panel_pwm_set_duty(unsigned char channel, unsigned int duty)
{
    switch (channel) {
    case 1:
        R(0xcf016130) = duty & 3;
        R(0xcf01612c) = (unsigned short)duty >> 2;
        break;
    case 17:
        R(0xcf016418) = duty & 3;
        R(0xcf01641c) = (unsigned short)duty >> 2;
        break;
    case 18:
        R(0xcf016420) = duty & 3;
        R(0xcf016424) = (unsigned short)duty >> 2;
        break;
    case 19:
        R(0xcf016428) = duty & 3;
        R(0xcf01642c) = (unsigned short)duty >> 2;
        break;
    case 20:
        R(0xcf016430) = duty & 3;
        R(0xcf016434) = (unsigned short)duty >> 2;
        break;
    case 21:
        R(0xcf016438) = duty & 3;
        R(0xcf01643c) = (unsigned short)duty >> 2;
        break;
    case 22:
        R(0xcf016440) = duty & 3;
        R(0xcf016444) = (unsigned short)duty >> 2;
        break;
    case 26:
        R(0xcf0164cc) = duty & 3;
        R(0xcf0164d0) = (unsigned short)duty >> 2;
        break;
    case PWM_CHANNEL_REFERENCE:
        R(0xcf016474) = duty & 3;
        R(0xcf016478) = (unsigned short)duty >> 2;
        break;
    case 2:
        R(0xcf016148) = duty & 3;
        R(0xcf016144) = (unsigned short)duty >> 2;
        break;
    case 3:
        R(0xcf016160) = duty & 3;
        R(0xcf01615c) = (unsigned short)duty >> 2;
        break;
    case 4:
        R(0xcf016178) = duty & 3;
        R(0xcf016174) = (unsigned short)duty >> 2;
        break;
    case 5:
        R(0xcf016190) = duty & 3;
        R(0xcf01618c) = (unsigned short)duty >> 2;
        break;
    case 6:
        R(0xcf0161a8) = duty & 3;
        R(0xcf0161a4) = (unsigned short)duty >> 2;
        break;
    case 25:
        R(0xcf0164a0) = duty & 3;
        R(0xcf0164a4) = (unsigned short)duty >> 2;
        break;
    case 23:
        R(0xcf016448) = duty & 3;
        R(0xcf01644c) = (unsigned short)duty >> 2;
        break;
    case 16:
        R(0xcf016410) = duty & 3;
        R(0xcf016414) = (unsigned short)duty >> 2;
        break;
    }
}
