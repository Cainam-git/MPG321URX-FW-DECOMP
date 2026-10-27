/* leon2m FUN_a00aa520 @ 0xa00aa520-0xa00aa83c (796 bytes), flags -mcpu=v8 -O3 -g.
 * Returns 0 or 1 for index sel, depending on the byte DAT_a802b08f (m) and fields of the record DAT_a802d290
 * (A = (byte +0x181 - 4) as a byte <= 2 and word +0xa8 bit 11 set):
 *   m 0:      0 when FUN_a00d7d48() != 0 and sel == 2.
 *   m 1:      0 when FUN_a00d7d48() != 0 and sel is 1 or 2; when word +0x174 bit 15 is set and sel == 1; when
 *             byte +0x1f != 0 and sel == 6.
 *   m 2, 12:  for sel == 1: 0 when FUN_a00d7d48() != 0 or A.
 *   m 3:      0 for sel == 0 when word +0x11c bit 31 is set, or word +0xb0 != 0 and FUN_a00d8bd8() != 0, or
 *             FUN_a00d7d48() != 0; for sel 1 or 3 when A; for sel 1 when byte +0x178 != 0; for sel 1 or 3 when
 *             FUN_a00d7d48() != 0; for sel 4 when byte +0x1f == 2; for sel 5 when byte +0x1f != 0.
 *   m 7:      0 for sel 6 when byte +0x1f != 0; for sel 7 when word +0xb0 != 0 and FUN_a00d8bd8() != 0.
 * All other cases return 1. Called by FUN_a00aa83c, FUN_a0091668, FUN_a0091784, FUN_a00b0034 and about 40 others.
 * Source form: old-style (K&R) definition of the byte parameter (zero-extended at each use); m tested with an
 * if/else-if chain; the bit 31 test as w >> 31 on an unsigned word; the tests that stay branches in the
 * firmware (byte +0x178 / sel 1, byte +0x1f == 2 / sel 4, m 7) are nested ifs, the others && conditions.
 */
struct R290 {
    unsigned char p00[0x1f];
    unsigned char b1f;
    unsigned char p20[0xa8 - 0x20];
    unsigned int wa8;
    unsigned char pac[0xb0 - 0xac];
    unsigned int wb0;
    unsigned char pb4[0x11c - 0xb4];
    unsigned int w11c;
    unsigned char p120[0x174 - 0x120];
    unsigned int w174;
    unsigned char b178;
    unsigned char p179[0x181 - 0x179];
    unsigned char b181;
};
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08f;
extern int FUN_a00d7d48(void);
extern unsigned char FUN_a00d8bd8(void);

unsigned char FUN_a00aa520(sel)
unsigned char sel;
{
    if (DAT_a802b08f == 0) {
        if (FUN_a00d7d48() && sel == 2)
            return 0;
    } else if (DAT_a802b08f == 1) {
        if (FUN_a00d7d48() && (sel == 1 || sel == 2))
            return 0;
        if ((DAT_a802d290.w174 & 0x8000) && sel == 1)
            return 0;
        if (DAT_a802d290.b1f && sel == 6)
            return 0;
    } else if (DAT_a802b08f == 2 || DAT_a802b08f == 12) {
        if (sel == 1) {
            if (FUN_a00d7d48())
                return 0;
            if ((unsigned char)(DAT_a802d290.b181 - 4) <= 2 && (DAT_a802d290.wa8 & 0x800))
                return 0;
        }
    } else if (DAT_a802b08f == 3) {
        if ((DAT_a802d290.w11c >> 31 || (DAT_a802d290.wb0 != 0 && FUN_a00d8bd8()) || FUN_a00d7d48()) && sel == 0)
            return 0;
        if ((unsigned char)(DAT_a802d290.b181 - 4) <= 2 && (DAT_a802d290.wa8 & 0x800) && (sel == 1 || sel == 3))
            return 0;
        if (DAT_a802d290.b178)
            if (sel == 1)
                return 0;
        if (FUN_a00d7d48() && (sel == 1 || sel == 3))
            return 0;
        if (DAT_a802d290.b1f == 2)
            if (sel == 4)
                return 0;
        if (DAT_a802d290.b1f && sel == 5)
            return 0;
    } else if (DAT_a802b08f == 6) {
    } else if (DAT_a802b08f == 7) {
        if (DAT_a802d290.b1f)
            if (sel == 6)
                return 0;
        if (DAT_a802d290.wb0 == 0)
            return 1;
        if (!FUN_a00d8bd8())
            return 1;
        if (sel == 7)
            return 0;
    }
    return 1;
}
