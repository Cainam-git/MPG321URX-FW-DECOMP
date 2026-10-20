/* leon2s FUN_a00a9380 @ 0xa00a9380  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: [walk]; swap lines 15; swap lines 17; swap lines 15; void -> int, return 0; swap lines 18; swap lines 17; swap lines 19; swap lines 20; return void; [walk]; swap lines 18; swap lines 19; swap lines 18; swap lines 20; swap lines 18
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


void FUN_a00a9380(unsigned char param_1,undefined1 *param_2)

{
  *param_2 = 0x7f;
  param_2[1] = 0xc0;
  param_2[2] = 0;
  param_2[4] = 0;
  param_2[5] = 1;
  param_2[7] = 1;
  param_2[9] = 4;
  param_2[6] = 0;
  param_2[8] = 0;
  if (param_1 == '\x01') {
    param_2[3] = 0x84;
    param_2[10] = 1;
  }
  else {
    param_2[3] = 0xc4;
    param_2[10] = 0;
  }
  return 0;
  return 0;
}