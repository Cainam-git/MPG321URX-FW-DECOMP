/* FUN_a008c9a8 (leon2s 0xa008c9a8-0xa008cba8, 512 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a008ae80(sel, c), FUN_a008aba8(sel, port), FUN_a008bddc(sel, port), clears DAT_a8078b30 and calls
 * FUN_a008c5d8(sel, port). sel 8 / 10: FUN_a00a67b8(0 / 1, 5, 2, 1) and (0 / 1, 5, 2, 0); sel 12 / 14:
 * FUN_a00a73ac(10, word 0 of ARR_a807db00[0 / 1] + 4), FUN_a00b160c(1), FUN_a00a73d4(10, same). Then
 * FUN_a008b32c(a, sel, c); sel 12 / 14: FUN_a008a110(sel, port, FUN_a00a29b0(0 / 1)); sel 4 / 6:
 * FUN_a008a1b4(sel, port, 1) and, when FUN_a0089f98(sel) is non-zero, FUN_a008ae18(0 / 1).
 * Source form: the final sel 4 and sel 6 tests are two separate ifs (the sel 4 call is then not a sibling
 * call).
 */
struct Port34 { unsigned int w0; unsigned char rest[0x34 - 4]; };
extern struct Port34 ARR_a807db00[];
extern unsigned char DAT_a8078b30;
extern void FUN_a008ae80(unsigned char, unsigned char);
extern void FUN_a008aba8(unsigned char, unsigned char);
extern void FUN_a008bddc(unsigned char, unsigned char);
extern void FUN_a008c5d8(unsigned char sel, unsigned char port);
extern void FUN_a00a67b8(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00a73ac(unsigned int, unsigned int);
extern void FUN_a00a73d4(unsigned int, unsigned int);
extern void FUN_a00b160c(unsigned int);
extern void FUN_a008b32c(unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a00a29b0(unsigned char port);
extern void FUN_a008a110(unsigned char sel, unsigned char port, unsigned char en);
extern void FUN_a008a1b4(unsigned char mode, unsigned char port, unsigned int val);
extern unsigned short FUN_a0089f98(unsigned char);
extern void FUN_a008ae18(unsigned char);

void FUN_a008c9a8(unsigned char sel, unsigned char a, unsigned char port, unsigned char c)
{
    FUN_a008ae80(sel, c);
    FUN_a008aba8(sel, port);
    FUN_a008bddc(sel, port);
    DAT_a8078b30 = 0;
    FUN_a008c5d8(sel, port);
    if (sel == 8) {
        FUN_a00a67b8(0, 5, 2, 1);
        FUN_a00a67b8(0, 5, 2, 0);
    } else if (sel == 10) {
        FUN_a00a67b8(1, 5, 2, 1);
        FUN_a00a67b8(1, 5, 2, 0);
    } else if (sel == 12) {
        FUN_a00a73ac(10, ARR_a807db00[0].w0 + 4);
        FUN_a00b160c(1);
        FUN_a00a73d4(10, ARR_a807db00[0].w0 + 4);
    } else if (sel == 14) {
        FUN_a00a73ac(10, ARR_a807db00[1].w0 + 4);
        FUN_a00b160c(1);
        FUN_a00a73d4(10, ARR_a807db00[1].w0 + 4);
    }
    FUN_a008b32c(a, sel, c);
    if (sel == 12)
        FUN_a008a110(12, port, FUN_a00a29b0(0));
    else if (sel == 14)
        FUN_a008a110(14, port, FUN_a00a29b0(1));
    else if (sel == 4)
        FUN_a008a1b4(4, port, 1);
    else if (sel == 6)
        FUN_a008a1b4(6, port, 1);
    if (sel == 4) {
        if (FUN_a0089f98(4))
            FUN_a008ae18(0);
    }
    if (sel == 6) {
        if (FUN_a0089f98(6))
            FUN_a008ae18(1);
    }
}
