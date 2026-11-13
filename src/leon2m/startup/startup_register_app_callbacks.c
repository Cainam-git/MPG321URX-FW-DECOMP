/* startup_register_app_callbacks  (FUN_a008796c)
 *
 * Register the ten application callbacks with the system layer.
 * Note: Includes the FRC lock/bypass and the after-settings callbacks; first step of startup_main.
 * Name basis: proven - header: main() step 1, sys_register_callback = register callback
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g (gcc 3.4.4). Source form: ten plain calls in the order shown; the last is a tail call.
 * The handlers are routines of the RAM copy the program runs from.
 */
extern void sys_register_callback(int slot, void (*handler)(void));
extern void irq_empty_handler_copy7(void);
extern void APP_ConfigDispSize(void);
extern void pq_update_input_window(void);
extern void pq_apply_frc_lock_mode(void);
extern void pq_apply_frc_main_bypass(void);
extern void sys_set_state_bit10_and_apply(void);
extern void APPOnSystemAfterNvramInit(void);
extern void input_enable_four_port_items(void);
extern void pq_adjust_value_mode7(void);
extern void APPBeforeDisplay_TriggerBySystem(void);

/* Put the ten application callbacks into their slots of the callback table (sys_callback_table, 15 slots).
 * Slot: 2 empty routine, 3 APP_ConfigDispSize, 6 pq_update_input_window, 10 pq_apply_frc_lock_mode,
 * 11 pq_apply_frc_main_bypass, 7 sys_set_state_bit10_and_apply, 8 APPOnSystemAfterNvramInit,
 * 12 input_enable_four_port_items, 14 pq_adjust_value_mode7, 15 APPBeforeDisplay_TriggerBySystem.
 * The slots are filled in this order; the code that runs a slot is elsewhere. */
void startup_register_app_callbacks(void)
{
    sys_register_callback(2, irq_empty_handler_copy7);
    sys_register_callback(3, APP_ConfigDispSize);
    sys_register_callback(6, pq_update_input_window);
    sys_register_callback(10, pq_apply_frc_lock_mode);
    sys_register_callback(11, pq_apply_frc_main_bypass);
    sys_register_callback(7, sys_set_state_bit10_and_apply);
    sys_register_callback(8, APPOnSystemAfterNvramInit);
    sys_register_callback(12, input_enable_four_port_items);
    sys_register_callback(14, pq_adjust_value_mode7);
    sys_register_callback(15, APPBeforeDisplay_TriggerBySystem);
}
