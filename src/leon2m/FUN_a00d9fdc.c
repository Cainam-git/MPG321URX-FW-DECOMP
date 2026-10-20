/* leon2m FUN_a00d9fdc @ 0xa00d9fdc-0xa00da184 (106 words).
 * sel 0: FUN_a00d99f8(0, 1), FUN_a014a8d4(4, 1, 1000), FUN_a0148268(0, 1), FUN_a0148268(1, 1),
 * FUN_a0151aa4(0xf, 1). sel 1: upd(). Other sel: the same sequence with FUN_a00d99f8(2, 1), then upd().
 * upd(): when bit 31 of the word at 0xa802d484 is set and FUN_a014a6e0(0xc) or FUN_a014a6e0(0xd) returns 0,
 * FUN_a014a654(0xc, 1) and FUN_a014a654(0xd, 1); when it is clear and FUN_a014a6e0(0xc) or
 * FUN_a014a6e0(0xd) returns 1, FUN_a014a654(0xc, 0) and FUN_a014a654(0xd, 0). upd() is a static helper (inlined
 * twice). The sign of the word at 0xa802d484 is read as a signed 1-bit bit-field: a plain int compared with 0
 * gives the same test but the opposite block placement.
 */
struct W484 {
    int top : 1;
    unsigned int rest : 31;
};
extern struct W484 DAT_a802d484;
extern void FUN_a00d99f8(int, int);
extern void FUN_a014a8d4(int, int, int);
extern void FUN_a0148268(int, int);
extern void FUN_a0151aa4(unsigned int, unsigned int);
extern unsigned char FUN_a014a6e0(unsigned char p);
extern void FUN_a014a654(unsigned char p, unsigned char q);

static void upd(void)
{
    if (DAT_a802d484.top) {
        if (!FUN_a014a6e0(0xc) || !FUN_a014a6e0(0xd)) {
            FUN_a014a654(0xc, 1);
            FUN_a014a654(0xd, 1);
        }
    } else {
        if (FUN_a014a6e0(0xc) == 1 || FUN_a014a6e0(0xd) == 1) {
            FUN_a014a654(0xc, 0);
            FUN_a014a654(0xd, 0);
        }
    }
}

void FUN_a00d9fdc(unsigned char sel)
{
    if (sel == 0) {
        FUN_a00d99f8(0, 1);
        FUN_a014a8d4(4, 1, 1000);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a0151aa4(0xf, 1);
    } else if (sel == 1) {
        upd();
    } else {
        FUN_a00d99f8(2, 1);
        FUN_a014a8d4(4, 1, 1000);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a0151aa4(0xf, 1);
        upd();
    }
}
