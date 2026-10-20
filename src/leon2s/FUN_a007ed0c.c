/* FUN_a007ed0c (leon2s 0xa007ed0c-0xa007ed88, 124 bytes), flags -mcpu=v8 -Os -g.
 * When FUN_a0073520(port) returns 0, tail-calls FUN_a00a67b8(port, 0x2f6, 2, on). Otherwise uses record
 * (port != 2) of ARR_a807db00 (0x34 bytes each) and sets (on non-zero, FUN_a00a73ac) or clears (FUN_a00a73d4)
 * bit 0x11 of the bitmap at record word 3 (offset 0xc) + 0x74.
 * Source forms: on is a raw word parameter tested and passed as a byte (fw: separate 'and 0xff' for the call and
 * 'btst 0xff' for the test); the record index is a byte local (gives the smul).
 */
extern unsigned char FUN_a0073520(unsigned char);
extern void FUN_a00a67b8(unsigned char, unsigned short, unsigned int, unsigned char);
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00a73d4(unsigned int, int);
struct Port34 { unsigned int w0, w1, w2, w3; unsigned char rest[0x34 - 16]; };
extern struct Port34 ARR_a807db00[];

void FUN_a007ed0c(unsigned char port, unsigned int on)
{
    if (FUN_a0073520(port) != 0) {
        unsigned char ch = port != 2;
        if ((unsigned char)on != 0)
            FUN_a00a73ac(0x11, ARR_a807db00[ch].w3 + 0x74);
        else
            FUN_a00a73d4(0x11, ARR_a807db00[ch].w3 + 0x74);
    } else {
        FUN_a00a67b8(port, 0x2f6, 2, on);
    }
}
