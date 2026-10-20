/* 8051_bank2 FUN_CODE_ce2a @ 0xce2a  MATCH (OPTIMIZE(8,SPEED) LARGE, hand)
 *
 * DUALFW slot pick: find which of the two firmware regions carries the valid tag.
 * FUN_CODE_e27c(0), then for slot i = 0, 1: FUN_CODE_d53d(base + (i << 12) + 0xFFF) with the 32-bit base at XDATA
 * 0x042F (sets the address on the service-bus slave 0x6E), wait FUN_CODE_d059(100), read 1 byte from slave 0x6E
 * with FUN_CODE_cd68(0x6E, &tag, 1). Tag 0xAA = slot i is valid: TagInfo.ValidRegionCurrent (XDATA 0x0434) = i,
 * stop. If neither slot has it, Current = 0 (set on the i == 1 pass). Then ValidRegionNext (0x0435) =
 * (Current + 1) wrapped to 0 at 2, and both are printed with printf FUN_CODE_65ab (strings CODE 0xCB10
 * "TagInfo.ValidRegionNext = %d\r\n", 0xCB2F "TagInfo.ValidRegionCurrent = %d\r\n"; int arguments in its XDATA
 * block at 0x0989). Locals i / tag sit in this function's LARGE-model XDATA block 0x08EE / 0x08EF.
 * 0x0434 / 0x0435 are reached with one INC DPTR, so they are declared as one object (TagRegion).
 * Update path: chooses the region the next update is written to (ref-8051.md: DUALFW is off in both MSI images).
 */
struct TagRegion { unsigned char cur; unsigned char next; };
extern struct TagRegion xdata DAT_EXTMEM_0434;
extern unsigned long xdata DAT_EXTMEM_042f;
extern void FUN_CODE_e27c(unsigned char a);
extern void FUN_CODE_d53d(unsigned long addr);
extern void FUN_CODE_d059(unsigned int t);
extern void FUN_CODE_cd68(unsigned char dev, unsigned char *buf, unsigned int n);
extern void FUN_CODE_65ab(void *fmt, ...) large;

void FUN_CODE_ce2a(void)
{
    unsigned char i;
    unsigned char tag;
    FUN_CODE_e27c(0);
    for (i = 0; i < 2; i++) {
        FUN_CODE_d53d(DAT_EXTMEM_042f + ((unsigned int)i << 12) + 0xfff);
        FUN_CODE_d059(100);
        FUN_CODE_cd68(0x6e, &tag, 1);
        if (tag == 0xaa) {
            DAT_EXTMEM_0434.cur = i;
            break;
        }
        if (i == 1) DAT_EXTMEM_0434.cur = 0;
    }
    DAT_EXTMEM_0434.next = DAT_EXTMEM_0434.cur + 1;
    if (DAT_EXTMEM_0434.next >= 2) DAT_EXTMEM_0434.next = 0;
    FUN_CODE_65ab((void code *)0xcb10, (unsigned int)DAT_EXTMEM_0434.next);
    FUN_CODE_65ab((void code *)0xcb2f, (unsigned int)DAT_EXTMEM_0434.cur);
}
