/* FUN_a009e894 (leon2m, 0xa009e894-0xa009e91c, 34 words). Flags -mcpu=v8 -O3 -g.
 * Code facts: void(void). If _DAT_a802afec != 0x1c or FUN_a00d7d48() != 0: _DAT_a802afec = 0x10f. If it is (still)
 * 0x1c: FUN_a0146dc0(1, 0). FUN_a00b848c(); _DAT_a802d03c = (u16)func_0x4008d588(); _DAT_a802cff4 |= 0x100.
 * FUN_a00d7d48 takes no argument: its entry never reads %i0; the fw 'mov 0x10f,%o0' in the be delay slot is the
 * store value filled from the fall-through, dead on the call path. FUN_a00b848c takes none either: the 1/0 set-up
 * before it belongs to the hoisted FUN_a0146dc0 call.
 * Compiler aids: none.
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
extern unsigned int _DAT_a802afec;
extern unsigned short _DAT_a802cff4;
extern unsigned short _DAT_a802d03c;
extern void FUN_a00b848c(void);
extern int FUN_a00d7d48(void);
extern void FUN_a0146dc0(unsigned int, unsigned int);
extern unsigned short func_0x4008d588(void);

void FUN_a009e894(void)
{
    if (_DAT_a802afec != 0x1c || FUN_a00d7d48() != 0)
        _DAT_a802afec = 0x10f;
    if (_DAT_a802afec == 0x1c)
        FUN_a0146dc0(1, 0);
    FUN_a00b848c();
    _DAT_a802d03c = func_0x4008d588();
    _DAT_a802cff4 = _DAT_a802cff4 | 0x100;
}
