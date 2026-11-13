/* hdmi_rx21_set_audio_mute  (FUN_a009c794)
 *
 * Set or clear the audio mute bit of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 *   on: 1 = mute
 * Name basis: derived - bit 0x19 of control word +0x34; DRV_HDMI_Set_AudStatus sets it while audio is not
 *   stable
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c794 @ 0xa009c794-0xa009c7e4 (20 words), flags -mcpu=v8 -Os -g. Leaf.
 * Both register calls are sibling calls.
 * Source form: the block 1 address in the 0x34-byte entry is a byte pointer.
 */
#define BLOCK1_REG_34 0x34              /* byte offset of the control register in block 1 */
#define AUDIO_MUTE_BIT 0x19

/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks { unsigned int block0; unsigned char *block1; unsigned char pad8[0x2c]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern void reg_set_bit(int, unsigned char *);
extern void reg_clear_bit(int, unsigned char *);

/*
 * Set or clear bit 0x19 of the register at block 1 + 0x34 of an HDMI 2.1 receiver, which is its audio mute.
 *   port: HDMI 2.1 receiver 0/1
 *   on: 1 = set the bit, any other value = clear it
 * Called by DRV_HDMI_Set_AudStatus with on = 1 while the audio is not marked stable.
 */
void hdmi_rx21_set_audio_mute(unsigned char port, unsigned char on)
{
  if (on == 1) {
    reg_set_bit(AUDIO_MUTE_BIT, ARR_a807db00[port].block1 + BLOCK1_REG_34);
    return;
  }
  reg_clear_bit(AUDIO_MUTE_BIT, ARR_a807db00[port].block1 + BLOCK1_REG_34);
}
