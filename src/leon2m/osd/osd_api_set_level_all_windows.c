/* osd_api_set_level_all_windows  (FUN_a014a388)
 *
 * Apply a level 0..5 to both menu layers and to their eight windows.
 * Name basis: descriptive - per layer: osd_set_blend_level, osd_set_blend_level_second and, per window,
 *   osd_set_window_blend_level
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a388 @ 0xa014a388-0xa014a428 (40 words), flags -mcpu=v8 -O2 -g.
 * Source form: two copies of the same block, one for layer 0 and one for layer 1 (not a loop over the layers);
 * the window counter is an unsigned char in a do-while loop.
 */
#define WINDOWS_PER_LAYER 8             /* windows 0..7 of a menu layer */
#define BLEND_NONE        0xff          /* level value that makes osd_set_blend_level_second write nothing */

extern void osd_set_blend_level(unsigned char level, unsigned char layer);
extern void osd_set_blend_level_second(unsigned char level, unsigned char layer);
extern void osd_set_window_blend_level(unsigned char level, unsigned char layer);
extern void osd_select_window(unsigned int window, unsigned char layer);

/* Set the level of both menu layers (0 and 1) to `level`: the first level field of the layer, then the level of
 * each of its eight windows. The second level field of the layer is called with BLEND_NONE, so it is left as it
 * is. Called by osd_user_apply_transparency (the menu transparency setting, 0..5) and sys_user_factory_reset. */
void osd_api_set_level_all_windows(unsigned char level)
{
    unsigned char window;

    osd_set_blend_level(level, 0);
    osd_set_blend_level_second(BLEND_NONE, 0);
    window = 0;
    do {
        osd_select_window(window, 0);
        osd_set_window_blend_level(level, 0);
        window++;
    } while (window < WINDOWS_PER_LAYER);
    osd_set_blend_level(level, 1);
    osd_set_blend_level_second(BLEND_NONE, 1);
    window = 0;
    do {
        osd_select_window(window, 1);
        osd_set_window_blend_level(level, 1);
        window++;
    } while (window < WINDOWS_PER_LAYER);
}
