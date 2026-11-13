/* oled_power_set_field_0c  (FUN_a012795c)
 *
 * Store field +0x0C of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x0C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012795c @ 0xa012795c, flags -mcpu=v8 -O2 -g.
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
extern unsigned char oled_power_state_power_down_done;

/*
 * Store field +0x0C of the OLED power state record. power_escape_fake_sleep clears it together with
 * fields +0x0D and +0x12.
 *
 *   value  new field value
 */
void oled_power_set_field_0c(unsigned char value)
{
  oled_power_state_power_down_done = value;
}