/* 8051_bank0 FUN_CODE_17af @ 0x17af  STBC boot loader: SPI flash command without data (byte-exact
 * with OPTIMIZE(7,SPEED)).
 * Sends one opcode (cmd in R7) to the SPI flash through the scaler's SPI controller: XDATA 0xF0E6 = (0xF0E6 & 0x0C) |
 * 0x41 (keeps the bus-mode bits 2-3, selects plain command mode), 0xF0EE = opcode, 0xF0EB..0xF0ED = 0 (no address /
 * length), 0xF0E5 = 1 (start), then waits while 0xF0E5 bit 0 (busy) is set, 10 delay units (FUN_CODE_1873) per poll.
 * Used for 0x06 Write Enable by FUN_CODE_180d. Register meanings as described in the public MPG 341CQPX boot loader
 * write-up (same boot code); the busy test is written with an int cast because that is what produces the
 * original's ANL A,#1 / JZ instead of JNB ACC.0.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ee, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0e5;
extern unsigned char volatile xdata DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3, DAT_EXTMEM_f00a, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0ef;
void FUN_CODE_1873(unsigned char n);

void FUN_CODE_17af(unsigned char cmd)
{
    unsigned char t;
    t = DAT_EXTMEM_f0e6 & 0x0c;
    t |= 0x41;
    DAT_EXTMEM_f0e6 = t;
    DAT_EXTMEM_f0ee = cmd;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 0;
    DAT_EXTMEM_f0e5 = 1;
    while ((int)(DAT_EXTMEM_f0e5 & 1)) FUN_CODE_1873(10);
}
