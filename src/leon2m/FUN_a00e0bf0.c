/* leon2m FUN_a00e0bf0 @ 0xa00e0bf0-0xa00e0c68 (30 words).
 * Reads register addr of DDR PHY phy (0, 1 or 2; any other value is treated as 2) with FUN_a00e02ec(phy, addr) and
 * prints it with the debug format " read %s page%d [0x%02x]=0x%02x" (string 0x199608): the PHY name "ddrphy0",
 * "ddrphy1" or "ddrphy2", FUN_a00e02d8(addr), FUN_a00e02e4(addr) and the value.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e02d8(unsigned short);
extern unsigned int FUN_a00e02e4(unsigned short);
extern int FUN_a00e02ec(unsigned int, unsigned int);
extern const char s_001995f0[], s_001995f8[], s_00199600[], s_00199608[];

void FUN_a00e0bf0(unsigned char phy, unsigned short addr)
{
    const char *name;
    unsigned int page, reg;

    if (phy == 0)
        name = s_001995f0;
    else if (phy == 1)
        name = s_001995f8;
    else
        name = s_00199600;
    page = FUN_a00e02d8(addr);
    reg = FUN_a00e02e4(addr);
    FUN_a00df170(s_00199608, name, page, reg, FUN_a00e02ec(phy, addr));
}
