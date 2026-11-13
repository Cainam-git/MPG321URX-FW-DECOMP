/* sys_ddr_dump_phy_reg  (FUN_a00e0bf0)
 *
 * Read a memory interface register and print it with the interface's name.
 * Name basis: derived - register read, then a print; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0bf0 @ 0xa00e0bf0-0xa00e0c68 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: the names of the three interfaces are read-only strings referenced by address.
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_reg_page_of(unsigned short);
extern unsigned int sys_ddr_identity(unsigned short);
extern int sys_ddr_phy_read(unsigned int, unsigned int);
extern const char s_001995f0[], s_001995f8[], s_00199600[];

/*
 * Read register addr of memory interface phy and print it as " read <name> page<page> [0x<reg>]=0x<value>",
 * where <name> is the interface's name string (phy 0, phy 1, any other number is taken as interface 2), <page>
 * is bits 8..11 of addr and <reg> the low byte. Nothing in the image calls it.
 */
void sys_ddr_dump_phy_reg(unsigned char phy, unsigned short addr)
{
    const char *name;
    unsigned int page, reg;

    if (phy == 0)
        name = s_001995f0;
    else if (phy == 1)
        name = s_001995f8;
    else
        name = s_00199600;
    page = sys_ddr_reg_page_of(addr);
    reg = sys_ddr_identity(addr);
    dbg_printf(" read %s page%d [0x%02x]=0x%02x\n", name, page, reg, sys_ddr_phy_read(phy, addr));
}
