/* input_block_get_config_word  (FUN_a01215c8)
 *
 * Return the first word of an input block's configuration.
 * Returns: word
 * Name basis: descriptive - table at 0xA8027AAC; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01215c8 @ 0xa01215c8, flags -mcpu=v8 -O3 -g.
 */
struct input_block_config { unsigned int word_0, word_4, word_8; };
extern struct input_block_config input_block_configs[];

/*
 * Return word 0 of entry blk of input_block_configs.
 *
 * No routine in the image calls it.
 */
unsigned int input_block_get_config_word(unsigned char blk)
{
    return input_block_configs[blk].word_0;
}
