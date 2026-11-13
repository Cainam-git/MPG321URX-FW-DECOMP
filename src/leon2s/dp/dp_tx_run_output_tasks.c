/* dp_tx_run_output_tasks  (FUN_a0089d38)
 *
 * Run the hot-plug handling and the pacing update of each DP output the main processor requested.
 * Name basis: derived - calls dp_tx_run_hpd_actions, dp_tx_edp_run_hpd_actions, DPTX_SetBrilliantMode per
 *   requested output
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0089d38 @ 0xa0089d38 (-mcpu=v8 -Os -g)
 * Source form: the six parameters are never used by the code (Ghidra's signature); the first return path
 * returns CONCAT44(param_2, param_1), the last returns the result of dp_tx_refresh_reg73. The callers do not use
 * the result. The calls are written out one per output.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
typedef unsigned char byte;
typedef unsigned int undefined4;
extern unsigned char dp_tx_edp_first_output;
extern int dp_tx_run_hpd_actions();
extern int DPTX_SetBrilliantMode();
extern byte dp_tx_mode_requested_1(void);
extern byte dp_tx_mode_requested_2(void);
extern byte dp_tx_mode_requested_3(void);
extern byte dp_tx_mode_requested_4(void);
extern byte dp_tx_mode_requested_0(void);
extern int dp_tx_refresh_reg73();
extern int dp_tx_edp_run_hpd_actions();

/*
 * One pass over the DP outputs, called once per main-loop pass by input_poll_port_services.
 * First the hot-plug handling: dp_tx_run_hpd_actions(0) for output 0 when the main processor has asked for an
 * update of output 0 (dp_tx_mode_requested_0), and dp_tx_edp_run_hpd_actions for the eDP outputs on every pass,
 * with dp_tx_edp_first_output as its argument.
 * Then for each output 0..4 whose update was requested by the main processor (dp_tx_mode_requested_0..4, bits
 * 2 to 6 of the command byte): DPTX_SetBrilliantMode(output) and dp_tx_refresh_reg73(output).
 */
int dp_tx_run_output_tasks(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4,
                           undefined4 param_5, undefined4 param_6)

{
  byte requested;

  requested = dp_tx_mode_requested_0();
  if (requested != 0) {
    dp_tx_run_hpd_actions(0);
  }
  dp_tx_edp_run_hpd_actions(dp_tx_edp_first_output);
  requested = dp_tx_mode_requested_0();
  if (requested != 0) {
    DPTX_SetBrilliantMode(0);
    dp_tx_refresh_reg73(0);
  }
  requested = dp_tx_mode_requested_1();
  if (requested != 0) {
    DPTX_SetBrilliantMode(1);
    dp_tx_refresh_reg73(1);
  }
  requested = dp_tx_mode_requested_2();
  if (requested != 0) {
    DPTX_SetBrilliantMode(2);
    dp_tx_refresh_reg73(2);
  }
  requested = dp_tx_mode_requested_3();
  if (requested != 0) {
    DPTX_SetBrilliantMode(3);
    dp_tx_refresh_reg73(3);
  }
  requested = dp_tx_mode_requested_4();
  if (requested == 0) {
    return CONCAT44(param_2, param_1);
  }
  DPTX_SetBrilliantMode(4);
  return dp_tx_refresh_reg73(4, param_2, param_3, param_4, param_5, param_6);
}
