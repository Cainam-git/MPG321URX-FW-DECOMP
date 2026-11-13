/* hdmi_rx21_read_audio_status  (FUN_a009c718)
 *
 * Collect the audio status fields of an HDMI 2.1 receiver into a block.
 *   port: HDMI 2.1 receiver 0/1
 *   status: destination block
 * Name basis: derived - fills record +0x38 when DRV_HDMI_Set_AudStatus marks audio stable; includes the
 *   sample-rate code
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c718 @ 0xa009c718 (-mcpu=v8 -Os -g)
 * The four status routines called for fields 4 and 5 take one argument (only %o0 is set before the calls).
 * Source form: the destination is a struct whose four words are stored from the callees' low bytes (fields 0 and 1)
 * and full results (fields 2 and 3); the status30_bit4 routine is called twice, the second result tests the
 * last field.
 */
/* The audio status block of a receiver (at +0x38 of its 400-byte record, hdmi_rx21_input_records). */
struct hdmi_rx21_audio_status {
    unsigned int bit17_clear;           /* hdmi_rx21_audio_bit17_is_clear */
    unsigned int freq_code;             /* hdmi_rx21_get_audio_freq_code */
    unsigned int n;                     /* audio clock regeneration N */
    unsigned int cts;                   /* audio clock regeneration CTS */
    unsigned char status30_bit4;        /* hdmi_rx21_status30_bit4 */
    unsigned char status70_bit17;       /* hdmi_rx21_status70_bit17, 0 when status30_bit4 is 0 */
};

extern unsigned int hdmi_rx21_status30_bit4(unsigned int);
extern unsigned int hdmi_rx21_audio_bit17_is_clear(unsigned int);
extern unsigned int hdmi_rx21_get_audio_freq_code(unsigned int);
extern unsigned int hdmi_rx21_read_audio_n(unsigned int);
extern unsigned int hdmi_rx21_read_audio_cts(unsigned int);
extern unsigned int hdmi_rx21_status70_bit17(unsigned int);

/*
 * Fill an audio status block with the audio fields of an HDMI 2.1 receiver (see struct hdmi_rx21_audio_status).
 * The last field is read only when the status30 bit is set, otherwise it is 0.
 *   port: HDMI 2.1 receiver 0/1
 *   status: the block to fill
 * Called by DRV_HDMI_Set_AudStatus when the audio is marked stable.
 */
void hdmi_rx21_read_audio_status(unsigned int port, struct hdmi_rx21_audio_status *status)
{
    unsigned int receiver;
    unsigned int status30_bit4;

    receiver = port & 0xff;
    status->bit17_clear = hdmi_rx21_audio_bit17_is_clear(receiver) & 0xff;
    status->freq_code = hdmi_rx21_get_audio_freq_code(receiver) & 0xff;
    status->n = hdmi_rx21_read_audio_n(receiver);
    status->cts = hdmi_rx21_read_audio_cts(receiver);
    status->status30_bit4 = (unsigned char)hdmi_rx21_status30_bit4(receiver);
    status30_bit4 = hdmi_rx21_status30_bit4(receiver);
    if ((status30_bit4 & 0xff) != 0) {
        status->status70_bit17 = 
            (unsigned char)hdmi_rx21_status70_bit17(receiver);
    } else {
        status->status70_bit17 = 0;
    }
}
