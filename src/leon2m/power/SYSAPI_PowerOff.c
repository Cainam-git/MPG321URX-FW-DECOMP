/* SYSAPI_PowerOff  (FUN_a002f8d8)
 *
 * Shut the system down: stop the units, interrupts and outputs in order.
 * Note: Runs with only interrupt level 4 enabled during the sequence.
 * Name basis: proven - prints 'SYSAPI_PowerOff' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f8d8 @ 0xa002f8d8, flags -mcpu=v8 -O2 -g (the section default).
 * Source forms the exact build depends on: the six parameters are kept and passed on unchanged to the last call;
 * the callees are declared without a parameter list (int f();), so the one argument given to
 * ipc_8051_send_wake_key_table and the six given to ipc_8051_notify_power_off are passed as written.
 */
extern unsigned char sys_config_byte_0x33;
extern void irq_set_level4_only(unsigned char on);
extern int power_core_sleep_sequence();
extern int dbg_printf();
extern int sys_shut_down_blocks();
extern int gpio_set_aux_bit2_low_copy();
extern int audio_mute_outputs();
extern int sys_poll_events_stub_copy13();
extern int ipc_8051_notify_power_off();
extern int ipc_8051_send_power_cut_table();
extern int ipc_8051_send_wake_key_table();
extern int ipc_power_down();
extern int ipc_wait_input_cpu_power_down();
extern int ldc_power_down_handshake();
extern int nvram_flush_pending_now();
extern int SYSAPI_PanelOnOffControl();

/*
 * Shut the system down for good: the last step of "Power Button = OFF" in APPSetPowerOff. The routine stops the
 * units one after the other, hands the 8051 its tables for the off state, and ends by telling the 8051 to
 * cut the power.
 *
 * The six parameters are handed unchanged to ipc_8051_notify_power_off. APPSetPowerOff calls this routine with
 * none, and ipc_8051_notify_power_off takes none, so the values are not used.
 *
 * Order:
 *   1. Print "SYSAPI_PowerOff". From here on only interrupt level 4 is enabled (irq_set_level4_only(1)),
 *      until step 4.
 *   2. Mute the sound, switch the panel off and wait until it is off (SYSAPI_PanelOnOffControl(0, 1)), call
 *      gpio_set_aux_bit2_low_copy (it passes port 0xFF to gpio_write_pin, which writes nothing) and the empty
 *      event source.
 *   3. Power the receivers of the input processor down (ipc_power_down), run the power-down handshake with the
 *      dimming processor, and write the flash-backed settings that are still pending (nvram_flush_pending_now).
 *      Then give the 8051 its table of standby keys and wake-up pins (chosen with configuration byte 0x33) and
 *      its power-cut table, wait until the input processor reports that it has powered down, and run the
 *      shut-down sequence of the picture blocks.
 *   4. Enable all interrupt levels again (irq_set_level4_only(0)), write the two core registers that precede
 *      power off, and send command 0x17 (power off) to the 8051.
 */
void SYSAPI_PowerOff(unsigned int unused_1, unsigned int unused_2, unsigned int unused_3, unsigned int unused_4,
                 unsigned int unused_5, unsigned int unused_6)

{
  dbg_printf("SYSAPI_PowerOff\r\n");
  irq_set_level4_only(1);
  audio_mute_outputs();
  SYSAPI_PanelOnOffControl(0,1);
  gpio_set_aux_bit2_low_copy();
  sys_poll_events_stub_copy13();
  ipc_power_down();
  ldc_power_down_handshake();
  nvram_flush_pending_now();
  ipc_8051_send_wake_key_table(sys_config_byte_0x33);
  ipc_8051_send_power_cut_table();
  ipc_wait_input_cpu_power_down();
  sys_shut_down_blocks();
  irq_set_level4_only(0);
  power_core_sleep_sequence();
  ipc_8051_notify_power_off(unused_1,unused_2,unused_3,unused_4,unused_5,unused_6);
  return;
}
