/* sys_ddr_phy_read_masked  (FUN_a00e0514)
 *
 * Read a register of a memory interface and return it masked.
 * Returns: masked value
 * Name basis: proven - page select through a cached page byte
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0514 @ 0xa00e0514-0xa00e05d8 (49 words), flags -mcpu=v8 -O3, built without -g (no nop after the
 * last call).
 * Source form: same form as sys_ddr_phy_read. PHY_TAB is repeated after the page-register write and the compiler
 * removes the stores of that re-fill as repeats. The register accesses are 'volatile unsigned long'; the offset
 * reg * 4 is computed before the page test.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_fatal_prefix(void);
extern unsigned char sys_ddr_phy_pages[];
extern unsigned int sys_ddr_register_trace_enabled;       /* read-back trace switch */

/* Register blocks of the three memory interfaces, 0x400 bytes apart. */
#define PHY_TAB(t) ((t)[0] = 0xcf022800, (t)[1] = 0xcf022c00, (t)[2] = 0xcf023000)

/* Page register of a block: register 0xfe, word offset 0xfe * 4. */
#define PHY_PAGE_REG_OFFSET 0x3f8

/*
 * Read one register of memory interface phy (0..2) and return only the bits of mask (value & mask).
 *
 * addr is a 12-bit register number: bits 8..11 are the page, the low byte is the register inside the page; the
 * page is switched first when the cached page differs (see sys_ddr_phy_write). An interface number above 2
 * prints a fatal error and the routine goes on regardless. When sys_ddr_register_trace_enabled is non-zero the masked value is
 * printed with the interface number and addr.
 */
unsigned int sys_ddr_phy_read_masked(int phy, unsigned int addr, unsigned int mask)
{
    unsigned int block_base;
    unsigned int page = (addr >> 8) & 0xf;
    unsigned int reg = addr & 0xff;
    unsigned int value;
    unsigned int reg_offset;

    if (phy > 2) {
        sys_ddr_print_step();
        sys_ddr_print_fatal_prefix();
        dbg_printf("phy_mask_get error: phy_id=%d\n", phy);
    }
    {
        unsigned int base[3];

        PHY_TAB(base);
        block_base = base[phy];
        reg_offset = reg * 4;
        if (sys_ddr_phy_pages[phy] != page) {
            *(volatile unsigned long *)(block_base + PHY_PAGE_REG_OFFSET) = page;
            PHY_TAB(base);
            sys_ddr_phy_pages[phy] = page;
        }
        value = *(volatile unsigned long *)(block_base + reg_offset) & mask;
    }
    if (sys_ddr_register_trace_enabled != 0)
        dbg_printf("phy_mask_get %d [0x%03x]=0x%02x\n", phy, addr, value);
    return value;
}
