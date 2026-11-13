/* panel_layer_set_stream_mode  (FUN_a010ebd0)
 *
 * Write the mode word chosen by two selectors to the stream registers of both halves.
 * Name basis: descriptive - registers 0xD0030420 and 0xD0038420; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010ebd0 @ 0xa010ebd0-0xa010ec70 (40 words), flags -mcpu=v8 -O3 -g. Both addresses are hardware
 * registers, hence volatile.
 * Source form: the first register is accessed through a pointer local (the firmware keeps its address in a
 * register from the read to the write); its value is read and replaced before use.
 */
#define STREAM_MODE_SECOND_SET (*(volatile unsigned int *)0xd0038420)

/*
 * Write a mode word to the stream register 0x420 of both register sets (0xD0030420 and 0xD0038420). The word is
 * chosen by two selectors, each with its own table of three words:
 *
 *   second selector 0: first selector 0 -> 0x13200000, 1 -> 0x13020000, 2 -> 0x10320000
 *   second selector 1: first selector 0 -> 0x03210000, 1 -> 0x03120000, 2 -> 0x01320000
 *
 * Any other value of either selector: nothing is written. No routine calls it directly.
 */
void panel_layer_set_stream_mode(unsigned char first_selector, unsigned char second_selector)
{
    volatile unsigned int *first_set = (volatile unsigned int *)0xd0030420;
    unsigned int mode_word;

    mode_word = *first_set;
    if (second_selector == 0) {
        switch (first_selector) {
        case 0:
            mode_word = 0x13200000;
            break;
        case 1:
            mode_word = 0x13020000;
            break;
        case 2:
            mode_word = 0x10320000;
            break;
        default:
            return;
        }
    } else if (second_selector == 1) {
        switch (first_selector) {
        case 0:
            mode_word = 0x03210000;
            break;
        case 1:
            mode_word = 0x03120000;
            break;
        case 2:
            mode_word = 0x01320000;
            break;
        default:
            return;
        }
    } else
        return;
    *first_set = mode_word;
    STREAM_MODE_SECOND_SET = mode_word;
}
