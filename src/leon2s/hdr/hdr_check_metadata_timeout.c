/* hdr_check_metadata_timeout  (FUN_a00624b4)
 *
 * Clear the HDR10+ metadata-present flag when no new packet arrived for 200 ticks.
 * Returns: 1 while metadata is present
 * Name basis: derived - flag and time stamp set by hdr_update_hdr10plus_metadata when a valid packet is seen
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00624b4 @ 0xa00624b4-0xa006250c (22 words), flags -mcpu=v8 -Os -g.
 * The time stamp is read before the flag test and is not volatile. The result is the flag, read again.
 * Source form: the wrap arm is the explicit '0xffffffff - last + now' with the '>=' arm first (a 'd--' or
 * 'd - 1' form is merged into one subx).
 */
#define HDR10PLUS_TIMEOUT_TICKS 200             /* ticks without a valid HDR10+ packet before the flag is cleared */

extern unsigned char hdr10plus_present_flag;
extern unsigned int hdr10plus_last_ticks;
extern unsigned int timer_get_ticks(void);

/*
 * Clear hdr10plus_present_flag when more than 200 ticks have passed since the last valid HDR10+ packet
 * (hdr_update_hdr10plus_metadata sets the flag and the time stamp hdr10plus_last_ticks when it sees one).
 * A tick counter that has wrapped since the time stamp is taken into account.
 * Returns the flag: 1 while HDR10+ metadata is present, 0 otherwise.
 */
unsigned char hdr_check_metadata_timeout(void)
{
    unsigned int now;
    unsigned int elapsed;
    unsigned int last = hdr10plus_last_ticks;
    if (hdr10plus_present_flag == 0)
        return 0;
    now = timer_get_ticks();
    if (now >= last)
        elapsed = now - last;
    else
        elapsed = 0xffffffff - last + now;
    if (elapsed > HDR10PLUS_TIMEOUT_TICKS)
        hdr10plus_present_flag = 0;
    return hdr10plus_present_flag;
}
