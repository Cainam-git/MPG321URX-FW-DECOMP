/* leon2s FUN_a00c0ce8 @ 0xa00c0ce8 (-mcpu=v8 -Os -g)
 * p = p1 & 0xff. Through the ROM register routines of port p: func_0xa0fb67b8(p, 0x40, 8, 1); the 5 bytes of a (p2) to
 * registers 0x1a..0x1e (func_0xa0fb65c4); v = register 0x41 (func_0xa0fb657c); s = low byte of register 0xCF011438;
 * func_0xa0fb67b8(p, 0x41, 0x80, 1). Then 0xCF011438 |= 4, 0xCF011780 = 0x32, 0xCF011784 = 0xCF011788 = 0,
 * 0xCF00BFCC = 0, the 0x11a bytes of b (p3) one by one to 0xCF01178C, register 0x41 = v & 0xff and 0xCF011438 = s.
 * Same data sizes as FUN_a00c0a88 / FUN_a00c0dfc. volatile: the 0xcf... hardware registers.
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
#define _DAT_cf00bfcc (*(volatile unsigned int *)0xcf00bfcc)
#define _DAT_cf011438 (*(volatile unsigned int *)0xcf011438)
#define _DAT_cf011780 (*(volatile unsigned int *)0xcf011780)
#define _DAT_cf011784 (*(volatile unsigned int *)0xcf011784)
#define _DAT_cf011788 (*(volatile unsigned int *)0xcf011788)
#define _DAT_cf01178c (*(volatile unsigned int *)0xcf01178c)
extern int func_0xa0fb657c();
extern int func_0xa0fb65c4();
extern int func_0xa0fb67b8();

void FUN_a00c0ce8(signed char param_1, unsigned int param_2,int param_3)

{
    unsigned short t11_;
  unsigned char uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar5 = param_1;
  
  uVar5 = uVar5 & 0xff;
  func_0xa0fb67b8(uVar5,0x40,8,1);
  uVar4 = 0;
  do {
    t11_ = uVar4 + 0x1a;
    func_0xa0fb65c4(uVar5, t11_, *(undefined1 *)(param_2 + uVar4));
    uVar4 = uVar4 + 1;
  } while (5 > uVar4);
  uVar2 = func_0xa0fb657c(uVar5,0x41);
  uVar1 = _DAT_cf011438;
  func_0xa0fb67b8(uVar5,0x41,0x80,1);
  _DAT_cf011438 = _DAT_cf011438 | 4;
  _DAT_cf011780 = 0x32;
  _DAT_cf011784 = 0;
  _DAT_cf011788 = 0;
  _DAT_cf00bfcc = 0;
  uVar4 = 0;
  do {
    _DAT_cf01178c = *(byte *)(param_3 + uVar4);
    uVar3 = uVar4 + 1;
    uVar4 = uVar3;
  } while (uVar3 < 0x11a);
  func_0xa0fb65c4(uVar5, 0x41, uVar2 & 0xff);
  _DAT_cf011438 = uVar1 & 0xff;
}