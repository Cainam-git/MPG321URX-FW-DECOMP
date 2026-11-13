/* sys_mode_reset_vx1_if_link_type_1  (FUN_a0151674)
 *
 * Call ResetVx1 when bits 20..22 of the active panel row's first word equal 1.
 * Returns: the ResetVx1 result, else the first argument
 * Note: Its only caller, GlobalModeHandler on entry to channel state 0xB, passes nothing and ignores the
 *   result.
 * Name basis: derived - tests bits 20-22 of the panel row word, then ResetVx1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0151674 @ 0xa0151674 (-mcpu=v8 -O3 -g).
 * Source form: the decompiler's type names, the six parameters and the pointer to the row's first word are kept.
 */
typedef unsigned int uint;
typedef unsigned char undefined1;

/* First word of the active panel timing row: bits 20..22 are the link type. */
#define ROW_LINK_TYPE_MASK 0x700000
#define ROW_LINK_TYPE_1    0x100000
extern int ResetVx1();
extern undefined1 * panel_get_active_row(void);

/*
 * When the link type of the active panel row is 1, reset the V-by-One link (ResetVx1) and return its result;
 * for any other link type return the first parameter unchanged.
 *
 *   value_1, value_2  passed to ResetVx1
 *   unused_3 .. unused_6  not used here
 *
 * Called by GlobalModeHandler (GlobalModeHandler) when a channel enters state 0xB (and no other channel is above
 * state 9); the caller passes no arguments and ignores the result.
 */
uint sys_mode_reset_vx1_if_link_type_1(uint value_1,uint value_2,uint unused_3,uint unused_4,uint unused_5,uint unused_6)

{
  uint *row_flags;
  uint result;
  
  row_flags = (uint *)panel_get_active_row();
  if ((*row_flags & ROW_LINK_TYPE_MASK) != ROW_LINK_TYPE_1) {
    return value_1;
  }
  result = ResetVx1(value_1,value_2);
  return result;
}
