/* leon2m FUN_a0080af0 @ 0xa0080af0-0xa0080bc0 (52 words).
 * Prints the string at 0xfeda0 with FUN_a00df170. For mode 0: FUN_a00da4b8(); when FUN_a00d7d48() returns nonzero
 * and bit 7 of halfword 0xa802cffe is clear, bit 11 of word 0xa802d338 takes the value of its bit 8 and bytes
 * 0xa802d411/0xa802d412 take bytes 0xa802d417/0xa802d418. Then, when byte 0xa802d444 differs from byte 0xa802af40,
 * FUN_a00db738 (bit 11 of 0xa802d338 set) or FUN_a00dbcf0 (clear) is called. Always ends with a tail call of
 * FUN_a00d8ffc.
 */
struct R290 {
    unsigned char p000[0xa8];
    unsigned int w0a8;
    unsigned char p0ac[0xd5];
    unsigned char b181, b182;
    unsigned char p183[4];
    unsigned char b187, b188;
    unsigned char p189[0x2b];
    unsigned char b1b4;
};
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802af40;
extern unsigned short DAT_a802cffe;
extern const char s_000feda0[];
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00da4b8(void);
extern int FUN_a00d7d48(void);
extern void FUN_a00db738(void);
extern void FUN_a00dbcf0(void);
extern void FUN_a00d8ffc(void);

void FUN_a0080af0(unsigned char mode)
{
    FUN_a00df170(s_000feda0);
    if (mode == 0) {
        FUN_a00da4b8();
        if (FUN_a00d7d48() && !(DAT_a802cffe & 0x80)) {
            DAT_a802d290.w0a8 = (DAT_a802d290.w0a8 & ~0x800) | ((DAT_a802d290.w0a8 << 3) & 0x800);
            DAT_a802d290.b182 = DAT_a802d290.b188;
            DAT_a802d290.b181 = DAT_a802d290.b187;
        }
        if (DAT_a802d290.b1b4 != DAT_a802af40) {
            if (!(DAT_a802d290.w0a8 & 0x800))
                FUN_a00dbcf0();
            else
                FUN_a00db738();
        }
    }
    FUN_a00d8ffc();
}
