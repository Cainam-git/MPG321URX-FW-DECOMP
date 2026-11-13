/* pq_block_set_blank_color  (FUN_a0103808)
 *
 * Write the three blanking colour values of a picture block.
 * Name basis: derived - registers 0x6B, 0x6C and 0x6D
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0103808 @ 0xa0103808 (-mcpu=v8 -O2 -g)
 * Source form: the untyped declaration of pq_block_write8 is kept; the last call passes blue and the two unused
 * parameters again, and the 64-bit return expression and the unused blue_reg store keep the firmware's return
 * register set-up.
 */

/* The three blanking colour registers of a picture block. */
enum {
    BLANK_COLOR_RED_REG   = 0x6b,
    BLANK_COLOR_GREEN_REG = 0x6c,
    BLANK_COLOR_BLUE_REG  = 0x6d
};

#define LAST_BLANK_COLOUR_BLOCK 3   /* only picture blocks 0..3 are written here */

#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

/* block, register offset, value; block 8 writes the register of all eight blocks. */
extern void pq_block_write8();

/*
 * Write the three blanking colour components (red, green, blue) of a picture block into its
 * registers 0x6b, 0x6c and 0x6d.
 *
 *   block  0..3: the picture block whose blanking colour is set; 4 and above writes nothing
 *   red, green, blue   the three 8-bit colour components
 *
 * Callers: pq_api_set_fill_color (block = the port of the channel, after pq_block_blank_with_color
 * when it was asked to blank), pq_fga_handle_command (block 0, colour from the request), and
 * osd_draw_no_signal_with_input / osd_draw_no_signal_message (block 0, black).
 */
void pq_block_set_blank_color(unsigned int block, unsigned char red, unsigned char green,
            unsigned int blue, unsigned int unused1, unsigned int unused2)

{
  unsigned int blue_reg;
  
  block = block & 0xff;
  if (LAST_BLANK_COLOUR_BLOCK < block) {
    return CONCAT44(BLANK_COLOR_BLUE_REG,block);
  }
  pq_block_write8(block,BLANK_COLOR_RED_REG,red);
  pq_block_write8(block,BLANK_COLOR_GREEN_REG,green);
  blue_reg = BLANK_COLOR_BLUE_REG;
  return pq_block_write8(block,BLANK_COLOR_BLUE_REG,blue & 0xff,blue,unused1,unused2);
}
