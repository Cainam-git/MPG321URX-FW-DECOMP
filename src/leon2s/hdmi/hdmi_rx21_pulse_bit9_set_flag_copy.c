/* hdmi_rx21_pulse_bit9_set_flag_copy  (FUN_a00a151c)
 *
 * Pulse control bit 9 of an HDMI 2.1 receiver and set a done flag.
 *   port: receiver
 * Note: Identical copy of hdmi_rx21_pulse_bit9_set_flag.
 * Name basis: descriptive - flag byte 0xA807918E; reached through a callback table; identical twin
 *   hdmi_rx21_pulse_bit9_set_flag
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a151c, flags -mcpu=v8 -Os -g (section default). Byte-identical twin: hdmi_rx21_pulse_bit9_set_flag.
 */
extern unsigned char hdmi_rx21_bit9_done_flag;
extern int reg_set_bit();
extern int reg_clear_bit();
extern int timer_delay_units();
extern int timer_delay_long_units();

extern unsigned char hdmi_rx21_reg_blocks[][0x34];

/*
 * Same code as hdmi_rx21_pulse_bit9_set_flag. Entered as the callback of event 0x19 (slot 1) in
 * hdmi_rx21_service_packet_events.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_pulse_bit9_set_flag_copy(unsigned int port)
{
  port &= 0xff;
  reg_set_bit(9,*(int *)hdmi_rx21_reg_blocks[port] + 4);
  timer_delay_units(1);
  reg_clear_bit(9,*(int *)hdmi_rx21_reg_blocks[port] + 4);
  timer_delay_long_units(1);
  hdmi_rx21_bit9_done_flag = 1;
}
