/* leon2m FUN_a00f9d78 @ 0xa00f9d78-0xa00f9f10 (102 words).
 * Reads bits 12..15 of the hardware register 0xd0040098. For value 3 it copies from the table at 0xa8026ed6, for
 * value 4 from the table at 0xa8026cb6 (16 rows of 17 halfwords); any other value changes nothing. The entries
 * t[r][2], t[r][5], t[r][8], t[r][11], t[r][14] of rows r = 0, 5, 10, 15 go to entries 0..4 of the halfword rows
 * 12..15 of 0xa802c864 (stride 8 halfwords). Returns 1. Counterpart of FUN_a00f9f10, which copies the other way.
 */
extern unsigned short DAT_a802c864[][8];
extern unsigned short DAT_a8026cb6[16][17];
extern unsigned short DAT_a8026ed6[16][17];
#define REG_D0040098 (*(volatile unsigned int *)0xd0040098)

int FUN_a00f9d78(void)
{
    unsigned int mode = (unsigned short)REG_D0040098 >> 12;

    if (mode == 3) {
        DAT_a802c864[12][0] = DAT_a8026ed6[0][2];
        DAT_a802c864[12][1] = DAT_a8026ed6[0][5];
        DAT_a802c864[12][2] = DAT_a8026ed6[0][8];
        DAT_a802c864[12][3] = DAT_a8026ed6[0][11];
        DAT_a802c864[12][4] = DAT_a8026ed6[0][14];
        DAT_a802c864[13][0] = DAT_a8026ed6[5][2];
        DAT_a802c864[13][1] = DAT_a8026ed6[5][5];
        DAT_a802c864[13][2] = DAT_a8026ed6[5][8];
        DAT_a802c864[13][3] = DAT_a8026ed6[5][11];
        DAT_a802c864[13][4] = DAT_a8026ed6[5][14];
        DAT_a802c864[14][0] = DAT_a8026ed6[10][2];
        DAT_a802c864[14][1] = DAT_a8026ed6[10][5];
        DAT_a802c864[14][2] = DAT_a8026ed6[10][8];
        DAT_a802c864[14][3] = DAT_a8026ed6[10][11];
        DAT_a802c864[14][4] = DAT_a8026ed6[10][14];
        DAT_a802c864[15][0] = DAT_a8026ed6[15][2];
        DAT_a802c864[15][1] = DAT_a8026ed6[15][5];
        DAT_a802c864[15][2] = DAT_a8026ed6[15][8];
        DAT_a802c864[15][3] = DAT_a8026ed6[15][11];
        DAT_a802c864[15][4] = DAT_a8026ed6[15][14];
    } else if (mode == 4) {
        DAT_a802c864[12][0] = DAT_a8026cb6[0][2];
        DAT_a802c864[12][1] = DAT_a8026cb6[0][5];
        DAT_a802c864[12][2] = DAT_a8026cb6[0][8];
        DAT_a802c864[12][3] = DAT_a8026cb6[0][11];
        DAT_a802c864[12][4] = DAT_a8026cb6[0][14];
        DAT_a802c864[13][0] = DAT_a8026cb6[5][2];
        DAT_a802c864[13][1] = DAT_a8026cb6[5][5];
        DAT_a802c864[13][2] = DAT_a8026cb6[5][8];
        DAT_a802c864[13][3] = DAT_a8026cb6[5][11];
        DAT_a802c864[13][4] = DAT_a8026cb6[5][14];
        DAT_a802c864[14][0] = DAT_a8026cb6[10][2];
        DAT_a802c864[14][1] = DAT_a8026cb6[10][5];
        DAT_a802c864[14][2] = DAT_a8026cb6[10][8];
        DAT_a802c864[14][3] = DAT_a8026cb6[10][11];
        DAT_a802c864[14][4] = DAT_a8026cb6[10][14];
        DAT_a802c864[15][0] = DAT_a8026cb6[15][2];
        DAT_a802c864[15][1] = DAT_a8026cb6[15][5];
        DAT_a802c864[15][2] = DAT_a8026cb6[15][8];
        DAT_a802c864[15][3] = DAT_a8026cb6[15][11];
        DAT_a802c864[15][4] = DAT_a8026cb6[15][14];
    }
    return 1;
}
