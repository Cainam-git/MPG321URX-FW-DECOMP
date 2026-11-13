/* sys_ddr_phy_update_bits  (FUN_a00e05d8)
 *
 * Replace the masked bits of a register of a memory interface.
 * Name basis: proven - read, merge, write; optional read-back print
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: PHY_TAB fills the three block bases element by element. Every page switch is written as 'page
 * register write; PHY_TAB; cache store', the form the firmware executes in sys_ddr_phy_write; in this routine
 * the compiler drops the stores of those re-fills. The re-fill after the merge, the order 'PHY_TAB before the
 * offset before block_base' in the trace path, and the offset assignment before the first branch are as the
 * firmware has them. All register accesses are 'volatile unsigned long'.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_fatal_prefix(void);
extern unsigned char sys_ddr_phy_pages[];
extern unsigned int sys_ddr_register_trace_enabled; /* read-back trace switch */

/* Register blocks of the three memory interfaces, 0x400 bytes apart. */
#define PHY_TAB(t) ((t)[0] = 0xcf022800, (t)[1] = 0xcf022c00, (t)[2] = 0xcf023000)

/* Page register of a block: register 0xfe, word offset 0xfe * 4. */
#define PHY_PAGE_REG_OFFSET 0x3f8
#define PHY_PAGE_REG_NUMBER 0xfe

/*
 * Change only the bits of mask in one register of memory interface phy (0..2): the register becomes
 * (old & ~mask) | (val & mask).
 *
 * addr is a 12-bit register number: bits 8..11 are the page, the low byte is the register inside the page (see
 * sys_ddr_phy_write for the page register and its cached copy sys_ddr_phy_pages). An interface number above 2
 * prints a fatal error and the routine goes on regardless.
 *
 * Order: switch to the page of addr if the cache differs; read the register; merge; write it back. When the
 * register is the page register itself (low byte 0xfe) the merged value is the new page and is written only if
 * it differs from the cached page. When sys_ddr_register_trace_enabled is non-zero the register is read once more and
 * printed with the interface number, addr and the value read.
 */
void sys_ddr_phy_update_bits(int phy, unsigned int addr, unsigned int mask, unsigned int val)
{
    unsigned int block_base;
    unsigned int page = (addr >> 8) & 0xf;
    unsigned int reg = addr & 0xff;
    unsigned int value;
    unsigned int reg_offset;
    unsigned int base[3];

    if (phy > 2) {
        sys_ddr_print_step();
        sys_ddr_print_fatal_prefix();
        dbg_printf("phy_mask_set error: phy_id=%d\n", phy);
    }
    PHY_TAB(base);
    block_base = base[phy];
    reg_offset = reg * 4;
    if (sys_ddr_phy_pages[phy] != page) {
        *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = page;
        PHY_TAB(base);
        sys_ddr_phy_pages[phy] = page;
    }
    value = *(volatile unsigned long *)(block_base + reg_offset);
    value = (value & ~mask) | (val & mask);
    PHY_TAB(base);
    if (reg == PHY_PAGE_REG_NUMBER) {
        /* The merged value is the new page. */
        if (sys_ddr_phy_pages[phy] != value) {
            *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = value;
            sys_ddr_phy_pages[phy] = value;
        }
    } else {
        if (sys_ddr_phy_pages[phy] != page) {
            *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = page;
            PHY_TAB(base);
            sys_ddr_phy_pages[phy] = page;
        }
        *(volatile unsigned long *)(block_base + reg_offset) = value;
    }
    if (sys_ddr_register_trace_enabled != 0) {
        PHY_TAB(base);
        reg_offset = (addr & 0xff) * 4;
        block_base = base[phy];
        if (sys_ddr_phy_pages[phy] != page) {
            *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = page;
            PHY_TAB(base);
            sys_ddr_phy_pages[phy] = page;
        }
        value = *(volatile unsigned long *)(block_base + reg_offset);
        dbg_printf("phy_mask_set %d [0x%03x]=0x%02x\n", phy, addr, value);
    }
}
