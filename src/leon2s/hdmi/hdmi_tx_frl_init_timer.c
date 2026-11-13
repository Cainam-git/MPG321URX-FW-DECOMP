/* hdmi_tx_frl_init_timer  (FUN_a00a4610)
 *
 * Create the HDMI TX FRL training timer with its callback.
 *   param_1: 0 = create
 * Name basis: derived - descriptor 0xA8079218 = {0, period, hdmi_tx_run_frl_training}; caller hdmi_tx_init
 *
 * Matching notes
 * --------------
 * FUN_a00a4610 (leon2s, 0xa00a4610), flags -mcpu=v8 -Os -g.
 * Leaf frame with a tail call (mov %o7,%g1 / call / mov %g1,%o7). Source form: the descriptor is a struct symbol and
 * the callback address is stored as an unsigned int; the clear of the first word comes first in the firmware.
 */
/* Descriptor of the timer: periodic flag, period in ticks, callback address. */
struct hdmi_tx_timer_desc { unsigned int periodic; unsigned int period; unsigned int fn; };
extern unsigned int hdmi_tx_frl_timer_init_period;
extern struct hdmi_tx_timer_desc hdmi_tx_frl_timer;
extern unsigned int hdmi_tx_run_frl_training();
extern int sys_task_create();

/* With param_1 = 0: fill the descriptor of the FRL training timer (not periodic, the period taken from the word
   at 0xA8079214, callback hdmi_tx_run_frl_training) and register it with sys_task_create. Any other value
   does nothing. Called by hdmi_tx_init. */
void hdmi_tx_frl_init_timer(int param_1)
{
    if (param_1 == 0) {
        hdmi_tx_frl_timer.periodic = 0;
        hdmi_tx_frl_timer.fn = (unsigned int)hdmi_tx_run_frl_training;
        hdmi_tx_frl_timer.period = hdmi_tx_frl_timer_init_period;
        sys_task_create(&hdmi_tx_frl_timer);
    }
}
