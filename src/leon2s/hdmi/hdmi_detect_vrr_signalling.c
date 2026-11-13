/* hdmi_detect_vrr_signalling  (FUN_a008f79c)
 *
 * Return the variable refresh rate flags of an HDMI receiver, read from two received packets.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: flag bits
 * Name basis: derived - packet bytes 0x164..0x166 = 1A 00 00 with version 1..3 and its bits; packet type 0x7F
 *   at 0x360 with 00 01 00 01 at 0x364..0x367; caller stores the result in the port flags
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f79c @ 0xa008f79c, flags -mcpu=v8 -Os (section default).
 * Source form: the test of register 0x16C is written as: bit set -> { flag 2; flag 0x10 cleared when 0x169 bit 5
 * is set, else set }, bit clear -> flag 0x10 set (other orders lose the firmware's branch delay-slot shape).
 */
extern unsigned int hdmi_reg_read8(unsigned int param_1, unsigned short param_2);

/* The SPD packet area is at register 0x160 (see hdmi_capture_spd_packet): 0x161 is its second header byte,
   0x164..0x166 the first three data bytes. */
#define RX_SPD_VERSION      0x161
#define RX_SPD_ID_0         0x164
#define RX_SPD_ID_1         0x165
#define RX_SPD_ID_2         0x166
#define RX_SPD_DATA_5       0x169
#define RX_SPD_DATA_12      0x16c
#define SPD_ID_BYTE_0       0x1a        /* the id is 1A 00 00 */

/* The vendor packet area is at register 0x360 (type byte 0x7F). */
#define RX_VTEM_TYPE        0x360
#define RX_VTEM_HEADER_3    0x363
#define RX_VTEM_DATA_0      0x364       /* 0x364..0x367 must read 00 01 00 01 */
#define RX_VTEM_DATA_1      0x365
#define RX_VTEM_DATA_2      0x366
#define RX_VTEM_DATA_3      0x367
#define RX_VTEM_DATA_6      0x36a
#define VTEM_TYPE           0x7f

/* Bits of the result. hdmi_update_port_status_flags turns them into the port's published flags: bit 0 or 2 into
   flag bit 2 (the one the main program sees), bit 1 into bit 3, bit 4 into bit 4, bit 3 into bit 7. */
#define VRR_SPD_BIT0        0x01        /* SPD data byte 5 bit 0 */
#define VRR_SPD_BIT1        0x02        /* SPD data byte 12 bit 5 set */
#define VRR_VTEM_MODE_1     0x04        /* VTEM data byte 6 bits 0..1 = 1; replaces every other bit */
#define VRR_VTEM_MODE_3     0x08        /* VTEM data byte 6 bits 0..1 = 3; replaces every other bit */
#define VRR_SPD_BIT4        0x10        /* SPD data byte 12 bit 5 clear, or data byte 5 bit 5 clear */

/* Look at the SPD packet and at the vendor packet that the receiver holds.
   SPD: when its data starts with 1A 00 00 and its version byte (0x161) is 1, bit 0 of register 0x169 gives
   VRR_SPD_BIT0; for version 2 or 3 the same bit is or-ed in, and register 0x16C bit 5 decides between
   VRR_SPD_BIT1 (set; VRR_SPD_BIT4 is added unless register 0x169 bit 5 is set) and VRR_SPD_BIT4 (clear).
   Vendor packet: when register 0x360 is 0x7F, 0x363 & 0x3F is 4 and 0x364..0x367 are 00 01 00 01, register
   0x36A bits 0..1 = 1 gives VRR_VTEM_MODE_1 and = 3 gives VRR_VTEM_MODE_3, replacing what the SPD part found. */
unsigned char hdmi_detect_vrr_signalling(unsigned char port)
{
    unsigned char flags = 0;

    if ((unsigned char)hdmi_reg_read8(port, RX_SPD_ID_0) == SPD_ID_BYTE_0
        && (unsigned char)hdmi_reg_read8(port, RX_SPD_ID_1) == 0
        && (unsigned char)hdmi_reg_read8(port, RX_SPD_ID_2) == 0) {
        if ((unsigned char)hdmi_reg_read8(port, RX_SPD_VERSION) == 1) {
            if (hdmi_reg_read8(port, RX_SPD_DATA_5) & 1) flags = VRR_SPD_BIT0;
        }
        if ((unsigned char)hdmi_reg_read8(port, RX_SPD_VERSION) == 2
            || (unsigned char)hdmi_reg_read8(port, RX_SPD_VERSION) == 3) {
            if (hdmi_reg_read8(port, RX_SPD_DATA_5) & 1) flags |= VRR_SPD_BIT0;
            if (hdmi_reg_read8(port, RX_SPD_DATA_12) & 0x20) {
                flags |= VRR_SPD_BIT1;
                if (hdmi_reg_read8(port, RX_SPD_DATA_5) & 0x20) flags &= ~VRR_SPD_BIT4;
                else flags |= VRR_SPD_BIT4;
            } else flags |= VRR_SPD_BIT4;
        }
    }
    if ((unsigned char)hdmi_reg_read8(port, RX_VTEM_TYPE) == VTEM_TYPE
        && (hdmi_reg_read8(port, RX_VTEM_HEADER_3) & 0x3f) == 4
        && (unsigned char)hdmi_reg_read8(port, RX_VTEM_DATA_0) == 0
        && (unsigned char)hdmi_reg_read8(port, RX_VTEM_DATA_1) == 1
        && (unsigned char)hdmi_reg_read8(port, RX_VTEM_DATA_2) == 0
        && (unsigned char)hdmi_reg_read8(port, RX_VTEM_DATA_3) == 1) {
        if ((hdmi_reg_read8(port, RX_VTEM_DATA_6) & 3) == 1) flags = VRR_VTEM_MODE_1;
        else if ((hdmi_reg_read8(port, RX_VTEM_DATA_6) & 3) == 3) flags = VRR_VTEM_MODE_3;
    }
    return flags;
}
