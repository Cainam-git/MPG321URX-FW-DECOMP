/* hdmi_calc_pixel_clock  (FUN_a00910ec)
 *
 * Compute the pixel clock of an HDMI 2.0 receiver from its measured clock.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: pixel clock
 * Name basis: derived - clock count / pixel repetition * 8 / bits per colour, doubled for 4:2:0; mailbox
 *   command 0x03 ports 0/1
 *
 * Matching notes
 * --------------
 * FUN_a00910ec (leon2s 0xa00910ec-0xa00911bc, 208 bytes), flags -mcpu=v8 -Os -g.
 * Source form: one unsigned short variable holds every intermediate result; "port & 1" is written at each use;
 * the divisions are on that unsigned short promoted to int (signed).
 */

/* PHY record of one HDMI 2.0 receiver (24 bytes, hdmi_phy_records); only the byte at +4 is used here. */
struct hdmi_phy_record {
    unsigned char bytes_0x0[4];
    unsigned char clock_ratio_mode; /* +4: when not 0 the measured clock is multiplied by 4, as in hdmi_get_tmds_clock */
    unsigned char bytes_0x5[19];
};

#define RX_AVI_DATA_1   0x144       /* AVI packet area starts at 0x140 */

extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned short hdmi_phy_read_clock_count(unsigned char);
extern unsigned char hdmi_get_pixel_repetition(unsigned char port);
extern int hdmi_get_color_depth(unsigned char port);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);

/* Pixel clock of HDMI 2.0 receiver "port": the PHY's clock count (hdmi_phy_read_clock_count of PHY port & 1),
   times 4 when the PHY record's clock_ratio_mode is not 0, divided by
   the pixel repetition factor, times 8, divided by the bits per colour, and doubled when the AVI colour space
   field (register 0x144 bits 5..7) is 3. hdmi_save_link_timing stores the result in the record; the main
   program can ask for it with the mailbox command that ipc_dispatch_command answers. */
unsigned short hdmi_calc_pixel_clock(unsigned char port)
{
    unsigned short clock = hdmi_phy_read_clock_count(port & 1);
    unsigned char repetition;
    unsigned char bits_per_colour;

    if (hdmi_phy_records[port & 1].clock_ratio_mode)
        clock <<= 2;
    repetition = hdmi_get_pixel_repetition(port);
    bits_per_colour = hdmi_get_color_depth(port);
    clock = clock / repetition * 8 / bits_per_colour;
    if ((hdmi_reg_read8(port, RX_AVI_DATA_1) & 0xe0) == 0x60)
        clock = clock * 2;
    return clock;
}
