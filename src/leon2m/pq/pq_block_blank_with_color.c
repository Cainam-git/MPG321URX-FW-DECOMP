/* pq_block_blank_with_color  (FUN_a0106bfc)
 *
 * Blank a picture block with a given value and re-apply the output timing.
 * Name basis: derived - register 0x6B, then as pq_block_blank; used by the colour fill and the power sequencer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106bfc @ 0xa0106bfc (-mcpu=v8 -O3 -g)
 * Source form: the untyped declarations, the row read through raw offsets and the 64-bit return expression are
 * kept as they are; the two dead stores to block and red before the final return model the values left in the
 * return registers.
 */

/* The working copy of the active panel timing row. */
extern unsigned int panel_working_row_ptr;

/* Registers of a picture block. */
#define BLK_BLANK_MODE       0x54   /* blanking mode, bits 0..1 */
#define BLANK_MODE_2         2      /* the blanking mode this routine sets */
#define BLANK_MODE_3         3      /* another blanking mode; also skips the body */
#define BLANK_COLOR_RED_REG  0x6b   /* the three blanking colour components */
#define BLANK_COLOR_GREEN_REG 0x6c
#define BLANK_COLOR_BLUE_REG 0x6d

#define LAST_COLOUR_BLOCK    3      /* only picture blocks 0..3 are blanked here (the code tests block < 4) */

#define REG_11658 (*(volatile unsigned int *)0xcf011658)   /* also written 0x40 by the output timing set-up */

#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

extern int pq_block_read8();
extern void pq_block_write8();
extern int panel_output_apply_timing();
extern void panel_set_pll_frequency();
extern int pq_block_set_output_path();
extern void pq_port_set_reg10_bit0();
extern void reg_set_channel_ctrl_bit();

/*
 * Blank a picture block with a solid colour and re-apply the panel output timing.
 *
 *   block  0..3: the picture block to blank; for 4 and above only register 0x54 is read and the final
 *          register write done
 *   red, green, blue   the three 8-bit colour components of the blanking colour
 *
 * When register 0x54 bits 0..1 of the block are neither 2 nor 3 (read once for each test), it writes the colour
 * to registers 0x6B..0x6D, sets bit <block> of the channel control register (reg_set_channel_ctrl_bit) and
 * bit 0 of block register 0x10, writes mode 2 to register 0x54 and switches the block's output path off. For
 * block 0 it then applies the output timing of picture block 0 and sets the four display clock generators from
 * the working panel row: GPLL_DISPM = line rate (+0x34, tenths of Hz, / 10) * middle horizontal total (+0x22),
 * DISP1 and DISP2 half of that, DISP3 a quarter. In every case 0x40 is written to 0xCF011658 at the end.
 *
 * Callers: pq_api_set_fill_color, panel_power_sequencer_task.
 */
void pq_block_blank_with_color(unsigned int block,unsigned int red,unsigned char green,unsigned char blue)

{
  unsigned int v;
  
  block = block & 0xff;
  v = pq_block_read8(block,BLK_BLANK_MODE);
  if ((v & 3) != BLANK_MODE_2) {
    v = pq_block_read8(block,BLK_BLANK_MODE);
    if ((v & 3) != BLANK_MODE_3) {
      if (block < 4) {
        pq_block_write8(block,BLANK_COLOR_RED_REG,red & 0xff);
        pq_block_write8(block,BLANK_COLOR_GREEN_REG,green);
        pq_block_write8(block,BLANK_COLOR_BLUE_REG,blue);
        reg_set_channel_ctrl_bit(block,1);
        pq_port_set_reg10_bit0(block,1);
        pq_block_write8(block,BLK_BLANK_MODE,BLANK_MODE_2);
        pq_block_set_output_path(block,0);
      }
      if (block == 0) {
        red = 0xa802d400;                                    /* dead store: leftover return value (unused) */
        panel_output_apply_timing(0);
        block = 0xcccccc00;                                  /* dead store: leftover return value (unused) */
        v = (*(unsigned int *)(panel_working_row_ptr + 0x34) / 10) * (unsigned int)*(unsigned short *)(panel_working_row_ptr + 0x22);
        panel_set_pll_frequency(0,v);
        panel_set_pll_frequency(1,v >> 1);
        panel_set_pll_frequency(2,v >> 1);
        panel_set_pll_frequency(3,v >> 2);
      }
    }
  }
  REG_11658 = 0x40;
  return CONCAT44(red,block);
}
