/* panel_api_set_pwm_duty_channel_ff  (FUN_a014382c)
 *
 * Call panel_pwm_set_duty with channel 0xFF, which has no case for it and writes nothing.
 * Note: Nothing calls it.
 * Name basis: descriptive - panel_pwm_set_duty(0xFF, value); that routine handles channels 1..6 and 16..26
 *   only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014382c @ 0xa014382c, flags -mcpu=v8 -O2 -g.
 * Source form: a plain call with the channel argument 0xff.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define CONCAT11(a, b) ((unsigned short)(((unsigned)(a) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT13(a, b) (((unsigned)(a) << 24) | ((unsigned)(b) & 0xffffff))
#define CONCAT21(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define CONCAT22(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define SUB41(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define SUB42(x, c) ((unsigned short)((unsigned)(x) >> ((c) * 8)))
#define SUB43(x, c) (((unsigned)(x) >> ((c) * 8)) & 0xffffff)
#define SUB21(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define ZEXT14(x) ((unsigned)(unsigned char)(x))
#define ZEXT24(x) ((unsigned)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
#define SEXT14(x) ((int)(signed char)(x))
#define SEXT24(x) ((int)(short)(x))
#define SEXT12(x) ((short)(signed char)(x))
extern int panel_pwm_set_duty();

#define PWM_CHANNEL_0XFF 0xff   /* panel_pwm_set_duty has no case for this channel number */

/*
 * Call panel_pwm_set_duty with channel 0xFF and the given duty value. That routine writes registers only for the
 * channels 1..6 and 16..26, so this call writes nothing. No routine calls it.
 *
 *   duty  value for panel_pwm_set_duty (10-bit)
 */
void panel_api_set_pwm_duty_channel_ff(unsigned short duty)
{
  panel_pwm_set_duty(PWM_CHANNEL_0XFF, duty);
}