/* osd_draw_image_enhancement_choices  (FUN_a00b6e1c)
 *
 * Draw the Image Enhancement choices and mark the current level.
 * Note: Current level = low 4 bits of settings halfword +0x34.
 * Name basis: proven - texts 0x194b34 'OFF|Weak|Medium|Strong|Strongest'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6e1c @ 0xa00b6e1c-0xa00b6ec0 (41 words), flags -mcpu=v8 -O3 -g.
 * Source form: the level is a 4-bit bit-field of the halfword at +0x34 (the firmware loads the halfword and
 * masks with 0xf; the mask form '& 0xf' into the unsigned char parameter lets the compiler narrow the load to
 * the byte at +0x35); one record user_settings (the firmware keeps the full address in a register, which a
 * plain for loop gives).
 */
#define GLYPH_WRITE_ADDRESS   0x111
#define TEXT_MODE_NORMAL      0                 /* text drawing mode 0 */
#define TEXT_ALIGN_LEFT       0
#define CHOICE_TEXT_COLUMN    0x2A              /* column of the choice texts */
#define LANGUAGE_COUNT        29                /* text index = entry * 29 + language byte of the settings */
#define IMAGE_ENHANCEMENT_LEVELS 5              /* OFF, Weak, Medium, Strong, Strongest */
#define LIST_KIND_CHOICES     1                 /* first argument of osd_draw_choice_mark */

struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +8: selects the text of the menu language */
    unsigned char pad9[0x2b];
    struct { unsigned short hi : 12, level : 4; } image_enhancement;    /* +0x34: level in the low 4 bits */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_image_enhancement_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/* Draw the five texts two rows apart, from row 6 down, then mark the saved level. */
void osd_draw_image_enhancement_choices(void)
{
  unsigned char i;

  osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
  osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
  for (i = 0; i <= IMAGE_ENHANCEMENT_LEVELS - 1; i++)
    osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_image_enhancement_texts, i * LANGUAGE_COUNT + user_settings.language), TEXT_ALIGN_LEFT);
  osd_draw_choice_mark(LIST_KIND_CHOICES, user_settings.image_enhancement.level, 1);
}
