/* 8051_bank1 FUN_CODE_7ca8 @ 0x7ca8..0x7df1 (329 B)  SPI flash: read len bytes from flash address addr into
 * XDATA at dst ("read flash flashaddr %08lx, Length %d") (byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * Inputs: dst (R6:R7, XDATA pointer), addr (unsigned long) and len (unsigned int) in the Keil LARGE parameter
 * block (dst 0xA4B3, addr 0xA4B5..0xA4B8, len 0xA4B9..0xA4BA; locals v 0xA4BB, cur 0xA4BC..0xA4BF, n 0xA4C0..C1).
 * Steps: printf with addr and len (bank 1 string 0xA2F3); FUN_CODE_dc51 (bracket start); FUN_CODE_0016 (pulses
 * bit 6 of 0xF0E5); then per chunk of at most 0x200 bytes: read opcode from XDATA 0xA771 into 0xF0EA, mode
 * (0xF0E6 & 0x0C) | 0x01, 0xF0EB = 0, 0xF0EC/0xF0ED = chunk length high/low, 0xF0F0..0xF0F2 = flash address
 * bytes 23..0, 0xF0F4 = 0x0B, 0xF1C0 = 0x81, start 0xF0E5 = 2 and wait for bit 1 clear, 0xF1C0 = 0x82, one
 * discarded read of 0xF1C0 (kept in v), then n reads of 0xF1C0 into dst++; cur += 0x200; repeat while len != 0.
 * Ends with FUN_CODE_dc67 (bracket end, tail jump). Reads only, no flash writes.
 * Keil notes: 'n & 0xff' for the low length byte (a plain 'n' or a cast swaps MOV A,R5 / MOV DPTR at 0x7D4A);
 * len >= 0x200 compiles to the high-byte SUBB #2 test.
 * 0xA771 holds the read opcode (set elsewhere).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed;
extern unsigned char volatile xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2, DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0;
extern unsigned char xdata DAT_EXTMEM_a771;
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_dc67(void);
extern void FUN_CODE_0016(void);
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_7ca8(unsigned char xdata *dst, unsigned long addr, unsigned int len)
{
    unsigned char v;
    unsigned long cur;
    unsigned int n;

    FUN_CODE_2820((void code *)0xa2f3, addr, len);
    FUN_CODE_dc51();
    FUN_CODE_0016();
    cur = addr;
    do {
        if (len >= 0x200) {
            n = 0x200;
            len -= 0x200;
        } else {
            n = len;
            len = 0;
        }
        DAT_EXTMEM_f0ea = DAT_EXTMEM_a771;
        DAT_EXTMEM_f0e6 = DAT_EXTMEM_f0e6 & 0x0c | 0x01;
        DAT_EXTMEM_f0eb = 0;
        DAT_EXTMEM_f0ec = n >> 8;
        DAT_EXTMEM_f0ed = n & 0xff;
        DAT_EXTMEM_f0f0 = ((unsigned char *)&cur)[1];
        DAT_EXTMEM_f0f1 = ((unsigned char *)&cur)[2];
        DAT_EXTMEM_f0f2 = ((unsigned char *)&cur)[3];
        DAT_EXTMEM_f0f4 = 0x0b;
        DAT_EXTMEM_f1c0 = 0x81;
        DAT_EXTMEM_f0e5 = 2;
        while ((unsigned int)(DAT_EXTMEM_f0e5 & 2)) ;
        DAT_EXTMEM_f1c0 = 0x82;
        v = DAT_EXTMEM_f1c0;
        while (n > 0) {
            *dst++ = DAT_EXTMEM_f1c0;
            n--;
        }
        cur += 0x200;
    } while (len);
    FUN_CODE_dc67();
}
