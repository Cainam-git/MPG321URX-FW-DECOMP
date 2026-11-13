/* hdcp_is_ksv_valid  (FUN_a00c83e4)
 *
 * Check that a 5-byte key-selection value has exactly twenty one-bits.
 * Returns: 1 when valid
 * Name basis: proven - counts the set bits of five bytes; the rule of the HDCP specification
 *
 * Matching notes
 * --------------
 * FUN_a00c83e4 (leon2s 0xa00c83e4-0xa00c8444, 96 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the loop works on ksv[i] directly (GCC keeps the byte in a register and stores it once after the
 * inner loop); total and i are both initialised to 0 at their declarations (i's start value is then copied from
 * total's register). The return type is char, as its caller declares it.
 */
#define KSV_LENGTH     5                        /* bytes of the value */
#define KSV_ONES_COUNT 20                       /* number of set bits a valid value has */

/*
 * Count the set bits of the 5-byte key-selection value ksv and return 1 when there are exactly 20, else 0. The
 * bytes of ksv are cleared by the count (each loop step removes the lowest set bit).
 *
 * Called by hdcp_tx_hdmi_read_bksv.
 */
char hdcp_is_ksv_valid(unsigned char *ksv)
{
    unsigned char total = 0;
    unsigned char i = 0;
    unsigned char n;

    for (i = 0; i < KSV_LENGTH; i++) {
        n = 0;
        while (ksv[i]) {
            ksv[i] &= ksv[i] - 1;
            n++;
        }
        total += n;
    }
    return total == KSV_ONES_COUNT;
}
