/* 8051_bank0 FUN_CODE_1346 @ 0x1346  STBC boot loader: copy into the share structure at XDATA 0x3000 (byte-exact
 * with OPTIMIZE(7,SPEED)).
 * FUN_CODE_1346(kind R7, len R5, src generic pointer R1..R3): copies len bytes from src to XDATA 0x3000 + off[kind],
 * off = 0x00, 0x02, 0x0E, 0x32, 0x5A, 0x66, 0x6A, 0x76, 0x82, 0x8E for kind 0..9 (a kind >= 10 leaves off
 * uninitialised: not reached by any caller). The block at 0x3000 is the "share structure" the next image (STBC
 * main) reads, e.g. the flash type at 0x3066 = kind 5 (per the public MPG 341CQPX write-up). Callers: the
 * partition-table loader FUN_CODE_0003 (version + descriptors) and the flash identification FUN_CODE_111f (kind 5).
 * The parameter order is taken from the registers (kind in R7), the reverse of the reference write-up's notation.
 */
extern unsigned char xdata DAT_EXTMEM_3000[];
void FUN_CODE_1346(unsigned char kind, unsigned char len, unsigned char *src)
{
    unsigned int off;
    unsigned char i;
    switch (kind) {
    case 0: off = 0; break;
    case 1: off = 0x02; break;
    case 2: off = 0x0e; break;
    case 3: off = 0x32; break;
    case 4: off = 0x5a; break;
    case 5: off = 0x66; break;
    case 6: off = 0x6a; break;
    case 7: off = 0x76; break;
    case 8: off = 0x82; break;
    case 9: off = 0x8e; break;
    }
    for (i = 0; i < len; i++) {
        DAT_EXTMEM_3000[i + off] = src[i];
    }
}
