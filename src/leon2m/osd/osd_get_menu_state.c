/* osd_get_menu_state  (FUN_a0090fcc)
 *
 * Return the current menu state.
 * Returns: menu state (low 16 bits)
 * Note: Reads the low half of the word 0xA802AFEC.
 * Name basis: derived - same variable as osd_set_menu_state
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0090fcc, flags -mcpu=v8 -O2. A leaf routine without a register window.
 */

extern unsigned short osd_menu_state_low16;

/* Return the menu state (the low halfword of osd_menu_state). */
unsigned short osd_get_menu_state(void)

{
  return osd_menu_state_low16;
}
