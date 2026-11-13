/* hdmi_tx_run_setup_steps  (FUN_a00958d4)
 *
 * Run the HDMI TX set-up steps (source, packets, clocks, PHY, timing check).
 *   port: HDMI TX port 0/1
 * Name basis: proven - prints '[HDMI_TX]: (1) .. (9) Port%d: ...', 'TMDS Mode' / 'FRL Mode', 'DSC
 *   Enable/Disable'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00958d4 @ 0xa00958d4-0xa0095c30 (215 words), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the hdmi_tx_is_active test is written 'if (!...) { ... } else { ... }' with the packet_bypass call of
 *    FUN_a00a9870 in both arms;
 *  - each step that depends on a bit is written as two calls, the arm for the clear bit first;
 *  - the channel record is read through bit-fields.
 */

/* The set-up steps of hdmi_tx_run_step (enum hdmi_tx_step there). */
enum {
    TX_STEP_SELECT_SOURCE      = 0,
    TX_STEP_PACKETS_BYPASS     = 1,
    TX_STEP_PACKETS_OWN_AVI    = 2,
    TX_STEP_PACKETS_OFF        = 3,
    TX_STEP_PACKETS_ON         = 4,
    TX_STEP_CLOCK_SOURCE_TMDS  = 5,
    TX_STEP_CLOCK_SOURCE_FRL   = 6,
    TX_STEP_PHY_CLOCK          = 7,
    TX_STEP_PHY_POWER_ON       = 8,
    TX_STEP_STOP               = 9,
    TX_STEP_LINK_TMDS          = 10,
    TX_STEP_LINK_FRL           = 11,
    TX_STEP_DSC                = 12,
    TX_STEP_REG7C_ON           = 13,
    TX_STEP_RESET_KEEP_PACKETS = 15,
    TX_STEP_INPUT_TIMING       = 17
};

#define TX_BANK_0       0
#define TX_REG_123      0x123           /* bit 3 = frl_mode */
#define   REG123_BIT3     8

/* TX channel record of one HDMI output (28 bytes, hdmi_tx_output_records); the fields read here. Big-endian bit-fields:
   the first field is bit 31 of its word. */
