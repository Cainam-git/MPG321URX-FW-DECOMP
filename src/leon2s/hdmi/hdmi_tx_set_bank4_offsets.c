/* hdmi_tx_set_bank4_offsets  (FUN_a0094b30)
 *
 * Store a value (11..492) and write offsets derived from it to HDMI TX bank 4.
 *   port: HDMI TX port
 *   value
 * Name basis: descriptive - regs 0x14..0x21 = 0x400 + v, 0x400 - v, 0x3F8 + v, 0x3F4 + v; stored in 0xA80785E8
 *
 * Matching notes
 * --------------
 * FUN_a0094b30 (leon2s 0xa0094b30-0xa0094c54, 292 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Source form: the four sums are assigned after the range test and the store; the last call is a sibling call.
 */
#define HDMI_TX_BANK_FRL 4              /* bank 4 of an HDMI transmitter's registers (the FRL registers) */

#define BANK4_VALUE_MIN  11             /* smaller values are ignored */
#define BANK4_VALUE_MAX  0x1ec          /* 492; larger values are ignored */

extern unsigned int hdmi_tx_bank4_value;
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

/*
 * Store a value and write four offsets derived from it to the 16-bit register pairs of bank 4.
 *   port: HDMI TX port 0/1
 *   value: 11..492; anything else is ignored and nothing is written
 * Each sum is written low byte first: 0x400 + value to registers 0x14/0x15, 0x400 - value to 0x16/0x17,
 * 0x3F8 + value to 0x1C/0x1D and again to 0x1E/0x1F, 0x3F4 + value to 0x20/0x21. The value is kept in
 * hdmi_tx_bank4_value.
 * Called by hdmi_tx_run_step in TX_STEP_LINK_FRL, with 0x15E for a pixel clock above 100 and 0xB4 otherwise.
 */
void hdmi_tx_set_bank4_offsets(unsigned char port, unsigned int value)
{
    unsigned int sum_0x400_plus, sum_0x400_minus, sum_0x3f8_plus, sum_0x3f4_plus;

    if (value - BANK4_VALUE_MIN > BANK4_VALUE_MAX - BANK4_VALUE_MIN)
        return;
    hdmi_tx_bank4_value = value;
    sum_0x400_plus = value + 0x400;
    sum_0x400_minus = 0x400 - value;
    sum_0x3f8_plus = value + 0x3f8;
    sum_0x3f4_plus = value + 0x3f4;
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x14, sum_0x400_plus);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x15, sum_0x400_plus >> 8);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x16, sum_0x400_minus);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x17, sum_0x400_minus >> 8);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x1c, sum_0x3f8_plus);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x1d, sum_0x3f8_plus >> 8);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x1e, sum_0x3f8_plus);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x1f, sum_0x3f8_plus >> 8);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x20, sum_0x3f4_plus);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, 0x21, sum_0x3f4_plus >> 8);
}
