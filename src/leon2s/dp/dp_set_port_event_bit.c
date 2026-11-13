/* dp_set_port_event_bit  (FUN_a00b1470)
 *
 * Set the bit of a port in the event register 0xCF03C894.
 * Name basis: descriptive - 1 << port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1470 @ 0xa00b1470 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept; the register is read and written as a whole word.
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
#define reg_ipc_shared_port_events (*(volatile unsigned int *)0xcf03c894)

/* Set bit `port` of the shared event register 0xCF03C894 (one bit per port). */
void dp_set_port_event_bit(byte port)

{
  reg_ipc_shared_port_events = reg_ipc_shared_port_events | 1 << port;
  return;
}
