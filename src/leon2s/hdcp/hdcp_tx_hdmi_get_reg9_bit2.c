/* hdcp_tx_hdmi_get_reg9_bit2  (FUN_a00cc9ac)
 *
 * Return 1 when bit 2 of register 9 of an HDMI output's block is set, else 0.
 * Returns: 0 or 1
 * Name basis: descriptive - hdmi_tx_reg_read8(port, 0, 9) & 4; called by the output polling routine together
 *   with bit 1 of the same register
 *
 * Matching notes
 * --------------
 * FUN_a00cc9ac (leon2s, 0xa00cc9ac-0xa00cc9f8, 76 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the result goes through a 2-byte stack table {0, 0} indexed by the port (the firmware clears it
 * with one halfword store and stores 1 or 0 into the slot).
 */
extern unsigned int hdmi_tx_reg_read8(unsigned int, unsigned int, unsigned int);

#define STATUS_REG              9       /* register read from the output's block */
#define STATUS_BIT2             4       /* bit 2 of that register */

/*
 * Return 1 when bit 2 of register 9 of the HDMI output's block is set, else 0. port is 0 or 1 (it indexes the
 * 2-byte table). hdcp_tx_task combines it with bit 1 of the same register to decide that a sink is attached.
 */
unsigned char hdcp_tx_hdmi_get_reg9_bit2(unsigned char port)
{
    unsigned char flag[2] = {0, 0};

    if (hdmi_tx_reg_read8(port, 0, STATUS_REG) & STATUS_BIT2)
        flag[port] = 1;
    else
        flag[port] = 0;
    return flag[port];
}
