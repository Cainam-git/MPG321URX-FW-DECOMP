/* pq_fga_set_byte  (FUN_a012cf10)
 *
 * Store an FGA byte in the device settings.
 * Name basis: descriptive - byte at 0xA802E1D7
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012cf10 @ 0xa012cf10-0xa012cf1c (12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern byte (the store sits in the retl delay slot).
 */
extern unsigned char device_settings_byte_0x37;

/*
 * Store the FGA layout byte, device settings byte +0x37 (byte_0x37 of struct fga_location). FGA_Init places
 * the marker area 0x120 bytes into the FGA block when it is 0 or 1, 0x240 bytes in when it is above 1.
 *
 * The only caller is pq_api_set_fga_byte, which nothing in the firmware calls.
 */
void pq_fga_set_byte(unsigned char layout)
{
    device_settings_byte_0x37 = layout;
}
