/* leon2s FUN_a008a470 @ 0xa008a470-0xa008a590 (72 words), flags -mcpu=v8 -Os -g.
 * Register 0xcf0114b0 &= ~4; then four 7-word write blocks to 0xcf011000/04/08/0c/10/58/5c (values
 * 0,0,0,0x12,1 | 0,0xee,0,0x12,0 | 0,0xee,1,2,0xfc | 0,0xee,1,0,0xfc; 0x58 and 0x5c = 0xc6 each time,
 * 0x58 first); if (byte 0xa8076688 & 1) 0xcf011008 |= 0x20; 0xcf011014 = 0xff; 0xcf011048 |= 0x60;
 * 0xcf011080 |= 0x30; 0xcf011018 |= 0xc. Leaf.
 * 0x58 is written before 0x5c in every block, block 4 also writes 0x5c, and 0xcf011018 gets one
 * read-modify-write only.
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

extern char DAT_a8076688;

#define _DAT_cf011000 (*(volatile unsigned int *)0xcf011000)
#define _DAT_cf011004 (*(volatile unsigned int *)0xcf011004)
#define _DAT_cf011008 (*(volatile unsigned int *)0xcf011008)
#define _DAT_cf01100c (*(volatile unsigned int *)0xcf01100c)
#define _DAT_cf011010 (*(volatile unsigned int *)0xcf011010)
#define _DAT_cf011014 (*(volatile unsigned int *)0xcf011014)
#define _DAT_cf011018 (*(volatile unsigned int *)0xcf011018)
#define _DAT_cf011048 (*(volatile unsigned int *)0xcf011048)
#define _DAT_cf011058 (*(volatile unsigned int *)0xcf011058)
#define _DAT_cf01105c (*(volatile unsigned int *)0xcf01105c)
#define _DAT_cf011080 (*(volatile unsigned int *)0xcf011080)
#define _DAT_cf0114b0 (*(volatile unsigned int *)0xcf0114b0)

void FUN_a008a470(void)
{
  _DAT_cf0114b0 = _DAT_cf0114b0 & 0xfffffffb;
  _DAT_cf011000 = 0;
  _DAT_cf011004 = 0;
  _DAT_cf011008 = 0;
  _DAT_cf01100c = 0x12;
  _DAT_cf011010 = 1;
  _DAT_cf011058 = 0xc6;
  _DAT_cf01105c = 0xc6;
  _DAT_cf011000 = 0;
  _DAT_cf011004 = 0xee;
  _DAT_cf011008 = 0;
  _DAT_cf01100c = 0x12;
  _DAT_cf011010 = 0;
  _DAT_cf011058 = 0xc6;
  _DAT_cf01105c = 0xc6;
  _DAT_cf011000 = 0;
  _DAT_cf011004 = 0xee;
  _DAT_cf011008 = 1;
  _DAT_cf01100c = 2;
  _DAT_cf011010 = 0xfc;
  _DAT_cf011058 = 0xc6;
  _DAT_cf01105c = 0xc6;
  _DAT_cf011000 = 0;
  _DAT_cf011004 = 0xee;
  _DAT_cf011008 = 1;
  _DAT_cf01100c = 0;
  _DAT_cf011010 = 0xfc;
  _DAT_cf011058 = 0xc6;
  _DAT_cf01105c = 0xc6;
  if ((DAT_a8076688 & 1) != 0) {
    _DAT_cf011008 = _DAT_cf011008 | 0x20;
  }
  _DAT_cf011014 = 0xff;
  _DAT_cf011048 = _DAT_cf011048 | 0x60;
  _DAT_cf011080 = _DAT_cf011080 | 0x30;
  _DAT_cf011018 = _DAT_cf011018 | 0xc;
}
