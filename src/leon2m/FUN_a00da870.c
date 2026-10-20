/* leon2m FUN_a00da870 @ 0xa00da870, flags -mcpu=v8 -O3 -g.
 * Picks a status code for port 'p' (0 or not 0) from the 0xA802D290 record and the 0xA802CFF4 record, stores it in
 * byte 0xA802D00D (0xA802CFF4 + 0x19) and returns it:
 *   p == 0: +0x1E4 set -> 5; else v = +0x1E2: v == cff4.h010 and +0x1E6 == 1 -> 9 when (v != 0 ? v - 1 : 0) > 2,
 *     else 7; otherwise 1 (v <= 2) / 3.
 *   p != 0: +0x1E5 set -> 6; else v = +0x1E3: v == cff4.h012 and +0x1E7 == 1 -> 8 (v <= 2) / 10; otherwise 2 / 4.
 * Caller: FUN_a009f184.
 * Source form: v is read before the +0x1E4 / +0x1E5 test; the 'v <= 2' tests come first (the smaller code is the
 *   fall-through); v is decremented only when non-zero. The firmware has the 'ldub v' in the branch delay slot,
 *   before 'sethi &cff4', the same pattern as in FUN_a0106d64 / FUN_a0105150.
 * Compiler aids: none.
 */
struct G290 { unsigned char p000[0x1e2]; unsigned char b1e2, b1e3, b1e4, b1e5, b1e6, b1e7; };
struct Scff4 { unsigned char p00[0x10]; unsigned short h010, h012; unsigned char p14[5]; unsigned char b19; };
extern struct G290 DAT_a802d290;
extern struct Scff4 DAT_a802cff4;

unsigned char FUN_a00da870(unsigned char p)
{
    unsigned char v;
    if (p == 0) {
        v = DAT_a802d290.b1e2;
        if (DAT_a802d290.b1e4 != 0) { DAT_a802cff4.b19 = 5; return 5; }
        if (v == DAT_a802cff4.h010 && DAT_a802d290.b1e6 == 1) {
            if (v != 0) v--;
            if (v <= 2) { DAT_a802cff4.b19 = 7; return 7; }
            DAT_a802cff4.b19 = 9; return 9;
        }
        if (v <= 2) { DAT_a802cff4.b19 = 1; return 1; }
        DAT_a802cff4.b19 = 3; return 3;
    }
    v = DAT_a802d290.b1e3;
    if (DAT_a802d290.b1e5 != 0) { DAT_a802cff4.b19 = 6; return 6; }
    if (v == DAT_a802cff4.h012 && DAT_a802d290.b1e7 == 1) {
        if (v <= 2) { DAT_a802cff4.b19 = 8; return 8; }
        DAT_a802cff4.b19 = 10; return 10;
    }
    if (v <= 2) { DAT_a802cff4.b19 = 2; return 2; }
    DAT_a802cff4.b19 = 4; return 4;
}
