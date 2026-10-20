/* 8051_bank1 FUN_CODE_c73e @ 0xc73e (82 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Sets (set == 1) or clears (any other set) the bits of mask in byte idx of one of two XDATA blocks:
 * bank 0 -> 0x4D00[idx], bank 1 -> 0x4E00[idx]; any other bank does nothing.
 * Callers: FUN_CODE_45aa (0x4720) and FUN_CODE_942e (0x9489, 0x94CB).
 * LARGE parameter block at XDATA 0xA4B9: bank is stored there and read back for the second test; the fourth
 * parameter set does not fit in registers and is passed in its slot 0xA4BC. idx stays in R5, mask in R3.
 * Keil shares the final read-modify-write of both 'set == 1' paths and of both clear paths.
 */
extern unsigned char xdata DAT_EXTMEM_4d00[];
extern unsigned char xdata DAT_EXTMEM_4e00[];

void FUN_CODE_c73e(unsigned char bank, unsigned char idx, unsigned char mask, unsigned char set)
{
    if (bank == 0) {
        if (set == 1) DAT_EXTMEM_4d00[idx] |= mask;
        else DAT_EXTMEM_4d00[idx] &= ~mask;
    } else if (bank == 1) {
        if (set == 1) DAT_EXTMEM_4e00[idx] |= mask;
        else DAT_EXTMEM_4e00[idx] &= ~mask;
    }
}
