/* osd_draw_gaming_items  (FUN_a00ad02c)
 *
 * Draw the Gaming items (Game Mode .. DSC) and their states.
 *   page: page number
 *   force: skip if unchanged
 * Note: Skipped when the page is already shown and force is set.
 * Name basis: proven - texts 0x188DA0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ad02c @ 0xa00ad02c, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the pointer to user_settings is declared inside the page-0 block; with direct accesses or a
 * pointer at function scope the compiler also keeps the table address in a register across the loop. The
 * Gaming item table is written as the address 0x188da0.
 */
#define LANGUAGE_COUNT 29      /* languages per text entry */
#define GAMING_ITEM_COUNT 7    /* Game Mode, Night Vision, AI Vision, Refresh Rate, Alarm Clock, Adaptive-Sync, DSC */
#define GAMING_ITEM_COLUMN 0x14
#define GAMING_ITEM_FIRST_ROW 6  /* item i is on row i * 2 + 6 */

/* Settings record (user_settings): the menu language. */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned char osd_gaming_page_drawn;
extern void panel_wait_sync_pulse(void);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void osd_draw_ai_vision_switch(void);
extern void osd_draw_adaptive_sync_switch(void);
extern void osd_draw_dsc_switch(void);

/* Redraw the item area of the Gaming tab. The area (rows 5..0x14) is always cleared; only page 0
 * has content: the seven item names, and the switches of AI Vision, Adaptive-Sync and DSC.
 *   page:  the page of the list to show; remembered in osd_gaming_page_drawn.
 *   force: non-zero means "only when the page changed": if page is already the drawn page the
 *          routine returns without drawing.
 * Items for which osd_is_item_enabled() returns 0 get their cells filled with 0x292 before the
 * name is drawn. The item stepper passes force 1 when the cursor moves to another page; other
 * callers pass force 0. */
void osd_draw_gaming_items(unsigned char page, unsigned char force)
{
    unsigned char i;

    if (force && osd_gaming_page_drawn == page)
        return;
    osd_gaming_page_drawn = page;
    panel_wait_sync_pulse();
    for (i = 5; i <= 0x14; i++) {
        osd_api_fill_cell_bytes(0, 0x13, i, 0x13, 0, 0);
        osd_api_fill_cells(0x13, i, 0x13, 0x792, 0);
    }
    osd_api_fill_cell_bytes(0, 0x1c, 0x15, 2, 0, 0);
    osd_api_set_window_enable(5, 0, 0);
    osd_api_set_glyph_write_address(0x92, 0);
    osd_api_set_text_mode(0, 0);
    if (page == 0) {
        struct user_settings_record *p = &user_settings;
        for (i = 0; i <= 6; i++) {
            if (!osd_is_item_enabled(i))
                osd_api_fill_cells(GAMING_ITEM_COLUMN, i * 2 + GAMING_ITEM_FIRST_ROW, 0xd, 0x292, 0);
            osd_draw_text(0, GAMING_ITEM_COLUMN, i * 2 + GAMING_ITEM_FIRST_ROW, 1, osd_get_text((unsigned int *)0x188da0, i * LANGUAGE_COUNT + p->language), 0);
        }
        osd_draw_ai_vision_switch();
        osd_draw_adaptive_sync_switch();
        osd_draw_dsc_switch();
    }
}
