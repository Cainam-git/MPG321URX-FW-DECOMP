/* 8051_bank1 FUN_CODE_9b11 @ 0x9b11..0x9bde (205 B)  SPI flash: erase one 4 KB sector ("sector erase")
 * (OPTIMIZE(8,SPEED) LARGE).
 * Inputs: sector (R6:R7) = 4 KB sector number, cmd (R5) = SPI erase opcode. Keil LARGE block: sector 0xA4BA,
 * cmd 0xA4BC, addr 0xA4BD..0xA4C0.
 * Steps: FUN_CODE_dc51 (bracket start); Write Enable (FUN_CODE_d5f3(0x06)), wait until Read Status
 * (FUN_CODE_cf73(0x05)) shows WEL (bit 1); byte address = sector << 12 whatever cmd is (the three arms for
 * 0x20 / 0x52 / other are identical here, unlike the sibling FUN_CODE_8b58 which shifts by 12/15/16);
 * 0xF1C0 = 0x80, mode (0xF0E6 & 0x0C) | 0x41, 0xF0F4 = 3, 0xF0EB/EC/ED = 0/0/3, opcode into 0xF0EE,
 * 0xF1C0 = 0x82, address bytes 23..0 into 0xF1C3, 0xF1C0 = 0x84, start 0xF0E5 = 1, wait for bit 0 clear;
 * wait while WIP (status bit 0); printf "sector erase\t%04lX!!\r\n" (bank 1 string 0xC919) with the address;
 * FUN_CODE_dc67 (bracket end, tail jump).
 * This ERASES flash (update path only).
 * No-code aid: the firmware's last arm re-reads cmd from XDATA (0x9B3D: MOV DPTR,#0xA4BC; MOVX A,@DPTR)
 * and drops the value before the shared shift code. A volatile read of the local reproduces it with no change in behaviour (it reads this function's own
 * parameter slot only). Without it Keil merges the 0x52 and default arms and the file is 196 B.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee;
extern unsigned char volatile xdata DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3;
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_dc67(void);
extern void FUN_CODE_d5f3(unsigned char cmd);
extern unsigned char FUN_CODE_cf73(unsigned char cmd);
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_9b11(unsigned int sector, unsigned char cmd)
{
    unsigned long addr;

    FUN_CODE_dc51();
    FUN_CODE_d5f3(6);
    while (!(FUN_CODE_cf73(5) & 2)) ;
    if (cmd == 0x20) addr = (unsigned long)sector << 12;
    else if (cmd == 0x52) addr = (unsigned long)sector << 12;
    else { *(unsigned char volatile xdata *)&cmd; addr = (unsigned long)sector << 12; }
    DAT_EXTMEM_f1c0 = 0x80;
    DAT_EXTMEM_f0e6 = DAT_EXTMEM_f0e6 & 0x0c | 0x41;
    DAT_EXTMEM_f0f4 = 3;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 3;
    DAT_EXTMEM_f0ee = cmd;
    DAT_EXTMEM_f1c0 = 0x82;
    DAT_EXTMEM_f1c3 = ((unsigned char *)&addr)[1];
    DAT_EXTMEM_f1c3 = ((unsigned char *)&addr)[2];
    DAT_EXTMEM_f1c3 = ((unsigned char *)&addr)[3];
    DAT_EXTMEM_f1c0 = 0x84;
    DAT_EXTMEM_f0e5 = 1;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 1)) ;
    while (FUN_CODE_cf73(5) & 1) ;
    FUN_CODE_2820((void code *)0xc919, addr);
    FUN_CODE_dc67();
}
