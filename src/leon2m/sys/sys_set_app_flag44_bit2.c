/* sys_set_app_flag44_bit2  (FUN_a0082c0c)
 *
 * Set bit 2 of the application flag byte 0xA802AF44.
 * Note: Called by the command handler uart_cmd_check_data_block after a good checksum.
 * Name basis: descriptive - code only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082c0c @ 0xa0082c0c, flags -mcpu=v8 -O2 -g (section default).
 * Code: app_flags_second = app_flags_second | 4.
 */
extern unsigned char app_flags_second;

#define APP_FLAG44_STORE_MODES_0 0x04   /* app_flags_second bit 2 */

/*
 * Set bit 2 of app_flags_second. It is called by the command handler uart_cmd_check_data_block after a good checksum.
 * The one-second step of sys_run_app_timer_task tests the bit, calls nvram_api_store_by_selector(0) and then
 * clears the whole byte.
 */
void sys_set_app_flag44_bit2(void)
{
  app_flags_second = app_flags_second | APP_FLAG44_STORE_MODES_0;
}
