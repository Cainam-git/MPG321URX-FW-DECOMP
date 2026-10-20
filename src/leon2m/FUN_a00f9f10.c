/* leon2m FUN_a00f9f10 @ 0xa00f9f10-0xa00fa560 (1616 bytes).
 * Reads bits 12..15 of the hardware register 0xd0040098. For value 3 it fills the table at 0xa8026ed6, for value 4
 * the table at 0xa8026cb6; any other value changes nothing. Each table is 16 rows of 17 halfwords. Returns 1.
 * Steps for the selected table t, with s = the halfword rows at 0xa802c864 + 0x10 (stride 8 halfwords):
 *   1. t[0][2], t[0][5], t[0][8], t[0][11], t[0][14] = s row 0 entries 0..4; rows 5, 10 and 15 likewise from s
 *      rows 1, 2 and 3.
 *   2. t[i][16] = 0x400 for i = 0..15.
 *   3. For columns 2, 5, 8, 11, 14 and row groups 0, 5, 10: rows r+1..r+4 = (a * w + b * (256 - w) + 0x80) >> 8
 *      with a = t[r][c], b = t[r+5][c], w = 0xcc, 0x99, 0x66, 0x33.
 *   4. For every row and columns 2, 5, 8, 11: t[r][c+1] and t[r][c+2] = the same rounding with w = 0xaa and 0x55
 *      between t[r][c] and t[r][c+3].
 *   5. t[i][15] = rounded mean of t[i][14] and t[i][16]; t[i][0] = 0x400; t[i][1] = rounded mean of t[i][0] and
 *      t[i][2].
 * The two branches are written out separately: as one static helper taking the table pointer the build differs.
 * The means are computed in unsigned arithmetic (srl, not sra).
 */
extern unsigned short DAT_a802c864[][8];
extern unsigned short DAT_a8026cb6[16][17];
extern unsigned short DAT_a8026ed6[16][17];
#define REG_D0040098 (*(volatile unsigned int *)0xd0040098)

