/* leon2m FUN_a00a4f68 @ 0xa00a4f68-0xa00a50c4 (87 words).
 * When bit 22 of word 0xa802d33c (offset 0xac of the block at 0xa802d290) is clear, it is set and v = the new bit
 * (1). Then FUN_a0146a80(5, 8, 4, 0x792, 0), four calls FUN_a0146b20(0, i + 9, 8, 1, c, 0) for i = 0..3 with c = i +
 * 0x1e when v is set and i + 0x22 otherwise, and FUN_a0146a80(3, 8, 5, p, 0), FUN_a0146a80(0xe, 8, 5, q, 0) with (p,
 * q) = (0x992, 0x792) when v is set and (0x792, 0x992) otherwise. In every case bit 1 of byte 0xa802b08e is set at
 * the end. The opposite of FUN_a00a4b4c. Source form: the word is a union of a plain word (tested with the mask
 * 0x400000) and a bit-field view (cleared and read as a 1-bit field); the arms test !v first.
 */
struct G290 {
    unsigned char pad0[0xac];
    union {
        unsigned int w;         /* 0xa802d33c */
        struct {
            unsigned int hi9 : 9;
            unsigned int b22 : 1;
            unsigned int lo22 : 22;
        } f;
    } u0a8;
};
extern struct G290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00a4f68(void)
{
    unsigned char v, i;

    if (!(DAT_a802d290.u0a8.w & 0x400000)) {
        DAT_a802d290.u0a8.f.b22 = 1;
        v = DAT_a802d290.u0a8.f.b22;
        FUN_a0146a80(5, 8, 4, 0x792, 0);
        for (i = 0; i <= 3; i++) {
            if (!v)
                FUN_a0146b20(0, i + 9, 8, 1, i + 0x22, 0);
            else
                FUN_a0146b20(0, i + 9, 8, 1, i + 0x1e, 0);
        }
        if (!v) {
            FUN_a0146a80(3, 8, 5, 0x792, 0);
            FUN_a0146a80(0xe, 8, 5, 0x992, 0);
        } else {
            FUN_a0146a80(3, 8, 5, 0x992, 0);
            FUN_a0146a80(0xe, 8, 5, 0x792, 0);
        }
    }
    DAT_a802b08e |= 2;
}
