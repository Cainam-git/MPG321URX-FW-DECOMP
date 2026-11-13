/* sys_setup_pll_regs  (FUN_CODE_cc7d)
 *
 * Program the clock unit's PLL registers and wait briefly.
 * Name basis: descriptive - 0xCC8B bit 3 cleared, 0xD904..0xD90C = FE 03 04 .. 55 55 84 30, 0xF0-pass delay;
 *   step 1 of sys_step_clock_switch
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cc7d @ 0xcc7d  Byte-exact with OPTIMIZE(8,SPEED) (also level 7 and LARGE).
 * Source form: runs in register bank 3 ('using 3', PUSH PSW, PSW = 0x18). The loop counter lives in R6:R7 and the
 * bound is tested with MOV A,R7 / XRL A,#0F0H / ORL A,R6 / JNZ.
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

/* Number of empty (NOP) passes after the register writes. */
#define PLL_SHORT_WAIT_PASSES 0xf0

/*
 * Write the clock unit's registers (bit 3 of 0xCC8B cleared, then 0xD909 and
 * 0xD90A = 0x55, 0xD906 / 0xD905 / 0xD904 = 04 / 03 / FE, 0xD90B / 0xD90C =
 * 84 / 30) and wait 0xF0 passes. Called by sys_step_clock_switch.
 */
void sys_setup_pll_regs(void) using 3
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

    for (i = 0; i != PLL_SHORT_WAIT_PASSES; i++) {
        _nop_();
    }
}
