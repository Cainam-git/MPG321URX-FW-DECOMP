/* startup_init_path_blocks  (FUN_a01423dc)
 *
 * Initialise both signal path blocks and their selector.
 * Name basis: derived - sys_path_block_init, selector 2 and value 0x500 for both blocks; called from
 *   System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01423dc @ 0xa01423dc, flags -mcpu=v8 -O2 -g.
 * Source form: the callees are declared without prototypes.
 */

#define PATH_MUX_FIELD_START  2         /* selector value written by sys_path_set_mux_field (valid range 1..3) */
#define PATH_BLOCK_0          0
#define PATH_BLOCK_1          1
#define PATH_REG24_VALUE      0x500     /* 12-bit value of registers 0x25 / 0x26 */

extern int sys_path_block_init();
extern int sys_path_block_set_reg24();
extern int sys_path_set_mux_field();

/*
 * Set up the two signal path blocks at power-on. Called by System_Initialize (System_Initialize): load the start values
 * of both blocks from the ROM tables, set the 2-bit selector to 2, then write register 0x24 (both selector
 * arguments 0) and the 12-bit value 0x500 behind it in block 0 and in block 1.
 */
void startup_init_path_blocks(void)

{

  sys_path_block_init();
  sys_path_set_mux_field(PATH_MUX_FIELD_START);
  sys_path_block_set_reg24(PATH_BLOCK_0,0,0,PATH_REG24_VALUE);
  sys_path_block_set_reg24(PATH_BLOCK_1,0,0,PATH_REG24_VALUE);
  return;
}
