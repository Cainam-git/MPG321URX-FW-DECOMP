/* input_get_port_status_word  (FUN_a0129b38)
 *
 * Return the first port status word.
 * Returns: word
 * Name basis: descriptive - halfword at 0xA802C9FE; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129b38 @ 0xa0129b38, flags -mcpu=v8 -O2 -g. Direct read of the extern halfword.
 */
extern unsigned short port_present_mask;

/*
 * Return port_present_mask.
 */
unsigned short input_get_port_status_word(void)
{
    return port_present_mask;
}
