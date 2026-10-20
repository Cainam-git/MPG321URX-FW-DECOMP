/* FUN_a006155c (leon2s, 0xa006155c-0xa0061578, 7 words, leaf). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: byte read through an aligned word access: w = word at (addr & ~3); returns (w >> ((addr & 3) << 3)) & 0xff (fw: and 3, and -4,
 ld, sll 3, srl, and 0xff). Fix vs draft: the word load is a separate statement before the shift (the one-expression form schedules
 the sll before the and -4/ld). Not volatile: nothing shows the address is a hardware register. Aids: none.
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


unsigned int FUN_a006155c(unsigned int addr)
{
    unsigned int w = *(unsigned int *)(addr & ~3);

    return (w >> ((addr & 3) << 3)) & 0xff;
}
