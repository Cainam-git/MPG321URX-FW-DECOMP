/* osd_toggle_dsc  (FUN_a0095dd8)
 *
 * Switch DSC (display stream compression) support on or off.
 * Note: Toggles bit 31 of settings word +0x1F4 and re-applies the port set-up
 *   (sys_user_apply_input_link_settings(2)).
 * Name basis: proven - handler table 0xA802422C: OK on state 0x14 = Gaming item 'DSC'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095dd8 @ 0xa0095dd8-0xa0095e54 (31 words), flags -mcpu=v8 -O3 -g.
 * Source form: the DSC switch is the most significant bit of the word at +0x1F4, declared as a 1-bit
 * bit-field (the first field is the top bit, big-endian) and flipped with ~. The record is reached through a
 * struct pointer. One tail call to sys_user_apply_input_link_settings after the conditional clear.
 */

/* The two fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1a4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
    unsigned char pad1a5[0x1f4 - 0x1a5];
    unsigned int dsc_switch : 1, rest : 31;     /* +0x1F4: bit 31 = the DSC switch */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern void osd_draw_gaming_item_state(unsigned char, int);
extern void sys_user_apply_input_link_settings(int);

#define PAGE_GAMING_ITEMS 0xe        /* first item state of the Gaming page; item row = state - 0xE */
#define SCREEN_SIZE_16_10            3          /* the Screen Size list entry "16:10" */
#define SCREEN_SIZE_INPUT_ASPECT     0          /* Screen Size: width from the input's aspect */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */
#define LINK_SELECTOR_2              2          /* selector argument of sys_user_apply_input_link_settings */

/*
 * OK on the DSC item of the Gaming page: flip the DSC switch (bit 31 of the settings word at +0x1F4) and redraw
 * the item's switch state.
 *
 * When the switch is now on and Screen Size is 16:10, Screen Size is set back to the input's aspect. At the end
 * the per-input link settings are applied for selector 2.
 */
void osd_toggle_dsc(void)
{
  struct user_settings_record *settings = &user_settings;

  settings->dsc_switch = ~settings->dsc_switch;
  osd_draw_gaming_item_state(osd_menu_state - PAGE_GAMING_ITEMS, HIGHLIGHT_ITEM_ACTIVE);
  if (settings->screen_size == SCREEN_SIZE_16_10 && settings->dsc_switch)
    settings->screen_size = SCREEN_SIZE_INPUT_ASPECT;
  sys_user_apply_input_link_settings(LINK_SELECTOR_2);
}
