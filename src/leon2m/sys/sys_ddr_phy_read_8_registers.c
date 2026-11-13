/* sys_ddr_phy_read_8_registers  (FUN_a00e0b00)
 *
 * Read 8 registers in a row of page 3 of a memory interface and return them as one 64-bit value.
 * Returns: 64-bit value, register i in bits 8i..8i+7
 * Note: First register = low byte of sys_ddr_rd_deskew_result_regs[idx]; no mask is applied.
 * Name basis: descriptive - loop of 8 reads shifted by 8 * i; called by sys_ddr_check_gate_fields
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0b00 @ 0xa00e0b00-0xa00e0ba8 (42 words), flags -mcpu=v8 -O3 -g (the 64-bit shift is a call to
 * __ashldi3).
 * Source form: PHY_TAB assigns the three elements of base[] directly and is repeated after the page-register write
 * as in sys_ddr_phy_read (the compiler removes the stores of the re-fill as repeats). p is computed from base[phy]
 * directly and block_base = base[phy] is read again after it (the firmware order at 0xa00e0b3c-0xa00e0b4c: add of
 * the table address, ldub of the cache byte, sll of the offset, then ld of the base); page = 3 is a local used
 * for the test, the write and the cache store.
 */
extern unsigned int sys_ddr_rd_deskew_result_regs[];
extern unsigned char sys_ddr_phy_pages[];

/* Register blocks of the three memory interfaces, 0x400 bytes apart. */
#define PHY_TAB(t) ((t)[0] = 0xcf022800, (t)[1] = 0xcf022c00, (t)[2] = 0xcf023000)

/* Page register of a block: register 0xfe, word offset 0xfe * 4. */
#define PHY_PAGE_REG_OFFSET 0x3f8

/*
 * Read 8 consecutive registers of page 3 of memory interface phy (0..2) and join them into one 64-bit value:
 * the register i of the run is shifted left by 8 * i bits and the shifted words are ORed together. The first
 * register is the low byte of sys_ddr_rd_deskew_result_regs[idx]. Switches to page 3 first when the cached page
 * differs. Called by sys_ddr_check_gate_fields.
 */
unsigned long long sys_ddr_phy_read_8_registers(int phy, int idx)
{
    unsigned char first_reg = sys_ddr_rd_deskew_result_regs[idx];
    unsigned int base[3];
    unsigned int block_base;
    unsigned int reg_addr;
    unsigned long long value;
    unsigned int i;
    unsigned int page;

    PHY_TAB(base);
    reg_addr = base[phy] + first_reg * 4;
    block_base = base[phy];
    value = 0;
    i = 0;
    page = 3;
    if (sys_ddr_phy_pages[phy] != page) {
        *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = page;
        PHY_TAB(base);
        sys_ddr_phy_pages[phy] = page;
    }
    for (; i < 8; i++)
        value |= (unsigned long long)*(volatile unsigned long *)((reg_addr + (i << 2))) << (i * 8);
    return value;
}
