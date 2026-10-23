/* leon2m FUN_a00b8ca8 @ 0xa00b8ca8-0xa00b8e7c (117 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * FUN_a0146b6c(2, 0), FUN_a0146b50(0x6f, 0), FUN_a00a7c88(). mode non-zero: for i = 4..5 passes entry
 * i * 29 + byte DAT_a802d290+8 of the table DAT_00195f24 (FUN_a00a3844) to FUN_a00a31a4(0, 6, i * 2 - 3, 0xa,
 * entry, 0); mode 0: the same for i = 0..3 with row i * 2 + 5. When byte 0xa8025c56 >> 2 equals mode:
 * FUN_a00ad86c(byte & 3, 0), then with k = byte & 3 (minus 4 when above 3) FUN_a0146b20(0, j + 4, k * 2 + 5, 1,
 * j + 0x1c, 0) for j = 0, 1; otherwise FUN_a0146c40(4, 0, 0) (tail call).
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
};
extern struct St DAT_a802d290;
extern unsigned int DAT_00195f24[];
extern unsigned char DAT_a8025c56;
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a7c88(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned short, int, unsigned int, int);
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a0146c40(int, int, int);

void FUN_a00b8ca8(unsigned char mode)
{
    unsigned char i, k;

    FUN_a0146b6c(2, 0);
    FUN_a0146b50(0x6f, 0);
    FUN_a00a7c88();
    if (mode != 0) {
        for (i = 4; i <= 5; i++)
            FUN_a00a31a4(0, 6, i * 2 - 3, 0xa, FUN_a00a3844(DAT_00195f24, i * 29 + DAT_a802d290.b08), 0);
    } else {
        for (i = 0; i <= 3; i++)
            FUN_a00a31a4(0, 6, i * 2 + 5, 0xa, FUN_a00a3844(DAT_00195f24, i * 29 + DAT_a802d290.b08), 0);
    }
    if (mode == DAT_a8025c56 >> 2) {
        FUN_a00ad86c(DAT_a8025c56 & 3, 0);
        k = DAT_a8025c56 & 3;
        if (k > 3)
            k -= 4;
        for (i = 0; i <= 1; i++)
            FUN_a0146b20(0, i + 4, k * 2 + 5, 1, i + 0x1c, 0);
    } else {
        FUN_a0146c40(4, 0, 0);
    }
}
