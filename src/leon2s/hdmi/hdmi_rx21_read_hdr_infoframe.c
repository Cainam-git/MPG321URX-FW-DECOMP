/* hdmi_rx21_read_hdr_infoframe  (FUN_a009fed0)
 *
 * Read and decode the HDR mastering InfoFrame of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 *   d: 0x48-byte block
 * Returns: 0 when read, 1 when absent
 * Name basis: proven - packet type 0x87 version 1 (Dynamic Range and Mastering); sorts the primaries; 'No HDR
 *   Info Frame'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009fed0 @ 0xa009fed0-0xa00a0268 (920 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - K&R definition (unsigned char port), int result;
 *  - eotf_type / metadata_id declared unsigned long (their own alias set, so the stores move past the volatile
 *    register reads as in the firmware);
 *  - the failure arm as the else of the success test, with all record stores after the if;
 *  - `second` given its default 0 before the last test in the third case;
 *  - the byte stores of each data word in the order of this file.
 */

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers): block k of receiver n is at 0xCE009000 + n * 0x1000 + k * 0x100.
   This routine reads block 5 only. */
struct rx21_reg_blocks {
    unsigned char blocks_0_to_4[0x14];
    volatile unsigned int *block5;
    unsigned char blocks_6_to_12[0x34 - 0x18];
};

/* One entry of the firmware's value/text lists: a field value and the address of its printable name. */
struct value_text { unsigned int value; unsigned int text; };

/* The decoded HDR data: 0x48 bytes at +0x114 of the receiver's record (hdmi_rx21_input_records). */
struct hdr_info {
    unsigned char read_ok;              /* 1 after a successful read */
    unsigned char _1[3];
    unsigned long eotf_type;            /* EN_EOTF_TYPE_TSDR / THDR / ST2084 / HLG (hdmi_rx21_hdr_eotf_names) */
    unsigned long metadata_id;          /* EN_MD_ID_TYPE1 / EN_MD_ID_RESERVED (hdmi_rx21_hdr_metadata_id_names) */
    /* The three (x, y) pairs of data words 1..4, in sorted order (see the routine). */
    unsigned short pair1_x, pair1_y, pair2_x, pair2_y, pair3_x, pair3_y;
    /* The halves after the pairs, in the order received. hdr_static_info, whose fields at +4, +0x1C and +0x20
       the firmware prints as enEOTF_Type, u16Max_MasterLum and u16MaxCLL, has its fields at the same offsets. */
    unsigned short half_0x18, half_0x1a, half_0x1c, half_0x1e, half_0x20, half_0x22;
    /* +0x24: the received bytes as they are (type code, header bytes 1..3, then 27 bytes of data words 1..7).
       +0x43..+0x45 are status bytes kept by the callers; this routine writes them only when it clears. */
    unsigned char raw[0x24];
};

#define HDR_TYPE_CODE     0x87          /* byte 0 of the header word when the receiver holds HDR data */
#define HDR_HEADER_BYTE1  1             /* the only accepted value of header byte 1 */
#define HDR_INFO_SIZE     0x48

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern const struct value_text hdmi_rx21_hdr_eotf_names[], hdmi_rx21_hdr_metadata_id_names[];
extern void *lib_memset(void *, int, unsigned int);

/*
 * Read the HDR data that HDMI 2.1 receiver `port` holds in words 0..7 of register block 5 and decode it into
 * `hdr`.
 *
 *   port  HDMI 2.1 receiver 0 or 1
 *   hdr   the receiver's HDR record (receiver record +0x114)
 *
 * Returns 0 when the data was read, 1 when the block holds no HDR data (`hdr` is then cleared).
 *
 * Called by DRV_HDMI_ModeDetect_FSM_Complete, which prints 'No HDR Info Frame' on 1, and by the packet-event
 * callback hdmi_rx21_on_hdr_infoframe.
 *
 * Phases:
 *   1. Header word 0: without type code 0x87 and byte 1 = 1 clear the record and stop.
 *   2. Look up eotf_type (word 1 bits 0..2) and metadata_id (word 1 bits 8..10, any non-zero value = 1) in
 *      their value/text lists. Both lists hold the index itself as value.
 *   3. Sort the three pairs: x = high halves of words 1..3, y = low halves of words 2..4. The pair with the
 *      largest x comes first; of the other two, the lower-numbered one comes second when its y is the largest of
 *      all three y values, else the higher-numbered one does; the last pair is third.
 *   4. Store read_ok, the sorted pairs, the six halves of words 4..7 and the raw bytes.
 */
int hdmi_rx21_read_hdr_infoframe(port, hdr)
    unsigned char port;
    struct hdr_info *hdr;
{
    volatile unsigned int *block5;
    unsigned short x[3];
    unsigned short y[3];
    unsigned char eotf_index, metadata_id_index, first, second;
    unsigned short half_0x18, half_0x1a, half_0x1c, half_0x1e, half_0x20, half_0x22;
    unsigned int data;

