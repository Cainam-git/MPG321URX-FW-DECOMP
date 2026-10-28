/* leon2m FUN_a00da754 @ 0xa00da754-0xa00da840 (59 words).
 * UserSetAuroraLEDBarBrightness: v = level * 20 + 20 (byte) is printed, then the 11-byte command "5b00740" +
 * three decimal digits of v + '\r' is built at 0xa802d268 and sent with FUN_a01487e8(2, 11, buf), followed by
 * FUN_a01350dc().
 * The digits are computed into unsigned char locals of one inner block before the stores (as in FUN_a00bf110).
 */
extern unsigned char DAT_a802d268[11];
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);
extern void FUN_a01350dc(void);

void FUN_a00da754(unsigned char level)
{
    unsigned char v = level * 20 + 20;

    FUN_a00df170("UserSetAuroraLEDBarBrightness %d\r\n", v);
    {
        unsigned char h, r, t, o;
        h = v / 100;
        r = v - h * 100;
        t = r / 10;
        o = r - t * 10;
        DAT_a802d268[0] = '5';
        DAT_a802d268[1] = 'b';
        DAT_a802d268[2] = '0';
        DAT_a802d268[3] = '0';
        DAT_a802d268[4] = '7';
        DAT_a802d268[5] = '4';
        DAT_a802d268[6] = '0';
        DAT_a802d268[7] = h + '0';
        DAT_a802d268[8] = t + '0';
        DAT_a802d268[9] = o + '0';
        DAT_a802d268[10] = '\r';
    }
    FUN_a01487e8(2, 11, DAT_a802d268);
    FUN_a01350dc();
}
