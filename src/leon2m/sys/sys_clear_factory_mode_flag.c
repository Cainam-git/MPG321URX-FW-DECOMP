/* sys_clear_factory_mode_flag  (FUN_a00cea44)
 *
 * Clear the factory mode flag and switch all input signals off.
 * Note: Bit 14 of settings word +0; input_api_set_port_signal(0xFE, 0).
 * Name basis: derived - pair of sys_set_factory_mode_flag; callers ddc_tool_set_factory_mode,
 *   ddc_apply_maker_vcp_set
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the first word of the user settings is declared as a plain unsigned int and updated with a mask
 * constant; the port-signal call takes int arguments (no prototype).
 */
#define SETTINGS_FACTORY_MODE 0x4000    /* bit 14 of the first word of the user settings: factory mode */
#define ALL_PORTS             0xfe      /* input_api_set_port_signal: all input slots */
#define PORT_SIGNAL_OFF       0

extern unsigned int user_settings;      /* word_0x0, the first word of the user settings record */
extern int input_api_set_port_signal();

/*
 * Clear the factory mode flag and switch the signal of all input slots off. Pair of sys_set_factory_mode_flag;
 * called by ddc_tool_set_factory_mode (factory tool command "factory mode off", which also writes the cleared
 * marker at settings +0x1F6) and by ddc_apply_maker_vcp_set (factory switch A0 00, value 0).
 */
void sys_clear_factory_mode_flag(void)

{
  user_settings = user_settings & 0xffffbfff;   /* ~SETTINGS_FACTORY_MODE */
  input_api_set_port_signal(ALL_PORTS, PORT_SIGNAL_OFF);
  return;
}
