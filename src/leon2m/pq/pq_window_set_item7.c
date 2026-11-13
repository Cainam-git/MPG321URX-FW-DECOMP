/* pq_window_set_item7  (FUN_a00f6f7c)
 *
 * Write picture item 7 of the selected picture window.
 * Name basis: descriptive - value unchanged, to register 0xCF00EF20; item number as in pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6f7c @ 0xa00f6f7c-0xa00f6f94 (24 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default;
 * -O3 -g and -Os -g give the same bytes).
 * Source form: a volatile register store of an unsigned char parameter (and 0xff; the store stays before retl).
 */
/* The register that holds picture item 7 of the selected picture window. */
#define PICTURE_ITEM7_REGISTER (*(volatile unsigned int *)0xcf00ef20)

/*
 * Set picture item 7 of the selected picture window to item_value: the byte goes straight to the word
 * register at 0xCF00EF20 (items 6..8 do not go through pq_window_item_hook).
 *
 * Only caller: pq_api_set_window_item (item 7).
 */
void pq_window_set_item7(unsigned char item_value)
{
    PICTURE_ITEM7_REGISTER = item_value;
}
