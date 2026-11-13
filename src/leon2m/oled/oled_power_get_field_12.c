/* oled_power_get_field_12  (FUN_a01279dc)
 *
 * Return field +0x12 of the OLED power state record.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802D896 + 0x12
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01279dc @ 0xa01279dc, flags -mcpu=v8 -O2.
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
extern unsigned char oled_power_state_byte_0x12;

/*
 * Return field +0x12 of the OLED power state record. While it is 1 sys_run_app_timer_task counts the minutes of
 * the fake sleep timer.
 */
unsigned char oled_power_get_field_12(void)
{
  return oled_power_state_byte_0x12;
}