/* leon2m FUN_a0133a10 @ 0xa0133a10-0xa0133ad8 (50 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Checks the 35-byte UART ring records at 0xa802dd90 {write index, read index, 32 data bytes, overflow flag} for
 * pending data (write index != read index). For port p != 0 returns p when its ring has data, else 0; for p == 0
 * returns the first port 1..4 whose ring has data, else 0. Same record as FUN_a013497c.
 */
struct UartRing { unsigned char wr, rd, data[32], ovf; };
extern struct UartRing DAT_a802dd90[];

unsigned char FUN_a0133a10(unsigned char p)
{
    unsigned char r = 0;
    unsigned char i;

    if (p != 0) {
        if (DAT_a802dd90[p].wr != DAT_a802dd90[p].rd)
            r = p;
    } else {
        for (i = 1; i <= 4; i++)
            if (DAT_a802dd90[i].wr != DAT_a802dd90[i].rd) {
                r = i;
                break;
            }
    }
    return r;
}
