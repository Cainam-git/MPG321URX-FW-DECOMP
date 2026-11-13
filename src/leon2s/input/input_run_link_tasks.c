/* input_run_link_tasks  (FUN_a006fa28)
 *
 * Run the link state machines of all HDMI and DP ports once.
 * Name basis: proven - called every main-loop pass; records 0/1 TMDS, 2/3 HDMI 2.1, 4/5 DP state machines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006fa28 @ 0xa006fa28, flags -mcpu=v8 -Os -g.
 * The last call is a tail call.
 */

/* Port records: 20 bytes per input stream, byte +0 is the link state (see docs/DATA.md). */
struct port_record { unsigned char state; unsigned char rest[19]; };
extern struct port_record input_port_records[];
extern void input_load_port_flag_bits(void);
extern void hdmi_tmds_run_link_state(struct port_record *, unsigned char);
extern void hdmi_rx21_run_link_state(struct port_record *, unsigned char);
extern void dp_run_link_state(struct port_record *, unsigned char, unsigned int);
extern void audio_run_service(void);

/*
 * Run the link state machine of each of the six HDMI / DisplayPort inputs once (records 0 and 1: HDMI 2.0, 2 and
 * 3: HDMI 2.1, 4 and 5: DisplayPort; the second argument is the input's number within its kind). Called every
 * main-loop pass.
 */
void input_run_link_tasks(void)
{
    input_load_port_flag_bits();
    hdmi_tmds_run_link_state(&input_port_records[0], 0);
    hdmi_tmds_run_link_state(&input_port_records[1], 1);
    hdmi_rx21_run_link_state(&input_port_records[2], 0);
    hdmi_rx21_run_link_state(&input_port_records[3], 1);
    dp_run_link_state(&input_port_records[4], 0, 0);
    dp_run_link_state(&input_port_records[5], 1, 4);
    audio_run_service();
}
