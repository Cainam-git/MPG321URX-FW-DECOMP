/* 8051_bank2 FUN_CODE_d10a @ 0xd10a  BYTE-EXACT under OPTIMIZE(8,SPEED) LARGE (first C, MATCH exact
 * None 177/177). Only caller: 0x7145 (LCALL d10a, no arguments, no return value used).
 * DUALFW tag update after a write: addr = base (32-bit, XDATA 0x042F) + (TagInfo.ValidRegionNext (0x0435) << 12)
 * + 0x0E00; FUN_CODE_c6ea(addr, 0xAA) (0xAA = the 'region valid' tag value that FUN_CODE_ce2a looks for), wait
 * FUN_CODE_d059(4000); then, when TagInfo.ValidRegionCurrent (0x0434) < 2, the same for the current region with
 * tag 0 (old region marked not valid) and another 4000-unit wait. (ce2a reads the tag at + 0xFFF; this one writes
 * at + 0xE00.)
 * addr is the LARGE local at XDATA 0x08EB (stored by ?C?LSTXDATA, reloaded for the call); c6ea's char parameter
 * is in its own XDATA parameter block (0x08F3). TagRegion = the same struct as in FUN_CODE_ce2a (0x0434 / 0x0435).
 * Tail 'LCALL d059; RET' is a real jump target (JNC 0xd1ba from the '< 2' test), no aid needed.
 * The form with the sum written straight into the call argument (no addr local) is 137 B (no XDATA local).
 */
struct TagRegion { unsigned char cur; unsigned char next; };
extern struct TagRegion xdata DAT_EXTMEM_0434;
extern unsigned long xdata DAT_EXTMEM_042f;
extern void FUN_CODE_c6ea(unsigned long addr, unsigned char v);
extern void FUN_CODE_d059(unsigned int t);
void FUN_CODE_d10a(void)
{
    unsigned long addr;
    addr = DAT_EXTMEM_042f + ((unsigned int)DAT_EXTMEM_0434.next << 12) + 0xe00;
    FUN_CODE_c6ea(addr, 0xaa);
    FUN_CODE_d059(0x0fa0);
    if (DAT_EXTMEM_0434.cur < 2) {
        addr = DAT_EXTMEM_042f + ((unsigned int)DAT_EXTMEM_0434.cur << 12) + 0xe00;
        FUN_CODE_c6ea(addr, 0);
        FUN_CODE_d059(0x0fa0);
    }
}
