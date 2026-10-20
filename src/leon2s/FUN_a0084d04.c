/* leon2s FUN_a0084d04 @ 0xa0084d04  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical Ghidra C, finished by hand: 300-byte record array, register read results restored, byte casts and Ghidra
 * type names kept.
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
extern unsigned int DAT_a807d319;
extern unsigned int DAT_a807d369;
extern unsigned char ARR_a807dc18[][300];
extern int FUN_a0083ed0();
extern int FUN_a008d800();
extern int FUN_a00a74b8();
extern void FUN_a00a7614();
extern int FUN_a00a7718();

void FUN_a0084d04(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  unsigned short uVar2;
  unsigned char *pcVar3;
  unsigned char uVar4;
  
  uVar2 = FUN_a0083ed0(param_1 & 0xff);
  uVar4 = uVar2 & 0xff;
  FUN_a00a7614(uVar4,0,0xc0);
  FUN_a00a7614(uVar4,0x5e,0xd1);
  FUN_a00a7614(uVar4,0x5f,0x95);
  FUN_a00a7614(uVar4,0x75,0xd);
  FUN_a00a7614(uVar4,0xaf,0x84);
  FUN_a00a7614(uVar4,0x48f,0x48);
  FUN_a00a7614(uVar4,0x490,0x81);
  FUN_a00a7614(uVar4,0x469,0x2d);
  FUN_a00a7614(uVar4,0x423,0x62);
  FUN_a00a7614(uVar4,0x118,0xf);
  FUN_a00a7614(uVar4,0x198,0xf);
  FUN_a00a7614(uVar4,0x218,0xf);
  FUN_a00a7614(uVar4,0x298,0xf);
  FUN_a00a7614(uVar4,0x119,0xdf);
  FUN_a00a7614(uVar4,0x199,0xdf);
  FUN_a00a7614(uVar4,0x219,0xdf);
  FUN_a00a7614(uVar4,0x299,0xdf);
  FUN_a00a7614(uVar4,0x9e,0xc5);
  FUN_a00a7614(uVar4,0x465,0x77);
  FUN_a00a7614(uVar4,0x466,0x37);
  FUN_a00a7614(uVar4,0x30,0x77);
  FUN_a00a7614(uVar4,0x31,0x89);
  FUN_a00a7614(uVar4,0x32,0x2f);
  FUN_a00a7614(uVar4,0x37,0xa8);
  FUN_a00a7614(uVar4,0x7e,0xb9);
  FUN_a00a7614(uVar4,0x76,0x90);
  FUN_a00a7614(uVar4,0xaa,0xeb);
  FUN_a00a7614(uVar4,0xa4,0x61);
  FUN_a00a7614(uVar4,0xa5,0xc4);
  FUN_a00a7614(uVar4,0xa6,0x9c);
  FUN_a00a7614(uVar4,0xa7,0x2a);
  FUN_a00a7614(uVar4,0x510,1);
  FUN_a00a7614(uVar4,0x610,1);
  FUN_a00a7614(uVar4,0x710,1);
  FUN_a00a7614(uVar4,0x810,1);
  FUN_a00a7614(uVar4,0x464,0xd4);
  FUN_a00a7614(uVar4,0x119,0x5f);
  FUN_a00a7614(uVar4,0x199,0x5f);
  FUN_a00a7614(uVar4,0x219,0x5f);
  FUN_a00a7614(uVar4,0x299,0x5f);
  FUN_a00a7614(uVar4,0x426,0xff);
  FUN_a00a7614(uVar4,0x462,0xf4);
  FUN_a00a7614(uVar4,0x5d,0xff);
  FUN_a00a7614(uVar4,0x68,4);
  FUN_a00a7614(uVar4,0x6f,0xff);
  FUN_a00a7614(uVar4,0x70,0xff);
  FUN_a00a7614(uVar4,0x426,0x4f);
  uVar1 = FUN_a008d800();
  if (0x81 < (uVar1 & 0xff)) {
    FUN_a00a7718(uVar4,0x306,0x80,1);
  }
  FUN_a00a7614(uVar4,4,0xfa);
  if (ARR_a807dc18[param_1 & 0xff][0x11f] == 1) {
    FUN_a00a7614(uVar4,0x55,0xf);
  }
  FUN_a00a7614(uVar4,0x10b,0);
  FUN_a00a7614(uVar4,0x18b,0);
  FUN_a00a7614(uVar4,0x20b,0);
  FUN_a00a7614(uVar4,0x28b,0);
  FUN_a00a7614(uVar4,0x10c,0);
  FUN_a00a7614(uVar4,0x18c,0);
  FUN_a00a7614(uVar4,0x20c,0);
  FUN_a00a7614(uVar4,0x28c,0);
  FUN_a00a7614(uVar4,0x11b,8);
  FUN_a00a7614(uVar4,0x19b,8);
  FUN_a00a7614(uVar4,0x21b,8);
  FUN_a00a7614(uVar4,0x29b,8);
  FUN_a00a7614(uVar4,0x11c,0xe);
  FUN_a00a7614(uVar4,0x19c,0xe);
  FUN_a00a7614(uVar4,0x21c,0xe);
  FUN_a00a7614(uVar4,0x29c,0xe);
  FUN_a00a7614(uVar4,0x11e,0x40);
  FUN_a00a7614(uVar4,0x19e,0x40);
  FUN_a00a7614(uVar4,0x21e,0x40);
  FUN_a00a7614(uVar4,0x29e,0x40);
  FUN_a00a7614(uVar4,0x127,0x10);
  FUN_a00a7614(uVar4,0x1a7,0x10);
  FUN_a00a7614(uVar4,0x227,0x10);
  FUN_a00a7614(uVar4,0x2a7,0x10);
  FUN_a00a7614(uVar4,0x150,8);
  FUN_a00a7614(uVar4,0x1d0,8);
  FUN_a00a7614(uVar4,0x250,8);
  FUN_a00a7614(uVar4,0x2d0,8);
  FUN_a00a7614(uVar4,0x46d,5);
  FUN_a00a7614(uVar4,0x4e9,0);
  FUN_a00a7614(uVar4,0x4b1,0);
  FUN_a00a7614(uVar4,0x4b2,0);
  FUN_a00a7614(uVar4,0x4d1,0);
  FUN_a00a7614(uVar4,0x550,0x2a);
  FUN_a00a7614(uVar4,0x650,0x2a);
  FUN_a00a7614(uVar4,0x750,0x2a);
  FUN_a00a7614(uVar4,0x850,0x2a);
  FUN_a00a7614(uVar4,0x553,0xb);
  FUN_a00a7614(uVar4,0x653,0xb);
  FUN_a00a7614(uVar4,0x753,0xb);
  FUN_a00a7614(uVar4,0x853,0xb);
  FUN_a00a7614(uVar4,0x554,0x80);
  FUN_a00a7614(uVar4,0x654,0x80);
  FUN_a00a7614(uVar4,0x754,0x80);
  FUN_a00a7614(uVar4,0x854,0x80);
  FUN_a00a7614(uVar4,0x559,0x10);
  FUN_a00a7614(uVar4,0x659,0x10);
  FUN_a00a7614(uVar4,0x759,0x10);
  FUN_a00a7614(uVar4,0x859,0x10);
  FUN_a00a7614(uVar4,0x562,0);
  FUN_a00a7614(uVar4,0x662,0);
  FUN_a00a7614(uVar4,0x762,0);
  FUN_a00a7614(uVar4,0x862,0);
  FUN_a00a7614(uVar4,0x569,0);
  FUN_a00a7614(uVar4,0x669,0);
  FUN_a00a7614(uVar4,0x769,0);
  FUN_a00a7614(uVar4,0x869,0);
  FUN_a00a7614(uVar4,0x56a,0);
  FUN_a00a7614(uVar4,0x66a,0);
  FUN_a00a7614(uVar4,0x76a,0);
  FUN_a00a7614(uVar4,0x86a,0);
  FUN_a00a7614(uVar4,0x56b,0);
  FUN_a00a7614(uVar4,0x66b,0);
  FUN_a00a7614(uVar4,0x76b,0);
  FUN_a00a7614(uVar4,0x86b,0);
  FUN_a00a7614(uVar4,0x56c,0);
  FUN_a00a7614(uVar4,0x66c,0);
  FUN_a00a7614(uVar4,0x76c,0);
  FUN_a00a7614(uVar4,0x86c,0);
  FUN_a00a7614(uVar4,0x5d3,8);
  FUN_a00a7614(uVar4,0x6d3,8);
  FUN_a00a7614(uVar4,0x7d3,8);
  FUN_a00a7614(uVar4,0x8d3,8);
  pcVar3 = &DAT_a807d319;
  if (uVar4 != 0) {
    pcVar3 = &DAT_a807d369;
  }
  if (*pcVar3 == 0xa0) {
    FUN_a00a7614(uVar4,0x30,pcVar3[3]);
    uVar1 = uVar4;
    uVar1 = FUN_a00a74b8(uVar4,0x31);
    FUN_a00a7614(uVar4,0x31,(unsigned char)(uVar1 & 0xf0 | pcVar3[4]));
    uVar1 = uVar4;
    uVar1 = FUN_a00a74b8(uVar4,0x32);
    FUN_a00a7614(uVar4,0x32,(unsigned char)(uVar1 & 0xe0 | pcVar3[5]));
    uVar1 = FUN_a00a74b8(uVar4,0x7e);
    FUN_a00a7614(uVar4,0x7e,uVar1 & 7 | (uint)(byte)pcVar3[7]);
    uVar1 = FUN_a00a74b8(uVar4,0x76);
    FUN_a00a7614(uVar4,0x76,uVar1 & 0x1f | (uint)(byte)pcVar3[6]);
  }
  uVar2 = uVar2 & 0xff;
  FUN_a00a7614(uVar2,0xaf,0x94);
  FUN_a00a7614(uVar2,0x4a8,0xff);
  FUN_a00a7614(uVar2,0x4a9,0xfd);
  FUN_a00a7614(uVar2,0x4ab,2);
  FUN_a00a7614(uVar2,0x4ac,2);
  FUN_a00a7614(uVar2,0x4b1,2);
  FUN_a00a7614(uVar2,0x4b1,0);
  FUN_a00a7614(uVar2,0x4b2,2);
  FUN_a00a7614(uVar2,0x4b2,0);
  FUN_a00a7614(uVar2,0x4ae,0xfd);
  FUN_a00a7614(uVar2,0x4af,0xfd,param_4,param_5,param_6);
  return;
}