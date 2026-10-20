/* 8051_bank1 FUN_CODE_d5f3 @ 0xd5f3  SPI flash: send a one-byte command (byte-exact with
 * OPTIMIZE(8,SPEED) REGFILE(R.ORC)).
 * SPI master registers in XDATA: 0xF0EE = command byte, 0xF0E6 = mode (bits 2..3 kept, 0x41 = command-only
 * transfer), 0xF0EB..0xF0ED = 0 (0xF0ED is a data-count register, see FUN_CODE_cad5), 0xF0E5
 * bit 0 = start / busy.
 * Writes the command, starts the transfer and waits until the controller clears the busy bit.
 * Used by FUN_CODE_d81c with 06h (Write Enable). Boot/update path: read only for us.
 * The busy test is an int-typed expression in the original ((unsigned int)(x & 1)): that is what makes Keil emit
 * ANL A,#1 / JNZ instead of a JB on ACC.0.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee;

void FUN_CODE_d5f3(unsigned char cmd)
{
    DAT_EXTMEM_f0ee = cmd;                                  /* command byte */
    DAT_EXTMEM_f0e6 = DAT_EXTMEM_f0e6 & 0x0c | 0x41;        /* command-only transfer */
    DAT_EXTMEM_f0eb = 0;                                    /* no data bytes */
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 0;
    DAT_EXTMEM_f0e5 = 1;                                    /* start */
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 1)) ;           /* wait while busy */
}
