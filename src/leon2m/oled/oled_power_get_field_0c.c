/* oled_power_get_field_0c  (FUN_a0127968)
 *
 * Return field +0x0C of the OLED power state record.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802D896 + 0x0C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127968 @ 0xa0127968, flags -mcpu=v8 -O2.
 * Source form: a direct read of the extern byte.
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
extern unsigned char oled_power_state_power_down_done;

/*
 * Return field +0x0C of the OLED power state record. sys_run_app_timer_task prints "Vx1 is abnormal" only while
 * it is 0, among other conditions.
 */
unsigned char oled_power_get_field_0c(void)
{
  return oled_power_state_power_down_done;
}