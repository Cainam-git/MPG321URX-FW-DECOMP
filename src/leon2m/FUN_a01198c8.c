/* leon2m FUN_a01198c8 @ 0xa01198c8 (-mcpu=v8 -O3 -g)
 * Writes p1 & 3 to bits 2-3 of byte 0xA802C9B0 when p2 == 0, otherwise to bits 4-5 of that byte.
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
extern unsigned char DAT_a802c9b0;

void FUN_a01198c8(uint param_1, unsigned char param_2)

{
  if (param_2 == '\0') {
    DAT_a802c9b0 = DAT_a802c9b0 & 0xf3 | (byte)((param_1 & 3) << 2);
  }
  else {
    DAT_a802c9b0 = DAT_a802c9b0 & 0xcf | (byte)((param_1 & 3) << 4);
  }
  return;
}