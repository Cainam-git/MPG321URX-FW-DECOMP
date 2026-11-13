/* audio_route_source  (FUN_a008c9a8)
 *
 * Route an audio source to an output and set up its audio unit.
 *   src: audio source id (any id audio_set_source_unit knows; extra steps for 4 / 6 DP, 8 / 10 HDMI 2.0, 12 /
 *       14 HDMI 2.1)
 *   out: audio output 0..8
 *   unit: audio unit
 *   en: source enable value, also passed on to audio_set_output_source
 * Name basis: derived - mailbox command 0x92; source enable, unit assignment, unit set-up, output select
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the final src 4 and src 6 tests are two separate ifs (the src 4 call is then not a sibling
 * call).
 */
struct Port34 { unsigned int w0; unsigned char rest[0x34 - 4]; };
extern struct Port34 hdmi_rx21_reg_blocks[];
extern unsigned char audio_dp_32k_mode;
extern void audio_set_source_enable(unsigned char, unsigned char);
extern void audio_set_source_unit(unsigned char, unsigned char);
extern void audio_setup_unit(unsigned char, unsigned char);
extern void audio_update_dp_32k_mode(unsigned char sel, unsigned char port);
extern void hdmi_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern void reg_set_bit(unsigned int, unsigned int);
extern void reg_clear_bit(unsigned int, unsigned int);
extern void timer_delay_units(unsigned int);
extern void audio_set_output_source(unsigned char, unsigned char, unsigned char);
extern unsigned char hdmi_rx21_is_frl_mode(unsigned char port);
extern void audio_set_hdmi21_unit_option(unsigned char sel, unsigned char port, unsigned char en);
extern void audio_set_dp_unit_option(unsigned char mode, unsigned char port, unsigned int val);
extern unsigned short audio_find_outputs_of_source(unsigned char);
extern void audio_flag_dp_resync(unsigned char);

/*
 * Connect an audio source to an audio output through an audio unit, and do the per-source preparation.
 * Callers: audio_configure (source 1, output 0, unit 0, en 1) and the mailbox command 0x92 handler.
 *
 *   src   audio source id (1..3, 4 / 6 DP, 8 / 10 HDMI 2.0, 12 / 14 HDMI 2.1)
 *   out   audio output 0..8
 *   unit  audio unit the source is assigned to (audio_set_source_unit; audio_setup_unit programs it)
 *   en    passed on as the source enable value and as the enable of the output (0 on output 0 only
 *         sets bits 2..3 of 0xCF011018)
 *
 * Order: switch the source's audio capture on or off (audio_set_source_enable), assign and set up the unit,
 * clear audio_dp_32k_mode and run audio_update_dp_32k_mode. Then, by source:
 *  - 8 / 10: write bit 1 of byte register 5 of HDMI 2.0 receiver 0 / 1 as 1, then as 0;
 *  - 12 / 14: set bit 10 of the register at (word 0 of hdmi_rx21_reg_blocks entry 0 / 1) + 4, delay one unit
 *    (timer_delay_units), clear the bit again.
 * Then audio_set_output_source(out, src, en). Last, by source: 12 / 14 set the HDMI 2.1 unit option with the
 * receiver's FRL mode flag; 4 / 6 set the DP unit option to 1 and, when the source has an output, flag the DP
 * receiver 0 / 1 for a fresh FIFO set-up (audio_flag_dp_resync).
 */
void audio_route_source(unsigned char src, unsigned char out, unsigned char unit, unsigned char en)
{
    audio_set_source_enable(src, en);
    audio_set_source_unit(src, unit);
    audio_setup_unit(src, unit);
    audio_dp_32k_mode = 0;
    audio_update_dp_32k_mode(src, unit);
    if (src == 8) {
        hdmi_reg_update_bits(0, 5, 2, 1);
        hdmi_reg_update_bits(0, 5, 2, 0);
    } else if (src == 10) {
        hdmi_reg_update_bits(1, 5, 2, 1);
        hdmi_reg_update_bits(1, 5, 2, 0);
    } else if (src == 12) {
        reg_set_bit(10, hdmi_rx21_reg_blocks[0].w0 + 4);
        timer_delay_units(1);
        reg_clear_bit(10, hdmi_rx21_reg_blocks[0].w0 + 4);
    } else if (src == 14) {
        reg_set_bit(10, hdmi_rx21_reg_blocks[1].w0 + 4);
        timer_delay_units(1);
        reg_clear_bit(10, hdmi_rx21_reg_blocks[1].w0 + 4);
    }
    audio_set_output_source(out, src, en);
    if (src == 12)
        audio_set_hdmi21_unit_option(12, unit, hdmi_rx21_is_frl_mode(0));
    else if (src == 14)
        audio_set_hdmi21_unit_option(14, unit, hdmi_rx21_is_frl_mode(1));
    else if (src == 4)
        audio_set_dp_unit_option(4, unit, 1);
    else if (src == 6)
        audio_set_dp_unit_option(6, unit, 1);
    if (src == 4) {
        if (audio_find_outputs_of_source(4))
            audio_flag_dp_resync(0);
    }
    if (src == 6) {
        if (audio_find_outputs_of_source(6))
            audio_flag_dp_resync(1);
    }
}
