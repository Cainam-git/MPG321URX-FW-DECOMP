/* sys_core_setup_unit_0320  (FUN_a00b18ac)
 *
 * Start the unit at core register 0x9F120320 with its buffer address.
 * Name basis: descriptive - value 5 and the address 0xA807E000
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b18ac @ 0xa00b18ac (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept.
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
#define CORE_UNIT_0320_CONTROL (*(volatile unsigned int *)0x9f120320)
#define CORE_UNIT_0320_ADDRESS (*(volatile unsigned int *)0x9f120324)

/* Write 5 to the core register at 0x9f120320 and the address 0xa807e000 to the register at 0x9f120324.
 * Called by startup_init_system. */
void sys_core_setup_unit_0320(void)

{
  CORE_UNIT_0320_CONTROL = 5;
  CORE_UNIT_0320_ADDRESS = 0xa807e000;
  return;
}
