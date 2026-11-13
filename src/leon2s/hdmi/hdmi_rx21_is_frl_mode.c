/* hdmi_rx21_is_frl_mode  (FUN_a00a29b0)
 *
 * Return whether an HDMI 2.1 receiver runs in FRL (not TMDS) mode.
 *   port: receiver
 * Returns: 1 in FRL mode
 * Name basis: derived - hdmi_rx21_get_link_rate_code != 0; mailbox command 0x83
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a29b0 @ 0xa00a29b0, flags -mcpu=v8 -Os -g.
 * Source form: the result is a flag set on one path and returned as "is_frl & 1" (not the callee's value).
 */
extern unsigned char hdmi_rx21_get_link_rate_code(unsigned char);

/* 1 when the receiver has a non-zero link rate code (it is in FRL mode), else 0. */
unsigned char hdmi_rx21_is_frl_mode(unsigned char port)
{
    unsigned char is_frl = 0;

    if (hdmi_rx21_get_link_rate_code(port) != 0)
        is_frl = 1;
    return is_frl & 1;
}
