/* leon2m FUN_a00bb260 @ 0xa00bb260-0xa00bb414 (109 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00ce348. Compares
 * bytes 2..n of the receive record at 0xa802d0d0 with the table rows returned by three lookup functions (a table
 * byte 0xff matches any value): rows i = 0..0x8c of FUN_a015468c(i, j) for j = 2..9 (returns i on a full match),
 * rows i = 0..0xc of FUN_a01546ec(i, j) for j = 2..0x18 (returns i + 0x8d), row 0 of FUN_a0154750(0, j) for j = 2..5
 * (returns 0x99). Returns 0xff when no row matches. The port parameter is not used.
 */
extern unsigned char DAT_a802d0d0[];
extern unsigned char FUN_a015468c(unsigned short a, unsigned short b);
extern unsigned char FUN_a01546ec(unsigned short a, unsigned short b);
extern unsigned char FUN_a0154750(unsigned short a, unsigned short b);

unsigned char FUN_a00bb260(unsigned char port)
{
    unsigned char i, j;

    for (i = 0; i <= 0x8c; i++) {
        for (j = 2; j <= 9; j++)
            if (FUN_a015468c(i, j) != 0xff && FUN_a015468c(i, j) != DAT_a802d0d0[j])
                break;
        if (j == 10)
            return i;
    }
    for (i = 0; i <= 0xc; i++) {
        for (j = 2; j <= 0x18; j++)
            if (FUN_a01546ec(i, j) != 0xff && FUN_a01546ec(i, j) != DAT_a802d0d0[j])
                break;
        if (j == 0x19)
            return i + 0x8d;
    }
    for (i = 0; i <= 0; i++) {
        for (j = 2; j <= 5; j++)
            if (FUN_a0154750(i, j) != 0xff && FUN_a0154750(i, j) != DAT_a802d0d0[j])
                break;
        if (j == 6)
            return 0x99;
    }
    return 0xff;
}
