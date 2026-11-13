/* hdmi_tx_run_frl_training  (FUN_a00a4658)
 *
 * Run the FRL link-training state machine of both HDMI TX ports and re-arm its timer.
 * Name basis: derived - timer callback; calls DRV_HDMI21_TXDetect_FSM_* from table 0xA00B4CF8 while they
 *   return non-zero
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a4658 @ 0xa00a4658, flags -mcpu=v8 -Os -g.
 * Source forms: the channel record is declared with only the word at +0x14 named; the state handlers are an
 * array of function pointers called in an empty while loop; the link flag is set in an if/else.
 */
/* Descriptor of the timer (see hdmi_tx_frl_init_timer). */
struct hdmi_tx_timer_desc { unsigned int periodic; unsigned int period; void (*fn)(void); };
/* Record of an HDMI transmitter channel (28 bytes, table hdmi_tx_output_records); only the word at +0x14 is used here. */
struct hdmi_tx_channel_record { unsigned char pad[0x14]; unsigned int word_0x14; unsigned char rest[4]; };
extern struct hdmi_tx_timer_desc hdmi_tx_frl_timer;
extern unsigned int hdmi_tx_frl_timer_period;
extern unsigned char hdmi_tx_frl_link_flags[];
extern unsigned char hdmi_tx_frl_done_flags[];
extern unsigned int hdmi_tx_frl_states[];                     /* training state of each port */
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned char (*hdmi_tx_frl_training_state_handlers[])(unsigned char);
extern short hdmi_tx_reg_read8(unsigned int, unsigned short, unsigned short);
extern unsigned char hdmi_tx_get_ctrl_bit31(unsigned char);
extern unsigned int hdmi_tx_is_active(unsigned char);
extern void sys_task_start(struct hdmi_tx_timer_desc *);

/*
 * Timer callback of the HDMI TX FRL link training. For each of the two ports, in turn:
 *  - hdmi_tx_frl_link_flags[port] is bit 1 of bank 0 register 9 of the transmitter;
 *  - the port's training state is set to 0 when that flag is clear, or when the port is neither "control bit 31
 *    set and bit 11 of record word +0x14 set" nor active;
 *  - otherwise, if the done flag is set and the state is above 1, the state goes back to 2 and the done flag is
 *    cleared; then the handler of the current state (hdmi_tx_frl_training_state_handlers) is called again as
 *    long as it returns non-zero;
 *  - the timer is re-armed with hdmi_tx_frl_timer_period.
 */
void hdmi_tx_run_frl_training(void)
{
    unsigned char port;

    port = 0;
    do {
        if (hdmi_tx_reg_read8(port, 0, 9) & 2)
            hdmi_tx_frl_link_flags[port] = 1;
        else
            hdmi_tx_frl_link_flags[port] = 0;
        if (hdmi_tx_frl_link_flags[port] == 0
            || (((unsigned char)hdmi_tx_get_ctrl_bit31(port) == 0 || (hdmi_tx_output_records[port].word_0x14 & 0x800) == 0)
                && (unsigned char)hdmi_tx_is_active(port) == 0)) {
            hdmi_tx_frl_states[port] = 0;
        } else {
            if (hdmi_tx_frl_done_flags[port] != 0 && hdmi_tx_frl_states[port] > 1) {
                hdmi_tx_frl_states[port] = 2;
                hdmi_tx_frl_done_flags[port] = 0;
            }
            while (hdmi_tx_frl_training_state_handlers[hdmi_tx_frl_states[port]](port))
                ;
        }
        hdmi_tx_frl_timer.period = hdmi_tx_frl_timer_period;
        sys_task_start(&hdmi_tx_frl_timer);
        port++;
    } while (port <= 1);
}
