/* 8051_bank0 FUN_CODE_16db @ 0x16db  STBC boot loader: SPI flash command with one data byte (built
 * with OPTIMIZE(7,SPEED)).
 * FIFO-mode write of opcode cmd (R7) plus one data byte val (R5): 0xF1C0 = 0x80 (FIFO reset), 0xF0E6 = (0xF0E6 &
 * 0x0C) | 0x41, 0xF0F4 = 0x03 (transfer type), length 0xF0EB..0xF0ED = 00 00 01, 0xF0EE = cmd, 0xF1C0 = 0x82 (FIFO
 * write), 0xF1C3 = val (FIFO data), 0xF1C0 = 0x84, 0xF0E5 = 1 (start), wait while 0xF0E5 bit 0 is set. Used for 0xC5
 * Write Extended Address Register by FUN_CODE_180d (SetExtendedAddr).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ee, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0e5;
extern unsigned char volatile xdata DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3, DAT_EXTMEM_f00a, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0ef;
void FUN_CODE_1873(unsigned char n);

void FUN_CODE_16db(unsigned char cmd, unsigned char val)
{
    unsigned char t;
    DAT_EXTMEM_f1c0 = 0x80;
    t = DAT_EXTMEM_f0e6 & 0x0c;
    t |= 0x41;
    DAT_EXTMEM_f0e6 = t;
    DAT_EXTMEM_f0f4 = 0x03;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 1;
    DAT_EXTMEM_f0ee = cmd;
    DAT_EXTMEM_f1c0 = 0x82;
    DAT_EXTMEM_f1c3 = val;
    DAT_EXTMEM_f1c0 = 0x84;
    DAT_EXTMEM_f0e5 = 1;
    while ((int)(DAT_EXTMEM_f0e5 & 1)) FUN_CODE_1873(10);
}
