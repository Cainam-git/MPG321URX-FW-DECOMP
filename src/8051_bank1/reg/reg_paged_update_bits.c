/* reg_paged_update_bits  (FUN_CODE_9e3f)
 *
 * Set or clear bits in a paged register of block 0 or 1.
 *   block: block 0/1
 *   page_reg: page:register
 *   bits
 *   set: 1 set, else clear
 * Name basis: descriptive - page select 0xF405..0xF408, access 0xD50B..0xD50D, window 0x6500 / 0x6600
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9e3f @ 0x9e3f (197 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Parameters: block in R7 (copied to R1 = block_copy), page_reg in R4:R5, bits in R3, set in the LARGE slot
 * 0xA47A; page_bits at 0xA47B..0xA47C.
 * Source form: each branch has its own shift-count local (shift_0, shift_1).
 */

extern unsigned char xdata reg_chip_id;
extern unsigned char xdata reg_paged_block0_page_low, reg_paged_block0_page_high, reg_paged_block1_page_low, reg_paged_block1_page_high;
extern unsigned char xdata reg_paged_select, reg_paged_index, reg_paged_data;
extern unsigned char xdata reg_paged_block0_window[256];
extern unsigned char xdata reg_paged_block1_window[256];

#define CHIP_ID_20          0x20  /* reg_chip_id: the page register takes the page number itself */
#define PAGED_SELECT_BLOCK0 0x85  /* reg_paged_select: reg_paged_index / reg_paged_data reach block 0 */
#define PAGED_SELECT_BLOCK1 0x86

/*
 * reg_paged_update_bits - set or clear bits in a paged register of block 0 or 1.
 *   block     0 = block 0 (page register 0xF405/0xF406, window 0x6500), else block 1 (0xF407/0xF408, 0x6600)
 *   page_reg  high byte = page, low byte = register in the page
 *   bits      the bits to change
 *   set       1 = set them, any other value = clear them
 * The page register gets the page number on chip 0x20, else a single bit 1 << page. The current value is read
 * through reg_paged_select / reg_paged_index / reg_paged_data and the changed value written into the window.
 * Only caller: reg_paged_init_wake_port.
 */
void reg_paged_update_bits(unsigned char block, unsigned int page_reg, unsigned char bits, unsigned char set)
{
    unsigned char block_copy, shift_0, shift_1, value;
    unsigned int page_bits;

    block_copy = block;
    if (block_copy == 0) {
        if (reg_chip_id == CHIP_ID_20) {
            page_bits = (unsigned char)(page_reg >> 8);
        } else {
            shift_0 = page_reg >> 8;
            page_bits = 1 << shift_0;
        }
        reg_paged_block0_page_low = (unsigned char)page_bits;
        reg_paged_block0_page_high = page_bits >> 8;
        reg_paged_select = PAGED_SELECT_BLOCK0;
    } else {
        if (reg_chip_id == CHIP_ID_20) {
            page_bits = (unsigned char)(page_reg >> 8);
        } else {
            shift_1 = page_reg >> 8;
            page_bits = 1 << shift_1;
        }
        reg_paged_block1_page_low = (unsigned char)page_bits;
        reg_paged_block1_page_high = page_bits >> 8;
        reg_paged_select = PAGED_SELECT_BLOCK1;
    }
    reg_paged_index = (unsigned char)page_reg;
    value = reg_paged_data;
    if (set == 1) value |= bits;
    else value &= ~bits;
    if (block_copy == 0) reg_paged_block0_window[(unsigned char)page_reg] = value;
    else reg_paged_block1_window[(unsigned char)page_reg] = value;
}
