/* sys_report_output_timing  (FUN_a012bc08)
 *
 * Build the output timing record of a channel and report it to the input processor.
 * Name basis: derived - from the active panel timing row; mailbox commands 0x50 and 0x51; unused directly
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012bc08, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the output record EMBEDS the size block type (struct output_size_block timing at +4) and the block has
 *    NAMED fields h0..h7: gcc's alias analysis then knows that a load of size.hN and a store to
 *    record.timing.hM with N != M do not overlap, which gives the firmware's load / store order. With an array
 *    h[8] or two unrelated struct types the reads move next to each store;
 *  - the stores are in field order (h0..h7, byte_0x14, bits_per_colour), byte_0x1 / byte_0x2 first; the else path
 *    stores byte_0x14, bits_per_colour, then fills the message;
 *  - the record copy is written `copy = *(sys_output_records + id);` (indexing the array moves one load; a
 *    memcpy of the same size also matches);
 *  - the 0x20 case of the first chain is a real `split = 1` (gcc folds it away but the compare stays);
 *    the 0x24 / 0x25 tests are a second, separate if-chain.
 */
/* Size block filled by sys_fill_output_size_record: eight halfword values, then two bytes. */
struct output_size_block
{
  unsigned short h0, h1, h2, h3, h4, h5, h6, h7;
  unsigned char pad[4];
  unsigned char byte_0x14;
  unsigned char bits_per_colour;                /* +0x15, from the active row */
  unsigned char pad2[2];
};
/* Output record, 0x24 bytes per output, at sys_output_records. */
struct output_record
{
  unsigned char byte_0x0;
  unsigned char signal_code_1;                  /* +1 and +2 both hold the signal code of the channel */
  unsigned char signal_code_2;
  unsigned char byte_0x3;
  struct output_size_block timing;              /* +4 */
  unsigned int word_0x1c;
  unsigned int word_0x20;
};
extern struct output_record sys_output_records[];
extern unsigned char panel_active_row_bpc;
extern unsigned char *panel_get_active_row(void);
extern unsigned char input_block_get_signal_code(unsigned char);
extern void sys_fill_output_size_record(unsigned char, struct output_size_block *);
extern void ipc_set_dp_tx_timing(unsigned char, struct output_record *);
extern void ipc_send_command(int, int, void *, int);

#define ROW_DISPLAY_MODE   6    /* byte 6 of a panel timing row */
#define OUTPUT_MSG_SIZE    0x1c /* bytes of the message for command 0x51 */
#define IPC_CMD_DP_TX_TIMING_PART 0x51   /* mailbox command 0x51: another part of the timing record */

/*
 * Fill the size block of channel `ch`, store it in the output record `id` (or only report it) and send it to
 * the input processor.
 *
 *   ch      the channel whose signal code and size block are used
 *   id      output record index; for id != 0 the active row's byte 6 gives a split factor (see below)
 *   update  non-zero: store the whole timing in the record and send the record (ipc_set_dp_tx_timing,
 *           mailbox command 0x50); zero: store only byte 0x14 and the bits per colour in the record and send
 *           the 28-byte message {id, byte 0x14, bits per colour, 0 ...} as command 0x51
 *
 * The split factor is 1 for id 0. For other ids it comes from byte 6 of the active panel row (the untouched
 * copy): 0x21 gives 2, 0x22 gives 4, 0x23 gives 8, 0x25 gives 2, every other value 1. With update set, the
 * values h0, h2, h4 and h5 of the block are divided by the split factor; the others are stored as they are.
 * Both record bytes +1 and +2 get the signal code of `ch`. The bits per colour come from the active row
 * (panel_active_row_bpc). No direct caller was found.
 */
void sys_report_output_timing(unsigned char ch, unsigned char id, unsigned char update)
{
  struct output_size_block size = {0};
  unsigned char msg[OUTPUT_MSG_SIZE] = {0};
  struct output_record copy;
  unsigned char *active_row = panel_get_active_row();
  unsigned char signal_code = input_block_get_signal_code(ch);
  unsigned char split = 1;
  unsigned char bpc;
  if (id != 0)
  {
    if (active_row[ROW_DISPLAY_MODE] == 0x20) split = 1;
    else if (active_row[ROW_DISPLAY_MODE] == 0x21) split = 2;
    else if (active_row[ROW_DISPLAY_MODE] == 0x22) split = 4;
    else if (active_row[ROW_DISPLAY_MODE] == 0x23) split = 8;
    if (active_row[ROW_DISPLAY_MODE] == 0x24) split = 1;
    else if (active_row[ROW_DISPLAY_MODE] == 0x25) split = 2;
  }
  sys_fill_output_size_record(ch, &size);
  bpc = panel_active_row_bpc;
  size.bits_per_colour = bpc;
  if (update)
  {
    sys_output_records[id].signal_code_1 = signal_code;
    sys_output_records[id].signal_code_2 = signal_code;
    sys_output_records[id].timing.h0 = size.h0 / split;
    sys_output_records[id].timing.h1 = size.h1;
    sys_output_records[id].timing.h2 = size.h2 / split;
    sys_output_records[id].timing.h3 = size.h3;
    sys_output_records[id].timing.h4 = size.h4 / split;
    sys_output_records[id].timing.h5 = size.h5 / split;
    sys_output_records[id].timing.h6 = size.h6;
    sys_output_records[id].timing.h7 = size.h7;
    sys_output_records[id].timing.byte_0x14 = size.byte_0x14;
    sys_output_records[id].timing.bits_per_colour = bpc;
    copy = *(sys_output_records + id);
    ipc_set_dp_tx_timing(id, &copy);
  }
  else
  {
    sys_output_records[id].timing.byte_0x14 = size.byte_0x14;
    sys_output_records[id].timing.bits_per_colour = bpc;
    msg[0] = id;
    msg[1] = size.byte_0x14;
    msg[2] = bpc;
    ipc_send_command(IPC_CMD_DP_TX_TIMING_PART, OUTPUT_MSG_SIZE, msg, 0);
  }
}
