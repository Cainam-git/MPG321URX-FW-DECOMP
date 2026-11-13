/* osd_enter_image_items  (FUN_a0091f58)
 *
 * Enter the Image tab's list at its first enabled item (OK or right key)
 * Note: Start item is Brightness, Contrast or Sharpness, chosen from sys_user_get_picture_state and settings
 *   +0x11C/+0xB0.
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x18CA88
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091f58, flags -mcpu=v8 -O3 -g.
 * Source form: 'for (;;) { if (call == 1) break; ... }' gives the firmware's rotated loop ('while (call != 1)' gives other
 * code).
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_IMAGE             3
#define PAGE_IMAGE_ITEMS           0x18       /* menu state of the first item of the Image tab */
#define IMAGE_ITEM_COUNT           6

extern unsigned int osd_menu_state;
extern void osd_highlight_item_row(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_tab(unsigned char, int);
extern int sys_user_get_picture_state(void);
extern unsigned char input_user_has_rate_mode(void);

/* The two settings words used here. */
struct user_settings_record {
  unsigned char pad0[0xb0];
  unsigned int blur_free_mode;                  /* +0xB0 */
  unsigned char padb4[0x11c - 0xb4];
  int professional_flags;                       /* +0x11C: bit 31 = automatic level */
};
extern struct user_settings_record user_settings;

/*
 * Open the item list of the Image tab from the tab row: the tab gets the "parent" highlight. The first item
 * tried is item 2 when sys_user_get_picture_state returns non-zero; else item 1 when bit 31 of the
 * professional flags is set, or when the Blur Free setting is non-zero and input_user_has_rate_mode
 * returns true; else item 0. The menu state becomes the first item from there that osd_is_item_enabled
 * accepts (stepping forward, wrapping after the last), and that item's row is highlighted.
 */
void osd_enter_image_items(void)
{
  int next_item;

  osd_highlight_tab(osd_menu_state - MENU_STATE_TAB_BASE, TAB_STYLE_PARENT);
  if (sys_user_get_picture_state() != 0)
    osd_menu_state = PAGE_IMAGE_ITEMS + 2;
  else if (user_settings.professional_flags < 0)
    osd_menu_state = PAGE_IMAGE_ITEMS + 1;
  else if (user_settings.blur_free_mode != 0 && input_user_has_rate_mode())
    osd_menu_state = PAGE_IMAGE_ITEMS + 1;
  else
    osd_menu_state = PAGE_IMAGE_ITEMS;
  for (;;) {
    if (osd_is_item_enabled(osd_menu_state - PAGE_IMAGE_ITEMS) == 1)
      break;
    next_item = (unsigned short)osd_menu_state - (PAGE_IMAGE_ITEMS - 1);
    next_item = next_item % IMAGE_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_IMAGE_ITEMS;
  }
  osd_highlight_item_row(osd_menu_state - PAGE_IMAGE_ITEMS, 1);
}
