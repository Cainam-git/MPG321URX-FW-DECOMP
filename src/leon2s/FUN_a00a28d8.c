/* FUN_a00a28d8 (leon2s, 0xa00a28d8-0xa00a2928, 20 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void, 6 params (only p3..p6 used). FUN_a00638cc(); FUN_a00a69fc(0, 0x9c8, 1); if DAT_a807d7e1 != 0: tail call
 FUN_a00a0c84(0, 0, p3, p4, p5, p6); else FUN_a00a0bfc(0) and tail call FUN_a00a0b10(0, 0).
 Fixes vs draft: BEHAVIOUR the else path also tail-calls FUN_a00a0b10(0, 0) (the draft returned bfc's value); void; the != 0 arm is first in
 the source (fw falls through into the c84 sibcall). Aids: none.
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
extern unsigned char DAT_a807d7e1;
extern void FUN_a00638cc(void);
extern void FUN_a00a0b10(unsigned int, unsigned int);
extern unsigned char FUN_a00a0bfc(unsigned int);
extern void FUN_a00a0c84(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00a69fc(unsigned int, unsigned int, unsigned int);

void FUN_a00a28d8(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4,
                  unsigned int param_5, unsigned int param_6)
{
    FUN_a00638cc();
    FUN_a00a69fc(0, 0x9c8, 1);
    if (DAT_a807d7e1 != 0) {
        FUN_a00a0c84(0, 0, param_3, param_4, param_5, param_6);
        return;
    }
    FUN_a00a0bfc(0);
    FUN_a00a0b10(0, 0);
}
