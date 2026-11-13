/* dp_irq_disable_port  (FUN_a00b0540)
 *
 * Switch the interrupt sources of DisplayPort input 0 or 1 off.
 * Name basis: descriptive - one disable routine per port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0540 @ 0xa00b0540 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept for the declarations.
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
extern int irq_disable_dp_port0();
extern int irq_disable_dp_port1();

/* Switch off the interrupt sources of DisplayPort input `port` (0 or 1): port 0 goes to
 * irq_disable_dp_port0, any other value to irq_disable_dp_port1. Called by dp_stop_port and
 * dp_start_port. */
void dp_irq_disable_port(unsigned char port)

{
  if (port == '\0') {
    irq_disable_dp_port0();
    return;
  }
  irq_disable_dp_port1();
  return;
}
