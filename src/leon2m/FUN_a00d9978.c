/* leon2m FUN_a00d9978 @ 0xa00d9978 (-mcpu=v8 -O2 -g)
 * Calls FUN_a0125aac() when bit 6 (0x40) of word 0xA802D338 is set, otherwise FUN_a0125ac8().
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
extern unsigned int _DAT_a802d338;
extern void FUN_a0125aac(void);
extern void FUN_a0125ac8(void);

void FUN_a00d9978(void)

{
  if ((_DAT_a802d338 & 0x40) != 0) {
    FUN_a0125aac();
    return;
  }
  FUN_a0125ac8();
  return;
}