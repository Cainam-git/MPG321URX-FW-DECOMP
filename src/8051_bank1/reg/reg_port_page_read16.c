/* reg_port_page_read16  (FUN_CODE_cefd)
 *
 * Read a 16-bit value from a port's paged register window.
 *   page: port page
 *   page_and_reg: page:register
 * Returns: 16-bit value
 * Name basis: descriptive - page byte 0xF401 + page, data at 0x6100 + page * 256 + register
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cefd @ 0xcefd..0xcf38 (59 bytes)  Byte-exact with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * LARGE parameter: 'page' at XDATA 0xA477 (re-read for the second address); 'page_and_reg' stays in R4:R5.
 * Source form: the first address is the array's address cast to a generic pointer plus page, which sets R3 = 1
 * before the address add as in the firmware ('reg_port_page_select + page' sets R3 after it). All accesses go
 * through generic pointers (?C?CSTPTR, ?C?CLDPTR).
 */
extern unsigned char xdata reg_port_page_select[];
extern unsigned char xdata reg_port_page_window[][256];

/*
 * Read a 16-bit register of the port selected by 'page'. The high byte of
 * page_and_reg is first stored in the page select register of that port
 * (0xF401 + page); the low byte is the register number inside the port's
 * window (0x6100 + page * 256). The value is the byte there (low) and the
 * next byte (high). Caller: the code at 0xB2ED and 0xB322 (page_and_reg =
 * 0x1F1C there). The same address scheme is used by reg_port_page_write (store)
 * and reg_read_paged_byte (8-bit read).
 */
unsigned int reg_port_page_read16(unsigned char page, unsigned int page_and_reg)
{
    unsigned char *ptr;
    unsigned char low_byte;
    ptr = (unsigned char *)&reg_port_page_select + page;
    *ptr = page_and_reg >> 8;
    ptr = reg_port_page_window[page];
    ptr += (unsigned char)page_and_reg;
    low_byte = *ptr;
    ptr++;
    return (*ptr << 8) | low_byte;
}
