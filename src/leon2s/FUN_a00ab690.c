/* leon2s FUN_a00ab690 @ 0xa00ab690 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Reads register 0x21c of port param_1
 * (FUN_a00a6bb8) and maps its low byte to a small index: 6 -> 0, 10 -> 1, 0x14 -> 2, 0x1e ->
 * 3, anything else -> 4. The values 6/10/20/30 look like a rate or clock code (for example,
 * link speeds in units of 0.27 or 1 Gbps); unproven.
 * Still needs a real name and proper types.
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
extern int FUN_a00a6bb8();

int FUN_a00ab690(unsigned char param_1)

{
  int iVar1;
  
  param_1 = param_1 & 0xff;
  param_1 = FUN_a00a6bb8(param_1,0x21c) & 0xff;
  iVar1 = 0;
  if (((param_1 != 6) && (iVar1 = 1, param_1 != 10)) && (iVar1 = 2, param_1 != 0x14)) {
    iVar1 = (param_1 == 0x1e) ? 3 : 4;
  }
  return iVar1;
}