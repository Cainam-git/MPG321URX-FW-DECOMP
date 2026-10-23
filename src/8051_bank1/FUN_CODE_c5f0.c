/* 8051_bank1 FUN_CODE_c5f0 @ 0xc5f0  SPI flash: issue Page Program (02h) for the prepared page
 * (OPTIMIZE(8,SPEED) REGFILE(R.ORC)).
 * Mode 0xF0E6 = (bits 2..3 kept) | 0x01, 0xF0F4 = 3, command 0xF0EA = 02h, 0xF0EB/0xF0EC = 0, 0xF0ED = 0xFF; then the
 * write-buffer controls exactly as the original does them (0xF1C0 = 2, a dummy read of 0xF1C0, 0xF0EE = 0xF1C0,
 * 0xF1C2 written back with its own value, 0xF1C1 = 1, 0xF1C0 = 4),
 * start (0xF0E5 = 1), wait until bit 0 clears, 0xF1C0 = 0. The 24-bit address was put into 0xF0F0..0xF0F2 and the
 * 256 data bytes into the buffer by the caller FUN_CODE_bd81. Boot/update path.
 * The wait is written as a for (;;) with a break: that is what makes Keil emit CLR A before the last store.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee, DAT_EXTMEM_f0f4;
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c1, DAT_EXTMEM_f1c2;
void FUN_CODE_c5f0(void)
{
    DAT_EXTMEM_f0e6 = DAT_EXTMEM_f0e6 & 0x0c | 0x01;
    DAT_EXTMEM_f0f4 = 3;
    DAT_EXTMEM_f0ea = 2;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 0;
    DAT_EXTMEM_f0ed = 0xff;
    DAT_EXTMEM_f1c0 = 2;
    DAT_EXTMEM_f1c0;
    DAT_EXTMEM_f0ee = DAT_EXTMEM_f1c0;
    DAT_EXTMEM_f1c2 = DAT_EXTMEM_f1c2;
    DAT_EXTMEM_f1c1 = 1;
    DAT_EXTMEM_f1c0 = 4;
    DAT_EXTMEM_f0e5 = 1;
    for (;;) if (!(unsigned int)(DAT_EXTMEM_f0e5 & 1)) break;
    DAT_EXTMEM_f1c0 = 0;
}
