/* FUN_a0091540 (leon2s, 0xa0091540-0xa0091578, 14 words, leaf). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void (u8 port). For port 0 or 1: clears bit 31 of word 0 of the 7-word record port of ARR_a807d580 (offset port * 0x1c).
 Required form: ARR_a807d580 as a u32 array indexed [port * 7] gives the fw [base + off] operand order; byte arithmetic swaps it. Aids: none.
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
extern unsigned int ARR_a807d580[];

void FUN_a0091540(unsigned char port)
{
    if (port < 2)
        ARR_a807d580[port * 7] &= 0x7fffffff;
}
