/* hdmi_tx_print_frl_rate  (FUN_a0094fb0)
 *
 * Print the FRL rate of an HDMI TX port as text.
 *   frl_rate: FRL rate 0..6
 * Name basis: proven - prints 'FRL Rate = DISABLE / 3G/3L / .. / 12G/4L / NG'
 *
 * Matching notes
 * --------------
 * FUN_a0094fb0 (leon2s 0xa0094fb0-0xa0095054, 164 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: an if/else chain with one call per arm (the firmware shares the call). The texts at the eight
 * addresses are not named in the data list; see the proposals in header_fixes.
 */
extern char DAT_a00691f0[], DAT_a0069210[], DAT_a0069230[], DAT_a0069250[], DAT_a0069270[], DAT_a0069290[], DAT_a00692b0[],
    DAT_a00692d0[];
extern int dbg_print_string(const char *);

/*
 * Print the FRL rate as a debug text 'FRL Rate = ...'.
 *   frl_rate: 0 = DISABLE, 1 = 3G/3L, 2 = 6G/3L, 3 = 6G/4L, 4 = 8G/4L, 5 = 10G/4L, 6 = 12G/4L; any other value
 *     prints NG
 * Every arm of the chain is one call of dbg_print_string with a different text.
 * Called by hdmi_tx_run_setup_steps with the channel's frl_rate.
 */
void hdmi_tx_print_frl_rate(unsigned char frl_rate)
{
    if (frl_rate == 0)
        dbg_print_string(DAT_a00691f0);
    else if (frl_rate == 1)
        dbg_print_string(DAT_a0069210);
    else if (frl_rate == 2)
        dbg_print_string(DAT_a0069230);
    else if (frl_rate == 3)
        dbg_print_string(DAT_a0069250);
    else if (frl_rate == 4)
        dbg_print_string(DAT_a0069270);
    else if (frl_rate == 5)
        dbg_print_string(DAT_a0069290);
    else if (frl_rate == 6)
        dbg_print_string(DAT_a00692d0);
    else
        dbg_print_string(DAT_a00692b0);
}