    /* Phase 1: header word. */
    block5 = hdmi_rx21_reg_blocks[port].block5;
    if ((block5[0] & 0xff) == HDR_TYPE_CODE && ((block5[0] >> 8) & 0xff) == HDR_HEADER_BYTE1) {
        /* Phase 2: the two listed fields. */
        eotf_index = block5[1] & 7;
        if (eotf_index > 3)
            eotf_index = 4;             /* EN_EOTF_TYPE_RESERVED */
        metadata_id_index = (block5[1] >> 8) & 7;
        hdr->eotf_type = hdmi_rx21_hdr_eotf_names[eotf_index].value;
        if (metadata_id_index != 0)
            metadata_id_index = 1;      /* EN_MD_ID_RESERVED */

        /* Phase 3: the three pairs and their order. */
        x[0] = block5[1] >> 16;
        x[1] = block5[2] >> 16;
        x[2] = block5[3] >> 16;
        y[0] = block5[2];
        y[1] = block5[3];
        y[2] = block5[4];
        hdr->metadata_id = hdmi_rx21_hdr_metadata_id_names[metadata_id_index].value;
        if (x[0] >= x[1] && x[0] >= x[2]) {
            first = 0;
            if (y[1] < y[0] || y[1] < y[2])
                second = 2;
            else
                second = 1;
        } else if (x[1] >= x[0] && x[1] >= x[2]) {
            first = 1;
            if (y[0] < y[1] || y[0] < y[2])
                second = 2;
            else
                second = 0;
        } else {
            first = 2;
            second = 0;
            if (y[0] < y[1] || y[0] < y[2])
                second = 1;
        }
        half_0x18 = hdmi_rx21_reg_blocks[port].block5[4] >> 16;
        half_0x1a = hdmi_rx21_reg_blocks[port].block5[5];
        half_0x1c = hdmi_rx21_reg_blocks[port].block5[5] >> 16;
        half_0x1e = hdmi_rx21_reg_blocks[port].block5[6];
        half_0x20 = hdmi_rx21_reg_blocks[port].block5[6] >> 16;
        half_0x22 = hdmi_rx21_reg_blocks[port].block5[7];
    } else {
        lib_memset(hdr, 0, HDR_INFO_SIZE);
        return 1;
    }

    /* Phase 4: store everything. The registers are read again for the raw bytes. */
    hdr->read_ok = 1;
    hdr->raw[0] = HDR_TYPE_CODE;
    hdr->raw[1] = hdmi_rx21_reg_blocks[port].block5[0] >> 8;
    hdr->raw[2] = hdmi_rx21_reg_blocks[port].block5[0] >> 16;
    hdr->pair1_x = x[first];
    hdr->pair1_y = y[first];
    hdr->pair2_x = x[second];
    hdr->pair2_y = y[second];
    hdr->pair3_x = x[3 - first - second];
    hdr->pair3_y = y[3 - first - second];
    hdr->half_0x18 = half_0x18;
    hdr->half_0x1a = half_0x1a;
    hdr->half_0x1c = half_0x1c;
    hdr->half_0x1e = half_0x1e;
    hdr->half_0x20 = half_0x20;
    hdr->half_0x22 = half_0x22;
    hdr->raw[3] = hdmi_rx21_reg_blocks[port].block5[0] >> 24;
    data = hdmi_rx21_reg_blocks[port].block5[1];
    hdr->raw[5] = data >> 8;
    hdr->raw[4] = data;
    hdr->raw[6] = data >> 16;
    hdr->raw[7] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block5[2];
    hdr->raw[9] = data >> 8;
    hdr->raw[10] = data >> 16;
    hdr->raw[8] = data;
    hdr->raw[11] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block5[3];
    hdr->raw[13] = data >> 8;
    hdr->raw[14] = data >> 16;
    hdr->raw[12] = data;
    hdr->raw[15] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block5[4];
    hdr->raw[17] = data >> 8;
    hdr->raw[18] = data >> 16;
    hdr->raw[16] = data;
    hdr->raw[19] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block5[5];
    hdr->raw[21] = data >> 8;
    hdr->raw[22] = data >> 16;
    hdr->raw[23] = data >> 24;
    hdr->raw[20] = data;
    data = hdmi_rx21_reg_blocks[port].block5[6];
    hdr->raw[24] = data;
    hdr->raw[25] = data >> 8;
    hdr->raw[26] = data >> 16;
    hdr->raw[27] = data >> 24;
    data = hdmi_rx21_reg_blocks[port].block5[7];
    hdr->raw[28] = data;
    hdr->raw[29] = data >> 8;
    hdr->raw[30] = data >> 16;
    return 0;
}
