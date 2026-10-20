/*
 * FUN_a00a4e68 (leon2s, 0xa00a4e68-0xa00a4ec4, 92 bytes), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/23.
 * Code facts: init of the 12-byte record table at 0xa807dc04 (same base as FUN_a00a60d8): for a u8
 * counter over ONE record (fw loop test 'btst 0xff' after inc = i < 1), word 0 = i + 0xc0100000,
 * word 1 = i + 0xc0100400, word 2 = i + 0xc0100800 (register block bases). -Os emits the last
 * source store (+8) first, then +0, +4 (fw order). void (the fw base sits in %i0 only by allocation).
 * Aids: none.
 */
struct rec12 { unsigned int a; unsigned int b; unsigned int c; };
extern struct rec12 DAT_a807dc04[];

void FUN_a00a4e68(void)
{
    unsigned char i;

    for (i = 0; i < 1; i++) {
        DAT_a807dc04[i].a = i + 0xc0100000;
        DAT_a807dc04[i].b = i + 0xc0100400;
        DAT_a807dc04[i].c = i + 0xc0100800;
    }
}
