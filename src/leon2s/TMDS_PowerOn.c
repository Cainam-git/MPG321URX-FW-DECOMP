/* leon2s TMDS_PowerOn @ 0xa0074c78 (-mcpu=v8 -Os)
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
extern int FUN_a0073044();
extern void FUN_a00734d8();
extern void FUN_a007381c();
extern void FUN_a0073c24();
extern void FUN_a00a7424();
extern void FUN_a00a7488();

void TMDS_PowerOn(undefined1 param_1)

{
  
  FUN_a0073044("TMDS_PowerOn  %d  \r\n",param_1);
  FUN_a007381c(param_1,1);
  FUN_a00a7424(1,7,param_1,0x1c04);
  FUN_a00a7424(1,7,param_1,0x2c04);
  FUN_a00a7488(param_1,0x1000,0xffffff00,0xf9);
  FUN_a0073c24(param_1,1);
  FUN_a00734d8(param_1);
  return;
}
