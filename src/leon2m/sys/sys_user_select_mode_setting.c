/* sys_user_select_mode_setting  (FUN_a00d8100)
 *
 * Select the settings field that belongs to an item number in the current picture mode.
 * Name basis: derived - index and mode byte into bytes, words and bits of the settings record; used by
 *   UserSetProMode and UserSetGameMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8100 @ 0xa00d8100-0xa00d8b30 (2608 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the case bodies are written in the order 6, 0, 2, 1, 3, 5, 7, 8, 4 (the jump table fixes the block
 * layout; the source order decides the register names); the Pro/Game test is written with the Game arm first,
 * every SECOND_TABLE_FLAG test with the set arm first. The mode number is an unsigned char, zero-extended at each
 * use. Items 4, 7 and 8 are if-chains over the mode number, not array reads; the per-mode words and bits are
 * single fields of the record.
 */

/*
 * The fields of the user settings record used here (docs/RECORDS.md). The record is stored with the most
 * significant bit first, so the first bit-field of a word is its bit 31.
 *
 * Each setting that follows the picture mode has two sets of per-mode copies: "tab1" is read while
 * SECOND_TABLE_FLAG is clear, "tab2" while it is set. The byte copies are arrays indexed by the mode number. The
 * word and bit copies are single fields, named here by the mode number that selects them; their order in the
 * record is not the mode order (see the routine's comment).
 */
