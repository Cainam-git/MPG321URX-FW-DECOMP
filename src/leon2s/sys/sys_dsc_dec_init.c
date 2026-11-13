/* sys_dsc_dec_init  (FUN_a00a47b0)
 *
 * Initialise the DSC decoder: register pointers, state and default set-up.
 *   p1: passed back
 * Returns: p1
 * Name basis: derived - sys_dsc_dec_init_register_pointers, sys_dsc_dec_reset_state,
 *   sys_dsc_dec_load_default_config; caller input_init_receivers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a47b0 @ 0xa00a47b0 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept (two undefined4 parameters, the first is returned).
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char sys_dsc_dec_init_flag;
extern int sys_dsc_dec_init_register_pointers();
extern int sys_dsc_dec_reset_state();
extern int sys_dsc_dec_load_default_config();

/* Initialise the DSC decoder: set the register block pointers, reset the state, load the default set-up and set
 * sys_dsc_dec_init_flag. Called by input_init_receivers.
 * The first parameter is returned unchanged; the second is not used.
 */
int sys_dsc_dec_init(undefined4 passed_through,undefined4 unused)

{
  sys_dsc_dec_init_register_pointers();
  sys_dsc_dec_reset_state();
  sys_dsc_dec_load_default_config();
  sys_dsc_dec_init_flag = 1;
  return passed_through;
}
