/* input_csc_setup_with_selector  (FUN_a01016a4)
 *
 * Store the selector and run the colour format set-up.
 * Name basis: derived - word at 0xA8027A78, then input_csc_setup; used by the bring-up state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01016a4 @ 0xa01016a4, flags -mcpu=v8 -O2 -g (section default).
 * The call to input_csc_setup is a tail call (the caller's return address is handed on; the last word is the nop
 * the compiler places behind such a call sequence). The four byte arguments are masked to 8 bits on the way.
 */
extern unsigned int input_csc_selector;
extern void input_csc_setup(unsigned int p1, unsigned char port, unsigned int p3, unsigned char p4);

/*
 * Set input_csc_selector, then run input_csc_setup for the port. input_csc_setup and input_csc_set_format_code
 * test the selector (1, 2 or other) to choose the colour format code.
 *
 *   a, c  passed on as the first and third argument of input_csc_setup, which does not read them
 *   port  input block
 *   m     the selector
 *   d     the last argument of input_csc_setup (the value input_csc_setup takes over as format code for
 *         some signal codes)
 *
 * Called from input_channel_bring_up_task (state 7).
 */
void input_csc_setup_with_selector(unsigned char a, unsigned char port, unsigned int m, unsigned char c, unsigned char d)
{
    input_csc_selector = m;
    input_csc_setup(a, port, c, d);
}
