/* 8051_bank0 FUN_CODE_172d @ 0x172d  STBC boot loader: SPI flash command returning one byte
 * (byte-exact with OPTIMIZE(7,SPEED)).
 * 0xF00A = 0x55, 0xF1C0 = 0 (FIFO off), 0xF0EA = cmd (read opcode register), 0xF0E6 = (0xF0E6 & 0x0C) | 0x41,
 * length 0xF0EB..0xF0ED = 0, 0xF0F4 = 0x07 (read-one-byte transfer), 0xF0E5 = 2 (start read), wait while 0xF0E5
 * bit 1 is set, return 0xF0EF (the byte read). Used with 0x05 Read Status Register (bit 0 WIP, bit 1 WEL) by
 * FUN_CODE_180d and the bus-mode set-up FUN_CODE_0c83.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ee, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0e5;
extern unsigned char volatile xdata DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3, DAT_EXTMEM_f00a, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0ef;
void FUN_CODE_1873(unsigned char n);

unsigned char FUN_CODE_172d(unsigned char cmd)
{
    unsigned char t;
    DAT_EXTMEM_f00a = 0x55;
    DAT_EXTMEM_f1c0 = 0;
    DAT_EXTMEM_f0ea = cmd;
    t = DAT_EXTMEM_f0e6 & 0x0c;
    t |= 0x41;
    DAT_EXTMEM_f0e6 = t;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 0;
    DAT_EXTMEM_f0f4 = 0x07;
    DAT_EXTMEM_f0e5 = 2;
    while ((int)(DAT_EXTMEM_f0e5 & 2)) FUN_CODE_1873(10);
    return DAT_EXTMEM_f0ef;
}
