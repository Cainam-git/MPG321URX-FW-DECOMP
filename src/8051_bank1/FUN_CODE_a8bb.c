/* 8051_bank1 FUN_CODE_a8bb @ 0xa8bb..0xa958  window clear/fill job of the image-copy DMA.
 * FUN_CODE_a8bb(dst, len, mode): F602..F605 = dst (low byte first into F605, same registers as the copy routine
 * FUN_CODE_738c), F606..F609 = len / 4 (word count, ?C?ULDIV), then mode 0: F600 = 0x04 (start, no flash source
 * programmed), wait until F601 bit 7 is set, F601 = 0x80 (ack); mode 1: F600 = 0x02, wait F601 bit 6, ack 0x40;
 * any other mode starts nothing; finally F600 = 0. Callers: only FUN_CODE_0b0d, always mode 0, for the unused rest
 * of a run-time window after an image record (Big chip data window rest 0x9F066F38..0x9F07C000 = CPU 0xA802AF38..
 * 0xA8040000, Small chip 0x9F1987E0..0x9F1A0000 = CPU 0xA80787E0..0xA8080000). 0b0d does NOT call it
 * for the rest of the Big chip's code window (after the 0x7B44-byte record at 0x9F040000), so CPU 0xA002FB44..
 * 0xA0043FFF is never written by the helper chip.
 * Local t = XDATA 0xA4F0 (union: the firmware moves the long's bytes one by one), params in the LARGE block
 * 0xA4E7 (dst, arrives in R4..R7), 0xA4EB (len), 0xA4EF (mode).
 * BYTE-EXACT: diff8051 MATCH 100.0 %, exact None, OPTIMIZE(8,SPEED) LARGE. Keil forms: '(unsigned int)(F601 & m)' gives
 * ANL/JZ for the waits (as in FUN_CODE_738c); the ack written through the absolute address
 * '*(volatile unsigned char xdata *)0xf601' makes Keil reload DPTR (with the named register it reuses DPTR, 3 bytes
 * short). Same register, same access: a source form, no data change.
 */
extern volatile unsigned char xdata DAT_EXTMEM_f600, DAT_EXTMEM_f601, DAT_EXTMEM_f602, DAT_EXTMEM_f603, DAT_EXTMEM_f604, DAT_EXTMEM_f605;
extern volatile unsigned char xdata DAT_EXTMEM_f606, DAT_EXTMEM_f607, DAT_EXTMEM_f608, DAT_EXTMEM_f609;

void FUN_CODE_a8bb(unsigned long dst, unsigned long len, unsigned char mode)
{
    union { unsigned long l; unsigned char b[4]; } t;
    t.l = dst;
    DAT_EXTMEM_f605 = t.b[0];
    DAT_EXTMEM_f604 = t.b[1];
    DAT_EXTMEM_f603 = t.b[2];
    DAT_EXTMEM_f602 = t.b[3];
    t.l = len / 4;
    DAT_EXTMEM_f606 = t.b[3];
    DAT_EXTMEM_f607 = t.b[2];
    DAT_EXTMEM_f608 = t.b[1];
    DAT_EXTMEM_f609 = t.b[0];
    if (mode == 0) {
        DAT_EXTMEM_f600 = 4;
        while (!(unsigned int)(DAT_EXTMEM_f601 & 0x80)) ;
        *(volatile unsigned char xdata *)0xf601 = 0x80;
    } else if (mode == 1) {
        DAT_EXTMEM_f600 = 2;
        while (!(unsigned int)(DAT_EXTMEM_f601 & 0x40)) ;
        *(volatile unsigned char xdata *)0xf601 = 0x40;
    }
    DAT_EXTMEM_f600 = 0;
}
