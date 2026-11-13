/* reg_paged_write  (FUN_CODE_ab2c)
 *
 * Write a paged register of block 0 or 1.
 *   block: block 0/1
 *   page_reg: page:register
 *   value
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - page select 0xF405..0xF408, window 0x6500 / 0x6600; counterpart reg_paged_read
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ab2c @ 0xab2c (152 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: each branch has its own shift-count local (shift_0, shift_1); the page value goes through the
 * XDATA int 0xA774.
 */
extern unsigned char xdata reg_chip_id;
extern unsigned int xdata DAT_EXTMEM_a774;
extern unsigned char xdata reg_paged_block0_page_low, reg_paged_block0_page_high, reg_paged_block1_page_low, reg_paged_block1_page_high;
extern unsigned char xdata reg_paged_block0_window[256];
extern unsigned char xdata reg_paged_block1_window[256];

#define CHIP_ID_20  0x20  /* reg_chip_id: the page register takes the page number itself */

/*
 * reg_paged_write - write a paged register of block 0 or 1.
 *   block     0 = block 0 (page register 0xF405/0xF406, window 0x6500), else block 1 (0xF407/0xF408, 0x6600)
 *   page_reg  high byte = page, low byte = register in the page
 *   value     the value written
 * The page register gets the page number on chip 0x20, else a single bit 1 << page.
 * Nothing in the bank 1 program calls this routine.
 */
void reg_paged_write(unsigned char block, unsigned int page_reg, unsigned char value)
{
    unsigned char shift_0, shift_1;

    if (block == 0) {
        if (reg_chip_id == CHIP_ID_20) {
            DAT_EXTMEM_a774 = page_reg >> 8;
        } else {
            shift_0 = page_reg >> 8;
            DAT_EXTMEM_a774 = 1 << shift_0;
        }
        reg_paged_block0_page_low = DAT_EXTMEM_a774;
        reg_paged_block0_page_high = DAT_EXTMEM_a774 >> 8;
        reg_paged_block0_window[(unsigned char)page_reg] = value;
    } else {
        if (reg_chip_id == CHIP_ID_20) {
            DAT_EXTMEM_a774 = page_reg >> 8;
        } else {
            shift_1 = page_reg >> 8;
            DAT_EXTMEM_a774 = 1 << shift_1;
        }
        reg_paged_block1_page_low = DAT_EXTMEM_a774;
        reg_paged_block1_page_high = DAT_EXTMEM_a774 >> 8;
        reg_paged_block1_window[(unsigned char)page_reg] = value;
    }
}
