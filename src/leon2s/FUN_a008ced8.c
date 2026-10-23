/* leon2s FUN_a008ced8 @ 0xa008ced8 (-mcpu=v8 -Os)
 * Fixed hardware register set-up (volatile): 0xCF012448 = 0; 0xCF014760 = 0x50 when FUN_a008d800() & 0xff > 0x81, else 3;
 * FUN_a00b1d00(n, 0x40, v) for n 0..3 (0x50, 0x50, 0x20, 0x20), 0xCF014754 |= 0x10, FUN_a00b1d00(5, 0x40, 0x40),
 * 0xCF014754 |= 0x20, FUN_a00b1d00(7, 0x40, 0x40); 0xCF0147C0..CC = 0, 0, 0, 0xc; pulses 0xCF014788 (0xf1, 0xf0) and
 * 0xCF014790 (1, 0); FUN_a00b1794(1); 0xCF0146C0 = 0x22, 0xCF0146C4 = 8, 0xCF0146FC = 0x80, 0x81, 0x80 and the same
 * at 0xCF014700 / 704 / 73C; FUN_a00b1794(1); 0xCF0146C4 = 0xCF014704 = 0; when FUN_a008d800() & 0xff > 0x81 again:
 * 0xCF014774 = 2, FUN_a00b1d00(4, 0x80, 0x80), FUN_a00b1d00(6, 0x80, 0x80); then 0xCF01249C = 0x20 and
 * 0xCF012498 / 494 / 490 = 0.
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

#define _DAT_cf012448 (*(volatile unsigned int *)0xcf012448)
#define _DAT_cf012490 (*(volatile unsigned int *)0xcf012490)
#define _DAT_cf012494 (*(volatile unsigned int *)0xcf012494)
#define _DAT_cf012498 (*(volatile unsigned int *)0xcf012498)
#define _DAT_cf01249c (*(volatile unsigned int *)0xcf01249c)
#define _DAT_cf0146c0 (*(volatile unsigned int *)0xcf0146c0)
#define _DAT_cf0146c4 (*(volatile unsigned int *)0xcf0146c4)
#define _DAT_cf0146fc (*(volatile unsigned int *)0xcf0146fc)
#define _DAT_cf014700 (*(volatile unsigned int *)0xcf014700)
#define _DAT_cf014704 (*(volatile unsigned int *)0xcf014704)
#define _DAT_cf01473c (*(volatile unsigned int *)0xcf01473c)
#define _DAT_cf014754 (*(volatile unsigned int *)0xcf014754)
#define _DAT_cf014760 (*(volatile unsigned int *)0xcf014760)
#define _DAT_cf014774 (*(volatile unsigned int *)0xcf014774)
#define _DAT_cf014788 (*(volatile unsigned int *)0xcf014788)
#define _DAT_cf014790 (*(volatile unsigned int *)0xcf014790)
#define _DAT_cf0147c0 (*(volatile unsigned int *)0xcf0147c0)
#define _DAT_cf0147c4 (*(volatile unsigned int *)0xcf0147c4)
#define _DAT_cf0147c8 (*(volatile unsigned int *)0xcf0147c8)
#define _DAT_cf0147cc (*(volatile unsigned int *)0xcf0147cc)

extern unsigned char FUN_a008d800(void);
extern int FUN_a00b1794(int);
extern void FUN_a00b1d00(unsigned int, unsigned int, unsigned int);

void FUN_a008ced8(void)
{
    unsigned int uVar1;
    
    _DAT_cf012448 = 0;
    uVar1 = FUN_a008d800();
    if ((uVar1 & 0xff) > 0x81) {
        _DAT_cf014760 = 0x50;
    } else {
        _DAT_cf014760 = 3;
    }
    
    FUN_a00b1d00(0, 0x40, 0x50);
    FUN_a00b1d00(1, 0x40, 0x50);
    FUN_a00b1d00(2, 0x40, 0x20);
    FUN_a00b1d00(3, 0x40, 0x20);
    
    _DAT_cf014754 = _DAT_cf014754 | 0x10;
    FUN_a00b1d00(5, 0x40, 0x40);
    _DAT_cf014754 = _DAT_cf014754 | 0x20;
    FUN_a00b1d00(7, 0x40, 0x40);
    
    _DAT_cf0147c0 = 0;
    _DAT_cf0147c4 = 0;
    _DAT_cf0147c8 = 0;
    _DAT_cf0147cc = 0xc;
    _DAT_cf014788 = 0xf1;
    _DAT_cf014788 = 0xf0;
    _DAT_cf014790 = 1;
    _DAT_cf014790 = 0;
    
    FUN_a00b1794(1);
    
    _DAT_cf0146c0 = 0x22;
    _DAT_cf0146c4 = 8;
    _DAT_cf0146fc = 0x80;
    _DAT_cf0146fc = 0x81;
    _DAT_cf0146fc = 0x80;
    _DAT_cf014700 = 0x22;
    _DAT_cf014704 = 8;
    _DAT_cf01473c = 0x80;
    _DAT_cf01473c = 0x81;
    _DAT_cf01473c = 0x80;
    
    FUN_a00b1794(1);
    
    _DAT_cf0146c4 = 0;
    _DAT_cf014704 = 0;
    
    uVar1 = FUN_a008d800();
    if ((uVar1 & 0xff) > 0x81) {
        _DAT_cf014774 = 2;
        FUN_a00b1d00(4, 0x80, 0x80);
        FUN_a00b1d00(6, 0x80, 0x80);
    }
    
    _DAT_cf01249c = 0x20;
    _DAT_cf012498 = 0;
    _DAT_cf012494 = 0;
    _DAT_cf012490 = 0;
}
