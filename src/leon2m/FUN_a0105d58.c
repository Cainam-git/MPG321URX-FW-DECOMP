/* leon2m FUN_a0105d58 @ 0xa0105d58-0xa0105e60 (66 words), flags -mcpu=v8 -O3 (no -g: with -g a nop follows the
 * final call).
 * Searches the 8 records of 9 halfwords at 0x19a640 for the first one where (unsigned short)(+0x06 - w) is below
 * +0x06 / 10, (unsigned short)(+0x0e - h) is below +0x0e / 10, and +0x10 - f lies within -9..9. Prints
 * "%d x %d @ %d : Support(%d_%d)" (between the ANSI escape sequences ESC[1;31m and ESC[m) with w, h, f, found (1 or
 * 0) and the record index (8 when none matched) through FUN_a00df170, and returns found. Called from FUN_a0131518.
 */
struct Row { unsigned short h0, h2, h4, h6, h8, ha, hc, he, h10; };
extern const struct Row DAT_0019a640[8];
extern int FUN_a00df170(const char *fmt, ...);

unsigned char FUN_a0105d58(unsigned short w, unsigned short h, unsigned short f)
{
    unsigned char found = 0;
    unsigned char i;

    for (i = 0; i < 8; i++) {
        if ((unsigned short)(DAT_0019a640[i].h6 - w) < DAT_0019a640[i].h6 / 10 &&
            (unsigned short)(DAT_0019a640[i].he - h) < DAT_0019a640[i].he / 10 &&
            (unsigned int)(DAT_0019a640[i].h10 - f + 9) <= 0x12) {
            found = 1;
            break;
        }
    }
    FUN_a00df170("\x1b[1;31m%d x %d @ %d : Support(%d_%d)\r\n\x1b[m", w, h, f, found, i);
    return found;
}
