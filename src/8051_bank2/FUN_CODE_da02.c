/* 8051_bank2 FUN_CODE_da02 @ 0xda02 (100 B).
 * Callers (byte scan, xref.py): FUN_CODE_60b9 (0x6533), FUN_CODE_b706 (0xb83f).
 * Code: printf FUN_CODE_65ab("USB_PHY0_CTRL52= %X\r\n" at CODE 0xE48E, XDATA 0x5052 as unsigned int); then if
 * XDATA 0x09CC < 0x20: 0x5050 |= 0x20, 0x5052 = ((0x5052 | 0x60) & 0xE0) | 0x09CC, 0x5051 = 0x20, e44b(1),
 * 0x5051 = 0; else 0x5050 &= ~0x20, 0x5052 = 0x10. Then the same printf again (tail LJMP).
 * Form: 0x09CC is read once (kept in R5) and named twice in C; a local copy x makes Keil compute the OR the other
 * way round (98 B). 65ab declared as in the accepted bank-2 files. No aids, no volatile (each
 * register is read once per statement).
 */
extern unsigned char xdata DAT_EXTMEM_5050, DAT_EXTMEM_5051, DAT_EXTMEM_5052;
extern unsigned char xdata DAT_EXTMEM_09cc;
extern void FUN_CODE_65ab(void *fmt, ...) large;
void FUN_CODE_e44b(unsigned char t);
void FUN_CODE_da02(void)
{
    FUN_CODE_65ab((void code *)0xe48e, (unsigned int)DAT_EXTMEM_5052);
    if (DAT_EXTMEM_09cc < 0x20) {
        DAT_EXTMEM_5050 |= 0x20;
        DAT_EXTMEM_5052 = ((DAT_EXTMEM_5052 | 0x60) & 0xe0) | DAT_EXTMEM_09cc;
        DAT_EXTMEM_5051 = 0x20;
        FUN_CODE_e44b(1);
        DAT_EXTMEM_5051 = 0;
    } else {
        DAT_EXTMEM_5050 &= ~0x20;
        DAT_EXTMEM_5052 = 0x10;
    }
    FUN_CODE_65ab((void code *)0xe48e, (unsigned int)DAT_EXTMEM_5052);
}
