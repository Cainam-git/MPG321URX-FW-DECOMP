/* 8051_bank1 FUN_CODE_9fc8 @ 0x9fc8..0xa085 (189 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_9fc8(off, n): calls FUN_CODE_6f26(&XDATA[0xA800 + off], (long at XDATA 0xA711) + off, n), then passes the
 * format at CODE 0xC496 ("FE2P WriteByte %BX %BX %BX %BX %BX\r\n") with the five bytes XDATA 0xA800 + off - 2 ..
 * off + 2 to FUN_CODE_2820 (tail LJMP).
 * LARGE parameters: off at XDATA 0xA4B3, n at 0xA4B5; FUN_CODE_6f26 takes its second and third parameters in its
 * own XDATA block (0xA4B8 long, 0xA4BC int).
 * Caller: FUN_CODE_224f (command case 21, off = (b2 << 8) + b3, n = b1).
 */
extern unsigned char xdata DAT_EXTMEM_a800[];
extern unsigned long xdata DAT_EXTMEM_a711;
extern void FUN_CODE_6f26(unsigned char xdata *p, unsigned long a, unsigned int n);
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_9fc8(unsigned int off, unsigned char n)
{
    FUN_CODE_6f26(&DAT_EXTMEM_a800[off], DAT_EXTMEM_a711 + off, n);
    FUN_CODE_2820((void code *)0xc496, DAT_EXTMEM_a800[off - 2], DAT_EXTMEM_a800[off - 1], DAT_EXTMEM_a800[off],
                  DAT_EXTMEM_a800[off + 1], DAT_EXTMEM_a800[off + 2]);
}
