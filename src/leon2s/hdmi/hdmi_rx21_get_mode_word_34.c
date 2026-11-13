/* hdmi_rx21_get_mode_word_34  (FUN_a00a276c)
 *
 * Return the mode info halfword +0x34 of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: value
 * Name basis: descriptive - record halfword +0x34 = timing register 0x54 field set by
 *   hdmi_rx21_update_mode_info; caller the timing record fill
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a276c, flags -mcpu=v8 -Os -g (section default). The table is a halfword array: index
 * port * 200 + 0x1a.
 */
#define RX21_HALF_0x34 0x1a             /* halfword index of record offset 0x34 (the record has 200 halfwords) */

extern unsigned short hdmi_rx21_input_records[];

/*
 * Return the halfword at record offset 0x34 of receiver `port`. Called by sys_dsc_dec_fill_hdmi21_timing.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned short hdmi_rx21_get_mode_word_34(unsigned int port)
{
    return hdmi_rx21_input_records[(port & 0xff) * 200 + RX21_HALF_0x34];
}
