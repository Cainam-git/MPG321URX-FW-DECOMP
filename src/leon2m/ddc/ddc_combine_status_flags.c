/* ddc_combine_status_flags  (FUN_a00cf23c)
 *
 * Return the OR of the flag halfwords of the three status entries.
 * Returns: combined flags
 * Note: Uncalled; the VCP 0xE1 reply sends the same value.
 * Name basis: descriptive - same computation inside the 0xE1 arm of ddc_apply_maker_vcp_set
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g. Nothing in the image calls this routine.
 * Source form: an unsigned char loop counter; the entry is declared with halfword fields.
 */
#define DDC_STATUS_ENTRY_COUNT 3

/* One of the three DDC/CI status entries (docs/DATA.md, ddc_status_entries): value and key bytes, then flags. */
struct ddc_status_entry {
    unsigned short value_and_key;
    unsigned short flags;
};
extern struct ddc_status_entry ddc_status_entries[];

/*
 * Return the OR of the flags of the three status entries. ddc_apply_maker_vcp_set forms the same value inline for
 * its reply to the factory switch E1 A2 01.
 */
unsigned short ddc_combine_status_flags(void)
{
    unsigned short combined = 0;
    unsigned char i;

    for (i = 0; i < DDC_STATUS_ENTRY_COUNT; i++)
        combined |= ddc_status_entries[i].flags;
    return combined;
}
