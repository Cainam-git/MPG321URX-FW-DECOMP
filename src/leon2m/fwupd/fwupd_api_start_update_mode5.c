/* fwupd_api_start_update_mode5  (FUN_a0148254)
 *
 * Start the update in mode 5.
 * Name basis: descriptive - mode 5 of the update entry routine; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148254 @ 0xa0148254 (-mcpu=v8 -O2 -g).
 * Source form: the decompiler's form is kept (unused first parameter, byte pointer second parameter, a byte pointer
 * as the mode).
 */
typedef unsigned char byte;
typedef unsigned int undefined4;
extern int fwupd_enter_update();

/*
 * Start the firmware update in mode 5 (docs/MAP.md: nothing in FW.021 calls this routine).
 *   unused  not used
 *   arg     passed on as the second argument of fwupd_enter_update
 *
 * Calls fwupd_enter_update with mode 5, in which the registers of the picture path are saved and changed and
 * the update agent is sent its command 0x13 (see fwupd_enter_update).
 */
void fwupd_api_start_update_mode5(undefined4 unused,byte *arg)

{
  fwupd_enter_update((byte *)0x5,arg);
  return;
}