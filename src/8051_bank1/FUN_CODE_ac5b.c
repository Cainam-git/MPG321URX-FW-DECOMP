/* 8051_bank1 FUN_CODE_ac5b @ 0xac5b..0xacf2 (151 B)  SPI flash: 16-bit checksum of one 256-byte page
 * (byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * Inputs: a2/a1/a0 = 24-bit flash address, high to low (R7, R5, R3; Keil LARGE keeps them in this function's
 * XDATA block 0xA4BA..0xA4BC, local i at 0xA4BD, sum at 0xA4BE..0xA4BF).
 * Output: unsigned int (R6:R7) = sum of the 256 bytes read starting at that address.
 * Sequence, same as its sibling FUN_CODE_b192 (which copies the page to XDATA 0x3200 instead of summing):
 * FUN_CODE_dc51 (bracket start), Fast Read command 0x0B into 0xF0EA, mode 0xF0E6 = (old & 0x0C) | 0x01,
 * 0xF0EB/EC/ED = 0/1/0, address into 0xF0F0..0xF0F2, 0xF0F4 = 0x0B, 0xF1C0 = 0x81, start 0xF0E5 = 2 and wait
 * while bit 1 is set, 0xF1C0 = 0x82, one discarded read of 0xF1C0, then 256 reads of 0xF1C0 added up,
 * FUN_CODE_dc67 (bracket end). Update/verify path: read only, writes nothing to the flash.
 * Keil notes (facts from the judge): the MOV R7,A after the ORL and the bare MOVX read of 0xF1C0 both come
 * from one char local v that is assigned twice (v = mode; v = dummy read); a plain expression statement or
 * an inline store drops the R7 copy. 'i++; } while (i);' gives the re-read of i after the store (++i does not).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed;
extern unsigned char volatile xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2, DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0;
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_dc67(void);

unsigned int FUN_CODE_ac5b(unsigned char a2, unsigned char a1, unsigned char a0)
{
    unsigned char i = 0;
    unsigned char v;
    unsigned int sum;

    FUN_CODE_dc51();
    DAT_EXTMEM_f0ea = 0x0b;
    v = (DAT_EXTMEM_f0e6 & 0x0c) | 0x01;
    DAT_EXTMEM_f0e6 = v;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 1;
    DAT_EXTMEM_f0ed = 0;
    DAT_EXTMEM_f0f0 = a2;
    DAT_EXTMEM_f0f1 = a1;
    DAT_EXTMEM_f0f2 = a0;
    DAT_EXTMEM_f0f4 = 0x0b;
    DAT_EXTMEM_f1c0 = 0x81;
    DAT_EXTMEM_f0e5 = 2;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 2)) ;
    DAT_EXTMEM_f1c0 = 0x82;
    v = DAT_EXTMEM_f1c0;
    sum = 0;
    do {
        sum += DAT_EXTMEM_f1c0;
        i++;
    } while (i);
    FUN_CODE_dc67();
    return sum;
}
