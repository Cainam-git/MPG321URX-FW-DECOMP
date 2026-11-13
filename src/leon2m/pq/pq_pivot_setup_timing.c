/* pq_pivot_setup_timing  (FUN_a010a558)
 *
 * Program the rotation block's timing registers from the working panel timing row.
 * Name basis: descriptive - five size fields of the row; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a558 @ 0xa010a558 (179 words), flags -mcpu=v8 -O3 -g.
 * Source form: pq_pivot_update_counter is compiled here as a static function and inlined (it also matches on
 * its own, src/leon2m/pq/pq_pivot_update_counter.c). Its reg_read16_bytes arm goes through the early-return unsigned short
 * function read_converter_counter ('if (bit 7) return f(AD8); return f(C18);'): its return conversion gives
 * the firmware's extend-into-temp and 'mov' copy; every if/else or ternary form folds the extension into the
 * counter variable.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Frame-rate converter registers read for the counter. */
#define FRC_OUTPUT_SELECT       R(0xcf011a80)   /* bit 0 and bit 7 choose where the counter is read */
#define FRC_COUNTER_A           0xcf011ad8      /* byte register pairs read with reg_read16_bytes */
#define FRC_COUNTER_B           0xcf011c18

/* Registers of the pivot block (0xCF01E4xx..0xCF01EAxx). */
#define PIVOT_REG_E404          R(0xcf01e404)
#define PIVOT_REG_E660          R(0xcf01e660)
#define PIVOT_REG_E664          R(0xcf01e664)
#define PIVOT_CHANNEL0_CTRL     R(0xcf01e684)   /* bit 4: the per-channel bit of pq_pivot_set_bit4_pattern */
#define PIVOT_CHANNEL1_CTRL     R(0xcf01e688)
#define PIVOT_CHANNEL2_CTRL     R(0xcf01e68c)
#define PIVOT_REG_E9C8          R(0xcf01e9c8)
#define PIVOT_REG_E9DC          R(0xcf01e9dc)
#define PIVOT_REG_EA80          R(0xcf01ea80)
#define PIVOT_REG_EA84          R(0xcf01ea84)
#define PIVOT_REG_EA90          R(0xcf01ea90)
#define PIVOT_REG_EA94          R(0xcf01ea94)
#define PIVOT_BLANK_LOW         R(0xcf01eaa8)   /* low / high byte of the pair at 0xCF01EAA8 */
#define PIVOT_BLANK_HIGH        R(0xcf01eaac)
#define PIVOT_COUNTER_LOW       R(0xcf01eac4)
#define PIVOT_COUNTER_HIGH      R(0xcf01eac0)   /* bit 7 set together with the counter's high byte */
#define PIVOT_CHANNEL_BIT       0x10

/* 16-bit values go to byte register pairs: the low byte at a, the high byte at a + 4. */
#define PIVOT_PAIR_ACTIVE_1     0xcf01ea44
#define PIVOT_PAIR_ACTIVE_2     0xcf01ea4c
#define PIVOT_PAIR_EA88         0xcf01ea88
#define PIVOT_PAIR_ACTIVE_3     0xcf01ea98
#define PIVOT_PAIR_HALF_0X30    0xcf01eaa0
#define PIVOT_PAIR_BLANK        0xcf01eaa8
#define PIVOT_PAIR_HALF_0X32    0xcf01eab0
#define PIVOT_PAIR_ACTIVE_4     0xcf01eab8
#define pivot_write16(a, v) (R(a) = (unsigned char)(v), R((a) + 4) = (unsigned short)(v) >> 8)

/* The fields of the working panel timing row read here (struct panel_timing_row, 0x58 bytes). */
struct panel_timing_row
{
  unsigned char pad00[0x0a];
  unsigned short active_size1;          /* +0xA: active lines */
  unsigned char pad0c[0x16];
  unsigned short half_0x22;             /* +0x22: the middle of the row's three horizontal totals */
  unsigned char pad24[8];
  unsigned short vtotal;                /* +0x2C */
  unsigned short vtotal_max;            /* +0x2E */
  unsigned short half_0x30;             /* +0x30 */
  unsigned short half_0x32;             /* +0x32 */
};
extern struct panel_timing_row *panel_working_row_ptr;
extern int dbg_printf();
extern unsigned short pq_block_read_reg64_word_copy(unsigned char);
extern int reg_read16_bytes(int);

