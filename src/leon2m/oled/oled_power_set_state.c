/* oled_power_set_state  (FUN_a0127938)
 *
 * Store the state of the OLED power state machine.
 * Name basis: derived - byte at 0xA802D896
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127938 @ 0xa0127938, flags -mcpu=v8 -O2 -g.
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
extern unsigned char oled_power_state;

/*
 * Store the state byte of the OLED power state record (the state of oled_power_task).
 *
 *   value  new state byte
 */
void oled_power_set_state(unsigned char value)
{
  oled_power_state = value;
}