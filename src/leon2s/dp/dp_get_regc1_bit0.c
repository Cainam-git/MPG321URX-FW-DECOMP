/* dp_get_regc1_bit0  (FUN_a00d6694)
 *
 * Return bit 0 of register 0xC1 of a port.
 * Returns: 0 or 1
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d6694 @ 0xa00d6694 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept (the second parameter is declared but not used).
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
extern int dp_reg_read8();

/* Bit 0 of register 0xC1 of DisplayPort receiver `port` (0 or 1). `unused` is not used. */
unsigned char dp_get_regc1_bit0(uint port,undefined4 unused)

{
  port = port & 0xff;
  return dp_reg_read8(port,0xc1) & 1;
}
