/* sys_fill_output_size_record  (FUN_a012b9a8)
 *
 * Fill four size values of a record from the output blocks and derive four more from them.
 * Name basis: descriptive - one of three getter sets; derived values by /3 and *2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b9a8 @ 0xa012b9a8-0xa012bae0 (78 words).
 */
/* Size block of one output (the same tag as in sys_report_output_timing): eight halfword values, then two bytes. */
struct output_size_block
{
  unsigned short h0, h1, h2, h3, h4, h5, h6, h7;
  unsigned char pad[4];
  unsigned char byte_0x14;
  unsigned char bits_per_colour;                /* +0x15 */
  unsigned char pad2[2];
};
extern unsigned char input_block_get_status_bit2(unsigned char port);
extern unsigned char panel_output_get_source_select(void);
extern unsigned char sys_frc_is_running(void);
extern unsigned short pq_block_read_reg5e_word_copy(unsigned char);
extern unsigned short pq_block_read_reg5b_word_copy(unsigned char);
extern unsigned short pq_block_read_reg68_word_copy(unsigned char);
extern unsigned short pq_block_read_reg64_word_copy(unsigned char);
extern unsigned short sys_frc_get_output_active_width(void);
extern unsigned short sys_frc_get_output_line_length(void);
extern unsigned short sys_frc_get_output_active_height(void);
extern unsigned short sys_frc_get_output_frame_length(void);

#define SOURCE_SELECT_BLOCK4 4                  /* output source select value that reads picture block 4 */

/*
 * Fill halfwords h0..h7 of block with the output size, as two groups of four.
 *
 * h0..h3 come from picture block 4 when panel_output_get_source_select() is 4, else from picture block 0 when
 * the FRC is not running, else from the FRC getters (h0 line length, h1 frame length, h2 active width,
 * h3 active height). Picture block registers read: h0 0x5e, h1 0x5b, h2 0x68, h3 0x64.
 * Then h4 = (h0 - h2) / 3, h5 = 2 * h4, h6 = (h1 - h3) / 3, h7 = 2 * h6 (signed division).
 *
 *   port   passed to input_block_get_status_bit2, whose result is not used
 *   block  the block to fill; the other fields are left alone
 *
 * Called by sys_report_output_timing.
 */
void sys_fill_output_size_record(unsigned char port, struct output_size_block *block)
{
    input_block_get_status_bit2(port);
    if (panel_output_get_source_select() == SOURCE_SELECT_BLOCK4) {
        block->h0 = pq_block_read_reg5e_word_copy(4);
        block->h1 = pq_block_read_reg5b_word_copy(4);
        block->h2 = pq_block_read_reg68_word_copy(4);
        block->h3 = pq_block_read_reg64_word_copy(4);
    } else if (!sys_frc_is_running()) {
        block->h0 = pq_block_read_reg5e_word_copy(0);
        block->h1 = pq_block_read_reg5b_word_copy(0);
        block->h2 = pq_block_read_reg68_word_copy(0);
        block->h3 = pq_block_read_reg64_word_copy(0);
    } else {
        block->h2 = sys_frc_get_output_active_width();
        block->h0 = sys_frc_get_output_line_length();
        block->h3 = sys_frc_get_output_active_height();
        block->h1 = sys_frc_get_output_frame_length();
    }
    block->h4 = (block->h0 - block->h2) / 3;
    block->h5 = block->h4 * 2;
    block->h6 = (block->h1 - block->h3) / 3;
    block->h7 = block->h6 * 2;
}
