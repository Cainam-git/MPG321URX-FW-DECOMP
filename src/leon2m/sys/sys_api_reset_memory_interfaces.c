/* sys_api_reset_memory_interfaces  (FUN_a011552c)
 *
 * Run the register sequence of the three memory interfaces.
 * Name basis: descriptive - forwards to sys_reset_memory_interfaces; called from sys_shut_down_blocks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011552c @ 0xa011552c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int sys_reset_memory_interfaces();

/* Call sys_reset_memory_interfaces. Called by sys_shut_down_blocks. */
void sys_api_reset_memory_interfaces(void)

{
  sys_reset_memory_interfaces();
  return;
}