struct hdmi_tx_channel_record {
    /* word 0 */
    unsigned int ctrl_bit31 : 1;        /* also read through hdmi_tx_get_ctrl_bit31 */
    unsigned int ctrl_bit30 : 1;
    unsigned int packet_bypass : 1;     /* bit 29 */
    unsigned int bits_24_28 : 5;
    unsigned int source_code : 8;       /* +1 */
    unsigned int audio_source : 8;      /* +2 */
    unsigned int hsync_positive : 1;
    unsigned int vsync_positive : 1;
    unsigned int hdmi_mode : 1;         /* bit 5 */
    unsigned int frl_mode : 1;          /* bit 4: 0 = TMDS */
    unsigned int dsc_enable : 1;        /* bit 3 */
    unsigned int bit2 : 1;
    unsigned int bit1 : 1;
    unsigned int bit0 : 1;
    unsigned int word_0x4;
    unsigned int pixel_clock;
    unsigned int word_0xc;
    unsigned int word_0x10;
    /* word 5 */
    unsigned int byte_0x14 : 8;
    unsigned int frl_rate : 8;          /* +0x15 */
    unsigned int word_0x14_bit15 : 1;
    unsigned int cfg_bit14 : 1;
    unsigned int frl_rate_update : 1;   /* bit 13: cleared by hdmi_tx_clear_frl_rate_update */
    unsigned int bit12 : 1;             /* with ctrl_bit31 it lets the set-up run; TX_STEP_STOP clears it */
    unsigned int bits_8_11 : 4;
    unsigned int input_code : 8;        /* +0x17 */
    unsigned int word_0x18;
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned char hdmi_tx_get_ctrl_bit31(unsigned char);
extern unsigned char hdmi_tx_is_active(unsigned char);
extern void hdmi_tx_run_step(unsigned char, unsigned char);
extern void hdmi_tx_print_frl_rate(unsigned char);
extern void hdmi_tx_clear_frl_rate_update(unsigned char);
extern void hdmi_tx_set_reg12f_bits(unsigned char, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void hdmi_tx_check_timing(unsigned char);
extern void hdmi_tx_set_active(unsigned char);
extern void CONV2HDMITX_UpdatePacket(unsigned char, unsigned char);     /* CONV2HDMITX_UpdatePacket */
extern void hdmi_tx_reset_channel(unsigned char);

/*
 * Bring one HDMI output up, keep its packets up to date, or shut it down.
 *
 *   port  HDMI TX port 0 or 1
 *
 * Called by hdmi_tx_run_service for port 0 and port 1, after hdmi_tx_apply_pending_request.
 *
 * Three cases, by ctrl_bit31 and bit12 of the channel record (both set or not) and hdmi_tx_is_active:
 *   Both set, not active: run the set-up steps in the order of the printed phases
 *     (1) Input Source Selection: select the input, all packets off;
 *     (2) Packet Configuration: TX_STEP_PACKETS_BYPASS or _OWN_AVI by packet_bypass; with frl_rate_update set,
 *         print the FRL rate and clear the flag;
 *     (3) Clock Source Configuration: TMDS or FRL by frl_mode;
 *     (4) HTX Link_Input_Timing;
 *     (5) HTX PHY+Link Configuration: TMDS, or FRL (with the DSC step first when dsc_enable is set);
 *     (6) HTX PHY Power ON;  (7) HTX PHY CLK Configuration, then register 0x12F bits from hdmi_mode;
 *     (8) Packet Enable/Disable, skipped when ctrl_bit30 is set; register 0x123 bit 3 = frl_mode;
 *     (9) Check PSTABLE/Timing, transmitter reset keeping the packets, register 0x7C step; mark it active.
 *   Both set (active, or just set up): with packet_bypass set, FUN_a00a9870 (CONV2HDMITX_UpdatePacket) updates
 *     the packets from the input.
 *   Not both set, but active: TX_STEP_STOP and the channel record back to its defaults (hdmi_tx_reset_channel).
 */
void hdmi_tx_run_setup_steps(unsigned char port)
{
    if (hdmi_tx_get_ctrl_bit31(port) && hdmi_tx_output_records[port].bit12) {
        if (!hdmi_tx_is_active(port)) {
            dbg_printf("\x1b[0;34m[HDMI_TX]: (1) Port%d: Input Source Selection \n", port);
            hdmi_tx_run_step(port, TX_STEP_SELECT_SOURCE);
            hdmi_tx_run_step(port, TX_STEP_PACKETS_OFF);
            dbg_printf("\x1b[0;34m[HDMI_TX]: (2) Port%d: Packet Configuration \n", port);
            if (!hdmi_tx_output_records[port].packet_bypass)
                hdmi_tx_run_step(port, TX_STEP_PACKETS_OWN_AVI);
            else
                hdmi_tx_run_step(port, TX_STEP_PACKETS_BYPASS);
            if (hdmi_tx_output_records[port].frl_rate_update) {
                dbg_printf("\x1b[0;34m[HDMI_TX]: -- Port%d: Update FRL Rate !!! --\n", port);
                hdmi_tx_print_frl_rate(hdmi_tx_output_records[port].frl_rate);
                hdmi_tx_clear_frl_rate_update(port);
            }
            dbg_printf("\x1b[0;34m[HDMI_TX]: (3) Port%d: Clock Source Configuration \n", port);
            if (!hdmi_tx_output_records[port].frl_mode)
                hdmi_tx_run_step(port, TX_STEP_CLOCK_SOURCE_TMDS);
            else
                hdmi_tx_run_step(port, TX_STEP_CLOCK_SOURCE_FRL);
            dbg_printf("\x1b[0;34m[HDMI_TX]: (4) Port%d: HTX Link_Input_Timing \n", port);
            hdmi_tx_run_step(port, TX_STEP_INPUT_TIMING);
            dbg_printf("\x1b[0;34m[HDMI_TX]: (5) Port%d: HTX PHY+Link Configuration \n", port);
            if (!hdmi_tx_output_records[port].frl_mode) {
                dbg_print_string("\x1b[0m\t\t - TMDS Mode \n");
                hdmi_tx_run_step(port, TX_STEP_LINK_TMDS);
            } else {
                if (hdmi_tx_output_records[port].dsc_enable) {
                    dbg_print_string("\x1b[0m\t\t - DSC Enable \n");
                    hdmi_tx_run_step(port, TX_STEP_DSC);
                } else
                    dbg_print_string("\x1b[0m\t\t - DSC Disable \n");
                dbg_print_string("\x1b[0m\t\t - FRL Mode \n");
                hdmi_tx_run_step(port, TX_STEP_LINK_FRL);
            }
            dbg_printf("\x1b[0;34m[HDMI_TX]: (6) Port%d: HTX PHY Power ON \n", port);
            hdmi_tx_run_step(port, TX_STEP_PHY_POWER_ON);
            dbg_printf("\x1b[0;34m[HDMI_TX]: (7) Port%d: HTX PHY CLK Configuration \n", port);
            hdmi_tx_run_step(port, TX_STEP_PHY_CLOCK);
            hdmi_tx_set_reg12f_bits(port, hdmi_tx_output_records[port].hdmi_mode);
            if (!hdmi_tx_output_records[port].ctrl_bit30) {
                dbg_printf("\x1b[0;34m[HDMI_TX]: (8) Port%d: Packet Enable/Disable \n", port);
                hdmi_tx_run_step(port, TX_STEP_PACKETS_ON);
            }
            if (hdmi_tx_output_records[port].frl_mode)
                hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_123, REG123_BIT3, 1);
            else
                hdmi_tx_reg_update_bits(port, TX_BANK_0, TX_REG_123, REG123_BIT3, 0);
            dbg_printf("\x1b[0;34m[HDMI_TX]: (9) Port%d: Check PSTABLE/Timing \n", port);
            hdmi_tx_check_timing(port);
            hdmi_tx_run_step(port, TX_STEP_RESET_KEEP_PACKETS);
            hdmi_tx_run_step(port, TX_STEP_REG7C_ON);
            hdmi_tx_set_active(port);
            if (hdmi_tx_output_records[port].packet_bypass)
                CONV2HDMITX_UpdatePacket(port, hdmi_tx_output_records[port].input_code);
        } else {
            /* Already running: only the packets. */
            if (hdmi_tx_output_records[port].packet_bypass)
                CONV2HDMITX_UpdatePacket(port, hdmi_tx_output_records[port].input_code);
        }
        return;
    }
    /* Not both set: shut an active port down. */
    if (hdmi_tx_is_active(port)) {
        hdmi_tx_run_step(port, TX_STEP_STOP);
        hdmi_tx_reset_channel(port);
    }
}
