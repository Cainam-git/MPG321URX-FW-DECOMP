/* sys_ddr_phy_write  (FUN_a00e03b0)
 *
 * Write a register of a memory interface.
 * Name basis: proven - page select through a cached page byte; optional read-back print
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: PHY_TAB fills the three block bases element by element, and is repeated where the firmware repeats
 * it. In the write path a page that is already selected skips the page switch with 'goto write' (the firmware
 * branches over the page-register write, the re-fill and the cache store). After the page-register write the
 * re-fill is executed by the firmware; in the trace path the same re-fill sits before the page-register write and
 * the compiler drops its stores as repeats. The offset is computed once before the first branch. All register
 * accesses are 'volatile unsigned long'.
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
 * Write one register of memory interface phy (0..2).
 *
 * addr is a 12-bit register number: bits 8..11 are the page, the low byte is the register inside the page.
 * The registers of a block are 32-bit words, register n at block base + n * 4. The block has a page register
 * (register 0xfe) that selects which page the other registers show; sys_ddr_phy_pages keeps a copy of it per
 * interface so the page register is only written when the page changes.
 *
 * Order: an interface number above 2 prints a fatal error with the number and goes on regardless. Then, if the
 * register is the page register itself, val is written there only when it differs from the cached page (and the
 * cache is set to val). Any other register: switch to its page if the cache differs, then write val.
 * When sys_ddr_register_trace_enabled is non-zero the register is read back (switching page again if needed) and
 * printed with the interface number, addr and the value read.
 */
void sys_ddr_phy_write(int phy, unsigned int addr, unsigned int val)
{
    unsigned int block_base;
    unsigned int page = (addr >> 8) & 0xf;
    unsigned int reg = addr & 0xff;
    unsigned char cached_page;
    unsigned int readback;
    unsigned int reg_offset;
    unsigned int base[3];

    if (phy > 2) {
        sys_ddr_print_step();
        sys_ddr_print_fatal_prefix();
        dbg_printf("phy_write error: phy_id=%d\n", phy);
    }
    PHY_TAB(base);
    block_base = base[phy];
    reg_offset = reg * 4;
    if (reg == PHY_PAGE_REG_NUMBER) {
        /* Writing the page register directly: val is the new page. */
        if (sys_ddr_phy_pages[phy] != val) {
            *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = val;
            sys_ddr_phy_pages[phy] = val;
        }
    } else {
        if (sys_ddr_phy_pages[phy] == page)
            goto write;
        *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = page;
        PHY_TAB(base);
        sys_ddr_phy_pages[phy] = page;
    write:
        *(volatile unsigned long *)(block_base + reg_offset) = val;
    }
    if (sys_ddr_register_trace_enabled != 0) {
        reg_offset = (addr & 0xff) * 4;
        cached_page = sys_ddr_phy_pages[phy];
        PHY_TAB(base);
        block_base = base[phy];
        if (cached_page != page) {
            PHY_TAB(base);
            block_base = base[phy];
            *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = page;
            sys_ddr_phy_pages[phy] = page;
        }
        readback = *(volatile unsigned long *)(block_base + reg_offset);
        dbg_printf("phy_write %d [0x%03x]=0x%02x\n", phy, addr, readback);
    }
}
