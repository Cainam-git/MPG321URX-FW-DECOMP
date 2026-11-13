/* osd_draw_item_choices  (FUN_a00af44c)
 *
 * Draw the choice column of the highlighted item and mark its current value.
 *   page: tab item base state
 *   item
 * Note: One arm per tab page (0x0B, 0x0E, 0x15, 0x18, 0x23, 0x26, 0x2A, 0x34) and item.
 * Name basis: derived - called by every item step handler; uses the choice text tables of all tabs
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00af44c @ 0xa00af44c-0xa00b0034, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - mark_choice_row is a static helper;
 *  - the Screen Size rows (Image tab, item 4) keep their block-local saved list id and row count `count`;
 *  - the Reset rows (Settings tab, item 9) use their own block-local counter;
 *  - the text tables are extern array symbols, and the DisplayHDR table keeps the link name
 *    DAT_00190cec_hdr_mode_text: gcse orders the hoisted address parts by a hash of the names (firmware
 *    0xa00af5a4 %i5 for the table, 0xa00af5a8 %i4 for the settings record).
 */
/* The user settings fields read here (offsets in the record user_settings). */
struct user_settings_record {
    unsigned char p000[8];
    unsigned char language;                     /* +0x08: menu language */
    unsigned char p009[0x11 - 0x09];
    unsigned char color_temperature;            /* +0x11: Color Temperature */
    unsigned char p012[0x1e - 0x12];
    unsigned char input_source;                 /* +0x1E: selected Input Source */
    unsigned char p01f;
    unsigned char second_source;                /* +0x20: source of the second picture */
    unsigned char p021[0xa8 - 0x21];
    unsigned int gaming_flags;                  /* +0xA8: bit 12 Refresh Rate display, bit 15 Power Button */
    unsigned int settings_page_flags;           /* +0xAC: bits 18..19 the DisplayHDR choice */
    unsigned char p0b0[0x15b - 0xb0];
    unsigned char night_vision;                 /* +0x15B: Night Vision */
    unsigned char p15c[0x181 - 0x15c];
    unsigned char pro_mode;                     /* +0x181: Professional mode */
    unsigned char p182[0x18a - 0x182];
    unsigned char navi_key_function[0x1a3 - 0x18a]; /* +0x18A: function of Navi key up, down, left, right */
    unsigned char byte_0x1a3;                   /* +0x1A3: stepped 0..3 with the Navi Key item */
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
};
extern struct user_settings_record user_settings;
extern unsigned char user_settings_kvm, user_settings_game_mode, user_settings_alarm_clock, user_settings_optix_scope, osd_list_id;
/* Settings halfword +0x34 seen as the upper half of a word: `level` is bits 0..3 of the halfword. */
struct image_enhancement_word {
    unsigned int hi : 12;
    unsigned int level : 4;                     /* Image Enhancement level */
    unsigned int f12 : 4;
    unsigned int lo : 12;
};
extern struct image_enhancement_word user_settings_image_enhancement;
extern unsigned int osd_crosshair_item_texts[], DAT_00190cec_hdr_mode_text[], osd_color_temp_texts[], osd_screen_size_texts[], osd_pip_item_texts[],
    osd_night_vision_texts[], osd_location_texts[], osd_off_on_texts[], osd_yes_no_texts[];

extern void osd_clear_choice_column(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_oled_care_choices(unsigned int);
extern void osd_draw_choice_notes(unsigned char, unsigned char);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);
extern void osd_draw_pro_mode_choices(unsigned char);
extern void osd_draw_navi_key_function_choices(unsigned char);
extern void osd_draw_language_list(unsigned char);
extern void osd_draw_alarm_clock_choices(int);
extern void osd_draw_pbp_items(void);
extern void osd_draw_game_mode_choices(void);
extern void osd_draw_image_enhancement_choices(void);
extern void osd_draw_contrast_slider(int);
extern void osd_draw_brightness_slider(void);
extern void osd_draw_sharpness_slider(int);
extern void osd_draw_transparency_slider(int);
extern void osd_draw_timeout_slider(int);
extern void osd_draw_rgb_led_choices(void);
extern void osd_draw_power_button_choices(void);
extern void osd_draw_kvm_choices(void);
extern void osd_draw_optix_scope_items(void);

