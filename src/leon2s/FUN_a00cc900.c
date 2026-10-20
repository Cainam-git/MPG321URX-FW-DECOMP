/* leon2s FUN_a00cc900 @ 0xa00cc900  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Per-port refresh (param_1 = port): runs
 * FUN_a00c9968(port, 1), then compares two per-port values, FUN_a00c9368(port) and
 * FUN_a00c9750(port) (low bytes); when they differ, applies the first via FUN_a00cc834(port,
 * value). Finally sets bits 16-17 (0x30000) in the first word of the port's 24-byte record at
 * 0xa8078bb0. Ghidra had lost the port argument on both value reads.
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
extern unsigned char DAT_a8078bb0;
extern undefined4 FUN_a00c9368();
extern int FUN_a00c9750();
extern int FUN_a00c9968();
extern int FUN_a00cc834();

void FUN_a00cc900(uint param_1)

{
  unsigned char uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 & 0xff;
  FUN_a00c9968(uVar3,1);
  uVar1 = FUN_a00c9368(uVar3);
  uVar2 = FUN_a00c9750(uVar3);
  if ((uVar1 & 0xff) != (uVar2 & 0xff)) {
    FUN_a00cc834(uVar3,uVar1 & 0xff);
  }
  *(uint *)(&DAT_a8078bb0 + uVar3 * 0x18) = *(uint *)(&DAT_a8078bb0 + uVar3 * 0x18) | 0x30000;
}