/* audio_calc_dp_sample_rate  (FUN_a008c538)
 *
 * Compute the audio sample rate of a DP receiver in Hz.
 *   port: DP receiver 0/1
 * Returns: sample rate in Hz
 * Name basis: proven - Maud * link rate MHz (162/270/540/810) / 64 * 1250 / Naud * 100 = fs from the DP M/N
 *   formula
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008c538 @ 0xa008c538-0xa008c5d8 (160 bytes), flags -mcpu=v8 -Os -g.
 * Source form: one complete formula per case (as in dp_tx_calc_pixel_clock and dp_calc_rate_value), default case first.
 */
extern int audio_read_dp_maud(unsigned char);
extern unsigned int audio_read_dp_naud(unsigned int port);
extern int dp_get_link_rate_index(unsigned char port);

/* Factor for link rate index 0..3 (162, 270, 540 and 810); any other index uses the first. */
#define DP_RATE_INDEX_0 162
#define DP_RATE_INDEX_1 270
#define DP_RATE_INDEX_2 540
#define DP_RATE_INDEX_3 810

/*
 * Compute the audio sample rate of a DP receiver in Hz:
 *   Maud * rate / 64 * 1250 / Naud * 100
 * where rate is 162, 270, 540 or 810 for link rate index 0, 1, 2 or 3 of dp_get_link_rate_index (162 for any
 * other value).
 *   port: DP receiver 0 or 1
 * Called by audio_update_dp_32k_mode.
 */
unsigned int audio_calc_dp_sample_rate(unsigned char port)
{
    unsigned int maud, naud, rate_hz;

    maud = audio_read_dp_maud(port);
    naud = audio_read_dp_naud(port);
    switch (dp_get_link_rate_index(port) & 0xff) {
    default:
        rate_hz = maud * DP_RATE_INDEX_0 / 64 * 1250 / naud * 100;
        break;
    case 1:
        rate_hz = maud * DP_RATE_INDEX_1 / 64 * 1250 / naud * 100;
        break;
    case 2:
        rate_hz = maud * DP_RATE_INDEX_2 / 64 * 1250 / naud * 100;
        break;
    case 3:
        rate_hz = maud * DP_RATE_INDEX_3 / 64 * 1250 / naud * 100;
        break;
    }
    return rate_hz;
}
