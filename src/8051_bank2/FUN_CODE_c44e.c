/* FUN_CODE_c44e, 8051_bank2 (helper chip updater), range 0xC44E..0xC52F (225 B).
 * Options: OPTIMIZE(8,SPEED) LARGE. Judge: tools/diff8051.judge (jj.py, scratch copy) MATCH, exact None, 225/225.
 * Code facts: LARGE parameters id (generic pointer, 0x0902..0x0904, from R3/R2/R1) and tbl (generic pointer, memory
 * parameter 0x0905..0x0907), local i at 0x0908. Table lookup over 8-byte records (all reads ?C?CLDOPTR with a DPTR
 * field offset): for i = 0..254 it returns i when record bytes 5, 6, 7 equal id[3], id[4], id[5]; it stops at the
 * first record whose byte 5 is 0xFF and then returns 0xFF (also after 255 records).
 * The caller FUN_CODE_0003 (0x0044, src/8051_bank2/FUN_CODE_0003.c) passes the SPI flash JEDEC reply buffer and the
 * chip table at CODE 0xCB8C; it declares tbl as void *, the record layout here is the 8-byte struct (fields at 5..7;
 * bytes 0..4 are not read by this function). Keil keeps i * 8 in R6:R7 for the first two fields and recomputes it
 * with B for the third and for the 0xFF test. No aids.
 */
struct rec { unsigned char a[5]; unsigned char b; unsigned char c; unsigned char d; };
unsigned char FUN_CODE_c44e(unsigned char *id, struct rec *tbl)
{
    unsigned char i;
    for (i = 0; i < 0xff; i++) {
        if (tbl[i].b == id[3] && tbl[i].c == id[4] && tbl[i].d == id[5]) return i;
        if (tbl[i].b == 0xff) break;
    }
    return 0xff;
}
