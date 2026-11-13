/* pq_apply_picture_mode  (FUN_a014c118)
 *
 * Select the curve and colour set-up for a picture mode and apply it.
 * Name basis: derived - 23-entry switch on the mode; switches the preset curve stages and passes three values
 *   to the colour routine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014c118 @ 0xa014c118-0xa014c778 (408 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - K&R definition (the unsigned char picture_mode is extended at each use);
 *  - each case that gives 0xff is written on its own; the case blocks are in the order 12, 14, 2, 9, 0, 1, 4, 5,
 *    6, 7, 3, 13, 8, 10, 11, 15..22, default (jump table 0xa0143534, 23 entries);
 *  - the part record stores in the order written; case 9 clears apply_gains after its two calls;
 *  - the port status test reads bit 6 as '((status_bits & 0x40) >> 6) == 1', as panel_api_get_brightness_level
 *    and panel_api_set_brightness do;
 *  - red, green and blue are unsigned int, the stored colour a 3-byte array cleared at the start.
 */

/* The fields of the system configuration record (stSysConfig) used here. */
struct sys_config_record {
    unsigned char bytes_0x00[0xc];
    unsigned char red_gain;             /* +0xC, 0..100 */
    unsigned char green_gain;           /* +0xD, 0..100 */
    unsigned char blue_gain;            /* +0xE, 0..100 */
    unsigned char bytes_0x0f[0x18 - 0xf];
    unsigned char gamma_selection;      /* +0x18: low nibble = row bit number, bit 4 = use the FGA data */
    unsigned char byte_0x19;
    unsigned short matrix_row_bit;      /* +0x1A: stored colour matrix row of picture modes 15..22 */
};
struct port_record {
    unsigned short status_bits;
    unsigned char rest[0x28];
};

/*
 * Picture modes (stSysConfig +0xB) with a known source: pq_user_apply_color_settings turns the Color Temperature
 * choices Cool / Normal / Warm / Customization (0..3) into the modes 7 / 4 / 1 / 0x17.
 */
#define PICTURE_MODE_WARM       1       /* part record +6..8, the factory menu row Warm 50 */
#define PICTURE_MODE_NORMAL     4       /* part record +9..0xB, Normal 65 */
#define PICTURE_MODE_COOL       7       /* part record +0x12..0x14, Cool 93 */
#define PICTURE_MODE_CURVES_ON  9       /* only switches the curve stages on */
#define PICTURE_MODE_FGA_FIRST  15      /* modes 15..22 use a stored colour matrix row when FGA data is in use */
#define PICTURE_MODE_FGA_COUNT  7       /* (unsigned char)(mode - 15) <= 7 */
#define PICTURE_MODE_CUSTOM     0x17    /* and any mode above 22: the gains of stSysConfig */

/* Columns of the stored colour block (as FGA_COLOR_KEYS in FGA_Init). */
#define FGA_COLUMN_WARM50       0x02
#define FGA_COLUMN_NORMAL65     0x10
#define FGA_COLUMN_COOL93       0x80

#define FGA_IN_USE_BIT          4       /* bit of gamma_selection tested by pq_is_fga_bit4_set */
#define FGA_ROW_NUMBER_MASK     0x0f

#define GAIN_FULL               0xff
#define PORT_STATUS_BIT6        0x40
#define CHANNEL_PORT(word0)     (((word0) >> 12) & 0xf)     /* port of a channel: bits 12..15 of its first word */

/* A custom gain 0..100 as a colour value 55..255 (rounded). */
#define GAIN_TO_VALUE(gain)     (((gain) * 200u + 50) / 100 + 0x37)

extern struct sys_config_record sys_config;
extern unsigned char part_record[];
extern struct port_record port_records[];
extern unsigned int channel_records;            /* first word of channel record 0 */
extern unsigned char pq_is_fga_bit4_set(unsigned char);
extern unsigned char pq_fga_read_color_entry(unsigned short, unsigned short, unsigned char *);
extern unsigned char pq_gamma_is_first_curve_stage_enabled(void);
extern unsigned char pq_gamma_is_second_curve_stage_enabled(void);
extern void pq_gamma_disable_first_curve_stage(void);
extern void pq_gamma_disable_second_curve_stage(void);
extern void pq_gamma_load_first_curve_preset2(unsigned char *);
extern void pq_gamma_load_second_curve_preset2(unsigned char *);
extern void pq_gamma_enable_first_curve_stage(void);
extern void pq_gamma_enable_second_curve_stage(void);
extern unsigned char pq_mode_to_color_row_bit(unsigned char);
extern void pq_fga_load_color_matrix_row(unsigned short);
extern unsigned char input_port_get_status_bit9(unsigned char);
extern void pq_color_matrix_set_gains(unsigned short, unsigned short, unsigned short);

