/* pq_api_set_fga_word  (FUN_a0149210)
 *
 * Store a 16-bit value in bits 8..23 of the device settings word at +0x34 (bytes +0x35 and +0x36).
 *   address: the 16-bit value to store
 * Name basis: descriptive - tail call to pq_fga_set_word, which replaces bits 8..23 of the word at +0x34;
 *   called from the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149210 @ 0xa0149210-0xa0149228 (6 words), flags -mcpu=v8 -O2 -g (section default).
 * The call is a tail call; the last word is the nop the compiler places behind it.
 */
extern void pq_fga_set_word(unsigned short);

/*
 * Store a 16-bit FGA value in bits 8..23 of the device settings word at +0x34 (bytes +0x35 and +0x36, the
 * FGA address of struct fga_location), through pq_fga_set_word.
 * The only caller, ddc_handle_request, passes request byte 5 * 800 + 0x500 for FGA command 0x2A.
 */
void pq_api_set_fga_word(unsigned short address)
{
    pq_fga_set_word(address);
}
