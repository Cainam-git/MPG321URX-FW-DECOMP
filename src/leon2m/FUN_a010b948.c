/* FUN_a010b948 (leon2m 0xa010b948-0xa010b96c, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns bit 0 of the word register 0xd0030004 (0 or 1). Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a010b918 and FUN_a010b96c. Source form: r = 0; if (REG &
 * 1) r = 1; return r & 1; (the and 1 sits in the retl delay slot).
 */
#define REG (*(volatile unsigned int *)0xd0030004)

unsigned char FUN_a010b948(void)
{
    unsigned char r = 0;

    if (REG & 1)
        r = 1;
    return r & 1;
}
