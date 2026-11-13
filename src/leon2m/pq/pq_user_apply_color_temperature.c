/* pq_user_apply_color_temperature  (FUN_a00d94fc)
 *
 * Apply the three colour values of the chosen colour temperature.
 * Name basis: derived - three values by settings byte +0x11: stored colour entries or the custom values
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d94fc @ 0xa00d94fc-0xa00d972c (75 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - main_port_flag_test() is a static helper with one return per case (inlined);
 *  - the scaling uses unsigned arithmetic (200U) as the firmware divides with umul;
 *  - the blue scale is a double constant, so the multiplication is done in double (soft-float calls
 *    __floatsidf, __muldf3, __fixunsdfsi in the build).
 */

#define PROFESSIONAL_FLAGS_LOW_BLUE_LIGHT 0x10 /* professional_flags bit 4: Low Blue Light switch */
#define COLOR_TEMPERATURE_BLUE_SCALE      0.81 /* the blue value is scaled down by this */

/* Map a custom gain (0..100) to a colour value: (g * 200 + 50) / 100 + 55. */
#define GAIN_TO_VALUE(x) (((x) * 200U + 50) / 100 + 55)

struct user_settings_record {
    unsigned char pad0[0x11];
    unsigned char color_temperature;    /* +0x11: the Color Temperature choice */
    unsigned char red_gain;             /* +0x12: the custom red gain */
    unsigned char green_gain;           /* +0x13: the custom green gain */
    unsigned char blue_gain;            /* +0x14: the custom blue gain */
    unsigned char pad15[0x11c - 0x15];
    unsigned int professional_flags;    /* +0x11C */
};
extern struct user_settings_record user_settings;
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);
extern unsigned char pq_api_get_mode_color_value(unsigned char);
extern void pq_api_set_color_triple(unsigned short a, unsigned short b, unsigned short c);

/* True when the port of channel 0 has flag bit 9 set, or has flag bit 6 set while the mailbox status field
   reads 1..4 (ipc_api_get_status_field gives 4 for a value outside 0..3). */
static int main_port_flag_test(void)
{
    if (sys_api_get_channel_port_flag9(0) == 1)
        return 1;
    if (sys_api_get_channel_port_flag6(0) == 1) {
        switch (ipc_api_get_status_field()) {
        case 1: return 1;
        case 2: return 1;
        case 3: return 1;
        case 4: return 1;
        }
    }
    return 0;
}

/*
 * Apply the three colour values of the chosen colour temperature.
 *
 * Acts only when the Low Blue Light switch (bit 4 of the professional flags) is on; returns at
 * once when it is off or when main_port_flag_test() is true. The Color Temperature choice
 * (settings byte +0x11) selects the red, green and blue values:
 *   - choice 3 (Customization): the custom gains +0x12..+0x14, each through GAIN_TO_VALUE;
 *   - the other choices: three consecutive colour values read with pq_api_get_mode_color_value,
 *     ids 0x12..0x14 for 0 (Cool), 6..8 for 2 (Warm), 0xC..0xE for 5, 0xF..0x11 for 6,
 *     0x15..0x17 for 7, and 9..0xB for 1 (Normal), 4 and every other choice.
 * The blue value is then multiplied by COLOR_TEMPERATURE_BLUE_SCALE (0.81), and the three values,
 * each plus one, go to pq_api_set_color_triple, which stores them and rebuilds the colour matrix.
 *
 * Callers: pq_user_set_custom_blue, pq_user_apply_color_settings, sys_user_reset_settings_keep_source,
 * sys_user_factory_reset.
 */
void pq_user_apply_color_temperature(void)
{
    unsigned char red, green, blue;

    if (main_port_flag_test())
        return;
    if (!(user_settings.professional_flags & PROFESSIONAL_FLAGS_LOW_BLUE_LIGHT))
        return;
    switch (user_settings.color_temperature) {
    case 0:
        red = pq_api_get_mode_color_value(0x12); green = pq_api_get_mode_color_value(0x13); blue = pq_api_get_mode_color_value(0x14);
        break;
    case 2:
        red = pq_api_get_mode_color_value(6); green = pq_api_get_mode_color_value(7); blue = pq_api_get_mode_color_value(8);
        break;
    case 3:
        /* The custom Red, Green and Blue gains. */
        red = GAIN_TO_VALUE(user_settings.red_gain);
        green = GAIN_TO_VALUE(user_settings.green_gain);
        blue = GAIN_TO_VALUE(user_settings.blue_gain);
        break;
    case 5:
        red = pq_api_get_mode_color_value(0xc); green = pq_api_get_mode_color_value(0xd); blue = pq_api_get_mode_color_value(0xe);
        break;
    case 6:
        red = pq_api_get_mode_color_value(0xf); green = pq_api_get_mode_color_value(0x10); blue = pq_api_get_mode_color_value(0x11);
        break;
    case 7:
        red = pq_api_get_mode_color_value(0x15); green = pq_api_get_mode_color_value(0x16); blue = pq_api_get_mode_color_value(0x17);
        break;
    case 1:
    case 4:
    default:
        red = pq_api_get_mode_color_value(9); green = pq_api_get_mode_color_value(10); blue = pq_api_get_mode_color_value(11);
        break;
    }
    blue = blue * COLOR_TEMPERATURE_BLUE_SCALE;
    pq_api_set_color_triple(red + 1, green + 1, blue + 1);
}
