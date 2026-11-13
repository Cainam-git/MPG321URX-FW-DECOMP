/* hdmi_rx21_clear_event_word  (FUN_a00a10ec)
 *
 * Clear the per-port event word used by the HDMI 2.1 sync event handler.
 *   port: receiver
 * Name basis: descriptive - word i of 0xA8079184, compared in hdmi_rx21_service_sync_events; reached through a
 *   callback table
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a10ec, flags -mcpu=v8 -Os -g (section default). Leaf without a register window (no save).
 */
extern unsigned int hdmi_rx21_sync_event_words[];

/*
 * Clear the sync-event word of receiver `port`. It is the callback of event 2 (slot 2) in
 * hdmi_rx21_service_packet_events; hdmi_rx21_service_sync_events compares the word.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_clear_event_word(unsigned char port)
{
    hdmi_rx21_sync_event_words[port] = 0;
}
