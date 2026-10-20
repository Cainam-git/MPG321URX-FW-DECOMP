/* leon2m FUN_a0094368 @ 0xa0094368  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: [walk]; global DAT_a802d433 unsigned int; callee FUN_a00a6b98 unsigned short; callee func_0x4008e2a4 void; global DAT_a802d433 char; callee FUN_a00b5080 void
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
extern char DAT_a802d433;
extern unsigned int _DAT_a802afec;
extern unsigned short FUN_a00a6b98();
extern void FUN_a00b5080();
extern void func_0x4008e2a4();

void FUN_a0094368(void)

{
  
  DAT_a802d433 = 2;
  _DAT_a802afec = 0x108;
  FUN_a00b5080();
  func_0x4008e2a4();
  func_0x4008e2a4();
  FUN_a00a6b98(2,1,0);
  return;
}