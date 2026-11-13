/* hdcp_rx_hdmi21_load_keys  (FUN_a00c0dfc)
 *
 * Load the key-selection value and the key block into an HDMI 2.1 input.
 * Name basis: derived - 5 bytes to registers 0x1A..0x1E, 0x11A bytes through registers 0xA1 / 0xA2
 *
 * Matching notes
 * --------------
 * FUN_a00c0dfc (leon2s 0xa00c0dfc-0xa00c0ecc, 208 bytes), flags -mcpu=v8 -Os -g.
 * Source form: unsigned short loop counter. The register of the 0xA0 read is read and its result dropped.
 */
extern void hdmi_rx21_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned int hdmi_rx21_reg_read8(unsigned char, unsigned short);
extern void hdmi_rx21_reg_write8(unsigned char, unsigned short, unsigned char);

#define KSV_LENGTH       5                      /* bytes of the key-selection value */
#define KEY_BLOCK_LENGTH 0x11a                  /* bytes of the key block */

/*
 * Load a key set into HDMI 2.1 receiver `port` (0 or 1) through its register helpers.
 *
 * First bit 3 of register 0x40 is set. The key-selection value goes to registers 0x1A..0x1E. After a read of
 * register 0xA0 (result dropped) 0xE0 is written to it. Then every byte of the key block is written with
 * its index: low byte to register 0xA1, high byte to 0xA2, the byte itself to 0xA3.
 *
 * Called from InitHDCP for the first key set, once for each HDMI 2.1 receiver.
 *
 *   ksv        KSV_LENGTH bytes
 *   key_block  KEY_BLOCK_LENGTH bytes
 */
void hdcp_rx_hdmi21_load_keys(unsigned char port, unsigned char *ksv, unsigned char *key_block)
{
    unsigned short i;

    hdmi_rx21_reg_update_bits(port, 0x40, 8, 1);
    for (i = 0; i < KSV_LENGTH; i++)
        hdmi_rx21_reg_write8(port, i + 0x1a, ksv[i]);
    hdmi_rx21_reg_read8(port, 0xa0);
    hdmi_rx21_reg_write8(port, 0xa0, 0xe0);
    for (i = 0; i < KEY_BLOCK_LENGTH; i++) {
        hdmi_rx21_reg_write8(port, 0xa1, i);
        hdmi_rx21_reg_write8(port, 0xa2, i >> 8);
        hdmi_rx21_reg_write8(port, 0xa3, key_block[i]);
    }
}
