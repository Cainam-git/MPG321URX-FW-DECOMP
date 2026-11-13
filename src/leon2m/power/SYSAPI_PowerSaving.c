/* SYSAPI_PowerSaving  (FUN_a01451fc)
 *
 * Put the monitor into power saving: panel off, outputs and blocks shut down.
 * Name basis: proven - prints 'SYSAPI_PowerSaving' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01451fc @ 0xa01451fc, flags -mcpu=v8 -O3 -g.
 * Source form: bit 18 is a 1-bit bit-field of the first word of sys_config and byte +0x33 a byte of the same
 * record (the firmware reads it at [record + 0x33]); not volatile (RAM); no aids. ipc_8051_notify_power_saving is
 * the last call and is a tail call. ldc_power_down_handshake takes no arguments.
 */
/* The system configuration record (sys_config), only the parts used here. */
struct sys_config_record {
    unsigned int bits_19_31 : 13;
    unsigned int bit18 : 1;         /* set from the reply of ipc_ping */
    unsigned int bits_0_17 : 18;
    unsigned char pad04[0x33 - 4];
    unsigned char byte_0x33;        /* flag byte, 0 or 1; passed to ipc_8051_send_wake_key_table */
};
extern struct sys_config_record sys_config;
extern void power_core_sleep_sequence(void);
extern int dbg_printf(const char *fmt, ...);
extern void input_set_port_pin_function(unsigned int, unsigned int);
extern void sys_shut_down_blocks(void);
extern void gpio_set_aux_bit2_low_copy(void);
extern void audio_mute_outputs(void);
extern void power_prepare_standby_pins(void);
extern void sys_poll_events_stub_copy13(void);
extern void ipc_8051_notify_power_saving(void);
extern void ipc_8051_send_wake_port_table(void);
extern void ipc_8051_send_usb_c_info(void);
extern void ipc_8051_send_power_cut_table(void);
extern void ipc_8051_send_wake_key_table(unsigned char);
extern int ipc_ping(void);
extern void ipc_power_down_for_saving(void);
extern void ipc_wait_input_cpu_power_down(void);
extern void ldc_power_down_handshake(void);
extern void nvram_flush_pending_now(void);
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);
extern void irq_set_level4_only(unsigned int);

/*
 * Put the monitor into power saving. Called by power_enter_app_state, after the panel has been switched off and
 * unless the factory condition holds there. Returns nothing; the last call (ipc_8051_notify_power_saving) sends
 * the 8051 its power-saving command and does not return until the 8051 has taken it.
 *
 * Order of the steps:
 *  1. Print the routine's name, switch the pin function of input 2 (input_set_port_pin_function(2, 0)).
 *  2. irq_set_level4_only(1); sound muted; panel off (SYSAPI_PanelOnOffControl(0, 1));
 *     gpio_set_aux_bit2_low_copy (GPIO port number 0xFF, so no pin changes).
 *  3. Ask the input processor to answer (ipc_ping) and keep the reply in bit 18 of sys_config word 0; then tell it
 *     to power its receivers down (ipc_power_down_for_saving) and run the power-down handshake with the dimming
 *     processor.
 *  4. Write any pending flash-backed data out at once (nvram_flush_pending_now).
 *  5. Hand the 8051 its tables: wake keys (sys_config byte +0x33 is passed along), power cut, USB-C port info; wait
 *     until the input processor reports it has powered down.
 *  6. Shut down the picture blocks (sys_shut_down_blocks), hand the 8051 the wake-up port table,
 *     irq_set_level4_only(0).
 *  7. Core sleep register sequence, standby pin levels, then the notification to the 8051.
 */
void SYSAPI_PowerSaving(void)
{
    dbg_printf("SYSAPI_PowerSaving\r\n");
    input_set_port_pin_function(2, 0);
    irq_set_level4_only(1);
    audio_mute_outputs();
    SYSAPI_PanelOnOffControl(0, 1);
    gpio_set_aux_bit2_low_copy();
    sys_poll_events_stub_copy13();
    sys_config.bit18 = ipc_ping();
    ipc_power_down_for_saving();
    ldc_power_down_handshake();
    nvram_flush_pending_now();
    ipc_8051_send_wake_key_table(sys_config.byte_0x33);
    ipc_8051_send_power_cut_table();
    ipc_8051_send_usb_c_info();
    ipc_wait_input_cpu_power_down();
    sys_shut_down_blocks();
    ipc_8051_send_wake_port_table();
    irq_set_level4_only(0);
    power_core_sleep_sequence();
    power_prepare_standby_pins();
    ipc_8051_notify_power_saving();
}
