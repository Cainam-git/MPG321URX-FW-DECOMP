/* gpio_user_set_port2_bit2  (FUN_a00d9978)
 *
 * Drive pin 2 of GPIO port 2 as settings bit 6 says.
 * Name basis: descriptive - bit 6 of the settings word at 0xA802D338
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d9978 @ 0xa00d9978, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's typedefs and macros are kept; each arm of the test returns on its own, with a
 * blank line between the header and the brace.
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

#define GAMING_FLAG_PORT2_PIN2  0x40    /* bit 6 of settings word +0xA8: the RGB LED switch of the Settings page */

extern unsigned int user_settings_gaming_flags;     /* user settings word +0xA8 */
extern void gpio_set_port2_bit2_high(void);
extern void gpio_set_port2_bit2_low(void);

/*
 * Set pin 2 of GPIO port 2 high when bit 6 of settings word +0xA8 is set, low when it is clear.
 * Called from APPActionDispatcher, oled_power_task and other settings code.
 */
void gpio_user_set_port2_bit2(void)

{
  if ((user_settings_gaming_flags & GAMING_FLAG_PORT2_PIN2) != 0) {
    gpio_set_port2_bit2_high();
    return;
  }
  gpio_set_port2_bit2_low();
  return;
}
