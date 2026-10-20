/* 8051_bank1 FUN_CODE_cf73 @ 0xcf73  SPI flash: send a command and read one byte back (byte-exact
 * with OPTIMIZE(8,SPEED) REGFILE(R.ORC)).
 * 0xF1C0 = 0 (cleared first), 0xF0EA = command byte for a
 * read transfer, 0xF0E6 mode as in FUN_CODE_d5f3, no address (0xF0EB..0xF0ED = 0), 0xF0F4 = 7 (one-byte read
 * transfer), 0xF0E5 = 2 starts the read, bit 1 = busy; result byte at 0xF0EF.
 * Used by FUN_CODE_d81c with 05h (Read Status Register: bit 0 WIP, bit 1 WEL). Boot/update path.
 * Busy test written int-typed, as in FUN_CODE_d5f3 (ANL/JNZ instead of JB).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ef, DAT_EXTMEM_f0f4;
unsigned char FUN_CODE_cf73(unsigned char cmd)
{
    DAT_EXTMEM_f1c0 = 0;
    DAT_EXTMEM_f0ea = cmd;
    DAT_EXTMEM_f0e6 = DAT_EXTMEM_f0e6 & 0x0c | 0x41;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 0;
    DAT_EXTMEM_f0f4 = 7;
    DAT_EXTMEM_f0e5 = 2;                                    /* start read */
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 2)) ;
    return DAT_EXTMEM_f0ef;
}
