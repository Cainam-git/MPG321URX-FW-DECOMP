/* sys_api_set_config_mask_and_value  (FUN_a014a860)
 *
 * Set bits of configuration byte +0x34, store a 16-bit value at +0x36 and print the byte.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a860 @ 0xa014a860-0xa014a8d4 (29 words), flags -mcpu=v8 -O3 -g (exact at -O3 -g; -O2 -g is not).
 * Source form the exact build depends on: the bit setting is a small static helper that gets the record by pointer
 * (inlined), the caller then writes +0x36 and reads +0x34 through the record's name. The record address is therefore
 * formed once before the test (its low part lands in the delay slot of 'be') and formed again after the join, which
 * the block-reorder pass copies into both arms. Writing the stores through the record's name instead (one form for
 * all accesses) lets the first scheduler move one arm's address into the entry block (67.74 %).
 */
/* System configuration record: the two fields written here. */
struct sys_config_delay_fields {
    unsigned char pad[0x34];
    unsigned char delay_to_show;        /* +0x34: printed as stSysConfig.ucDelayToShow */
    unsigned char pad35;
    unsigned short word_0x36;           /* +0x36 */
};
extern struct sys_config_delay_fields sys_config;
extern int dbg_printf();

#define DELAY_ALL_SLOTS 4       /* slot value that sets all four bits 4..7 */

/* Set the bits of the delay byte: all four high bits for slot 4, else bit slot+4; value is or-ed in. */
static void set_delay_bits(struct sys_config_delay_fields *config, unsigned char slot, unsigned char value)
{
    if (slot == DELAY_ALL_SLOTS)
        config->delay_to_show = value | 0xf0;
    else
        config->delay_to_show = value | (1 << (slot + 4));
}

/*
 * Set bits in byte +0x34 of the system configuration record, store a 16-bit value at +0x36 and print the byte.
 *
 *   slot   0..3 sets bit slot+4, 4 sets bits 4..7
 *   value  low bits or-ed into the byte
 *   word   stored at +0x36
 *
 * Nothing in the firmware calls it.
 */
void sys_api_set_config_mask_and_value(unsigned char slot, unsigned char value, unsigned short word)
{
    set_delay_bits(&sys_config, slot, value);
    sys_config.word_0x36 = word;
    dbg_printf("stSysConfig.ucDelayToShow = %x \r\n", sys_config.delay_to_show);
}
