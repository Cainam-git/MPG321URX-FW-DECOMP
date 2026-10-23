/* leon2m FUN_a00ad970 @ 0xa00ad970-0xa00adaf4 (97 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * FUN_a0146b6c(2, 0), FUN_a0146b50(0x6f, 0), func_0x4008e2a4(); for i = 4..11: FUN_a0146b20(0, 3, i, 0x10, 0, 0)
 * and FUN_a0146a80(3, i, 0x10, 0x792, 0). mode 0: for i = 0..3 passes entry i * 29 + byte DAT_a802d290+8 of the
 * table DAT_001890d4 (FUN_a00a3844) to FUN_a00a31a4(0, 6, i * 2 + 5, 0xa, entry, 0); other modes pass entry
 * byte + 0x74 with row 5. When byte 0xa8025c56 >> 2 equals mode: FUN_a00ad86c(byte & 3, 0) and
 * FUN_a00b3614(byte & 3, 1) (tail call); otherwise FUN_a0146c40(4, 0, 0) (tail call).
 * Source form: the second loop has its own counter j; the mode != 0 arm comes first.
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
};
extern struct St DAT_a802d290;
extern unsigned int DAT_001890d4[];
extern unsigned char DAT_a8025c56;
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void func_0x4008e2a4(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned short, int, unsigned int, int);
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a00b3614(unsigned char, unsigned char);
extern void FUN_a0146c40(int, int, int);

void FUN_a00ad970(unsigned char mode)
{
    unsigned char i, j;

    FUN_a0146b6c(2, 0);
    FUN_a0146b50(0x6f, 0);
    func_0x4008e2a4();
    for (i = 4; i <= 0xb; i++) {
        FUN_a0146b20(0, 3, i, 0x10, 0, 0);
        FUN_a0146a80(3, i, 0x10, 0x792, 0);
    }
    if (mode != 0) {
        FUN_a00a31a4(0, 6, 5, 0xa, FUN_a00a3844(DAT_001890d4, DAT_a802d290.b08 + 0x74), 0);
    } else {
        for (j = 0; j <= 3; j++)
            FUN_a00a31a4(0, 6, j * 2 + 5, 0xa, FUN_a00a3844(DAT_001890d4, j * 29 + DAT_a802d290.b08), 0);
    }
    if (mode == DAT_a8025c56 >> 2) {
        FUN_a00ad86c(DAT_a8025c56 & 3, 0);
        FUN_a00b3614(DAT_a8025c56 & 3, 1);
    } else {
        FUN_a0146c40(4, 0, 0);
    }
}
