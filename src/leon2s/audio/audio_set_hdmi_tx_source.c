/* audio_set_hdmi_tx_source  (FUN_a0091ebc)
 *
 * Store the audio source of an HDMI TX port and reset its audio input.
 *   channel: HDMI TX port
 *   source: source id
 * Name basis: derived - record byte +2; called by audio_set_output_source for audio outputs 2/3 = HDMI TX 0/1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091ebc @ 0xa0091ebc-0xa0091eec (12 words), flags -mcpu=v8 -Os -g.
 * Leaf routine ending in a tail call. The base hdmi_tx_output_records is the table of 0x1c-byte channel records; only
 * the byte at +2 is used. The compiled object has a trailing alignment nop after the range.
 */
/* The 0x1c-byte record of an HDMI TX channel; only audio_source is used here. */
struct hdmi_tx_channel_record {
    unsigned char byte_0;
    unsigned char source_code;          /* +1 */
    unsigned char audio_source;         /* +2 */
    unsigned char byte_3;
    unsigned int  words[6];             /* +4 .. +0x1b */
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern void hdmi_tx_reset_audio_regs(unsigned char, unsigned char);

/*
 * Store the audio source of an HDMI TX port in its channel record, then call hdmi_tx_reset_audio_regs with the
 * same two values.
 *   channel: HDMI TX port
 *   source:  audio source id
 */
void audio_set_hdmi_tx_source(unsigned char channel, unsigned char source)
{
    hdmi_tx_output_records[channel].audio_source = source;
    hdmi_tx_reset_audio_regs(channel, source);
}
