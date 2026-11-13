/* osd_factory_set_edit_state  (FUN_a009ea78)
 *
 * Set the menu state to factory item editing (0x112)
 * Note: No reference to it was found in the handler or event tables.
 * Name basis: descriptive - stores 0x112 to the menu state word only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ea78, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store of a constant to the extern symbol (the store sits in the return delay slot). Nothing
 * in the image refers to this routine.
 */
extern unsigned int osd_menu_state;

#define MENU_STATE_FACTORY_ITEM_EDIT 0x112      /* a factory menu item is being edited */

/* Set the menu state to 0x112 (editing a factory menu item). No other code or table refers to this routine. */
void osd_factory_set_edit_state(void)
{
    osd_menu_state = MENU_STATE_FACTORY_ITEM_EDIT;
}
