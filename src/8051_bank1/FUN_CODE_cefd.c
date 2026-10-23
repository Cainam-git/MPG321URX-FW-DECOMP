/* 8051_bank1 FUN_CODE_cefd @ 0xcefd..0xcf38 (59 bytes)
 * Options: OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * FUN_CODE_cefd(page, v): stores v >> 8 to XDATA 0xF401 + page, then returns the 16-bit value whose low byte is at
 *   XDATA 0x6100 + page * 256 + (v & 0xFF) and whose high byte is at the next address. All accesses go through
 *   generic pointers (?C?CSTPTR, ?C?CLDPTR; the pointer is advanced by 1 between the two reads).
 * LARGE parameter: page at XDATA 0xA477 (re-read for the second address); v stays in R4:R5.
 * Source form: the first address is the array's address cast to a generic pointer plus page, which sets R3 = 1
 *   before the address add as in the firmware ('DAT_EXTMEM_f401 + page' sets R3 after it).
 * Caller: FUN_CODE_b2b0 (LCALLs at 0xB2ED and 0xB322, v = 0x1F1C, result masked with 0x3FF there). Same address
 *   scheme as FUN_CODE_ce18 (store) and FUN_CODE_d53f (8-bit read).
 */
extern unsigned char xdata DAT_EXTMEM_f401[];
extern unsigned char xdata DAT_EXTMEM_6100[][256];

unsigned int FUN_CODE_cefd(unsigned char page, unsigned int v)
{
    unsigned char *p;
    unsigned char lo;
    p = (unsigned char *)&DAT_EXTMEM_f401 + page;
    *p = v >> 8;
    p = DAT_EXTMEM_6100[page];
    p += (unsigned char)v;
    lo = *p;
    p++;
    return (*p << 8) | lo;
}
