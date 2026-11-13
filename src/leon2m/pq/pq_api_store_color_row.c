/* pq_api_store_color_row  (FUN_a014923c)
 *
 * Copy an 18-byte colour row into the selected slot and save it.
 * Name basis: descriptive - tail call to the row copy with EEPROM block access; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014923c @ 0xa014923c-0xa0149254 (6 words), flags -mcpu=v8 -O2 -g (section default).
 * The call is a tail call; the last word is the nop the compiler places behind it.
 */
extern void pq_fga_store_color_row(unsigned char, unsigned char *, unsigned char);

/*
 * Pass an 18-byte FGA colour row on to pq_fga_store_color_row.
 *
 *   mode   the picture mode that picks the slot of the row
 *   row    the 18 bytes to store
 *   flags  bit 0: read the stored colour rows first; bit 2: write them back to storage
 *
 * Nothing in the firmware calls this routine.
 */
void pq_api_store_color_row(unsigned char mode, unsigned char * row, unsigned char flags)
{
    pq_fga_store_color_row(mode, row, flags);
}
