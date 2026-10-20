/* FUN_a0095778 (leon2m, 0xa0095778-0xa00957e8, 28 words). Flags -mcpu=v8 -O3 -g.
 Code facts: void, 6 params (p3..p6 passed on). DAT_a8025c56 = DAT_a802d290[0x190]; _DAT_a802afec = 0x43; FUN_a00a8c88(); FUN_a00a9dac(b, 1) and
 FUN_a00a9dac(b, 0) with b = DAT_a802d290[0x190] re-read after each call; FUN_a00ab0e0(0); FUN_a00a9468(0, 0); FUN_a00a9468(1, 3); tail call
 FUN_a00b34d4(0, 4, p3, p4, p5, p6).
 Fixes vs draft: the byte at 0xa802d290+0x190 is a plain u8 array element (fw ldub; the draft read a volatile word), p4 is a plain word. Aids: none.
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
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802d290[];
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8c88(void);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00a9dac(unsigned int, unsigned int);
extern void FUN_a00ab0e0(unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a0095778(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4,
                  unsigned int param_5, unsigned int param_6)
{
    DAT_a8025c56 = DAT_a802d290[0x190];
    _DAT_a802afec = 0x43;
    FUN_a00a8c88();
    FUN_a00a9dac(DAT_a802d290[0x190], 1);
    FUN_a00a9dac(DAT_a802d290[0x190], 0);
    FUN_a00ab0e0(0);
    FUN_a00a9468(0, 0);
    FUN_a00a9468(1, 3);
    FUN_a00b34d4(0, 4, param_3, param_4, param_5, param_6);
}
