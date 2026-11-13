/* pq_api_load_preset_curves  (FUN_a014e1d0)
 *
 * Switch both curve stages off, wait, and load preset curve 0..4 into both.
 * Name basis: derived - five 64-byte tables of 32 rising 16-bit points (curve shape) at 0x19ACDC..; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e1d0, flags -mcpu=v8 -O3 -g. Source form: a plain switch with no default; the last loader call
 * becomes a tail call.
 */

#define CURVE_SWITCH_OFF_WAIT 10    /* timer ticks waited after both stages are switched off */
#define CURVE_PRESET_COUNT 5

extern void pq_gamma_disable_first_curve_stage(void);
extern void pq_gamma_disable_second_curve_stage(void);
extern int timer_sleep_ticks(int);
extern void pq_gamma_load_first_curve_preset0(void *p);
extern void pq_gamma_load_second_curve_preset0(void *p);
extern void pq_gamma_load_first_curve_preset1(void *p);
extern void pq_gamma_load_second_curve_preset1(void *p);
extern void pq_gamma_load_first_curve_preset2(void *p);
extern void pq_gamma_load_second_curve_preset2(void *p);
extern void pq_gamma_load_first_curve_preset3(void *p);
extern void pq_gamma_load_second_curve_preset3(void *p);
extern void pq_gamma_load_first_curve_preset4(void *p);
extern void pq_gamma_load_second_curve_preset4(void *p);

/*
 * Load one of the five preset curve pairs into both curve stages.
 *
 *   sel  the preset number 0..4
 *
 * Both curve stages are switched off and timer_sleep_ticks(10) waits; then the first and the second curve stage
 * loaders for sel are called with a null table, so each writes its own ROM preset (64 bytes with table command
 * 0x76 for the first stage, 32 bytes with 0xB6 for the second).
 * A sel above 4 does nothing after the switch-off and the wait. The stages are not switched on again here.
 *
 * No direct call to it was found in the image.
 */
void pq_api_load_preset_curves(unsigned char sel)
{
    pq_gamma_disable_first_curve_stage();
    pq_gamma_disable_second_curve_stage();
    timer_sleep_ticks(CURVE_SWITCH_OFF_WAIT);
    switch (sel) {
    case 0:
        pq_gamma_load_first_curve_preset0(0);
        pq_gamma_load_second_curve_preset0(0);
        break;
    case 1:
        pq_gamma_load_first_curve_preset1(0);
        pq_gamma_load_second_curve_preset1(0);
        break;
    case 2:
        pq_gamma_load_first_curve_preset2(0);
        pq_gamma_load_second_curve_preset2(0);
        break;
    case 3:
        pq_gamma_load_first_curve_preset3(0);
        pq_gamma_load_second_curve_preset3(0);
        break;
    case 4:
        pq_gamma_load_first_curve_preset4(0);
        pq_gamma_load_second_curve_preset4(0);
        break;
    }
}
