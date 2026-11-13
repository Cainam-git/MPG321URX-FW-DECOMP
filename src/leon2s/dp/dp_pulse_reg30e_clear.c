/* dp_pulse_reg30e_clear  (FUN_a00d6560)
 *
 * Clear register 0x30E of a port inside a pulse of bit 7 of register 0x30.
 * Name basis: descriptive - three register writes
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d6560 @ 0xa00d6560 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept (callees declared without prototype, reached through
 * their func_0x... names).
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
extern int dp_reg_write8();
extern void dp_reg_update_bits();

/* Set bit 7 of register 0x30 of DisplayPort receiver `port`, write 0 to register 0x30E, then clear bit 7
 * of register 0x30 again. Called through dp_api_pulse_reg30e_clear. */
void dp_pulse_reg30e_clear(undefined1 port)

{
  
  dp_reg_update_bits(port,0x30,0x80,1);
  dp_reg_write8(port,0x30e,0);
  dp_reg_update_bits(port,0x30,0x80,0);
  return;
}
