/* leon2s FUN_a0084c94 @ 0xa0084c94  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Port p comes back from FUN_a0083ed0(param_1 &
 * 0xff) (low byte). Then writes the low four bits of param_2 one by one through
 * FUN_a00a7718(p, reg, 1, bit) to registers 0x140, 0x1c0, 0x240 and 0x2c0 (bit 0 to the first,
 * bit 3 to the last): four separate on/off switches set from one mask. Ghidra had dropped the
 * first call's result.
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
extern int FUN_a0083ed0();
extern void FUN_a00a7718();

void FUN_a0084c94(int param_1, unsigned char param_2)

{
  uint uVar1;
  
  param_1 = FUN_a0083ed0(param_1 & 0xff) & 0xff;
  uVar1 = param_2 & 0xff;
  FUN_a00a7718(param_1,0x140,1,param_2 & 1);
  FUN_a00a7718(param_1,0x1c0,1,uVar1 >> 1 & 1);
  FUN_a00a7718(param_1,0x240,1,uVar1 >> 2 & 1);
  FUN_a00a7718(param_1,0x2c0,1,uVar1 >> 3 & 1);
  return;
}