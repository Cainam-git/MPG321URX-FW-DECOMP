/* 8051_bank0 FUN_CODE_1491 @ 0x1491  STBC boot loader: streaming SPI flash read through the FIFO
 * (OPTIMIZE(8,SPEED)).
 * FUN_CODE_1491(op R7, addr @0x48 (32-bit, big-endian), n @0x4C, dst generic pointer @0x4D): read opcode 0xF0EA =
 * op; 0xF0E6 = (0xF0E6 & 0x0C) | 1 (stream mode, bus-mode bits kept); 0xF0F4 = 0x0B; transfer length
 * 0xF0EB..0xF0ED = 00 02 00, i.e. the controller always fetches 512 bytes whatever n is; address bytes 0xF0F0 =
 * addr >> 24, 0xF0F1 = addr >> 16, 0xF0F2 = low byte: bits 15..8 of the address are never written (a latent bug,
 * harmless because both callers pass address 0; same observation in the public MPG 341CQPX write-up). 0xF1C0 =
 * 0x81, start 0xF0E5 = 2, wait until bit 1 clears; 0xF1C0 = 0x82, one byte read from the FIFO 0xF1C0 and dropped,
 * then n bytes from 0xF1C0 to dst. Caller: the bus-mode check FUN_CODE_0c83 (opcode 0x6B quad / 0x3B dual,
 * 10 bytes from address 0 into IDATA 0x3D, compared with CODE 0x0000..0x0009).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0ea, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0f4, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed;
extern unsigned char volatile xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2, DAT_EXTMEM_f1c0, DAT_EXTMEM_f0e5;
void FUN_CODE_1491(unsigned char op, unsigned long addr, unsigned char n, unsigned char *dst)
{
    unsigned char t;
    unsigned char first;    /* first FIFO byte, read and dropped */
    DAT_EXTMEM_f0ea = op;
    t = DAT_EXTMEM_f0e6 & 0x0c;
    t |= 0x01;
    DAT_EXTMEM_f0e6 = t;
    DAT_EXTMEM_f0f4 = 0x0b;
    DAT_EXTMEM_f0eb = 0x00;
    DAT_EXTMEM_f0ec = 0x02;
    DAT_EXTMEM_f0ed = 0x00;
    DAT_EXTMEM_f0f0 = addr >> 24;
    DAT_EXTMEM_f0f1 = addr >> 16;
    DAT_EXTMEM_f0f2 = (unsigned int)(addr & 0xff);
    DAT_EXTMEM_f1c0 = 0x81;
    DAT_EXTMEM_f0e5 = 0x02;
    while ((int)(DAT_EXTMEM_f0e5 & 0x02));
    DAT_EXTMEM_f1c0 = 0x82;
    first = DAT_EXTMEM_f1c0;
    do {
        *dst++ = DAT_EXTMEM_f1c0;
    } while (--n);
}
