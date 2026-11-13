/* hdmi_rx21_empty_callback  (FUN_a00a1574)
 *
 * Do nothing (empty event callback).
 * Name basis: descriptive - empty body; not called directly
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1574, flags -mcpu=v8 -Os -g (section default). An empty void function compiles to 'retl; nop'.
 */
/*
 * Callback with an empty body: it fills slot 3 for event 0x2B in hdmi_rx21_service_packet_events.
 */
void hdmi_rx21_empty_callback(void)
{
}
