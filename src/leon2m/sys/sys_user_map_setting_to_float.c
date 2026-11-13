/* sys_user_map_setting_to_float  (FUN_a00d3d30)
 *
 * Map a setting byte to an output value in floating point.
 * Name basis: descriptive - neighbour of APP_ConfigDispSize; unused
 *
 * Matching notes
 * --------------
 * FUN_a00d3d30: maps the byte setting user_settings_contrast to an output value through float math:
 *   v > 70: (v - 70) * 22 / 30 + 128, else v * 100 / 70 + 28 (truncated to unsigned char).
 * Real neighbour in the same source unit as APP_ConfigDispSize (APP_ConfigDispSize); its six float
 * constants are the first .rodata.cst4 entries at 0x198748. Flags: -mcpu=v8 -O3 -g -msoft-float.
 */
extern unsigned char user_settings_contrast;

#define CONTRAST_KNEE 70                /* below and above this value the mapping has another slope */

/*
 * Map the Contrast setting (settings byte +0xA) to an output value, in floating point:
 * above 70 it is (contrast - 70) * 22 / 30 + 128, otherwise contrast * 100 / 70 + 28; the result is truncated to
 * an unsigned char. Nothing calls it.
 */
unsigned char sys_user_map_setting_to_float(void)
{
    unsigned char contrast = user_settings_contrast;
    float mapped;
    if (contrast > CONTRAST_KNEE)
        mapped = (float)(contrast - CONTRAST_KNEE) * 22.0f / 30.0f + 128.0f;
    else
        mapped = (float)(int)contrast * 100.0f / 70.0f + 28.0f;
    return mapped;
}
