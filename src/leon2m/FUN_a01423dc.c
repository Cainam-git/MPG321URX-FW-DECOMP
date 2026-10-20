/* leon2m FUN_a01423dc @ 0xa01423dc  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a011eadc();
extern int FUN_a011fd84();
extern int FUN_a01205c0();

void FUN_a01423dc(void)

{
  
  FUN_a011eadc();
  FUN_a01205c0(2);
  FUN_a011fd84(0,0,0,0x500);
  FUN_a011fd84(1,0,0,0x500);
  return;
}