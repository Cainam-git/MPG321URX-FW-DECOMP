/* reg_paged_read  (FUN_CODE_bb56)
 *
 * Read a paged register of block 0 or 1.
 *   sel: block 0/1
 *   p: page:register
 * Returns: value
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - page select 0xF405..0xF408, access 0xD50B..0xD50D
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_bb56, OPTIMIZE(8,SPEED) LARGE.
 * Source form: each branch has its own shift-count local (shift_0, shift_1).
 */
extern unsigned char xdata reg_chip_id;
extern unsigned char xdata reg_paged_block0_page_low, reg_paged_block0_page_high, reg_paged_block1_page_low, reg_paged_block1_page_high;
extern unsigned char xdata reg_paged_select, reg_paged_index, reg_paged_data;

/*
 * reg_paged_read - read one register of the paged register space of block 0 or 1.
 *   sel: 0 = block 0, else block 1
 *   p: page in the high byte, register number in the low byte
 * The page select word is written to 0xF405/0xF406 (block 0) or 0xF407/0xF408 (block 1): the page itself when
 * reg_chip_id is 0x20, else 1 << page. Then 0xD50B gets the select code (0x85 for block 0, 0x86 for block 1), 0xD50C
 * the register number, and the value is read from 0xD50D. No caller in the bank-1 image.
 */
unsigned char reg_paged_read(unsigned char sel, unsigned int p)
{
    unsigned int page_word;
    unsigned char shift_0, shift_1;

    if (sel == 0) {
        if (reg_chip_id == 0x20) {
            page_word = p >> 8;
        } else {
            shift_0 = p >> 8;
            page_word = 1 << shift_0;
        }
        reg_paged_block0_page_low = page_word;
        reg_paged_block0_page_high = page_word >> 8;
        reg_paged_select = 0x85;
    } else {
        if (reg_chip_id == 0x20) {
            page_word = p >> 8;
        } else {
            shift_1 = p >> 8;
            page_word = 1 << shift_1;
        }
        reg_paged_block1_page_low = page_word;
        reg_paged_block1_page_high = page_word >> 8;
        reg_paged_select = 0x86;
    }
    reg_paged_index = p;
    return reg_paged_data;
}
