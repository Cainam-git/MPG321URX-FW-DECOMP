/* 8051_bank1 FUN_CODE_bf18 @ 0xBF18..0xBF7B (99 bytes; unlisted code found in a gap of the function table).
 * Writes XDATA 0xD807 = 0x28, 0xD800 = 1, 0xD811 = 0x53; then sets a 2-bit field of XDATA 0xD533 chosen by n
 * (0: bits 7..6 = 01, 1: bits 5..4 = 01, 2: bits 3..2 = 01, 3: bits 1..0 = 01; other n: none); then 0xD80D = 0xFF,
 * XDATA 0xA75A = 0x0F, 0xA757 = 0x0F, 0xA759 = 0xFF, and tail-calls the unlisted routine at 0xD8EA (LJMP).
 * Keil compiles the switch as a DEC A / JZ chain with the case 0 body first. No caller in the image. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_d800, DAT_EXTMEM_d807, DAT_EXTMEM_d80d, DAT_EXTMEM_d811, DAT_EXTMEM_d533;
extern unsigned char xdata DAT_EXTMEM_a757, DAT_EXTMEM_a759, DAT_EXTMEM_a75a;
extern void FUN_CODE_d8ea(void);
void FUN_CODE_bf18(unsigned char n)
{
    DAT_EXTMEM_d807 = 0x28;
    DAT_EXTMEM_d800 = 1;
    DAT_EXTMEM_d811 = 0x53;
    switch (n) {
    case 0: DAT_EXTMEM_d533 = DAT_EXTMEM_d533 & 0x3f | 0x40; break;
    case 1: DAT_EXTMEM_d533 = DAT_EXTMEM_d533 & 0xcf | 0x10; break;
    case 2: DAT_EXTMEM_d533 = DAT_EXTMEM_d533 & 0xf3 | 0x04; break;
    case 3: DAT_EXTMEM_d533 = DAT_EXTMEM_d533 & 0xfc | 0x01; break;
    }
    DAT_EXTMEM_d80d = 0xff;
    DAT_EXTMEM_a75a = 0x0f;
    DAT_EXTMEM_a757 = 0x0f;
    DAT_EXTMEM_a759 = 0xff;
    FUN_CODE_d8ea();
}
