/* leon2m FUN_a0088654 @ 0xa0088654 (-mcpu=v8 -Os -g)
 * Returns bit 0 of byte 0xA802AF99 and clears that bit.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char DAT_a802af99;

byte FUN_a0088654(void)

{
  byte bVar1;
  
  bVar1 = DAT_a802af99;
  DAT_a802af99 = DAT_a802af99 & 0xfe;
  return bVar1 & 1;
}