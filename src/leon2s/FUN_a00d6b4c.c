/* leon2s FUN_a00d6b4c @ 0xa00d6b4c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. One-byte member of the FUN_a00d7210 /
 * FUN_a00d7274 family: n = (param_2[0] >> 4) - 1, index = n/2 rounded up; copies the low 7
 * bits of param_2[index + 3] into param_1[0], keeping its bit 7.
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


void FUN_a00d6b4c(byte *param_1,byte *param_2)

{
  uint uVar1;
  unsigned char uVar2;
  
  uVar1 = (*param_2 >> 4) - 1;
  uVar2 = (int)uVar1 / 2;
  if ((uVar1 & 1) != 0) {
    uVar2 = uVar2 + 1;
  }
  { uint t_ = param_2[(uVar2 & 0xff) + 3] & 0x7f; *param_1 = *param_1 & 0x80 | t_; }
  return;
}