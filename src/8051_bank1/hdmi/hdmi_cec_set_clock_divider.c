/* hdmi_cec_set_clock_divider  (FUN_CODE_d8ea)
 *
 * Set the CEC block's timing value for the selected clock rate.
 * Name basis: descriptive - CEC block reg 0xD801 = 0x78 >> (reg 0xD520 & 3); tail of hdmi_cec_select_port (CEC
 *   regs 0xD800..0xD811)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d8ea @ 0xd8ea (32 B)  Options: OPTIMIZE(7,SPEED) (also level 8).
 * Nothing in the bank-1 image calls or jumps to 0xD8EA.
 */
#define CEC_DIVIDER_BASE 0x78  /* divider value for clock select 0 */

extern unsigned char xdata DAT_EXTMEM_d520;
extern unsigned char xdata reg_hdmi_cec_clock_divider;

/*
 * Set the CEC controller's clock divider from the clock select (bits 0..1 of XDATA 0xD520): 0x78 for select 0,
 * otherwise 0x78 shifted right by the select. Nothing in the image calls this routine.
 */
void hdmi_cec_set_clock_divider(void)
{
    unsigned char clock_select;

    clock_select = DAT_EXTMEM_d520 & 3;
    if (clock_select == 0) {
        reg_hdmi_cec_clock_divider = CEC_DIVIDER_BASE;
    } else {
        reg_hdmi_cec_clock_divider = CEC_DIVIDER_BASE >> clock_select;
    }
}
