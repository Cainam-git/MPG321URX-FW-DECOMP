/* leon2m FUN_a00bb86c @ 0xa00bb86c (-mcpu=v8 -O3 -g)
 * Returns the first i in 0 .. 0x82 for which each FUN_a015463c(i, j), j = 2 .. 6, is 0xFF or equals byte j of the
 * array 0xA802D040; returns 0xFF when no i matches. Same code as FUN_a00bb1c4 with other constants.
 * See FUN_a00bb1c4 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern unsigned char DAT_a802d040[];

unsigned char FUN_a00bb86c(void)
{
    unsigned char idx, j;

    for (idx = 0; idx <= 0x82; idx++) {
        for (j = 2; j <= 6; j++) {
            if (FUN_a015463c(idx, j) != 0xff && FUN_a015463c(idx, j) != DAT_a802d040[j])
                break;
        }
        if (j == 7)
            return idx;
    }
    return 0xff;
}
