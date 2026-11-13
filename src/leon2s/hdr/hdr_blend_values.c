/* hdr_blend_values  (FUN_a00d36e4)
 *
 * Blend two values with a weight of n/256.
 * Returns: blended value
 * Name basis: proven - (b * (256 - w) + a * w + 128) >> 8
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d36e4 @ 0xa00d36e4 (-mcpu=v8 -Os -g)
 * Source form: the decompiler's type names are kept; the expression is written as one return statement.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


/*
 * Weighted mean of new_value and old_value, rounded: (old_value * (256 - weight) + new_value * weight + 128) >> 8.
 * weight is in 256ths. hdr_smooth_level calls it with weight 0x28.
 */
uint hdr_blend_values(int new_value,int old_value,int weight)

{
  return old_value * (0x100 - weight) + new_value * weight + 0x80U >> 8;
}