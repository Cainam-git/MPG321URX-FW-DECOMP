/* hdmi_tmds_restart_port  (FUN_a008ffa4)
 *
 * Restart an HDMI 2.0 input port after a request from the main processor.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - mailbox command 0x12 for ports 0/1: ratio flag, SCDC clear, error counter reset
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008ffa4 @ 0xa008ffa4 (-mcpu=v8 -Os -g)
 * Source form: the decompiled type and return forms are kept (see the comment at the routine).
 */

typedef unsigned char undefined1, byte;
typedef unsigned int undefined4;
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

#define RESTART_RATIO_FLAG  1       /* value stored by hdmi_set_port_ratio_flag */

extern void hdmi_phy_reset_error_counters(undefined1 param_1);
extern int hdmi_set_port_ratio_flag();
extern void hdmi_clear_scdc_config(undefined1 param_1);

/* Restart of HDMI 2.0 receiver "port" on the main program's command (IPC_CMD_RESTART_HDMI_PORT, which passes
   inputs 0 and 1 to this routine). For port 0 or 1 it sets the port's clock-ratio flag to 1
   (hdmi_set_port_ratio_flag), clears the SCDC mirror registers and resets the PHY's error counters. Any other
   port number does nothing. Source form: the routine is declared void but returns values, as in the
   decompiled form. */
void hdmi_tmds_restart_port(byte port,undefined4 param_2)

{
  unsigned char phy;
  
  phy = 0;
  if ((port != 0) && (phy = 1, port != 1)) {
    return CONCAT44(param_2,1);
  }
  hdmi_set_port_ratio_flag(phy,RESTART_RATIO_FLAG);
  hdmi_clear_scdc_config(port);
  return hdmi_phy_reset_error_counters((byte)phy);
}
