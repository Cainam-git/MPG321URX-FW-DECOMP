/* leon2m FUN_a00b3ed0 @ 0xa00b3ed0  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Sets up an output window for port mode param_2.
 * Mode 1, and modes 0x13/0x27, use small margins (2,3,4 and a width of param_4 - 3 or - 2);
 * every other mode uses (7,0x1c,0xb,0x1f) and the full param_4. With param_1 == 0 only two
 * resets via FUN_a0146c40 run. Otherwise the area is computed from param_2, param_3 and the
 * width, and programmed through FUN_a014667c, FUN_a0146870 and FUN_a014692c. Needed the
 * default width assigned before the mode checks.
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
#define CONCAT11(a, b) ((unsigned short)(((unsigned)(a) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT13(a, b) (((unsigned)(a) << 24) | ((unsigned)(b) & 0xffffff))
#define CONCAT21(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define CONCAT22(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define SUB41(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define SUB42(x, c) ((unsigned short)((unsigned)(x) >> ((c) * 8)))
#define SUB43(x, c) (((unsigned)(x) >> ((c) * 8)) & 0xffffff)
#define SUB21(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define ZEXT14(x) ((unsigned)(unsigned char)(x))
#define ZEXT24(x) ((unsigned)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
#define SEXT14(x) ((int)(signed char)(x))
#define SEXT24(x) ((int)(short)(x))
#define SEXT12(x) ((short)(signed char)(x))
extern void FUN_a014667c();
extern void FUN_a0146870();
extern void FUN_a014692c();
extern void FUN_a0146c40();

void FUN_a00b3ed0(unsigned char param_1, unsigned char param_2,uint param_3,uint param_4,undefined4 param_5,
            undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  unsigned char uVar5;
  unsigned char uVar6;
  unsigned char uVar7;
  unsigned char uVar8;
  
  param_2 = param_2 & 0xff;
  uVar1 = param_4;
  if (param_2 == 1) {
    uVar1 = param_4 - 3;
    uVar7 = 2;
    uVar8 = 3;
    uVar5 = 4;
    uVar6 = 4;
  }
  else if (param_2 == 0x13 || param_2 == 0x27) {
    uVar7 = 2;
    uVar8 = 3;
    uVar5 = 4;
    uVar1 = param_4 - 2;
    uVar6 = 5;
  }
  else {
    uVar7 = 7;
    uVar8 = 0x1c;
    uVar5 = 0xb;
    uVar6 = 0x1f;
  }
  if (param_1 == '\0') {
    FUN_a0146c40(1,0,0);
    uVar7 = 2;
    uVar8 = 0;
    return FUN_a0146c40(2,0,0,param_4);
  }
  FUN_a0146c40(1,0,0);
  FUN_a0146c40(2,0,0);
  FUN_a014667c(2,0,0,0,0,0xe,0,0,0,0,0);
  iVar3 = (param_3 & 0xff) * 0x24;
  iVar2 = param_2 * 0x18 + 0x18;
  iVar4 = (param_2 + (uVar1 & 0xff)) * 0x18 + 0x17;
  FUN_a0146870(2,iVar2,iVar3 + 0x16,iVar4,iVar3 + 0x19,0);
  FUN_a014692c(2,0,0,1,uVar7,uVar8,0);
  FUN_a014692c(2,1,0,0,uVar5,uVar6,0);
  FUN_a014692c(2,2,0,0,0,0,0);
  FUN_a014667c(1,0,0,0,0,0xe,0,0,0,0,0);
  FUN_a0146870(1,iVar2,iVar3 + 0x52,iVar4,iVar3 + 0x55,0);
  FUN_a014692c(1,0,0,1,uVar7,uVar8,0);
  FUN_a014692c(1,1,0,0,uVar5,uVar6,0);
  FUN_a014692c(1,2,0,0,0,0,0);
  return CONCAT44((param_3 & 0xff) * 8,param_2 * 3);
}