/* 8051_bank1 FUN_CODE_bc3d @ 0xbc3d (112 B)  Byte-exact with OPTIMIZE(7,SPEED).
 * Runs in register bank 3 ('using 3'); only caller is the interrupt handler FUN_CODE_3091 (0x30B3).
 * Latches the 16-bit count from XDATA 0xF028 (high) / 0xF027 (low) into IDATA 0x5E..0x5F and computes
 * (0xFFFF - count) / 75 (?C?UIDIV) into IDATA 0x5B, or 0xFF for a zero count. Then writes 0xFF to 0xF027 and 0xF028
 * and, when FUN_CODE_d862() returns 0, appends 0x5B to the 128-byte ring buffer XDATA 0xA566 at index 0xA564
 * (wraps at 0x80; FUN_CODE_d697 reads it with index 0xA565).
 * IDATA 0x5E and 0x5B are volatile (written in interrupt context): the firmware reads 0x5E back right after storing
 * it, and stores the result into 0x5B twice ('MOV @R0,A' two times), which is the chained assignment
 * '5B = 5B = value' on a volatile byte.
 */
extern unsigned char xdata DAT_EXTMEM_f027, DAT_EXTMEM_f028, DAT_EXTMEM_a564;
extern unsigned char xdata DAT_EXTMEM_a566[];
extern unsigned int volatile idata DAT_INTMEM_5e;
extern unsigned char volatile idata DAT_INTMEM_5b;
unsigned char FUN_CODE_d862(void);

void FUN_CODE_bc3d(void) using 3
{
    unsigned int v;

    DAT_INTMEM_5e = ((unsigned int)DAT_EXTMEM_f028 << 8) + DAT_EXTMEM_f027;
    v = DAT_INTMEM_5e;
    if (v > 0)
        DAT_INTMEM_5b = DAT_INTMEM_5b = (0xffff - v) / 75;
    else
        DAT_INTMEM_5b = 0xff;
    DAT_EXTMEM_f027 = 0xff;
    DAT_EXTMEM_f028 = 0xff;
    if (FUN_CODE_d862() == 0) {
        DAT_EXTMEM_a566[DAT_EXTMEM_a564] = DAT_INTMEM_5b;
        DAT_EXTMEM_a564++;
        if (DAT_EXTMEM_a564 == 0x80) DAT_EXTMEM_a564 = 0;
    }
}
