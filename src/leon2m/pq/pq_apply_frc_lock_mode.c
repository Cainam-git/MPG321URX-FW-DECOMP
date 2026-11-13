/* pq_apply_frc_lock_mode  (FUN_a0083aa0)
 *
 * Pass bit 0 of APPGetFRCMode() to SYSAPI_ConfigSystemPostFRCLockMode.
 *   param_2: passed through
 * Note: No direct caller (pointer table).
 * Name basis: proven - callee SYSAPI_ConfigSystemPostFRCLockMode = SYSAPI_ConfigSystemPostFRCLockMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083aa0 @ 0xa0083aa0, flags -mcpu=v8 -O2 -g (section default).
 * Source form: SYSAPI_ConfigSystemPostFRCLockMode is declared here int-returning and with a second parameter,
 * and the call passes passed_on to it.
 */

#define FRC_MODE_LOCK 1                 /* bit 0 of APPGetFRCMode(): output locked to a frame rate */

extern int APPGetFRCMode(void);
extern int SYSAPI_ConfigSystemPostFRCLockMode(int on, unsigned int passed_on);

/*
 * Set or clear the lock mode of the frame-rate converter output (sys_config bit 27) from the mode that
 * APPGetFRCMode chooses for channel 0.
 *   unused     not used
 *   passed_on  handed to SYSAPI_ConfigSystemPostFRCLockMode, which does not use it
 *
 * Callback 10 of startup_register_app_callbacks. sys_call_frc_callbacks calls it, with no arguments, while
 * the capture window of channel 0 is stored (input_store_capture_window).
 */
void pq_apply_frc_lock_mode(unsigned int unused, unsigned int passed_on)
{
    int frc_mode = APPGetFRCMode();
    SYSAPI_ConfigSystemPostFRCLockMode(frc_mode & FRC_MODE_LOCK, passed_on);
}
