/* input_power_off_receivers_mode0  (FUN_a006d0fc)
 *
 * Power off all HDMI and DP receivers and their links (power-off mode 0).
 * Note: They differ in the mode given to TMDS_PowerOff, in dp_set_port_enable_bits (0,0 against 1,1) and in
 *   where audio_clear_main_enable runs (mode 0 before the HPD check, mode 1 as the last call).
 * Name basis: derived - TMDS_PowerOff(port, 0) for ports 0..3, DP and link resets, then all port states set to
 *   power-off; caller is ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d0fc @ 0xa006d0fc, flags -mcpu=v8 -Os -g.
 * Source form: Ghidra's declarations are kept. The six parameters are never read; parameters 2 to 6 are only
 * passed on to dp_tx_force_hpd_check, which is declared without a parameter list.
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
extern int input_set_ports_power_off();
extern void dp_set_port_enable_bits();
extern int dp_tx_force_hpd_check();
extern int audio_clear_main_enable();
extern void irq_empty_vector_handler_copy3();
extern void dp_tx_phy_power_down_edp_unit(void);
extern int dp_tx_phy_power_down_dptx_unit();
extern int dp_tx_phy_power_down_output();
extern int dp_setup_service_block();
extern int dp_unit_set_reg1_bit5_and_reg3();
extern void dp_unit_restart();
extern int dp_stop_port();
extern void TMDS_PowerOff();

/*
 * Power down every receiver and link of the input program for command 0x73 of the mailbox dispatcher
 * (it prints "_SetLeonSPowerDown 999" first). After it the dispatcher sets status flag 6, publishes the
 * status flags and loops forever.
 * Order: the four HDMI receivers (TMDS_PowerOff, mode 0), the five DP PHY outputs, the two registers
 * 0xCF012448 and 0xCF014760 cleared, the DP unit reset field and restart for unit 0 and 1, the DP port stop,
 * the empty interrupt-vector handler copy for 0 and 1, the eDP and DP-TX PHY power-down, the DP port enable
 * bits for port 0 and 1 set to 0 and 0, the service block, the audio main enable cleared, all nine port
 * records set to power-off, and a forced HPD check with argument 0.
 * Mode 1 (command 0x72) does the same with TMDS mode 1, enable bits 1 and 1, and clears the audio enable last.
 * Parameters: none are used by this routine.
 */
void input_power_off_receivers_mode0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  TMDS_PowerOff(0,0);
  TMDS_PowerOff(1,0);
  TMDS_PowerOff(2,0);
  TMDS_PowerOff(3,0);
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
  dp_set_port_enable_bits(0,0,0);
  dp_set_port_enable_bits(1,0,0);
  dp_setup_service_block(1);
  audio_clear_main_enable();
  /* Mode 0 clears the audio enable first; mode 1 does it after the HPD check. */
  input_set_ports_power_off();
  dp_tx_force_hpd_check(0,param_2,param_3,param_4,param_5,param_6);
  return;
}