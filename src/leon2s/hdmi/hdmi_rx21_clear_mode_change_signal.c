/* hdmi_rx21_clear_mode_change_signal  (FUN_a00a2a04)
 *
 * Clear the mode-change signal bit of an HDMI 2.1 receiver.
 *   receiver
 * Name basis: derived - bit p + 2 of shared register 0xCF03C890, set by hdmi_rx21_detect_timing_change; caller
 *   hdmi_rx21_run_link_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2a04 @ 0xa00a2a04, flags -mcpu=v8 -Os -g.
 */
#define reg_ipc_shared_hdmi_status (*(volatile unsigned int *)0xcf03c890)

/* Clear the mode-change signal of the HDMI 2.1 receiver (0 or 1): bit (receiver + 2) of the shared status
   register. The signal is set by the mode-change reports of the HDMI 2.1 code. */
void hdmi_rx21_clear_mode_change_signal(unsigned char receiver)
{
    unsigned int mask = 4 << receiver;
    reg_ipc_shared_hdmi_status = reg_ipc_shared_hdmi_status & ~mask;
}
