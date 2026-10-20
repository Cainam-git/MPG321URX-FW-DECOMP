/* leon2s FUN_a00ae1c0 @ 0xa00ae1c0 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Pulse on port param_1: saves register 0, clears
 * its bit 5, sets bit 6 of register 0x30, busy-waits 35000 nop iterations, then writes the
 * saved value back to register 0 (FUN_a00a6c00). Probably a reset or calibration kick. The
 * delay loop has an explicit nop that Ghidra drops.
 * Still needs a real name and proper types.
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
extern int FUN_a00a6bb8();
extern int FUN_a00a6c00();
extern void FUN_a00a6c98();

void FUN_a00ae1c0(uint param_1)

{
  unsigned char uVar1;
  ushort uVar2;
  
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a00a6bb8(param_1,0);
  FUN_a00a6c98(param_1,0,0x20,0);
  FUN_a00a6c98(param_1,0x30,0x40,1);
  for (uVar2 = 0; uVar2 < 35000; uVar2++) __asm__("nop");
  FUN_a00a6c00(param_1,0,uVar1 & 0xff);
  return;
}