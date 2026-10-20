/* leon2m FUN_a008e650 @ 0xa008e650-0xa008e7a8 (86 words).
 * k = FUN_a012621c(). For nonzero k: byte 0xa802cffa = the second byte of the first of the six 2-byte entries at
 * 0x10053f whose first byte shares a bit with k (0 when none). When halfword 0xa802d486 is 0x55aa, byte 0xa802d284
 * has none of those bits and byte 0xa802d465 is 0, the bits are added to 0xa802d284 and FUN_a014aed0(0x30,
 * 0xa802d274, 0x2e0, 0x1c) is called. Then, when bit 11 of halfword 0xa802cff4 is set, bit 14 of word 0xa802d290 is
 * set for k 2 and cleared otherwise; bit 11 of 0xa802cff4 is cleared.
 */
struct Ent { unsigned char mask, val; };
struct R290 { unsigned int w000; unsigned char p004[0x1d1]; unsigned char b1d5; unsigned char p1d6[0x20];
              unsigned short h1f6; };
struct F4 { unsigned short h0; unsigned char p2[4]; unsigned char b6; };
extern const struct Ent DAT_0010053f[6];
extern struct R290 DAT_a802d290;
extern struct F4 DAT_a802cff4;
extern unsigned char DAT_a802d274[];
extern unsigned char FUN_a012621c(void);
extern int FUN_a014aed0(unsigned char, void *, unsigned short, unsigned short);

void FUN_a008e650(void)
{
    unsigned char k, i, v = 0;

    k = FUN_a012621c();
    if (k != 0) {
        for (i = 0; i < 6; i++) {
            if (DAT_0010053f[i].mask & k) {
                v = DAT_0010053f[i].val;
                break;
            }
        }
        DAT_a802cff4.b6 = v;
        if (DAT_a802d290.h1f6 == 0x55aa && !(DAT_a802d274[0x10] & DAT_a802cff4.b6) && DAT_a802d290.b1d5 == 0) {
            DAT_a802d274[0x10] |= DAT_a802cff4.b6;
            FUN_a014aed0(0x30, DAT_a802d274, 0x2e0, 0x1c);
        }
    }
    if (DAT_a802cff4.h0 & 0x800) {
        if (k == 2)
            DAT_a802d290.w000 |= 0x4000;
        else
            DAT_a802d290.w000 &= ~0x4000;
    }
    DAT_a802cff4.h0 &= ~0x800;
}
