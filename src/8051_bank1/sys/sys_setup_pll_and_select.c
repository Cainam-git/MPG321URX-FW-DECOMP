/* sys_setup_pll_and_select  (FUN_CODE_c9fb)
 *
 * Program the clock unit, wait for it to settle and select the PLL setting.
 * Name basis: descriptive - same 0xD904..0xD90C writes as sys_setup_pll_regs, 0x3840-pass delay, 0xD929 =
 *   (sys_find_pll_setting() + 1) | 0x40
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c9fb @ 0xc9fb  Byte-exact with OPTIMIZE(8,SPEED) and OPTIMIZE(7,SPEED).
 * Source form: the delay counter lives in R6:R7 (the loop ends with CJNE R6,#38H / CJNE R7,#40H, no tail). The
 * last statement is the same as in sys_switch_to_pll_clock.
 */
#include <intrins.h>
extern unsigned char xdata DAT_EXTMEM_cc8b;
extern unsigned char xdata DAT_EXTMEM_d904;
extern unsigned char xdata DAT_EXTMEM_d905;
extern unsigned char xdata DAT_EXTMEM_d906;
extern unsigned char xdata DAT_EXTMEM_d909;
extern unsigned char xdata DAT_EXTMEM_d90a;
extern unsigned char xdata DAT_EXTMEM_d90b;
extern unsigned char xdata DAT_EXTMEM_d90c;
extern unsigned char xdata DAT_EXTMEM_d929;
unsigned char sys_find_pll_setting(void);

/* Number of empty (NOP) passes that give the clock unit time to settle. */
#define PLL_SETTLE_PASSES 0x3840

/*
 * Same register writes as sys_setup_pll_regs, but with the long wait
 * (0x3840 passes instead of 0xF0), followed by the selection of the setting:
 * 0xD929 = (sys_find_pll_setting() + 1) | 0x40. Callers: the code at 0x3FE9
 * and 0x4287.
 */
void sys_setup_pll_and_select(void)
{
    unsigned int i;

    DAT_EXTMEM_cc8b &= 0xf7;
    DAT_EXTMEM_d909 = 0x55;
    DAT_EXTMEM_d90a = 0x55;
    DAT_EXTMEM_d906 = 0x04;
    DAT_EXTMEM_d905 = 0x03;
    DAT_EXTMEM_d904 = 0xfe;
    DAT_EXTMEM_d90b = 0x84;
    DAT_EXTMEM_d90c = 0x30;

    for (i = 0; i != PLL_SETTLE_PASSES; i++) {
        _nop_();
    }
    DAT_EXTMEM_d929 = (sys_find_pll_setting() + 1) | 0x40;
}
