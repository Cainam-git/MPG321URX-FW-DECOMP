/* reg_read_paged_byte  (FUN_CODE_d53f)
 *
 * Select a register page and read one byte through the page window.
 *   page: block
 *   select_offset: page:offset
 * Returns: register byte
 * Name basis: derived - page register 0xF401 + page, window 0x6100 + page * 256
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d53f @ 0xd53f..0xd56d (46 bytes)
 * Options: OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * LARGE parameter: page at XDATA 0xA477 (re-read for the second address); select_offset stays in R4:R5.
 * Source form: the first address is the array's address cast to a generic pointer plus page, which sets R3 = 1
 *   before the address add as in the firmware ('reg_port_page_select + page' sets R3 after it). The second pointer
 *   keeps R3 = 1 from the first. Both accesses go through generic pointers (?C?CSTPTR, ?C?CLDPTR).
 */
extern unsigned char xdata reg_port_page_select[];
extern unsigned char xdata reg_port_page_window[][256];

/*
 * Read one byte of the paged register window of the input ports.
 *   page: window page (selects the page select byte and the 256-byte page)
 *   select_offset: high byte = value written to the page select byte of this page, low byte = offset in the page
 * Returns the byte at offset (low byte) in window page 'page'.
 * Caller: power_test_port_wake_status (page, 0x041A).
 */
unsigned char reg_read_paged_byte(unsigned char page, unsigned int select_offset)
{
    unsigned char *reg;

    reg = (unsigned char *)&reg_port_page_select + page;
    *reg = select_offset >> 8;
    reg = reg_port_page_window[page];
    reg += (unsigned char)select_offset;
    return *reg;
}
