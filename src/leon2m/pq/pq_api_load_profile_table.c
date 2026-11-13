/* pq_api_load_profile_table  (FUN_a014dc18)
 *
 * Load the built-in 1024-entry profile table into the picture hardware.
 * Name basis: proven - forwards to the routine that prints 'Profile_Load_Table'; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014dc18 @ 0xa014dc18-0xa014dc28 (4 words), flags -mcpu=v8 -O2 -g (section default).
 * The call is a tail call; the last word is the nop the compiler places behind it.
 */
extern void pq_load_profile_table(void);

/* Load the built-in profile table (pq_load_profile_table). Nothing in the firmware calls this routine. */
void pq_api_load_profile_table(void)
{
    pq_load_profile_table();
}
