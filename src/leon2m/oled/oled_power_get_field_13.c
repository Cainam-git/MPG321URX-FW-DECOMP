/* oled_power_get_field_13  (FUN_a01279f4)
 *
 * Return field +0x13 of the OLED power state record.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802D896 + 0x13
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01279f4 @ 0xa01279f4, flags -mcpu=v8 -O2.
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
extern unsigned char oled_power_state_sensing_active;

/*
 * Return field +0x13 of the OLED power state record. panel_cycle_burnin_colour skips the swap of GPIO port 4
 * pins 4 and 7 while it is 1.
 */
unsigned char oled_power_get_field_13(void)
{
  return oled_power_state_sensing_active;
}