/* pq_fga_set_selector  (FUN_a012ced8)
 *
 * Store the FGA selector byte.
 * Name basis: descriptive - byte at 0xA802E1D4 of the device settings
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012ced8 @ 0xa012ced8, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern byte.
 */
extern unsigned char device_settings_fga_storage_device;

/*
 * Store the FGA selector, device settings byte +0x34 (fga_selector of struct fga_location): the storage
 * device that FGA_Init and the FGA routines read and write the FGA block on.
 *
 * The only caller is pq_api_set_fga_selector, which nothing in the firmware calls.
 */
void pq_fga_set_selector(unsigned char selector)
{
  device_settings_fga_storage_device = selector;
}