/*
 * Apply a picture mode: set the two preset-curve stages and the three colour gains of the mode.
 *
 *   picture_mode  the mode, as stored in stSysConfig +0xB
 *
 * Called by pq_api_set_picture_mode and command 20 of sys_api_config (a new mode); by pq_api_set_gamma_and_reapply
 * and command 23 of sys_api_config (the stored mode after a new gamma selection); and by
 * pq_api_set_mode_color_value when a changed colour value belongs to the current mode.
 *
 * Phases:
 *   1. Curve stages: for modes 15..22 with FGA data in use (bit 4 of gamma_selection), load preset 2 into both
 *      stages and switch them on, unless both are already on; for every other case switch both stages off.
 *   2. Modes 15..22: store the mode's colour matrix row bit in stSysConfig +0x1A.
 *   3. The gains of the mode (0xff each when the mode has none):
 *      - Warm / Normal / Cool: with FGA data in use, the triple stored in the FGA block for the row of
 *        gamma_selection and the mode's column, when that read succeeds; else the part record triple, which is
 *        first reset to a default when one of its values is below a lower limit (see each case);
 *      - modes 5, 6, 8: the part record triple, with the same reset; modes 10, 11: the part record triple;
 *      - mode 9: switch both curve stages on, no gains;
 *      - modes 15..22: with FGA data in use, program the stored colour matrix row instead of gains; else 0xff,
 *        and for mode 15 the part record triple at +0x21;
 *      - above 22: the custom gains of stSysConfig.
 *   4. When the port of channel 0 has status bit 9, or status bit 6, the custom gains replace all of the above.
 *   5. Hand gain + 1 of each colour to pq_color_matrix_set_gains, unless phase 3 did something else.
 */
