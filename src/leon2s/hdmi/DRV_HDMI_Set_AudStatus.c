/* DRV_HDMI_Set_AudStatus  (DRV_HDMI_Set_AudStatus)
 *
 * Mark the audio of an HDMI receiver port stable or not and update its mute.
 *   port: receiver
 *   on: 1 = stable
 * Name basis: proven - original name printed ('[MODEDET]: Port%c %s Audio Stable = %d')
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_Set_AudStatus @ 0xa009c7e8, flags -mcpu=v8 -Os -g.
 * Source form: port is a raw unsigned int parameter cast to unsigned char at each use; the record is
 * indexed directly in each access.
 */
#define RX21_RECORD_SIZE 400        /* bytes per entry of hdmi_rx21_input_records */
#define RX21_AUDIO_STABLE 5         /* byte +5 of the receiver record */
#define RX21_AUDIO_STATUS 0x38      /* audio status block filled by hdmi_rx21_read_audio_status */
#define HDMI_MSG_MODEDET_FLOW 4 /* debug message bit: '[MODEDET]' lines (dbg_hdmi_message_flags) */

extern unsigned int dbg_hdmi_message_flags;
extern unsigned char hdmi_rx21_input_records[];
extern int dbg_printf(const char *, ...);
extern void hdmi_rx21_read_audio_status(unsigned int, unsigned int *);
extern void hdmi_rx21_set_audio_mute(unsigned char, unsigned char);
static const char fn_[] = "DRV_HDMI_Set_AudStatus";

/* Records whether the audio of a receiver is stable and sets the audio mute to match. With on == 1 it
 * sets the receiver record's stable byte and has the audio status block (record +0x38) filled in;
 * otherwise it clears the byte. Finally the audio mute is set when on is 0 and cleared when on is 1.
 *   port: receiver (the letter in the print is 'A' + port)
 *   on:   1 = audio stable */
void DRV_HDMI_Set_AudStatus(unsigned int port, unsigned char on)
{
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: Port%c %s Audio Stable = %d\n", (char)(port + 0x41), fn_, on);
    if (on == 1) {
        hdmi_rx21_input_records[(unsigned char)port * RX21_RECORD_SIZE + RX21_AUDIO_STABLE] = 1;
        hdmi_rx21_read_audio_status((unsigned char)port, (unsigned int *)(hdmi_rx21_input_records + (unsigned char)port * RX21_RECORD_SIZE + RX21_AUDIO_STATUS));
    } else
        hdmi_rx21_input_records[(unsigned char)port * RX21_RECORD_SIZE + RX21_AUDIO_STABLE] = 0;
    hdmi_rx21_set_audio_mute(port, on == 0);
}
