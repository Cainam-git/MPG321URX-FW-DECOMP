/* oled_power_get_elapsed_ticks  (FUN_a012798c)
 *
 * Return the ticks passed since the state machine's time stamp.
 * Returns: ticks
 * Name basis: derived - timer_ticks_since on the halfword at 0xA802D89A; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012798c @ 0xa012798c, flags -mcpu=v8 -O2 -g.
 * Source form: the time stamp is first copied to an unsigned int local; the two parameters are never used and are
 * kept as declared (the firmware passes nothing meaningful in them).
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
extern unsigned short oled_power_state_ticks;
extern int timer_ticks_since();

/*
 * Return the timer ticks that have passed since the time stamp (halfword +4) of the OLED power state record.
 * No routine calls it.
 */
unsigned short oled_power_get_elapsed_ticks(undefined4 param_1, undefined4 param_2)
{
  unsigned int time_stamp;

  time_stamp = (unsigned int)oled_power_state_ticks;
  return timer_ticks_since(time_stamp);
}