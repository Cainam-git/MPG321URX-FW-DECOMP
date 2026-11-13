/* input_mode_list_has_entry  (FUN_a013f224)
 *
 * Return whether the short mode list holds an entry {0xC, k}.
 * Returns: 0 or 1
 * Name basis: descriptive - first 13 entries of the ROM list at 0x1A59E2; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013f224 @ 0xa013f224-0xa013f284, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Nothing in the image refers to it (no call, branch or address constant).
 */

/* One entry of the short mode list: a one-byte kind and a mode id. */
struct short_mode_entry { unsigned char kind; unsigned char byte_1; unsigned short mode_id; };
extern const struct short_mode_entry input_short_mode_list[];

#define SHORT_MODE_LIST_LENGTH 13       /* entries at 0x1A59E2 */
#define SHORT_MODE_KIND_EXCLUDED 0xc    /* the kind input_match_port_mode skips */

/*
 * Return 1 when one of the 13 entries of the short mode list has kind 0xC and the mode id mode_id.
 *
 * input_match_port_mode skips every mode-table row whose id (halfword +0x22) is listed with kind 0xC. Nothing in
 * the image calls this routine.
 */
int input_mode_list_has_entry(unsigned short mode_id)
{
    unsigned char i;

    for (i = 0; i < SHORT_MODE_LIST_LENGTH; i++)
        if (input_short_mode_list[i].kind == SHORT_MODE_KIND_EXCLUDED && input_short_mode_list[i].mode_id == mode_id)
            return 1;
    return 0;
}
