/* hdmi_rx21_read_audio_stream_packet  (FUN_a00a0268)
 *
 * Copy the audio stream packet bytes of an HDMI 2.1 receiver into a buffer.
 *   port: HDMI 2.1 receiver 0/1
 *   bytes: byte buffer
 * Returns: 0 when read, 1 when absent
 * Name basis: derived - fifth packet read by FSM_Complete, whose failure prints 'No AUD Stream'; 31 bytes from
 *   registers 0x80..0x9C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0268 @ 0xa00a0268-0xa00a03c8, flags -mcpu=v8 -Os -g.
 * Source form: every register word is read through hdmi_rx21_reg_blocks[port].block2 at its use (volatile: the
 * firmware reads word 0x80 twice, once for the test and once for the copy).
 */

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers). This routine reads block 2 only. */
struct rx21_reg_blocks {
    unsigned int block0;
    unsigned int block1;
    volatile unsigned int *block2;
    unsigned char blocks_3_to_12[0x34 - 0xc];
};

#define AUDIO_STREAM_BLOCK_SIZE  0x22   /* 0x1F data bytes and the callers' three status bytes behind them */

/* Word offsets of the packet in register block 2: eight words, of which the last gives three bytes. */
#define STREAM_REG_WORD0  (0x80 / 4)    /* low byte 0: no packet held */
#define STREAM_REG_WORD1  (0x84 / 4)
#define STREAM_REG_WORD2  (0x88 / 4)
#define STREAM_REG_WORD3  (0x8c / 4)
#define STREAM_REG_WORD4  (0x90 / 4)
#define STREAM_REG_WORD5  (0x94 / 4)
#define STREAM_REG_WORD6  (0x98 / 4)
#define STREAM_REG_WORD7  (0x9c / 4)

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern void *lib_memset(void *, int, unsigned int);

/*
 * Copy the packet that HDMI 2.1 receiver `port` holds at words 0x80..0x9C of register block 2 into `bytes`.
 *
 *   port   HDMI 2.1 receiver 0 or 1
 *   bytes  the receiver's audio stream block (receiver record +0x162): 0x1F bytes, low byte of each word first
 *
 * Returns 0 when the bytes were copied, 1 when the low byte of word 0x80 is 0 (the block and its three status
 * bytes are then cleared). Nothing is decoded here.
 *
 * Called by DRV_HDMI_ModeDetect_FSM_Complete, which prints 'No AUD Stream' on 1, and by
 * hdmi_rx21_on_audio_stream_packet.
 */
int hdmi_rx21_read_audio_stream_packet(unsigned char port, unsigned char *bytes)
{
    unsigned int data;

    if ((hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD0] & 0xff) == 0) {
    lib_memset(bytes, 0, AUDIO_STREAM_BLOCK_SIZE);
    return 1;
    }
    data = hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD0];
    bytes[0x0] = data;
    bytes[0x1] = data >> 8;
    bytes[0x2] = data >> 16;
    bytes[0x3] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD1];
    bytes[0x4] = data;
    bytes[0x5] = data >> 8;
    bytes[0x6] = data >> 16;
    bytes[0x7] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD2];
    bytes[0x8] = data;
    bytes[0x9] = data >> 8;
    bytes[0xa] = data >> 16;
    bytes[0xb] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD3];
    bytes[0xc] = data;
    bytes[0xd] = data >> 8;
    bytes[0xe] = data >> 16;
    bytes[0xf] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD4];
    bytes[0x10] = data;
    bytes[0x11] = data >> 8;
    bytes[0x12] = data >> 16;
    bytes[0x13] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD5];
    bytes[0x14] = data;
    bytes[0x15] = data >> 8;
    bytes[0x16] = data >> 16;
    bytes[0x17] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD6];
    bytes[0x18] = data;
    bytes[0x19] = data >> 8;
    bytes[0x1a] = data >> 16;
    bytes[0x1b] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block2[STREAM_REG_WORD7];
    bytes[0x1c] = data;
    bytes[0x1d] = data >> 8;
    bytes[0x1e] = data >> 16;
    return 0;
}
