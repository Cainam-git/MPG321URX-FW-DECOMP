/* osd_factory_cursor_down  (FUN_a008a878)
 *
 * Move the factory menu highlight to the next item (wraps)
 * Note: Item index 0xA802AFBD steps up and wraps to 0x0D after 0x1A; on a colour row or item 0x14 it also sets
 *   and applies the colour temperature.
 * Name basis: derived - twin of osd_factory_cursor_up with an increment
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a878, flags -mcpu=v8 -O3 -g.
 * Twin of osd_factory_cursor_up. The fall-out path has a real nop (asm) before the return, not a delay slot.
 * Source form: the if-chain with the nested block gives the firmware's compare order and the shared
 * 'colour_temperature = 1' block (a switch gives a jump table).
 */

/* The factory menu item numbers used here (enum factory_item in the factory menu files). */
#define FACTORY_ITEM_LAST          0x1a         /* CRC_AUTO */
#define FACTORY_ITEM_BRIGHTNESS    0x0d
#define FACTORY_ITEM_WARM50_RED    1
#define FACTORY_ITEM_COOL93_RED    4
#define FACTORY_ITEM_USER_RED      7
#define FACTORY_ITEM_NORMAL65_RED  10
#define FACTORY_ITEM_CEC_PWM_ADJUST 0x14

/* Fill values written to the label cells of an item by osd_api_fill_cells. */
#define CELL_VALUE_VALUE_FIELD   0x790  /* the item the cursor leaves */
#define CELL_VALUE_LABEL         0x90   /* the item the cursor reaches */

/* One entry of osd_factory_menu_layout: where the label of an item sits, in character cells. */
struct factory_item_position { unsigned char col, row, len; };
extern struct factory_item_position osd_factory_menu_layout[];
extern unsigned char osd_factory_item;
extern unsigned char user_settings_color_temperature;
extern void pq_user_apply_color_settings(void);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

/*
 * Move the cursor of the factory menu down by one item and wrap to item 13 when the number passes 26. The label of the old item is filled with
 * CELL_VALUE_VALUE_FIELD, that of the new item with CELL_VALUE_LABEL. When the new item is one of the colour
 * rows below, the colour temperature setting is set to the number given and applied:
 *   item 1 (WARM50_RED) -> 2, item 7 (USER_RED) -> 3, item 10 (NORMAL65_RED) -> 1, item 4 (COOL93_RED) -> 0,
 *   item 20 (CEC_PWM_ADJUST) -> 1.
 * Any other item leaves the colour temperature alone.
 */
void osd_factory_cursor_down(void)
{
  unsigned char colour_temperature;

  osd_api_fill_cells(osd_factory_menu_layout[osd_factory_item].col, osd_factory_menu_layout[osd_factory_item].row, osd_factory_menu_layout[osd_factory_item].len, CELL_VALUE_VALUE_FIELD, 0);
  osd_factory_item++;
  if (osd_factory_item > FACTORY_ITEM_LAST)
    osd_factory_item = FACTORY_ITEM_BRIGHTNESS;
  osd_api_fill_cells(osd_factory_menu_layout[osd_factory_item].col, osd_factory_menu_layout[osd_factory_item].row, osd_factory_menu_layout[osd_factory_item].len, CELL_VALUE_LABEL, 0);
  if (osd_factory_item == FACTORY_ITEM_WARM50_RED)
    colour_temperature = 2;
  else if (osd_factory_item == FACTORY_ITEM_USER_RED)
    colour_temperature = 3;
  else {
    if (osd_factory_item != FACTORY_ITEM_NORMAL65_RED) {
      if (osd_factory_item == FACTORY_ITEM_COOL93_RED) {
        user_settings_color_temperature = 0;
        pq_user_apply_color_settings();
        return;
      }
      if (osd_factory_item != FACTORY_ITEM_CEC_PWM_ADJUST) {
        __asm__ volatile ("nop");
        return;
      }
    }
    colour_temperature = 1;
  }
  user_settings_color_temperature = colour_temperature;
  pq_user_apply_color_settings();
}
