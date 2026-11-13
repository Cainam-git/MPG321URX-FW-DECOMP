/* hdmi_rx21_store_clock  (FUN_a00977cc)
 *
 * Store the measured clock of an HDMI 2.1 receiver in its record.
 *   port: receiver
 *   clock
 * Name basis: derived - halfword +0x32 of the 400-byte record, used for the rate reply of mailbox command 0x03
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00977cc @ 0xa00977cc-0xa00977e8 (7 words), flags -mcpu=v8 -Os -g. Leaf (retl).
 * Source form: the base is hdmi_rx21_input_records as a 400-byte struct array; the receiver is an unsigned char and the clock an
 * unsigned short.
 */
/* The receiver record (400 bytes, hdmi_rx21_input_records); only the pixel clock is named here. */
struct rx21_record { unsigned char pad_0x0[0x32]; unsigned short pixel_clock; unsigned char pad_0x34[400 - 0x34]; };
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Store the measured pixel clock in the record of an HDMI 2.1 receiver (halfword +0x32; the unit is 0.1 MHz).
 *   port: HDMI 2.1 receiver 0/1
 *   clock: the value from hdmi_rx21_measure_pixel_clock
 * Called by FSM_MODE_DETECT_STANDBY.
 */
void hdmi_rx21_store_clock(unsigned char port, unsigned short clock)
{
  hdmi_rx21_input_records[port].pixel_clock = clock;
}
