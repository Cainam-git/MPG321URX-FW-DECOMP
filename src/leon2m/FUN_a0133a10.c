/* leon2m FUN_a0133a10 @ 0xa0133a10-0xa0133ad8 (50 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Checks the 35-byte records at 0xa802dd90 for byte 0 != byte 1. For port p != 0 returns p when its record
 * has byte 0 != byte 1, else 0; for p == 0 returns the first record 1..4 with byte 0 != byte 1, else 0. Same record
 * as FUN_a013497c.
 */
struct Rec35 { unsigned char b0, b1, data[32], b34; };
extern struct Rec35 DAT_a802dd90[];

unsigned char FUN_a0133a10(unsigned char p)
{
    unsigned char r = 0;
    unsigned char i;

    if (p != 0) {
        if (DAT_a802dd90[p].b0 != DAT_a802dd90[p].b1)
            r = p;
    } else {
        for (i = 1; i <= 4; i++)
            if (DAT_a802dd90[i].b0 != DAT_a802dd90[i].b1) {
                r = i;
                break;
            }
    }
    return r;
}
