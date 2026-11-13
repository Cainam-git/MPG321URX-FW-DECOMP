/* osd_load_layer_lookup_tables  (FUN_a00a2bdc)
 *
 * Load the start-up lookup table block into both menu layers.
 * Note: Block of 0x1B4 from ROM 0x125770 to layer 0, block of 0x34 from 0x125738 to layer 1
 *   (osd_api_write_block).
 * Name basis: descriptive - records 0xA80241A0 / 0xA80241A8; called first by osd_set_layout
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a2bdc, flags -mcpu=v8 -O2 -g. Called by osd_set_layout (osd_set_layout).
 * Source form: the second call is a tail call. osd_api_write_block copies the 8-byte record {u16, u16, u32} onto
 * its stack and passes it on with the layer number.
 */
extern unsigned short osd_layer0_lookup_block[], osd_layer1_lookup_block[];
extern void osd_api_write_block(unsigned short *, int);

/*
 * Send the lookup table block of each menu layer: the 8-byte record at 0xA80241A8 to layer 0 and the record at
 * 0xA80241A0 to layer 1, both with osd_api_write_block.
 *
 * Called first by osd_set_layout.
 */
void osd_load_layer_lookup_tables(void)
{
    osd_api_write_block(osd_layer0_lookup_block, 0);
    osd_api_write_block(osd_layer1_lookup_block, 1);
}
