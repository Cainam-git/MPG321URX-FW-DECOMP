/* input_query_port_timing  (FUN_a013dbcc)
 *
 * Fetch the 16-byte measured timing report of the input behind a block (signal codes 0x51..0x81).
 * Note: For any other signal code nothing is written. The second argument is not used.
 * Name basis: derived - ipc_get_input_timing for input 0..3 chosen by the block's signal code; result stored
 *   through the third argument
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013dbcc @ 0xa013dbcc, flags -mcpu=v8 -O2 -g (cflags in symbols/leon2m.json; -msoft-float gives the same
 * object). Same compile unit as input_channel_bring_up_task, which calls it.
 * Source form the exact build depends on: every case has its own call and its own copy. The compiler merges the four
 * copies into one call block, and the summed frequency of that block gives the firmware's case-tree layout (the
 * subtree above 0x61 inline, 0x51 out of line). The one-call form (set an index in each case, call once after the
 * switch) gives another layout.
 */

/* The measured timing of one input as the input processor reports it: 16 bytes. */
struct input_timing_report { unsigned short half[8]; };
extern unsigned char input_block_get_signal_code(unsigned char block);
extern void ipc_get_input_timing(int input, struct input_timing_report *report);

/*
 * Fetch the measured timing of the input behind a block into *out.
 *
 *   block   the input block
 *   unused  not used (the caller passes a buffer pointer here)
 *   out     receives the 16-byte report
 *
 * The signal code of the block selects the input: 0x51, 0x61, 0x71, 0x81 are inputs 0 to 3. For any other
 * code nothing is written.
 */
void input_query_port_timing(unsigned char block, unsigned int unused, struct input_timing_report *out)
{
  struct input_timing_report report;

  switch (input_block_get_signal_code(block)) {
  case 0x51:
    ipc_get_input_timing(0, &report);
    *out = report;
    break;
  case 0x61:
    ipc_get_input_timing(1, &report);
    *out = report;
    break;
  case 0x71:
    ipc_get_input_timing(2, &report);
    *out = report;
    break;
  case 0x81:
    ipc_get_input_timing(3, &report);
    *out = report;
    break;
  }
}
