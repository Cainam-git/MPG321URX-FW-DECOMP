/* FUN_a00d7844 (leon2s, 7 words, leaf; twin pair FUN_a00d7844/FUN_a00d7860). Flags -mcpu=v8 -Os -g.
 Code facts: void (u8 *src, u8 *dst): dst[0] = src[0] & 0x7f; dst[1] = src[1] & 0xf0.
 Fix vs draft: the second value goes through an unsigned short temp (fw 'and %g1,0xf0' in SImode; the direct byte form gives the QImode
 mask 'and -16'), same lever as FUN_a00d76ac. Aids: none.
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


void FUN_a00d7844(byte *param_1,byte *param_2)

{
  unsigned short t;

  *param_2 = *param_1 & 0x7f;
  t = param_1[1] & 0xf0;
  param_2[1] = t;
  return;
}