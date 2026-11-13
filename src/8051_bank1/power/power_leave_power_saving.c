/* power_leave_power_saving  (FUN_CODE_b06f)
 *
 * Switch the chip's blocks back on after standby.
 * Name basis: derived - power cut list phase 0 (entries 3..5 of the power-cut table), clears the standby flag
 *   bit set by the power-saving set-up, clock registers 0xD9xx, then timer_set_clock_rates; caller sys_main
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b06f @ 0xb06f, OPTIMIZE(8,SPEED).
 * Source form: all registers are plain xdata (no volatile); sys_on_crystal_clock_flag (BITS_21_6) is declared here
 * as the sbit BIT_0x0E of the bdata byte at 0x21.
 */
extern void power_apply_cut_list(unsigned char);
extern void timer_set_clock_rates(void);

extern unsigned char xdata DAT_EXTMEM_d910;
extern unsigned char xdata DAT_EXTMEM_d904;
extern unsigned char xdata DAT_EXTMEM_d911;
extern unsigned char xdata DAT_EXTMEM_d90f;
extern unsigned char xdata DAT_EXTMEM_d92d;
extern unsigned char xdata DAT_EXTMEM_da00;
extern unsigned char xdata DAT_EXTMEM_e1bf;
extern unsigned char xdata DAT_EXTMEM_e1cf;
extern unsigned char xdata DAT_EXTMEM_e1d8;
extern unsigned char xdata DAT_EXTMEM_e1e0;
extern unsigned char xdata DAT_EXTMEM_e1e2;
extern unsigned char xdata reg_chip_id;
extern unsigned char xdata DAT_EXTMEM_e1ec;
extern unsigned char xdata DAT_EXTMEM_e1ee;
extern unsigned char xdata DAT_EXTMEM_e19f;
extern unsigned char xdata DAT_EXTMEM_e1af;
extern unsigned char xdata DAT_EXTMEM_e12b;
extern unsigned char xdata DAT_EXTMEM_d523;
extern unsigned char xdata DAT_EXTMEM_d52c;
extern unsigned char xdata DAT_EXTMEM_d52d;

unsigned char bdata byte_0x21 _at_ 0x21;
sbit BIT_0x0E = byte_0x21 ^ 6;   /* = sys_on_crystal_clock_flag (bit address 0x0E) */

#define CUT_LIST_SECOND_HALF  0     /* power_apply_cut_list: entries 3..5 of the power-cut table (1 = entries 0..2) */
#define CHIP_VARIANT_20       0x20  /* reg_chip_id value with five more registers to switch on */

/*
 * power_leave_power_saving - switch the chip's blocks back on; the counterpart of power_setup_power_saving.
 * Called twice by sys_main: in the basic start-up with interrupts off, and on wake-up after the clock set-up has
 * been redone, before the other processors are started again.
 * Order:
 *   1. Switch the pins of entries 3..5 of the power-cut table (power_apply_cut_list) and clear
 *      sys_on_crystal_clock_flag.
 *   2. Set the registers that power_setup_power_saving clears on chip 0x20: 0xD910 / 0xD911 / 0xE1D8 = 0xFF and
 *      fixed bit masks ORed into 0xD904, 0xD90F, 0xD92D, 0xDA00, 0xE1BF, 0xE1CF, 0xE1E0 and 0xE1E2. This part runs
 *      on every chip; 0xE1EC, 0xE1EE, 0xE19F, 0xE1AF and 0xE12B follow on chip 0x20 only.
 *   3. 0xD523 = 0xA3, and the bits power_setup_power_saving sets in 0xD52C (2..3) and 0xD52D (1, 7) are cleared.
 *   4. Load the tick timer reload and serial speed for the normal clock (timer_set_clock_rates).
 * What the single registers select is not shown.
 */
void power_leave_power_saving(void)
{
    power_apply_cut_list(CUT_LIST_SECOND_HALF);
    BIT_0x0E = 0;   /* sys_on_crystal_clock_flag: the 8051 runs on the normal clock again */
    
    DAT_EXTMEM_d910 = 0xff;
    DAT_EXTMEM_d904 |= 0xfe;
    DAT_EXTMEM_d911 = 0xff;
    DAT_EXTMEM_d90f |= 0x80;
    DAT_EXTMEM_d92d |= 0xc0;
    DAT_EXTMEM_da00 |= 0x01;
    DAT_EXTMEM_e1bf |= 0x80;
    DAT_EXTMEM_e1cf |= 0x80;
    DAT_EXTMEM_e1d8 = 0xff;
    DAT_EXTMEM_e1e0 |= 0x7f;
    DAT_EXTMEM_e1e2 |= 0x70;
    
    if (reg_chip_id == CHIP_VARIANT_20) {
        DAT_EXTMEM_e1ec |= 0x7f;
        DAT_EXTMEM_e1ee |= 0x7f;
        DAT_EXTMEM_e19f |= 0x80;
        DAT_EXTMEM_e1af |= 0x80;
        DAT_EXTMEM_e12b |= 0x80;
    }
    
    DAT_EXTMEM_d523 = 0xa3;
    DAT_EXTMEM_d52c &= 0xf3;
    DAT_EXTMEM_d52d &= 0x7d;
    
    timer_set_clock_rates();
}
