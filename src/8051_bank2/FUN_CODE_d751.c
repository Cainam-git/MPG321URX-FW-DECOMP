/* 8051_bank2 FUN_CODE_d751 @ 0xd751  MATCH (OPTIMIZE(7,SPEED))
 * If XDATA 0x041C == 2: copies the 32-bit value at 0x0117 to 0x03EE and the 16-bit value at 0x011B to 0x040A.
 * Otherwise: copies 32 bits 0x03F2 -> 0x0414, one byte 0x03F6 -> 0x0429, 16 bits 0x03F7 -> 0x0150, and 32 bits
 * 0x03F9 -> 0x01DE and 0x03FD -> 0x0410. The 16-bit copies, declared 'unsigned int', produce the XCH sequence; the
 * byte and 32-bit copies produce direct MOVX sequences.
 */
extern unsigned long xdata DAT_EXTMEM_0117;
extern unsigned long xdata DAT_EXTMEM_03f2;
extern unsigned long xdata DAT_EXTMEM_03f9;
extern unsigned long xdata DAT_EXTMEM_03fd;
extern unsigned int xdata DAT_EXTMEM_011b;
extern unsigned char xdata DAT_EXTMEM_03f6;
extern unsigned int xdata DAT_EXTMEM_03f7;
extern unsigned char xdata DAT_EXTMEM_041c;
extern unsigned char xdata DAT_EXTMEM_0429;
extern unsigned int xdata DAT_EXTMEM_040a;
extern unsigned int xdata DAT_EXTMEM_0150;

void FUN_CODE_d751(void)
{
    if (DAT_EXTMEM_041c == 0x02) {
        *(unsigned long xdata *)0x3ee = DAT_EXTMEM_0117;
        DAT_EXTMEM_040a = DAT_EXTMEM_011b;
        return;
    }
    *(unsigned long xdata *)0x414 = DAT_EXTMEM_03f2;
    DAT_EXTMEM_0429 = DAT_EXTMEM_03f6;
    DAT_EXTMEM_0150 = DAT_EXTMEM_03f7;
    *(unsigned long xdata *)0x1de = DAT_EXTMEM_03f9;
    *(unsigned long xdata *)0x410 = DAT_EXTMEM_03fd;
}
