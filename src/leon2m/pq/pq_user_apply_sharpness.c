/* pq_user_apply_sharpness  (FUN_a00d4084)
 *
 * Apply the sharpness setting 0..5.
 * Name basis: derived - item 13 of pq_api_set_window_item with 3 * value; the menu limits the value to 5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4084 @ 0xa00d4084-0xa00d40c4 (64 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: the value is an unsigned short local passed as (unsigned char)sharpness * 3.
 */
struct user_settings_record {
    unsigned char pad0x00[0x49];
    unsigned char sharpness;                    /* +0x49: the Sharpness setting (0..5) */
};
extern struct user_settings_record user_settings;
extern void pq_api_set_window_item(int, int, unsigned char);

#define MAIN_CHANNEL 0                          /* channel 0: the main picture */
#define PICTURE_ITEM_SHARPNESS 0xd              /* picture item 13: sharpness */
#define MAX_SHARPNESS 5                         /* highest allowed sharpness value */

/*
 * Apply the sharpness setting from the user settings record to the picture window.
 * Clamps the value to 0..5, stores it back, and sets picture item 13 (sharpness) to 3 * value.
 * Called from the OSD sharpness sliders and the UART sharpness commands.
 */
void pq_user_apply_sharpness(void)
{
    unsigned short sharpness = user_settings.sharpness;

    if (sharpness > MAX_SHARPNESS)
        sharpness = MAX_SHARPNESS;
    user_settings.sharpness = sharpness;
    pq_api_set_window_item(MAIN_CHANNEL, PICTURE_ITEM_SHARPNESS, (unsigned char)sharpness * 3);
}
