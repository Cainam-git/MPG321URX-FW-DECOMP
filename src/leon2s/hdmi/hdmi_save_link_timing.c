/* hdmi_save_link_timing  (FUN_a0091204)
 *
 * Store the measured timing, clocks and colour depth of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - fills record fields +0x8D..+0xA4 from the hdmi_read_* getters; caller
 *   hdmi_tmds_run_link_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091204 @ 0xa0091204 (-mcpu=v8 -Os -g)
 * The eight timing getters take one argument ('mov %i0, %o0').
 */
extern unsigned short hdmi_read_hactive(unsigned int);
extern unsigned short hdmi_read_vactive(unsigned int);
extern unsigned short hdmi_read_htotal(unsigned int);
extern unsigned short hdmi_read_vtotal(unsigned int);
extern unsigned short hdmi_read_hfront_porch(unsigned int);
extern unsigned short hdmi_read_hsync_width(unsigned int);
extern unsigned short hdmi_read_vback_porch(unsigned int);
extern unsigned short hdmi_read_vsync_width(unsigned int);
extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);
extern unsigned short hdmi_get_tmds_clock(unsigned int);
extern unsigned short hdmi_calc_pixel_clock(unsigned int);
extern int hdmi_get_color_depth(unsigned char);

#define HDMI_RX_RECORD_SIZE 0xb0       /* bytes per receiver record in the table at 0xA807D3E4 */

/*
 * Store the measured timing of HDMI receiver 'port' in its 0xB0-byte record of the table at 0xA807D3E4:
 * the eight values from the hdmi_read_* getters as halfwords at +0x96..+0xA4, the TMDS clock
 * at +0x94 (hdmi_get_tmds_clock), the pixel clock at +0x92 (hdmi_calc_pixel_clock), the colour depth at +0x8E.
 * Bytes +0x8D, +0x8F and +0x90 each hold one bit of receiver registers 0x30 and 0x55.
 */
void hdmi_save_link_timing(unsigned int port)
{
    unsigned char *tbl;
    unsigned char *base;
    unsigned char reg_value;

    port = port & 0xff;
    tbl = (unsigned char *)0xa807d3e4;
    base = tbl + port * HDMI_RX_RECORD_SIZE;

    *(unsigned short *)(base + 0x98) = hdmi_read_hactive(port);
    *(unsigned short *)(base + 0x96) = hdmi_read_htotal(port);
    *(unsigned short *)(base + 0x9a) = hdmi_read_hfront_porch(port);
    *(unsigned short *)(base + 0x9c) = hdmi_read_hsync_width(port);
    *(unsigned short *)(base + 0xa0) = hdmi_read_vactive(port);
    *(unsigned short *)(base + 0x9e) = hdmi_read_vtotal(port);
    *(unsigned short *)(base + 0xa2) = hdmi_read_vback_porch(port);
    *(unsigned short *)(base + 0xa4) = hdmi_read_vsync_width(port);

    reg_value = hdmi_reg_read8(port, 0x55);
    base[0x8f] = (unsigned char)(reg_value & 1);

    reg_value = hdmi_reg_read8(port, 0x55);
    base[0x90] = (unsigned char)((reg_value & 2) >> 1);

    reg_value = hdmi_reg_read8(port, 0x30);
    base[0x8d] = (unsigned char)((reg_value & 0x10) >> 4);

    *(unsigned short *)(base + 0x94) = hdmi_get_tmds_clock(port);
    *(unsigned short *)(base + 0x92) = hdmi_calc_pixel_clock(port);
    base[0x8e] = (unsigned char)hdmi_get_color_depth(port);
}
