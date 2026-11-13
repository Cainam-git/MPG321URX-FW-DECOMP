/* panel_api_set_blurfree_mode  (FUN_a014bc58)
 *
 * Store the blur-reduction mode and switch the feature off, to GEN1 or to GEN2.
 * Name basis: proven - calls panel_blurfree_set_mode with (0,0), (1,0) or (1,1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014bc58 @ 0xa014bc58, flags -mcpu=v8 -O2 -g.
 * The two GEN2 values are two separate tests, as in the firmware.
 */

extern unsigned int sys_config_blurfree_mode;
extern int panel_blurfree_set_mode(int on, int mode);

/* Blur-reduction modes of the menu setting. */
enum { BLURFREE_MODE_OFF = 0, BLURFREE_MODE_GEN1 = 1, BLURFREE_MODE_GEN2 = 2, BLURFREE_MODE_GEN2_B = 3 };

/*
 * Store the blur-reduction mode and apply it: 0 switches the feature off, 1 selects GEN1, 2 and 3 both
 * select GEN2. Any other value is only stored.
 */
void panel_api_set_blurfree_mode(unsigned int mode)
{
    sys_config_blurfree_mode = mode;

    if (mode == BLURFREE_MODE_OFF) {
        panel_blurfree_set_mode(0, 0);
    } else if (mode == BLURFREE_MODE_GEN1) {
        panel_blurfree_set_mode(1, 0);
    } else {
        if (mode == BLURFREE_MODE_GEN2) {
            panel_blurfree_set_mode(1, 1);
        } else if (mode == BLURFREE_MODE_GEN2_B) {
            panel_blurfree_set_mode(1, 1);
        }
    }
}