void pq_apply_picture_mode(picture_mode)
    unsigned char picture_mode;
{
    unsigned char stored_color[3] = {0, 0, 0};
    unsigned int red, green, blue;
    unsigned char apply_gains;

    red = 0xff;
    green = 0xff;
    blue = 0xff;
    apply_gains = 1;

    /* Phase 1: the preset-curve stages. */
    if (pq_is_fga_bit4_set(sys_config.gamma_selection) != 0 && (unsigned char)(picture_mode - PICTURE_MODE_FGA_FIRST) <= PICTURE_MODE_FGA_COUNT) {
        if (pq_gamma_is_first_curve_stage_enabled() == 0 || pq_gamma_is_second_curve_stage_enabled() == 0) {
            pq_gamma_disable_first_curve_stage();
            pq_gamma_disable_second_curve_stage();
            pq_gamma_load_first_curve_preset2(0);
            pq_gamma_load_second_curve_preset2(0);
            pq_gamma_enable_first_curve_stage();
            pq_gamma_enable_second_curve_stage();
        }
    } else {
        pq_gamma_disable_first_curve_stage();
        pq_gamma_disable_second_curve_stage();
    }

    /* Phase 2. */
    if ((unsigned char)(picture_mode - PICTURE_MODE_FGA_FIRST) <= PICTURE_MODE_FGA_COUNT)
        sys_config.matrix_row_bit = pq_mode_to_color_row_bit(picture_mode);

    /* Phase 3: the gains of the mode. */
    switch (picture_mode) {
    case 12:
        red = 0xff;
        green = 0xff;
        blue = 0xff;
        break;
    case 14:
        red = 0xff;
        green = 0xff;
        blue = 0xff;
        break;
    case 2:
        red = 0xff;
        green = 0xff;
        blue = 0xff;
        break;
    case PICTURE_MODE_CURVES_ON:
        pq_gamma_enable_first_curve_stage();
        pq_gamma_enable_second_curve_stage();
        apply_gains = 0;
        break;
    case 0:
        red = 0xff;
        green = 0xff;
        blue = 0xff;
        break;
    case PICTURE_MODE_WARM:
        if (pq_is_fga_bit4_set(sys_config.gamma_selection) && pq_fga_read_color_entry(1 << (sys_config.gamma_selection & 0xf), FGA_COLUMN_WARM50, stored_color)) {
            red = stored_color[0];
            green = stored_color[1];
            blue = stored_color[2];
        } else {
            /* Reset to ff e8 bd when red <= 0x7e, green <= 0x73, or blue is 0 or 0xff. */
            if (part_record[6] <= 0x7e || part_record[7] <= 0x73 || part_record[8] == 0 || part_record[8] == 0xff) {
                part_record[6] = 0xff;
                part_record[7] = 0xe8;
                part_record[8] = 0xbd;
            }
            red = part_record[6];
            green = part_record[7];
            blue = part_record[8];
        }
        break;
    case PICTURE_MODE_NORMAL:
        if (pq_is_fga_bit4_set(sys_config.gamma_selection) && pq_fga_read_color_entry(1 << (sys_config.gamma_selection & 0xf), FGA_COLUMN_NORMAL65, stored_color)) {
            red = stored_color[0];
            green = stored_color[1];
            blue = stored_color[2];
        } else {
            /* Reset to ff ff ff when any value is <= 0x7e. */
            if (part_record[9] <= 0x7e || part_record[0xa] <= 0x7e || part_record[0xb] <= 0x7e) {
                part_record[9] = 0xff;
                part_record[0xa] = 0xff;
                part_record[0xb] = 0xff;
            }
            red = part_record[9];
            green = part_record[0xa];
            blue = part_record[0xb];
        }
        break;
    case 5:
        /* Reset to f8 ff ff when red <= 0x7b, green or blue <= 0x7e. */
        if (part_record[0xc] <= 0x7b || part_record[0xd] <= 0x7e || part_record[0xe] <= 0x7e) {
            part_record[0xc] = 0xf8;
            part_record[0xd] = 0xff;
            part_record[0xe] = 0xff;
        }
        red = part_record[0xc];
        green = part_record[0xd];
        blue = part_record[0xe];
        break;
    case 6:
        /* Reset to f8 f8 ff when red or green <= 0x7b, blue <= 0x7e. */
        if (part_record[0xf] <= 0x7b || part_record[0x10] <= 0x7b || part_record[0x11] <= 0x7e) {
            part_record[0xf] = 0xf8;
            part_record[0x10] = 0xf8;
            part_record[0x11] = 0xff;
        }
        red = part_record[0xf];
        green = part_record[0x10];
        blue = part_record[0x11];
        break;
    case PICTURE_MODE_COOL:
        if (pq_is_fga_bit4_set(sys_config.gamma_selection) && pq_fga_read_color_entry(1 << (sys_config.gamma_selection & 0xf), FGA_COLUMN_COOL93, stored_color)) {
            red = stored_color[0];
            green = stored_color[1];
            blue = stored_color[2];
        } else {
            /* Reset to d1 d6 ff when red <= 0x67, green <= 0x6a or blue <= 0x7e. */
            if (part_record[0x12] <= 0x67 || part_record[0x13] <= 0x6a || part_record[0x14] <= 0x7e) {
                part_record[0x12] = 0xd1;
                part_record[0x13] = 0xd6;
                part_record[0x14] = 0xff;
            }
            red = part_record[0x12];
            green = part_record[0x13];
            blue = part_record[0x14];
        }
        break;
    case 3:
        red = 0xff;
        green = 0xff;
        blue = 0xff;
        break;
    case 13:
        red = 0xff;
        green = 0xff;
        blue = 0xff;
        break;
    case 8:
        /* Reset to f0 f0 ff when red or green <= 0x77, blue <= 0x7e. */
        if (part_record[0x15] <= 0x77 || part_record[0x16] <= 0x77 || part_record[0x17] <= 0x7e) {
            part_record[0x15] = 0xf0;
            part_record[0x16] = 0xf0;
            part_record[0x17] = 0xff;
        }
        red = part_record[0x15];
        green = part_record[0x16];
        blue = part_record[0x17];
        break;
    case 10:
        red = part_record[0x1b];
        green = part_record[0x1c];
        blue = part_record[0x1d];
        break;
    case 11:
        red = part_record[0x1e];
        green = part_record[0x1f];
        blue = part_record[0x20];
        break;
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
        if (pq_is_fga_bit4_set(sys_config.gamma_selection)) {
            /* The stored row is programmed as the colour matrix; no gains. */
            pq_fga_load_color_matrix_row(sys_config.matrix_row_bit);
            apply_gains = 0;
        } else {
            red = 0xff;
            green = 0xff;
            blue = 0xff;
            if (picture_mode == 15) {
                red = part_record[0x21];
                green = part_record[0x22];
                blue = part_record[0x23];
            }
        }
        break;
    default:
        /* PICTURE_MODE_CUSTOM and every mode above 22. */
        red = GAIN_TO_VALUE(sys_config.red_gain);
        green = GAIN_TO_VALUE(sys_config.green_gain);
        blue = GAIN_TO_VALUE(sys_config.blue_gain);
        break;
    }

    /* Phase 4: these port states always take the custom gains. */
    if (input_port_get_status_bit9(CHANNEL_PORT(channel_records)) == 1 || ((port_records[CHANNEL_PORT(channel_records)].status_bits & PORT_STATUS_BIT6) >> 6) == 1) {
        red = GAIN_TO_VALUE(sys_config.red_gain);
        green = GAIN_TO_VALUE(sys_config.green_gain);
        blue = GAIN_TO_VALUE(sys_config.blue_gain);
    }

    /* Phase 5. */
    if (apply_gains)
        pq_color_matrix_set_gains(red + 1, green + 1, blue + 1);
}
