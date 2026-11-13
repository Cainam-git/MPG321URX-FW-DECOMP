/* input_poll_port_services  (FUN_a006d050)
 *
 * Run one pass of the receiver, DP output and cable-state service routines of the main loop.
 * Name basis: descriptive - called every main-loop pass; 16 service calls then 'Reliable Check Error!!' when
 *   the port-state read fails
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. The routine's end is merged with the unreachable ret/restore tail
 * FUN_a006d0f4 (43 words in all). The final print is a tail call with one argument.
 */
typedef unsigned int uint;
typedef unsigned long long undefined8;
typedef unsigned int undefined4;

extern void dp_update_pending_bits(void);
extern int dp_port_task(int);
extern int dp_tx_run_output_tasks(void);
extern void hdmi_tx_run_service(void);
extern void dp_mst_select_port(int);
extern void dp_mst_task(void);
extern void input_run_port_services(void);
extern void dp_tx_update_hpd_status(int);
extern void sys_dsc_dec_run_state(int);
extern void hdmi_clear_packet_update_flags(int);
extern void hdmi_rx21_clear_status_flags(int);
extern int input_set_ports_power_on_by_status(int);
extern void dbg_print_string(unsigned int *);
extern unsigned int DAT_a0065c00; /* "Reliable Check Error!!\r" */

/*
 * One pass of the input program's service work, called from the main loop right after sys_task_run_pending.
 * It runs, in this order: the DP pending-bit update, the DP port task for port 0 and 1, the DP transmitter
 * output tasks, the HDMI transmitter service, the DP MST task for port 0 and for port 1 (each after selecting
 * the port), the input port service, the DP transmitter HPD update (argument 3), the DSC decoder state, and the
 * HDMI packet-flag clear and HDMI 2.1 status-flag clear for port 0 and 1.
 * Last it calls input_set_ports_power_on_by_status(9); that routine returns -1 only for an argument other than 9, so the
 * 'Reliable Check Error!!' text is printed only in that case.
 */
void input_poll_port_services(void)
{
    int iVar1;
    
    dp_update_pending_bits();
    dp_port_task(0);
    dp_port_task(1);
    dp_tx_run_output_tasks();
    hdmi_tx_run_service();
    dp_mst_select_port(0);
    dp_mst_task();
    dp_mst_select_port(1);
    dp_mst_task();
    input_run_port_services();
    dp_tx_update_hpd_status(3);
    sys_dsc_dec_run_state(0);
    hdmi_clear_packet_update_flags(0);
    hdmi_clear_packet_update_flags(1);
    hdmi_rx21_clear_status_flags(0);
    hdmi_rx21_clear_status_flags(1);
    /* Updates the link state of the nine port records from the status register. */
    iVar1 = input_set_ports_power_on_by_status(9);
    if (iVar1 != -1) {
        return;
    }
    dbg_print_string(&DAT_a0065c00);
}
