/* panel_vx1_setup_lanes  (FUN_a01227f0)
 *
 * Set up the lanes of the V-by-One link.
 * Name basis: proven - Vx1 lane set-up with prints; a step of the panel power sequencer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01227f0 @ 0xa01227f0-0xa0122cd8 (314 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - panel_vx1_first_param is read once into first_param, and scaled_param = first_param * 17 - 17 (an unsigned
 *    short, stored as its low byte in each block) is computed once before the four tests;
 *  - tests 2..4 are written 'is_zero = first_param == 0; if (is_zero)': with a plain 'if (first_param == 0)'
 *    the jump bypass of the global common-subexpression pass threads the arms into each other and the second
 *    common-subexpression pass deletes the tests; the stored comparison makes the join block two instructions
 *    long so the bypass skips it, and combine folds it back into one compare (the firmware keeps all four tests);
 *  - the head (switches with repeated case bodies, the explicit locals) is kept as written.
 */
extern unsigned char *panel_working_row_ptr;
extern unsigned char panel_vx1_second_param;    /* 0..31 (panel_vx1_set_two_params) */
extern unsigned char panel_vx1_first_param;     /* 1..16 (panel_vx1_set_two_params); 0 switches its registers off */
extern unsigned short panel_vx1_measure_lane_clock(int, int);
extern int dbg_printf();
extern void panel_vx1_setup_transmitter(void);
extern int timer_sleep_ticks();
#define R(a) (*(volatile unsigned int *)(a))

#define ROW_DISPLAY_MODE 6      /* byte +6 of the panel timing row (display_mode) */
#define ROW_BPC          7      /* byte +7 of the panel timing row (bits per colour) */

/* V-by-One set-up registers 0xCF00EB40..0xCF00EB60 (as panel_vx1_write_lane_config). */
#define VX1_SETUP_REG_40 0xcf00eb40     /* from the bits per colour: 10 gives 2, 8 gives 1, else 3 */
#define VX1_RESET        0xcf00eb44     /* reg_panel_vx1_reset: 1 = reset, 0 = run */
#define VX1_LOCK_STATUS  0xcf00eb48     /* reg_panel_vx1_lock_status */
#define VX1_SETUP_REG_4C 0xcf00eb4c
#define VX1_SETUP_REG_50 0xcf00eb50
#define VX1_SETUP_REG_54 0xcf00eb54     /* from the display mode */
#define VX1_SETUP_REG_58 0xcf00eb58
#define VX1_SETUP_REG_5C 0xcf00eb5c
#define VX1_SETUP_REG_60 0xcf00eb60

/* V-by-One transmitter registers written before the blocks. */
#define VX1_TX_REG_800   0xcf01c800
#define VX1_TX_REG_804   0xcf01c804
#define VX1_TX_REG_830   0xcf01c830
#define VX1_TX_REG_99C   0xcf01c99c
#define VX1_TX_REG_BB8   0xcf01cbb8     /* takes 0xFF, 1, then one bit at a time */
#define VX1_TX_REG_BBC   0xcf01cbbc

/* The four transmitter register blocks, 0x8C bytes apart (as panel_vx1_setup_transmitter). */
#define VX1_BLOCK(n)            (0xcf01ccec + 0x8c * (n))
#define VX1_BLOCK_FIRST(n, k)   (VX1_BLOCK(n) + 0x10 + 4 * (k))  /* four registers: the scaled first parameter */
#define VX1_BLOCK_FIRST_ON(n)   (VX1_BLOCK(n) + 0x20)            /* 0xFF: the four first-parameter registers are used */
#define VX1_BLOCK_ON(n)         (VX1_BLOCK(n) + 0x24)            /* 0xFF: the block is used, 0: not used */
#define VX1_BLOCK_GROUP(n, k)   (VX1_BLOCK(n) + 0x44 + 4 * (k))  /* eight registers: the second parameter */
#define VX1_ON  0xff
#define VX1_OFF 0

#define SETTLE_TICKS 10