struct user_settings_record {
    unsigned char pad000[9];
    unsigned char brightness;                   /* +0x09: Brightness */
    unsigned char contrast;                     /* +0x0A: Contrast */
    unsigned char pad00b[0x19 - 0xb];
    unsigned char response_time;                /* +0x19: the response time level */
    unsigned char pad01a[0x34 - 0x1a];
    struct {
        unsigned int upper : 12;
        unsigned int level : 4;                 /* halfword +0x34 bits 0..3: Image Enhancement level */
        unsigned int rest : 16;
    } image_enhancement;                        /* +0x34 */
    unsigned char pad038[0x49 - 0x38];
    unsigned char sharpness;                    /* +0x49: Sharpness */
    unsigned char pad04a[0x58 - 0x4a];
    unsigned char brightness_tab1[13];          /* +0x58 */
    unsigned char brightness_tab2[13];          /* +0x65 */
    unsigned char contrast_tab1[13];            /* +0x72 */
    unsigned char contrast_tab2[13];            /* +0x7F */
    unsigned char pad08c[0x90 - 0x8c];
    unsigned char response_time_tab1[13];       /* +0x90 */
    unsigned char response_time_tab2[11];       /* +0x9D: only 11 bytes before the next field */
    unsigned int gaming_flags;                  /* +0xA8: bit 11 = Pro (1) / Game (0) mode */
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned int blur_free_tab1_mode0;          /* +0xB4 */
    unsigned int blur_free_tab1_mode1;
    unsigned int blur_free_tab1_mode2;
    unsigned int blur_free_tab1_mode3;
    unsigned int blur_free_tab1_mode4;
    unsigned int blur_free_tab1_mode5;
    unsigned int blur_free_tab1_mode6;          /* +0xCC */
    unsigned int blur_free_tab1_mode12;         /* +0xD0 */
    unsigned int blur_free_tab1_mode7;          /* +0xD4 */
    unsigned int blur_free_tab1_mode8;
    unsigned int blur_free_tab1_mode9;
    unsigned int blur_free_tab1_mode10;
    unsigned int blur_free_tab1_mode11;         /* +0xE4 */
    unsigned int blur_free_tab2_mode0;          /* +0xE8 */
    unsigned int blur_free_tab2_mode1;
    unsigned int blur_free_tab2_mode2;
    unsigned int blur_free_tab2_mode3;
    unsigned int blur_free_tab2_mode4;
    unsigned int blur_free_tab2_mode5;
    unsigned int blur_free_tab2_mode12;         /* +0x100 */
    unsigned int blur_free_tab2_mode6;          /* +0x104 */
    unsigned int blur_free_tab2_mode7;
    unsigned int blur_free_tab2_mode8;
    unsigned int blur_free_tab2_mode9;
    unsigned int blur_free_tab2_mode10;
    unsigned int blur_free_tab2_mode11;         /* +0x118 */
    /* +0x11C, the professional flags word: bit 31 automatic level, bit 4 Low Blue Light. */
    unsigned int auto_level : 1;                /* bit 31 */
    unsigned int auto_level_tab1_mode0 : 1;     /* bits 30..25: modes 0..5 */
    unsigned int auto_level_tab1_mode1 : 1;
    unsigned int auto_level_tab1_mode2 : 1;
    unsigned int auto_level_tab1_mode3 : 1;
    unsigned int auto_level_tab1_mode4 : 1;
    unsigned int auto_level_tab1_mode5 : 1;
    unsigned int auto_level_tab1_mode12 : 1;    /* bit 24 */
    unsigned int auto_level_tab1_mode6 : 1;     /* bits 23..18: modes 6..11 */
    unsigned int auto_level_tab1_mode7 : 1;
    unsigned int auto_level_tab1_mode8 : 1;
    unsigned int auto_level_tab1_mode9 : 1;
    unsigned int auto_level_tab1_mode10 : 1;
    unsigned int auto_level_tab1_mode11 : 1;
    unsigned int auto_level_tab2_mode0 : 1;     /* bits 17..12: modes 0..5 */
    unsigned int auto_level_tab2_mode1 : 1;
    unsigned int auto_level_tab2_mode2 : 1;
    unsigned int auto_level_tab2_mode3 : 1;
    unsigned int auto_level_tab2_mode4 : 1;
    unsigned int auto_level_tab2_mode5 : 1;
    unsigned int auto_level_tab2_mode12 : 1;    /* bit 11 */
    unsigned int auto_level_tab2_mode6 : 1;     /* bits 10..5: modes 6..11 */
    unsigned int auto_level_tab2_mode7 : 1;
    unsigned int auto_level_tab2_mode8 : 1;
    unsigned int auto_level_tab2_mode9 : 1;
    unsigned int auto_level_tab2_mode10 : 1;
    unsigned int auto_level_tab2_mode11 : 1;
    unsigned int low_blue_light : 1;            /* bit 4 */
    unsigned int low_blue_light_tab1_mode0 : 1; /* bits 3..0: modes 0..3 */
    unsigned int low_blue_light_tab1_mode1 : 1;
    unsigned int low_blue_light_tab1_mode2 : 1;
    unsigned int low_blue_light_tab1_mode3 : 1;
    /* +0x120 */
    unsigned int low_blue_light_tab1_mode4 : 1; /* bit 31 */
    unsigned int low_blue_light_tab1_mode5 : 1; /* bit 30 */
    unsigned int low_blue_light_tab1_mode12 : 1; /* bit 29 */
    unsigned int low_blue_light_tab1_mode6 : 1; /* bits 28..23: modes 6..11 */
    unsigned int low_blue_light_tab1_mode7 : 1;
    unsigned int low_blue_light_tab1_mode8 : 1;
    unsigned int low_blue_light_tab1_mode9 : 1;
    unsigned int low_blue_light_tab1_mode10 : 1;
    unsigned int low_blue_light_tab1_mode11 : 1;
    unsigned int low_blue_light_tab2_mode0 : 1; /* bits 22..17: modes 0..5 */
    unsigned int low_blue_light_tab2_mode1 : 1;
    unsigned int low_blue_light_tab2_mode2 : 1;
    unsigned int low_blue_light_tab2_mode3 : 1;
    unsigned int low_blue_light_tab2_mode4 : 1;
    unsigned int low_blue_light_tab2_mode5 : 1;
    unsigned int low_blue_light_tab2_mode12 : 1; /* bit 16 */
    unsigned int low_blue_light_tab2_mode6 : 1; /* bits 15..10: modes 6..11 */
    unsigned int low_blue_light_tab2_mode7 : 1;
    unsigned int low_blue_light_tab2_mode8 : 1;
    unsigned int low_blue_light_tab2_mode9 : 1;
    unsigned int low_blue_light_tab2_mode10 : 1;
    unsigned int low_blue_light_tab2_mode11 : 1;
    unsigned char sharpness_tab1[13];           /* +0x123, right after the bits above */
    unsigned char sharpness_tab2[13];           /* +0x130 */
    unsigned char pad13d[0x15b - 0x13d];
    unsigned char night_vision;                 /* +0x15B: Night Vision */
    unsigned char night_vision_tab1[13];        /* +0x15C */
    unsigned char night_vision_tab2[11];        /* +0x169: only 11 bytes before word +0x174 */
    unsigned char pad174[0x181 - 0x174];
    unsigned char pro_mode;                     /* +0x181: the Professional mode */
    unsigned char game_mode;                    /* +0x182: the Game Mode */
    unsigned char pad183[0x1bb - 0x183];
    unsigned char image_enhance_tab1[13];       /* +0x1BB */
    unsigned char image_enhance_tab2[13];       /* +0x1C8 */
};
extern struct user_settings_record user_settings;
/* Halfword +0xA of app_state_record (0xA802CFF4). */
extern unsigned short app_state_record_half_0xa;

