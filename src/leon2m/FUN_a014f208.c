/* leon2m FUN_a014f208 @ 0xa014f208-0xa014f32c (73 words).
 * For each nibble n = (DAT_a802cc80 >> 4i) & 0xf, i = 0..3: when none of the 9 bytes DAT_a802a480[0..8] equals n,
 * nibble i of DAT_a802cc80 is cleared and the first nibble k of DAT_a802cc82 (k = 0..3) equal to n is handled:
 * DAT_a802cc82 = (((int)(DAT_a802cc82 << (16 - 4k))) >> (16 - 4k)) | ((DAT_a802cc82 >> (4k + 4)) << 4k), stored as
 * 16 bits (the first term keeps the whole halfword). No direct callers (reached through a pointer).
 * Source form: the byte search and the DAT_a802cc82 update are inlined static helpers; the update works on the
 * global itself (GCC keeps it in a register and stores it at both loop exits); the table byte is copied into a
 * local before the compare 'n == d' (operand order of the cmp). Flags include -msoft-float (it keeps the 0xf
 * mask constant out of the loop preheader as in the firmware).
 */
extern unsigned short DAT_a802cc80;
extern unsigned short DAT_a802cc82;
extern unsigned char DAT_a802a480[9];

static unsigned short find(unsigned char n)
{
    unsigned char j, d;
    unsigned short mask = 0;

    for (j = 0; j < 9; j++) {
        d = DAT_a802a480[j];
        if (n == d)
            mask |= 1 << j;
    }
    return mask;
}

static void drop(unsigned char n)
{
    unsigned char k;

    for (k = 0; k < 4; k++) {
        if (((DAT_a802cc82 >> (k * 4)) & 0xf) == n) {
            DAT_a802cc82 = ((int)((unsigned int)DAT_a802cc82 << (16 - k * 4)) >> (16 - k * 4)) |
                           ((DAT_a802cc82 >> (k * 4 + 4)) << (k * 4));
            break;
        }
    }
}

void FUN_a014f208(void)
{
    unsigned char i;
    unsigned char n;

    for (i = 0; i < 4; i++) {
        n = (DAT_a802cc80 >> (i * 4)) & 0xf;
        if (find(n) == 0) {
            DAT_a802cc80 &= ~(0xf << (i * 4));
            drop(n);
        }
    }
}
