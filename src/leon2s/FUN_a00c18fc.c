/* leon2s FUN_a00c18fc @ 0xa00c18fc (-mcpu=v8 -Os -g)
 * Calls func_0xa0fb65c4(2, 0x41, 0x10), func_0xa0fb65c4(2, 0x3f, 0x74), func_0xa0fb69fc(2, 0x3f, 0x74),
 * func_0xa0fb6aa0(2, 0x43, 1, 1), func_0xa0fb65c4(2, 0x301, 4), func_0xa0fb65c4(2, 0x30e, 0xd), then
 * func_0xa0fb69fc(2, r, v) for (r, v) = (0xa6, 0x41), (0xa4, 0), (0xa5, 1), (0xa7, 0xd), (0xa4, 0x20).
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
extern void func_0xa0fb65c4();
extern void func_0xa0fb69fc();
extern void func_0xa0fb6aa0();

void FUN_a00c18fc(void)

{
  
  func_0xa0fb65c4(2,0x41,0x10);
  func_0xa0fb65c4(2,0x3f,0x74);
  func_0xa0fb69fc(2,0x3f,0x74);
  func_0xa0fb6aa0(2,0x43,1,1);
  func_0xa0fb65c4(2,0x301,4);
  func_0xa0fb65c4(2,0x30e,0xd);
  func_0xa0fb69fc(2,0xa6,0x41);
  func_0xa0fb69fc(2,0xa4,0);
  func_0xa0fb69fc(2,0xa5,1);
  func_0xa0fb69fc(2,0xa7,0xd);
  func_0xa0fb69fc(2,0xa4,0x20);
  return;
}