/* Menu state of the first item of each tab: the page number this routine takes. */
enum {
    PAGE_GI_ITEMS           = 0x0b,
    PAGE_GAMING_ITEMS       = 0x0e,
    PAGE_PROFESSIONAL_ITEMS = 0x15,
    PAGE_IMAGE_ITEMS        = 0x18,
    PAGE_PIP_PBP_ITEMS      = 0x23,
    PAGE_NAVI_KEY_ITEMS     = 0x26,
    PAGE_SETTINGS_ITEMS     = 0x2a,
    PAGE_OLED_CARE_ITEMS    = 0x34
};

/* Menu layout in character cells. Choice n is drawn on row n * 2 + 6. */
#define CHOICE_MARK_COLUMN   0x28       /* the two cells of the choice mark: columns 0x28 and 0x29 */
#define CHOICE_TEXT_COLUMN   0x2a       /* the choice texts */
#define CHOICE_MARK_CODE     0x0f       /* byte plane values of the mark: 0x0F, then 0x10 */
#define TEXTS_PER_ITEM       29         /* a text table holds one text per menu language for every item */
#define CELL_CHOICE_GREYED   0x296      /* cell value laid under the text of a choice that cannot be selected */
#define CHOICES_PER_PAGE     7          /* longer lists are drawn in pages of seven */
#define LIST_ID_SCREEN_SIZE  0x0e       /* osd_list_id value under which osd_is_choice_enabled tests the Screen Size choices */

/* Bits of the settings words read here. */
#define REFRESH_RATE_BIT     12         /* gaming_flags bit 12: Refresh Rate display on */
#define POWER_BUTTON_BIT     15         /* gaming_flags bit 15: Power Button 0 OFF, 1 Standby */
#define HDR_MODE_SHIFT       18         /* settings_page_flags bits 18..19: DisplayHDR choice 0..2 */

/* Draw the mark of the stored choice in front of choice row `choice`. From the eighth choice on the rows start
   again at the top, as the list is then drawn as its second page. */
static void mark_choice_row(unsigned char choice)
{
    unsigned char row;

    if (choice < 7)
        row = choice * 2 + 6;
    else
        row = choice * 2 - 8;
    osd_api_fill_cell_bytes(0, CHOICE_MARK_COLUMN, row, 1, CHOICE_MARK_CODE, 0);
    osd_api_fill_cell_bytes(0, CHOICE_MARK_COLUMN + 1, row, 1, CHOICE_MARK_CODE + 1, 0);
}

/*
 * Draw the choice column for one item of a main menu tab and show which choice is stored.
 *
 *   page  menu state of the first item of the tab (PAGE_GI_ITEMS .. PAGE_OLED_CARE_ITEMS)
 *   item  the item of that tab, counted from 0; for the PIP/PBP tab the PIP/PBP mode (0 off, 1 PIP, 2 PBP)
 *
 * Called by osd_draw_tab_page, by the item step handlers of every tab (osd_select_prev|next_<tab>_item,
 * osd_enter_gaming_items, osd_leave_<tab>_items) and by some accept / cancel handlers that return to an item.
 *
 * Phases:
 *   1. Clear the choice column (osd_clear_choice_column).
 *   2. By tab and item, either call the drawer of that setting, or draw the choice texts here: set the glyph
 *      write address 0x111 and text mode 0, then write each choice text in the menu language at
 *      CHOICE_TEXT_COLUMN, row n * 2 + 6.
 *   3. Where the stored choice is known here, put the choice mark in front of it (mark_choice_row) and move the
 *      highlight to it (osd_highlight_choice_row). Some drawers mark their own choice.
 *
 * Items with no arm here (Low Blue Light, the Settings items 5..8) leave the column empty.
 */
