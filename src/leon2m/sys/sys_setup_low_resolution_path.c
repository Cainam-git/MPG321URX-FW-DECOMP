/* sys_setup_low_resolution_path  (FUN_a0142518)
 *
 * Set the line width and padding of the path used for low-resolution and interlaced signals.
 * Name basis: derived - 480p / interlace chain size set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142518 @ 0xa0142518-0xa01427d4, flags -mcpu=v8 -O3 -g.
 * Code facts that fix the source, all plain C, no aids:
 *  - the path block comes from an inline helper `r = 3; switch (v) { case 0; case 1 }` (firmware: `mov 3` in the
 *    bne delay slot, then the `mov %o4,%l3` copy of the helper's result);
 *  - flag bit 31 of the channel record's word +0x70 is a BIT-FIELD (with `w70 < 0` the opcode heuristic sent the
 *    rounding block to the end);
 *  - the port code test is THREE else-if arms (0x71/0x81, 0x31/0x41, 0x51/0x61) with identical lookup bodies:
 *    crossjump merges them, but at branch-prediction time each lookup is dominated by its own pair test, so the
 *    call heuristic predicts all three pair branches not taken (firmware: fall-through instructions in their delay
 *    slots);
 *  - `lim` is a u16 local set in every arm and `if (lim < w) lim = w + 0x22; sys_path_block_set_width(m, lim);`
 *    (firmware: both sides `sll 16` in the compare, one shared `srl 16` before the call);
 *  - the bit-25 test of sys_config that skips the rounding is a `goto sized;` (gcc 3.4 PRED_GOTO predicts the goto
 *    path not taken). Same code; the changed block frequencies make global-alloc give port %l1 and pad %l2 as in
 *    the firmware (with the plain `&&` chain pad's priority was 400 against port's 397 and the two swapped);
 *  - sys_path_block_set_line_sizes takes the u16 pad as its second argument (the firmware sets %i1 = 0x300000
 *    only on the pad < 0x30 path).
 */
/* Channel record: word 0 = port (bits 12..15) and path (bits 1..3); word +0x70 holds flags. */
struct Port {
  unsigned int w0;
  unsigned char p04[0x70 - 4];
  unsigned int b31 : 1;
  unsigned int b30 : 1;
  unsigned int r70 : 30;
};
/* Port record: +0xA port code. */
struct SrcT { unsigned char p00[0x0a]; unsigned char port_code; unsigned char p0b[0x2a - 0x0b]; };
/* Port entry (0x12 bytes): the halfword at +6 is the width limit used below. */
struct Ent { unsigned char p00[6]; unsigned short h06; unsigned char p08[0x12 - 8]; };
extern struct SrcT port_records[];
extern struct Ent port_entries[];
extern unsigned int sys_config;
extern struct Port *sys_find_channel_by_port(unsigned char port);
extern unsigned char input_block_get_status_bit2(unsigned char port);
extern unsigned char input_get_port_sync_mode(unsigned char port);
extern unsigned char input_block_get_signal_code(unsigned char);
extern unsigned char sys_get_active_port_code(void);
extern unsigned char input_port_id_to_entry_index(unsigned char);
extern void sys_path_block_set_width(unsigned char, unsigned short);
extern void input_block_write_reg9d(unsigned char, unsigned char);
extern void sys_path_block_set_line_sizes(unsigned char, unsigned short, unsigned short);

#define SYS_CONFIG_BIT25 0x2000000      /* bit 25 of sys_config word 0 */
#define PORT_TYPE_5      5              /* port type checked before the width is set */
#define PORT_CODE_ROUTED 0xb1           /* signal code replaced by sys_get_active_port_code() */
#define MIN_PAD          0x30           /* least value of pad; the missing part goes to register 0x9D */
#define WIDTH_MARGIN     0x22           /* added to the width when the entry's limit is below it */

/* Path block of a path field value: 0 and 1 are their own blocks, anything else gives 3. */
static unsigned char mode_of(unsigned int v)
{
  unsigned char r = 3;
  switch (v) {
  case 0: r = 0; break;
  case 1: r = 1; break;
  }
  return r;
}

