/* leon2s FUN_a00d7210 @ 0xa00d7210 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Table pick into a 2-byte setting: n =
 * (param_2[0] >> 4) - 1, index = n/2 rounded up; copies the low 7 bits of param_2[index + 3]
 * into param_1[0] (keeping its bit 7) and the high nibble of param_2[index + 4] into
 * param_1[1] (keeping its low nibble). FUN_a00d7210 and FUN_a00d7274 are twins (different
 * table offsets).
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


void FUN_a00d7210(byte *param_1,byte *param_2)

{
  uint uVar1;
  unsigned char uVar2;
  
  uVar1 = (*param_2 >> 4) - 1;
  uVar2 = (int)uVar1 / 2;
  if ((uVar1 & 1) != 0) {
    uVar2 = uVar2 + 1;
  }
  *param_1 = *param_1 & 0x80 | param_2[(uVar2 & 0xff) + 3] & 0x7f;
  { uint hi = param_2[(uVar2 & 0xff) + 4] & 0xf0; param_1[1] = param_1[1] & 0xf | hi; }
  return;
}