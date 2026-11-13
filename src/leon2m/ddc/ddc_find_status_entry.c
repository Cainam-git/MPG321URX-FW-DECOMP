/* ddc_find_status_entry  (FUN_a00cf1ec)
 *
 * Return the value byte of the status entry whose key byte matches.
 *   key
 * Returns: value, or 0
 * Note: Uncalled; three 4-byte entries (ddc_status_entries); ddc_apply_maker_vcp_set reads only their flag
 *   halfwords.
 * Name basis: descriptive - loop over the three entries of ddc_status_entries: key byte compared, value byte
 *   returned
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default). Nothing in the image calls this routine.
 * Source form: an unsigned char loop counter; the entry is declared with byte fields.
 */
#define DDC_STATUS_ENTRY_COUNT 3

/* One of the three DDC/CI status entries (docs/DATA.md, ddc_status_entries). */
struct ddc_status_entry {
    unsigned char value;
    unsigned char key;
    unsigned short flags;       /* ORed together by ddc_combine_status_flags */
};
extern struct ddc_status_entry ddc_status_entries[];

/*
 * Return the value byte of the first status entry whose key byte is `key`, or 0 when none matches.
 * ddc_apply_maker_vcp_set reads only the flags of these entries (see ddc_combine_status_flags), not the key and value
 * bytes.
 */
unsigned char ddc_find_status_entry(unsigned char key)
{
    unsigned char i;

    for (i = 0; i < DDC_STATUS_ENTRY_COUNT; i++)
        if (ddc_status_entries[i].key == key)
            return ddc_status_entries[i].value;
    return 0;
}
