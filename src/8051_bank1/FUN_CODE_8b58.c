/* 8051_bank1 FUN_CODE_8b58 @ 0x8b58..0x8c5d (261 B)  SPI flash: erase one sector or block ("DoBlockErase")
 * (byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * Inputs: sector (R6:R7) = unit number, cmd (R5) = SPI erase opcode. Keil LARGE block: sector 0xA4B3, cmd 0xA4B5,
 * addr 0xA4B6..0xA4B9, sr[] 0xA4BA.. (status bytes, filled by FUN_CODE_7765, handed to FUN_CODE_b456).
 * Steps: printf "DoBlockErase start %04x\r\n" (bank 1 string 0xA33B) with sector; FUN_CODE_dc51 (bracket start);
 * FUN_CODE_7765(sr) saves the status registers; Write Enable (FUN_CODE_d5f3(0x06)) and wait until Read Status
 * (FUN_CODE_cf73(0x05)) shows WEL (bit 1); byte address = sector << 12 for cmd 0x20 (4 KB sector erase),
 * << 15 for cmd 0x52 (32 KB block erase), << 16 for any other cmd (64 KB block erase, 0xD8); SPI controller set-up
 * as in FUN_CODE_9b11 (0xF1C0 = 0x80, mode (0xF0E6 & 0x0C) | 0x41, 0xF0F4 = 3, 0xF0EB/EC/ED = 0/0/3, opcode in
 * 0xF0EE, 0xF1C0 = 0x82, three address bytes high to low into 0xF1C3, 0xF1C0 = 0x84, start 0xF0E5 = 1 and wait
 * for bit 0 clear); wait while WIP (status bit 0); printf "sector erase\t%04lX!!\r\n" (0xA355) with the address;
 * FUN_CODE_b456(sr) writes the saved status back; FUN_CODE_dc67 (bracket end, tail jump).
 * This function erases flash.
 * Keil note: the if / else if / else chain (not a switch) gives cmd in R3 with CJNE + SJMP per arm.
 * sr[] is 12 bytes: the gap up to 0xA4C6, where the callees' blocks start.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee;
extern unsigned char volatile xdata DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3;
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_dc67(void);
extern void FUN_CODE_d5f3(unsigned char cmd);
extern unsigned char FUN_CODE_cf73(unsigned char cmd);
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_7765(unsigned char *p);
extern void FUN_CODE_b456(unsigned char *p);

void FUN_CODE_8b58(unsigned int sector, unsigned char cmd)
{
    unsigned long addr;
    unsigned char sr[12];

    FUN_CODE_2820((void code *)0xa33b, sector);
    FUN_CODE_dc51();
    FUN_CODE_7765(sr);
    FUN_CODE_d5f3(6);
    while (!(FUN_CODE_cf73(5) & 2)) ;
    if (cmd == 0x20) addr = (unsigned long)sector << 12;
    else if (cmd == 0x52) addr = (unsigned long)sector << 15;
    else addr = (unsigned long)sector << 16;
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
    FUN_CODE_2820((void code *)0xa355, addr);
    FUN_CODE_b456(sr);
    FUN_CODE_dc67();
}
