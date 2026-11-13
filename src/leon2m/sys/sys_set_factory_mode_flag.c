/* sys_set_factory_mode_flag  (FUN_a00cea18)
 *
 * Set the factory mode flag and switch all input signals on.
 * Note: Bit 14 of settings word +0; input_api_set_port_signal(0xFE, 1).
 * Name basis: derived - set together with marker 0x55AA by ddc_tool_set_factory_mode; sys_read_startup_key
 *   sets the same bit
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the first word of the user settings is declared as a plain unsigned int and updated with |=; the
 * port-signal call takes int arguments (no prototype).
 */
#define SETTINGS_FACTORY_MODE 0x4000    /* bit 14 of the first word of the user settings: factory mode */
#define ALL_PORTS             0xfe      /* input_api_set_port_signal: all input slots */
#define PORT_SIGNAL_ON        1

extern unsigned int user_settings;      /* word_0x0, the first word of the user settings record */
extern int input_api_set_port_signal();

/*
 * Set the factory mode flag and switch the signal of all input slots on. Called by ddc_tool_set_factory_mode
 * (factory tool command "factory mode on", which also writes the marker at settings +0x1F6) and by
 * ddc_apply_maker_vcp_set (factory switch A0 00, value 1).
 */
void sys_set_factory_mode_flag(void)

{
  user_settings = user_settings | SETTINGS_FACTORY_MODE;
  input_api_set_port_signal(ALL_PORTS, PORT_SIGNAL_ON);
  return;
}
