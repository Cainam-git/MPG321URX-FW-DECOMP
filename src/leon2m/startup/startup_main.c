/* startup_main  (FUN_a00295a4)
 *
 * Run the three start-up steps, then the main loop tasks forever.
 * Note: Called by the reset code once stack and trap base are set; never returns.
 * Name basis: proven - docs/MAP.md start-up sequence: main = FUN_a00295a4
 *
 * Matching notes
 * --------------
 * leon2m startup_main @ 0xa00295a4 (-mcpu=v8 -O2 -g).
 * Source form: the three start-up calls are separate statements, and the main loop is a do-while(true) with four separate calls in that order.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int App_CoolInitialize();
extern int sys_run_app_main_task();
extern int startup_register_app_callbacks();
extern int dbg_command_shell();
extern int ipc_ack_port_change_bits();
extern int startup_bring_up_system();
extern int sys_main_loop_periodic_task();

/*
 * Run the three start-up steps, then run the four main-loop tasks forever.
 * The loop calls ipc_ack_port_change_bits, sys_main_loop_periodic_task,
 * sys_run_app_main_task and dbg_command_shell in that order.
 */
void startup_main(void)

{
  startup_register_app_callbacks();
  startup_bring_up_system();
  App_CoolInitialize();
  do {
    ipc_ack_port_change_bits();
    sys_main_loop_periodic_task();
    sys_run_app_main_task();
    dbg_command_shell();
  } while( true );
}
