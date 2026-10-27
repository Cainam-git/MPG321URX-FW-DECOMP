/* leon2m FUN_a014f6f4 @ 0xa014f6f4-0xa014f888 (404 bytes), flags -mcpu=v8 -O3 -g.
 * Builds a 3-byte local record s (bit-fields, first field = most significant bit): byte 0 bits 7..1 = 0 and
 * bit 0 = 1, byte 2 = 1, byte 1 bits 7..6 = 0 (bits 5..0 of byte 1 are not written). Then tests the record:
 * byte 0 bit 7 -> FUN_a00fe880(0xc, m, 0xb) for m = 1, 2, 4, 8; bit 6 -> FUN_a014f620(0); bit 5 ->
 * FUN_a014f620(1); bit 2 -> FUN_a00fe880(0xe, 4, 0xe); bit 1 -> FUN_a00fe880(0xe, 8, 0xe). Finally copies the
 * record into a second local and passes its address to FUN_a0138564. Called by FUN_a015209c.
 * Source form: unsigned char bit-fields (GCC accesses them with word loads and stores on the aligned stack slot;
 * the tests extract byte 0 with srl 24); each test reads the record again; the copy is a structure assignment
 * (lduh + ldub of the 3 bytes).
 */
struct Bits {
    unsigned char a7 : 1, a6 : 1, a5 : 1, a4 : 1, a3 : 1, a2 : 1, a1 : 1, a0 : 1;
    unsigned char b76 : 2, b50 : 6;
    unsigned char c;
};
extern void FUN_a00fe880(unsigned char, unsigned char, unsigned char);
extern void FUN_a014f620(unsigned char);
extern void FUN_a0138564(unsigned char *p);

void FUN_a014f6f4(void)
{
    struct Bits s;
    struct Bits m;

    s.a7 = 0;
    s.a6 = 0;
    s.a5 = 0;
    s.a4 = 0;
    s.a3 = 0;
    s.a2 = 0;
    s.a1 = 0;
    s.a0 = 1;
    s.c = 1;
    s.b76 = 0;
    if (s.a7) {
        FUN_a00fe880(0xc, 1, 0xb);
        FUN_a00fe880(0xc, 2, 0xb);
        FUN_a00fe880(0xc, 4, 0xb);
        FUN_a00fe880(0xc, 8, 0xb);
    }
    if (s.a6)
        FUN_a014f620(0);
    if (s.a5)
        FUN_a014f620(1);
    if (s.a2)
        FUN_a00fe880(0xe, 4, 0xe);
    if (s.a1)
        FUN_a00fe880(0xe, 8, 0xe);
    m = s;
    FUN_a0138564((unsigned char *)&m);
}