/* Item numbers (the parameter); the same names as in UserSetProMode and UserSetGameMode. */
enum {
    MODE_ITEM_BRIGHTNESS      = 0,      /* +0x09 */
    MODE_ITEM_CONTRAST        = 1,      /* +0x0A */
    MODE_ITEM_RESPONSE_TIME   = 2,      /* +0x19 */
    MODE_ITEM_NIGHT_VISION    = 3,      /* +0x15B */
    MODE_ITEM_BLUR_FREE       = 4,      /* +0xB0 */
    MODE_ITEM_IMAGE_ENHANCE   = 5,      /* +0x34 bits 0..3 */
    MODE_ITEM_SHARPNESS       = 6,      /* +0x49 */
    MODE_ITEM_AUTO_LEVEL      = 7,      /* +0x11C bit 31 */
    MODE_ITEM_LOW_BLUE_LIGHT  = 8       /* +0x11C bit 4 */
};

#define GAMING_FLAG_PRO_MODE 0x800      /* gaming_flags bit 11: Pro (1) / Game (0) mode */
#define PRO_MODE_NUMBER_BASE 5          /* Pro modes 1 and up take mode numbers 6 and up */
#define SECOND_TABLE_FLAG    0x80       /* bit 7 of app_state_record_half_0xa: read the tab2 copies. UserGetCECSourceMode sets
                                           it when it loads mode copy 1 and clears it when it loads copy 2 */
#define SECOND_TABLE_IN_USE  (app_state_record_half_0xa & SECOND_TABLE_FLAG)

/*
 * Copy one setting from its per-mode copy into the live field of the settings record.
 *
 * item: which setting (MODE_ITEM_*, 0..8); any other value changes nothing. Called by UserSetProMode and
 * UserSetGameMode for each setting that follows the picture mode, before they apply the settings.
 *
 * Phases, in order:
 *   1. The mode number: with the Game Mode chosen (gaming_flags bit 11 clear) it is the Game Mode byte. With the
 *      Pro Mode chosen it is 1 for Pro mode 0 and the Pro mode + 5 otherwise, so Pro mode 0 shares number 1
 *      with Game Mode 1.
 *   2. The copy set: tab2 while SECOND_TABLE_FLAG is set, else tab1.
 *   3. The copy itself, by item:
 *      - brightness, contrast, response time, Night Vision, sharpness, Image Enhancement: byte table[mode].
 *        Only 11 bytes of response_time_tab2 and night_vision_tab2 lie before the next field, so mode numbers
 *        11 and 12 read the first bytes of gaming_flags and of word +0x174.
 *      - blur reduction (a word), automatic level and Low Blue Light (one bit each): an if-chain over modes
 *        0..12, other mode numbers change nothing. Modes 0..5 sit in record order, then mode 12, then modes
 *        6..11; in blur_free_tab1 alone mode 6 comes before mode 12.
 */
