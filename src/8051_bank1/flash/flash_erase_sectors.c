/* flash_erase_sectors  (FUN_CODE_d0cc)
 *
 * Erase a run of consecutive flash sectors with the given erase opcode.
 *   sector: first sector
 *   count_minus_1: count minus one
 *   cmd: erase opcode
 * Note: Not called anywhere.
 * Name basis: derived - loops the DoBlockErase routine over sector .. sector + n; no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d0cc @ 0xD0CC..0xD103 (55 bytes)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * LARGE parameters: sector at XDATA 0xA75B, 'count_minus_1' at 0xA75D, cmd at 0xA75E.
 * Source form: 'count_minus_1--;' is its own statement with the test '!= 0xff' (Keil re-reads the variable after the
 * store and compares with CJNE #0FFH).
 */
void DoBlockErase(unsigned int sector, unsigned char cmd);

/*
 * Erase count_minus_1 + 1 consecutive flash sectors, starting at 'sector',
 * by calling DoBlockErase(sector, cmd) for each. 'cmd' is passed through
 * unchanged. No caller in the bank-1 image.
 */
void flash_erase_sectors(unsigned int sector, unsigned char count_minus_1, unsigned char cmd)
{
    do {
        DoBlockErase(sector, cmd);
        sector++;
        count_minus_1--;
    } while (count_minus_1 != 0xff);
}
