/* leon2m FUN_a0101704 @ 0xa0101704-0xa010178c (34 words).
 * Writes 0x10 to hardware register 0xcf0160f8, then writes the 0x80 bytes p[0..0x7f] one by one to the data
 * register 0xcf0160fc (two loops of 0x40 with an unsigned short counter, the second reading p[i + 0x40]), then
 * writes 0 to 0xcf0160f8. Called from FUN_a0129b44.
 * Source form: the first loop reads through an unsigned int copy j of the counter; that copy gives the load operand
 * order [p + j] of the firmware.
 */
#define REG_cf0160f8 (*(volatile unsigned int *)0xcf0160f8)
#define REG_cf0160fc (*(volatile unsigned int *)0xcf0160fc)

void FUN_a0101704(unsigned char *p)
{
    unsigned short i;
    unsigned int j;

    REG_cf0160f8 = 0x10;
    for (i = 0; i < 0x40; i++) {
        j = i;
        REG_cf0160fc = p[j];
    }
    for (i = 0; i < 0x40; i++)
        REG_cf0160fc = p[i + 0x40];
    REG_cf0160f8 = 0;
}
