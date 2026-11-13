/* APPOnSystemAfterNvramInit  (FUN_a0083b60)
 *
 * Print the power-on type; set two GPIO port 4 pins unless type 4, or type 3 woken by the power key.
 * Note: Callback 8 of the callback table; the two pin routines (pin 4 low, pin 7 high) act only when their own
 *   conditions allow.
 * Name basis: proven - prints 'APPOnSystemAfterNvramInit %d' (original name from the text)
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: "start" is an unsigned char set to 1 and then cleared in the power-on type 3
 * arm (a one-line "!= 1" store-flag gives other code).
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned char SYSAPI_GetPowerOnType(void);
extern unsigned char power_api_is_woken_by_power_key(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void gpio_set_port4_bit7_high_if_allowed(void);

/* Callback 8 of the callback table (registered by startup_register_app_callbacks).
 * Looks up the power-on type and prints it. Unless the type is 4, and unless the type is 3 and the power key
 * woke the monitor, it then calls the two pin routines (pin 4 of GPIO port 4 low, pin 7 of GPIO port 4 high);
 * each of them acts only when its own condition allows it. Nothing is done for the other cases. */
void APPOnSystemAfterNvramInit(void)
{
  unsigned char power_on_type;
  unsigned char start;

  power_on_type = SYSAPI_GetPowerOnType();
  dbg_printf("APPOnSystemAfterNvramInit %d \r\n", power_on_type);
  if (power_on_type == 3) {
    start = 1;
    if (power_api_is_woken_by_power_key() == 1)
      start = 0;
  } else
    start = power_on_type != 4;
  if (start) {
    gpio_set_port4_bit4_low_if_allowed();
    gpio_set_port4_bit7_high_if_allowed();
  }
}
