/* oled_power_set_field_12  (FUN_a01279d0)
 *
 * Store field +0x12 of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x12
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01279d0 @ 0xa01279d0, flags -mcpu=v8 -O2 -g.
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
extern unsigned char oled_power_state_byte_0x12;

/*
 * Store field +0x12 of the OLED power state record. Cleared when fake sleep is left or entered (field +0x11 = 1).
 *
 *   value  new field value
 */
void oled_power_set_field_12(unsigned char value)
{
  oled_power_state_byte_0x12 = value;
}