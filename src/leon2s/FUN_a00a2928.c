/* leon2s FUN_a00a2928 @ 0xa00a2928 (-mcpu=v8 -Os -g)
 * Calls FUN_a00638a0() and FUN_a00a69fc(1, 0x9c8, 1). If the byte DAT_a807d971 is non-zero it tail-calls
 * FUN_a00a0c84(1, 0, param_3..param_6); otherwise it calls FUN_a00a0bfc(1) and tail-calls FUN_a00a0b10(1, 0).
 *
 * Required form: the `!= 0` arm comes first, so the target's be branches to the FUN_a00a0bfc path.
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

extern unsigned char DAT_a807d971;
extern void FUN_a00638a0(void);
extern int FUN_a00a0b10();
extern void FUN_a00a0bfc(uint);
extern int FUN_a00a0c84();
extern void FUN_a00a69fc(unsigned int, unsigned short, unsigned int);

int FUN_a00a2928(undefined4 param_1, undefined4 param_2, int param_3, undefined4 param_4,
                 undefined4 param_5, undefined4 param_6)

{
  FUN_a00638a0();
  FUN_a00a69fc(1,0x9c8,1);
  if (DAT_a807d971 != 0) {
    return FUN_a00a0c84(1,0,param_3,param_4,param_5,param_6);
  }
  FUN_a00a0bfc(1);
  return FUN_a00a0b10(1,0);
}
