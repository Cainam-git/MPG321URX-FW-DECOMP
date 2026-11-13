/* dp_mst_read_payload_words  (FUN_a00b1394)
 *
 * Wait for the ready flag and read 63 words of the payload table from the hardware.
 * Name basis: descriptive - registers 0xCF037C84 / 0xCF037C88
 *
 * Matching notes
 * --------------
 * FUN_a00b1394 (leon2s 0xa00b1394-0xa00b1418, 132 bytes, leaf), flags -mcpu=v8 -Os -g.
 * One register pointer variable is reused for 0xcf037c80, 0xcf037c84 and the read loop: the firmware keeps
 * all three in the same register. `port` is not used.
 */
#define REG_7C80 (*(volatile unsigned int *)0xcf037c80)
#define REG_7C84 (*(volatile unsigned int *)0xcf037c84)
#define REG_C820 (*(volatile unsigned int *)0xcf03c820)
#define REG_C830 (*(volatile unsigned int *)0xcf03c830)
#define REG_7C88 ((volatile unsigned int *)0xcf037c88)

/* Read the 63 words of the payload table from the hardware into `buf` (low byte of each word).
 * Writes 1 to register 0xcf037c80, waits until register 0xcf037c84 reads 1 (copying register 0xcf03c820
 * to 0xcf03c830 while it waits), reads the words at 0xcf037c88 upward, then writes 0 to 0xcf037c80.
 * Called by dp_mst_update_payload_table; `port` is passed 0 there and not used. */
void dp_mst_read_payload_words(unsigned char port, unsigned char *buf)
{
    volatile unsigned int *p;
    unsigned char i;

    p = &REG_7C80;
    *p = 1;
    p = &REG_7C84;
    while (*p != 1)
        REG_C830 = REG_C820;
    p = REG_7C88;
    for (i = 0; i < 63; i++)
        buf[i] = *p++;
    p = &REG_7C80;
    *p = 0;
}
