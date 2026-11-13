/* oled_power_set_field_11  (FUN_a01279b8)
 *
 * Store field +0x11 of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x11
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01279b8 @ 0xa01279b8, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern byte.
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
extern unsigned char oled_power_state_byte_0x11;

/*
 * Store field +0x11 of the OLED power state record. sys_run_app_timer_task sets it to 1 when the fake sleep
 * count reaches 10 minutes.
 *
 *   value  new field value
 */
void oled_power_set_field_11(unsigned char value)
{
  oled_power_state_byte_0x11 = value;
}