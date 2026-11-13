/* gpio_set_aux_bit0_low  (FUN_a0124a08)
 *
 * Ask for pin 0 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; called by
 *   sys_user_reset_display_path, sys_user_apply_output_mode, sys_user_apply_startup_settings,
 *   panel_user_set_output_on and 6 more.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x1, 0xFE); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124a08, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's type definitions (undefined, byte, uint, ...) and the unprototyped
 * int-returning declaration of gpio_write_pin are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();

/* Port number 0xFF: gpio_write_pin has no such port and writes nothing. */
#define GPIO_PORT_NONE 0xff
#define PIN_0_MASK     1
#define GPIO_LEVEL_LOW 0xfe     /* bit 0 clear: output low */

extern int gpio_write_pin();

/* Call gpio_write_pin(0xFF, 1, 0xFE). Because port 0xFF is not a port, nothing is written. */
void gpio_set_aux_bit0_low(void)

{
  gpio_write_pin(GPIO_PORT_NONE,PIN_0_MASK,GPIO_LEVEL_LOW);
  return;
}
