/* pq_block_set_fill_color  (FUN_a0118a80)
 *
 * Write the three fill colour values of a picture block.
 * Name basis: derived - registers 0x14, 0x15 and 0x16; used by pq_api_set_fill_color
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118a80 @ 0xa0118a80 (-mcpu=v8 -O2 -g)
 * Source form: the untyped declaration of pq_port_write8 is kept; the last call passes blue and the two unused
 * parameters again, and the 64-bit return expression and the unused blue_reg store keep the firmware's return
 * register set-up.
 */

/* The three fill colour registers of a port block. */
enum {
    FILL_COLOR_RED_REG   = 0x14,
    FILL_COLOR_GREEN_REG = 0x15,
    FILL_COLOR_BLUE_REG  = 0x16
};

#define LAST_FILL_COLOUR_PORT 3   /* only port blocks 0..3 are written here */

#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

/* port block, register offset, value; port block 8 writes the register of all four port blocks. */
extern void pq_port_write8();

/*
 * Write the three fill colour components (red, green, blue) of a port block into its registers
 * 0x14, 0x15 and 0x16.
 *
 *   port  0..3: the port block whose fill colour is set (pq_port_write8); 4 and above writes nothing
 *   red, green, blue   the three 8-bit colour components
 *
 * Callers: pq_api_set_fill_color (the port of the channel, after pq_block_set_blank_color) and
 * sys_mode_restart_channel (black).
 */
void pq_block_set_fill_color(unsigned int port, unsigned char red, unsigned char green,
            unsigned int blue, unsigned int unused1, unsigned int unused2)

{
  unsigned int blue_reg;
  
  port = port & 0xff;
  if (LAST_FILL_COLOUR_PORT < port) {
    return CONCAT44(FILL_COLOR_BLUE_REG,port);
  }
  pq_port_write8(port,FILL_COLOR_RED_REG,red);
  pq_port_write8(port,FILL_COLOR_GREEN_REG,green);
  blue_reg = FILL_COLOR_BLUE_REG;
  return pq_port_write8(port,FILL_COLOR_BLUE_REG,blue & 0xff,blue,unused1,unused2);
}
