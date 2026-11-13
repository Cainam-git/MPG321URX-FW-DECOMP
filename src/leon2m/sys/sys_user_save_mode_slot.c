/* sys_user_save_mode_slot  (FUN_a00d4998)
 *
 * Copy the current picture settings into the slot of a picture mode.
 * Name basis: derived - one of 26 slot entries with byte, word and bit-field arrays
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4998 @ 0xa00d4998-0xa00d5748 (876 words), flags -mcpu=v8 -O3 -g. No calls, no parameters.
 * The switch uses the jump table at 0xa00d3a30 (sys_user_save_mode_slot_jump_table).
 * Source form: in each arm the byte and word copies come before the two bit-field copies (the other order lets
 * the scheduler move the last byte store first); the case order is 0, 3, 1, 2, 4, 5, 8, 6, 9, 11, 12, 10, 7; the
 * mode number is chosen by an if / else-if chain with the Game Mode test first and the 'pro_mode == 0' test
 * second. The Image Enhancement level sits in an unsigned short bit-field and the Pro bit in an unsigned int
 * bit-field that starts at +0xAA; both container types are part of the exact build.
 */

/*
 * The fields of the user settings record used here (docs/RECORDS.md); the same names as in
 * sys_user_select_mode_setting, which reads these copies back. The record is stored with the most significant
 * bit first, so the first bit-field of a word is its bit 31.
 *
 * Each setting that follows the picture mode has two sets of per-mode copies: "tab1" is written while
 * SECOND_TABLE_FLAG is clear, "tab2" while it is set. The byte copies are arrays indexed by the mode number. The
 * word and bit copies are single fields, named by the mode number that selects them; in the record, modes 0..5
 * come first, then mode 12, then modes 6..11, except in blur_free_tab1, where mode 6 comes before mode 12.
 */
struct user_settings_record {
    unsigned char pad000[9];
    unsigned char brightness;                   /* +0x09: Brightness */
    unsigned char contrast;                     /* +0x0A: Contrast */
    unsigned char pad00b[0x19 - 0xb];
    unsigned char response_time;                /* +0x19: the response time level */
    unsigned char pad01a[0x34 - 0x1a];
    unsigned short image_enhancement_upper : 12,
                   image_enhancement : 4;       /* halfword +0x34 bits 0..3: Image Enhancement level */
    unsigned char pad036[0x49 - 0x36];
    unsigned char sharpness;                    /* +0x49: Sharpness */
    unsigned char pad04a[0x58 - 0x4a];
    unsigned char brightness_tab1[13];          /* +0x58 */
    unsigned char brightness_tab2[13];          /* +0x65 */
    unsigned char contrast_tab1[13];            /* +0x72 */
    unsigned char contrast_tab2[13];            /* +0x7F */
    unsigned char pad08c[0x90 - 0x8c];
    unsigned char response_time_tab1[13];       /* +0x90 */
    unsigned char response_time_tab2[13];       /* +0x9D; modes 11 and 12 land on +0xA8 and +0xA9, the top two
                                                   bytes of the gaming_flags word */
    /* Bits 15..0 of the gaming_flags word +0xA8. */
    unsigned int gaming_flags_bits15_12 : 4,
                 pro_selected : 1,              /* bit 11: Pro (1) / Game (0) mode */
                 gaming_flags_bits10_0 : 11;
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
    unsigned int auto_level : 1,                /* bit 31 */
                 auto_level_tab1_mode0 : 1,     /* bits 30..25: modes 0..5 */
                 auto_level_tab1_mode1 : 1,
                 auto_level_tab1_mode2 : 1,
                 auto_level_tab1_mode3 : 1,
                 auto_level_tab1_mode4 : 1,
                 auto_level_tab1_mode5 : 1,
                 auto_level_tab1_mode12 : 1,    /* bit 24 */
                 auto_level_tab1_mode6 : 1,     /* bits 23..18: modes 6..11 */
                 auto_level_tab1_mode7 : 1,
                 auto_level_tab1_mode8 : 1,
                 auto_level_tab1_mode9 : 1,
                 auto_level_tab1_mode10 : 1,
                 auto_level_tab1_mode11 : 1,
                 auto_level_tab2_mode0 : 1,     /* bits 17..12: modes 0..5 */
                 auto_level_tab2_mode1 : 1,
                 auto_level_tab2_mode2 : 1,
                 auto_level_tab2_mode3 : 1,
                 auto_level_tab2_mode4 : 1,
                 auto_level_tab2_mode5 : 1,
                 auto_level_tab2_mode12 : 1,    /* bit 11 */
                 auto_level_tab2_mode6 : 1,     /* bits 10..5: modes 6..11 */
                 auto_level_tab2_mode7 : 1,
                 auto_level_tab2_mode8 : 1,
                 auto_level_tab2_mode9 : 1,
                 auto_level_tab2_mode10 : 1,
                 auto_level_tab2_mode11 : 1,
                 low_blue_light : 1,            /* bit 4 */
                 low_blue_light_tab1_mode0 : 1, /* bits 3..0: modes 0..3 */
                 low_blue_light_tab1_mode1 : 1,
                 low_blue_light_tab1_mode2 : 1,
                 low_blue_light_tab1_mode3 : 1;
    /* +0x120 */
    unsigned int low_blue_light_tab1_mode4 : 1,  /* bit 31 */
                 low_blue_light_tab1_mode5 : 1,  /* bit 30 */
                 low_blue_light_tab1_mode12 : 1, /* bit 29 */
                 low_blue_light_tab1_mode6 : 1,  /* bits 28..23: modes 6..11 */
                 low_blue_light_tab1_mode7 : 1,
                 low_blue_light_tab1_mode8 : 1,
                 low_blue_light_tab1_mode9 : 1,
                 low_blue_light_tab1_mode10 : 1,
                 low_blue_light_tab1_mode11 : 1,
                 low_blue_light_tab2_mode0 : 1,  /* bits 22..17: modes 0..5 */
                 low_blue_light_tab2_mode1 : 1,
                 low_blue_light_tab2_mode2 : 1,
                 low_blue_light_tab2_mode3 : 1,
                 low_blue_light_tab2_mode4 : 1,
                 low_blue_light_tab2_mode5 : 1,
                 low_blue_light_tab2_mode12 : 1, /* bit 16 */
                 low_blue_light_tab2_mode6 : 1,  /* bits 15..10: modes 6..11 */
                 low_blue_light_tab2_mode7 : 1,
                 low_blue_light_tab2_mode8 : 1,
                 low_blue_light_tab2_mode9 : 1,
                 low_blue_light_tab2_mode10 : 1,
                 low_blue_light_tab2_mode11 : 1;
    unsigned char sharpness_tab1[13];           /* +0x123, right after the bits above */
    unsigned char sharpness_tab2[13];           /* +0x130 */
    unsigned char pad13d[0x15b - 0x13d];
    unsigned char night_vision;                 /* +0x15B: Night Vision */
    unsigned char night_vision_tab1[13];        /* +0x15C */
    unsigned char night_vision_tab2[13];        /* +0x169; modes 11 and 12 land on +0x174 and +0x175, the top two
                                                   bytes of settings word +0x174 */
    unsigned char pad176[0x181 - 0x176];
    unsigned char pro_mode;                     /* +0x181: the Professional mode */
    unsigned char game_mode;                    /* +0x182: the Game Mode */
    unsigned char pad183[0x1bb - 0x183];
    unsigned char image_enhance_tab1[13];       /* +0x1BB */
    unsigned char image_enhance_tab2[13];       /* +0x1C8 */
};
extern struct user_settings_record user_settings;
/* Halfword +0xA of app_state_record (0xA802CFF4). */
extern unsigned short app_state_record_half_0xa;
extern unsigned char osd_request_bits;

