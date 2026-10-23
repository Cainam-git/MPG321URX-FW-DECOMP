/* leon2s FUN_a0088f84 @ 0xa0088f84 (-mcpu=v8 -Os)
 * Returns the byte at 0xA80761B0. A leaf routine without a register window.
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
extern unsigned char DAT_a80761b0;

undefined1 FUN_a0088f84(void)

{
  return DAT_a80761b0;
}