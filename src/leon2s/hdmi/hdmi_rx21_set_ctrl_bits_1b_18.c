/* hdmi_rx21_set_ctrl_bits_1b_18  (FUN_a0097ff4)
 *
 * Set control bit 0x1B and set or clear bit 0x18 of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver
 *   on: 1 = set 0x18
 * Name basis: descriptive - bitmap at register block +0x34; caller the mode-detect complete state
 *
 * Matching notes
 * --------------
 * FUN_a0097ff4 (leon2s 0xa0097ff4-0xa0098048, 84 bytes), flags -mcpu=v8 -Os -g.
 * The register block address (record word 1) is read again before each call; the second call is a tail call.
 */
#define BLOCK1_REG_34 0x34              /* byte offset of the register in block 1 */

extern void reg_set_bit(unsigned int, int);
extern void reg_clear_bit(unsigned int, int);
extern unsigned char hdmi_rx21_reg_blocks[];    /* table of register block addresses, 0x34 bytes per receiver */

/*
 * Set bit 0x1B of the register at block 1 + 0x34 of an HDMI 2.1 receiver, then set or clear its bit 0x18.
 *   port: HDMI 2.1 receiver 0/1
 *   on: 1 = set bit 0x18, any other value = clear it
 * Called by DRV_HDMI_ModeDetect_FSM_Complete with on = 0.
 */
void hdmi_rx21_set_ctrl_bits_1b_18(unsigned char port, unsigned char on)
{
    unsigned int *blocks = (unsigned int *)(hdmi_rx21_reg_blocks + port * 0x34);

    reg_set_bit(0x1b, blocks[1] + BLOCK1_REG_34);
    if (on == 1)
        reg_set_bit(0x18, blocks[1] + BLOCK1_REG_34);
    else
        reg_clear_bit(0x18, blocks[1] + BLOCK1_REG_34);
}
