/* leon2m FUN_a00df450 @ 0xa00df450  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern int func_0x4008c250();
extern void func_0x4008c25c();

int FUN_a00df450(char *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    do {
      uVar2 = func_0x4008c250(0xc00b0000);
    } while ((uVar2 & 0x20) == 0);
    func_0x4008c25c(0xc00b0000,(int)*param_1);
    if (*param_1 == '\n') {
      do {
        uVar2 = func_0x4008c250(0xc00b0000);
      } while ((uVar2 & 0x20) == 0);
      func_0x4008c25c(0xc00b0000,0xd);
    }
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return CONCAT44(param_2,param_1);
}