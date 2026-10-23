/* leon2m FUN_a015e7fc @ 0xa015e7fc (-mcpu=v8 -O2 -g)
 * Stores 0x1D in the word whose address FUN_a01576dc() returns, and returns -1.
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
extern undefined4 FUN_a01576dc(void);

int FUN_a015e7fc(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_a01576dc();
  *puVar1 = 0x1d;
  return CONCAT44(param_2,0xffffffff);
}