/* edid_enable_port_slaves  (FUN_CODE_c59a)
 *
 * Switch on the EDID slave of the ports chosen by a bit mask.
 *   port_mask: port bits 0..6
 * Name basis: derived - sets bit 7 of 0xF01C/0xF01E/0xF085/0xF087/0xF099/0xF0A3/0xF076; command 0x01 after
 *   edid_setup_port_slaves
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c59a @ 0xc59a (86 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Source form: bits 0..3, 5 and 6 of the mask are tested as '(unsigned int)(mask & n)' (Keil emits 'ANL A,#n / JZ');
 * bit 4 is a plain 'mask & 0x10' test (Keil emits 'JNB ACC.4'). The mask is copied to R3.
 */
/* Bit 7 of an EDID slave control register switches that port's slave on. */
#define EDID_SLAVE_ON 0x80

extern unsigned char xdata reg_edid0_ctrl, reg_edid1_ctrl, reg_edid2_ctrl, reg_edid3_ctrl;
extern unsigned char xdata reg_edid4_ctrl, reg_edid5_ctrl, reg_edid6_ctrl;

/*
 * Bit i of port_mask (i = 0..6) selects port i; for each selected port the
 * enable bit of its control register is set. The registers are the ones
 * edid_disable_port_slaves clears and edid_set_port_control_bit6 rewrites.
 * Called from the command switch for command 0x01, after edid_setup_port_slaves.
 */
void edid_enable_port_slaves(unsigned char port_mask)
{
    if ((unsigned int)(port_mask & 0x01)) reg_edid0_ctrl |= EDID_SLAVE_ON;
    if ((unsigned int)(port_mask & 0x02)) reg_edid1_ctrl |= EDID_SLAVE_ON;
    if ((unsigned int)(port_mask & 0x04)) reg_edid2_ctrl |= EDID_SLAVE_ON;
    if ((unsigned int)(port_mask & 0x08)) reg_edid3_ctrl |= EDID_SLAVE_ON;
    if (port_mask & 0x10) reg_edid4_ctrl |= EDID_SLAVE_ON;
    if ((unsigned int)(port_mask & 0x20)) reg_edid5_ctrl |= EDID_SLAVE_ON;
    if ((unsigned int)(port_mask & 0x40)) reg_edid6_ctrl |= EDID_SLAVE_ON;
}
