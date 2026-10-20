/* FUN_a009fe60 (leon2s, 0xa009fe60-0xa009fe98, 14 words, leaf). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void (u8 port). r = register-block pointer at +0x14 of the 0x34-byte record port of ARR_a807db00; pulses bit 0 of the word at r+0x4c
 (|= 1 then &= ~1). volatile: the fw reads and writes r+0x4c twice (a register pulse).
 Fix vs draft: real base ARR_a807db00 as a struct array (fw add then 'ld [rec+0x14]'; the draft's mid-record ARR_a807db14 gave [base+idx]). Aids: none.
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
struct tx { unsigned char pad0[0x14]; volatile unsigned char *regs; unsigned char pad18[0x34 - 0x18]; };
extern struct tx ARR_a807db00[];

void FUN_a009fe60(unsigned char port)
{
    volatile unsigned char *r = ARR_a807db00[port].regs;

    *(volatile unsigned int *)(r + 0x4c) |= 1;
    *(volatile unsigned int *)(r + 0x4c) &= ~1u;
}
