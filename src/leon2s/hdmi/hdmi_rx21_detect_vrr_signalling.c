/* hdmi_rx21_detect_vrr_signalling  (FUN_a00974ec)
 *
 * Store the variable refresh rate flags of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - SPD type 0x83 with id 0x00001A (AMD FreeSync) and VTEM bits; twin of
 *   hdmi_detect_vrr_signalling
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00974ec @ 0xa00974ec-0xa0097680 (404 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the version test for 2 and 3 is (unsigned char)(version - 2) <= 1;
 * the bit-5 test of SPD word +0x6C has the set arm first; bit 13 of word +0x68 is tested as bit 5 of the byte
 * (word >> 8); the flags are stored through a byte array index (port * 400 + 6). The register blocks are
 * volatile (hardware).
 */
/* One row per HDMI 2.1 receiver (hdmi_rx21_reg_blocks): the addresses of its register blocks (block k =
   0xCE009000 + rx * 0x1000 + k * 0x100). Only blocks 1 and 5 are read here. */
struct hdmi_rx21_reg_blocks {
    unsigned int block0;
    volatile unsigned int *block1;      /* +4: holds the SPD packet bytes at +0x60..+0x6F */
    unsigned char blocks_2_to_4[0xc];
    volatile unsigned int *block5;      /* +0x14: holds the vendor packet bytes at +0x50..+0x5F */
    unsigned char blocks_6_to_12[0x34 - 0x18];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_rx21_input_records[];    /* struct rx21_record, 400 bytes per receiver */

#define RX21_RECORD_SIZE        400
#define RX21_RECORD_VRR_FLAGS   6       /* byte +6: vrr_flags */

/* Packet words, four packet bytes each (byte n of the packet = bits 8 * (n % 4) of word n / 4). They hold the
   same packet bytes that hdmi_detect_vrr_signalling reads from registers 0x160.. and 0x360.. of a 2.0
   receiver. */
#define SPD_WORD_0      (0x60 / 4)      /* byte 0: packet type, byte 1: version */
#define SPD_WORD_1      (0x64 / 4)      /* bytes 4..6: id */
#define SPD_WORD_2      (0x68 / 4)      /* byte 9 (bits 8..15): bit 0 and bit 5 tested */
#define SPD_WORD_3      (0x6c / 4)      /* byte 12 (bits 0..7): bit 5 tested */
#define VTEM_WORD_0     (0x50 / 4)      /* byte 0: packet type; byte 3 bits 0..5 */
#define VTEM_WORD_1     (0x54 / 4)      /* bytes 4..7 must read 00 01 00 01 */
#define VTEM_WORD_2     (0x58 / 4)      /* byte 10 (bits 16..23): bits 0..1 = mode */

#define INFOFRAME_TYPE_SPD  0x83
#define SPD_ID              0x1a        /* id bytes 1A 00 00 */
#define VTEM_TYPE           0x7f

/* Bits of the result, as in hdmi_detect_vrr_signalling. */
#define VRR_SPD_BIT0        0x01        /* SPD byte 9 bit 0 */
#define VRR_SPD_BIT1        0x02        /* SPD byte 12 bit 5 set */
#define VRR_VTEM_MODE_1     0x04        /* vendor packet mode 1; replaces every other bit */
#define VRR_VTEM_MODE_3     0x08        /* vendor packet mode 3; replaces every other bit */
#define VRR_SPD_BIT4        0x10        /* SPD byte 12 bit 5 clear, or byte 9 bit 5 clear */

/*
 * The HDMI 2.1 twin of hdmi_detect_vrr_signalling: the same tests on the packet bytes that HDMI 2.1 receiver
 * 'port' holds in its register blocks; the result is stored in vrr_flags (+6) of the receiver's rx21_record
 * instead of being returned. Called by FSM_MODE_DETECT_STANDBY and hdmi_rx21_modedet_watch_stable. While
 * vrr_flags is not 0, FSM_MODE_DETECT_STANDBY accepts any V_Total difference between two passes, and
 * DRV_HDMI_ModeDetect_FSM_Complete sets the receiver's timing change flag.
 *
 *   port   HDMI 2.1 receiver 0 or 1
 *
 * SPD packet (type 0x83 with id 1A 00 00):
 *   version 1:       VRR_SPD_BIT0 when byte 9 bit 0 is set;
 *   version 2 or 3:  the same, then byte 12 bit 5 set gives VRR_SPD_BIT1 plus VRR_SPD_BIT4 unless byte 9
 *                    bit 5 is set; byte 12 bit 5 clear gives VRR_SPD_BIT4.
 * Vendor packet (type 0x7F, byte 3 & 0x3F = 4, bytes 4..7 = 00 01 00 01): mode 1 or 3 in byte 10 replaces
 * everything found so far with VRR_VTEM_MODE_1 or VRR_VTEM_MODE_3.
 */
void hdmi_rx21_detect_vrr_signalling(unsigned char port)
{
    unsigned char flags = 0;
    unsigned int word;
    unsigned int version_word;
    unsigned int vtem_mode;

    word = ARR_a807db00[port].block1[SPD_WORD_0];
    if ((word & 0xff) == INFOFRAME_TYPE_SPD && (ARR_a807db00[port].block1[SPD_WORD_1] & 0xffffff) == SPD_ID) {
        version_word = word >> 8;
        if ((version_word & 0xff) == 1 && (ARR_a807db00[port].block1[SPD_WORD_2] & 0x100))
            flags = VRR_SPD_BIT0;
        if ((unsigned char)(version_word - 2) <= 1) {
            if (ARR_a807db00[port].block1[SPD_WORD_2] & 0x100)
                flags = VRR_SPD_BIT0;
            if (ARR_a807db00[port].block1[SPD_WORD_3] & 0x20) {
                flags |= VRR_SPD_BIT1;
                if ((unsigned char)(ARR_a807db00[port].block1[SPD_WORD_2] >> 8) & 0x20)
                    flags &= ~VRR_SPD_BIT4;
                else
                    flags |= VRR_SPD_BIT4;
            } else
                flags |= VRR_SPD_BIT4;
        }
    }
    word = ARR_a807db00[port].block5[VTEM_WORD_0];
    if ((word & 0xff) == VTEM_TYPE && ((word >> 24) & 0x3f) == 4) {
        word = ARR_a807db00[port].block5[VTEM_WORD_1];
        if ((word & 0xff) == 0 && ((word >> 8) & 0xff) == 1 && ((word >> 16) & 0xff) == 0 && (word >> 24) == 1) {
            word = ARR_a807db00[port].block5[VTEM_WORD_2];
            vtem_mode = (word >> 16) & 3;
            if (vtem_mode == 1)
                flags = VRR_VTEM_MODE_1;
            else if (vtem_mode == 3)
                flags = VRR_VTEM_MODE_3;
        }
    }
    hdmi_rx21_input_records[port * RX21_RECORD_SIZE + RX21_RECORD_VRR_FLAGS] = flags;
}
