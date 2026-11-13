/* panel_layer4_set_mode_word  (FUN_a010d8c4)
 *
 * Write one of two mode words of the fourth layer.
 * Name basis: descriptive - 0x40020000 or 0x40000000 to 0xD003210C / 0xD003A10C; unused
 *
 * Matching notes
 * --------------
 * FUN_a010d8c4 (leon2m 0xa010d8c4-0xa010d914, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 */

/* The same word register in the two register sets of the layer (the second set sits 0x8000 higher). */
#define MODE_WORD_FIRST_SET  (*(volatile unsigned int *)0xd003210c)
#define MODE_WORD_SECOND_SET (*(volatile unsigned int *)0xd003a10c)

/*
 * Write the same mode word to both register sets: 0x40020000 when mode is 1, 0x40000000 for any other value.
 * No routine in the image calls it.
 */
void panel_layer4_set_mode_word(unsigned char mode)
{
    if (mode == 1) {
        MODE_WORD_FIRST_SET = 0x40020000;
        MODE_WORD_SECOND_SET = 0x40020000;
    } else {
        MODE_WORD_FIRST_SET = 0x40000000;
        MODE_WORD_SECOND_SET = 0x40000000;
    }
}
