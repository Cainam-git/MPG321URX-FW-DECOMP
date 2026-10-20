/* FUN_a00cf980 (leon2s, 0xa00cf980-0xa00cf9e8, 26 words incl. the shared nop/ret/restore tail). Flags -mcpu=v8 -Os -g.
 Code facts: void (u8 port). Word 0 of the 24-byte record port of DAT_a8078bb0: bits 16..17 set to 01 (andn 0x30000, or 0x10000).
 r1 = (u8)FUN_a00c9368(port); if r1 != (u8)FUN_a00c972c(): tail call FUN_a00cca38(r1).
 Fixes vs draft: FUN_a00c9368 takes the port argument (fw computes 'and %i0,0xff,%o0' straight into %o0 and keeps it there to the call;
 without it the port sits in %i0); void (the draft returned values). Aids: none.
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

extern unsigned int DAT_a8078bb0[];
extern unsigned int FUN_a00c9368(unsigned char);
extern unsigned int FUN_a00c972c(void);
extern void FUN_a00cca38(unsigned int);

void FUN_a00cf980(unsigned char port)
{
    unsigned int base = port * 6;
    unsigned char r1;

    DAT_a8078bb0[base] = (DAT_a8078bb0[base] & ~0x30000) | 0x10000;
    r1 = FUN_a00c9368(port);
    if (r1 != (unsigned char)FUN_a00c972c())
        FUN_a00cca38(r1);
}
