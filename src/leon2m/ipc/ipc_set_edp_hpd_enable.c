/* ipc_set_edp_hpd_enable  (FUN_a01381c4)
 *
 * Send the eDP hotplug-enable byte to the input processor.
 *   edp_hpd_enable: the enable byte (1 or 0)
 * Note: With 0 the input processor forces a hotplug check on each eDP output 1..4 whose mode update was
 *   requested.
 * Name basis: derived - command 0x75 through the mailbox portal 1 sender; its handler in the input program
 *   stores the byte as dp_tx_edp_hpd_enable; called by the panel power sequencer with 1 and 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01381c4 @ 0xa01381c4, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the one parameter.
 */
#define IPC_CMD_SET_EDP_HPD_ENABLE 0x75         /* mailbox command 0x75 */
#define IPC_SEND_NO_WAIT           0            /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();

/*
 * Send the eDP hotplug-enable value to the input processor (mailbox command 0x75). The input processor keeps
 * it; when it is 0, every eDP output 1..4 whose mode update was requested gets a forced hotplug check.
 *
 *   edp_hpd_enable  the value to keep
 *
 * Called from panel_power_sequencer_task.
 */
void ipc_set_edp_hpd_enable(unsigned char edp_hpd_enable)
{
    unsigned char msg[4] = {edp_hpd_enable};
    ipc_send_command(IPC_CMD_SET_EDP_HPD_ENABLE, 4, msg, IPC_SEND_NO_WAIT);
}
