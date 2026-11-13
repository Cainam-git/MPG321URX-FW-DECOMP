/* dp_paged_reg_read8  (FUN_a00a74b8)
 *
 * Read a paged register of a DP receiver through the register window.
 *   port: DP receiver 0/1
 *   reg: register
 * Returns: byte
 * Note: reg: high byte = page 0..8 (one-hot in 0xCF03D014..20), low byte = register; window value 0x85 / 0x86
 *   selects receiver 0 / 1.
 * Name basis: derived - page mask 1 << (reg >> 8) in 0xCF03D014.., window 0xCF01142C, index 0xCF011430, data
 *   0xCF011434; saves and restores them; caller dp_read_lane_status
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a74b8 @ 0xa00a74b8-0xa00a7614 (-mcpu=v8 -Os -g).
 * Source form: page_mask is an unsigned short and its low byte is stored as '(unsigned char)page_mask'; the
 * data register is read twice (the second value kept) and once more after the restore.
 */
#define PAGE_SELECT_RX0_LOW  (*(volatile unsigned int *)0xcf03d014) /* receiver 0: bits 0..7 of the page mask */
#define PAGE_SELECT_RX0_BIT8 (*(volatile unsigned int *)0xcf03d018) /* receiver 0: bit 8 of the page mask */
#define PAGE_SELECT_RX1_LOW  (*(volatile unsigned int *)0xcf03d01c) /* receiver 1: bits 0..7 */
#define PAGE_SELECT_RX1_BIT8 (*(volatile unsigned int *)0xcf03d020) /* receiver 1: bit 8 */
#define WINDOW_BLOCK         (*(volatile unsigned int *)0xcf01142c) /* 0x85 for receiver 0, 0x86 for receiver 1 */
#define WINDOW_INDEX         (*(volatile unsigned int *)0xcf011430) /* low byte of the register number */
#define WINDOW_DATA          (*(volatile unsigned int *)0xcf011434) /* value of the selected register */

/*
 * Read one register of a DP receiver that sits behind the page and window registers.
 *   port: DP receiver 0 or 1 (any other value returns 0 and touches nothing)
 *   reg:  high byte = page number 0..8, low byte = register number inside the page
 * Returns the register byte.
 *
 * The page number is turned into a one-hot mask (1 << page) and written to the receiver's two page-select
 * registers (bits 0..7, then bit 8). Then the window is pointed at the receiver (0x85 or 0x86), the register
 * number is written to the index register and the data register is read; the first read is dropped and the
 * second is the result. All the page-select and window registers are saved before and written back after,
 * so the caller sees no change.
 * Called by dp_read_lane_status and dp_apply_port_record.
 */
unsigned int dp_paged_reg_read8(unsigned char port, unsigned short reg)
{
    unsigned char saved_sel0_low = PAGE_SELECT_RX0_LOW;
    unsigned char saved_sel0_bit8 = PAGE_SELECT_RX0_BIT8;
    unsigned char saved_sel1_low = PAGE_SELECT_RX1_LOW;
    unsigned char saved_sel1_bit8 = PAGE_SELECT_RX1_BIT8;
    unsigned char saved_block = WINDOW_BLOCK;
    unsigned char saved_index = WINDOW_INDEX;
    unsigned int value = 0;
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
        WINDOW_INDEX = (unsigned char)reg;
        WINDOW_DATA;
        value = WINDOW_DATA;
        WINDOW_INDEX = saved_index;
        WINDOW_BLOCK = saved_block;
        PAGE_SELECT_RX0_LOW = saved_sel0_low;
        PAGE_SELECT_RX0_BIT8 = saved_sel0_bit8;
        PAGE_SELECT_RX1_LOW = saved_sel1_low;
        PAGE_SELECT_RX1_BIT8 = saved_sel1_bit8;
        WINDOW_DATA;
        value &= 0xff;
    }
    return value;
}
