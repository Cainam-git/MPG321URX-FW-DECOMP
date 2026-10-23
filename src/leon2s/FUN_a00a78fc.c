/* leon2s FUN_a00a78fc @ 0xa00a78fc (-mcpu=v8 -Os -g)
 * For p1 (low byte) < 5 writes p3 & 0xff to the register 0xCF000000 | ((t + p2) * 4), where t is halfword p1 of
 * the table at 0xA00B4D7A.
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
extern unsigned char DAT_a00b4d7a;

void FUN_a00a78fc(uint param_1, unsigned short param_2,uint param_3)

{
  if ((param_1 & 0xff) < 5) {
    *(uint *)(((uint)*(ushort *)(&DAT_a00b4d7a + (param_1 & 0xff) * 2) + (param_2 & 0xffff)) * 4 |
             0xcf000000) = param_3 & 0xff;
  }
  return;
}