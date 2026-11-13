/* fwupd_api_start_update  (FUN_a0148230)
 *
 * Set the progress hook, switch flash write protection off and start the update in mode 0.
 * Name basis: derived - fwupd_set_progress_hook, flash_write_protect_off and mode 0 of fwupd_enter_update;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148230 @ 0xa0148230 (-mcpu=v8 -O2 -g).
 * Source form: the decompiler's form is kept (unused first parameter, byte pointer second parameter, a null byte
 * pointer as the mode).
 */
typedef unsigned char byte;
typedef unsigned int undefined4;
extern unsigned int sys_callback_table_slot1;
extern void fwupd_set_progress_hook(undefined4 hook);
extern int fwupd_enter_update();
extern void flash_write_protect_off(void);

/*
 * Start the firmware update in mode 0 (docs/MAP.md: nothing in FW.021 calls this routine).
 *   unused  not used
 *   arg     passed on as the second argument of fwupd_enter_update
 *
 * Store slot 1 of the system callback table as the hook that fwupd_run_progress_loop calls when the update
 * progress changes, switch the flash write protection off (it is not switched on again here), then call
 * fwupd_enter_update with mode 0, which runs the progress loop once the update agent has a file ready.
 */
void fwupd_api_start_update(undefined4 unused,byte *arg)

{
  fwupd_set_progress_hook(sys_callback_table_slot1);
  flash_write_protect_off();
  fwupd_enter_update((byte *)0x0,arg);
  return;
}