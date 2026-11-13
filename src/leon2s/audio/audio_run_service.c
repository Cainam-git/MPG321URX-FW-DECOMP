/* audio_run_service  (FUN_a008c8b0)
 *
 * Run the regular audio checks: DP FIFO unmute, unit options and unit states.
 * Note: DP sources 4 and 6: FIFO unmute check and unit option; HDMI 2.1 sources 12 and 14: unit option by FRL
 *   mode only; each only while the source has outputs.
 * Name basis: derived - called from input_run_link_tasks; calls audio_check_dp_fifo_unmute and
 *   audio_update_units
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008c8b0 @ 0xa008c8b0 (-mcpu=v8 -Os -g).
 * Source form: the helpers are declared without a prototype and their results are kept in unsigned short and
 * unsigned int locals. The HDMI 2.1 blocks assign the source id to "frl_mode" before the test; the value is
 * replaced inside the block.
 */
extern int audio_find_outputs_of_source();
extern int audio_check_dp_fifo_unmute();
extern int audio_get_source_unit();
extern int audio_set_dp_unit_option();
extern int hdmi_rx21_is_frl_mode();
extern int audio_set_hdmi21_unit_option();
extern int audio_update_units();

#define AUDIO_SRC_DP0       4
#define AUDIO_SRC_DP1       6
#define AUDIO_SRC_HDMI21_0  0xc
#define AUDIO_SRC_HDMI21_1  0xe

/*
 * Run the regular audio checks for the four sources that have a receiver of their own, then audio_update_units.
 *
 * A source is handled only when audio_find_outputs_of_source reports at least one audio output using it.
 *  - DP sources 4 and 6: audio_check_dp_fifo_unmute for DP receiver 0 or 1, then
 *    audio_set_dp_unit_option(source, audio unit of the source, 1).
 *  - HDMI 2.1 sources 12 and 14: audio_set_hdmi21_unit_option(source, audio unit of the source, FRL mode of
 *    HDMI 2.1 receiver 0 or 1).
 */
void audio_run_service(void)
{
    unsigned short outputs;
    unsigned int frl_mode;

    outputs = audio_find_outputs_of_source(AUDIO_SRC_DP0);
    if ((outputs & 0xffff) != 0) {
        audio_check_dp_fifo_unmute(0);
        outputs = audio_get_source_unit(AUDIO_SRC_DP0);
        audio_set_dp_unit_option(AUDIO_SRC_DP0, outputs & 0xff, 1);
    }

    outputs = audio_find_outputs_of_source(AUDIO_SRC_DP1);
    if ((outputs & 0xffff) != 0) {
        audio_check_dp_fifo_unmute(1);
        outputs = audio_get_source_unit(AUDIO_SRC_DP1);
        audio_set_dp_unit_option(AUDIO_SRC_DP1, outputs & 0xff, 1);
    }

    outputs = audio_find_outputs_of_source(AUDIO_SRC_HDMI21_0);
    frl_mode = AUDIO_SRC_HDMI21_0;
    if ((outputs & 0xffff) != 0) {
        outputs = audio_get_source_unit(AUDIO_SRC_HDMI21_0);
        frl_mode = hdmi_rx21_is_frl_mode(0);
        audio_set_hdmi21_unit_option(AUDIO_SRC_HDMI21_0, outputs & 0xff, frl_mode & 0xff);
    }

    outputs = audio_find_outputs_of_source(AUDIO_SRC_HDMI21_1);
    frl_mode = AUDIO_SRC_HDMI21_1;
    if ((outputs & 0xffff) != 0) {
        outputs = audio_get_source_unit(AUDIO_SRC_HDMI21_1);
        frl_mode = hdmi_rx21_is_frl_mode(1);
        audio_set_hdmi21_unit_option(AUDIO_SRC_HDMI21_1, outputs & 0xff, frl_mode & 0xff);
    }

    audio_update_units();
}