/* The eight group registers of block n all get the same value. */
#define WRITE_GROUP(n, value)          \
  R(VX1_BLOCK_GROUP(n, 0)) = (value);  \
  R(VX1_BLOCK_GROUP(n, 1)) = (value);  \
  R(VX1_BLOCK_GROUP(n, 2)) = (value);  \
  R(VX1_BLOCK_GROUP(n, 3)) = (value);  \
  R(VX1_BLOCK_GROUP(n, 4)) = (value);  \
  R(VX1_BLOCK_GROUP(n, 5)) = (value);  \
  R(VX1_BLOCK_GROUP(n, 6)) = (value);  \
  R(VX1_BLOCK_GROUP(n, 7)) = (value)

/*
 * Start the V-by-One link to the panel: set up the transmitter and its four register blocks for the working
 * panel timing row (panel_working_row_ptr).
 *
 * Called only by panel_power_sequencer_task, in power-on state 4, when the active row's link type is 1.
 *
 * Phases, in order:
 *   1. print the lane bandwidth: bytes per pixel (3 for 8 bits per colour, 4 for 10, 5 otherwise) times the
 *      clock from panel_vx1_measure_lane_clock(1, 0), times 5 / 4;
 *   2. put the link into reset (VX1_RESET = 1) and set up the transmitter (panel_vx1_setup_transmitter);
 *   3. fixed series on the transmitter registers, then each of the eight bits of VX1_TX_REG_BB8 in turn
 *      (bit 7 first), each followed by a 0 to VX1_TX_REG_800;
 *   4. the set-up registers 0xCF00EB40..0xCF00EB60 from the row's bits per colour and display mode, with the
 *      link out of reset (VX1_RESET = 0), then a wait of 10 ticks;
 *   5. switch the blocks on by display mode: modes 5..7 the first block, 8..10 the first two, any other mode
 *      all four;
 *   6. write panel_vx1_second_param to the eight group registers of all four blocks;
 *   7. in each of the four blocks: with panel_vx1_first_param 0 switch the first-parameter registers off; else
 *      switch them on and write (first_param - 1) * 17 to each of the four (1..16 gives 0..255).
 * What the registers do on the link is not stated by any firmware text.
 */
