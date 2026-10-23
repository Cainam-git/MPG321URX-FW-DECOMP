/* leon2s FUN_a00aec10 @ 0xa00aec10 (-mcpu=v8 -Os -g)
 * Sets bit 1 of the word at (word 0xA807DC04) + 0xB4.
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
extern unsigned int _DAT_a807dc04;

void FUN_a00aec10(void)

{
  *(volatile uint *)(_DAT_a807dc04 + 0xb4) = *(volatile uint *)(_DAT_a807dc04 + 0xb4) | 2;
  return;
}