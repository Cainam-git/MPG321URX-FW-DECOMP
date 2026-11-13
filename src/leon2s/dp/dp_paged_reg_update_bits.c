/* dp_paged_reg_update_bits  (FUN_a00a7718)
 *
 * Set or clear masked bits of a paged DP receiver register.
 *   port: DP receiver 0/1
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Note: reg: high byte = page 0..8 (one-hot in 0xCF03D014..20), low byte = register; window value 0x85 / 0x86
 *   selects receiver 0 / 1.
 * Name basis: derived - same window as dp_paged_reg_write8; caller dp_init_port_registers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a7718 @ 0xa00a7718-0xa00a78b4 (-mcpu=v8 -Os -g).
 * Same code shape as dp_paged_reg_read8. Source form: mask and the written value are unsigned char (the mask
 * parameter then has no stack-slot equivalence, which decides its register); the data register is read twice
 * (the second value kept) and once more after the restore.
 */
extern const unsigned short dp_paged_reg_bases[];

#define PAGE_SELECT_RX0_LOW  (*(volatile unsigned int *)0xcf03d014) /* receiver 0: bits 0..7 of the page mask */
#define PAGE_SELECT_RX0_BIT8 (*(volatile unsigned int *)0xcf03d018) /* receiver 0: bit 8 of the page mask */
#define PAGE_SELECT_RX1_LOW  (*(volatile unsigned int *)0xcf03d01c) /* receiver 1: bits 0..7 */
#define PAGE_SELECT_RX1_BIT8 (*(volatile unsigned int *)0xcf03d020) /* receiver 1: bit 8 */
#define WINDOW_BLOCK         (*(volatile unsigned int *)0xcf01142c) /* 0x85 for receiver 0, 0x86 for receiver 1 */
#define WINDOW_INDEX         (*(volatile unsigned int *)0xcf011430) /* low byte of the register number */
#define WINDOW_DATA          (*(volatile unsigned int *)0xcf011434) /* value of the selected register */

/*
 * Set or clear bits of one register of a DP receiver that sits behind the page and window registers.
 *   port: DP receiver 0 or 1 (any other value changes nothing)
 *   reg:  high byte = page number 0..8, low byte = register number inside the page
 *   mask: the bits to change
 *   mode: 1 = set the bits of mask, any other value = clear them
 *
 * The page is selected and the current value is read the way dp_paged_reg_read8 does it. The new value is
 * not written through the window but straight to the register address 0xCF000000 | ((dp_paged_reg_bases[port]
 * + register number) << 2). The page-select and window registers are then written back to what they were.
 * Called by dp_init_port_registers, dp_apply_port_record and dp_set_lane_option_bit.
 */
void dp_paged_reg_update_bits(unsigned char port, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char saved_sel0_low = PAGE_SELECT_RX0_LOW;
    unsigned char saved_sel0_bit8 = PAGE_SELECT_RX0_BIT8;
    unsigned char saved_sel1_low = PAGE_SELECT_RX1_LOW;
    unsigned char saved_sel1_bit8 = PAGE_SELECT_RX1_BIT8;
    unsigned char saved_block = WINDOW_BLOCK;
    unsigned char saved_index = WINDOW_INDEX;
    unsigned int value;
    unsigned char new_value;
    unsigned short page_mask;

    if (port < 2) {
        page_mask = 1 << ((reg & 0xff00) >> 8);
        switch (port) {
        case 0:
            PAGE_SELECT_RX0_LOW = (unsigned char)page_mask;
            PAGE_SELECT_RX0_BIT8 = (page_mask >> 8) & 1;
            break;
        case 1:
            PAGE_SELECT_RX1_LOW = (unsigned char)page_mask;
            PAGE_SELECT_RX1_BIT8 = (page_mask >> 8) & 1;
            break;
        }
        if (port == 0)
            WINDOW_BLOCK = 0x85;
        else
            WINDOW_BLOCK = 0x86;
        reg &= 0xff;
        WINDOW_INDEX = (unsigned char)reg;
        WINDOW_DATA;
        value = WINDOW_DATA;
        if (mode == 1)
            new_value = value | mask;
        else
            new_value = value & ~mask;
        *(volatile unsigned int *)(((dp_paged_reg_bases[port] + (unsigned short)reg) * 4) | 0xcf000000) = new_value;
        PAGE_SELECT_RX0_LOW = saved_sel0_low;
        PAGE_SELECT_RX0_BIT8 = saved_sel0_bit8;
        PAGE_SELECT_RX1_LOW = saved_sel1_low;
        PAGE_SELECT_RX1_BIT8 = saved_sel1_bit8;
        WINDOW_BLOCK = saved_block;
        WINDOW_INDEX = saved_index;
        WINDOW_DATA;
    }
}