void panel_vx1_setup_lanes(void)
{
  unsigned char i;
  unsigned char first_param;
  int is_zero;
  int lane_clock;
  unsigned short scaled_param;
  unsigned char bytes_per_pixel;

  /* 1. Lane bandwidth, printed only. */
  if (panel_working_row_ptr[ROW_BPC] == 10)
  {
    bytes_per_pixel = 4;
  }
  else
  {
    bytes_per_pixel = (panel_working_row_ptr[ROW_BPC] == 8) ? (3) : (5);
  }
  lane_clock = panel_vx1_measure_lane_clock(1, 0);
  dbg_printf("Vx1 Lane BW = %ld\r\n", ((unsigned int) ((bytes_per_pixel * lane_clock) * 5)) >> 2);

  /* 2. Reset, transmitter set-up. */
  R(VX1_SETUP_REG_58) = 7;
  R(VX1_RESET) = 1;
  panel_vx1_setup_transmitter();

  /* 3. Fixed series, then the eight bits one by one. */
  R(VX1_TX_REG_BB8) = 0xff;
  R(VX1_TX_REG_BBC) = 0;
  R(VX1_TX_REG_99C) = 0xfd;
  R(VX1_TX_REG_830) = 4;
  R(VX1_TX_REG_804) = 0;
  R(VX1_TX_REG_BB8) = 1;
  for (i = 0; 7 >= i; i++)
  {
    R(VX1_TX_REG_BB8) = (unsigned char) (0x80 >> i);
    R(VX1_TX_REG_800) = 0;
  }

  /* 4. Set-up registers (the same statements as panel_vx1_write_lane_config). */
  if (panel_working_row_ptr[ROW_BPC] == 10)
  {
    R(VX1_SETUP_REG_40) = 2;
  }
  else
    if (panel_working_row_ptr[ROW_BPC] == 8)
  {
    R(VX1_SETUP_REG_40) = 1;
  }
  else
  {
    R(VX1_SETUP_REG_40) = 3;
  }
  R(VX1_RESET) = 0;
  R(VX1_LOCK_STATUS) = 4;
  R(VX1_SETUP_REG_4C) = 0;
  R(VX1_SETUP_REG_50) = 0;
  switch (panel_working_row_ptr[ROW_DISPLAY_MODE])
  {
    case 10:
      R(VX1_SETUP_REG_54) = 5;
      break;
    case 9:
      R(VX1_SETUP_REG_54) = 5;
      break;
    case 8:
      R(VX1_SETUP_REG_54) = 1;
      break;
    case 7:
      R(VX1_SETUP_REG_54) = 1;
      break;
    case 6:
      R(VX1_SETUP_REG_54) = 1;
      break;
    case 5:
      R(VX1_SETUP_REG_54) = 1;
      break;
    default:
      R(VX1_SETUP_REG_54) = 7;
      break;
  }
  R(VX1_SETUP_REG_58) = 7;
  R(VX1_SETUP_REG_60) = (R(VX1_SETUP_REG_60)) & 0xfc;     /* clear the two low bits */
  R(VX1_SETUP_REG_5C) = 0;
  timer_sleep_ticks(SETTLE_TICKS);

  /* 5. Blocks in use, by display mode. */
  switch (panel_working_row_ptr[ROW_DISPLAY_MODE])
  {
    case 5:
    case 6:
    case 7:
      R(VX1_BLOCK_ON(0)) = VX1_ON;
      R(VX1_BLOCK_ON(1)) = VX1_OFF;
      R(VX1_BLOCK_ON(2)) = VX1_OFF;
      R(VX1_BLOCK_ON(3)) = VX1_OFF;
      break;
    case 8:
    case 9:
    case 10:
      R(VX1_BLOCK_ON(0)) = VX1_ON;
      R(VX1_BLOCK_ON(1)) = VX1_ON;
      R(VX1_BLOCK_ON(2)) = VX1_OFF;
      R(VX1_BLOCK_ON(3)) = VX1_OFF;
      break;
    default:
      R(VX1_BLOCK_ON(0)) = VX1_ON;
      R(VX1_BLOCK_ON(1)) = VX1_ON;
      R(VX1_BLOCK_ON(2)) = VX1_ON;
      R(VX1_BLOCK_ON(3)) = VX1_ON;
      break;
  }

  /* 6. The second parameter, to every block whether in use or not. */
  WRITE_GROUP(0, panel_vx1_second_param);
  WRITE_GROUP(1, panel_vx1_second_param);
  WRITE_GROUP(2, panel_vx1_second_param);
  WRITE_GROUP(3, panel_vx1_second_param);

  /* 7. The first parameter, spread from 1..16 to 0..255. */
  first_param = panel_vx1_first_param;
  scaled_param = (first_param * 17) - 17;
  if (first_param == 0)
  {
    R(VX1_BLOCK_FIRST_ON(0)) = VX1_OFF;
  }
  else
  {
    R(VX1_BLOCK_FIRST_ON(0)) = VX1_ON;
    R(VX1_BLOCK_FIRST(0, 0)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(0, 1)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(0, 2)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(0, 3)) = (unsigned char) scaled_param;
  }
  is_zero = first_param == 0;
  if (is_zero)
  {
    R(VX1_BLOCK_FIRST_ON(1)) = VX1_OFF;
  }
  else
  {
    R(VX1_BLOCK_FIRST_ON(1)) = VX1_ON;
    R(VX1_BLOCK_FIRST(1, 0)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(1, 1)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(1, 2)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(1, 3)) = (unsigned char) scaled_param;
  }
  is_zero = first_param == 0;
  if (is_zero)
  {
    R(VX1_BLOCK_FIRST_ON(2)) = VX1_OFF;
  }
  else
  {
    R(VX1_BLOCK_FIRST_ON(2)) = VX1_ON;
    R(VX1_BLOCK_FIRST(2, 0)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(2, 1)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(2, 2)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(2, 3)) = (unsigned char) scaled_param;
  }
  is_zero = first_param == 0;
  if (is_zero)
  {
    R(VX1_BLOCK_FIRST_ON(3)) = VX1_OFF;
  }
  else
  {
    R(VX1_BLOCK_FIRST_ON(3)) = VX1_ON;
    R(VX1_BLOCK_FIRST(3, 0)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(3, 1)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(3, 2)) = (unsigned char) scaled_param;
    R(VX1_BLOCK_FIRST(3, 3)) = (unsigned char) scaled_param;
  }
}
