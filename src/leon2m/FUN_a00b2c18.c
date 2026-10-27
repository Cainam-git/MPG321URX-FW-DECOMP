/* FUN_a00b2c18 (leon2m 0xa00b2c18-0xa00b2d04, 236 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns at once when the halfword DAT_a802cff4 + 0x12 is 5 and bit 30 of the word DAT_a802d290 + 0x1dc is set,
 * when the halfword DAT_a802cff4 + 0x10 is 4 and that word is negative, or when the byte DAT_a802d290 + 0x1e4 or +
 * 0x1e5 is 1; otherwise toggles bit 15 of the halfword DAT_a802cff4 + 0xe and calls FUN_a00b0710(1, 1) when it is
 * now set, FUN_a00b0710(1, 0) when clear, as a tail call. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a00b2a1c and FUN_a00b2d04. Source form: bit 15 is a
 * one-bit bit-field set to (unsigned char)(1 - bit); the sign test is written (w >> 31) on the int word (arithmetic
 * shift), which gives the firmware block order.
 */
struct F0e { unsigned short b15:1, rest:15; };
struct Cff4 { unsigned char p0[0xe]; struct F0e f0e; unsigned short h10, h12; };
struct G290 { unsigned char p0[0x1dc]; int w1dc; unsigned char p1e0[4]; unsigned char b1e4, b1e5; };
extern struct Cff4 DAT_a802cff4;
extern struct G290 DAT_a802d290;
extern void FUN_a00b0710(unsigned char, unsigned char);

void FUN_a00b2c18(void)
{
    if (DAT_a802cff4.h12 == 5 && (DAT_a802d290.w1dc & 0x40000000))
        return;
    if (DAT_a802cff4.h10 == 4 && (DAT_a802d290.w1dc >> 31))
        return;
    if (DAT_a802d290.b1e4 == 1 || DAT_a802d290.b1e5 == 1)
        return;
    DAT_a802cff4.f0e.b15 = (unsigned char)(1 - DAT_a802cff4.f0e.b15);
    if (DAT_a802cff4.f0e.b15)
        FUN_a00b0710(1, 1);
    else
        FUN_a00b0710(1, 0);
}
