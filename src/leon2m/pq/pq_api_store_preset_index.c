/* pq_api_store_preset_index  (FUN_a0149130)
 *
 * Store the preset index used for the preset table look-ups.
 * Name basis: descriptive - stSysConfig byte +0x1D, read by pq_get_preset_table_byte; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149130 @ 0xa0149130-0xa014913c (3 words: sethi, retl, the store in the delay slot), flags
 * -mcpu=v8 -O2 -g (section default).
 */
extern unsigned char sys_config_preset_index;

/*
 * Store the preset index (sys_config byte +0x1D) that pq_get_preset_table_byte and _alt use as the row of
 * pq_block8_value_tables. Nothing else is done. Nothing in the firmware calls this routine.
 */
void pq_api_store_preset_index(unsigned char preset_index)
{
    sys_config_preset_index = preset_index;
}
