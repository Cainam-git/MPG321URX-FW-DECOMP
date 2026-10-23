/* 8051_bank1 FUN_CODE_d53f @ 0xd53f..0xd56d (46 bytes)
 * Options: OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * FUN_CODE_d53f(page, v): stores v >> 8 to XDATA 0xF401 + page, then returns the byte at XDATA
 *   0x6100 + page * 256 + (v & 0xFF). Both accesses go through generic pointers (?C?CSTPTR, ?C?CLDPTR).
 * LARGE parameter: page at XDATA 0xA477 (re-read for the second address); v stays in R4:R5.
 * Source form: the first address is the array's address cast to a generic pointer plus page, which sets R3 = 1
 *   before the address add as in the firmware ('DAT_EXTMEM_f401 + page' sets R3 after it). The second pointer keeps
 *   R3 = 1 from the first.
 * Caller: FUN_CODE_d92a (LCALL at 0xD935, page in R7, v = 0x041A). Same address scheme as FUN_CODE_ce18 (store) and
 *   FUN_CODE_cefd (16-bit read).
 */
extern unsigned char xdata DAT_EXTMEM_f401[];
extern unsigned char xdata DAT_EXTMEM_6100[][256];

unsigned char FUN_CODE_d53f(unsigned char page, unsigned int v)
{
    unsigned char *p;
    p = (unsigned char *)&DAT_EXTMEM_f401 + page;
    *p = v >> 8;
    p = DAT_EXTMEM_6100[page];
    p += (unsigned char)v;
    return *p;
}
