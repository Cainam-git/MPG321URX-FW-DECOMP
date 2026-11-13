/* hdmi_rx21_stop_port  (FUN_a00a1638)
 *
 * Shut an HDMI 2.1 receiver port down: flags, events, interrupts and mode state.
 *   p: receiver
 * Returns: 0 when stopped, 1 when not initialised
 * Name basis: derived - DRV_HDMI_Setup_IntIRQ_Events(p, 0), hdmi_rx21_enable_sync_events off,
 *   hdmi_rx21_modedet_reset_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1638, flags -mcpu=v8 -Os -g (section default). The record index and the `== 0` test use the
 * parameter unmasked (`receiver`); the calls use `port & 0xff`. The second parameter is not used.
 */
/* Offsets in the 400-byte record of a receiver (hdmi_rx21_input_records). */
#define RX21_RECORD_BYTE_4 4            /* cleared here; set to 1 by DRV_HDMI_ModeDetect_FSM_Complete */
#define RX21_RECORD_BYTE_5 5

extern unsigned char hdmi_rx21_input_records[];
extern unsigned char hdmi_rx_if_init_flag;
extern void hdmi_rx21_set_port_flag(unsigned int param_1, unsigned char param_2);
extern void hdmi_rx21_modedet_reset_state(unsigned int param_1);
extern void irq_disable_hdmi_port0(void);
extern void irq_disable_hdmi_port1(void);
extern void DRV_HDMI_Setup_IntIRQ_Events(unsigned int param_1, unsigned int param_2);
extern void hdmi_rx21_enable_sync_events(unsigned int param_1, unsigned int param_2);

/*
 * Shut HDMI 2.1 receiver `port` down. Only when hdmi_rx_if_init_flag is non-zero, in this order: clear the port
 * flag (hdmi_rx21_set_port_flag), clear bytes 4 and 5 of the receiver record, switch the interrupt events off
 * (DRV_HDMI_Setup_IntIRQ_Events with 0), disable the sync events, disable the interrupt of the receiver's
 * port (irq_disable_hdmi_port0 for receiver 0, irq_disable_hdmi_port1 otherwise) and reset the mode-detect
 * state. Returns 0 when stopped, 1 when the interface is not initialised. Called by hdmi_rx21_set_port_enable.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned int hdmi_rx21_stop_port(unsigned int port, unsigned int unused)
{
  unsigned int result;
  unsigned int receiver;

  receiver = port;
  result = 1;
  if (hdmi_rx_if_init_flag != 0)
  {
    hdmi_rx21_set_port_flag(port & 0xff, 0);
    hdmi_rx21_input_records[(receiver * 400) + RX21_RECORD_BYTE_4] = 0;
    hdmi_rx21_input_records[(receiver * 400) + RX21_RECORD_BYTE_5] = 0;
    DRV_HDMI_Setup_IntIRQ_Events(port & 0xff, 0);
    hdmi_rx21_enable_sync_events(port & 0xff, 0);
    if (receiver == 0)
    {
      irq_disable_hdmi_port0();
    }
    else
    {
      irq_disable_hdmi_port1();
    }
    hdmi_rx21_modedet_reset_state(port & 0xff);
    result = 0;
  }
  return result;
}