#define SECOND_TABLE_FLAG    0x80       /* bit 7 of app_state_record_half_0xa: write the tab2 copies */
#define SECOND_TABLE_IN_USE  (app_state_record_half_0xa & SECOND_TABLE_FLAG)
#define PRO_MODE_NUMBER_BASE 5          /* Pro modes 1 and up take mode numbers 6 and up */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* osd_request_bits: OSD event 0x80 */

/*
 * Store the live value of every setting that follows the picture mode into the copy of the current mode.
 * This is the reverse of sys_user_select_mode_setting, with the same mode number and the same copy set.
 *
 * The settings saved: brightness, contrast, response time, Night Vision, blur reduction, Image Enhancement,
 * sharpness, automatic level and Low Blue Light. Callers change one of them first and then call this routine,
 * for example osd_flip_low_blue_light_setting, osd_accept_night_vision, uart_cmd_set_low_blue_light,
 * uart_cmd_set_night_vision and ddc_apply_maker_vcp_set (39 callers in all).
 *
 * Phases, in order:
 *   1. The mode number: with the Game Mode chosen (pro_selected clear) it is the Game Mode byte. With the Pro
 *      Mode chosen it is 1 for Pro mode 0 and the Pro mode + 5 otherwise, so Pro mode 0 shares number 1 with
 *      Game Mode 1.
 *   2. One switch arm per mode number 0..12. Each arm picks the copy set (tab2 while SECOND_TABLE_FLAG is set,
 *      else tab1) and copies the seven byte and word settings, then the two switch bits. A mode number above 12
 *      copies nothing.
 *   3. In every case, OSD_REQUEST_SETTINGS_CHANGED is set in osd_request_bits.
 *
 * In tab2, the response time and Night Vision copies of modes 11 and 12 are stored past the 13-byte arrays,
 * into the top two bytes of gaming_flags (+0xA8, +0xA9) and of word +0x174.
 */
