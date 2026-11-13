/* hdmi_rx21_read_spd_infoframe  (FUN_a009fcb8)
 *
 * Read the standard SPD (source product) InfoFrame of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 *   spd: 0x24-byte block
 * Returns: 0 when read, 1 when absent
 * Name basis: proven - packet type 0x83 (SPD); a packet whose first data word has the low 24 bits 0x00001A is
 *   not read; result 1 makes FSM_Complete print 'No StdSPD Info'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009fcb8 @ 0xa009fcb8-0xa009fe2c, flags -mcpu=v8 -Os -g.
 * Source form: every register word is read through hdmi_rx21_reg_blocks[port].block1 at its use (volatile, so the
 * firmware loads the block pointer and the word each time); the three conditions are one && expression.
 */

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers). This routine reads block 1 only. */
struct rx21_reg_blocks {
    unsigned int block0;
    volatile unsigned int *block1;
    unsigned char blocks_2_to_12[0x34 - 8];
};

/* The SPD block of a receiver record (0x24 bytes at record +0xEC). */
struct spd_info {
    unsigned char packet_byte1;         /* bits 8..15 of the header word; the data below is copied only when 1 */
    unsigned char data[0x1b];           /* data[0..23] = data words 0..5, low byte first */
    unsigned int data6_low;             /* low byte of data word 6 */
    unsigned char status[4];            /* kept by the callers (+0x20 .. +0x22); cleared here when absent */
};

#define SPD_TYPE_CODE     0x83          /* low byte of the header word when the receiver holds SPD data */
#define SPD_EXCLUDED_ID   0x1a          /* low 24 bits of data word 0: such a packet is not read here */
#define SPD_INFO_SIZE     0x24

/* Word offsets of the SPD data in register block 1. */
#define SPD_REG_HEADER    (0x60 / 4)    /* bits 0..7 type code, 8..15 packet_byte1, 16..23 must be non-zero */
#define SPD_REG_DATA0     (0x64 / 4)
#define SPD_REG_DATA1     (0x68 / 4)
#define SPD_REG_DATA2     (0x6c / 4)
#define SPD_REG_DATA3     (0x70 / 4)
#define SPD_REG_DATA4     (0x74 / 4)
#define SPD_REG_DATA5     (0x78 / 4)
#define SPD_REG_DATA6     (0x7c / 4)

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern void *lib_memset(void *, int, unsigned int);

/*
 * Copy the SPD InfoFrame that HDMI 2.1 receiver `port` holds in register block 1 into `spd`.
 *
 *   port  HDMI 2.1 receiver 0 or 1
 *   spd   the receiver's SPD block (receiver record +0xEC)
 *
 * Returns 0 when the data was taken, 1 when the block holds no SPD data of the kind read here (`spd`, with
 * its status bytes, is then cleared).
 *
 * The header word must carry type code 0x83 and a non-zero byte 2, and the low 24 bits of data word 0 must not
 * be 0x00001A; hdmi_rx21_on_spd_packet handles that case itself and calls this routine only for the others.
 * The header's byte 1 is always stored; the data bytes only when it is 1 (otherwise they keep their old values
 * and 0 is returned all the same).
 *
 * Called by DRV_HDMI_ModeDetect_FSM_Complete, which prints 'No StdSPD Info' on 1, and by
 * hdmi_rx21_on_spd_packet; both only while status byte +0x22 of the block is 0.
 */
int hdmi_rx21_read_spd_infoframe(unsigned char port, struct spd_info *spd)
{
    unsigned int header, data;

    header = hdmi_rx21_reg_blocks[port].block1[SPD_REG_HEADER];
    if ((header & 0xff) == SPD_TYPE_CODE && ((header >> 16) & 0xff) != 0 && (hdmi_rx21_reg_blocks[port].block1[SPD_REG_DATA0] & 0xffffff) != SPD_EXCLUDED_ID) {
        spd->packet_byte1 = header >> 8;
        if (((header >> 8) & 0xff) == 1) {
            data = hdmi_rx21_reg_blocks[port].block1[SPD_REG_DATA0];
            spd->data[0x0] = data;
            spd->data[0x1] = data >> 8;
            spd->data[0x2] = data >> 16;
            spd->data[0x3] = data >> 24;
            data = hdmi_rx21_reg_blocks[port].block1[SPD_REG_DATA1];
            spd->data[0x4] = data;
            spd->data[0x5] = data >> 8;
            spd->data[0x6] = data >> 16;
            spd->data[0x7] = data >> 24;
            data = hdmi_rx21_reg_blocks[port].block1[SPD_REG_DATA2];
            spd->data[0x8] = data;
            spd->data[0x9] = data >> 8;
            spd->data[0xa] = data >> 16;
            spd->data[0xb] = data >> 24;
            data = hdmi_rx21_reg_blocks[port].block1[SPD_REG_DATA3];
            spd->data[0xc] = data;
            spd->data[0xd] = data >> 8;
            spd->data[0xe] = data >> 16;
            spd->data[0xf] = data >> 24;
            data = hdmi_rx21_reg_blocks[port].block1[SPD_REG_DATA4];
            spd->data[0x10] = data;
            spd->data[0x11] = data >> 8;
            spd->data[0x12] = data >> 16;
            spd->data[0x13] = data >> 24;
            data = hdmi_rx21_reg_blocks[port].block1[SPD_REG_DATA5];
            spd->data[0x14] = data;
            spd->data[0x15] = data >> 8;
            spd->data[0x16] = data >> 16;
            spd->data[0x17] = data >> 24;
            spd->data6_low =hdmi_rx21_reg_blocks[port].block1[SPD_REG_DATA6] & 0xff;
        }
    } else {
        lib_memset(spd, 0, SPD_INFO_SIZE);
        return 1;
    }
    return 0;
}
