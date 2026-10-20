/* leon2m FUN_a00bacc4 @ 0xa00bacc4  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a00bac3c: same code, constants swapped; byte-exact.
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
extern unsigned char DAT_a802d078[];
extern int FUN_a015463c();

void FUN_a00bacc4(unsigned char param_1, undefined4 param_2)

{
  unsigned char uVar1;
  
  uVar1 = param_1 & 0xff;
  DAT_a802d078[0] = FUN_a015463c(uVar1, 0);
  DAT_a802d078[1] = 0x62;
  DAT_a802d078[2] = FUN_a015463c(uVar1, 2);
  DAT_a802d078[3] = FUN_a015463c(uVar1, 3);
  DAT_a802d078[4] = FUN_a015463c(uVar1, 4);
  DAT_a802d078[5] = FUN_a015463c(uVar1, 5);
  DAT_a802d078[6] = FUN_a015463c(uVar1, 6);
  DAT_a802d078[10] = 0xd;
  return;
}
