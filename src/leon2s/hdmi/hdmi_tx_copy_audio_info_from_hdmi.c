/* hdmi_tx_copy_audio_info_from_hdmi  (FUN_a00931fc)
 *
 * Copy the audio settings and InfoFrame of an HDMI input into an HDMI TX port.
 *   rx: receiver
 *   port: HDMI TX port
 * Name basis: derived - reads through the receiver read routine chosen by hdmi_tx_setup_audio (regs 0x12A..,
 *   0x180..0x188)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00931fc @ 0xa00931fc, flags -mcpu=v8 -Os -g.
 * Source form: the reader is an int-returning pointer without a prototype, called as (rx & 0xff, reg) and
 * its result cast to unsigned char; reg is an unsigned short local; each copy is a do-while loop.
 */
extern int (*hdmi_tx_audio_reg_reader)();     /* hdmi_reg_read8 or hdmi_rx21_reg_read8, set by hdmi_tx_setup_audio */
extern void hdmi_tx_reg_write8(unsigned int port, unsigned int bank, unsigned short reg, unsigned int value);
extern void hdmi_tx_reg_update_bits(unsigned int port, unsigned int bank, unsigned int reg, unsigned int mask, unsigned int mode);

#define TX_BANK_0               0
#define BITS_CLEAR              0       /* mode argument of hdmi_tx_reg_update_bits */
#define BITS_SET                1

/* Receiver registers copied, and where they go in bank 0 of the TX port. */
#define RX_REG_12A              0x12a   /* 0x12A..0x12C -> TX 0x11E..0x120 */
#define TX_REG_11E              0x11e
#define RX_REG_130              0x130   /* 0x130..0x131 -> TX 0x121..0x122 */
#define TX_REG_121              0x121
#define PACKET_SLOT_180         0x180   /* 0x180..0x188, same numbers on both sides */

#define PACKET_ENABLE_REG       0x13e   /* packet enable bits, bank 0 */
#define AUDIO_SLOT_ENABLE_MASK  0x30    /* bits 5..4: the packet in the 0x180 slot */

/*
 * Copy audio registers of an HDMI input (2.0 or 2.1 receiver) into bank 0 of an HDMI TX port. Called only by
 * hdmi_tx_setup_audio for the HDMI audio sources, after it has stored the matching register read routine in
 * hdmi_tx_audio_reg_reader. The DisplayPort counterpart is hdmi_tx_copy_audio_info_from_dp, which builds the
 * same TX registers itself.
 *
 *   rx     receiver number (0 or 1) for the read routine
 *   port   HDMI TX port
 *
 * Receiver registers 0x12A..0x12C go to TX registers 0x11E..0x120 and 0x130..0x131 to 0x121..0x122. The nine
 * registers of the 0x180 packet slot are copied one to one while the slot's enable bits (bits 5..4 of
 * register 0x13E) are cleared; they are set again at the end.
 */
void hdmi_tx_copy_audio_info_from_hdmi(unsigned int rx, unsigned char port)
{
  unsigned char i;
  unsigned short reg;
  unsigned char value;

  i = 0;
  do {
    reg = (unsigned short)(i + RX_REG_12A);
    value = (unsigned char)(*hdmi_tx_audio_reg_reader)(rx & 0xff, reg);
    hdmi_tx_reg_write8(port, TX_BANK_0, (unsigned short)(i + TX_REG_11E), value);
    i = i + 1;
  } while (i <= 2);

  i = 0;
  do {
    reg = (unsigned short)(i + RX_REG_130);
    value = (unsigned char)(*hdmi_tx_audio_reg_reader)(rx & 0xff, reg);
    hdmi_tx_reg_write8(port, TX_BANK_0, (unsigned short)(i + TX_REG_121), value);
    i = i + 1;
  } while (i <= 1);

  /* The slot is switched off while it is rewritten. */
  hdmi_tx_reg_update_bits(port, TX_BANK_0, PACKET_ENABLE_REG, AUDIO_SLOT_ENABLE_MASK, BITS_CLEAR);

  i = 0;
  do {
    reg = (unsigned short)(i + PACKET_SLOT_180);
    value = (unsigned char)(*hdmi_tx_audio_reg_reader)(rx & 0xff, reg);
    hdmi_tx_reg_write8(port, TX_BANK_0, reg, value);
    i = i + 1;
  } while (i <= 8);

  hdmi_tx_reg_update_bits(port, TX_BANK_0, PACKET_ENABLE_REG, AUDIO_SLOT_ENABLE_MASK, BITS_SET);
}
