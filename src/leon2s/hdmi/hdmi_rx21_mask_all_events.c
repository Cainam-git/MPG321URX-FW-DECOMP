/* hdmi_rx21_mask_all_events  (FUN_a00a2e48)
 *
 * Disable all interrupt events of an HDMI 2.1 receiver.
 *   receiver
 * Returns: 0
 * Name basis: derived - clears the enable bytes of event words 0x74..0xC8; caller _hdmi_Init_Interrupt
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2e48 @ 0xa00a2e48, flags -mcpu=v8 -Os -g.
 * Source form: the row array is the byte symbol hdmi_rx21_reg_blocks; the block pointer is read once through a
 * volatile int pointer and each word is read and written through volatile pointers.
 */
extern unsigned char hdmi_rx21_reg_blocks;     /* rows of 0x34 bytes, word 0 = block 0 of the receiver */

/* Mask all events of the HDMI 2.1 receiver (0 or 1): AND seven words of register block 0 with the masks below.
   The words at 0x74, 0x78, 0x7C and 0x90 are the ones in which hdmi_rx21_enable_event sets and clears event
   bits. Called for both receivers by _hdmi_Init_Interrupt. Returns 0.
     offset  0x74 keeps 0x000000FF     0x78 keeps 0xFFFFFF00     0x7C keeps 0x000000FF
             0x90 keeps 0x00FF00FF     0xAC keeps 0xFF000000     0xC4 keeps 0x00FF00FF
             0xC8 keeps 0xFFFF00FF */
unsigned int hdmi_rx21_mask_all_events(unsigned int receiver)
{
  int block0;

  block0 = *(volatile int *)(&hdmi_rx21_reg_blocks + (receiver & 0xff) * 0x34);
  *(volatile unsigned int *)(block0 + 0x74) = *(volatile unsigned int *)(block0 + 0x74) & 0xff;
  *(volatile unsigned int *)(block0 + 0x78) = *(volatile unsigned int *)(block0 + 0x78) & 0xffffff00;
  *(volatile unsigned int *)(block0 + 0x7c) = *(volatile unsigned int *)(block0 + 0x7c) & 0xff;
  *(volatile unsigned int *)(block0 + 0x90) = *(volatile unsigned int *)(block0 + 0x90) & 0xff00ff;
  *(volatile unsigned int *)(block0 + 0xac) = *(volatile unsigned int *)(block0 + 0xac) & 0xff000000;
  *(volatile unsigned int *)(block0 + 0xc4) = *(volatile unsigned int *)(block0 + 0xc4) & 0xff00ff;
  *(volatile unsigned int *)(block0 + 200) = *(volatile unsigned int *)(block0 + 200) & 0xffff00ff;
  return 0;
}