/*
 * Set the width and the line sizes of the signal path block of `port`, for the path used with the sizes of a
 * low-resolution signal. Called by sys_channel_apply_output_timing when the flag word +0x70 of the channel
 * record has bit 30 set.
 *
 *   port   input port (also the id that finds the channel record)
 *   width  picture width of the signal
 *   lines  picture lines of the signal
 *
 * Does nothing when the path field of the channel record is 2. Otherwise:
 * 1. When bit 25 of sys_config, flag bit 31 of the channel record and status bit 2 of the port's input block
 *    are all set, the width is rounded up to a multiple of 8.
 * 2. For port type 5 the signal code of the port is looked up (0xb1 is replaced by sys_get_active_port_code()).
 *    For the codes 0x31, 0x41, 0x51, 0x61, 0x71 and 0x81 the limit is the halfword +6 of the port entry that
 *    belongs to the port code of the port record; for any other code, or an entry index above 6, it is 0.
 *    pad becomes the width; the path block width is set to the limit, or to width + 0x22 when the width is
 *    larger than the limit. For other port types pad stays 0 and no width is set.
 * 3. Register 0x9D of the input block gets 0x30 - pad when pad is below 0x30 (pad then becomes 0x30), else 0.
 * 4. The line sizes of the path block are pad and the lines; the lines are halved when status bit 2 is set,
 *    unless the bit 25 / bit 31 case of step 1 applies, which uses them whole.
 */
void sys_setup_low_resolution_path(unsigned char port, unsigned short width, unsigned short lines)
{
  struct Port *chan;
  unsigned char path_block, port_code;
  unsigned short pad, width_limit;

  chan = sys_find_channel_by_port(port);
  if ((chan->w0 & 0xe) == 4)
    return;
  pad = 0;
  path_block = mode_of((chan->w0 >> 1) & 7);
  /* Rounding of the width applies only with bit 25 of sys_config, flag bit 31 and status bit 2. */
  if (!(sys_config & SYS_CONFIG_BIT25))
    goto sized;
  if (chan->b31 && input_block_get_status_bit2(port) == 1)
    width = (width + 7) / 8 * 8;
sized:
  if (input_get_port_sync_mode(port) == PORT_TYPE_5) {
    port_code = input_block_get_signal_code(port);
    if (port_code == PORT_CODE_ROUTED)
      port_code = sys_get_active_port_code();
    /* The three arms are the same lookup for the three pairs of port codes. */
    if (port_code == 0x71 || port_code == 0x81) {
      if (input_port_id_to_entry_index(port_records[(chan->w0 >> 12) & 0xf].port_code) <= 6)
        width_limit = port_entries[input_port_id_to_entry_index(port_records[(chan->w0 >> 12) & 0xf].port_code)].h06;
      else
        width_limit = 0;
    } else if (port_code == 0x31 || port_code == 0x41) {
      if (input_port_id_to_entry_index(port_records[(chan->w0 >> 12) & 0xf].port_code) <= 6)
        width_limit = port_entries[input_port_id_to_entry_index(port_records[(chan->w0 >> 12) & 0xf].port_code)].h06;
      else
        width_limit = 0;
    } else if (port_code == 0x51 || port_code == 0x61) {
      if (input_port_id_to_entry_index(port_records[(chan->w0 >> 12) & 0xf].port_code) <= 6)
        width_limit = port_entries[input_port_id_to_entry_index(port_records[(chan->w0 >> 12) & 0xf].port_code)].h06;
      else
        width_limit = 0;
    } else
      width_limit = 0;
    pad = width;
    if (width_limit < width)
      width_limit = width + WIDTH_MARGIN;
    sys_path_block_set_width(path_block, width_limit);
  }
  /* The padding is at least MIN_PAD; register 0x9D takes the shortfall. */
  if (pad < MIN_PAD) {
    input_block_write_reg9d(port, MIN_PAD - pad);
    pad = MIN_PAD;
  } else {
    input_block_write_reg9d(port, 0);
  }
  /* The lines are halved when status bit 2 is set, except in the bit 25 / bit 31 case. */
  if ((sys_config & SYS_CONFIG_BIT25) && chan->b31 && input_block_get_status_bit2((chan->w0 >> 12) & 0xf) == 1)
    sys_path_block_set_line_sizes(path_block, pad, lines);
  else if (input_block_get_status_bit2((chan->w0 >> 12) & 0xf))
    sys_path_block_set_line_sizes(path_block, pad, lines >> 1);
  else
    sys_path_block_set_line_sizes(path_block, pad, lines);
}
