/* 8051_bank1 FUN_CODE_cad5 @ 0xcad5  SPI flash: send a command followed by one data byte (built
 * with OPTIMIZE(8,SPEED) REGFILE(R.ORC); also without REGFILE: no calls here).
 * 0xF1C0/0xF1C3 = write-data buffer: 0x80 before the set-up, 0x82, then the data byte into 0xF1C3, then 0x84.
 * 0xF0E6 mode as in FUN_CODE_d5f3,
 * 0xF0F4 = 3 (FUN_CODE_cf73 uses 7 for its read), 0xF0EB/0xF0EC = 0, 0xF0ED = 1 (data-count register:
 * 1 here for one byte, 0 for command-only, 0xFF in the 256-byte page program FUN_CODE_c5f0), 0xF0EE =
 * command, 0xF0E5 = 1 starts, bit 0 = busy.
 * Used by FUN_CODE_d81c with C5h (Write Extended Address Register).
 * The value parameter is 16 bits wide in the definition (only its low byte, R5, is used): with an 8-bit parameter
 * Keil parks cmd in R6 first and the bytes differ. FUN_CODE_d81c's call passes a byte (R5 only, R4 not set), so the
 * vendor's declaration there differs from this definition; harmless, the high byte is never read.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3, DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee, DAT_EXTMEM_f0f4;
void FUN_CODE_cad5(unsigned char cmd, unsigned int val)
{
    DAT_EXTMEM_f1c0 = 0x80;
    DAT_EXTMEM_f0e6 = DAT_EXTMEM_f0e6 & 0x0c | 0x41;
    DAT_EXTMEM_f0f4 = 3;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 1;
    DAT_EXTMEM_f0ee = cmd;
    DAT_EXTMEM_f1c0 = 0x82;
    DAT_EXTMEM_f1c3 = val;
    DAT_EXTMEM_f1c0 = 0x84;
    DAT_EXTMEM_f0e5 = 1;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 1)) ;
}
