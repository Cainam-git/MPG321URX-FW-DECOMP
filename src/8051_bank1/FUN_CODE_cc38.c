/* 8051_bank1 FUN_CODE_cc38 @ 0xCC38..0xCC7D (69 bytes; unlisted code found in a gap of the function table).
 * Prints the bytes of the 0x38-byte ring buffer XDATA 0xA208 from the read index XDATA 0xA1E5 up to the write index
 * IDATA 0x47 with the format at CODE 0xDDA6 ("%BX ") through FUN_CODE_2820, wrapping the read index at 0x38, then
 * the format at 0xDDAB ("\r\n"); nothing when the indices are equal. No caller in the image. No aids.
 */
extern unsigned char idata DAT_INTMEM_47;
extern unsigned char xdata DAT_EXTMEM_a1e5;
extern unsigned char xdata DAT_EXTMEM_a208[];
extern void FUN_CODE_2820(void *fmt, ...) large;
void FUN_CODE_cc38(void)
{
    if (DAT_EXTMEM_a1e5 != DAT_INTMEM_47) {
        while (DAT_EXTMEM_a1e5 != DAT_INTMEM_47) {
            FUN_CODE_2820((void code *)0xdda6, DAT_EXTMEM_a208[DAT_EXTMEM_a1e5]);
            DAT_EXTMEM_a1e5++;
            if (DAT_EXTMEM_a1e5 >= 0x38) DAT_EXTMEM_a1e5 = 0;
        }
        FUN_CODE_2820((void code *)0xddab);
    }
}