void sys_user_select_mode_setting(unsigned char item)
{
    unsigned char mode;

    /* 1. Mode number. */
    if (!(user_settings.gaming_flags & GAMING_FLAG_PRO_MODE))
        mode = user_settings.game_mode;
    else if (user_settings.pro_mode == 0)
        mode = 1;
    else
        mode = user_settings.pro_mode + PRO_MODE_NUMBER_BASE;

    /* 2 and 3. Copy set and copy, per item. */
    switch (item) {
    case MODE_ITEM_SHARPNESS:
        if (SECOND_TABLE_IN_USE)
            user_settings.sharpness = user_settings.sharpness_tab2[mode];
        else
            user_settings.sharpness = user_settings.sharpness_tab1[mode];
        break;
    case MODE_ITEM_BRIGHTNESS:
        if (SECOND_TABLE_IN_USE)
            user_settings.brightness = user_settings.brightness_tab2[mode];
        else
            user_settings.brightness = user_settings.brightness_tab1[mode];
        break;
    case MODE_ITEM_RESPONSE_TIME:
        if (SECOND_TABLE_IN_USE)
            user_settings.response_time = user_settings.response_time_tab2[mode];
        else
            user_settings.response_time = user_settings.response_time_tab1[mode];
        break;
    case MODE_ITEM_CONTRAST:
        if (SECOND_TABLE_IN_USE)
            user_settings.contrast = user_settings.contrast_tab2[mode];
        else
            user_settings.contrast = user_settings.contrast_tab1[mode];
        break;
    case MODE_ITEM_NIGHT_VISION:
        if (SECOND_TABLE_IN_USE)
            user_settings.night_vision = user_settings.night_vision_tab2[mode];
        else
            user_settings.night_vision = user_settings.night_vision_tab1[mode];
        break;
    case MODE_ITEM_IMAGE_ENHANCE:
        if (SECOND_TABLE_IN_USE)
            user_settings.image_enhancement.level = user_settings.image_enhance_tab2[mode];
        else
            user_settings.image_enhancement.level = user_settings.image_enhance_tab1[mode];
        break;
    case MODE_ITEM_AUTO_LEVEL:
        if (mode == 0) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode0;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode0;
        } else if (mode == 1) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode1;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode1;
        } else if (mode == 2) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode2;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode2;
        } else if (mode == 3) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode3;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode3;
        } else if (mode == 4) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode4;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode4;
        } else if (mode == 5) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode5;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode5;
        } else if (mode == 6) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode6;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode6;
        } else if (mode == 7) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode7;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode7;
        } else if (mode == 8) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode8;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode8;
        } else if (mode == 9) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode9;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode9;
        } else if (mode == 10) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode10;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode10;
        } else if (mode == 11) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode11;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode11;
        } else if (mode == 12) {
            if (SECOND_TABLE_IN_USE)
                user_settings.auto_level = user_settings.auto_level_tab2_mode12;
            else
                user_settings.auto_level = user_settings.auto_level_tab1_mode12;
        }
        break;
    case MODE_ITEM_LOW_BLUE_LIGHT:
        if (mode == 0) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode0;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode0;
        } else if (mode == 1) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode1;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode1;
        } else if (mode == 2) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode2;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode2;
        } else if (mode == 3) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode3;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode3;
        } else if (mode == 4) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode4;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode4;
        } else if (mode == 5) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode5;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode5;
        } else if (mode == 6) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode6;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode6;
        } else if (mode == 7) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode7;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode7;
        } else if (mode == 8) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode8;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode8;
        } else if (mode == 9) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode9;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode9;
        } else if (mode == 10) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode10;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode10;
        } else if (mode == 11) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode11;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode11;
        } else if (mode == 12) {
            if (SECOND_TABLE_IN_USE)
                user_settings.low_blue_light = user_settings.low_blue_light_tab2_mode12;
            else
                user_settings.low_blue_light = user_settings.low_blue_light_tab1_mode12;
        }
        break;
    case MODE_ITEM_BLUR_FREE:
        if (mode == 0) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode0;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode0;
        } else if (mode == 1) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode1;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode1;
        } else if (mode == 2) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode2;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode2;
        } else if (mode == 3) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode3;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode3;
        } else if (mode == 4) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode4;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode4;
        } else if (mode == 5) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode5;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode5;
        } else if (mode == 6) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode6;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode6;
        } else if (mode == 7) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode7;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode7;
        } else if (mode == 8) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode8;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode8;
        } else if (mode == 9) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode9;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode9;
        } else if (mode == 10) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode10;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode10;
        } else if (mode == 11) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode11;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode11;
        } else if (mode == 12) {
            if (SECOND_TABLE_IN_USE)
                user_settings.blur_free_mode = user_settings.blur_free_tab2_mode12;
            else
                user_settings.blur_free_mode = user_settings.blur_free_tab1_mode12;
        }
        break;
    }
}
