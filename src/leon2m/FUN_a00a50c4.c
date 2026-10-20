/* leon2m FUN_a00a50c4 @ 0xa00a50c4-0xa00a5218 (85 words).
 * When byte 0xa802d2da (offset 0x4a of the block at 0xa802d290) is 1, it is cleared, FUN_a00d5eac(0) is called and
 * v = the byte (0). Then FUN_a0146a80(5, 8, 4, 0x792, 0), four calls FUN_a0146b20(0, i + 9, 8, 1, c, 0) for i = 0..3
 * with c = i + 0x1e when v is set and i + 0x22 otherwise, and FUN_a0146a80(3, 8, 5, p, 0), FUN_a0146a80(0xe, 8, 5, q,
 * 0) with (p, q) = (0x992, 0x792) when v is set and (0x792, 0x992) otherwise. In every case bit 1 of byte 0xa802b08e
 * is set at the end. Same code as FUN_a00a4cac with a byte instead of a bit.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00d5eac(int);

void FUN_a00a50c4(void)
{
    unsigned char v, i;

    if (DAT_a802d290[0x4a] == 1) {
        DAT_a802d290[0x4a] = 0;
        FUN_a00d5eac(0);
        v = DAT_a802d290[0x4a];
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
