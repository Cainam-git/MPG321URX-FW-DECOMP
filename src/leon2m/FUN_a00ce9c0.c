/* leon2m FUN_a00ce9c0 @ 0xa00ce9c0-0xa00cea18 (22 words).
 * Copies 16 bytes into dst from offset blk * 16 of the 512-byte record n of the table DAT_00010000 (record n at
 * DAT_00010000 + n * 0x200). Record numbers of 0x38 and above select record 0. Called from FUN_a00d3650.
 * Source form: the record address is an unsigned int computed from the table symbol (the %lo part of the symbol
 * is an `or` with offset 0); the block offset is computed before the record address.
 */
extern const unsigned char DAT_00010000[];

void FUN_a00ce9c0(unsigned short n, unsigned char *dst, unsigned char blk)
{
    unsigned int addr;
    int off;
    int i;

    if (n >= 0x38)
        n = 0;
    off = blk * 16;
    addr = (unsigned int)DAT_00010000 + n * 0x200;
    for (i = 0; i < 16; i++)
        dst[i] = *(const unsigned char *)(addr + off + i);
}
