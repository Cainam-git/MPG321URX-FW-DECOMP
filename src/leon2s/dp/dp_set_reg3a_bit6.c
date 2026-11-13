/* dp_set_reg3a_bit6  (FUN_a00b1450)
 *
 * Set bit 6 of register 0x3A of a port.
 * Name basis: descriptive - register bit write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1450 @ 0xa00b1450 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept (dp_reg_update_bits is declared without a prototype).
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int dp_reg_update_bits();

/* Set bit 6 (0x40) of register 0x3A of DisplayPort receiver `port`. */
void dp_set_reg3a_bit6(undefined1 port)

{
  dp_reg_update_bits(port,0x3a,0x40,1);
  return;
}
