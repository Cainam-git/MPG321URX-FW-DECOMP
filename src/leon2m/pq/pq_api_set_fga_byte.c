/* pq_api_set_fga_byte  (FUN_a0149228)
 *
 * Store one byte in the device record field at +0x37.
 * Name basis: descriptive - tail call to the field setter; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149228 @ 0xa0149228-0xa014923c (5 words), flags -mcpu=v8 -O2 -g (section default).
 * The call is a tail call; the last word is the nop the compiler places behind it.
 */
extern void pq_fga_set_byte(unsigned char);

/*
 * Store the device settings byte +0x37 (the FGA layout byte of struct fga_location) through pq_fga_set_byte.
 * Nothing in the firmware calls this routine.
 */
void pq_api_set_fga_byte(unsigned char layout)
{
    pq_fga_set_byte(layout);
}
