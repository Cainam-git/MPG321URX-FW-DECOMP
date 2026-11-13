/* sys_api_is_frc_active_unlocked  (FUN_a014d504)
 *
 * Return whether frame-rate conversion is running and neither bypass nor lock mode is set.
 * Returns: 0 or 1
 * Name basis: derived - FRC status bit 0xCF011AA0.7 and bits 26-27 of stSysConfig (PostFRCMainBypass,
 *   PostFRCLockMode)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014d504 @ 0xa014d504-0xa014d544 (16 words), flags -mcpu=v8 -O2 -g.
 * Source form: 'result = 0; if (...) result = 1; return result & 1'; the status test is on the callee's u8 return
 * value.
 */
/* Word 0 of the system configuration record: bit 26 = bypass of the main picture, bit 27 = lock mode. */
#define SYS_CONFIG_FRC_BYPASS_OR_LOCK 0xc000000
extern unsigned int sys_config;
extern unsigned char sys_frc_is_active(void);

/*
 * Return 1 when the frame-rate converter is active and neither the bypass bit nor the lock mode bit of the
 * system configuration word is set, else 0.
 */
unsigned char sys_api_is_frc_active_unlocked(void)
{
    unsigned char result = 0;

    if (sys_frc_is_active() == 1 && (sys_config & SYS_CONFIG_FRC_BYPASS_OR_LOCK) == 0)
        result = 1;
    return result & 1;
}
