/* sys_switch_to_pll_clock  (FUN_CODE_d24a)
 *
 * Switch the 8051 to the PLL clock once locked and set the fast timer rates.
 * Note: Runs in register bank 3 (interrupt context).
 * Name basis: derived - lock bit 7 of reg 0xD90B; divider to 0xD929, new timer 0 reload and timer 1 baud value
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d24a @ 0xd24a  Byte-exact with OPTIMIZE(7,SPEED).
 * Source form: runs in register bank 3 ('using 3', MOV PSW,#0x18). The test is written '(x & 0x80) ^ 0x80' with an
 * empty then-branch; that produces the target's ANL A,#0x80 / XRL A,#0x80 / JNZ.
 */
sfr TL1 = 0x8B;
sfr TH1 = 0x8D;

extern xdata unsigned char DAT_EXTMEM_d90b;
extern xdata unsigned char DAT_EXTMEM_d929;
extern xdata unsigned char DAT_EXTMEM_f04c;
extern xdata unsigned char timer_reload_low;
extern xdata unsigned char timer_reload_high;

unsigned char sys_find_pll_setting(void);   /* at 0xd6bf */

/*
 * When bit 7 of 0xD90B is set: 0xD929 = (sys_find_pll_setting() + 1) | 0x40,
 * 0xF04C = 0x60, the Timer 0 reload becomes 0xE0C0 (timer_reload_high =
 * 0xE0, timer_reload_low = 0xC0) and Timer 1 is loaded with TH1 = 0x98,
 * TL1 = 0xC3. Otherwise nothing happens. Called by sys_step_clock_switch.
 */
void sys_switch_to_pll_clock(void) using 3 {
    if ((DAT_EXTMEM_d90b & 0x80) ^ 0x80) {
        /* bit 7 not set: nothing to do */
    } else {
        DAT_EXTMEM_d929 = (sys_find_pll_setting() + 1) | 0x40;
        DAT_EXTMEM_f04c = 0x60;
        timer_reload_low = 0xc0;
        timer_reload_high = 0xe0;
        TL1 = 0xc3;
        TH1 = 0x98;
    }
}
