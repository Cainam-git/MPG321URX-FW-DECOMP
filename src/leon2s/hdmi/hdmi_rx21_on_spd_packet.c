/* hdmi_rx21_on_spd_packet  (FUN_a00a13a0)
 *
 * Store the AMD FreeSync data or the standard SPD InfoFrame of an HDMI 2.1 receiver.
 *   port: receiver
 * Name basis: derived - OUI 0x00001A (AMD) -> FreeSync bits to record +0x15C..; else
 *   hdmi_rx21_read_spd_infoframe
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a13a0, flags -mcpu=v8 -Os -g (section default). Stores are in the order written. The record is a
 * flat byte array indexed [port][offset].
 */
/* Offsets in the 400-byte record of a receiver (hdmi_rx21_input_records). */
#define RX21_SPD_INFOFRAME    0xec      /* SPD InfoFrame block; ends in three status bytes */
#define RX21_SPD_SEEN         0x10c
#define RX21_SPD_UPDATE       0x10d
#define RX21_SPD_HOLD         0x10e
#define RX21_FREESYNC_FOUND   0x15c     /* 1 when the vendor id matched, else 0 */
#define RX21_FREESYNC_BIT0    0x15d     /* bits 0..2 of byte 1 of the vendor data word */
#define RX21_FREESYNC_BIT1    0x15e
#define RX21_FREESYNC_BIT2    0x15f
#define RX21_FREESYNC_BYTE2   0x160     /* byte 2 of the vendor data word */
#define RX21_FREESYNC_BYTE3   0x161     /* byte 3 */

#define VENDOR_ID_AMD         0x1a      /* low 24 bits of word 0x19: vendor id 0x00001A (AMD, FreeSync) */

/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct rx21_reg_blocks {
    unsigned int block0_addr;           /* +0 */
    volatile unsigned int *block1;      /* +4: 0xCE009100 (+0x1000 for receiver 1) */
    unsigned char blocks_2_to_12[0x34 - 8];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_rx21_input_records[][0x190];
extern void hdmi_rx21_read_spd_infoframe(unsigned char, unsigned char *);
extern void hdmi_rx21_set_event_reg78_bit(unsigned char, int, int);

/*
 * Packet callback for the SPD packet of receiver `port` (event 0x11, slot 1 in
 * hdmi_rx21_service_packet_events). Word 0x19 of register block 1 holds the vendor id in its low 24 bits.
 * When it is 0x00001A, the FreeSync fields of the record are filled from word 0x1A of the block and
 * RX21_FREESYNC_FOUND is set to 1. Otherwise the SPD status bytes seen and update are set to 1, the SPD
 * InfoFrame is read with hdmi_rx21_read_spd_infoframe unless hold is set, and RX21_FREESYNC_FOUND is set
 * to 0. At the end bit 0x11 of the event word 0x78 is cleared in both cases.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_on_spd_packet(unsigned char port)
{
  volatile unsigned int *block1 = hdmi_rx21_reg_blocks[port].block1;
  unsigned int data;

  data = block1[0x18];
  if ((block1[0x19] & 0xffffff) == VENDOR_ID_AMD)
  {
    data = block1[0x1a];
    hdmi_rx21_input_records[port][RX21_FREESYNC_BYTE2] = data >> 16;
    hdmi_rx21_input_records[port][RX21_FREESYNC_BYTE3] = data >> 24;
    hdmi_rx21_input_records[port][RX21_FREESYNC_BIT0] = (data >> 8) & 1;
    hdmi_rx21_input_records[port][RX21_FREESYNC_BIT1] = (((data >> 8) & 0xff) >> 1) & 1;
    hdmi_rx21_input_records[port][RX21_FREESYNC_BIT2] = (((data >> 8) & 0xff) >> 2) & 1;
    hdmi_rx21_input_records[port][RX21_FREESYNC_FOUND] = 1;
  }
  else
  {
    hdmi_rx21_input_records[port][RX21_SPD_SEEN] = 1;
    hdmi_rx21_input_records[port][RX21_SPD_UPDATE] = 1;
    if (hdmi_rx21_input_records[port][RX21_SPD_HOLD] == 0)
    {
      hdmi_rx21_read_spd_infoframe(port, hdmi_rx21_input_records[port] + RX21_SPD_INFOFRAME);
    }
    hdmi_rx21_input_records[port][RX21_FREESYNC_FOUND] = 0;
  }
  hdmi_rx21_set_event_reg78_bit(port, 0x11, 0);
}
