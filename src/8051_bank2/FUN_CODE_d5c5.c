/* 8051_bank2 FUN_CODE_d5c5 @ 0xd5c5 (135 B).
 * Callers (byte scan, xref.py): FUN_CODE_6e16 (0x6ff3), LCALL at 0x8f8c (outside any functions.json entry).
 * Code: bit 0x0C = 0. If XDATA 0x041C == 2: bit 0x0B = 0, 0x042C = 0. Else: 0x0414 = 0x0418 (ulong),
 * 0x0410 = 0x0418 * 4 (?C?LMUL FUN_CODE_32f5), 0x01DE = 0x0418 * 4 / (uint at 0x042A) (?C?ULDIV FUN_CODE_3380,
 * the product computed again), 0x0150 (uint) = 0, 0x0429 = 0. Both arms end with 0x0409 = 0.
 * Form: 0x0409 = 0 written in each arm (Keil cross-jumps the shared MOVX / MOV DPTR,#0409 / MOVX / RET tail);
 * one store after the if gives 137 B. 0x0429 is declared uchar here (only the byte at
 * 0x0429 is written). No aids.
 */
extern bit DAT_BIT_000b;
extern bit DAT_BIT_000c;
extern unsigned char xdata DAT_EXTMEM_041c;
extern unsigned char xdata DAT_EXTMEM_042c;
extern unsigned char xdata DAT_EXTMEM_0429;
extern unsigned char xdata DAT_EXTMEM_0409;
extern unsigned int xdata DAT_EXTMEM_042a;
extern unsigned int xdata DAT_EXTMEM_0150;
extern unsigned long xdata DAT_EXTMEM_0410;
extern unsigned long xdata DAT_EXTMEM_0414;
extern unsigned long xdata DAT_EXTMEM_0418;
extern unsigned long xdata DAT_EXTMEM_01de;
void FUN_CODE_d5c5(void)
{
    DAT_BIT_000c = 0;
    if (DAT_EXTMEM_041c == 2) {
        DAT_BIT_000b = 0;
        DAT_EXTMEM_042c = 0;
        DAT_EXTMEM_0409 = 0;
    } else {
        DAT_EXTMEM_0414 = DAT_EXTMEM_0418;
        DAT_EXTMEM_0410 = DAT_EXTMEM_0418 * 4;
        DAT_EXTMEM_01de = DAT_EXTMEM_0418 * 4 / DAT_EXTMEM_042a;
        DAT_EXTMEM_0150 = 0;
        DAT_EXTMEM_0429 = 0;
        DAT_EXTMEM_0409 = 0;
    }
}
