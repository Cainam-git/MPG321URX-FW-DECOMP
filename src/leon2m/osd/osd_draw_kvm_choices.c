/* osd_draw_kvm_choices  (FUN_a00b7a44)
 *
 * Draw the KVM choices (Auto, Upstream, Type C) and mark the current one.
 * Note: Current choice = settings byte +0x17C.
 * Name basis: proven - texts 0x1909ec 'Auto|Upstream|Type C'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7a44 @ 0xa00b7a44-0xa00b7ae4 (160 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the loop has the form of osd_draw_crosshair_items; the last call is a tail call.
 */
#define GLYPH_WRITE_ADDRESS   0x111
#define TEXT_MODE_NORMAL      0
#define CHOICE_TEXT_COLUMN    0x2A              /* column of the choice texts */
#define LANGUAGE_COUNT        29                /* text index = entry * 29 + language byte of the settings */
#define KVM_CHOICES           3                 /* Auto, Upstream, Type C */
#define LIST_KIND_CHOICES     1                 /* first argument of osd_draw_choice_mark */

struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +8: selects the text of the menu language */
    unsigned char pad9[0x17c - 9];
    unsigned char kvm_choice;                   /* +0x17C: the saved KVM choice */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_kvm_texts[];
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(unsigned char c, unsigned char v);
extern void osd_draw_choice_mark(unsigned char mode, unsigned char sel, unsigned char on);

/* Draw the three KVM choices at rows 6, 8 and 10 and mark the one saved in settings byte +0x17C.
   Called by osd_draw_item_choices (osd_draw_item_choices). */
void osd_draw_kvm_choices(void)
{
    unsigned char i;

    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
    for (i = 0; i <= KVM_CHOICES - 1; i++)
        osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_kvm_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
    osd_draw_choice_mark(LIST_KIND_CHOICES, user_settings.kvm_choice, 1);
}
