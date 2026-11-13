/* input_power_off_receivers_mode1  (FUN_a006d204)
 *
 * Power off all HDMI and DP receivers and their links (power-off mode 1).
 * Note: They differ in the mode given to TMDS_PowerOff, in dp_set_port_enable_bits (0,0 against 1,1) and in
 *   where audio_clear_main_enable runs (mode 0 before the HPD check, mode 1 as the last call).
 * Name basis: derived - TMDS_PowerOff(port, 1) for ports 0..3, DP and link resets, then all port states set to
 *   power-off; caller is ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d204 @ 0xa006d204, flags -mcpu=v8 -Os -g.
 * Source form: the trailing audio_clear_main_enable call is the last statement and compiles to a tail call.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define reg_input_port_control (*(volatile unsigned int *)0xcf012448)
#define _DAT_cf014760 (*(volatile unsigned int *)0xcf014760)
extern void input_set_ports_power_off(void);
extern void dp_set_port_enable_bits(uint param_1, uint param_2, uint param_3);
extern void dp_tx_force_hpd_check(uint param_1);
extern void audio_clear_main_enable(void);
extern void irq_empty_vector_handler_copy3(uint param_1);
extern void dp_tx_phy_power_down_edp_unit(void);
extern void dp_tx_phy_power_down_dptx_unit(void);
extern void dp_tx_phy_power_down_output(uint param_1);
extern void dp_setup_service_block(uint param_1);
extern void dp_unit_set_reg1_bit5_and_reg3(uint param_1);
extern void dp_unit_restart(uint param_1, uint param_2);
extern void dp_stop_port(uint param_1);
extern void TMDS_PowerOff(uint param_1, uint param_2);

/*
 * Power down every receiver and link of the input program for command 0x72 of the mailbox dispatcher, after
 * dp_tx_set_sink_power(0, 0) and irq_set_mask_preset(1); after it the
 * dispatcher sets status flag 6, publishes the status flags and loops forever. Same sequence as input_power_off_receivers_mode0, except:
 * TMDS_PowerOff gets mode 1, dp_set_port_enable_bits gets (port, 1, 1), and the audio main enable is cleared
 * last, after the forced HPD check (mode 0 clears it before the port states are set to power-off).
 */
void input_power_off_receivers_mode1(void)
{
  TMDS_PowerOff(0,1);
  TMDS_PowerOff(1,1);
  TMDS_PowerOff(2,1);
  TMDS_PowerOff(3,1);
  dp_tx_phy_power_down_output(0);
  dp_tx_phy_power_down_output(1);
  dp_tx_phy_power_down_output(2);
  dp_tx_phy_power_down_output(3);
  dp_tx_phy_power_down_output(4);
  reg_input_port_control = 0;
  /* Both port-control registers are cleared before any unit is restarted. */
  _DAT_cf014760 = 0;
  dp_unit_set_reg1_bit5_and_reg3(2);
  dp_unit_restart(0,1);
  dp_unit_restart(1,1);
  dp_stop_port(0);
  dp_stop_port(1);
  irq_empty_vector_handler_copy3(0);
  irq_empty_vector_handler_copy3(1);
  dp_tx_phy_power_down_edp_unit();
  dp_tx_phy_power_down_dptx_unit();
  dp_set_port_enable_bits(0,1,1);
  dp_set_port_enable_bits(1,1,1);
  dp_setup_service_block(1);
  input_set_ports_power_off();
  dp_tx_force_hpd_check(0);
  audio_clear_main_enable();
}
