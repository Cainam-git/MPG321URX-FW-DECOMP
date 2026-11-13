/* hdmi_rx21_is_port_ready  (FUN_a0096308)
 *
 * Return whether an HDMI 2.1 receiver record has both ready flags set.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - record bytes +1 and +2 both 1; caller hdmi_eq_check_clock
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0096308 @ 0xa0096308 (-mcpu=v8 -Os)
 * Source form: the record is reached through an unsigned char pointer into the 400-byte entries.
 */
#define RX21_RECORD_SIZE    400         /* bytes per entry of hdmi_rx21_input_records */
#define RX21_MODE_DETECTED  1           /* record byte +1 */
#define RX21_CONNECTED      2           /* record byte +2 */

extern unsigned char hdmi_rx21_input_records;      /* HDMI 2.1 receiver records */

/*
 * Return 1 when the receiver's record has both mode_detected (byte +1) and connected (byte +2) equal to 1, else 0.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_eq_check_clock.
 */
int hdmi_rx21_is_port_ready(int port)
{
    int ready;
    unsigned char *record = (unsigned char *)&hdmi_rx21_input_records + port * RX21_RECORD_SIZE;
    
    ready = 1;
    if ((record[RX21_MODE_DETECTED] != 1) || (record[RX21_CONNECTED] != 1)) {
        ready = 0;
    }
    return ready;
}