int FUN_a00f9f10(void)
{
    unsigned int mode = (unsigned short)REG_D0040098 >> 12;
    unsigned char i, r, c;

    if (mode == 3) {
        DAT_a8026ed6[0][2] = DAT_a802c864[1][0];
        DAT_a8026ed6[0][5] = DAT_a802c864[1][1];
        DAT_a8026ed6[0][8] = DAT_a802c864[1][2];
        DAT_a8026ed6[0][11] = DAT_a802c864[1][3];
        DAT_a8026ed6[0][14] = DAT_a802c864[1][4];
        DAT_a8026ed6[5][2] = DAT_a802c864[2][0];
        DAT_a8026ed6[5][5] = DAT_a802c864[2][1];
        DAT_a8026ed6[5][8] = DAT_a802c864[2][2];
        DAT_a8026ed6[5][11] = DAT_a802c864[2][3];
        DAT_a8026ed6[5][14] = DAT_a802c864[2][4];
        DAT_a8026ed6[10][2] = DAT_a802c864[3][0];
        DAT_a8026ed6[10][5] = DAT_a802c864[3][1];
        DAT_a8026ed6[10][8] = DAT_a802c864[3][2];
        DAT_a8026ed6[10][11] = DAT_a802c864[3][3];
        DAT_a8026ed6[10][14] = DAT_a802c864[3][4];
        DAT_a8026ed6[15][2] = DAT_a802c864[4][0];
        DAT_a8026ed6[15][5] = DAT_a802c864[4][1];
        DAT_a8026ed6[15][8] = DAT_a802c864[4][2];
        DAT_a8026ed6[15][11] = DAT_a802c864[4][3];
        DAT_a8026ed6[15][14] = DAT_a802c864[4][4];
        for (i = 0; i < 16; i++)
            DAT_a8026ed6[i][16] = 0x400;
        for (c = 2; c < 17; c += 3) {
            for (r = 0; r < 15; r += 5) {
                unsigned int a = DAT_a8026ed6[r][c];
                unsigned int b = DAT_a8026ed6[r + 5][c];
                DAT_a8026ed6[r + 1][c] = (a * 0xcc + b * 0x34 + 0x80) >> 8;
                DAT_a8026ed6[r + 2][c] = (a * 0x99 + b * 0x67 + 0x80) >> 8;
                DAT_a8026ed6[r + 3][c] = (a * 0x66 + b * 0x9a + 0x80) >> 8;
                DAT_a8026ed6[r + 4][c] = (a * 0x33 + b * 0xcd + 0x80) >> 8;
            }
        }
        for (r = 0; r < 16; r++) {
            for (c = 2; c < 14; c += 3) {
                unsigned int a = DAT_a8026ed6[r][c];
                unsigned int b = DAT_a8026ed6[r][c + 3];
                DAT_a8026ed6[r][c + 1] = (a * 0xaa + b * 0x56 + 0x80) >> 8;
                DAT_a8026ed6[r][c + 2] = (a * 0x55 + b * 0xab + 0x80) >> 8;
            }
        }
        for (i = 0; i < 16; i++)
            DAT_a8026ed6[i][15] = (((unsigned int)DAT_a8026ed6[i][14] + DAT_a8026ed6[i][16]) * 0x80 + 0x80) >> 8;
        for (i = 0; i < 16; i++)
            DAT_a8026ed6[i][0] = 0x400;
        for (i = 0; i < 16; i++)
            DAT_a8026ed6[i][1] = (((unsigned int)DAT_a8026ed6[i][0] + DAT_a8026ed6[i][2]) * 0x80 + 0x80) >> 8;
    } else if (mode == 4) {
        DAT_a8026cb6[0][2] = DAT_a802c864[1][0];
        DAT_a8026cb6[0][5] = DAT_a802c864[1][1];
        DAT_a8026cb6[0][8] = DAT_a802c864[1][2];
        DAT_a8026cb6[0][11] = DAT_a802c864[1][3];
        DAT_a8026cb6[0][14] = DAT_a802c864[1][4];
        DAT_a8026cb6[5][2] = DAT_a802c864[2][0];
        DAT_a8026cb6[5][5] = DAT_a802c864[2][1];
        DAT_a8026cb6[5][8] = DAT_a802c864[2][2];
        DAT_a8026cb6[5][11] = DAT_a802c864[2][3];
        DAT_a8026cb6[5][14] = DAT_a802c864[2][4];
        DAT_a8026cb6[10][2] = DAT_a802c864[3][0];
        DAT_a8026cb6[10][5] = DAT_a802c864[3][1];
        DAT_a8026cb6[10][8] = DAT_a802c864[3][2];
        DAT_a8026cb6[10][11] = DAT_a802c864[3][3];
        DAT_a8026cb6[10][14] = DAT_a802c864[3][4];
        DAT_a8026cb6[15][2] = DAT_a802c864[4][0];
        DAT_a8026cb6[15][5] = DAT_a802c864[4][1];
        DAT_a8026cb6[15][8] = DAT_a802c864[4][2];
        DAT_a8026cb6[15][11] = DAT_a802c864[4][3];
        DAT_a8026cb6[15][14] = DAT_a802c864[4][4];
        for (i = 0; i < 16; i++)
            DAT_a8026cb6[i][16] = 0x400;
        for (c = 2; c < 17; c += 3) {
            for (r = 0; r < 15; r += 5) {
                unsigned int a = DAT_a8026cb6[r][c];
                unsigned int b = DAT_a8026cb6[r + 5][c];
                DAT_a8026cb6[r + 1][c] = (a * 0xcc + b * 0x34 + 0x80) >> 8;
                DAT_a8026cb6[r + 2][c] = (a * 0x99 + b * 0x67 + 0x80) >> 8;
                DAT_a8026cb6[r + 3][c] = (a * 0x66 + b * 0x9a + 0x80) >> 8;
                DAT_a8026cb6[r + 4][c] = (a * 0x33 + b * 0xcd + 0x80) >> 8;
            }
        }
        for (r = 0; r < 16; r++) {
            for (c = 2; c < 14; c += 3) {
                unsigned int a = DAT_a8026cb6[r][c];
                unsigned int b = DAT_a8026cb6[r][c + 3];
                DAT_a8026cb6[r][c + 1] = (a * 0xaa + b * 0x56 + 0x80) >> 8;
                DAT_a8026cb6[r][c + 2] = (a * 0x55 + b * 0xab + 0x80) >> 8;
            }
        }
        for (i = 0; i < 16; i++)
            DAT_a8026cb6[i][15] = (((unsigned int)DAT_a8026cb6[i][14] + DAT_a8026cb6[i][16]) * 0x80 + 0x80) >> 8;
        for (i = 0; i < 16; i++)
            DAT_a8026cb6[i][0] = 0x400;
        for (i = 0; i < 16; i++)
            DAT_a8026cb6[i][1] = (((unsigned int)DAT_a8026cb6[i][0] + DAT_a8026cb6[i][2]) * 0x80 + 0x80) >> 8;
    }
    return 1;
}
