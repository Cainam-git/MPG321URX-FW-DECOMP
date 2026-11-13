/* sys_scan_keys_and_ir  (FUN_CODE_d2e9)
 *
 * Run the key scan and the IR code matcher once; note when neither fired.
 * Returns: non-zero when a key or code was found and the release flag was already set
 * Name basis: derived - ORs power_scan_wake_keys (prints 'Key%02X', 'ADC key') and power_match_ir_wake_code
 *   (matches the IR ring); flag 0xA629
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d2e9 @ 0xd2e9  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Source form: 'found' is the LARGE local at XDATA 0xA473. The firmware's 'LCALL 5a39 / MOV A,R7 / MOV DPTR' order
 * comes from 'found |= power_scan_wake_keys()' after 'found = 0' (Keil folds 0 | R7 into MOV A,R7 before the
 * store); 'found = power_scan_wake_keys()' puts MOV DPTR first.
 */
extern unsigned char xdata power_key_release_seen_flag;
unsigned char power_scan_wake_keys(void);
unsigned char power_match_ir_wake_code(void);

/*
 * Run the key scan (power_scan_wake_keys) and the IR code match
 * (power_match_ir_wake_code) once and return the OR of their results.
 * When both return 0, power_key_release_seen_flag is set to 1. When one
 * of them returned non-zero and the flag is still 0, the result is changed
 * to 0. Callers: the code at 0x4102 and 0x41C8.
 */
unsigned char sys_scan_keys_and_ir(void)
{
    unsigned char found;
    found = 0;
    found |= power_scan_wake_keys();
    found |= power_match_ir_wake_code();
    if (found == 0) power_key_release_seen_flag = 1;
    else if (power_key_release_seen_flag == 0) found = 0;
    return found;
}
