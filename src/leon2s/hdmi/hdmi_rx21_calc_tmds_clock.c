/* hdmi_rx21_calc_tmds_clock  (FUN_a00a20c4)
 *
 * Compute the TMDS clock of an HDMI 2.1 input from pixel clock and colour depth.
 *   port: receiver
 * Returns: clock in 0.1 MHz
 * Name basis: proven - pixel clock * bits / 8 * repetition; printed as 'TMDS clock(0.1M)' by FSM_Complete;
 *   mailbox command 0x03
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a20c4, flags -mcpu=v8 -Os -g (section default). The table is declared as an unsigned short array
 * and the record address is computed by hand from it.
 */
/* Offsets in the 400-byte record of a receiver (hdmi_rx21_input_records). */
#define RX21_COLOR_DEPTH   0x19         /* bits per colour */
#define RX21_BYTE_0x2E     0x2e
#define RX21_PIXEL_CLOCK   0x32         /* halfword, in 0.1 MHz */

extern unsigned short hdmi_rx21_input_records[];

/*
 * Compute the TMDS clock of receiver `port` from its record: ((pixel clock * bits per colour) >> 3) *
 * (byte 0x2E + 1), cut to 16 bits, in 0.1 MHz. The result is printed as 'TMDS clock(0.1M)' by
 * DRV_HDMI_ModeDetect_FSM_Complete. Also called by ipc_dispatch_command, hdmi_tx_setup_audio and
 * audio_calc_hdmi21_sample_rate.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned short hdmi_rx21_calc_tmds_clock(unsigned char port) {
    unsigned char *record = (unsigned char *)((unsigned int)port * 400 + (unsigned int)hdmi_rx21_input_records);
    unsigned int result = ((unsigned int)*(unsigned short *)(record + RX21_PIXEL_CLOCK) * record[RX21_COLOR_DEPTH]) >> 3;
    return (unsigned short)(result * (record[RX21_BYTE_0x2E] + 1));
}
