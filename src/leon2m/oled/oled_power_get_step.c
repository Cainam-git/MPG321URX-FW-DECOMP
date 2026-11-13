/* oled_power_get_step  (FUN_a0127944)
 *
 * Return the step inside the current state of the OLED power state machine.
 * Returns: step
 * Name basis: derived - byte at 0xA802D897
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127944 @ 0xa0127944, flags -mcpu=v8 -O2.
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
extern unsigned char oled_power_state_step;

/*
 * Return the step byte of the OLED power state record (the step inside the state of oled_power_task).
 */
unsigned char oled_power_get_step(void)
{
  return oled_power_state_step;
}