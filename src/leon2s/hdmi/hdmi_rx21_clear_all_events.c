/* hdmi_rx21_clear_all_events  (FUN_a00a0bfc)
 *
 * Clear every pending interrupt status bit of an HDMI 2.1 receiver.
 *   port: receiver
 * Name basis: derived - writes ones to the status bytes of words 0x70..0x80 and 0x90 (write-one-to-clear)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0bfc, flags -mcpu=v8 -Os -g (section default). The register block pointer is read through a
 * volatile access.
 */
extern unsigned char hdmi_rx21_reg_blocks;

/*
 * Write a 1 to every status bit of the event words of receiver `port` (register block 0, byte offsets 0x70,
 * 0x74, 0x78, 0x7C, 0x80 and 0x90). The bits under the mask of each line are written back as read; the other
 * bits are written as 0 or 1 as the constants show. Called by the interrupt service routines of both
 * receivers and by DRV_HDMI_ModeDetect_FSM_Complete.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_clear_all_events(unsigned int port)
{
  int block0;

  block0 = *(volatile int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34);
  *(volatile unsigned int *)(block0 + 0x70) = *(volatile unsigned int *)(block0 + 0x70) & 0xff | 0xfffffc00;
  *(volatile unsigned int *)(block0 + 0x74) = *(volatile unsigned int *)(block0 + 0x74) | 0xff;
  *(volatile unsigned int *)(block0 + 0x78) = *(volatile unsigned int *)(block0 + 0x78) & 0xffffff | 0xff000000;
  *(volatile unsigned int *)(block0 + 0x7c) = *(volatile unsigned int *)(block0 + 0x7c) | 0xff;
  *(volatile unsigned int *)(block0 + 0x80) = *(volatile unsigned int *)(block0 + 0x80) & 0xffffff | 0xff000000;
  *(volatile unsigned int *)(block0 + 0x90) = *(volatile unsigned int *)(block0 + 0x90) & 0xff00ff00 | 0xff;
}
