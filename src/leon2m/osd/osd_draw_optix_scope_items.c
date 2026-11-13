/* osd_draw_optix_scope_items  (FUN_a00b7ae4)
 *
 * Draw the Optix Scope sub-items (Scope Size, Scope Ratio) and the on/off choice.
 * Name basis: proven - texts 0x18d578 'Scope Size|Scope Ratio|OFF|ON'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7ae4 @ 0xa00b7ae4-0xa00b7b8c (42 words), flags -mcpu=v8 -O3 -g.
 * Source form: same form as osd_draw_image_enhancement_choices with another table, loop count and last
 * argument. The record is one struct (its address is kept in a register).
 */
#define GLYPH_WRITE_ADDRESS   0x111
#define TEXT_MODE_NORMAL      0
#define CHOICE_TEXT_COLUMN    0x2A              /* column of the choice texts */
#define LANGUAGE_COUNT        29                /* text index = entry * 29 + language byte of the settings */
#define OPTIX_SCOPE_TEXTS     4                 /* Scope Size, Scope Ratio, OFF, ON */
#define OPTIX_SCOPE_MARK_ROW_OFFSET 2           /* the saved switch value 0/1 marks entry 2/3 (OFF/ON) */
#define LIST_KIND_CHOICES     1                 /* first argument of osd_draw_choice_mark */

struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +8: selects the text of the menu language */
    unsigned char pad9[0x4a - 9];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_optix_scope_item_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/* Draw the four Optix Scope entries (Scope Size, Scope Ratio, OFF, ON) at rows 6, 8, 10 and 12; the mark goes
   on OFF or ON according to settings byte +0x4A. Called by the Optix Scope handlers (osd_accept_scope_size,
   osd_cancel_scope_size, osd_accept_scope_ratio, osd_cancel_scope_ratio) and osd_draw_item_choices (osd_draw_item_choices). */
void osd_draw_optix_scope_items(void)
{
  unsigned char i;

  osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
  osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
  for (i = 0; i <= OPTIX_SCOPE_TEXTS - 1; i++)
    osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_optix_scope_item_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
  osd_draw_choice_mark(LIST_KIND_CHOICES, user_settings.optix_scope + OPTIX_SCOPE_MARK_ROW_OFFSET, 1);
}
