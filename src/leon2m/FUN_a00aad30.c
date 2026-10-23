/* leon2m FUN_a00aad30 @ 0xa00aad30-0xa00aaf48 (134 words).
 * Returns 0 or 1 for item on the page byte 0xa802b08f (record DAT_a802d290). Page 0xc: 0 when item lies between
 * FUN_a00b6b88(4, 0) and FUN_a00b6b88(6, 0) and FUN_a00d7d48() is non-zero. Page 0xe: item 4 -> 0 when byte +0x1f
 * is set, (byte +0x1a4 == 3) when FUN_a0145660(0, 7) equals FUN_a014837c(0) and FUN_a014837c(1) is not above
 * FUN_a0145660(0, 8); item 3 -> 0 when byte +0x1f is set or bit 31 of word +0x1f4 is set; items 5 and 6 -> 0 when
 * byte +0x1f is set. Page 0xf, items 3..4 and page 0x10, items 5..6: 0 when bytes +0x1e and +0x20 are equal.
 * Every other case returns 1.
 * Source form: bit 31 of word +0x1f4 is a signed 1-bit bit-field (as in FUN_a0097508).
 */
struct R290 {
    unsigned char pad0[0x1e];
    unsigned char b1e;
    unsigned char b1f;
    unsigned char b20;
    unsigned char pad21[0x1a4 - 0x21];
    unsigned char b1a4;
    unsigned char pad1a5[0x1f4 - 0x1a5];
    union {
        unsigned int w;
        struct {
            signed int b31 : 1;
            unsigned int rest : 31;
        } f;
    } w1f4;
};
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08f;
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);
extern int FUN_a00d7d48(void);
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern unsigned short FUN_a014837c(int);

unsigned char FUN_a00aad30(unsigned char item)
{
    if (DAT_a802b08f == 0xc && FUN_a00b6b88(4, 0) <= item && item <= FUN_a00b6b88(6, 0) && FUN_a00d7d48() != 0)
        return 0;
    if (DAT_a802b08f == 0xe) {
        if (item == 4) {
            if (DAT_a802d290.b1f)
                return 0;
            if (FUN_a0145660(0, 7) == FUN_a014837c(0) && FUN_a0145660(0, 8) >= FUN_a014837c(1))
                return DAT_a802d290.b1a4 == 3;
        } else if (item == 3) {
            if (DAT_a802d290.b1f)
                return 0;
            if (DAT_a802d290.w1f4.f.b31)
                return 0;
        } else if (item == 5) {
            if (DAT_a802d290.b1f)
                return 0;
        } else if (item == 6) {
            if (DAT_a802d290.b1f)
                return 0;
        }
    }
    if (DAT_a802b08f == 0xf && (unsigned char)(item - 3) <= 1 && DAT_a802d290.b1e == DAT_a802d290.b20)
        return 0;
    if (DAT_a802b08f == 0x10 && (unsigned char)(item - 5) <= 1 && DAT_a802d290.b1e == DAT_a802d290.b20)
        return 0;
    return 1;
}
