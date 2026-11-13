/* pq_fga_set_word  (FUN_a012cee4)
 *
 * Store a 16-bit FGA value in the device settings.
 * Name basis: descriptive - bits 8..23 of the word at +0x34
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012cee4 @ 0xa012cee4-0xa012cf10 (44 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: the record word at +0x34 is masked and or-ed as a whole (not a 16-bit bit-field store).
 */

/* The word at +0x34 of the device settings record: fga_selector (+0x34), address (+0x35, 16 bits) and the
   layout byte byte_0x37 of struct fga_location. */
struct device_settings_fga_word {
    unsigned char bytes_0x00[0x34];
    unsigned int fga_word;                  /* +0x34 */
};
extern struct device_settings_fga_word device_settings;

#define FGA_ADDRESS_KEEP  0xff0000ff        /* keep fga_selector and byte_0x37 */
#define FGA_ADDRESS_SHIFT 8                 /* the address sits in bits 8..23 of the word */

/*
 * Store the start address of the FGA block on its storage device (address of struct fga_location, device
 * settings bytes +0x35..+0x36).
 *
 * The only caller is pq_api_set_fga_word, called by ddc_handle_request for FGA command 0x2A.
 */
void pq_fga_set_word(unsigned short address)
{
    device_settings.fga_word = (device_settings.fga_word & FGA_ADDRESS_KEEP) | (address << FGA_ADDRESS_SHIFT);
}
