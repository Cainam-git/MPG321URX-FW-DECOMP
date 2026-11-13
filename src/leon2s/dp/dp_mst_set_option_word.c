/* dp_mst_set_option_word  (FUN_a00d66b0)
 *
 * Store the MST option value received from the main processor.
 * Name basis: descriptive - byte at 0xA80760AC
 *
 * Matching notes
 * --------------
 * FUN_a00d66b0 (leon2s 0xa00d66b0-0xa00d66bc, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 */
extern unsigned char dp_mst_option_word;

/* Store `value` in the byte dp_mst_option_word (0xA80760AC). */
void dp_mst_set_option_word(unsigned char value)
{
    dp_mst_option_word = value;
}
