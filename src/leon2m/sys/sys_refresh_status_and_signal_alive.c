/* sys_refresh_status_and_signal_alive  (FUN_a0154580)
 *
 * Refresh the input status codes when requested, then signal the 8051 that the main processor is alive.
 * Note: The status refresh runs only when byte 0xA802A4C0 is 1.
 * Name basis: derived - always ends in ipc_signal_alive, the alive signal checked by the 8051 (docs/MAP.md);
 *   called from the main loop
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0154580 @ 0xa0154580..0xa015463c (47 words), flags -mcpu=v8 -g (this unit was built without
 * optimisation: ldub + and 0xff and or-formed addresses). Called twice from the main-loop task sys_main_loop_periodic_task
 * (0xA015326C, 0xA015359C).
 * This is the per-main-loop-pass call of ipc_signal_alive; if main() never reaches its loop, only the start-up
 * callers of ipc_signal_alive (i2c_gpio_write_block, SYSAPI_PanelOnOffControl) make the F204 -> F208 copy, and after a halt nothing does.
 */
extern unsigned char sys_status_refresh_request, sys_chip_revision, sys_chip_model_code;
extern unsigned int sys_link_status_code;
extern unsigned char sys_get_chip_revision(void);
extern unsigned char sys_get_chip_model_code(void);
extern void sys_publish_chip_status_code(void);
extern void irq_empty_handler_copy92(void);
extern void ipc_signal_alive(void);

#define CHIP_REVISION_CLASS_MASK 0xf0           /* the high four bits of the chip revision code */
#define CHIP_REVISION_CLASS_8    0x80

/*
 * Main-loop step: refresh the chip identification when requested, then tell the 8051 the main processor is
 * alive. Called twice from the main-loop task sys_main_loop_periodic_task.
 *
 * When sys_status_refresh_request is 1, the chip revision and model code are read again, the link status code is
 * published (sys_publish_chip_status_code) and the request is cleared. When the link status code is not 0 and the
 * revision belongs to class 0x8x, irq_empty_handler_copy92 is called (it does nothing). In every case
 * ipc_signal_alive follows. Returns 0.
 */
int sys_refresh_status_and_signal_alive(void)
{
    if (sys_status_refresh_request == 1) {
        sys_chip_revision = sys_get_chip_revision();
        sys_chip_model_code = sys_get_chip_model_code();
        sys_publish_chip_status_code();
        sys_status_refresh_request = 0;
    }
    if (sys_link_status_code != 0 && (sys_chip_revision & CHIP_REVISION_CLASS_MASK) == CHIP_REVISION_CLASS_8)
        irq_empty_handler_copy92();
    ipc_signal_alive();
    return 0;
}
