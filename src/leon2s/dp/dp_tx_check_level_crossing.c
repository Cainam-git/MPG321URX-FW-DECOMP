/* dp_tx_check_level_crossing  (FUN_a0088fec)
 *
 * Report when a measured level crosses 40 in either direction.
 *   port: DP output; only output 0 is tested
 * Returns: 1 on a crossing
 * Note: The test is made only for DP output 0; other outputs give 0.
 * Name basis: descriptive - hysteresis flag on the signed word 0xA8078A30 vs 40; only for output 0; caller
 *   dp_tx_run_hpd_actions
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * dp_tx_measured_level is read once per test (twice on the flag-set path) and is not volatile.
 * Source form: the two tests are separate '&&' ifs inside 'if (port == 0)'.
 */
extern unsigned char dp_tx_level_low_flag;
extern int dp_tx_measured_level;

#define LEVEL_LIMIT 40

/*
 * Report a crossing of dp_tx_measured_level over 40, in either direction. dp_tx_level_low_flag remembers
 * which side the level was on at the last report.
 *
 *   port: DP output; the test is made only for output 0
 *
 * Returns 1 when the level fell below 40 (flag was clear) or rose to 40 or more (flag was set), else 0.
 * dp_tx_run_hpd_actions calls it with the output number and asks for a link training when it returns 1.
 */
unsigned int dp_tx_check_level_crossing(unsigned char port)
{
    if (port == 0) {
        if (dp_tx_measured_level < LEVEL_LIMIT && dp_tx_level_low_flag == 0) {
            dp_tx_level_low_flag = 1;
            return 1;
        }
        if (dp_tx_measured_level >= LEVEL_LIMIT && dp_tx_level_low_flag != 0) {
            dp_tx_level_low_flag = 0;
            return 1;
        }
    }
    return 0;
}
