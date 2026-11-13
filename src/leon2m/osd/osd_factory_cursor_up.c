/* osd_factory_cursor_up  (FUN_a008a794)
 *
 * Move the factory menu highlight to the previous item (wraps)
 * Note: Item index 0xA802AFBD runs 1..0x1A and wraps to 0x1A below 0x0D; on a colour row or item 0x14 it also
 *   sets and applies the colour temperature.
 * Name basis: derived - un-highlights / highlights the layout entries (attributes 0x790 / 0x90); twin of
 *   osd_factory_cursor_down
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a794, flags -mcpu=v8 -O3 -g.
 * Twin of osd_factory_cursor_down. The fall-out path has a real nop (asm) before the return, not a delay slot.
 * Source form: the if-chain with the nested block gives the firmware's compare order and the shared
 * 'colour_temperature = 1' block (a switch gives a jump table).
 */

/* The factory menu item numbers used here (enum factory_item in the factory menu files). */
#define FACTORY_ITEM_LAST          0x1a         /* CRC_AUTO */
#define FACTORY_ITEM_BRIGHTNESS    0x0d
#define FACTORY_ITEM_WARM50_BLUE   3
#define FACTORY_ITEM_COOL93_BLUE   6
#define FACTORY_ITEM_USER_BLUE     9
#define FACTORY_ITEM_NORMAL65_BLUE 12
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
 * Move the cursor of the factory menu up by one item and wrap to item 26 when the number falls below 13. The label of the old item is filled with
 * CELL_VALUE_VALUE_FIELD, that of the new item with CELL_VALUE_LABEL. When the new item is one of the colour
 * rows below, the colour temperature setting is set to the number given and applied:
 *   item 3 (WARM50_BLUE) -> 2, item 9 (USER_BLUE) -> 3, item 12 (NORMAL65_BLUE) -> 1, item 6 (COOL93_BLUE) -> 0,
 *   item 20 (CEC_PWM_ADJUST) -> 1.
 * Any other item leaves the colour temperature alone.
 */
void osd_factory_cursor_up(void)
{
  unsigned char colour_temperature;

  osd_api_fill_cells(osd_factory_menu_layout[osd_factory_item].col, osd_factory_menu_layout[osd_factory_item].row, osd_factory_menu_layout[osd_factory_item].len, CELL_VALUE_VALUE_FIELD, 0);
  osd_factory_item--;
  if (osd_factory_item < FACTORY_ITEM_BRIGHTNESS)
    osd_factory_item = FACTORY_ITEM_LAST;
  osd_api_fill_cells(osd_factory_menu_layout[osd_factory_item].col, osd_factory_menu_layout[osd_factory_item].row, osd_factory_menu_layout[osd_factory_item].len, CELL_VALUE_LABEL, 0);
  if (osd_factory_item == FACTORY_ITEM_WARM50_BLUE)
    colour_temperature = 2;
  else if (osd_factory_item == FACTORY_ITEM_USER_BLUE)
    colour_temperature = 3;
  else {
    if (osd_factory_item != FACTORY_ITEM_NORMAL65_BLUE) {
      if (osd_factory_item == FACTORY_ITEM_COOL93_BLUE) {
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
