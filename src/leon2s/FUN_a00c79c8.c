/* FUN_a00c79c8 (leon2s 0xa00c79c8-0xa00c7a4c, 132 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Clears the 3 x 5 byte table DAT_a807cda8: all three rows when port is 3, otherwise only row 0.
 * Source form: the row counter starts at 0 at its declaration and the row loop is a do-while.
 */
extern unsigned char DAT_a807cda8[3][5];

void FUN_a00c79c8(unsigned char port)
{
    unsigned char i = 0;
    unsigned char j = 0;

    if (port == 3) {
        do {
            for (j = 0; j < 5; j++)
                DAT_a807cda8[i][j] = 0;
            i++;
        } while (i < 3);
    } else {
        for (j = 0; j < 5; j++)
            DAT_a807cda8[i][j] = 0;
    }
}
