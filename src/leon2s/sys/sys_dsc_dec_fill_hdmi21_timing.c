/* sys_dsc_dec_fill_hdmi21_timing  (FUN_a00a6260)
 *
 * Fill the timing fields of a DSC decoder set-up record from an HDMI 2.1 input.
 *   port_code: input code 0x51/0x61
 *   rec: record
 * Name basis: derived - hdmi_rx21_get_pixel_clock / _htotal / _vtotal / _hsync_width / ...; the value 5/10/20
 *   at +0x1a is chosen by the width (below 480, 480..959, 960 up)
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * The width-dependent value (+0x1a) is an if / else-if chain with its own store in each arm and an explicit
 * 'x >= 0x1e0 &&' range test, x unsigned short. With one shared variable the post-reload if-conversion hoists
 * the 'mov 5' above the branch and the delay slots are filled differently; that form also changes the 'mov 2'
 * slot of the "<= 7" test. The getters are called again for every use (htotal three times, vtotal twice).
 */
extern unsigned short hdmi_rx21_get_pixel_clock(unsigned int);
extern unsigned short hdmi_rx21_get_mode_word_34(unsigned int);
extern unsigned short hdmi_rx21_get_htotal(unsigned int);
extern unsigned short hdmi_rx21_get_hactive(unsigned int);
extern unsigned short hdmi_rx21_get_hsync_width(unsigned int);
extern unsigned short hdmi_rx21_get_hfront_porch(unsigned int);
extern unsigned short hdmi_rx21_get_vtotal(unsigned int);
extern unsigned short hdmi_rx21_get_vactive(unsigned int);
extern unsigned short hdmi_rx21_get_vback_porch(unsigned int);

/* Port codes of port entries 0 and 1 (the two HDMI 2.1 inputs). */
#define PORT_CODE_ENTRY0 0x51
#define PORT_CODE_ENTRY1 0x61

/* Halfword positions (byte offset / 2) in the DSC decoder set-up record, as in struct dsc_dec_config. */
#define CFG_VTOTAL           (0x10 / 2)
#define CFG_HTOTAL           (0x14 / 2)
#define CFG_VTOTAL_2         (0x16 / 2)
#define CFG_HSYNC_WIDTH      (0x18 / 2)
#define CFG_HALF_0X1A        (0x1a / 2)
#define CFG_HACTIVE          (0x20 / 2)
#define CFG_VACTIVE          (0x24 / 2)
#define CFG_HBLANK_REST_DIV8 (0x38 / 2)
#define CFG_PIXEL_CLOCK      (0x48 / 2)
#define CFG_MODE_WORD_34     (0x4a / 2)
#define CFG_VBACK_PORCH      (0x4c / 2)

/*
 * Copy the timing of an HDMI 2.1 input into a DSC decoder set-up record. The input is chosen by its port code:
 * 0x51 is receiver 0 and 0x61 is receiver 1; any other code leaves the record untouched. Fields written:
 * pixel clock, htotal, vtotal (stored twice), hsync width (never less than 2: a width of 7 or less is stored
 * as 2), hactive, vactive, the mode word hdmi_rx21_get_mode_word_34, the vertical back porch, and
 * (htotal - front porch - hactive) / 8 as a signed division. The halfword at +0x1a depends on hactive
 * alone: 5 below 480, 10 from 480 to 959, 0x14 from 960 up.
 *   port_code: 0x51 or 0x61
 *   rec:       the record, as halfwords (offsets 0x10..0x4c are written)
 * Caller: sys_dsc_dec_build_hdmi21_config.
 */
void sys_dsc_dec_fill_hdmi21_timing(unsigned char port_code, unsigned short *rec)
{
    unsigned char i;
    int blank_rest;
    unsigned short hactive;

    if (port_code == PORT_CODE_ENTRY0)
        i = 0;
    else if (port_code == PORT_CODE_ENTRY1)
        i = 1;
    else
        return;
    rec[CFG_PIXEL_CLOCK] = hdmi_rx21_get_pixel_clock(i);
    rec[CFG_HTOTAL] = hdmi_rx21_get_htotal(i);
    rec[CFG_VTOTAL] = hdmi_rx21_get_vtotal(i);
    rec[CFG_VTOTAL_2] = hdmi_rx21_get_vtotal(i);
    if (hdmi_rx21_get_hsync_width(i) <= 7)
        rec[CFG_HSYNC_WIDTH] = 2;
    else
        rec[CFG_HSYNC_WIDTH] = hdmi_rx21_get_hsync_width(i);
    rec[CFG_HACTIVE] = hdmi_rx21_get_hactive(i);
    rec[CFG_VACTIVE] = hdmi_rx21_get_vactive(i);
    blank_rest = hdmi_rx21_get_htotal(i);
    blank_rest -= hdmi_rx21_get_hfront_porch(i);
    blank_rest -= hdmi_rx21_get_hactive(i);
    rec[CFG_HBLANK_REST_DIV8] = blank_rest / 8;
    hactive = rec[CFG_HACTIVE];
    if (hactive < 0x1e0)
        rec[CFG_HALF_0X1A] = 5;
    else if (hactive >= 0x1e0 && hactive < 0x3c0)
        rec[CFG_HALF_0X1A] = 10;
    else if (hactive >= 0x3c0)
        rec[CFG_HALF_0X1A] = 0x14;
    else
        rec[CFG_HALF_0X1A] = 10;
    rec[CFG_MODE_WORD_34] = hdmi_rx21_get_mode_word_34(i);
    rec[CFG_VBACK_PORCH] = hdmi_rx21_get_vback_porch(i);
}
