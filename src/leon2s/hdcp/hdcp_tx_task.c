/* hdcp_tx_task  (FUN_a00d17a8)
 *
 * Run the copy-protection service for the three video outputs.
 * Name basis: derived - per port: link state, flag and time stamp, then hdcp_tx_service_port
 *
 * Matching notes
 * --------------
 * FUN_a00d17a8 (leon2s 0xa00d17a8-0xa00d1b04, 860 bytes), flags -mcpu=v8 -Os -g.
 * The ROM calls input_get_port_option, dp_tx_is_connected, timer_get_ticks and hdmi_tx_reg_read8 are the labels
 * func_0xa0f803b8, func_0xa0f98af0, func_0xa0fc2064 and func_0xa0fb7fd8.
 * Source form: the output 2 block indexes its data and calls with i (inside 'if (i == 2)'), as the output 0/1
 * block does; the time-out test is 'b31 && elapsed > 5000' with 'else if (b31)'.
 */
/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records); only bit 31 of word 0 is named. */
struct hdcp_tx_record {
    unsigned int b31 : 1;
    unsigned int rest : 31;
    unsigned char _4[0x18 - 4];
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_task_flags[];
extern unsigned int hdcp_tx_task_ticks[];
extern unsigned char hdmi_tx_output_records[][0x1c];
extern unsigned char input_get_port_option(unsigned char);
extern unsigned char dp_tx_is_connected(unsigned char);
extern unsigned int timer_get_ticks(void);
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, unsigned short);
extern int dbg_printf(const char *, ...);
extern unsigned char hdcp_tx_hdmi_get_reg9_bit2(unsigned char);
extern void hdcp_tx_init_port_record(unsigned char, unsigned char);
extern unsigned char input_port_code_to_index(unsigned char);
extern void hdcp_tx_disable_output(unsigned char);
extern void hdcp_tx_service_port(unsigned char);

/* Copy-protection service of the three video outputs, run once per call.
 *
 * For each output i = 0..2 (0 and 1 are the HDMI outputs, 2 the DisplayPort output) for which
 * input_get_port_option(i) is non-zero, it tracks whether the sink is attached with a per-output flag (hdcp_tx_task_flags[i])
 * and a time stamp (hdcp_tx_task_ticks[i]). While the sink is attached the output's handshake is serviced by
 * hdcp_tx_service_port(i). When it is not attached the output is skipped; the record's bit 31 (set by
 * hdcp_tx_init_port_record) then gets 5000 ticks after the time stamp and is re-initialised afterwards.
 *
 * - Output 2: attached = dp_tx_is_connected(0). Newly attached (flag 0): the record is initialised with
 *   hdcp_tx_init_port_record(2, 1) when more than 1 tick passed since the stored time or the time is 0.
 *   Not attached: a flag of 1 stores the time; with bit 31 set and more than 5000 ticks passed the record is
 *   initialised again, bit 31 and the time are cleared; otherwise bit 31 alone clears the flag.
 * - Outputs 0 and 1: attached = bit 1 of hdmi_tx_reg_read8(i, 0, 9) set and hdcp_tx_hdmi_get_reg9_bit2(i) == 1.
 *   Newly attached (flag 0) after more than 0x5a ticks (or time 0): prints "link[%02X] short pulse", initialises
 *   the record and calls input_port_code_to_index on byte 1 of hdmi_tx_output_records[i]. Not attached: a flag of 1 calls
 *   hdcp_tx_disable_output(i) and stores the time; then the same bit 31 time-out as for output 2.
 * The flag is set to 1 on every attached pass.
 */
void hdcp_tx_task(void)
{
    unsigned char i;

    for (i = 0; i <= 2; i++) {
        if (i == 0) {
            if (!input_get_port_option(0))
                continue;
        }
        if (i == 1) {
            if (!input_get_port_option(1))
                continue;
        }
        if (i == 2) {
            if (!input_get_port_option(2))
                continue;
        }
        if (i == 2) {
            if (dp_tx_is_connected(0)) {
                if (hdcp_tx_task_flags[i] == 0) {
                    if (timer_get_ticks() - hdcp_tx_task_ticks[i] > 1 || hdcp_tx_task_ticks[i] == 0)
                        hdcp_tx_init_port_record(i, 1);
                }
                hdcp_tx_task_flags[i] = 1;
            } else {
                if (hdcp_tx_task_flags[i] == 1)
                    hdcp_tx_task_ticks[i] = timer_get_ticks();
                /* Time-out of 5000 ticks after the sink went away. */
                if (hdcp_tx_records[i].b31 && timer_get_ticks() - hdcp_tx_task_ticks[i] > 5000) {
                    hdcp_tx_init_port_record(i, 1);
                    hdcp_tx_records[i].b31 = 0;
                    hdcp_tx_task_ticks[i] = 0;
                } else if (hdcp_tx_records[i].b31)
                    hdcp_tx_task_flags[i] = 0;
                continue;
            }
        }
        if (i <= 1) {
            if ((hdmi_tx_reg_read8(i, 0, 9) & 2) && hdcp_tx_hdmi_get_reg9_bit2(i) == 1) {
                if (hdcp_tx_task_flags[i] == 0) {
                    if (timer_get_ticks() - hdcp_tx_task_ticks[i] > 0x5a || hdcp_tx_task_ticks[i] == 0) {
                        dbg_printf("\nlink[%02X] short pulse", i);
                        hdcp_tx_init_port_record(i, 1);
                        input_port_code_to_index(hdmi_tx_output_records[i][1]);
                    }
                }
                hdcp_tx_task_flags[i] = 1;
            } else {
                if (hdcp_tx_task_flags[i] == 1) {
                    hdcp_tx_disable_output(i);
                    hdcp_tx_task_ticks[i] = timer_get_ticks();
                }
                /* Time-out of 5000 ticks after the sink went away. */
                if (hdcp_tx_records[i].b31 && timer_get_ticks() - hdcp_tx_task_ticks[i] > 5000) {
                    hdcp_tx_task_ticks[i] = 0;
                    hdcp_tx_init_port_record(i, 1);
                    hdcp_tx_records[i].b31 = 0;
                } else if (hdcp_tx_records[i].b31)
                    hdcp_tx_task_flags[i] = 0;
                continue;
            }
        }
        hdcp_tx_service_port(i);
    }
}
