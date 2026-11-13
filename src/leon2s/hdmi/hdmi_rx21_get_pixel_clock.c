/* hdmi_rx21_get_pixel_clock  (FUN_a00a2750)
 *
 * Return the pixel clock of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: clock in 0.1 MHz
 * Name basis: proven - record halfword +0x32 printed as 'Pixel clock(0.1M)' by FSM_Complete
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2750, flags -mcpu=v8 -Os -g (section default). The table is a halfword array: index
 * port * 200 + 0x19.
 */
#define RX21_PIXEL_CLOCK_HALF 0x19      /* halfword index of record offset 0x32 (the record has 200 halfwords) */

extern unsigned short hdmi_rx21_input_records[];

/*
 * Return the pixel clock of receiver `port` in 0.1 MHz (record halfword at offset 0x32), the value printed as
 * 'Pixel clock(0.1M)' by DRV_HDMI_ModeDetect_FSM_Complete. Called by CONV2HDMITX_UpdateInterface,
 * sys_dsc_dec_fill_hdmi21_timing and FSM_MODE_DETECT_STANDBY.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned short hdmi_rx21_get_pixel_clock(unsigned int port)
{
    return hdmi_rx21_input_records[(port & 0xff) * 200 + RX21_PIXEL_CLOCK_HALF];
}
