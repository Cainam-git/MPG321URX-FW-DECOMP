/* pq_set_color_fill_enable  (FUN_a010385c)
 *
 * Switch the colour-fill path on or off.
 * Name basis: derived - bit 7 of 0xCF00E9C4, with bit 4 of 0xCF00EAC8 cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010385c @ 0xa010385c-0xa01038c0 (25 words), flags -mcpu=v8 -O3 -g.
 * Source form: the saved value is an unsigned char (the firmware's 'and %o3,0xff' is its zero-extension at the
 * store); 'unsigned int save ... save & 0xff' gives the same instructions with other registers.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define COLOR_FILL_CTRL 0xCF00E9C4
#define COLOR_FILL_ENABLE_BIT 0x80
#define PQ_GAMMA_REG_EAC8 0xCF00EAC8
#define PQ_GAMMA_REG_EAC8_BIT4 0x10

/*
 * Switch the colour-fill path on or off.
 *
 * The colour-fill enable bit is bit 7 of COLOR_FILL_CTRL.  To change it, the
 * low byte of PQ_GAMMA_REG_EAC8 is saved, bit 4 of that register is cleared,
 * the enable bit is set or cleared, and the saved low byte is written back,
 * restoring bit 4 and zeroing bits 8..31 of PQ_GAMMA_REG_EAC8.
 *
 * Callers: osd_dispatch_key_event, pq_api_set_fill_color and SYSAPI_ConfigSystemPIPMode.
 * panel_output_setup_channel_timing, panel_correct_clock_first_step and pq_block_show hold
 * the same steps inline.
 */
void pq_set_color_fill_enable(unsigned char enable)
{
    unsigned char saved_gamma_low_byte = R(PQ_GAMMA_REG_EAC8);

    R(PQ_GAMMA_REG_EAC8) &= ~PQ_GAMMA_REG_EAC8_BIT4;
    if (enable)
        R(COLOR_FILL_CTRL) |= COLOR_FILL_ENABLE_BIT;
    else
        R(COLOR_FILL_CTRL) &= ~COLOR_FILL_ENABLE_BIT;
    R(PQ_GAMMA_REG_EAC8) = saved_gamma_low_byte;
}
