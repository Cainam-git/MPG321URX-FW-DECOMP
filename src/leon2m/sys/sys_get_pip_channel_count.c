/* sys_get_pip_channel_count  (FUN_a012f3ec)
 *
 * Return the number of pictures shown in the current picture-in-picture mode.
 * Returns: 1..4
 * Name basis: descriptive - PIP mode 0..7 mapped to 1, 2, 2, 3, 4, 2, 3, 4; unused
 *
 * Matching notes
 * --------------
 * FUN_a012f3ec (leon2m 0xa012f3ec-0xa012f43c, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with a jump table (8 words at 0xa012f14c, run-time address 0xcf14c); case order default,
 * 0, 4/7, 3/6, 1/2/5 gives the firmware block order; return count & 7.
 */
extern unsigned char device_settings_pip_mode;

/*
 * Return how many pictures the current picture-in-picture / picture-by-picture mode
 * (device_settings_pip_mode) shows: mode 0 -> 1, modes 1, 2, 5 -> 2, modes 3, 6 -> 3, modes 4, 7 -> 4;
 * a value above 7 gives 1. Not called by name anywhere in the source.
 */
unsigned char sys_get_pip_channel_count(void)
{
    unsigned char count;

    switch (device_settings_pip_mode) {
    default:
        count = 1;
        break;
    case 0:
        count = 1;
        break;
    case 4:
    case 7:
        count = 4;
        break;
    case 3:
    case 6:
        count = 3;
        break;
    case 1:
    case 2:
    case 5:
        count = 2;
        break;
    }
    return count & 7;
}
