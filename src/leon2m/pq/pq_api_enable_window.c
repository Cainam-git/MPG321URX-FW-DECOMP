/* pq_api_enable_window  (FUN_a0146fdc)
 *
 * Switch picture window 0..3 on or off.
 * Name basis: derived - set / clear of the window enable bits; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146fdc @ 0xa0146fdc-0xa014705c (32 words), flags -mcpu=v8 -O2 -g (section default).
 * Source form: the window starts as 4 at its declaration and a switch has cases 0..3 only (a default arm gives
 * another layout); both calls are tail calls.
 */
extern void pq_window_disable(int window);
extern void pq_window_enable(unsigned int window);

#define WINDOW_NONE 4       /* the window number used for any value above 3 */

/*
 * Switch picture window 0..3 on (on = 1, pq_window_enable) or off (any other value, pq_window_disable).
 * A window number above 3 becomes 4, and 4 & 7 is passed on. Nothing in the firmware calls this routine;
 * pq_api_enable_channel_window does the same for the window of a channel.
 */
void pq_api_enable_window(unsigned char window_number, unsigned char on)
{
    unsigned char window = WINDOW_NONE;

    switch (window_number) {
    case 0:
        window = 0;
        break;
    case 1:
        window = 1;
        break;
    case 2:
        window = 2;
        break;
    case 3:
        window = 3;
        break;
    }
    if (on == 1)
        pq_window_enable(window & 7);
    else
        pq_window_disable(window & 7);
}
