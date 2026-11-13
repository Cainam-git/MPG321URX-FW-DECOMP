/* hdmi_rx21_enable_sync_events  (FUN_a00a0b10)
 *
 * Enable or disable the sync and mode-change events of an HDMI 2.1 receiver.
 *   port: receiver
 *   enable: 1 = enable
 * Name basis: derived - events 0x16, 0xE, 0x1C, 0xB, 8 (and 0xC on newer chips); off when sync is lost, on at
 *   'Sync Stable'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0b10, flags -mcpu=v8 -Os -g (section default). Includes the merged unreachable ret/restore tail
 * FUN_a00a0b90. hdmi_rx21_enable_event is the tail call of the last branch. sys_get_chip_revision takes no
 * argument (the firmware sets no %o0 before it; the 'mov 0xc,%i1' in its delay slot belongs to the tail call).
 */
#define CHIP_REV_82 0x82                /* event 0xC is handled on later chip revisions only */

extern int sys_get_chip_revision();
extern void hdmi_rx21_enable_event();

/*
 * Enable or disable the events 0x16, 0xE, 0x1C, 0xB and 8 of receiver `port` with hdmi_rx21_enable_event, and
 * event 0xC as well on chip revisions above 0x82. Called by hdmi_rx21_stop_port (with 0),
 * hdmi_rx21_service_sync_events and DRV_HDMI_ModeDetect_FSM_Complete.
 *   port    HDMI 2.1 receiver 0/1
 *   enable  1 = enable the events, 0 = disable them
 */
void hdmi_rx21_enable_sync_events(unsigned char port, unsigned char enable)
{
    unsigned char revision;

    port = port & 0xff;
    hdmi_rx21_enable_event(port, 0x16, enable);
    hdmi_rx21_enable_event(port, 0xe, enable);
    hdmi_rx21_enable_event(port, 0x1c, enable);
    hdmi_rx21_enable_event(port, 0xb, enable);
    hdmi_rx21_enable_event(port, 8, enable);
    revision = sys_get_chip_revision() & 0xff;
    if (revision <= CHIP_REV_82) {
        return;
    }
    hdmi_rx21_enable_event(port, 0xc, enable);
}
