/* 8051_bank1 FUN_CODE_d0cc @ 0xD0CC..0xD103 (55 bytes).
 * FUN_CODE_d0cc(sector, n, cmd): calls FUN_CODE_8b58(sector, cmd) for sector, sector + 1, ... n + 1 times.
 * LARGE parameters sector (XDATA 0xA75B), n (0xA75D), cmd (0xA75E). Source form: 'n--;' as its own statement with
 * the test 'n != 0xff' (Keil re-reads n after the store and compares with CJNE #0FFH). No caller in the image.
 */
void FUN_CODE_8b58(unsigned int sector, unsigned char cmd);
void FUN_CODE_d0cc(unsigned int sector, unsigned char n, unsigned char cmd)
{
    do {
        FUN_CODE_8b58(sector, cmd);
        sector++;
        n--;
    } while (n != 0xff);
}
