/* hdcp_tx_hdmi_state_check_link  (FUN_a00c9398)
 *
 * State handler: run the link checks of an HDMI output and update its record.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00c9398 (leon2s, 0xa00c9398-0xa00c966c, 724 bytes), flags -mcpu=v8 -Os -g.
 * Word 0 of the record is a group of bit-fields (see hdcp_tx_hdmi_state_start_engine). Source forms: the switch on the source code
 * carries a case 0x31 with the default action (see hdcp_tx_hdmi_state_read_repeater_info: it only shapes the compare tree, its compare is
 * removed); cnt-- is written before st = 3 (one read-modify-write).
 */

/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records); only the parts used here are
   named. Word 0 is a group of bit-fields, bit 31 first. */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28: the receiver is a repeater; the DDC reset and read are skipped when set */
    unsigned int tries_left : 4;        /* bits 24..27: decremented here when bits 4..7 of register 0x73 are set */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: result of the state handler (STEP_*) */
    unsigned int state : 8;             /* +2: state of the output's handshake (hdcp_tx_hdmi_run_state) */
    unsigned char rest[21];
};
/* HDMI output record (28 bytes, array hdmi_tx_output_records); only the source code is used here. */
struct hdmi_tx_channel_record { unsigned char byte_0x0; unsigned char source_code; unsigned char rest[26]; };
extern struct hdcp_tx_record hdcp_tx_records[];
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned char dp_tx_option_enabled_stub_copy2(unsigned char);
extern unsigned char hdcp_tx_hdmi_get_status_bit6(unsigned char);
extern void hdcp_tx_hdmi_set_enable(unsigned char, unsigned char);
extern void hdcp_tx_hdmi_set_reg27_bit0(unsigned char, unsigned char);
extern unsigned char hdmi_tx_ddc_reset(unsigned char);
extern unsigned char hdmi_tx_ddc_read_at(unsigned char, unsigned char *);
extern void hdmi_tx_reg_update_bits(unsigned char, int, int, int, int);
extern void hdmi_tx_reg_write8(unsigned char, int, int, unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, unsigned short);

/* Result of a state handler; hdcp_tx_select_next_state picks the next state from it. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

#define SOURCE_CODE_HDMI20_0 0x31       /* input code of the source (INPUT_CODE_*) */
#define SOURCE_CODE_HDMI20_1 0x41
#define SOURCE_CODE_HDMI21_0 0x51
#define SOURCE_CODE_HDMI21_1 0x61
#define TX_REG_71        0x71           /* transmitter registers 0x71..0x73 are written with 0xff */
#define TX_REG_72        0x72
#define TX_REG_73        0x73
#define RX_REG_71        0x71           /* register 0x71 of the HDMI 2.0 receiver selected by sel */
#define RX_REG_0X2E      0x2e           /* read (the value is not used) after an error */
#define DDC_REPLY_BIT4   0x10           /* bit 4 of the second byte read by hdmi_tx_ddc_read_at */
#define TX_REG_0X12F     0x12f

/*
 * State handler of an HDMI output (state 24 of hdcp_tx_hdmi_run_state). port = output 0 or 1.
 *
 * Sets step_result = STEP_NEXT, and STEP_AGAIN when one of the checks below fails (hdcp_tx_select_next_state
 * then keeps the state, so the checks run again; with STEP_NEXT the state stays 0x18, with any other result the
 * output goes back to state 1). Decisions in order:
 *  1. sel is 1 when the output's source code is 0x41 or 0x61, else 0 (0x31 and 0x51 give 0). It selects the
 *     HDMI 2.0 receiver (0 or 1) whose registers are read at the end.
 *  2. The output option (always 1 in this build) is on and status bit 6 of the protection block is clear: the
 *     protection of the output is switched on. Unless the receiver is a repeater, the DDC master is reset
 *     (hdmi_tx_ddc_reset) and two bytes h are read (hdmi_tx_ddc_read_at); if either step reports an error the
 *     protection is switched off again, the result is STEP_AGAIN and the handler returns. Bit 4 of h[1] sets
 *     bit 0 of transmitter register 0x12f. Then bit 0 of register 0x27 is set and the transmitter registers
 *     0x71..0x73 are written with 0xff.
 *  3. The option is off: when status bit 6 is set, bit 0 of register 0x27 and the protection are switched
 *     off. The handler returns in every case.
 *  4. Last checks: bit 1 of register 0x71 of receiver sel gives STEP_AGAIN. Otherwise any of bits 4..7 of
 *     transmitter register 0x73 writes 0xff to registers 0x71..0x73, decrements tries_left (set to 5 by
 *     hdcp_tx_init_port_record), gives STEP_AGAIN and reads register 0x2e of receiver sel (value unused).
 */
void hdcp_tx_hdmi_state_check_link(unsigned char port)
{
    unsigned char h[2];
    unsigned char sel;

    sel = 0;
    hdcp_tx_records[port].step_result = STEP_NEXT;
    switch (hdmi_tx_output_records[port].source_code) {
    case SOURCE_CODE_HDMI20_0:
        sel = 0;
        break;
    case SOURCE_CODE_HDMI20_1:
        sel = 1;
        break;
    case SOURCE_CODE_HDMI21_0:
        sel = 0;
        break;
    case SOURCE_CODE_HDMI21_1:
        sel = 1;
        break;
    }
    if (dp_tx_option_enabled_stub_copy2(port) == 1 && hdcp_tx_hdmi_get_status_bit6(port) == 0) {
        hdcp_tx_hdmi_set_enable(port, 1);
        if (hdcp_tx_records[port].repeater == 0) {
            if (hdmi_tx_ddc_reset(port)) {
                hdcp_tx_records[port].step_result = STEP_AGAIN;
                hdcp_tx_hdmi_set_enable(port, 0);
                return;
            }
            if (hdmi_tx_ddc_read_at(port, h)) {
                hdcp_tx_hdmi_set_enable(port, 0);
                hdcp_tx_records[port].step_result = STEP_AGAIN;
                return;
            }
            if (h[1] & DDC_REPLY_BIT4)
                hdmi_tx_reg_update_bits(port, 0, TX_REG_0X12F, 1, 1);
        }
        hdcp_tx_hdmi_set_reg27_bit0(port, 1);
        hdmi_tx_reg_write8(port, 0, TX_REG_71, 0xff);
        hdmi_tx_reg_write8(port, 0, TX_REG_72, 0xff);
        hdmi_tx_reg_write8(port, 0, TX_REG_73, 0xff);
    } else if (dp_tx_option_enabled_stub_copy2(port) == 0) {
        if (hdcp_tx_hdmi_get_status_bit6(port) == 1) {
            hdcp_tx_hdmi_set_reg27_bit0(port, 0);
            hdcp_tx_hdmi_set_enable(port, 0);
        }
        return;
    }
    if (hdmi_reg_read8(sel, RX_REG_71) & 2) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if (hdmi_tx_reg_read8(port, 0, TX_REG_73) & 0xf0) {
        hdmi_tx_reg_write8(port, 0, TX_REG_71, 0xff);
        hdmi_tx_reg_write8(port, 0, TX_REG_72, 0xff);
        hdmi_tx_reg_write8(port, 0, TX_REG_73, 0xff);
        hdcp_tx_records[port].tries_left--;
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        hdmi_reg_read8(sel, RX_REG_0X2E);
    }
}
