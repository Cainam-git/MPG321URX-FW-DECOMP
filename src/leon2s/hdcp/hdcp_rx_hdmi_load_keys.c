/* hdcp_rx_hdmi_load_keys  (FUN_a00c0ce8)
 *
 * Load the key-selection value and the key block into an HDMI 2.0 input.
 * Name basis: derived - 5 bytes to registers 0x1A..0x1E, 0x11A bytes through the table port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c0ce8 @ 0xa00c0ce8, flags -mcpu=v8 -Os -g (the section default).
 * Source form: the port is a signed char widened and masked with 0xff into an unsigned int; the key-selection
 * value is passed as an unsigned int address and the key block as an int address (both are cast when read);
 * the hardware registers are volatile.
 */
#define REG_cf00bfcc (*(volatile unsigned int *)0xcf00bfcc)
#define REG_cf011438 (*(volatile unsigned int *)0xcf011438)
#define REG_cf011780 (*(volatile unsigned int *)0xcf011780)
#define REG_cf011784 (*(volatile unsigned int *)0xcf011784)
#define REG_cf011788 (*(volatile unsigned int *)0xcf011788)
#define REG_cf01178c (*(volatile unsigned int *)0xcf01178c)

#define KSV_LENGTH       5      /* bytes of the key-selection value */
#define KEY_BLOCK_LENGTH 0x11a  /* bytes of the key block */

extern int hdmi_reg_read8();
extern int hdmi_reg_write8();
extern int hdmi_reg_update_bits();

/*
 * Load the key-selection value and the key block into one HDMI 2.0 receiver.
 *
 *   port  the receiver, 0 or 1 (the register helpers take the receiver number)
 *   ksv   the 5-byte key-selection value
 *   keys  the 0x11A-byte key block
 *
 * Called by InitHDCP for ports 0 and 1. In order: bit 3 of register 0x40 is set (and stays set); the five
 * bytes of ksv go to registers 0x1A..0x1E; then, with bit 7 of register 0x41 and bit 2 of 0xCF011438 set for
 * the time of the load, the key block is written byte by byte to 0xCF01178C after 0x32 was put in
 * 0xCF011780 and 0xCF011784, 0xCF011788 and 0xCF00BFCC were cleared. Register 0x41 and 0xCF011438 are
 * then restored to the values they had before; 0xCF011780 is not restored (hdcp_rx_dp_load_keys restores it).
 */
void hdcp_rx_hdmi_load_keys(signed char port, unsigned int ksv, int keys)

{
  unsigned short reg;
  unsigned char saved_cf011438;
  unsigned int saved_reg_0x41;
  unsigned short j;
  unsigned short i;
  unsigned int port_index;

  port_index = port;

  port_index = port_index & 0xff;
  hdmi_reg_update_bits(port_index,0x40,8,1);
  i = 0;
  do {
    reg = i + 0x1a;
    hdmi_reg_write8(port_index, reg, *(unsigned char *)(ksv + i));
    i = i + 1;
  } while (KSV_LENGTH > i);
  saved_reg_0x41 = hdmi_reg_read8(port_index,0x41);
  saved_cf011438 = REG_cf011438;
  hdmi_reg_update_bits(port_index,0x41,0x80,1);
  REG_cf011438 = REG_cf011438 | 4;
  REG_cf011780 = 0x32;
  REG_cf011784 = 0;
  REG_cf011788 = 0;
  REG_cf00bfcc = 0;
  i = 0;
  do {
    REG_cf01178c = *(unsigned char *)(keys + i);
    j = i + 1;
    i = j;
  } while (j < KEY_BLOCK_LENGTH);
  hdmi_reg_write8(port_index, 0x41, saved_reg_0x41 & 0xff);
  REG_cf011438 = saved_cf011438 & 0xff;
}
