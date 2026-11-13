/* pq_apply_frc_main_bypass  (FUN_a0083abc)
 *
 * Pass bit 1 of APPGetFRCMode() to SYSAPI_ConfigSystemPostFRCMainBypass.
 *   param_2: passed through
 * Note: No direct caller (pointer table).
 * Name basis: proven - callee SYSAPI_ConfigSystemPostFRCMainBypass prints
 *   'SYSAPI_ConfigSystemPostFRCMainBypass'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083abc @ 0xa0083abc, flags -mcpu=v8 -O2 -g (section default).
 * Source forms the exact build depends on: the void parameter list of APPGetFRCMode leaves a nop in the call
 * delay slot; the result held unsigned gives a logical shift (srl); the call is a tail call.
 */

#define FRC_MODE_BYPASS_SHIFT 1         /* bit 1 of APPGetFRCMode(): main picture bypasses the converter */

extern int APPGetFRCMode(void);
extern void SYSAPI_ConfigSystemPostFRCMainBypass(unsigned char on, unsigned int passed_on);

/*
 * Set or clear the frame-rate converter bypass of the main picture (sys_config bit 26) from the mode that
 * APPGetFRCMode chooses for channel 0.
 *   unused     not used
 *   passed_on  handed to SYSAPI_ConfigSystemPostFRCMainBypass, which does not use it
 *
 * Callback 11 of startup_register_app_callbacks. sys_call_frc_callbacks calls it, with no arguments and
 * before the lock-mode callback, while the capture window of channel 0 is stored (input_store_capture_window).
 */
void pq_apply_frc_main_bypass(unsigned int unused, unsigned int passed_on)
{
    unsigned int frc_mode = APPGetFRCMode();
    SYSAPI_ConfigSystemPostFRCMainBypass((frc_mode >> FRC_MODE_BYPASS_SHIFT) & 1, passed_on);
}
