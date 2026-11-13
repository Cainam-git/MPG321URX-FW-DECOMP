/* hdcp_tx_hdmi_write_fixed_stream  (FUN_a00c7d5c)
 *
 * Write the ksv and key block, framed by fixed bytes, to registers 0xFC and 0xFE of an HDMI output.
 * Name basis: descriptive - bytes 0x19, 0xA2, ... through the register write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c7d5c @ 0xa00c7d5c, flags -mcpu=v8 -Os -g (the section default).
 * Source form: the register write routine is declared without a prototype, and the last call passes two extra
 * arguments (unused_5, unused_6) that the build depends on; the three trailing parameters are not used
 * anywhere else. Each run of zero bytes is its own counting loop (5, 2, 8, 2, 8, 2, 4), not one loop of 31.
 */
extern void hdmi_tx_reg_write8();

#define KSV_LENGTH       5      /* bytes of the key-selection value */
#define KEY_BLOCK_LENGTH 0x118  /* bytes of the key block written (the key block of the caller is 0x11A long) */

/*
 * Write a fixed stream of bytes to the data registers of one HDMI output.
 *
 *   port       the HDMI output, 0 or 1
 *   ksv        the 5-byte key-selection value
 *   keys       the key block; its first 0x118 bytes are written
 *   unused_4,
 *   unused_5,
 *   unused_6   not used (unused_5 and unused_6 are only passed on in the last write)
 *
 * Called twice by hdcp_tx_hdmi_load_fixed_streams, once for each HDMI output, with the second key set of
 * InitHDCP. Every byte goes through hdmi_tx_reg_write8(port, 0, register, value).
 *
 * To register 0xFE: 0x19, 0xA2, 0xC4. Then to register 0xFC, in order: 0; the 5 bytes of ksv; 0, 0, 0xA8; the
 * 0x118 bytes of keys; 31 zero bytes (in runs of 5, 2, 8, 2, 8, 2 and 4). Last, to register 0xFE: 0x19, 0x4C,
 * 0x2A.
 */
void hdcp_tx_hdmi_write_fixed_stream(unsigned char port,int ksv,int keys,unsigned int unused_4,unsigned int unused_5,
                 unsigned int unused_6)

{
  unsigned short i;
  
  hdmi_tx_reg_write8(port,0,0xfe,0x19);
  hdmi_tx_reg_write8(port,0,0xfe,0xa2);
  i = 0;
  hdmi_tx_reg_write8(port,0,0xfe,0xc4);
  hdmi_tx_reg_write8(port,0,0xfc,0);
  do {
    hdmi_tx_reg_write8(port,0,0xfc,*(unsigned char *)(ksv + (unsigned int)i));
    i = i + 1;
  } while (i < KSV_LENGTH);
  hdmi_tx_reg_write8(port,0,0xfc,0);
  hdmi_tx_reg_write8(port,0,0xfc,0);
  hdmi_tx_reg_write8(port,0,0xfc,0xa8);
  i = 0;
  do {
    hdmi_tx_reg_write8(port,0,0xfc,*(unsigned char *)(keys + (unsigned int)i));
    i = i + 1;
  } while (i < KEY_BLOCK_LENGTH);
  i = 0;
  do {
    hdmi_tx_reg_write8(port,0,0xfc,0);
    i = i + 1;
  } while (i < 5);
  i = 0;
  do {
    hdmi_tx_reg_write8(port,0,0xfc,0);
    i = i + 1;
  } while (i < 2);
  i = 0;
  do {
    hdmi_tx_reg_write8(port,0,0xfc,0);
    i = i + 1;
  } while (i < 8);
  i = 0;
  do {
    hdmi_tx_reg_write8(port,0,0xfc,0);
    i = i + 1;
  } while (i < 2);
  i = 0;
  do {
    hdmi_tx_reg_write8(port,0,0xfc,0);
    i = i + 1;
  } while (i < 8);
  i = 0;
  do {
    hdmi_tx_reg_write8(port,0,0xfc,0);
    i = i + 1;
  } while (i < 2);
  i = 0;
  do {
    hdmi_tx_reg_write8(port,0,0xfc,0);
    i = i + 1;
  } while (i < 4);
  hdmi_tx_reg_write8(port,0,0xfe,0x19);
  hdmi_tx_reg_write8(port,0,0xfe,0x4c);
  hdmi_tx_reg_write8(port,0,0xfe,0x2a,unused_5,unused_6);
  return;
}
