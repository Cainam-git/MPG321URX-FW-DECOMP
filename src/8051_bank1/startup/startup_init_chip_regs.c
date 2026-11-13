/* startup_init_chip_regs  (FUN_CODE_afdc)
 *
 * Set the pin and block registers for the chip variant at start-up.
 * Name basis: derived - values chosen by the chip ID 0xD511 (0x20 / 0x1A / other); registers 0xF160..0xF165,
 *   0xF024.., 0xF0A6; caller sys_main
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_afdc, OPTIMIZE(8,SPEED).
 * volatile is real: reg_chip_id is re-read for every test (4 reads), and 'F02D |= 0xFF' keeps its read; without volatile on
 * F02D or on reg_chip_id the bytes differ. The second 0x1A test is XRL A,#1AH / JNZ in the firmware: '!(id ^ 0x1a)' gives
 * it, '== 0x1a' gives CJNE and a one-case switch gives other code.
 */
extern unsigned char xdata DAT_EXTMEM_f160, DAT_EXTMEM_f161, DAT_EXTMEM_f162, DAT_EXTMEM_f163, DAT_EXTMEM_f164, DAT_EXTMEM_f165;
extern unsigned char volatile xdata reg_chip_id;
extern unsigned char xdata DAT_EXTMEM_f3e9;
extern unsigned char xdata DAT_EXTMEM_f024, reg_uart_irq_enable, DAT_EXTMEM_f030, DAT_EXTMEM_f0a6;
extern unsigned char volatile xdata DAT_EXTMEM_f02d;
/*
 * startup_init_chip_regs - write the start-up values of the registers 0xF160..0xF165 and OR bits into 0xF024, 0xF02C,
 * 0xF02D, 0xF030 and 0xF0A6, depending on reg_chip_id (0x20, 0x1A or any other value):
 *   0xF160..0xF165 = FF 1F F3, (FF for chip 0x20, else 3F), 00, FF
 *   chip 0x1A: 0xF3E9 = 0x0F; OR 0x1C into 0xF024, 0x03 into 0xF02C, 0xBF into 0xF02D, 0x04 into 0xF030
 *   other chips: OR 0xDC into 0xF024, 0x3F into 0xF02C, 0xFF into 0xF02D, and 0xBF (chip 0x20) or 0xBB into 0xF030
 *   all chips: OR 0x3E into 0xF0A6
 * Only caller: sys_main (sys_main).
 */
void startup_init_chip_regs(void)
{
    DAT_EXTMEM_f160 = 0xff;
    DAT_EXTMEM_f161 = 0x1f;
    DAT_EXTMEM_f162 = 0xf3;
    if (reg_chip_id == 0x20) DAT_EXTMEM_f163 = 0xff;
    else DAT_EXTMEM_f163 = 0x3f;
    DAT_EXTMEM_f164 = 0;
    DAT_EXTMEM_f165 = 0xff;
    if (reg_chip_id == 0x1a) DAT_EXTMEM_f3e9 = 0x0f;
    if (!(reg_chip_id ^ 0x1a)) {
        DAT_EXTMEM_f024 |= 0x1c;
        reg_uart_irq_enable |= 0x03;
        DAT_EXTMEM_f02d |= 0xbf;
        DAT_EXTMEM_f030 |= 0x04;
    } else {
        DAT_EXTMEM_f024 |= 0xdc;
        reg_uart_irq_enable |= 0x3f;
        DAT_EXTMEM_f02d |= 0xff;
        if (reg_chip_id == 0x20) DAT_EXTMEM_f030 |= 0xbf;
        else DAT_EXTMEM_f030 |= 0xbb;
    }
    DAT_EXTMEM_f0a6 |= 0x3e;
}
