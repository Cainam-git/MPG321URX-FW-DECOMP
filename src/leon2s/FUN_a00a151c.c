/* leon2s FUN_a00a151c @ 0xa00a151c (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. For the 52-byte record of unit param_1 at
 * 0xa807db00, takes the pointer in its first word + 4, calls FUN_a00a73ac(9, p),
 * FUN_a00b160c(1), FUN_a00a73d4(9, p), FUN_a00b1794(1), then sets the flag byte at 0xa807918e
 * to 1. Ghidra read the records with a 4-byte element size. Byte-identical twin: FUN_a00a14c4.
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
extern unsigned char DAT_a807918e;
extern int FUN_a00a73ac();
extern int FUN_a00a73d4();
extern int FUN_a00b160c();
extern int FUN_a00b1794();

extern unsigned char ARR_a807db00[][0x34];
void FUN_a00a151c(uint param_1)

{
  int iVar1;
  
  param_1 &= 0xff;
  FUN_a00a73ac(9,*(int *)ARR_a807db00[param_1] + 4);
  FUN_a00b160c(1);
  FUN_a00a73d4(9,*(int *)ARR_a807db00[param_1] + 4);
  FUN_a00b1794(1);
  DAT_a807918e = 1;
}