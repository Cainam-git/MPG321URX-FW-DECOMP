/* sys_set_adc_key_tolerance  (FUN_CODE_deee)
 *
 * Store the tolerance used when matching ADC key readings.
 *   tolerance
 * Name basis: derived - byte 0xA62E = g in the key scan power_scan_wake_keys ('ADC key %BX %BX %BX'); mailbox
 *   command 0x1B
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_deee @ 0xdeee  OPTIMIZE(8,SPEED)
 */
#define POWER_ADC_KEY_TOLERANCE 0xa62e   /* power_adc_key_tolerance */

/*
 * Store the tolerance of the ADC key comparison (power_adc_key_tolerance at 0xA62E). power_scan_wake_keys counts
 * an ADC key as pressed when the reading lies within this distance of the key's setting. Only caller:
 * ipc_run_command, mailbox command 0x1B, with arg2 (bits 16..23 of the command word).
 */
void sys_set_adc_key_tolerance(unsigned char tolerance) {
    *(unsigned char xdata *)POWER_ADC_KEY_TOLERANCE = tolerance;
}
