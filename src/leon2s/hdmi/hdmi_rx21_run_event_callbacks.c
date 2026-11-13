/* hdmi_rx21_run_event_callbacks  (FUN_a00a1098)
 *
 * Call the callback of each set bit of an event mask from a table.
 *   port: receiver
 *   event_mask: event bits
 *   callbacks: callback table
 * Name basis: derived - 8 table entries, bit n -> entry n; caller hdmi_rx21_service_packet_events
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1098, flags -mcpu=v8 -Os -g (section default). The `(unsigned char)slot` cast produces the
 * `and %l0, 0xff, %g1` before the comparison.
 */
/*
 * Call the callback of every slot whose bit is set in `event_mask`: bit n selects slot n of the 8-entry table
 * `callbacks`. Empty slots (0) are skipped; each callback gets the receiver number. Called by
 * hdmi_rx21_service_packet_events, once per event word.
 *   port        HDMI 2.1 receiver 0/1, handed to each callback
 *   event_mask  status bits found set
 *   callbacks   table of 8 routine addresses
 */
void hdmi_rx21_run_event_callbacks(unsigned int port, unsigned char event_mask, unsigned int **callbacks)
{
    unsigned int slot = 0;

    if ((event_mask & 0xff) != 0) {
        do {
            if ((event_mask >> slot & 1U) != 0) {
                if (*callbacks != 0) {
                    ((int (*)(unsigned int))*callbacks)(port & 0xff);
                }
            }
            callbacks++;
            slot++;
        } while ((unsigned char)slot < 8);
    }
}