static unsigned short read_converter_counter(void)
{
  if (FRC_OUTPUT_SELECT & 0x80)
    return reg_read16_bytes(FRC_COUNTER_A);
  return reg_read16_bytes(FRC_COUNTER_B);
}
/* The counter is register 0x64 of picture block 0 when bit 0 of FRC_OUTPUT_SELECT is set, else one of the two
   converter register pairs; a quarter of it goes to the pivot block with bit 7 of the high register set. */
static void pq_pivot_update_counter(void)
{
  unsigned short counter;
  if (FRC_OUTPUT_SELECT & 1)
    counter = pq_block_read_reg64_word_copy(0);
  else
    counter = read_converter_counter();
  counter >>= 2;
  PIVOT_COUNTER_LOW = counter & 0xff;
  PIVOT_COUNTER_HIGH = (counter >> 8) | 0x80;
}

/*
 * Program the pivot block's timing registers from the working panel timing row (panel_working_row_ptr).
 *
 *   enable  0: do nothing; any other value: print "PIVOT_CaptureConfig" and program the registers
 *
 * From the row it takes the active lines, the vertical total, the horizontal total half_0x22 and the halfwords
 * +0x30 and +0x32. Four register pairs get the active lines; others get half_0x30, half_0x32, the lines left
 * over (vertical total - active lines - half_0x32 - half_0x30, 13 bits) and a value derived from the totals
 * (see below). The low five bits of the active lines decide the value of PIVOT_REG_E9DC. On the way it sets
 * bit 4 of channel registers 0 and 1, clears it in channel register 2 and refreshes the counter
 * (pq_pivot_update_counter).
 *
 * Nothing in the firmware calls this routine.
 */
void pq_pivot_setup_timing(unsigned char enable)
{
  struct panel_timing_row *row;
  unsigned short active_lines, vtotal, htotal, half_0x30, half_0x32, divisor, lines_left, ea88_value;
  unsigned int scaled_htotal, align_pad;

  if (enable == 0) return;
  dbg_printf("PIVOT_CaptureConfig\r\n");
  row = panel_working_row_ptr;
  active_lines = row->active_size1;
  PIVOT_REG_E404 = 0x10;
  pivot_write16(PIVOT_PAIR_ACTIVE_1, active_lines);
  vtotal = row->vtotal;
  half_0x30 = row->half_0x30;
  htotal = row->half_0x22;
  half_0x32 = row->half_0x32;
  lines_left = (vtotal - active_lines - half_0x32 - half_0x30) & 0x1fff;
  pivot_write16(PIVOT_PAIR_ACTIVE_2, active_lines);
  /* The divisor is the vertical total, or active lines + 18 when the total leaves 17 lines or fewer. */
  divisor = (vtotal - active_lines > 0x11) ? vtotal : active_lines + 0x12;
  PIVOT_CHANNEL0_CTRL |= PIVOT_CHANNEL_BIT;
  PIVOT_CHANNEL1_CTRL |= PIVOT_CHANNEL_BIT;
  scaled_htotal = (unsigned int)(vtotal * htotal) / divisor & ~1;   /* rounded down to even */
  PIVOT_CHANNEL2_CTRL &= ~PIVOT_CHANNEL_BIT;
  ea88_value = scaled_htotal - active_lines - 64;
  /* The distance from the active lines up to the next multiple of 32 (32 when they are one already). */
  align_pad = 0x20 - (active_lines & 0x1f);
  pq_pivot_update_counter();
  PIVOT_REG_EA80 = 0x20;
  PIVOT_REG_EA84 = 0;
  pivot_write16(PIVOT_PAIR_EA88, ea88_value);
  PIVOT_REG_EA90 = 0x20;
  PIVOT_REG_EA94 = 0;
  pivot_write16(PIVOT_PAIR_ACTIVE_3, active_lines);
  pivot_write16(PIVOT_PAIR_HALF_0X30, half_0x30);
  /* Read back PIVOT_COUNTER_HIGH, whose bit 7 pq_pivot_update_counter has just written as 1: with bit 7 set
     the pair gets 0x1FFF, else the lines left over. */
  if (PIVOT_COUNTER_HIGH & 0x80) {
    PIVOT_BLANK_LOW = 0xff;
    PIVOT_BLANK_HIGH = 0x1f;
  } else
    pivot_write16(PIVOT_PAIR_BLANK, lines_left);
  pivot_write16(PIVOT_PAIR_HALF_0X32, half_0x32);
  pivot_write16(PIVOT_PAIR_ACTIVE_4, active_lines);
  PIVOT_REG_E9C8 |= 0x10;
  PIVOT_REG_E9DC = align_pad & 0xff;
  PIVOT_REG_E660 = 0xc0;
  PIVOT_REG_E664 = 0xc0;
}
