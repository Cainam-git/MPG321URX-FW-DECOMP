/* input_set_bring_up_limits  (FUN_a00ef034)
 *
 * Store two limit values of the bring-up code.
 * Name basis: descriptive - halfwords at 0xA802B74C / 0xA802B74E; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ef034 @ 0xa00ef034, flags -mcpu=v8 -O2 -g (section default).
 */

extern unsigned short input_bring_up_hactive;
extern unsigned short input_bring_up_vactive;

/*
 * Store the two values that input_bring_up_set_pixel_clock reads as input_bring_up_hactive and
 * input_bring_up_vactive. No code calls this routine.
 */
void input_set_bring_up_limits(unsigned short hactive, unsigned short vactive)
{
    input_bring_up_hactive = hactive;
    input_bring_up_vactive = vactive;
}