void sys_user_save_mode_slot(void)
{
    unsigned char mode;

    /* 1. Mode number. */
    if (!user_settings.pro_selected)
        mode = user_settings.game_mode;
    else if (user_settings.pro_mode == 0)
        mode = 1;
    else
        mode = user_settings.pro_mode + PRO_MODE_NUMBER_BASE;

    /* 2. Copy set and copies, per mode number. */
    switch (mode) {
    case 0:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[0] = user_settings.brightness;
            user_settings.contrast_tab2[0] = user_settings.contrast;
            user_settings.response_time_tab2[0] = user_settings.response_time;
            user_settings.night_vision_tab2[0] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode0 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[0] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[0] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode0 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode0 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[0] = user_settings.brightness;
            user_settings.contrast_tab1[0] = user_settings.contrast;
            user_settings.response_time_tab1[0] = user_settings.response_time;
            user_settings.night_vision_tab1[0] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode0 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[0] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[0] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode0 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode0 = user_settings.low_blue_light;
        }
        break;
    case 3:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[3] = user_settings.brightness;
            user_settings.contrast_tab2[3] = user_settings.contrast;
            user_settings.response_time_tab2[3] = user_settings.response_time;
            user_settings.night_vision_tab2[3] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode3 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[3] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[3] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode3 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode3 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[3] = user_settings.brightness;
            user_settings.contrast_tab1[3] = user_settings.contrast;
            user_settings.response_time_tab1[3] = user_settings.response_time;
            user_settings.night_vision_tab1[3] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode3 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[3] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[3] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode3 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode3 = user_settings.low_blue_light;
        }
        break;
    case 1:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[1] = user_settings.brightness;
            user_settings.contrast_tab2[1] = user_settings.contrast;
            user_settings.response_time_tab2[1] = user_settings.response_time;
            user_settings.night_vision_tab2[1] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode1 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[1] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[1] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode1 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode1 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[1] = user_settings.brightness;
            user_settings.contrast_tab1[1] = user_settings.contrast;
            user_settings.response_time_tab1[1] = user_settings.response_time;
            user_settings.night_vision_tab1[1] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode1 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[1] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[1] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode1 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode1 = user_settings.low_blue_light;
        }
        break;
    case 2:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[2] = user_settings.brightness;
            user_settings.contrast_tab2[2] = user_settings.contrast;
            user_settings.response_time_tab2[2] = user_settings.response_time;
            user_settings.night_vision_tab2[2] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode2 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[2] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[2] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode2 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode2 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[2] = user_settings.brightness;
            user_settings.contrast_tab1[2] = user_settings.contrast;
            user_settings.response_time_tab1[2] = user_settings.response_time;
            user_settings.night_vision_tab1[2] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode2 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[2] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[2] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode2 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode2 = user_settings.low_blue_light;
        }
        break;
    case 4:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[4] = user_settings.brightness;
            user_settings.contrast_tab2[4] = user_settings.contrast;
            user_settings.response_time_tab2[4] = user_settings.response_time;
            user_settings.night_vision_tab2[4] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode4 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[4] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[4] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode4 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode4 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[4] = user_settings.brightness;
            user_settings.contrast_tab1[4] = user_settings.contrast;
            user_settings.response_time_tab1[4] = user_settings.response_time;
            user_settings.night_vision_tab1[4] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode4 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[4] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[4] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode4 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode4 = user_settings.low_blue_light;
        }
        break;
    case 5:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[5] = user_settings.brightness;
            user_settings.contrast_tab2[5] = user_settings.contrast;
            user_settings.response_time_tab2[5] = user_settings.response_time;
            user_settings.night_vision_tab2[5] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode5 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[5] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[5] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode5 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode5 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[5] = user_settings.brightness;
            user_settings.contrast_tab1[5] = user_settings.contrast;
            user_settings.response_time_tab1[5] = user_settings.response_time;
            user_settings.night_vision_tab1[5] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode5 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[5] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[5] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode5 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode5 = user_settings.low_blue_light;
        }
        break;
    case 8:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[8] = user_settings.brightness;
            user_settings.contrast_tab2[8] = user_settings.contrast;
            user_settings.response_time_tab2[8] = user_settings.response_time;
            user_settings.night_vision_tab2[8] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode8 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[8] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[8] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode8 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode8 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[8] = user_settings.brightness;
            user_settings.contrast_tab1[8] = user_settings.contrast;
            user_settings.response_time_tab1[8] = user_settings.response_time;
            user_settings.night_vision_tab1[8] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode8 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[8] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[8] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode8 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode8 = user_settings.low_blue_light;
        }
        break;
    case 6:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[6] = user_settings.brightness;
            user_settings.contrast_tab2[6] = user_settings.contrast;
            user_settings.response_time_tab2[6] = user_settings.response_time;
            user_settings.night_vision_tab2[6] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode6 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[6] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[6] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode6 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode6 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[6] = user_settings.brightness;
            user_settings.contrast_tab1[6] = user_settings.contrast;
            user_settings.response_time_tab1[6] = user_settings.response_time;
            user_settings.night_vision_tab1[6] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode6 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[6] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[6] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode6 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode6 = user_settings.low_blue_light;
        }
        break;
    case 9:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[9] = user_settings.brightness;
            user_settings.contrast_tab2[9] = user_settings.contrast;
            user_settings.response_time_tab2[9] = user_settings.response_time;
            user_settings.night_vision_tab2[9] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode9 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[9] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[9] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode9 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode9 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[9] = user_settings.brightness;
            user_settings.contrast_tab1[9] = user_settings.contrast;
            user_settings.response_time_tab1[9] = user_settings.response_time;
            user_settings.night_vision_tab1[9] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode9 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[9] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[9] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode9 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode9 = user_settings.low_blue_light;
        }
        break;
    case 11:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[11] = user_settings.brightness;
            user_settings.contrast_tab2[11] = user_settings.contrast;
            user_settings.response_time_tab2[11] = user_settings.response_time;    /* byte +0xA8 */
            user_settings.night_vision_tab2[11] = user_settings.night_vision;      /* byte +0x174 */
            user_settings.blur_free_tab2_mode11 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[11] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[11] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode11 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode11 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[11] = user_settings.brightness;
            user_settings.contrast_tab1[11] = user_settings.contrast;
            user_settings.response_time_tab1[11] = user_settings.response_time;
            user_settings.night_vision_tab1[11] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode11 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[11] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[11] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode11 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode11 = user_settings.low_blue_light;
        }
        break;
    case 12:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[12] = user_settings.brightness;
            user_settings.contrast_tab2[12] = user_settings.contrast;
            user_settings.response_time_tab2[12] = user_settings.response_time;    /* byte +0xA9 */
            user_settings.night_vision_tab2[12] = user_settings.night_vision;      /* byte +0x175 */
            user_settings.blur_free_tab2_mode12 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[12] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[12] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode12 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode12 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[12] = user_settings.brightness;
            user_settings.contrast_tab1[12] = user_settings.contrast;
            user_settings.response_time_tab1[12] = user_settings.response_time;
            user_settings.night_vision_tab1[12] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode12 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[12] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[12] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode12 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode12 = user_settings.low_blue_light;
        }
        break;
    case 10:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[10] = user_settings.brightness;
            user_settings.contrast_tab2[10] = user_settings.contrast;
            user_settings.response_time_tab2[10] = user_settings.response_time;
            user_settings.night_vision_tab2[10] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode10 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[10] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[10] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode10 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode10 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[10] = user_settings.brightness;
            user_settings.contrast_tab1[10] = user_settings.contrast;
            user_settings.response_time_tab1[10] = user_settings.response_time;
            user_settings.night_vision_tab1[10] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode10 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[10] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[10] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode10 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode10 = user_settings.low_blue_light;
        }
        break;
    case 7:
        if (SECOND_TABLE_IN_USE) {
            user_settings.brightness_tab2[7] = user_settings.brightness;
            user_settings.contrast_tab2[7] = user_settings.contrast;
            user_settings.response_time_tab2[7] = user_settings.response_time;
            user_settings.night_vision_tab2[7] = user_settings.night_vision;
            user_settings.blur_free_tab2_mode7 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab2[7] = user_settings.image_enhancement;
            user_settings.sharpness_tab2[7] = user_settings.sharpness;
            user_settings.auto_level_tab2_mode7 = user_settings.auto_level;
            user_settings.low_blue_light_tab2_mode7 = user_settings.low_blue_light;
        }
        else {
            user_settings.brightness_tab1[7] = user_settings.brightness;
            user_settings.contrast_tab1[7] = user_settings.contrast;
            user_settings.response_time_tab1[7] = user_settings.response_time;
            user_settings.night_vision_tab1[7] = user_settings.night_vision;
            user_settings.blur_free_tab1_mode7 = user_settings.blur_free_mode;
            user_settings.image_enhance_tab1[7] = user_settings.image_enhancement;
            user_settings.sharpness_tab1[7] = user_settings.sharpness;
            user_settings.auto_level_tab1_mode7 = user_settings.auto_level;
            user_settings.low_blue_light_tab1_mode7 = user_settings.low_blue_light;
        }
        break;
    }

    /* 3. Mark the settings as changed; osd_run_task_post_redraw_event turns this bit into OSD event 0x80. */
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}

