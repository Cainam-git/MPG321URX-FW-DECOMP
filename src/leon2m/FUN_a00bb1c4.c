/*
 * FUN_a00bb1c4: command-table lookup. For idx 0..0x82 compares table bytes 2..6 (FUN_a015463c(idx, j);
 * 0xff = wildcard) with the received command bytes DAT_a802d0d0[2..6]; returns the first full match or 0xff.
 * Inlined into FUN_a00ce348 case 2 (MSI tool command handling). Flags: -mcpu=v8 -O3 -g.
 * Hand. No compiler aids.
 */
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern unsigned char DAT_a802d0d0[];

unsigned char FUN_a00bb1c4(void)
{
    unsigned char idx, j;

    for (idx = 0; idx <= 0x82; idx++) {
        for (j = 2; j <= 6; j++) {
            if (FUN_a015463c(idx, j) != 0xff && FUN_a015463c(idx, j) != DAT_a802d0d0[j])
                break;
        }
        if (j == 7)
            return idx;
    }
    return 0xff;
}
