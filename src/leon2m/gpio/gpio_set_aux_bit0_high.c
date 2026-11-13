/* gpio_set_aux_bit0_high  (FUN_a01249ec)
 *
 * Ask for pin 0 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; called by
 *   uart_cmd_set_auto_level, GlobalModeHandler, panel_user_set_output_on, panel_power_sequencer_task and 2
 *   more.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x1, 0x1); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01249ec, flags -mcpu=v8 -O2 -g.
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
#define GPIO_PORT_NONE  0xff
#define PIN_0_MASK      1
#define GPIO_LEVEL_HIGH 1       /* bit 0 of the level is the output level */

extern int gpio_write_pin();

/* Call gpio_write_pin(0xFF, 1, 1). Because port 0xFF is not a port, nothing is written. */
void gpio_set_aux_bit0_high(void)

{
  gpio_write_pin(GPIO_PORT_NONE,PIN_0_MASK,GPIO_LEVEL_HIGH);
  return;
}
