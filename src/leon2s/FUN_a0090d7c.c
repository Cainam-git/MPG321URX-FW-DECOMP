/* FUN_a0090d7c (leon2s, 0xa0090d7c-0xa0090dcc, 20 words). Flags -mcpu=v8 -Os -g.
 Code facts: u8 port. v = FUN_a00a657c(port, 0x148) & 0xf (int, signed compares); returns 2 for v == 1, 4 for v == 3, else 1 (cases 0 and default
 both 1), masked & 7 (fw 'and %i0,7').
 Fix vs draft: written as a switch with cases 0/1/3/default (fw cmp 1, bg, cmp 0 / cmp 3 tree); the draft's if/else and CONCAT44 return
 gave the unsigned bgu form. Aids: none.
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
extern unsigned int FUN_a00a657c(unsigned char, unsigned int);

unsigned char FUN_a0090d7c(unsigned char port)
{
    int v = FUN_a00a657c(port, 0x148) & 0xf;
    unsigned char r;

    switch (v) {
    case 0: r = 1; break;
    case 1: r = 2; break;
    case 3: r = 4; break;
    default: r = 1; break;
    }
    return r & 7;
}
