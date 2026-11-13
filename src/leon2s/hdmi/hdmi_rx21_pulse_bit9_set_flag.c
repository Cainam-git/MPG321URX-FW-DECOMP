/* hdmi_rx21_pulse_bit9_set_flag  (FUN_a00a14c4)
 *
 * Pulse control bit 9 of an HDMI 2.1 receiver and set a done flag.
 *   port: receiver
 * Name basis: descriptive - flag byte 0xA807918E; reached through a callback table; identical twin
 *   hdmi_rx21_pulse_bit9_set_flag_copy
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a14c4, flags -mcpu=v8 -Os -g (section default). Byte-identical twin: hdmi_rx21_pulse_bit9_set_flag_copy.
 */
extern unsigned char hdmi_rx21_bit9_done_flag;
extern int reg_set_bit();
extern int reg_clear_bit();
extern int timer_delay_units();
extern int timer_delay_long_units();

extern unsigned char hdmi_rx21_reg_blocks[][0x34];

/*
 * Pulse bit 9 of the word at byte offset 4 of register block 0 of receiver `port` (set, wait one
 * timer_delay_units, clear, wait one timer_delay_long_units), then set hdmi_rx21_bit9_done_flag to 1. Entered as
 * the callback of event 0x18 (slot 0) in hdmi_rx21_service_packet_events; no other routine reads the flag.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_pulse_bit9_set_flag(unsigned int port)
{
  port &= 0xff;
  reg_set_bit(9,*(int *)hdmi_rx21_reg_blocks[port] + 4);
  timer_delay_units(1);
  reg_clear_bit(9,*(int *)hdmi_rx21_reg_blocks[port] + 4);
  timer_delay_long_units(1);
  hdmi_rx21_bit9_done_flag = 1;
}
