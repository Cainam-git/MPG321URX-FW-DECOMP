/* dp_api_pulse_reg30e_clear  (FUN_a00b0724)
 *
 * Clear register 0x30E of a port inside its control pulse.
 * Name basis: descriptive - forwards to dp_pulse_reg30e_clear
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0724 @ 0xa00b0724 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept (the callee is declared without a prototype and
 * is reached through its func_0x9f1c6560 name).
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int dp_pulse_reg30e_clear();

/* Plain forward of `port` to dp_pulse_reg30e_clear. */
void dp_api_pulse_reg30e_clear(undefined1 port)

{
  dp_pulse_reg30e_clear(port);
  return;
}