void osd_draw_item_choices(unsigned short page, unsigned char item)
{
    unsigned char i;

    /* Phase 1: empty choice column. */
    osd_clear_choice_column();

    /* Phases 2 and 3, one arm per tab. */
    switch (page) {
    case PAGE_GI_ITEMS:
        if (item == 0) {
            /* KVM */
            osd_draw_kvm_choices();
            osd_highlight_choice_row(user_settings_kvm, 2);
        } else if (item == 1) {
            /* Smart Crosshair: the sub-items Icon, Color, Position, Reset (texts 1..4 of the table). */
            osd_api_set_glyph_write_address(0x111, 0);
            osd_api_set_text_mode(0, 0);
            for (i = 0; i <= 3; i++)
                osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_crosshair_item_texts, user_settings.language + TEXTS_PER_ITEM + i * TEXTS_PER_ITEM), 0);
        } else if (item == 2) {
            /* Optix Scope: two sub-item rows come first, so the on/off choice sits two rows lower. */
            osd_draw_optix_scope_items();
            osd_highlight_choice_row(user_settings_optix_scope + 2, 2);
        }
        break;
    case PAGE_GAMING_ITEMS:
        if (item == 0) {
            /* Game Mode */
            osd_draw_game_mode_choices();
            osd_highlight_choice_row(user_settings_game_mode, 2);
        } else if (item == 1) {
            /* Night Vision: OFF, Normal, Strong, Strongest, A. I. */
            osd_api_set_glyph_write_address(0x111, 0);
            osd_api_set_text_mode(0, 0);
            for (i = 0; i <= 4; i++)
                osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_night_vision_texts, i * TEXTS_PER_ITEM + user_settings.language), 0);
            mark_choice_row(user_settings.night_vision);
            osd_highlight_choice_row(user_settings.night_vision, 2);
        } else if (item == 2)
            /* AI Vision */
            osd_draw_choice_notes(page, item);
        else if (item == 3) {
            /* Refresh Rate: 'Location' on row 0, then OFF and ON; the stored switch is row 1 (OFF) or 2 (ON). */
            osd_api_set_glyph_write_address(0x111, 0);
            osd_api_set_text_mode(0, 0);
            osd_draw_text(0, CHOICE_TEXT_COLUMN, 6, 1, osd_get_text(osd_location_texts, user_settings.language + 5 * TEXTS_PER_ITEM), 0);
            for (i = 1; i <= 2; i++)
                osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_off_on_texts, (i - 1) * TEXTS_PER_ITEM + user_settings.language), 0);
            mark_choice_row(((user_settings.gaming_flags >> REFRESH_RATE_BIT) & 1) + 1);
            osd_highlight_choice_row(((user_settings.gaming_flags >> REFRESH_RATE_BIT) & 1) + 1, 2);
        } else if (item == 4) {
            /* Alarm Clock: OFF is row 0, the timers follow, so the stored timer sits one row lower. */
            osd_draw_alarm_clock_choices(1);
            osd_highlight_choice_row(user_settings_alarm_clock + 1, 2);
        } else if (item == 5)
            /* Adaptive-Sync */
            osd_draw_choice_notes(page, item);
        else if (item == 6)
            /* DSC */
            osd_draw_choice_notes(page, item);
        break;
    case PAGE_PROFESSIONAL_ITEMS:
        if (item == 0) {
            /* Pro Mode: the list position of the stored mode is osd_step_pro_mode_index(pro_mode, 0), the stored
               value plus one with 7 wrapping to 0. The list has two pages of seven. */
            osd_draw_pro_mode_choices(osd_step_pro_mode_index(user_settings.pro_mode, 0) / CHOICES_PER_PAGE);
            mark_choice_row(osd_step_pro_mode_index(user_settings.pro_mode, 0) % CHOICES_PER_PAGE);
            osd_highlight_choice_row(osd_step_pro_mode_index(user_settings.pro_mode, 0) % CHOICES_PER_PAGE, 2);
        } else if (item == 2) {
            /* Image Enhancement */
            osd_draw_image_enhancement_choices();
            osd_highlight_choice_row(user_settings_image_enhancement.level, 2);
        }
        break;
    case PAGE_IMAGE_ITEMS:
        if (item == 0)
            osd_draw_brightness_slider();
        else if (item == 1)
            osd_draw_contrast_slider(0);
        else if (item == 2)
            osd_draw_sharpness_slider(0);
        else if (item == 3) {
            /* Color Temperature: Cool, Normal, Warm, Customization. */
            osd_api_set_glyph_write_address(0x111, 0);
            osd_api_set_text_mode(0, 0);
            for (i = 0; i <= 3; i++)
                osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_color_temp_texts, i * TEXTS_PER_ITEM + user_settings.language), 0);
            mark_choice_row(user_settings.color_temperature);
            osd_highlight_choice_row(user_settings.color_temperature, 2);
        } else if (item == 4) {
            /* Screen Size: seven choices. osd_is_choice_enabled answers for the list named by osd_list_id, so
               the Screen Size list id is set while the rows are drawn and the old id put back afterwards.
               Choices that cannot be selected now are laid on greyed cells first. */
            unsigned char saved_list_id, count;

            osd_api_set_glyph_write_address(0x111, 0);
            osd_api_set_text_mode(0, 0);
            saved_list_id = osd_list_id;
            osd_list_id = LIST_ID_SCREEN_SIZE;
            count = 7;
            for (i = 0; i < count; i++) {
                if (osd_is_choice_enabled(i) == 0)
                    osd_api_fill_cells(CHOICE_TEXT_COLUMN, i * 2 + 6, 0xa, CELL_CHOICE_GREYED, 0);
                osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_screen_size_texts, i * TEXTS_PER_ITEM + user_settings.language), 0);
            }
            mark_choice_row(user_settings.screen_size);
            osd_list_id = saved_list_id;
            osd_highlight_choice_row(user_settings.screen_size, 2);
        } else if (item == 5) {
            /* DisplayHDR: True Black 400, Peak 1000 nits, EOTF Boost. */
            osd_api_set_glyph_write_address(0x111, 0);
            osd_api_set_text_mode(0, 0);
            for (i = 0; i <= 2; i++)
                osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(DAT_00190cec_hdr_mode_text, i * TEXTS_PER_ITEM + user_settings.language), 0);
            mark_choice_row((user_settings.settings_page_flags >> HDR_MODE_SHIFT) & 3);
            osd_highlight_choice_row((user_settings.settings_page_flags >> HDR_MODE_SHIFT) & 3, 2);
        }
        break;
    case PAGE_PIP_PBP_ITEMS:
        if (item == 1) {
            /* PIP: the PIP items Source, PIP Size, Location, Display Switch, Audio Switch. With both pictures
               on the same source, Display Switch and Audio Switch (rows 0xC and 0xE) are greyed. */
            osd_api_set_glyph_write_address(0x111, 0);
            osd_api_set_text_mode(0, 0);
            if (user_settings.input_source == user_settings.second_source) {
                osd_api_fill_cells(CHOICE_TEXT_COLUMN, 0xc, 0xb, CELL_CHOICE_GREYED, 0);
                osd_api_fill_cells(CHOICE_TEXT_COLUMN, 0xe, 0xb, CELL_CHOICE_GREYED, 0);
            }
            for (i = 0; i <= 4; i++)
                osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_pip_item_texts, i * TEXTS_PER_ITEM + user_settings.language), 0);
        } else if (item == 2)
            /* PBP */
            osd_draw_pbp_items();
        else
            osd_draw_choice_notes(page, item);
        break;
    case PAGE_NAVI_KEY_ITEMS:
        /* Navi Key: the function list of the key numbered by settings byte +0x1A3 (not by `item`). Functions
           7 and up are on the second page of the list. */
        if (user_settings.navi_key_function[user_settings.byte_0x1a3] > 6)
            osd_draw_navi_key_function_choices(1);
        else
            osd_draw_navi_key_function_choices(0);
        osd_highlight_choice_row(user_settings.navi_key_function[user_settings.byte_0x1a3] % CHOICES_PER_PAGE, 2);
        mark_choice_row(user_settings.navi_key_function[user_settings.byte_0x1a3] % CHOICES_PER_PAGE);
        break;
    case PAGE_SETTINGS_ITEMS:
        if (item == 0) {
            /* Language: the page of seven that holds the current language. */
            osd_draw_language_list(user_settings.language / CHOICES_PER_PAGE);
            osd_highlight_choice_row(user_settings.language % CHOICES_PER_PAGE, 2);
            mark_choice_row(user_settings.language % CHOICES_PER_PAGE);
        } else if (item == 1)
            osd_draw_transparency_slider(0);
        else if (item == 2)
            osd_draw_timeout_slider(0);
        else if (item == 3)
            osd_draw_rgb_led_choices();
        else if (item == 4) {
            /* Power Button: OFF or Standby. */
            osd_draw_power_button_choices();
            osd_highlight_choice_row((user_settings.gaming_flags >> POWER_BUTTON_BIT) & 1, 2);
        } else if (item == 9) {
            /* Reset: Yes, No. Nothing is marked or highlighted. */
            unsigned char j;

            osd_api_set_glyph_write_address(0x111, 0);
            osd_api_set_text_mode(0, 0);
            for (j = 0; j <= 1; j++)
                osd_draw_text(0, CHOICE_TEXT_COLUMN, j * 2 + 6, 1, osd_get_text(osd_yes_no_texts, j * TEXTS_PER_ITEM + user_settings.language), 0);
        }
        break;
    case PAGE_OLED_CARE_ITEMS:
        /* MSI OLED Care: the drawer takes the menu state of the item. */
        osd_draw_oled_care_choices((unsigned short)(item + PAGE_OLED_CARE_ITEMS));
        break;
    }
}
