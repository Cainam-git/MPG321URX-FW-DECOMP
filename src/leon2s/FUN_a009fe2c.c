/* leon2s FUN_a009fe2c @ 0xa009fe2c (-mcpu=v8 -Os -g)
 * Table 0xA807DB00 holds records of 0x34 bytes. With p = word 0 of record p1 & 0xff, sets the bits p2 in the word
 * at p + 0x84 and then clears them (two read-modify-write accesses).
 * Source form: Ghidra's type and symbol names are kept.
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
extern unsigned char DAT_a807db00;

void FUN_a009fe2c(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(volatile int *)(&DAT_a807db00 + (param_1 & 0xff) * 0x34);
  *(volatile uint *)(iVar1 + 0x84) = *(volatile uint *)(iVar1 + 0x84) | param_2;
  *(volatile uint *)(iVar1 + 0x84) = *(volatile uint *)(iVar1 + 0x84) & ~param_2;
  return;
}