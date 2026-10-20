/* leon2m FUN_a0083c88 @ 0xa0083c88-0xa0083d80 (62 words).
 * Compares bytes 1..4 of the block at 0xa8024018 with the 4-character codes "Play", "Nint" and "XBOX" (a 12-byte
 * local array) and returns the index 0..2 of the last code that matches, or 0xff when none matches.
 */
extern unsigned char DAT_a8024018[];

unsigned char FUN_a0083c88(void)
{
    unsigned char codes[3][4] = { { 'P', 'l', 'a', 'y' }, { 'N', 'i', 'n', 't' }, { 'X', 'B', 'O', 'X' } };
    unsigned char i, r;

    r = 0xff;
    for (i = 0; i < 3; i++)
        if (codes[i][0] == DAT_a8024018[1] && codes[i][1] == DAT_a8024018[2] && codes[i][2] == DAT_a8024018[3]
            && codes[i][3] == DAT_a8024018[4])
            r = i;
    return r;
}
