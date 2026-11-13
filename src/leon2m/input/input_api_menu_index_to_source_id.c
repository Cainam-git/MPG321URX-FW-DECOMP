/* input_api_menu_index_to_source_id  (FUN_a014459c)
 *
 * Translate a menu index 0..3 to its source id (5, 6, 0xC, 0xD) through the four-pair table.
 * Returns: source id or 0xFF
 * Note: Scans all four pairs without stopping at a match.
 * Name basis: derived - compares the second byte of each pair of the ROM table at 0x1A6DB2 and returns the
 *   first; the menu items store the result in the Input Source setting
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014459c @ 0xa014459c-0xa01445fc (24 words), flags -mcpu=v8 -O2 -g.
 * Source form: the loop bound is written as i <= 3, and the loop has no early exit; a matching pair overwrites result and the loop continues.
 */
/* The ROM pairs {source id, menu index} are (6, 1), (5, 0), (0xD, 3), (0xC, 2). */
struct input_menu_source_pair {
  unsigned char source_id;  /* returned for a matching pair: 5, 6, 0xC or 0xD */
  unsigned char menu_index; /* compared against the parameter: 0..3 */
};
extern const struct input_menu_source_pair input_menu_source_pairs[4];

#define INPUT_MENU_INDEX_NONE 0xff /* no matching pair */

/*
 * Translate a menu index to its source id: 0 -> 5, 1 -> 6, 2 -> 0xC, 3 -> 0xD, else 0xFF. (The direction is
 * the reverse of what the routine's name says; input_api_source_id_to_menu_index does source id -> menu index.)
 *
 * key is compared with the menu index of each pair; the routine scans all four pairs in order, and the source id
 * of a matching pair becomes the result. The scan does not stop at the first match; a later matching pair
 * overwrites the result. If no pair matches, the result is INPUT_MENU_INDEX_NONE. The input menu items pass
 * their input 0..3 (HDMI 1, HDMI 2, DP, Type-C) and store the result in the Input Source setting (+0x1E).
 *
 * Callers (29): the input, PIP and PBP source menu items, the quick input and navi key routines,
 * osd_dispatch_key_event, osd_draw_input_info_banner, the UART and DDC/CI source commands,
 * App_Initialize, APPActionDispatcher and power_enter_app_state.
 */
unsigned char input_api_menu_index_to_source_id(unsigned char key)
{
  unsigned char result = INPUT_MENU_INDEX_NONE;
  unsigned char i;

  for (i = 0; i <= 3; i++) {
    if (input_menu_source_pairs[i].menu_index == key)
      result = input_menu_source_pairs[i].source_id;
  }
  return result;
}
