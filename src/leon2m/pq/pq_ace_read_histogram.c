/* pq_ace_read_histogram  (FUN_a00f76dc)
 *
 * Read the measured sums of the ACE block when start is 0 and no measurement is pending.
 *   start: 0: read the sums when bit 0 of 0xCF00EEC4 is clear; other: read nothing, only set that bit
 *   out: receives the first 4, 8, 16 or 32 sums
 * Returns: 0 when start is 0 and bit 0 of 0xCF00EEC4 is set (nothing read), else 1 (sums read only when start
 *   is 0)
 * Note: Every call that returns 1 sets bit 0 of 0xCF00EEC4; with start not 0 nothing is read. The first 4, 8,
 *   16 or 32 sums are copied out.
 * Name basis: derived - 32 values per selection over 8 selections, added up; only caller pq_auto_level_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f76dc @ 0xa00f76dc-0xa00f7894 (110 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two bits of WINDOW_SELECT_A are read first into an unsigned char local (window_bits).
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Register names as in pq_ace_init. */
#define ACE_CURVE_CTRL 0xcf00eec4   /* bit 0: see below; bits 4 and 6 cleared for the read */
#define WINDOW_SELECT_A 0xcf00ec84  /* bits 0..1: the selected picture window */
#define ACE_CTRL 0xcf00ee80         /* bits 1..2: window for ACE access */
#define ACE_CONFIG 0xcf00eec0       /* bits 2..3: sum code (pq_ace_configure); bit 5 cleared for the read */
#define ACE_CURVE_DATA 0xcf00eec8   /* read here: three bytes per sum, low byte first */
#define REG_CF00EE84 0xcf00ee84     /* one bit per selection 0..7 */

/*
 * Read the measured sums of the ACE block.
 *
 *   start  0: read the sums when bit 0 of ACE_CURVE_CTRL is clear; other values: read nothing
 *   out    receives the first n sums, n = 4 << (ACE_CONFIG bits 2..3) = 4, 8, 16 or 32
 *
 * Bit 0 of ACE_CURVE_CTRL is set at the end of every call that does not return 0:
 *   start != 0                 -> bit 0 set, returns 1 (pq_auto_level_task uses this to start a measurement);
 *   start == 0, bit 0 set      -> returns 0, nothing read, nothing written;
 *   start == 0, bit 0 clear    -> the sums are read into out, bit 0 set, returns 1.
 *
 * The read: the window of WINDOW_SELECT_A goes to ACE_CTRL, bit 5 of ACE_CONFIG and bits 4 and 6 of
 * ACE_CURVE_CTRL are cleared, then for each selection k = 0..7 (REG_CF00EE84 = 1 << k) 32 values of three bytes
 * are read from ACE_CURVE_DATA; sum i is the total of value i over the eight selections. All 32 values are read
 * every time; only the first n are added up and copied.
 *
 * Only caller: pq_auto_level_task.
 */
unsigned char pq_ace_read_histogram(unsigned char start, unsigned int *out)
{
    unsigned int histogram_sum[32];
    unsigned char i, k, num_sums;

    if (R(ACE_CURVE_CTRL) & 1) {
        if (start == 0)
            return 0;
    } else if (start == 0) {
        {
            unsigned char window_bits = R(WINDOW_SELECT_A) & 3;

            /* Copy window select bits 0..1 to ACE_CTRL bits 1..2. */
            R(ACE_CTRL) = (R(ACE_CTRL) & 0xf9) | window_bits << 1;
        }
        /* Clear bit 5 of ACE_CONFIG and bits 4 and 6 of ACE_CURVE_CTRL. */
        R(ACE_CONFIG) &= ~0x20;
        R(ACE_CURVE_CTRL) &= 0xaf;
        for (i = 0; i < 32; i++)
            histogram_sum[i] = 0;
        num_sums = 4 << ((R(ACE_CONFIG) >> 2) & 3);
        for (k = 0; k < 8; k++) {
            R(REG_CF00EE84) = 1 << k;
            for (i = 0; i < 32; i++) {
                unsigned int byte0 = R(ACE_CURVE_DATA) & 0xff;
                unsigned int byte1 = R(ACE_CURVE_DATA) & 0xff;
                unsigned int byte2 = R(ACE_CURVE_DATA) & 0xff;

                if (i < num_sums)
                    histogram_sum[i] += byte2 << 16 | byte1 << 8 | byte0;
            }
        }
        for (i = 0; i < num_sums; i++)
            out[i] = histogram_sum[i];
    }
    R(ACE_CURVE_CTRL) |= 1;
    return 1;
}
