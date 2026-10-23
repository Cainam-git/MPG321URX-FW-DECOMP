/* 8051_bank1 module FUN_CODE_b2b0: FUN_CODE_ce18 @ 0xce18..0xce4b and FUN_CODE_b2b0 @ 0xb2b0..0xb33e.
 * Options: OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 *   FUN_CODE_ce18 with its common-entry block 0xCE0D..0xCE18 -> 62/62 bytes at the same options, once the learned
 *   XDATA block base ?FUN_CODE_ce18?XD in symbols/8051_bank1.libs.json is 0xA477 (page at 0xA477, x at 0xA478).
 * One Keil module (code): the firmware has the common-entry block 0xCE0D..0xCE18 in front of FUN_CODE_ce18
 *   (0xCE0D: R3 = 0x28; 0xCE0F: R7 = XDATA 0xA476, R4:R5 = 0x1C02), entered only by the three calls in FUN_CODE_b2b0
 *   (0xB30D, 0xB332, 0xB337). Keil builds such a block only from calls inside the same module.
 * FUN_CODE_ce18(page, v, x): stores v >> 8 to XDATA 0xF401 + page and x to XDATA 0x6100 + page * 256 + (v & 0xFF),
 *   both through generic pointers (?C?CSTPTR). Source form: the first address is the array's address cast to a generic
 *   pointer plus page ('(unsigned char *)&DAT_EXTMEM_f401 + page'), which sets R3 = 1 before the address add as in
 *   the firmware; 'DAT_EXTMEM_f401 + page' sets R3 after it.
 * FUN_CODE_b2b0(pg) returns a bit (carry). pg is a LARGE parameter at XDATA 0xA476; ce18's page and x follow at
 *   0xA477/0xA478. When XDATA 0xD511 is 0x20 it returns FUN_CODE_d92a(pg). Otherwise: XDATA 0xD523 = 0x83;
 *   ce18(pg, 0x1F02, 4); returns 0 unless bit 0 of FUN_CODE_dd74(0x20) is set and (FUN_CODE_cefd(pg, 0x1F1C) & 0x3FF)
 *   is above 0x16 (the first cefd call reuses R4 = 0x1F from the ce18 call). Then returns 1 when bit 0x01 (BITS_20_1)
 *   is set; else prints "Check Again!!!!\r\n" (FUN_CODE_2820, format at CODE 0xB102), ce18(pg, 0x1C02, 0x24), repeats
 *   the dd74 / cefd test, and in both outcomes calls ce18(pg, 0x1C02, 0x28) before returning the test result.
 * The parameter of FUN_CODE_b2b0 is named pg, not page: tools/diff8051.py resolves a name in the common-entry block
 *   as the callee's local when both functions have a local of that name.
 */
extern unsigned char xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_d523;
extern unsigned char xdata DAT_EXTMEM_f401[];
extern unsigned char xdata DAT_EXTMEM_6100[][256];
extern bit BITS_20_1;
extern bit FUN_CODE_d92a(unsigned char page);
extern unsigned char FUN_CODE_dd74(unsigned char reg);
extern unsigned int FUN_CODE_cefd(unsigned char page, unsigned int v);
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_ce18(unsigned char page, unsigned int v, unsigned char x)
{
    unsigned char *p;
    p = (unsigned char *)&DAT_EXTMEM_f401 + page;
    *p = v >> 8;
    p = DAT_EXTMEM_6100[page];
    p += (unsigned char)v;
    *p = x;
}

bit FUN_CODE_b2b0(unsigned char pg)
{
    if (DAT_EXTMEM_d511 == 0x20) {
        if (FUN_CODE_d92a(pg)) return 1;
        return 0;
    }
    DAT_EXTMEM_d523 = 0x83;
    FUN_CODE_ce18(pg, 0x1f02, 4);
    if (FUN_CODE_dd74(0x20) & 1) {
        if ((FUN_CODE_cefd(pg, 0x1f1c) & 0x3ff) > 0x16) {
            if (BITS_20_1) return 1;
            FUN_CODE_2820((void code *)0xb102);
            FUN_CODE_ce18(pg, 0x1c02, 0x24);
            if (FUN_CODE_dd74(0x20) & 1) {
                if ((FUN_CODE_cefd(pg, 0x1f1c) & 0x3ff) > 0x16) {
                    FUN_CODE_ce18(pg, 0x1c02, 0x28);
                    return 1;
                }
            }
            FUN_CODE_ce18(pg, 0x1c02, 0x28);
            return 0;
        }
    }
    return 0;
}
