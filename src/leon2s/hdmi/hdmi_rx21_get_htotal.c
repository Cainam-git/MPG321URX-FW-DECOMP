/* hdmi_rx21_get_htotal  (FUN_a00a2788)
 *
 * Return the horizontal total of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: pixels
 * Name basis: proven - record halfword +0x1A = H_Total (mode info print); caller input_read_port_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2788, flags -mcpu=v8 -Os -g (section default). The table is a halfword array: index
 * port * 200 + 13.
 */
#define RX21_HTOTAL_HALF 13             /* halfword index of record offset 0x1A (the record has 200 halfwords) */

extern unsigned short hdmi_rx21_input_records[];

/*
 * Return the horizontal total of receiver `port`: the record halfword at offset 0x1A, printed as 'H_Total' by
 * DRV_HDMI_ModeDetect_FSM_Complete. Called by input_read_port_timing and sys_dsc_dec_fill_hdmi21_timing.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned short hdmi_rx21_get_htotal(unsigned int port)
{
    return hdmi_rx21_input_records[(port & 0xff) * 200 + RX21_HTOTAL_HALF];
}
