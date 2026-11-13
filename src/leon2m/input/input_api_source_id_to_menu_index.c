/* input_api_source_id_to_menu_index  (FUN_a01445fc)
 *
 * Translate a source id (5, 6, 0xC, 0xD) to its menu index 0..3 through the four-pair table.
 * Returns: menu index or 0xFF
 * Note: Returns at the first matching pair.
 * Name basis: derived - compares the first byte of each pair of the ROM table at 0x1A6DB2 and returns the
 *   second; the callers pass the Input Source setting and use the result as a menu row
 *
 * Matching notes
 * --------------
 * leon2m input_api_source_id_to_menu_index @ 0xa01445fc-0xa014464c (20 words), flags -mcpu=v8 -O3 -g.
 * Source form: one for loop with the bound written as index <= INPUT_MENU_SOURCE_PAIR_LAST_INDEX (3), the
 * match test in the loop body, and the no-match return after the loop as INPUT_MENU_SOURCE_NOT_FOUND (0xff).
 */
/* The ROM pairs {source id, menu index} are (6, 1), (5, 0), (0xD, 3), (0xC, 2). */
struct input_menu_source_pair {
    unsigned char source_id, menu_index;
};
extern struct input_menu_source_pair input_menu_source_pairs[];

#define INPUT_MENU_SOURCE_PAIR_LAST_INDEX 3  /* last index of the four pairs */
#define INPUT_MENU_SOURCE_NOT_FOUND 0xff     /* returned when no pair matches */

/*
 * Translate a source id to its menu index: 6 -> 1, 5 -> 0, 0xD -> 3, 0xC -> 2, else 0xFF. (The direction is
 * the reverse of what the routine's name says; input_api_menu_index_to_source_id does menu index -> source id.)
 *
 * source_id is compared with the source id of each pair; the routine scans the four entries in order and returns
 * the menu index of the first match. If no entry matches, it returns INPUT_MENU_SOURCE_NOT_FOUND. The callers
 * pass the stored Input Source setting (+0x1E) and use the result as the item row of the Input Source page.
 *
 * Callers (49): the input source, PIP / PBP source and quick input menu code, the menu drawing routines,
 * the UART and DDC/CI source commands, the audio routing, APPActionDispatcher, sys_run_app_timer_task and
 * power_enter_app_state.
 *
 * The table is fixed at four entries; INPUT_MENU_SOURCE_PAIR_LAST_INDEX is the last index of that table.
 */
unsigned char input_api_source_id_to_menu_index(unsigned char source_id)
{
  unsigned char index;

  for (index = 0; index <= INPUT_MENU_SOURCE_PAIR_LAST_INDEX; index++)
    if (input_menu_source_pairs[index].source_id == source_id)
      return input_menu_source_pairs[index].menu_index;
  /* No pair matched; return the no-match value. */
  return INPUT_MENU_SOURCE_NOT_FOUND;
}
