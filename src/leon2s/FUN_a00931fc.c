/* leon2s FUN_a00931fc @ 0xa00931fc (-mcpu=v8 -Os -g)
 * Copies values through the read function pointer at 0xa807d5b8, called as fn(param_1 & 0xFF, index), into
 * FUN_a00a8054(param_2, 0, dst, value): indexes 0x12A..0x12C to 0x11E..0x120 and 0x130..0x131 to 0x121..0x122,
 * then FUN_a00a80cc(param_2, 0, 0x13E, 0x30, 0), indexes 0x180..0x188 to the same index, and finally
 * FUN_a00a80cc(param_2, 0, 0x13E, 0x30, 1).
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

extern code *_DAT_a807d5b8;
extern void FUN_a00a8054(uint param_1, uint param_2, unsigned short param_3, uint param_4);
extern void FUN_a00a80cc(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5);

void FUN_a00931fc(uint param_1, undefined1 param_2)
{
  unsigned char i;
  unsigned short idx;
  unsigned char result;

  i = 0;
  do {
    idx = (unsigned short)(i + 0x12a);
    result = (unsigned char)(*_DAT_a807d5b8)(param_1 & 0xff, idx);
    FUN_a00a8054(param_2, 0, (unsigned short)(i + 0x11e), result);
    i = i + 1;
  } while (i <= 2);

  i = 0;
  do {
    idx = (unsigned short)(i + 0x130);
    result = (unsigned char)(*_DAT_a807d5b8)(param_1 & 0xff, idx);
    FUN_a00a8054(param_2, 0, (unsigned short)(i + 0x121), result);
    i = i + 1;
  } while (i <= 1);

  FUN_a00a80cc(param_2, 0, 0x13e, 0x30, 0);

  i = 0;
  do {
    idx = (unsigned short)(i + 0x180);
    result = (unsigned char)(*_DAT_a807d5b8)(param_1 & 0xff, idx);
    FUN_a00a8054(param_2, 0, idx, result);
    i = i + 1;
  } while (i <= 8);

  FUN_a00a80cc(param_2, 0, 0x13e, 0x30, 1);
}
