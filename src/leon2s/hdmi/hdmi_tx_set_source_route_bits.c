/* hdmi_tx_set_source_route_bits  (FUN_a008e7c0)
 *
 * Set or clear the route bits of an HDMI TX port in register 0xCF0116B4 for an input code.
 *   port: HDMI TX port
 *   code: input port code
 *   on: 1 = connect
 * Note: The only caller passes on = 0 (bits cleared); on connect only the HDMI 2.1 codes 0x51 / 0x61 leave the
 *   port's bit set.
 * Name basis: descriptive - 0xCF0116B4 bits by TX port and input code 0x31/0x41/0x51/0x61
 *   (input_decode_port_code values); one caller, hdmi_tx_run_step, with on = 0
 *
 * Matching notes
 * --------------
 * FUN_a008e7c0 (leon2s, 0xa008e7c0-0xa008e940, 96 words), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - every access is a read-modify-write of the volatile register;
 *  - the 0x51 / 0x61 dispatch is a switch whose cases return, with break for the other ports (firmware:
 *    cmp 0x51 be; cmp 0x61 be; default b to the shared & 0xfc tail);
 *  - the code test is written (c == 0x31 || c == 0x41 || (c == 0x51 || c == 0x61)).
 */
#define reg_hdmi_tx_source_route (*(volatile unsigned int *)0xcf0116b4)

/* Input codes of the HDMI receivers (source_code of the TX channel record). */
#define INPUT_CODE_HDMI20_0 0x31
#define INPUT_CODE_HDMI20_1 0x41
#define INPUT_CODE_HDMI21_0 0x51
#define INPUT_CODE_HDMI21_1 0x61

/* Bits of reg_hdmi_tx_source_route, one per TX port. */
#define ROUTE_ON_PORT0       0x01   /* bit 0 / 1: set only for an HDMI 2.1 input */
#define ROUTE_ON_PORT1       0x02
#define ROUTE_RX21_1_PORT0   0x04   /* bit 2 / 3: set for INPUT_CODE_HDMI21_1, cleared for _0 */
#define ROUTE_RX21_1_PORT1   0x08

/*
 * Set or clear the bits of an HDMI TX port in register 0xCF0116B4 (reg_hdmi_tx_source_route).
 *
 *   port  the HDMI TX port (0 or 1)
 *   code  the input code of the source (INPUT_CODE_*)
 *   on    1: connect; any other value: disconnect
 *
 * The only caller, TX set-up step 6 (TX_STEP_CLOCK_SOURCE_FRL in hdmi_tx_run_step), passes on = 0, so only the
 * disconnect path runs in the firmware: it clears bit 0 (port 0) or bit 1 (port 1), or both for another port.
 *
 * Connect, by code:
 *   HDMI 2.1 receiver 0 / 1:  set the port's bit 0 / 1, and clear (receiver 0) or set (receiver 1) its
 *                             bit 2 / 3;
 *   HDMI 2.0 receiver 0 / 1:  the port's bit is set and then cleared again together with the other port's
 *                             (the shared ending & 0xfc), so bits 0 and 1 both end up clear;
 *   any other code:           as disconnect.
 * A port other than 0 or 1 clears bits 0 and 1 on every path.
 */
void hdmi_tx_set_source_route_bits(unsigned char port, unsigned char code, unsigned char on)
{
  if ((on == 1) &&
     ((code == INPUT_CODE_HDMI20_0 || code == INPUT_CODE_HDMI20_1 || (code == INPUT_CODE_HDMI21_0 || code == INPUT_CODE_HDMI21_1)))) {
    if (port == 0) {
      reg_hdmi_tx_source_route = reg_hdmi_tx_source_route | ROUTE_ON_PORT0;
    }
    else if (port == 1) {
      reg_hdmi_tx_source_route = reg_hdmi_tx_source_route | ROUTE_ON_PORT1;
    }
    else {
      reg_hdmi_tx_source_route = reg_hdmi_tx_source_route & 0xfc;
    }
    switch (code) {
    case INPUT_CODE_HDMI21_0:
      if (port == 0) {
        reg_hdmi_tx_source_route = reg_hdmi_tx_source_route & 0xfb;
        return;
      }
      if (port == 1) {
        reg_hdmi_tx_source_route = reg_hdmi_tx_source_route & 0xf7;
        return;
      }
      break;
    case INPUT_CODE_HDMI21_1:
      if (port == 0) {
        reg_hdmi_tx_source_route = reg_hdmi_tx_source_route | ROUTE_RX21_1_PORT0;
        return;
      }
      if (port == 1) {
        reg_hdmi_tx_source_route = reg_hdmi_tx_source_route | ROUTE_RX21_1_PORT1;
        return;
      }
      break;
    }
  }
  else {
    if (port == 0) {
      reg_hdmi_tx_source_route = reg_hdmi_tx_source_route & 0xfe;
      return;
    }
    if (port == 1) {
      reg_hdmi_tx_source_route = reg_hdmi_tx_source_route & 0xfd;
      return;
    }
  }
  /* HDMI 2.0 codes on connect, and any port other than 0 / 1, end here. */
  reg_hdmi_tx_source_route = reg_hdmi_tx_source_route & 0xfc;
  return;
}
