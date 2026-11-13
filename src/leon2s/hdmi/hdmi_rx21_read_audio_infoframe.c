/* hdmi_rx21_read_audio_infoframe  (FUN_a009faf0)
 *
 * Read and decode the audio InfoFrame of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 *   audio: 0x30-byte block
 * Returns: 0 when read, 1 when absent
 * Name basis: proven - packet type 0x84 (audio InfoFrame) checked; result 1 makes FSM_Complete print 'No AUDIO
 *   Info'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009faf0 @ 0xa009faf0-0xa009fcb8 (456 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the data words 0 and 1 are read through the row pointer `row` taken after the header read, the header and
 *    data word 2 index hdmi_rx21_reg_blocks[port] directly;
 *  - the extra byte is written '(data & 0xff000000) >> 24';
 *  - the sample-size entry is read into `sample_size` after the read of data word 2;
 *  - the stores and reads are in the order of this file.
 */

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers). This routine reads block 1 only. */
struct rx21_reg_blocks {
    unsigned int block0;
    volatile unsigned int *block1;
    unsigned char blocks_2_to_12[0x34 - 8];
};

/* One entry of the firmware's value/text lists: a field value and the address of its printable name. */
struct value_text { unsigned int value; unsigned int text; };

/* The decoded audio InfoFrame: the first 0x2A bytes of the receiver record's audio block (record +0xBC). The
   fields decoded through a value/text list are named after the list; their texts are given with each field. */
struct audio_info {
    unsigned char packet_byte1;         /* bits 8..15 of the header word */
    unsigned char _1[3];
    unsigned int coding;                /* Refer To Stream Header, PCM, AC3 .. WMA-Pro, Refer To CXT */
    unsigned int channels;              /* Refer To Stream Header, 2 CH .. 8 CH */
    unsigned int sample_rate;           /* Refer To Stream Header, 32K .. 192K */
    unsigned int sample_size;           /* Refer To Stream Header, 16Bit, 20Bit, 24Bit */
    unsigned char byte_0x14;            /* bits 24..31 of data word 0 */
    unsigned char byte_0x15;            /* bits 3..6 of data word 1 */
    unsigned char _16[2];
    unsigned int permit;                /* Permitted, Prohibited (bit 7 of data word 1) */
    /* The received bytes as they are: the header word, data words 0 and 1, the low two bytes of data word 2. */
    unsigned char raw[14];
};

#define AUDIO_TYPE_CODE   0x84          /* low byte of the header word when the receiver holds audio InfoFrame data */
#define AUDIO_BLOCK_SIZE  0x30          /* cleared when absent: also covers the caller's status bytes +0x2A..+0x2C */

/* Word offsets of the audio InfoFrame in register block 1. */
#define AUDIO_REG_HEADER  (0x80 / 4)    /* bits 0..7 type code, 8..15 packet_byte1, 16..23 must be non-zero */
#define AUDIO_REG_DATA0   (0x84 / 4)
#define AUDIO_REG_DATA1   (0x88 / 4)
#define AUDIO_REG_DATA2   (0x8c / 4)

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern const struct value_text hdmi_rx21_audio_permit_names[];
extern const struct value_text hdmi_rx21_audio_sample_size_names[];
extern const struct value_text hdmi_rx21_audio_sample_rate_names[];
extern const struct value_text hdmi_rx21_audio_channel_names[];
extern const struct value_text hdmi_rx21_audio_coding_names[];
extern void *lib_memset(void *, int, unsigned int);

/*
 * Read the audio InfoFrame that HDMI 2.1 receiver `port` holds in register block 1 and decode it into `audio`.
 *
 *   port   HDMI 2.1 receiver 0 or 1
 *   audio  the receiver's audio block (receiver record +0xBC)
 *
 * Returns 0 when the data was read, 1 when the block holds no audio InfoFrame (`audio` and the three status
 * bytes behind it are then cleared).
 *
 * Called by DRV_HDMI_ModeDetect_FSM_Complete, which prints 'No AUDIO Info' on 1, and by
 * hdmi_rx21_on_audio_infoframe; both only while status byte +0x2C of the block is 0.
 *
 * Header word first: without type code 0x84 and a non-zero byte 2 nothing else is read. Then data word 0 gives
 * coding, channels, sample rate and sample size, data word 1 gives byte_0x15 and permit, and data word 2 only
 * its two low bytes. Each field is looked up in its value/text list with its bits as index; the lists hold the
 * index itself as value, so the fields store the bits unchanged. The index limits (15, or the list's last
 * entry 'Unknown') never change an index of the widths read here.
 */
unsigned char hdmi_rx21_read_audio_infoframe(unsigned char port, struct audio_info *audio)
{
    unsigned int header, data, permit_bit, sample_size;
    unsigned char coding, channels, sample_rate, size_index, permit;
    struct rx21_reg_blocks *row;

    header = hdmi_rx21_reg_blocks[port].block1[AUDIO_REG_HEADER];
    row = &hdmi_rx21_reg_blocks[port];
    audio->raw[0] = header;
    audio->raw[2] = header >> 16;
    if ((header & 0xff) == AUDIO_TYPE_CODE && ((header >> 16) & 0xff) != 0) {
        audio->raw[3] = header >> 24;
        data = row->block1[AUDIO_REG_DATA0];
        coding = (data & 0xf0) >> 4;
        audio->raw[4] = data;
        audio->packet_byte1 = header >> 8;
        audio->raw[5] = data >> 8;
        audio->raw[6] = data >> 16;
        audio->raw[7] = data >> 24;
        audio->raw[1] = header >> 8;
        if (coding > 14)
            coding = 15;
        audio->coding = hdmi_rx21_audio_coding_names[coding].value;
        channels = data & 7;
        if (channels > 7)
            channels = 8;
        audio->channels = hdmi_rx21_audio_channel_names[channels].value;
        sample_rate = (data >> 10) & 7;
        if (sample_rate > 7)
            sample_rate = 8;
        audio->sample_rate = hdmi_rx21_audio_sample_rate_names[sample_rate].value;
        size_index = (data & 0x300) >> 8;
        if (size_index > 3)
            size_index = 4;
    } else {
        /* No audio InfoFrame held. */
        lib_memset(audio, 0, AUDIO_BLOCK_SIZE);
        return 1;
    }
    audio->byte_0x14 = (data & 0xff000000) >> 24;
    data = row->block1[AUDIO_REG_DATA1];
    audio->raw[8] = data;
    audio->raw[9] = data >> 8;
    audio->raw[10] = data >> 16;
    audio->raw[11] = data >> 24;
    permit_bit = data & 0x80;
    audio->byte_0x15 = (data & 0x78) >> 3;
    permit = permit_bit >> 7;
    data = hdmi_rx21_reg_blocks[port].block1[AUDIO_REG_DATA2];
    sample_size = hdmi_rx21_audio_sample_size_names[size_index].value;
    if (permit > 1)
        permit = 2;
    audio->sample_size = sample_size;
    audio->raw[12] = data;
    audio->permit = hdmi_rx21_audio_permit_names[permit].value;
    audio->raw[13] = data >> 8;
    return 0;
}
